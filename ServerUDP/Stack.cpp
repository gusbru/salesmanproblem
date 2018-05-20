//
// Created by Gustavo Brunetto on 19/05/18.
//

#include "Stack.h"

Stack::Stack()
{
    stack.clear();
}

void Stack::addItem(PairPathCost item)
{
    this->stack.emplace_back(item);
}

PairPathCost Stack::getItem()
{
    return stack.back();
}

bool Stack::isEmpty()
{
    return stack.empty();
}

int Stack::getSize()
{
    return (int) stack.size();
}

void Stack::removeItem()
{
    stack.pop_back();
}

std::string Stack::toString()
{
    std::string ret;
    for (auto &item : stack)
        ret += item.toString() + "\n";

    return ret;
}
