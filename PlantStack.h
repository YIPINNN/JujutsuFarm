#ifndef PLANTSTACK_H
#define PLANTSTACK_H

class PlantStack{
    private:
        struct StackNode{
            int numPlant;
            StackNode* next;
        };
        StackNode* stackTop;
        int totalHarvest=0;

  public:
        PlantStack();
        ~PlantStack();
        void clear();
        bool isEmptyStack() const;
        void push(int);
        void pop(int&);
        void displayStack();
        void countHarvest();
        void setTotalHarvest(int);
        int getTotalHarvest();
        void subtract(int);
        int compare(int);
        int stackTop_value();
};
#endif
