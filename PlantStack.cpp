#include "PlantStack.h"
#include <iostream>
#include <iomanip>
using namespace std;

// Constructor
PlantStack::PlantStack(){
    stackTop = nullptr;
}

// Destructor
PlantStack::~PlantStack(){
    clear();
}

// clear all stack
void PlantStack::clear(){
    StackNode* temp;

    while(stackTop != nullptr){
        temp = stackTop;
        stackTop = stackTop->next;
        delete temp;
    }
}

// isEmptyStack()
bool PlantStack::isEmptyStack() const{
    if(!stackTop)
        return true;
    else
        return false;
}

// push() function
void PlantStack::push(int n){
    StackNode* newNode = nullptr;
    newNode = new StackNode;
    newNode->numPlant = n;

    if(isEmptyStack()){
        stackTop = newNode;
        newNode->next = nullptr;
    }
    else{
        newNode->next = stackTop;
        stackTop = newNode;
    }
}

// pop() function
void PlantStack::pop(int &n){
    StackNode* temp = nullptr;

    if(isEmptyStack()){
        cout<<"The stack is empty. Nothing to pop.\n";
    }
    else{
        n = stackTop->numPlant;
        temp = stackTop->next;
        delete stackTop;
        stackTop = temp;
    }
}

// display the stack
void PlantStack::displayStack(){
    StackNode *nodePtr;
    nodePtr = stackTop;

    while(nodePtr){
        cout <<"|"<< setw(3) << nodePtr->numPlant << setw(3) <<"|\n";
        cout <<"------"<< endl;
        nodePtr = nodePtr->next;
    }
}

// count total harvest in the stack
void PlantStack::countHarvest(){
    StackNode *nodePtr;
    nodePtr = stackTop;

    int sum=0;

    while(nodePtr){
        sum += (nodePtr->numPlant);
        nodePtr = nodePtr->next;
    }
    setTotalHarvest(sum);
}

// set total harvesting
void PlantStack::setTotalHarvest(int t){
    totalHarvest = t;
}

// get total harvesting
int PlantStack::getTotalHarvest(){
    return totalHarvest;
}

// subtract
void PlantStack::subtract(int amt){
    int num, diff;

    pop(num);

    if(amt > num)
        diff = amt - num;
    else
        diff = num - amt;

    push(diff);
}

// compare when customer order is more
int PlantStack::compare(int amt){
    StackNode *nodePtr;
    nodePtr = stackTop;
    int sum = nodePtr->numPlant;
    int sum2 = 0, n;

    while(sum < amt){
        pop(n);
        sum2 += n;
        nodePtr = nodePtr->next;
        sum += (nodePtr->numPlant);
    }
    return amt - sum2;
}

// return value of stack top
int PlantStack::stackTop_value(){
    return stackTop->numPlant;
}
