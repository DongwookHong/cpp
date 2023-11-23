#pragma once

#include <iostream>
#include <fstream>
#include <string>

class Copy {
    private:
        std::ifstream readfile;
        std::ofstream writefile;
    public:
        Copy();
        ~Copy();

        bool setCopy(char *string);
        void exe(std::string str1, std::string  str2);
};
