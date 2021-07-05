#include <zephyr.h>
#include <logging/log.h>
#include <stdio.h>

LOG_MODULE_REGISTER(MAIN, CONFIG_FLUIDD_LOG_LEVEL);


void main(void)
{
    LOG_INF("Hello World");
    
}