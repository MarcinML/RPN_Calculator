#include <iostream>
#include <stack>
#include <string>
#include <sstream>

bool isOperator(const std::string& input)
{
    std::string ops[] ={"-", "+", "*", "/"};
    for(int i=0; i<4; i++)
    {
        if(input == ops[i])
        {
            return true;
        }
    }
    return false;
}

void performOp(const std::string& input, std::stack<double>& calcStack)
{
    double lVal, rVal, result;

    rVal = calcStack.top();
    calcStack.pop();


    lVal = calcStack.top();
    calcStack.pop();

    if(input == "-") result = lVal - rVal;
    if(input == "+") result = lVal + rVal;
    if(input == "*") result = lVal * rVal;
    if(input == "/") result = lVal / rVal;
    std::cout<<result<<std::endl;
    calcStack.push(result);
}


int main()
{
    std::cout << "Welcome to the RPN calculator" << std::endl;

   std::stack<double> calcStack;
    std::string input;
    while(true)
    {
        std::cout<<">>";

        std::cin >> input;

        double num;
        if(std::istringstream(input) >> num)
        {
            calcStack.push(num);
        }
        else if(isOperator(input))
        {
            performOp(input, calcStack);
        }

        else if(input == "q") return 0;

        else
        {
            std::cout<<"invalid input" <<std::endl;
        }
    }
    return 0;
}
