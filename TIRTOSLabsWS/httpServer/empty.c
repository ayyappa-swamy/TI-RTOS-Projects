/*
 * Copyright (c) 2015, Texas Instruments Incorporated
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 *
 * *  Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 *
 * *  Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the distribution.
 *
 * *  Neither the name of Texas Instruments Incorporated nor the names of
 *    its contributors may be used to endorse or promote products derived
 *    from this software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
 * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO,
 * THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR
 * PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR
 * CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL,
 * EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO,
 * PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS;
 * OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY,
 * WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR
 * OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE,
 * EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */

/*
 *  ======== empty.c ========
 */
/* XDCtools Header files */
#include <xdc/std.h>
#include <xdc/runtime/System.h>

/* BIOS Header files */
#include <ti/sysbios/BIOS.h>
#include <ti/sysbios/knl/Task.h>
#include <ti/sysbios/knl/Clock.h>

/* TI-RTOS Header files */
// #include <ti/drivers/EMAC.h>
#include <ti/drivers/GPIO.h>
// #include <ti/drivers/I2C.h>
// #include <ti/drivers/SDSPI.h>
// #include <ti/drivers/SPI.h>
// #include <ti/drivers/UART.h>
// #include <ti/drivers/USBMSCHFatFs.h>
// #include <ti/drivers/Watchdog.h>
// #include <ti/drivers/WiFi.h>

/* Board Header file */
#include "Board.h"

#include <ti/ndk/inc/netmain.h>
#include "index_withCGI.h"
#include "greetings.h"
#include "chip.h"
#include <stdbool.h>
#include <stdint.h>
#include "inc/hw_gpio.h"
#include "inc/hw_memmap.h"
#include "inc/hw_types.h"
#include "driverlib/gpio.h"
#include "driverlib/pin_map.h"
#include "driverlib/rom.h"
#include "driverlib/rom_map.h"
#include "driverlib/sysctl.h"
#include "driverlib/debug.h"
#include "driverlib/pwm.h"

#include "pinout.h"

#define TASKSTACKSIZE   512
#define PWM_FREQUENCY 100
#define STEPS 256

Task_Struct task0Struct;
Char task0Stack[TASKSTACKSIZE];
uint32_t PWMPeriod = 0;

struct deviceData
{
	uint32_t devicePort;
	uint32_t devicePin;
	Int deviceID;
	Int deviceState;
};

struct groupData
{
	Int groupID;
	struct deviceData deviceArray[4];
}groupArray[1] = {
		{
				0,
				{
						{
								GPIO_PORTC_BASE,
								GPIO_PIN_4,
								0,
								0
						},
						{
								GPIO_PORTC_BASE,
								GPIO_PIN_5,
								0,
								1
						},
						{
								GPIO_PORTC_BASE,
								GPIO_PIN_6,
								0,
								0
						},
						{
								GPIO_PORTC_BASE,
								GPIO_PIN_7,
								0,
								1
						}

				}
		}
};

Int stringLength(char *string)
{
	int index = 0;

	while(string[index] != '\0')
	{
		index++;
	}

	return index - 1;
}

void printDeviceState(void)
{
	/*int index = 0;

	for (index = 0; index < 4; index++){
		System_printf("\nIndex: %d, State: %d", index, groupArray[0].deviceArray[index].deviceState);
	}*/
	System_printf("\nStructure: _%s_ \n", (Char*)&groupArray);
	System_flush();
}

void processData(char *dataBuf)
{
	PinoutSet();
	printDeviceState();
	//System_printf("The dataBuf is %s, length is %d\n", dataBuf, stringLength(dataBuf));
}

Int strtoint(Char *string, Int length)
{
	Int intValue = 0, index = 0;

	while(string[index] != '\0')
	{
		if((string[index] - '0' >= 0) && (string[index] - '0' < 10)){
			intValue = (intValue * 10) + string[index] - '0';
		}
		index++;
	}

	if(intValue > 256){
		intValue = 256;
	}

	return intValue;
}

Int setBrightness(SOCKET s, int length, char *pArgs)
{
	Char buffer[10];

	int lenRecv = recv(s, buffer, length, MSG_WAITALL);
	buffer[lenRecv] = '\0';

	PWMPulseWidthSet(PWM0_BASE, PWM_OUT_2, strtoint(buffer, lenRecv) * (PWMPeriod / STEPS));
    httpSendStatusLine(s, HTTP_OK, CONTENT_TYPE_HTML);
    httpSendClientStr(s, CRLF);
    return (1);
}

Int getTime(SOCKET s, int length, char *pArgs)
{
    Char buf[100];
    Char buf2[50];
    //System_printf("length : %d\npArgs :",length);//, pArgs);
    //System_flush();

    int lee = recv(s,buf2,length,MSG_WAITALL);
    buf2[lee] = '\0';
    httpSendStatusLine(s, HTTP_OK, CONTENT_TYPE_HTML);
    httpSendClientStr(s, CRLF);

    httpSendClientStr(s,
        "<html><head><title>SYS/BIOS Clock "\
	"Time</title></head><body><h1>Time</h1>\n");
    System_sprintf(buf, "<p>args : %s, lee : %d ,groupArray : %c</p><p>\n", buf2, lee, ((Char*)&groupArray)[0]);
    httpSendClientStr(s, buf);
    httpSendClientStr(s, "</p></body></html>");
    processData(buf2);
    return (1);
}

Int deviceControl(SOCKET s, int length, char *pArgs)
{
	Char commandBuffer[10];

	int commandLength = recv(s, commandBuffer, length, MSG_WAITALL);
	commandBuffer[commandLength] = '\0';

	GPIO_toggle(strtoint(commandBuffer, commandLength) + 4);

	httpSendStatusLine(s, HTTP_OK, CONTENT_TYPE_HTML);
	httpSendClientStr(s, CRLF);

	return (1);
}

Void AddWebFiles(Void)
{
    //Note: both INDEX_SIZE and INDEX are defined in index.h
    //efs_createfile("index.html", INDEX_SIZE, (UINT8 *)INDEX);
    efs_createfile("getTime.cgi", 0, (UINT8 *)&getTime);
    efs_createfile("setBrightness.cgi", 0, (UINT8 *)&setBrightness);
    efs_createfile("deviceControl.cgi", 0, (UINT8 *)&deviceControl);
    //efs_createfile("greetings.html", GREETINGS_SIZE, (UINT8 *)GREETINGS);
    //efs_createfile("chip.jpg", CHIP_SIZE, (UINT8 *)CHIP);
}

Void RemoveWebFiles(Void)
{
    //efs_destroyfile("index.html");
    efs_destroyfile("getTime.cgi");
    efs_destroyfile("setBrightness.cgi");
    efs_destroyfile("deviceControl.cgi");
    //efs_destroyfile("greetings.html");
    //efs_destroyfile("chip.jpg");
}

Void initPWMModule(Void)
{
	volatile uint32_t ui32Load;
	volatile uint32_t ui32SysClkFreq;
	volatile uint32_t ui32PWMClock;

	ui32SysClkFreq = SysCtlClockFreqSet((SYSCTL_XTAL_25MHZ | SYSCTL_OSC_MAIN | SYSCTL_USE_PLL | SYSCTL_CFG_VCO_480), 120000000);
	SysCtlPWMClockSet(SYSCTL_PWMDIV_64);

	SysCtlPeripheralEnable(SYSCTL_PERIPH_PWM0);
	SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOF);

	GPIOPinTypePWM(GPIO_PORTF_BASE, GPIO_PIN_2);
	GPIOPinConfigure(GPIO_PF2_M0PWM2);

	ui32PWMClock = ui32SysClkFreq / 64;
	ui32Load = (ui32PWMClock / PWM_FREQUENCY) - 1;
	PWMGenConfigure(PWM0_BASE, PWM_GEN_1, PWM_GEN_MODE_DOWN);
	PWMGenPeriodSet(PWM0_BASE, PWM_GEN_1, ui32Load);
	PWMPeriod = ui32Load;

	PWMPulseWidthSet(PWM0_BASE, PWM_OUT_2, ui32Load / 2);
	PWMOutputState(PWM0_BASE, PWM_OUT_2_BIT, true);
	PWMGenEnable(PWM0_BASE, PWM_GEN_1);

}

/*
 *  ======== heartBeatFxn ========
 *  Toggle the Board_LED0. The Task_sleep is determined by arg0 which
 *  is configured for the heartBeat Task instance.
 */
Void heartBeatFxn(UArg arg0, UArg arg1)
{
    while (1) {
        Task_sleep((unsigned int)arg0);
        GPIO_toggle(Board_LED0);
    }
}

/*
 *  ======== main ========
 */
int main(void)
{
    Task_Params taskParams;
    /* Call board init functions */
    Board_initGeneral();
    Board_initEMAC();
    Board_initGPIO();

    initPWMModule();
    /* Construct heartBeat Task  thread */
    Task_Params_init(&taskParams);
    taskParams.arg0 = 100;
    taskParams.stackSize = TASKSTACKSIZE;
    taskParams.stack = &task0Stack;
    Task_construct(&task0Struct, (Task_FuncPtr)heartBeatFxn, &taskParams, NULL);

     /* Turn on user LED */
    GPIO_write(Board_LED0, Board_LED_ON);
    GPIO_write(4, 1);

    System_printf("Starting the example\nSystem provider is set to SysMin. "
                  "Halt the target to view any SysMin contents in ROV.\n");
    /* SysMin will only print to the console when you call flush or exit */
    //System_flush();

    /* Start BIOS */
    BIOS_start();

    return (0);
}
