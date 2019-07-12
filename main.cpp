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
    ManoTranslator mano;



    return 0;
}

ManoTranslator::ManoTranslator()
{
    EncoderMaker(m_encoder);
    DecoderMaker(m_decoder);
}

ManoTranslator::string ManoTranslator::Encode(const ManoTranslator::string& str) const
{
    ManoTranslator::string result;

    for (auto w : str)
    {
        if (m_encoder.count(w) == 0)
        {
            result += w;
            continue;
        }
        result += m_encoder.at(w);
    }

    return result;
}

ManoTranslator::string ManoTranslator::Decode(const ManoTranslator::string& str) const
{
    ManoTranslator::string ret = L"";

    const ManoTranslator::string howa = L"ÇŸÇÌÇ¡";
    const ManoTranslator::string mun = L"ÇﬁÇÒÇ¡";
   
    int seek = 0;

    ManoTranslator::string match = L"";

    while (seek < str.length())
    {
        auto c = str[seek];

        if (c != howa.front() && c != mun.front())
        {
            ret += match;
            ret += c;
            seek++;
            match = L"";
            continue;
        }

        //èIóπèàóù
        if (str.length() - seek < 3)
        {
            ret += str.substr(seek);
            break;
        }

        auto s = str.substr(seek, 3);

        if (s != howa && s != mun)
        {
            ret += match;
            ret += c;
            seek++;
            match = L"";
            continue;
        }

        match += s;
        seek += 3;

        if (m_decoder.count(match) != 0)
        {
            ret += m_decoder.at(match);
            match.clear();
            continue;
        }
    }
    ret += match;

    return ret;
}
