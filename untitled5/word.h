//
// Created by aidan on 11/27/18.
//

#ifndef UNTITLED5_WORD_H
#define UNTITLED5_WORD_H
#include <string>
#include <iostream>
#include <vector>
#include <cctype>
#include <algorithm>
class word{
    private:
    std::string skey;
    std::vector<std::string> value;
public:
    word();
    word(std::string wordBinary);
    std::string name() const;
    std::string searchkey() const;
    bool operator==(const word &other);
    bool operator>(const word &other);
    bool operator<(const word &other);
    bool operator>=(const word &other);
    void operator<=(const word &other);
};
inline std::ostream& operator<<(std::ostream &out, const word outputWord)
{
    return out<< "The words are: " << outputWord.name() << "  The key is:" <<outputWord.searchkey() << std::endl;
}
#endif //UNTITLED5_WORD_H
