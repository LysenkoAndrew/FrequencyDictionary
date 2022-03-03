#include  <iostream>

#include "Utils.h"

Timer::Timer(const char* name) :
	m_begin(std::chrono::steady_clock::now()),
	m_name(name)
{
}

Timer::~Timer()
{
	const auto end = std::chrono::steady_clock::now();
	const auto elapsed = std::chrono::duration_cast<std::chrono::seconds>(end - m_begin).count();
	std::cout << "Time after " << m_name << " = " << elapsed << " s\n"<< std::flush;
}

ToLowerConverter::ToLowerConverter()
{
	for (int i = 0; i < 256; ++i)
		_convertTable[i] = tolower(i);
}


char ToLowerConverter::operator[](char ch)
{
	return _convertTable[(unsigned char)ch];
}

void ToLowerConverter::StringToLower(std::string &str)
{
	char * c = const_cast<char*>(str.c_str());
	size_t l = str.size();

	for (char * c2 = c; c2 < c + l; c2++)
		*c2 = (*this)[*c2];
}
