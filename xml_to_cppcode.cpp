#include <iostream>
#include <string>
#include <boost/property_tree/ptree.hpp>
#include <boost/property_tree/xml_parser.hpp>
#include <unordered_map>
#include <ostream>

using std::cout;
using std::endl;
using std::string;

int main()
{
    using namespace boost::property_tree;

    const string dicpath = "ManoLanguage/manodictionary.xml";

    ptree pt;
    read_xml(dicpath, pt);

    std::ofstream output;
    output.open("generated.cpp", std::ios::out);

    for (const auto& it : pt.get_child("ArrayOfSerial"))
    {
        char16_t w;
        string s;

        if (auto key = it.second.get_optional<std::string>("key"))
        {
            w = std::stoi(key.value());
        }
        else
        {
            continue;
        }

        if (auto value = it.second.get_optional<std::string>("value"))
        {
            s = value.value();
        }
        else
        {
            continue;
        }
        output << "dictionary[L\"" << s << "\"] = " << w << ";\n";
    }
}
