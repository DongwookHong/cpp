#include "Brain.hpp"

Brain::Brain(){
    std::cout<<"Brain default constructor called"<<std::endl;
}

Brain::~Brain(){
    std::cout<<"Brain desctructor called"<<std::endl;
}

Brain::Brain(const Brain& ref)
{
    std::cout<<"Brain Copy constructor called"<<std::endl;
    *this = ref;
}

Brain& Brain::operator=(const Brain& ref)
{
    std::cout<<"Brain Copy assignment constructor called"<<std::endl;
    if(this != &ref)
    {
        for(int i = 0; i <= 100;i++)
        {
            ideas[i]= ref.ideas[i];
        }
    }
    return *this;
}

void Brain::setIdeas(std::string str,int n){
    if (n >= 0 && n < 100) {
        this->ideas[n] = str;
    } else {
        std::cout << "Invalid index: " << n << std::endl;
        return ;
    }
}
std::string Brain::getIdeas(int n) const{
    if (n >= 0 && n < 100) {
        return this->ideas[n];
    }else
    {
        std::cout << "Invalid index: " << n << std::endl;
        return 0;
    }
}