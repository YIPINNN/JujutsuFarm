#include "Order.h"
#include <iostream>
#include <string>
#include <fstream>
using namespace std;

Order::Order()
{
    front = nullptr;
    rear = nullptr;
    numItems = 0;
}

void Order::inputFile()
{
    fstream inFile;
    inFile.open("customerOrder.txt",ios::in);
    int l;
    int c;
    string t;
    string t1;
    int am;
    int am1;

    if(inFile.fail())
    {
        cout << "Error in opening source file."<<endl;
    }

    else
    {
    inFile >> totalCoinEarned;

    while(!inFile.eof())
    {
        inFile >> l;
        inFile >> c;
        inFile >> t;
        inFile >> t1;
        inFile >> am;
        inFile >> am1;

        if(l==1000)
            break;
        append(l,c,t,t1,am,am1);

    }
    }

    inFile.close();
}


void Order::append(int l,int c,string t,string t1,int a,int a1)
{
    Node *newNode , *nodePtr;
    newNode = new Node;
    newNode->level = l;
    newNode->coinOrder = c;
    newNode->task = t;
    newNode->task1 = t1;
    newNode->amount = a;
    newNode->amount1 = a1;

    newNode->next = nullptr;

    if(isEmpty())
    {
        front = newNode;
        rear = newNode;
    }
    else
    {
        rear->next = newNode;
        rear = newNode;
    }

     numItems++;
}


void Order::displayOrder() const
{

    if(isEmpty())
    {
        cout << "No order now.";
    }
    else
    {
    	cout << endl;
        cout << "************ Level "<< front->level <<" ************"<<endl;
        cout << "Task 1   : "  <<front->task << endl;
        cout << "Amount 1 : " <<front->amount<<endl;
        cout << "Task 2   : "  <<front->task1 << endl;
        cout << "Amount 2 : " <<front->amount1<<endl;
        cout << "Cost     : " << front->coinOrder << " coin(s) " <<endl<<endl;
    }
}

void Order::printToFile()
{
        fstream outFile;
        outFile.open("customerOrder.txt",ios::out);
        Node * nodePtr;
        nodePtr = front;
        int l,a,a1,c;
        string t,t1;
            if(outFile.fail())
    {
        cout << "Error in opening source file."<<endl;
    }
        else{
        outFile << totalCoinEarned<<endl;
        while(numItems>0)
        {
        l = nodePtr->level;
        a = nodePtr->amount;
        a1 = nodePtr->amount1;
        c = nodePtr->coinOrder;
        t = nodePtr->task;
        t1 = nodePtr->task1;

        outFile << l;
        outFile << " ";
        outFile << c;
        outFile << " ";
        outFile << t;
        outFile << " ";
        outFile << t1;
        outFile << " ";
        outFile << a;
        outFile << " ";
        outFile << a1;
        outFile <<endl;


        nodePtr = nodePtr ->next;
        numItems--;
        }
    }
        outFile << 1000;
        outFile.close();
}

void Order::calculate()
{
    totalCoinEarned = totalCoinEarned + front->coinOrder;
}

void Order::deleteNode()
{
    calculate();
    Node * temp = nullptr;
    temp = front;
    front = front->next;
    delete temp;

    numItems--;
}

int Order::displayfinancial()
{

    return totalCoinEarned;

}


bool Order::isEmpty() const
{
    bool status;

    if(numItems > 0)
        status = false;
    else
        status = true;

    return status;

}

string Order::getTask()
{
    string task;
    Node *nodePtr;
    nodePtr = front;
    task = nodePtr->task;

    return task;
}

int Order::getAmount()
{
    int amountOfOrder;
    Node *nodePtr;
    nodePtr = front;
    amountOfOrder = nodePtr->amount;

    return amountOfOrder;
}

string Order::getTask1()
{
    string task;
    Node *nodePtr;
    nodePtr = front;
    task = nodePtr->task1;
    return task;
}

int Order::getAmount1()
{
    int amountOfOrder;
    Node *nodePtr;
    nodePtr = front;
    amountOfOrder = nodePtr->amount1;
    return amountOfOrder;
}
