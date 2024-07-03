#include <iostream>
#include <vector>
#include"Stack.h"

int calculate(const std::string& expression) {
    Stack<int> stack;
    std::string token;
    int i = 0;

    while (i < expression.size()) {
        if (isdigit(expression[i])) {
            int num = 0;
            while (i < expression.size() && isdigit(expression[i])) {
                num = num * 10 + (expression[i] - '0');
                i++;
            }
            stack.push(num);
        }
        else if (expression[i] == '+' || expression[i] == '-' || expression[i] == '*') {
            int operand2 = stack.top(); stack.pop();
            int operand1 = stack.top(); stack.pop();

            if (expression[i] == '+') {
                stack.push(operand1 + operand2);
            }
            else if (expression[i] == '-') {
                stack.push(operand1 - operand2);
            }
            else if (expression[i] == '*') {
                stack.push(operand1 * operand2);
            }
            i++;
        }
        while (i < expression.size() && expression[i] == ' ') {
            i++;
        }
    }

    return stack.top();
}

void task_1() {
    Stack<std::string> stack;
    stack.push("abc");
    stack.push("fx");
    stack.push("glc");
    stack.push("hi");
    stack.push("gogo");

    std::cout << "Стек: ";
    stack.show();

    stack.pop();

    stack.push("the end");

    std::cout << "Стек після видалення та додавання: ";
    stack.show();

    int count = 0;
    while (!stack.isEmpty()) {
        if (stack.top().length() == 2) {
            count++;
        }
        stack.pop();
    }

    std::cout << "Кількість рядків у стеку, що складаються з 2 символів: " << count << std::endl;
}


int main() {
    
    std::cout<<calculate("825 * +132 * +4-")<<std::endl;


    return 0;
}

