#define DT_DRV_COMPAT chenry_driver

#include <zephyr/kernel.h>
#include <zephyr/device.h>
#include <zephyr/drivers/sensor.h>

static int chenry_driver_sample_fetch(const struct device *dev, enum sensor_channel chan)
{
    return 0;
}

static int chenry_driver_channel_get(const struct device *dev, enum sensor_channel chan, struct sensor_value *val)
{
    val->val1 = 3.1415;
    return 0;
}

static int chenry_driver_init(const struct device *dev)
{
    printk("Initializing Chenry Driver...\n");
}

static const struct sensor_driver_api chenry_driver_api = {
    .sample_fetch = chenry_driver_sample_fetch,
    .channel_get = chenry_driver_channel_get,
};

#define CHENRY_DRIVER_INIT(i) \
    DEVICE_DT_INST_DEFINE(i, chenry_driver_init, NULL, NULL, NULL, POST_KERNEL, CONFIG_SENSOR_INIT_PRIORITY, &chenry_driver_api);

DT_INST_FOREACH_STATUS_OKAY(CHENRY_DRIVER_INIT)
