#include <iostream>
#include <string>
#include <unordered_map>
#include <locale>
#include <clocale>
#include <algorithm>
#include <climits>
#include <iomanip>

#include "ManoTranslator.hpp"

using std::cout;
using std::endl;

//èoóÕóp
//https://gist.github.com/calbonaler/1231f78c63fb0b78d26d368a025b1cce
std::string toChars(int ch) {
    std::string chars;
    unsigned int chu = static_cast<unsigned int>(ch);
    for (size_t i = 0; i < sizeof(chu); ++i)
    {
        char ch = static_cast<char>((chu >> (i * CHAR_BIT)) & ((1u << CHAR_BIT) - 1u));
        if (!ch) break;
        chars.push_back(ch);
    }
    std::reverse(chars.begin(), chars.end());
    return chars;
}



int main()
{
    Mano::ManoTranslator mano;



    return 0;
}
