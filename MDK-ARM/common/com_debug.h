#ifndef __COM_DEBUG_H__
#define __COM_DEBUG_H__

#include "usart.h"
#include "stdio.h"
#include "stdarg.h"
#include "string.h"
//日志输入占内存 设计日志输出打印开关
#define debug_log_enable 1

#ifdef debug_log_enable

//宏定义，只打印文件名称，不打印路径名称
//strrchr()从后往前查找字符串中的指定字符，返回指针，指向该字符，如果没有找到，返回NULL
#define __FILE_NAME__ (strrchr(__FILE__, '\\') ? (strrchr(__FILE__, '\\') + 1):__FILE__)
#define __FILE_NAME__ (strrchr(__FILE_NAME__, '/') ? (strrchr(__FILE_NAME__, '/') + 1):__FILE_NAME__)

#else
#define debug_printf(format,...)


#define debug_printf(format,...) printf("[%s,%d]" format,__FILE_NAME__,__LINE__,##__VA_ARGS__)
#endif
#endif