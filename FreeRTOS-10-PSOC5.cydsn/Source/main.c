/* ========================================
 *
 * Copyright 2018 Michael McCormack
 * All Rights Reserved
 *
 * Permission is hereby granted, free of charge, to any person obtaining 
 * a copy of this software and associated documentation files (the "Software"), 
 * to deal in the Software without restriction, including without limitation 
 * the rights to use, copy, modify, merge, publish, distribute, sublicense, 
 * and/or sell copies of the Software, and to permit persons to whom the 
 * Software is furnished to do so, subject to the following conditions:
 * 
 * The above copyright notice and this permission notice shall be included 
 * in all copies or substantial portions of the Software.
 * 
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, 
 * EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF 
 * MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. 
 * IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY 
 * CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, 
 * TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE 
 * OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
 *
 * ========================================
*/
#include "project.h"
#include "FreeRTOS.h"
#include "timers.h"

extern void RTOS_Start(void);

/*  */ 
void LED_Task(void *arg)
{
    (void)arg;
    while(1)
    {
        LED_Write(~LED_Read());
        vTaskDelay(500);  
    }
}


int main(void)
{
    CyGlobalIntEnable; /* Enable global interrupts. */
    RTOS_Start();


    /* Place your initialization/startup code here (e.g. MyInst_Start()) */

    for(;;)
    {
    xTaskCreate(LED_Task,"LED Task",configMINIMAL_STACK_SIZE,0,1,0);
    vTaskStartScheduler();  // TODO Should never return, add reset after
    }
}

/* [] END OF FILE */
