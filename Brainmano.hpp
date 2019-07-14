#pragma once

#include <string>
#include "ManoTranslator.hpp"

namespace Mano
{

    class Brainmano
    {
    private: //variables

        ManoTranslator m_mt;

        //ManoLanguage to ManoExtendedBrainf*ck
        std::unordered_map<ManoTranslator::string, char> mbfdic;

        ManoTranslator::string manolang;
        std::string compiled;

    public: //constructor

        Brainmano();

    public: //funcs

        void Compile();

        void Execute();
    };

    Brainmano::Brainmano()
    {

    }

}