/*
 *	Name:log.hpp
 *	Time:2017-1-23
 *	Author:ethan
 *	Version:1.0
 *	Remark:
 */
	
#pragma once


#ifndef __LOG__HPP__
#define __LOG__HPP__

#ifdef _WIN32
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <mutex>
#include <string>
#include <map>
#include <vector>
#include <fstream>
#include <stdarg.h>
#include <time.h>

void myLog(const char* fmt, ...)
{
	FILE* f = nullptr;
#ifdef LOGF
	f = fopen("log.txt", "a");
#endif 
	va_list args;
	va_start(args, fmt);
	char msg[256];
	vsprintf(msg, fmt, args);
	va_end(args);

	char buff[256];
	time_t t = time(NULL);
	strftime(buff, sizeof(buff), "[%c] ", localtime(&t));
	char out_str[1024];
	sprintf(out_str, "%s%s%s", buff, msg, "\n");
	if (f)
	{
		fputs(out_str, f);
		fclose(f);
	}
	fputs(out_str, stdout);
}
#ifdef _DEBUG
void myLog(int index)
{
	char msg[1024];
	sprintf(msg, "%s %d %s", "--------<", index, ">---------");
	myLog("%s", msg);
}
#else
void myLog(int index)
{

}
#endif //_DEBUG


#endif // _win32


#endif //__LOG__HPP__

