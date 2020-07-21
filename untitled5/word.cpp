//
// Created by aidan on 11/27/18.
//

#include "word.h"
#include <algorithm>

// Default Constructor
word::word()
{
    value.push_back("");
    skey = "";
}

// Copy Constructor
word::word(std::string wordBinary)
{
    value.push_back(wordBinary);
    skey = wordBinary;
    for(unsigned int i=0;i<value[0].length();i++)
    {
        skey[i] = static_cast<char>(tolower(skey[i]));
    }
    std::sort(skey.begin(),skey.end());
}

// returns the name of the word
std::string word::name() const
{
    std::string result = "";

    for(unsigned int i=0;i<value.size();i++)
    {
        result = result+""+value[i];
    }

    return result;
}

// returns key of the word
std::string word::searchkey() const
{
    std::string search = value[0];

    for(unsigned int i=0;i<value[0].length();i++)
    {
        search[i] = static_cast<char>(tolower(search[i]));
    }
    std::sort(search.begin(),search.end());

    return search;
}

// checks if keys are equal
bool word::operator==(const word &other)
{
    return skey.compare(other.searchkey()) == 0;
}

// checks if current key is greater than other key
bool word::operator>(const word &other)
{
    return skey.compare(other.searchkey()) > 0;
}

// checks if current key is less than other key
bool word::operator<(const word &other)
{
    return skey.compare(other.searchkey()) < 0;
}

// checks if current key is greater than or equal to other key
bool word::operator>=(const word &other)
{
    return searchkey().compare(other.searchkey()) == 0;
}

// checks if current key is less than or equal to other key
void word::operator<=(const word &other)
{
    value.push_back(other.name());
}