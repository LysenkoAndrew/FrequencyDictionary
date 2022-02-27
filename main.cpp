#include  <iostream>

#include "CFrequencyDictionary.h"

int main(int argc, char* argv[])
{
	if (argc < 3)
	{
		std::cout << "Error: too few arguments\nEnter input and output file" << std::endl;
	}
	else
	{
		std::string str;
		CFrequencyDictionary dict;
		if (!dict.make(argv[1], argv[2]))
		{
			std::cout << "Error: " << dict.getError() << std::endl;
		}
	}
	return 0;
}