#include <fstream>
#include <algorithm>
#include <vector>
#include  <iostream>
#include <sstream> 

#include "CFrequencyDictionary.h"
#include "Utils/Utils.h"

std::string CFrequencyDictionary::getError() const
{
	return m_error;
}

bool CFrequencyDictionary::make(const char* inFile, const char* outFile)
{
	m_sortMap.clear();
	m_error.clear();
	std::string data;
	if (loadData(inFile, data))
	{
		const auto freqMap = getFrequencyMap(data);
		if (freqMap.empty())
		{
			m_error = "Can't make frequency map";
		}
		else
		{
			if (sort(freqMap))
			{
				return saveData(outFile);
			}
		}
	}
	return false;
}

bool CFrequencyDictionary::loadData(const char * filename, std::string& data)
{
	std::ifstream file(filename, std::ios_base::in);
	if (!file)
	{
		m_error = "Can't open input file";
		return false;
	}

	data.clear();

	try
	{
		std::stringstream strStream;
		strStream << file.rdbuf();
		data = strStream.str();
	}
	catch(const std::exception& e)
	{
		m_error = "Can't assign data: ";
		m_error += e.what();
		return false;
	}

	if (data.empty())
	{
		m_error = "Input file is empty";
		return false;
	}

	return true;
}

bool CFrequencyDictionary::saveData(const char* filename)
{
	std::ofstream file(filename, std::ios_base::out | std::ios_base::trunc);
	if (!file)
	{
		m_error = "Can't open output file";
		return false;
	}

	for (const auto& e : m_sortMap)
	{
		for (const auto& s : e.second)
			file << e.first << " " << s << std::endl;
	}

	file.close();

	return true;
}

FrequencyMap CFrequencyDictionary::getFrequencyMap(const std::string& str)
{
	FrequencyMap freqMap;

	ToLowerConverter converter;
	std::string token;
	char ch;

	char* begin = const_cast<char*>(str.c_str());
	const char* end = begin + str.size();

	for (char* c = begin; c < end; c++)
	{
		ch = converter[*c];
		if (ch < 'a' || ch > 'z')
		{
			if (token.size())
			{
				freqMap[token]++;
				token.clear();
			}
		}
		else
		{
			token += ch;
		}
	}

	return freqMap;
}


bool CFrequencyDictionary::sort(const FrequencyMap& data) 
{
	std::vector<std::pair<WordType, SizeType>> result;
	try
	{
		std::copy(data.begin(), data.end(), std::back_inserter(result));
		std::sort(result.begin(), result.end(),[](const auto& p1, const auto& p2) { return p1.second > p2.second;});

		std::for_each(result.cbegin(), result.cend(),
               [this](const auto& key_value)
               		{
               			return m_sortMap[key_value.second].insert(key_value.first) ;
               		});
	}
	catch(std::exception& e)
	{
		m_error = "Can't sort data: ";
		m_error += e.what();
		return false;
	}

	return true;
}
