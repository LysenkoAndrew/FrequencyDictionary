#pragma once
#include <chrono>
#include <string>

class Timer
{
public:
	Timer(const char* name);
	~Timer();

private:
	const std::chrono::steady_clock::time_point m_begin;
	const std::string m_name;
};

class ToLowerConverter
{
public:
	ToLowerConverter();
	char operator[](char ch);
	void StringToLower(std::string &str);

private:
	char _convertTable[256];
};
