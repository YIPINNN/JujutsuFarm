#ifndef ANIMALPRODUCT_H
#define ANIMALPRODUCT_H

class AnimalProduct{
	private:
		struct QueueNode{
			int productNum;
            QueueNode *next;
		};
		QueueNode *front;          // Subscript for the first element
        QueueNode *rear;           // Subscript for the element added
        int numItems;              // Number of items in the queue
        int totalProduct=0;

    public:
        AnimalProduct();                // constructor
        ~AnimalProduct();               // destructor

        void enqueue(int);
        void dequeue(int&);
        void countProduct();
        void setTotalProduct(int);
        int getTotalProduct();
        void displayProduct();
        bool isEmpty() const;
        void clear();
        void subtract_2(int);
        int compare_2(int);
        int front_value();
};
#endif
