#ifndef ORDER_H
#define ORDER_H
#include <iostream>
#include <string>
#include <fstream>
using namespace std;

class Order{

	private:
		struct Node{
			int level;
			int coinOrder;
			string task;
			string task1;
			int amount;
			int amount1;
			int coinEarned;
			Node *next;
		};

		Node *front;
		Node *rear;

		int totalCoinEarned=0;
		int numItems=0;

	public:
		Order();

		~Order(){};

		void append(int , int , string,string,int,int);
		void deleteNode();
		void displayOrder() const;
		bool isEmpty() const;
		void calculate();
		int displayfinancial();
		string getTask();
		int getAmount();
		string getTask1();
		int getAmount1();
		void inputFile();
		void printToFile();
};
#endif
