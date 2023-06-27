#include "AnimalProduct.h"
#include <iostream>
#include <iomanip>
using namespace std;

// constructor
AnimalProduct::AnimalProduct(){
  front = nullptr;
  rear = nullptr;
  numItems = 0;
}

// destructor
AnimalProduct::~AnimalProduct(){
  clear();
}

// check whether the queue is empty or not
bool AnimalProduct::isEmpty() const{
  bool status;

  if(numItems>0)
    status = false;
  else
    status = true;

  return status;
}

// enqueue product (getProduct)
void AnimalProduct::enqueue(int n){
  QueueNode* newNode = nullptr;
  newNode = new QueueNode;
  newNode->productNum = n;
  newNode->next = nullptr;

  if(isEmpty()){
    front = newNode;
    rear = newNode;
  }
  else{
    rear->next = newNode;
    rear = newNode;
  }
  numItems++;
}

// dequeue product (complete order)
void AnimalProduct::dequeue(int &n){
  QueueNode* temp = nullptr;

  if(isEmpty()){
    cout<<"The queue is empty.";
  }
  else{
    n = front->productNum;

    temp = front;
    front = front->next;
    delete temp;

    numItems--;
  }
}

// count total product in the queue
void AnimalProduct::countProduct(){
    QueueNode *nodePtr = nullptr;
    nodePtr = front;

    while(nodePtr){
        totalProduct = totalProduct + (nodePtr->productNum);
        nodePtr = nodePtr->next;
    }
    setTotalProduct(totalProduct);
}

// set total product
void AnimalProduct::setTotalProduct(int t){
	totalProduct = t;
}

// get total product
int AnimalProduct::getTotalProduct(){
	return totalProduct;
}

// display all number of product
void AnimalProduct::displayProduct(){
	QueueNode *nodePtr;
    nodePtr = front;
    
    while(nodePtr){
    	cout << setw(3) << nodePtr->productNum << setw(3) <<"||";
		nodePtr = nodePtr->next;
	}
	cout << endl;
}

// for the destructor
void AnimalProduct::clear(){
  int productNum;             // Dummy variable for dequeue

  while(!isEmpty())
    dequeue(productNum);
}

// subtract
void AnimalProduct::subtract_2(int amt){
	QueueNode *nodePtr = nullptr;
    nodePtr = front;
    
    int num, diff;

	dequeue(num);
	
	if(amt > num)
	    diff = amt - num;
	else
	    diff = num - amt;
	    
	nodePtr->productNum = diff;
}

// compare when customer order is more
int AnimalProduct::compare_2(int amt){
	QueueNode *nodePtr = nullptr;
    nodePtr = front;
    
    int sum = nodePtr->productNum;
    int sum2 = 0, n;
    
	while(sum < amt){
		dequeue(n);
		sum2 += n;
		nodePtr = nodePtr->next;
		sum += (nodePtr->productNum);
	}
	return amt - sum2;
}

// return front value
int AnimalProduct::front_value(){
	return front->productNum;
}
