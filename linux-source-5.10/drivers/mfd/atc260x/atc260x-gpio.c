#include "atc260x-core.h"
#include <linux/mfd/atc260x/regs_map_atc2603c.h>
#include <linux/gpio/driver.h>
#include <linux/gpio/consumer.h>
#include <linux/module.h>
#include <linux/of_platform.h>

#define ATC2603C_NGPIO 6

struct atc260x_gpio {
    struct gpio_chip gpio_chip;
    struct atc260x_dev *pmic;
};

static int atc260x_gpio_direction_input(struct gpio_chip *gc, unsigned int offset) {
	struct atc260x_gpio *chip = gpiochip_get_data(gc);
	atc260x_reg_setbits(chip->pmic, ATC2603C_GPIO_OUTEN, BIT(offset),  0);
	atc260x_reg_setbits(chip->pmic, ATC2603C_GPIO_INEN, BIT(offset), BIT(offset));

	offset += 2;
	atc260x_reg_setbits(chip->pmic, ATC2603C_PMU_SGPIO_CTL3, BIT(offset), BIT(offset));

	offset += 7;
	atc260x_reg_setbits(chip->pmic, ATC2603C_PMU_SGPIO_CTL3, BIT(offset), 0);
	return 0;
}

static int atc260x_gpio_direction_output(struct gpio_chip *gc, unsigned int offset, int value) {
	struct atc260x_gpio *chip = gpiochip_get_data(gc);
	atc260x_reg_setbits(chip->pmic, ATC2603C_GPIO_OUTEN, BIT(offset), BIT(offset));
	atc260x_reg_setbits(chip->pmic, ATC2603C_GPIO_INEN, BIT(offset),  0);

	offset += 2;
	atc260x_reg_setbits(chip->pmic, ATC2603C_PMU_SGPIO_CTL3, BIT(offset), 0);

	offset += 7;
	atc260x_reg_setbits(chip->pmic, ATC2603C_PMU_SGPIO_CTL3, BIT(offset), BIT(offset));
	return 0;
}

static int atc260x_gpio_get_value(struct gpio_chip *gc, unsigned int offset) {
	struct atc260x_gpio *chip = gpiochip_get_data(gc);
	u16 gpiodat, ctl4;
	int val;

	gpiodat = atc260x_reg_read(chip->pmic, ATC2603C_GPIO_DAT);
	ctl4 = atc260x_reg_read(chip->pmic, ATC2603C_PMU_SGPIO_CTL4);

	dev_info(chip->pmic->dev, "GPIO DAT value: %d\n", gpiodat);
	dev_info(chip->pmic->dev, "GPIO CTL4 value: %d\n", ctl4);

	val = (ctl4 & (BIT(offset))) >> offset;

	return (int) val;
}

static void atc260x_gpio_set_value(struct gpio_chip *gc, unsigned int offset, int value) { //Sets the value of the GPIO pin data
	struct atc260x_gpio *chip = gpiochip_get_data(gc);
	atc260x_reg_setbits(chip->pmic, ATC2603C_GPIO_DAT, BIT(offset), value << offset); 
	atc260x_reg_setbits(chip->pmic, ATC2603C_PMU_SGPIO_CTL4, BIT(offset), value << offset);
	return;
}

static int atc260x_gpio_get_direction(struct gpio_chip *gc, unsigned int offset) { //Gets the direction of the GPIO pin
	struct atc260x_gpio *chip = gpiochip_get_data(gc);
	u16 outen, inen, ctl3, val;
	outen = atc260x_reg_read(chip->pmic, ATC2603C_GPIO_OUTEN);
	inen = atc260x_reg_read(chip->pmic, ATC2603C_GPIO_INEN);
	ctl3 = atc260x_reg_read(chip->pmic, ATC2603C_PMU_SGPIO_CTL3);

	dev_info(chip->pmic->dev, "GPIO OUTEN value: %d\n", outen);
	dev_info(chip->pmic->dev, "GPIO INEN value: %d\n", inen);
	dev_info(chip->pmic->dev, "GPIO CTL3 value: %d\n", ctl3);

	offset += 9;

	val = (ctl3 & (BIT(offset))) >> offset;
	
	return (int) val;
}

static int atc260x_gpio_probe(struct platform_device *pdev) {
    int ret;
    struct atc260x_gpio *chip;
    struct gpio_chip *gc;

	chip = devm_kzalloc(&pdev->dev, sizeof(*chip), GFP_KERNEL);
	
	if (!chip) {
		return -ENOMEM;
	}
	
	chip->pmic = dev_get_drvdata(pdev->dev.parent);
	
	if (!chip->pmic) {
		dev_info(&pdev->dev, "pmic null");
		return -EINVAL;
	}

	gc = &chip->gpio_chip;

	gc->direction_input  = atc260x_gpio_direction_input;
	gc->direction_output = atc260x_gpio_direction_output;
	gc->get = atc260x_gpio_get_value;
	gc->set = atc260x_gpio_set_value;
	gc->get_direction = atc260x_gpio_get_direction;
	gc->ngpio = ATC2603C_NGPIO;
	gc->label = "PMICGPIO";
	gc->base = -1;

    /*config regs ATC2603C_MFP_CTL, 
        ATC2603C_GPIO_OUTEN
        ATC2603C_GPIO_INEN
        ATC2603C_GPIO_DAT
        ATC2603C_PMU_SGPIO_CTL0
        ATC2603C_PMU_SGPIO_CTL1
        ATC2603C_PMU_SGPIO_CTL2
        ATC2603C_PMU_SGPIO_CTL3
        ATC2603C_PMU_SGPIO_CTL4
    *//* 
	atc260x_reg_setbits(chip->pmic, ATC2603C_GPIO_OUTEN , BIT(0),  0);
	atc260x_reg_setbits(chip->pmic, ATC2603C_GPIO_INEN , BIT(0),  0);
	atc260x_reg_setbits(chip->pmic, ATC2603C_GPIO_DAT , BIT(0), 0);
	atc260x_reg_setbits(chip->pmic, ATC2603C_PMU_SGPIO_CTL3 , BIT(0),  0); */
    atc260x_reg_setbits(chip->pmic, ATC2603C_MFP_CTL, 0x0180, 0x0080);

	ret = devm_gpiochip_add_data(&pdev->dev, gc, chip);
	if(ret){
		dev_err(&pdev->dev, "error adding gpiochip data");
		return ret;
	}

	ret = platform_device_add_data(pdev, chip, sizeof(chip));
	if(ret){
		dev_err(&pdev->dev, "error adding platform data");
		return ret;
	}

	dev_info(&pdev->dev, "probe finished");

    return ret;
}

static int atc260x_gpio_remove (struct platform_device *pdev){
	struct atc260x_gpio *chip = dev_get_platdata(&pdev->dev);
	gpiochip_remove(&chip->gpio_chip);
	kfree(chip);
	return 0;
}

static const struct of_device_id atc260x_gpio_of_match[] = {
	{ .compatible = "actions,atc2603c-gpio" },
	{ }
};
MODULE_DEVICE_TABLE(of, atc260x_gpio_of_match);

static struct platform_driver atc260x_gpio_driver = {
	.probe = atc260x_gpio_probe,
	.remove = atc260x_gpio_remove,
	.driver = {
		.name = "atc2603c-gpio",
		.owner = THIS_MODULE,
		.of_match_table = atc260x_gpio_of_match,
	},
}; 

module_platform_driver(atc260x_gpio_driver);

MODULE_AUTHOR("Ana Clara Forcelli <ana.forcelli@lsitec.org.br>");
MODULE_DESCRIPTION("ATC2603C GPIO driver");
MODULE_LICENSE("GPL");

