/*
 * @Author: Elayflok 2103307819@qq.com
 * @Date: 2026-04-20 10:34:15
 * @LastEditors: Elayflok 2103307819@qq.com
 * @LastEditTime: 2026-04-20 11:38:54
 * @FilePath: \LED_Freertos\Core\Src\freertos_demo.c
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */
#include "freertos_demo.h"
/* FreeRTOS相关的头文件 */
#include "FreeRTOS.h"
#include "task.h"

/* 启动任务配置 */
#define START_TASK_STACK 128
#define START_TASK_Priority 1
TaskHandle_t start_task_handle;
void start_task(void *pvParameters);

/* 任务1的配置 */
#define TASK1_STACK 128
#define TASK1_Priority 2
TaskHandle_t task1_handle;
void task1(void *pvParameters);

/* 任务2的配置 */
#define TASK2_STACK 128
#define TASK2_Priority 3
TaskHandle_t task2_handle;
void task2(void *pvParameters);

/* 任务3的配置 */
#define TASK3_STACK 128
#define TASK3_Priority 4
TaskHandle_t task3_handle;
void task3(void *pvParameters);

/* 启动FreeRTOS */
void freertos_start(void)
{
    // 1.创建一个启动任务
    xTaskCreate((TaskFunction_t)start_task,               // 任务函数地址
                (char *)"start_task",                     // 任务名称：字符串类型
                (configSTACK_DEPTH_TYPE)START_TASK_STACK, // 任务栈大小：默认最小为128，单位为4字节
                (void *)NULL,                             // 形参（传递给任务的参数） ：不需要直接给NULL
                (UBaseType_t)START_TASK_Priority,         // 任务优先级 : 0-31
                (TaskHandle_t *)&start_task_handle);      // 任务的句柄：传入任务句柄的地址
    // 2.启动调度器：会自动创建空闲任务
    vTaskStartScheduler();
}
/* 启动任务：用来创建其他task */
void start_task(void *pvParameters)
{
    /* 创建3个任务 */
    xTaskCreate((TaskFunction_t)task1,               // 任务函数地址
                (char *)"task1",                     // 任务名称：字符串类型
                (configSTACK_DEPTH_TYPE)TASK1_STACK, // 任务栈大小：默认最小为128，单位为4字节
                (void *)NULL,                        // 形参（传递给任务的参数） ：不需要直接给NULL
                (UBaseType_t)TASK1_Priority,         // 任务优先级 : 0-31
                (TaskHandle_t *)&task1_handle);      // 任务的句柄：传入任务句柄的地址

    xTaskCreate((TaskFunction_t)task2,               // 任务函数地址
                (char *)"task2",                     // 任务名称：字符串类型
                (configSTACK_DEPTH_TYPE)TASK2_STACK, // 任务栈大小：默认最小为128，单位为4字节
                (void *)NULL,                        // 形参（传递给任务的参数） ：不需要直接给NULL
                (UBaseType_t)TASK2_Priority,         // 任务优先级 : 0-31
                (TaskHandle_t *)&task2_handle);      // 任务的句柄：传入任务句柄的地址

    xTaskCreate((TaskFunction_t)task3,               // 任务函数地址
                (char *)"task3",                     // 任务名称：字符串类型
                (configSTACK_DEPTH_TYPE)TASK3_STACK, // 任务栈大小：默认最小为128，单位为4字节
                (void *)NULL,                        // 形参（传递给任务的参数） ：不需要直接给NULL
                (UBaseType_t)TASK3_Priority,         // 任务优先级 : 0-31
                (TaskHandle_t *)&task3_handle);      // 任务的句柄：传入任务句柄的地址

    vTaskDelete(NULL); // 启动任务只需要执行一次即可，用完删除
}

/**
 * @description: 任务一：实现lED1每500ms闪烁一次
 * @param {void} *pvParameters
 * @return {*}
 */
void task1(void *pvParameters)
{
    while (1)
    {
        printf("task1运行....\r\n");
        //LED1翻转任务
        vTaskDelay(500);
    }
}

/**
 * @description:任务二：实现LED2每500ms闪烁一次
 * @param {void} *pvParameters
 * @return {*}
 */
void task2(void *pvParameters)
{
        while (1)
    {
        printf("task2运行....\r\n");
        //LED2翻转任务
        vTaskDelay(500);
    }
}

/**
 * @description:任务三:
 * @param {void} *pvParameters
 * @return {*}
 */
void task3(void *pvParameters)
{
        while (1)
    {
        printf("task3运行....\r\n");


        printf("执行删除task1....\r\n");
    }
}

