/*
 *	Name:log.hpp
 *	Time:2017-1-23
 *	Author:ethan
 *	Version:0.1
 *	Remark:
 */
	
#pragma once
#define _CRT_SECURE_NO_WARNINGS

#ifndef __LOG__HPP__
#define __LOG__HPP__



#ifdef _DEBUG

#include <iostream>
#include <mutex>
#include <string>
#include <map>
#include <vector>
#include <fstream>
#include <stdarg.h>
#include <time.h>



struct LOGGER
{
public:
	LOGGER();
	~LOGGER();
	void LOG();
	void LOG(const char* fmt, ...);

private:
	int index;
	
};

LOGGER::LOGGER()
{
	index = 1;

}
LOGGER::~LOGGER()
{
	index = 0;
	
}
void LOGGER::LOG()
{
	char msg[1024];
	sprintf_s(msg, "%s %d %s", "--------<", index, ">---------");
	LOG("%s", msg);
	index++;
}

void LOGGER::LOG(const char* fmt, ...)
{
	FILE* f = nullptr;
#ifdef SAVELOG
	f = fopen("log.txt", "a");
#endif
	va_list args;
	va_start(args, fmt);
	char msg[256];
	vsprintf_s(msg, fmt, args);
	va_end(args);

	char buff[256];
	time_t t = time(NULL);
	strftime(buff, sizeof(buff), "[%c] ", localtime(&t));
	char out_str[1024];
	sprintf_s(out_str, "%s%s%s", buff, msg,"\n");
	if (f)
	{
		fputs(out_str, f);
		fclose(f);
	}
	fputs(out_str, stdout);
	
}


#endif


#endif //__LOG__HPP__

