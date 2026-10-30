#ifndef _INT_MOTOR__
#define _INT_MOTOR__

#include "tim.h"
#include "com_debug.h" 

typedef struct
{
    TIM_HandleTypeDef *tim; 
    uint16_t channel;
    uint16_t speed; 
} Motor_Struct;




//传入的参数是比较值 最大为1000，默认值为200
void Int_motor_set_speed(Motor_Struct *motor);
//启动电机，传入具体电机的结构体
void Int_motor_start(Motor_Struct *motor);


#endif /* _INT_MOTOR_H_ */
