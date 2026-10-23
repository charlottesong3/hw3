#ifndef STACK_H
#define STACK_H

#include <cstddef>
#include <stdexcept>
#include <vector>

template <typename T>
class Stack : private std::vector<T>
{
public:
    Stack();
    ~Stack();

    bool empty() const;
    std::size_t size() const;
    void push(const T& item);
    void pop(); //:p
    const T& top() const;
};

//setup

template <typename T>
Stack<T>::Stack()
{
}

template <typename T>
Stack<T>::~Stack()
{
}

template <typename T>
bool Stack<T>::empty() const
{

    return std::vector<T>::empty();
}

template <typename T>
std::size_t Stack<T>::size() const
{
    return std::vector<T>::size();


}

template <typename T>
void Stack<T>::push(const T& item)
{

// :p
    std::vector<T>::push_back(item);
}

template <typename T>
void Stack<T>::pop()
{ // :3

    if (std::vector<T>::empty()) {
        throw std::underflow_error("Cannot pop an empty stack");
    }

    std::vector<T>::pop_back();
}

template <typename T>
const T& Stack<T>::top() const
{

    if (std::vector<T>::empty()) {


        throw std::underflow_error("Cannot access the top of an empty stack");
    }

    return std::vector<T>::back();
}

#endif