#pragma once
#include <iostream>
#include <string>

class Brain
{
    private:
        std::string ideas[100];
    public:
        Brain();
        ~Brain();
        Brain(const Brain& ref);
        
        Brain& operator=(const Brain& ref);

        void setIdeas(std::string str,int n);
        std::string getIdeas(int n) const;
};