//
// Created by Gustavo Brunetto on 19/05/18.
//

#ifndef SERVERUDP_STACK_H
#define SERVERUDP_STACK_H

#include "PairPathCost.h"

class Stack
{
public:
    Stack();
    void addItem(PairPathCost item);
    PairPathCost getItem();
    void removeItem();
    bool isEmpty();
    int getSize();
    std::string toString();

private:
    std::vector<PairPathCost> stack{};

};


#endif //SERVERUDP_STACK_H
