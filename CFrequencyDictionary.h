#pragma once

#include <string>
#include <map>
#include <unordered_map>
#include <set>

using FrequencyMap = std::unordered_map<std::string, size_t>;
using WordType = FrequencyMap::key_type;
using SizeType = FrequencyMap::value_type::second_type;

class CFrequencyDictionary
{
public:
	virtual ~CFrequencyDictionary() = default;
	bool make(const char* inFile, const char* outFile);
	std::string getError() const;

protected:
	std::string m_error;

protected:
	virtual bool loadData(const char* filename, std::string& data);
	virtual bool saveData(const char* filename);
	virtual FrequencyMap getFrequencyMap(const std::string& str);
	virtual bool sort(const FrequencyMap& map);

	std::map<SizeType, std::set<WordType>, std::greater<SizeType>> m_sortMap;
};
