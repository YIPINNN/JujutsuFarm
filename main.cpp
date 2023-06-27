#include "plantAndRear.h"
#include "AnimalProduct.h"
#include "PlantStack.h"
#include "Order.h"
#include <iostream>
#include <iomanip>
using namespace std;

void gameIntro();
void menu(int&);
void tutorial(string&);
const int PLANT_REAR = 1,
          ORDER = 2,
          INVENTORY = 3,
          COIN = 4,
          RESTORE = 5,
          QUIT = 6;

int main(){
	Order OD;

	plantAndRear PR;
	int choice, totalCoinEarned, amt, amt1;
	string playerName, ans, task, task1;
	OD.inputFile();
	gameIntro();
	tutorial(playerName);

	do{
		menu(choice);
		if(choice != QUIT){
			switch(choice){
				case PLANT_REAR: PR.askPlayer();
				                 break;

				case ORDER: 
				            OD.displayOrder();

										task = OD.getTask();
										amt =  OD.getAmount();
										task1 = OD.getTask1();
										amt1 =  OD.getAmount1();

										if(PR.Amount(task,amt) && PR.Amount(task1,amt1))
										{
											cout <<"Do you want to complete the following order? "<< endl;
											cout <<"--> ";   cin >> ans;

											if(ans == "yes"){
												PR.completeOrder(task,task1,amt,amt1);
												OD.deleteNode();
											}
										}
										else
										{
											cout << "you have not enough inventory.\n";
										}
					          break;

				case INVENTORY: PR.displayAllHarvest();
					              break;

				case RESTORE: PR.restoreProgress();
				              break;

				case COIN: totalCoinEarned = OD.displayfinancial();
				           cout <<"\nYour total coin earned: "<< totalCoinEarned <<" coin(s)"<< endl;
					         break;
			}
		}
	} while(choice != QUIT);

	PR.storeProgress();
	OD.printToFile();

	return 0;
}

void gameIntro(){
	  cout <<"       #  #     #        #  #     #  #######   #####   #     #      #######     #     ######   #     # "<< endl;
    cout <<"       #  #     #        #  #     #     #     #     #  #     #      #          # #    #     #  ##   ## "<< endl;
    cout <<"       #  #     #        #  #     #     #     #        #     #      #         #   #   #     #  # # # # "<< endl;
    cout <<"       #  #     #        #  #     #     #      #####   #     #      #####    #     #  ######   #  #  # "<< endl;
    cout <<" #     #  #     #  #     #  #     #     #           #  #     #      #        #######  #   #    #     # "<< endl;
    cout <<" #     #  #     #  #     #  #     #     #     #     #  #     #      #        #     #  #    #   #     # "<< endl;
    cout <<"  #####    #####    #####    #####      #      #####    #####       #        #     #  #     #  #     # "<< endl;


	cout <<"\n------------------------------------------- WELCOME PLAYER !!! ------------------------------------------\n\n";
}

void menu(int &choice){
	cout <<"__________________________________________________"<< endl;
	cout <<"| 1. Plant new crops and rear new animal         |"<< endl;
	cout <<"| 2. Complete customers' order                   |"<< endl;
	cout <<"| 3. Check inventory (only check after option 1) |"<< endl;
	cout <<"| 4. Check the amount of coins earned            |"<< endl;
	cout <<"| 5. Restore the game progress                   |"<< endl;
	cout <<"| 6. Quit                                        |"<< endl;
	cout <<"--------------------------------------------------"<< endl;
	cout <<"--> ";   cin >> choice;

	while(choice < PLANT_REAR || choice > QUIT){
		cout <<"Enter a valid choice --> ";   cin >> choice; cin.ignore();
	}
}

void tutorial(string &name){
	string playerAns;

	cout <<"Hi player! Nice to meet you!"<< endl;
	cout <<"My name is Ed and what's yours?"<< endl;
	cout <<"--> ";   getline(cin,name);

	cout <<"\nHi, "<< name <<". I will provide guidance to you for managing you Jujutsu Farm. "<< endl;
	cout <<"So, "<< name <<", are your ready for the next phase? "<< endl;
	cout <<"--> ";   cin >> playerAns;

	while(playerAns != "yes" && playerAns != "ready"){
		cout <<"\nHAHAHAHA, okey, I will wait for your ready."<< endl;
		cout <<"So, "<< name <<", are your ready for the next phase? "<< endl;
	    cout <<"--> ";   cin >> playerAns;
	}
	
	cout <<"\nA little reminder, planting and rearing more types of crops and animal are encouraged.\n";
}
