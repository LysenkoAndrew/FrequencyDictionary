#include <gtest/gtest.h>

#include "Utils/Utils.h"
#include "CFrequencyDictionary.h"

const char* fileIn = "/home/god/Documents/Dict/journal_by_file.txt";
const char* fileOut = "/home/god/Documents/Dict/1.txt";

class CFrequencyDictionaryTest : public CFrequencyDictionary
{
public:
	bool loadData(const char* filename, std::string& data) override
	{
		Timer t("loadData");
		return CFrequencyDictionary::loadData(filename, data);
	}

	bool saveData(const char* filename) override
	{
		Timer t("saveData");
		return CFrequencyDictionary::saveData(filename);
	}

	FrequencyMap getFrequencyMap(const std::string& str) override
	{
		Timer t("getFrequencyMap");
		return CFrequencyDictionary::getFrequencyMap(str);
	}
	bool sort(const FrequencyMap& map) override
	{
		Timer t("sort");
		return CFrequencyDictionary::sort(map);
	}
};

TEST(MakeDictionary, WithTimer)
{
	std::string str;
	CFrequencyDictionaryTest dict;

	const bool result = dict.make(fileIn, fileOut);
	if (!result)
	{
		std::cout << "Error: " << dict.getError() << std::endl;
	}

	EXPECT_EQ(result, true);
}

int main(int argc, char* argv[])
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
