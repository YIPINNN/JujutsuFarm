#include "plantAndRear.h"
#include "AnimalProduct.h"
#include "PlantStack.h"
#include "Order.h"
#include <iostream>
#include <iomanip>
#include <fstream>
using namespace std;

// plant or rear
void plantAndRear::askPlayer(){
	do{
		cout <<"\n***********************************************************"<< endl;
		cout <<"Do you want to plant new crops or rear new animal? "<< endl;
		cout <<"Type 'no' if you do not want to do the activities above.\n";
		cout <<"--> ";
		cin >> playerChoice;
		cin.ignore();

		if(playerChoice == "plant")
		{
			plantSeed_phase1();
		}
		else if(playerChoice == "rear")
		{
			animalList();
		}
	} while(playerChoice != "no");

	countingHarvest();
}

// display plant list & let player to choose what to plant
void plantAndRear::plantSeed_phase1(){
	cout <<"\nIn the first phase, we have the seeds of: "<< endl;
	cout <<"-----------------------------------------------"<< endl;
	cout <<"|  corn   paddy   soy bean   potato   tomato  |"<< endl;
	cout <<"-----------------------------------------------"<< endl;
	cout <<"Select your desired seeds: ";   getline(cin,seedType);

	while(seedType!= "corn" && seedType!= "paddy" && seedType!= "soy bean" && seedType!= "potato" && seedType!= "tomato"){
		cout <<"\nYou have entered an unvalid type of seeds.\n";
		cout <<"Try to enter the type of seeds based on the choices above.\n";
		cout <<"Select your desired seeds: ";   getline(cin,seedType);
	}

	cout <<"\n:) Warm reminder: For instance, you will harvest 5 corns for planting 1 seed of corn.";
	cout <<"\n                  Maximum seeds that you are allowed to plant for one time is 5."<< endl;
	cout <<"\nHow many seeds do you wish to plant: ";   cin >> seedNum;

	while(seedNum<1 || seedNum>5){
		cout <<"You have entered an unvalid number.\n";
		cout <<"Try to enter the number between 1 to 5.\n";
		cout <<"How many "<< seedType <<" seeds do you wish to plant: ";   cin >> seedNum;   cin.ignore();
	}
	setSeedType(seedType);
	plant(seedNum);

	if(seedType == "corn"){
		harvest(Corn);
		cout <<"------"<< endl;
		Corn.displayStack();
	}
	else if(seedType == "paddy"){
		harvest(Paddy);
		cout <<"------"<< endl;
		Paddy.displayStack();
	}
	else if(seedType == "soy bean"){
		harvest(SoyBean);
		cout <<"------"<< endl;
		SoyBean.displayStack();
	}
	else if(seedType == "potato"){
	    harvest(Potato);
	    cout <<"------"<< endl;
	    Potato.displayStack();
	}
	else if(seedType == "tomato"){
		harvest(Tomato);
		cout <<"------"<< endl;
		Tomato.displayStack();
	}

	cout <<"\nYeah! You have earned "<< harvestNum <<" of "<< seedType <<"(s)."<< endl;
}

// display animal list & let player to choose what to rear
void plantAndRear::animalList(){
	cout <<"\nThese are the available animal in our market."<< endl;
	cout <<"-----------------------------------"<< endl;
	cout <<"|  chicken   cow   sheep   fish   |"<< endl;
	cout <<"-----------------------------------"<< endl;
	cout <<"Select your desired animal: ";   getline(cin,animalType);

	while(animalType!= "chicken" && animalType!= "cow" && animalType!= "sheep" && animalType!= "fish"){
		cout <<"You have entered an unvalid type of animal.\n";
		cout <<"Try to enter the type of animal based on the choices above.\n";
		cout <<"Select your desired animal: ";   getline(cin,animalType);
		// can add the name of player that set by the player.
	}

	cout <<"\n:) Warm reminder: For instance, you will get 5 eggs for rearing 1 chicken.";
	cout <<"\n                  Maximum number of animal that you are allowed to rear for one time is 5."<< endl;
	cout <<"\nHow many "<< animalType <<" do you wish to rear: ";   cin >> animalNum;

	while(animalNum<1 || animalNum>5){
		cout <<"You have entered an unvalid number.\n";
		cout <<"Try to enter the number between 1 to 5.\n";
		cout <<"How many "<< animalType <<" do you wish to rear: ";   cin >> animalNum;   cin.ignore();
		// can add the name of player that set by the player.
	}
	cout <<"\nYeah! You have reared "<< animalNum <<" "<< animalType <<"(s)."<< endl;

	calcProductNum(animalNum);

	if(animalType == "chicken"){
		cout <<"\nYou have gained "<< productNum <<" eggs."<< endl;
		getProduct(Egg);
		cout <<"\n||";
	    Egg.displayProduct();
	}
	else if(animalType == "cow"){
		cout <<"\nYou have gained "<< productNum <<" bottles of milk."<< endl;
	    getProduct(Milk);
	    cout <<"\n||";
	    Milk.displayProduct();
	}
	else if(animalType == "sheep"){
		cout <<"\nYou have gained "<< productNum <<" units of wool."<< endl;
	    getProduct(Wool);
	    cout <<"\n||";
	    Wool.displayProduct();
	}
	else if(animalType == "fish"){
		cout <<"\nYou have gained "<< productNum <<" fish."<< endl;
	    getProduct(Fish);
	    cout <<"\n||";
	    Fish.displayProduct();
	}
}

// set the seed type
void plantAndRear::setSeedType(string s){
	seedType = s;
}

// get the seed type
//string plantAndRear::getSeedType(){
//	return seedType;
//}

// plant the selected number of seeds & get the harvesting
void plantAndRear::plant(int n){
	harvestNum = n * 5;

	setHarvestNum(harvestNum);
}

// set harvestNum
void plantAndRear::setHarvestNum(int h){
	harvestNum = h;
}

// get harvestNum
int plantAndRear::getHarvestNum(){
	return harvestNum;
}

// set productNum
void plantAndRear::setProductNum(int p){
	productNum = p;
}

// get productNum
int plantAndRear::getProductNum(){
	return productNum;
}

// rear the selected number of animal & get product
void plantAndRear::calcProductNum(int n){
	setProductNum(n * 5);
}

// harvest the number of seeds*5 & push it into stack
void plantAndRear::harvest(PlantStack &PS){
  PS.push(harvestNum);        // PlantStack
}

// get the product made by the animal & enqueue it
void plantAndRear::getProduct(AnimalProduct &AP){
	AP.enqueue(productNum);     // AnimalProduct;
}

// display Inventory
void plantAndRear::displayAllHarvest(){
    cout <<"\n-----------------YOUR CROPS----------------\n\n";
	cout <<"Total harvest of corn    : "<< Corn.getTotalHarvest() << endl;
	cout <<"Total harvest of paddy   : "<< Paddy.getTotalHarvest() << endl;
	cout <<"Total harvest of soy bean: "<< SoyBean.getTotalHarvest() << endl;
	cout <<"Total harvest of potato  : "<< Potato.getTotalHarvest() << endl;
	cout <<"Total harvest of tomato  : "<< Tomato.getTotalHarvest() << endl;

	cout <<"\n---------------YOUR PRODUCTS---------------\n\n";
	cout <<"Total number of egg          : "<< Egg.getTotalProduct() << endl;
	cout <<"Total number of milk (bottle): "<< Milk.getTotalProduct() << endl;
	cout <<"Total number of wool         : "<< Wool.getTotalProduct() << endl;
	cout <<"Total number of fish         : "<< Fish.getTotalProduct() << endl;
}

// count the harvest
void plantAndRear::countingHarvest(){
	cout <<"\nCounting the harvest...\n";
	Corn.countHarvest();
	Paddy.countHarvest();
	SoyBean.countHarvest();
	Potato.countHarvest();
	Tomato.countHarvest();
	Egg.countProduct();
	Milk.countProduct();
	Wool.countProduct();
	Fish.countProduct();
}

// complete order
void plantAndRear::completeOrder(string task1, string task2, int amt1, int amt2){
	int num;

	if(task1 == "corn"){
		if(Corn.stackTop_value() == amt1){
			Corn.pop(num);
		}
		else if(Corn.stackTop_value() > amt1){
			Corn.subtract(amt1);
		}
		else{
			Corn.subtract(Corn.compare(amt1));
		}
	}
	if(task1 == "paddy"){
		if(Paddy.stackTop_value() == amt1){
			Paddy.pop(num);
		}
		else if(Paddy.stackTop_value() > amt1){
			Paddy.subtract(amt1);
		}
		else{
			Paddy.subtract(Paddy.compare(amt1));
		}
	}
	if(task1 == "soy bean"){
		if(SoyBean.stackTop_value() == amt1){
			SoyBean.pop(num);
		}
		else if(SoyBean.stackTop_value() > amt1){
			SoyBean.subtract(amt1);
		}
		else{
			SoyBean.subtract(SoyBean.compare(amt1));
		}
	}
	if(task1 == "potato"){
	    if(Potato.stackTop_value() == amt1){
			Potato.pop(num);
		}
		else if(Potato.stackTop_value() > amt1){
			Potato.subtract(amt1);
		}
		else{
			Potato.subtract(Potato.compare(amt1));
		}
	}
	if(task1 == "tomato"){
		if(Tomato.stackTop_value() == amt1){
			Tomato.pop(num);
		}
		else if(Tomato.stackTop_value() > amt1){
			Tomato.subtract(amt1);
		}
		else{
			Tomato.subtract(Tomato.compare(amt1));
		}
	}
	if(task1 == "egg"){
		if(Egg.front_value() == amt1){
		    Egg.dequeue(num);
		}
		else if(Egg.front_value() > amt1){
			Egg.subtract_2(amt1);
		}
		else{
			Egg.subtract_2(Egg.compare_2(amt1));
		}
	}
	if(task1 == "milk"){
		if(Milk.front_value() == amt1){
		    Milk.dequeue(num);
		}
		else if(Egg.front_value() > amt1){
			Milk.subtract_2(amt1);
		}
		else{
			Milk.subtract_2(Milk.compare_2(amt1));
		}
	}
	if(task1 == "wool"){
		if(Wool.front_value() == amt1){
		    Wool.dequeue(num);
		}
		else if(Wool.front_value() > amt1){
			Wool.subtract_2(amt1);
		}
		else{
			Wool.subtract_2(Wool.compare_2(amt1));
		}
	}
	if(task1 == "fish"){
		if(Fish.front_value() == amt1){
		    Fish.dequeue(num);
		}
		else if(Fish.front_value() > amt1){
			Fish.subtract_2(amt1);
		}
		else{
			Fish.subtract_2(Fish.compare_2(amt1));
		}
	}


	if(task2 == "corn"){
		if(Corn.stackTop_value() == amt2){
			Corn.pop(num);
		}
		else if(Corn.stackTop_value() > amt2){
			Corn.subtract(amt2);
		}
		else{
			Corn.subtract(Corn.compare(amt2));
		}
	}
	if(task2 == "paddy"){
		if(Paddy.stackTop_value() == amt2){
			Paddy.pop(num);
		}
		else if(Paddy.stackTop_value() > amt2){
			Paddy.subtract(amt2);
		}
		else{
			Paddy.subtract(Paddy.compare(amt2));
		}
	}
	if(task2 == "soy bean"){
		if(SoyBean.stackTop_value() == amt2){
			SoyBean.pop(num);
		}
		else if(SoyBean.stackTop_value() > amt2){
			SoyBean.subtract(amt2);
		}
		else{
			SoyBean.subtract(SoyBean.compare(amt2));
		}
	}
	if(task2 == "potato"){
	    if(Potato.stackTop_value() == amt2){
			Potato.pop(num);
		}
		else if(Potato.stackTop_value() > amt2){
			Potato.subtract(amt2);
		}
		else{
			Potato.subtract(Potato.compare(amt2));
		}
	}
	if(task2 == "tomato"){
		if(Tomato.stackTop_value() == amt2){
			Tomato.pop(num);
		}
		else if(Tomato.stackTop_value() > amt2){
			Tomato.subtract(amt2);
		}
		else{
			Tomato.subtract(Tomato.compare(amt2));
		}
	}
	if(task2 == "egg"){
		if(Egg.front_value() == amt2){
		    Egg.dequeue(num);
		}
		else if(Egg.front_value() > amt2){
			Egg.subtract_2(amt2);
		}
		else{
			Egg.subtract_2(Egg.compare_2(amt2));
		}
	}
	if(task2 == "milk"){
		if(Milk.front_value() == amt2){
		    Milk.dequeue(num);
		}
		else if(Egg.front_value() > amt2){
			Milk.subtract_2(amt2);
		}
		else{
			Milk.subtract_2(Milk.compare_2(amt2));
		}
	}
	if(task2 == "wool"){
		if(Wool.front_value() == amt2){
		    Wool.dequeue(num);
		}
		else if(Wool.front_value() > amt2){
			Wool.subtract_2(amt2);
		}
		else{
			Wool.subtract_2(Wool.compare_2(amt2));
		}
	}
	if(task2 == "fish"){
		if(Fish.front_value() == amt2){
		    Fish.dequeue(num);
		}
		else if(Fish.front_value() > amt2){
			Fish.subtract_2(amt2);
		}
		else{
			Fish.subtract_2(Fish.compare_2(amt2));
		}
	}
}

// store progress from game
void plantAndRear::storeProgress()
{
	fstream outFile;
	outFile.open("gameProgress.txt",ios::out);

	if(outFile.fail())
	{
		cout << "Error in opening \"gameProgress\" txt file.";
	}
	else
	{
		outFile << Corn.getTotalHarvest() <<" ";
		outFile << Paddy.getTotalHarvest() <<" ";
		outFile << SoyBean.getTotalHarvest() <<" ";
		outFile << Potato.getTotalHarvest() <<" ";
		outFile << Tomato.getTotalHarvest() <<" ";
		outFile << Egg.getTotalProduct() <<" ";
		outFile << Milk.getTotalProduct() <<" ";
		outFile << Wool.getTotalProduct() <<" ";
		outFile << Fish.getTotalProduct() <<" ";
	}

	outFile.close();
}

//
void plantAndRear::restoreProgress(){
	ifstream read;
	int num;

	read.open("gameProgress.txt");

	if(read.fail())
	{
		cout << "Error in opening \"gameProgress\" txt file.";
	}
	else
	{
		read >> num;
		if(num>0)
		  Corn.push(num);

		read >> num;
		if(num>0)
		  Paddy.push(num);

		read >> num;
		if(num>0)
		  SoyBean.push(num);

		read >> num;
		if(num>0)
		  Potato.push(num);

		read >> num;
		if(num>0)
		  Tomato.push(num);

		read >> num;
		if(num>0)
		  Egg.enqueue(num);

		read >> num;
		if(num>0)
		  Milk.enqueue(num);

		read >> num;
		if(num>0)
		  Wool.enqueue(num);

		read >> num;
		if(num>0)
		  Fish.enqueue(num);
	}

	read.close();
}

bool plantAndRear::Amount(string t,int a)
{

	if(t=="corn")
	{
		if(Corn.getTotalHarvest()>=a)
			return true;
		else
			return false;
	}
	else if(t=="paddy")
	{
		if(Paddy.getTotalHarvest()>=a)
			return true;
		else
			return false;
	}
	else if(t=="soybean")
	{
		if(SoyBean.getTotalHarvest()>=a)
			return true;
		else
			return false;
	}
	else if(t=="potato")
	{
		if(Potato.getTotalHarvest()>=a)
			return true;
		else
			return false;
	}
	else if(t=="tomato")
	{
		if(Tomato.getTotalHarvest()>=a)
			return true;
		else
			return false;
	}
	else if(t=="egg")
	{
		if(Egg.getTotalProduct()>=a)
			return true;
		else
			return false;
	}
	else if(t=="milk")
	{
		if(Milk.getTotalProduct()>=a)
			return true;
		else
			return false;
	}
	else if(t=="wool")
	{
		if(Wool.getTotalProduct()>=a)
			return true;
		else
			return false;
	}
	else if(t=="fish")
	{
		if(Fish.getTotalProduct()>=a)
			return true;
		else
			return false;
	}

	else
		return false;
}
