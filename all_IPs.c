#include <stdio.h>
#include "platform.h"
#include "xil_printf.h"
#include "xparameters.h"
#include "xil_io.h"
#include "xbasic_types.h"

//S1 and S2 regs
Xuint32 *baseaddr_s1 = (Xuint32*)XPAR_SENSOR_READINGS_0_S00_AXI_BASEADDR;
Xuint32 *baseaddr_s2 = baseaddr_s1 + 5;
Xuint32 *baseaddr_sensor_rst = baseaddr_s1 + 10;

//Middle Servo regs
Xuint32 *baseaddr_middle_servo_rst = (Xuint32 *)XPAR_MIDDLESERVO_0_S00_AXI_BASEADDR; //LSB
Xuint32 *baseaddr_middle_servo_stop = baseaddr_middle_servo_rst + 1; //LSB
Xuint32 *baseaddr_middle_servo_current_angle = baseaddr_middle_servo + 2;  //8 lSBs

//Side Servo regs
Xuint32 *baseaddr_side_servos_rst = (Xuint32 *)XPAR_SIDESERVOS_0_S00_AXI_BASEADDR; //LSB
Xuint32 *baseaddr_side_servos_write_current_angle = baseaddr_side_servos_rst + 1; //7 LSBs
Xuint32 *baseaddr_side_servos_read_current_angle = baseaddr_side_servos_rst + 2; //7 LSBs


int main()
{
    init_platform();

    print("Hello World\n\r");

    *(baseaddr_sensor_rst) = 0x00000000;

    //Sensor Readings Test
    int i = 0;
    int j = 0;
    for (i = 0; i<20; i++){
    	printf("Sensor 1 Readings \n");
    	printf("Register 0 : %lu \n", *(baseaddr_s1));
    	printf("Register 1 : %lu \n", *(baseaddr_s1+1));
    	printf("Register 2 : %lu \n", *(baseaddr_s1+2));
    	printf("Register 3 : %lu \n", *(baseaddr_s1+3));
    	printf("Register 4 : %lu \n", *(baseaddr_s1+4));

    	printf("Sensor 2 Readings \n");
    	printf("Register 5 : %lu \n", *(baseaddr_s2));
    	printf("Register 6 : %lu \n", *(baseaddr_s2+1));
    	printf("Register 7 : %lu \n", *(baseaddr_s2+2));
    	printf("Register 8 : %lu \n", *(baseaddr_s2+3));
    	printf("Register 9 : %lu \n", *(baseaddr_s2+4));
    	sleep(1);


    	if(i == 5)*(baseaddr_sensor_rst) = 0x00000001;
    	else *(baseaddr_sensor_rst) = 0x00000000;
    }

    //Middle Servos Test
    for(i=0;i<300000; i++);
    *(baseaddr_middle_servo_rst) = 0x00000001;
    for(i=0;i<300000; i++);
    *(baseaddr_middle_servo_rst) = 0x00000000;
    for(i=0;i<300000; i++);
    *(baseaddr_middle_servo_stop) = 0x00000000;
    for(i=0;i<300000000; i++);
    *(baseaddr_middle_servo_stop) = 0x00000001;
    for(i=0;i<3000000; i++);
    *(baseaddr_middle_servo_stop) = 0x00000000;
    for(i=0;i<300000; i++);
    *(baseaddr_middle_servo_stop) = 0x00000001;
    for(i=0;i<300000; i++);
    *(baseaddr_middle_servo_rst) = 0x00000001;
    for(i=0;i<300000; i++);
    *(baseaddr_middle_servo_rst) = 0x00000000;


	//Side Servos Test
	for(i=0;i<3000000; i++);
    *(baseaddr_side_servos_rst) = 0x00000001;
    xil_printf("Reset =  %d \n\r", *(baseaddr_side_servos_rst));
    for(i=0;i<300000; i++);
    *(baseaddr_side_servos_rst) = 0x00000000;
    xil_printf("Reset =  %d \n\r", *(baseaddr_side_servos_rst));
    while(j != 4)
    {
    for(i=0;i<300000000; i++);
    xil_printf("left servo angel: %d \n\r", *(baseaddr_side_servos_read_current_angle));
    xil_printf("right servo angel: %d \n\r", *(baseaddr_side_servos_read_current_angle));
    *(baseaddr_side_servos_write_current_angle) = 0x00000000;
    xil_printf("input angel: %d \n\r", *(baseaddr_side_servos_write_current_angle));
    for(i=0;i<300000000; i++);
    xil_printf("left servo angel: %d \n\r", *(baseaddr_side_servos_read_current_angle));
    xil_printf("right servo angel: %d \n\r", *(baseaddr_side_servos_read_current_angle));
    *(baseaddr_side_servos_write_current_angle) = 0x0000001E;
    xil_printf("input angel: %d \n\r", *(baseaddr_side_servos_write_current_angle));
    for(i=0;i<300000000; i++);
    xil_printf("left servo angel: %d \n\r", *(baseaddr_side_servos_read_current_angle));
    xil_printf("right servo angel: %d \n\r", *(baseaddr_side_servos_read_current_angle));
    *(baseaddr_side_servos_write_current_angle) = 0x0000002D;
    xil_printf("input angel: %d \n\r", *(baseaddr_side_servos_write_current_angle));
    for(i=0;i<300000000; i++);
    xil_printf("left servo angel: %d \n\r", *(baseaddr_side_servos_read_current_angle));
    xil_printf("right servo angel: %d \n\r", *(baseaddr_side_servos_read_current_angle));
    *(baseaddr_side_servos_write_current_angle) = 0x0000003C;
    xil_printf("input angel: %d \n\r", *(baseaddr_side_servos_write_current_angle));
    for(i=0;i<300000000; i++);
    xil_printf("left servo angel: 0x%08x \n\r", *(baseaddr_side_servos_read_current_angle));
    xil_printf("right servo angel: %d \n\r", *(baseaddr_side_servos_read_current_angle));
    *(baseaddr_side_servos_write_current_angle) = 0x0000005A;
    xil_printf("input angel: %d \n\r", *(baseaddr_side_servos_write_current_angle));
    for(i=0;i<300000000; i++);
    xil_printf("left servo angel: %d \n\r", *(baseaddr_side_servos_read_current_angle));
    xil_printf("right servo angel: %d \n\r", *(baseaddr_side_servos_read_current_angle));
    *(baseaddr_side_servos_write_current_angle) = 0x0000002D;
    xil_printf("input angel: %d \n\r", *(baseaddr_side_servos_write_current_angle));
    j++;
    xil_printf("j =: %d \n\r", j);
    }
    *(baseaddr_side_servos_rst) = 0x00000001;
    xil_printf("Reset =  %d \n\r", *(baseaddr_side_servos_rst));
    for(i=0;i<500000000; i++);
    *(baseaddr_side_servos_rst) = 0x00000000;
    xil_printf("Reset =  %d \n\r", *(baseaddr_side_servos_rst));


    cleanup_platform();
    return 0;
}


