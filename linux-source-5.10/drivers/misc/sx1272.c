#include <linux/spi/spi.h>
#include <linux/property.h>
#include <linux/module.h>
#include <linux/device.h>
#include <linux/of.h>

struct sx1272_chip {
	struct mutex lock;
};

#define REG_VERSION 0x42

static int sx1272_read_reg8(struct spi_device *spi, u8 reg, u8 *val)
{
	reg = reg & ~BIT(7); /* clear bit 7 to read reg */
	return spi_write_then_read(spi, &reg, 1, val, 1);
}

static int sx1272_write_reg8(struct spi_device *spi, u8 reg, u8 val)
{
	u8 buf[2];
	buf[0] = reg | BIT(7); /* set bit 7 to write reg */
	buf[1] = val;
	return spi_write(spi, buf, 2);
}

static int sx1272_probe(struct spi_device *spi)
{
	struct device *dev = &spi->dev;
	struct sx1272_chip *sx1272;
	int ret;
	u8 val;

	sx1272 = devm_kzalloc(dev, sizeof(*sx1272), GFP_KERNEL);
	
	if (!sx1272) {
		return -ENOMEM;
	}
	
	spi_set_drvdata(spi, sx1272);
	
	mutex_init(&sx1272->lock);
	
	dev_info(dev, "Hello from sx1272 probe!!\n");
	
	/* Configure the SPI bus */
	spi->mode = (SPI_MODE_0);
	spi->bits_per_word = 8;
	spi->max_speed_hz = 100000;
	
	ret = spi_setup(spi);
	
	if (ret) {
		dev_err(dev, "spi setup failed\n");
		return ret;
	}
	
	ret = sx1272_read_reg8(spi, REG_VERSION, &val);
	
	if (ret) {
		dev_err(dev, "unable to read chip version\n");
		return ret;
	}
	
	/* val should be 0x22 for sx1272 */
	dev_info(dev, "Chip version is 0x%x\n", val);
	
	return 0;
}

static int sx1272_remove(struct spi_device *spi)
{
	struct sx1272_chip *sx1272 = spi_get_drvdata(spi);
	
	mutex_destroy(&sx1272->lock);
	
	return 0;
}

#ifdef CONFIG_OF
static const struct of_device_id sx1272_of_id[] = {
	{ .compatible = "caninos,sx1272" },
	{ }
};
MODULE_DEVICE_TABLE(of, sx1272_of_id);
#endif

static const struct spi_device_id sx1272_spi_id[] = {
	{ "sx1272" },
	{ }
};

MODULE_DEVICE_TABLE(spi, sx1272_spi_id);

static struct spi_driver sx1272_driver = {
	.driver = {
		.name = "sx1272",
		.of_match_table = of_match_ptr(sx1272_of_id),
	},
	.probe    = sx1272_probe,
	.remove   = sx1272_remove,
	.id_table = sx1272_spi_id,
};

module_spi_driver(sx1272_driver);

MODULE_AUTHOR("Ana");
MODULE_DESCRIPTION("SX1272 Driver");
MODULE_LICENSE("GPL v2");