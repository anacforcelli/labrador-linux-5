#include <linux/spi/spi.h>
#include <linux/property.h>
#include <linux/module.h>

#define SPI_MODE 0
#define SPI_MAX_SPEED_HZ 100000
#define SPI_BITS_PER_WORD 8

struct sx1272 {
	struct spi_device *spi;
};

static int sx1272_probe(struct spi_device *spi) {

    int err;
    uint8_t data; 
    uint8_t tx = 0x00;

    struct spi_transfer tr = {
        .rx_buf = &data,
        .tx_buf = &tx,
        .len = 1,
    };
    

    // Setup SPI
    spi->mode = SPI_MODE;
    spi->max_speed_hz = SPI_MAX_SPEED_HZ;
    spi->bits_per_word = SPI_BITS_PER_WORD;

    err = spi_setup(spi);
    if(err < 0){
        pr_err("spi_setup failed\n");
        return err;
    }
    err = spi_sync_transfer(spi, &tr, 1);
    if (err != 0){
        pr_err("spi xfer failed\n");
        return err;
    }
    pr_info("rx: %x\n", data);

    return 0; 
}

static const struct spi_device_id caninos_ids[] = {
	{"caninos,sx1272", 0},
	{ }
};
MODULE_DEVICE_TABLE(spi, caninos_ids);

static struct spi_driver sx1272_driver = {
    .driver= { .name = "caninos-lora"},
	.probe		= sx1272_probe,
    .id_table = caninos_ids,
};

module_spi_driver(sx1272_driver);

MODULE_DESCRIPTION("SX1272 Driver");
MODULE_LICENSE("GPL");