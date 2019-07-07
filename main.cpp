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

    //for(const auto& child : pt.get_child("ArrayOfSerial")) {
    //    std::cout << child.second.get_child("Serial").data() << std::endl;
    //    //const auto key = child.second.data();
    //    //std::cout << key << std::endl;        
    //    //const std::string value = child.second.data();
    //    //std::cout << value << std::endl;
    //}

    std::unordered_map<int, string> dic_en;
    std::unordered_map<string, int> dic_de;

    std::ofstream output;
    output.open("manotest.txt", std::ios::out);

    for (const auto& it : pt.get_child("ArrayOfSerial"))
    {
        char16_t w;
        string s;

        if (auto key = it.second.get_optional<std::string>("key"))
        {
            w = std::stoi(key.value());
            std::cout << key << '\n';
        }
        else
        {
            continue;
        }

        if (auto value = it.second.get_optional<std::string>("value"))
        {
            s = value.value();
            std::cout << "‚Ù‚í‚Á:" << value << '\n';
        }
        else
        {
            continue;
        }
        output << w << endl;
        output << s << '\n';

        dic_en[w] = s;
        dic_de[s] = w;
    }



}