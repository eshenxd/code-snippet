#ifndef _LOG_HPP_
#define _LOG_HPP_

#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <fstream>
#include <stdarg.h>
#include <time.h>

/*!
 * \brief log日志输出函数
 * \param fmt ： log 输出的格式
 * \param ... ： 需要在输出格式中显示的参数
 *
 */
void LOG(const char *fmt, ...);

void LOG(const char *fmt, ...) {
	
	va_list args;
	va_start(args, fmt);
	char msg[256];
	vsprintf(msg, fmt, args);
	va_end(args);

	char buff[256];
	time_t t = time(NULL);
	strftime(buff, sizeof(buff), "[%x - %X]", localtime(&t));
	printf("%s %s\n", buff, msg);
}

/*
  //test
  int main(int argc, char* argv[])
  {
  string out1 = "1";
  string out2 = "2";

  LOG("This is the %d of %d argv", 1, 5);
  return 0;
  }

*/


#endif