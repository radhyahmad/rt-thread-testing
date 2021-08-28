#include <rtthread.h>
#include <rtdevice.h>
#include <board.h>

#define DBG_TAG "main"
#define DBG_LVL DBG_LOG

#include <rtdbg.h>

//defined the LED0 pin: PB14
#define LED0_PIN    GET_PIN(B, 14)

int main(void)
{
    int count = 1;
    //set LED0 pin mode to output
    rt_pin_mode(LED0_PIN, PIN_MODE_OUTPUT);
    rt_kprintf("Hello, first testing from IoT dev\n");


    while (count++)
    {
        rt_pin_write(LED0_PIN, PIN_HIGH);
        LOG_D("led on, count: %d", count);
        rt_thread_mdelay(1000);

        rt_pin_write(LED0_PIN, PIN_LOW);
        LOG_D("led off");
        rt_thread_mdelay(1000);
    }

    return RT_EOK;
}

