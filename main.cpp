#include "mbed.h"
#include "HEPTA_EPS.h"
#include "HEPTA_SENSOR.h"
HEPTA_EPS eps(PA_0,PA_4);
HEPTA_SENSOR sensor(PA_7,PB_7,PB_6,0xD0);
Serial pc(USBTX,USBRX,9600);
int main()
{   
    float temp;
    pc.printf("Temperature Sensor\r\n");
    eps.turn_on_regulator(); //Turn on 3.3V converter
    for(int i=0;i<10;i++){
        sensor.temp_sense(&temp);
        pc.printf("Temperature=%f[degC]\r\n",temp);
        wait_ms(1000);
    }
}