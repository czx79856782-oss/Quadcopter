Quadcopter - 四轴无人机 STM32 项目

这基于 STM32 微控制器和 FreeRTOS 实时操作系统的四轴无人机飞控项目源码。

硬件与软件环境
主控芯片：STM32F103C8T6
操作系统：FreeRTOS
开发工具：STM32CubeMX + Keil MDK-ARM + VS Code
电源管理：IP5305T

工程结构
P01_flight_hal：飞控核心工程（包含电机控制、电源管理、FreeRTOS 任务调度）。
P02_remote_hal：遥控器通信工程（预留/开发中）。

目前实现的功能
[x] 底层外设初始化（HAL库）
[x] FreeRTOS 基础任务框架搭建
[x] 电源管理任务（定期启动 IP5305T 防止关机）
[x] 飞行控制任务框架
[ ] LED 状态指示灯任务（待完善）
[ ] 遥控器串口通信及数据解析
[ ] PID 姿态控制算法

编译说明
1. 使用 Keil MDK-ARM 打开 MDK-ARM 文件夹下的 .uvprojx 工程文件。
2. 编译并下载到 STM32F103C8T6 开发板。

*持续更新中...*
