#include "copy.hpp"

Copy::Copy(){}
Copy::~Copy(){}


bool Copy::setCopy(std::string filename) {
	this->readfile.open(filename);
	if (!this->readfile.is_open())
	{
		std::cout<<"Can't open file"<<std::endl;
		return false;
	}
	filename += ".replace";  
    this->writefile.open(filename); 
	if (!this->writefile.is_open())
	{
		this->readfile.close();
		std::cout<<"Can't open file"<<std::endl;
		return false;
	}
	return true;
}


void Copy::exe(std::string str1, std::string  str2){
	
	while(true)
	{
		std::string str;
		std::getline(this->readfile, str);
		size_t index=0;
		while(true)
		{
			index = str.find(str1, index);
			if (index == std::string::npos)
				break;
			str.erase(index, str1.length());
            str.insert(index, str2);
            index += str2.length();
		}
		this->writefile << str;
		if(this->readfile.eof())
			break;
		if (str1 != "\n")
			this->writefile<<std::endl;
		else
			this->writefile<<str2;
	}
	this->readfile.close();
	this->writefile.close();
}