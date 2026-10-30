#include "App_freeRTOS_Task.h"

//STM32F103C8T6=>分配12k给操作系统
//内存管理。c语言的结构体通常保存在堆中，不会自动垃圾回收=>始终使用同一个结构体，不断循环使用
//电机结构体
Motor_Struct left_top_motor = {.tim = &htim3, .channel = TIM_CHANNEL_1, .speed = 200};
Motor_Struct left_bottom_motor = {.tim = &htim4, .channel = TIM_CHANNEL_4, .speed = 200};
Motor_Struct right_top_motor = {.tim = &htim2, .channel = TIM_CHANNEL_2, .speed = 200};
Motor_Struct right_bottom_motor = {.tim = &htim1, .channel = TIM_CHANNEL_3, .speed = 200};

// 表示遥控器状态
Remote_State remote_state = REMOTE_DISCONNECTED;

// 表示飞行状态
Flight_State flight_state = NORMAL;

//电源管理任务
void power_task(void *args);
//最小推荐填写128 128*4=512B
#define POWER_TASK_STACK_SIZE 128
//任务优先级 数值越小，优先级越高=>1最小，4最大=>不推荐使用最小优先级0
#define POWER_TASK_PRIORITY 4
TaskHandle_t power_task_handle;
// 定义任务的周期
#define POWER_TASK_PERIOD 10000

//飞行控制任务
void flight_task(void *args);
#define FLIGHT_TASK_STACK_SIZE 128
#define FLIGHT_TASK_PRIORITY 3
TaskHandle_t flight_task_handle;
//定义任务的周期
#define FLIGHT_TASK_PERIOD 6










//启动FREERTOS操作系统
void App_freeRTOS_start(void)
{
//1.创建电源管理任务
 xTaskCreate(power_task,"power_task",POWER_TASK_STACK_SIZE,NULL,POWER_TASK_PRIORITY,&power_task_handle);

//2.创建飞行控制任务
xTaskCreate(flight_task,"flight_task",FLIGHT_TASK_STACK_SIZE,NULL,FLIGHT_TASK_PRIORITY,&flight_task_handle);


//3.启动调度器
    vTaskStartScheduler();

}


void power_task(void *args)
{
    //获取当前基准时间
    TickType_t xLastWakeTime = xTaskGetTickCount();
    //每10s执行一次，启动电源，避免自动关机
    while(1)
    {
      
        //每10s执行一次，启动电源，避免自动关机
        vTaskDelayUntil(&xLastWakeTime,POWER_TASK_PERIOD);

       //启动电源
        Int_IP5305T_start();
}

}

void flight_task(void *args)
{
     //获取当前基准时间
    TickType_t xLastWakeTime = xTaskGetTickCount();
    //每10s执行一次，启动电源，避免自动关机
    while(1)
    {  
        //1.设置电机的转速
        left_top_motor.speed = 400;

        //2.直接启动电机
        // Int_motor_start(&left_top_motor);
        // Int_motor_start(&right_bottom_motor);

      vTaskDelayUntil(&xLastWakeTime,FLIGHT_TASK_PERIOD);
    }
}
