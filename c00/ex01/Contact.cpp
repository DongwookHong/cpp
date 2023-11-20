#include <iostream>
#include <string>
#include "Contact.hpp"

Contact::Contact() {}
Contact::~Contact() {}

std::string Contact::getFname() const {
	return this->Fname;
}

std::string Contact::getLname() const {
	return this->Lname;
}

std::string Contact::getNname() const {
	return this->Nname;
}

std::string Contact::getNum() const {
	return this->Num;
}

std::string Contact::getSecret() const {
	return this->Secret;
}
std::string Contact::getIndex() const {
	return this->Index;
}

void Contact::setFname(std::string fname){
	this->Fname = fname;
}

void Contact::setLname(std::string lname){
	this->Lname = lname;
}
void Contact::setNname(std::string nname){
	this->Nname = nname;
}
void Contact::setNum(std::string num){
	this->Num = num;
}
void Contact::setSecret(std::string secret){
	this->Secret = secret;
}

void Contact::setIndex(std::string index){
	this->Index = index;
}
