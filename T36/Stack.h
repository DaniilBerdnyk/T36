#pragma once
#include <iostream>
#include <vector>
#include <string>

template <typename T>
class Stack {
private:
    std::vector<T> elements;

public:
    bool isEmpty() const {
        return elements.empty();
    }

    T top() const {
        if (!isEmpty()) {
            return elements.back();
        }
        return T();
    }

    void push(const T& value) {
        elements.push_back(value);
    }

    void pop() {
        if (!isEmpty()) {
            elements.pop_back();
        }
    }

    void show() {
        for (const auto& element : elements) {
            std::cout << element << " ";
        }
        std::cout << std::endl;
    }
};

