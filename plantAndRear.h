#ifndef PLANTANDREAR_H
#define PLANTANDREAR_H
#include "AnimalProduct.h"
#include "PlantStack.h"
#include "Order.h"
#include <string>
#include <iostream>
using namespace std;

class plantAndRear{
	private:
		string playerChoice, product,
		       seedType, animalType, harvestItem;
	    int	seedNum, animalNum, harvestNum, productNum;
	    AnimalProduct Egg, Milk, Wool, Fish;
	    PlantStack Corn, Paddy, SoyBean, Potato, Tomato;
	    int corn, paddy, soybean, potato, tomato,
	        egg, milk, wool, fish;

	public:
		void askPlayer();
		void plantSeed_phase1();
		void animalList();
		void plant(int);
		void setSeedType(string);
		void setHarvestNum(int);
		void setProductNum(int);
		int getHarvestNum();
		int getProductNum();
		void calcProductNum(int);
		void harvest(PlantStack&);
		void getProduct(AnimalProduct&);
		void displayAllHarvest();
		void countingHarvest();
		void completeOrder(string,string,int,int);
		void storeProgress();
		void restoreProgress();
		bool Amount(string,int);
};
#endif
