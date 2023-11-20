#pragma once

#include <iostream>
#include <string>
#include "Contact.hpp"

class PhoneBook
{
	private:
		Contact contact[8];
		int  i;
		int CountContact;
	public:
		PhoneBook();
		~PhoneBook();

		void Add();
		void Search();

};

void exe();
void base_print();
void check_len(std::string str,int num);
std::string over_len(std::string str);
void print_form(std::string str);
void get_line(std::string &str);
bool empty_check(const std::string& str);
