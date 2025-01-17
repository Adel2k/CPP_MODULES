# include "RPN.hpp"

namespace ft{

    bool isDigit(const char& ch) {
        return (ch >= '0' && ch <= '9');
    }

    bool isOperator(const char& o) {
        if (o == '-' || o == '*' || o == '/' || o == '+')
            return 1;
        return 0;
    }

    bool isSpace(const char& o) {
        return ((o >= 9 && o <= 13) || o == 32);
    }

}

// Orthodox
RPN::RPN() {}
RPN::RPN(const RPN& ) {}
RPN& RPN::operator=(const RPN& ) {return *this;}
RPN::~RPN() {}
//

void    RPN::validation(const std::string& string) {
    if (string.empty()) {
    std::cerr << "Error: Empty input!" << endl;
    return;
    }
    for (size_t i = 0; i < string.length(); i++) {
        if (!ft::isDigit(string[i]) && !ft::isOperator(string[i]) && !std::isspace(string[i])) {
            std::cerr << "Error: Wrong argument at index " << i << endl;
            return ;
        }
        else {
            if (ft::isSpace(string[i]))
                continue;
            if (ft::isDigit(string[i]) && (string[i] - '0' >= 0 && string[i] - '0' < 10))
                _stack.push(string[i] - '0');
            else if (ft::isOperator(string[i])) {
                operatorCount++;
                if (_stack.size() < 2) {
                    std::cerr << "Error: Not enaough operands for operation" << endl;
                    return ;
                }
                int operand2 = _stack.top();
                _stack.pop();
                int operand1 = _stack.top();
                _stack.pop();

                if (string[i] == '+')
                    _stack.push(operand1 + operand2);
                if (string[i] == '-')
                    _stack.push(operand1 - operand2);
                if (string[i] == '*')
                    _stack.push(operand1 * operand2);
                if (string[i] == '/') {
                    if (operand1 == 0 || operand2 == 0) {
                        std::cerr << "Error: the number can not be devide by 0" << endl;
                        return ;
                    }
                    _stack.push(operand1 / operand2);
                }
            }
            else {
                std::cerr << "The numbers should be in the range of 0 - 10"  << endl;
                return ;
            }
        }
    }
    if (_stack.size() != 1) {
        std::cerr << "Error: No result on the stack" << endl;
        return ;
    }
    cout << _stack.top() << endl;
}

RPN::RPN(const char* string) {
    validation(string);
}