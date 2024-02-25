#include "RPN.hpp"

RPN::RPN() {}

RPN::~RPN() {}

RPN::RPN(const RPN& other) { this->numberStack = other.numberStack; }

RPN& RPN::operator=(const RPN& other) {
  if (this != &other) {
    this->numberStack = other.numberStack;
  }
  return *this;
}



RPN::RPN(std::string av) {
    try{
        executeRpn(av);
    }catch (const std::exception& e)
    {
        std::cout << e.what()<<std::endl;
    }
}

   void RPN::executeRpn(std::string& str) 
   {
        for (std::size_t i = 0; i < str.size(); ++i) {
            char ch = str[i];

            if (std::isdigit(ch))
                numberStack.push(ch - '0');
            else if (std::isspace(ch))
                continue;
            else if (ch == '+' || ch == '-' || ch == '*' || ch == '/') 
            {
                if (numberStack.size() < 2)
                    throw Error();

                double b = numberStack.top(); 
                numberStack.pop();
                double a = numberStack.top(); 
                numberStack.pop();

                numberStack.push(perform(a, ch, b));
            } else {
                throw Error();
            }
        }

        if (numberStack.size() != 1)
            throw Error();

        std::cout << numberStack.top() << std::endl;
    }

 double RPN::perform(double a, char op, double b) {
        switch (op) {
            case '+': return a + b;
            case '-': return a - b;
            case '*': return a * b;
            case '/':
                if (b == 0) throw Error();
                return a / b;
            default:
                throw Error();
        }
    }



const char* Error::what(void) const throw() {
  return "Error";
}
