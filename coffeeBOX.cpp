#include <iostream>
#include <cstdlib>
#include <cmath>

using namespace std;

void showStartMenu();
void showCoffeeMenu();
void showServiceMenu();
int passwordVerification();
double getMoney(double price);
void makeCoffee();
void offerSugar();

int main()
{
	double totalBYN = 0.0; //общий баланс средств в кофемашине
	double priceE = 2.50;
	double priceC = 3.50;
	double priceL = 3.00;
	double portionSugarWeight = 5.0;
	double totalSugar = 1000.0;
	//int maxCups = 100;
	
	while (true) {
		int startChoice;
		int coffeeChoice;
		int serviceChoice;
		int choiceSugar;
		int countPortionSugar;
		double usedSugar = 0.0;	
		double byn = 0.0;
		//int restCups = maxCups - usedCups;		
		//int usedCups = 0;
		
		showStartMenu();
		cout << "Your choice? ";
		cin >> startChoice;
		system("cls");
		
		if (startChoice == 1)
		{
			showCoffeeMenu();
			cout << "Your choice? ";
			cin >> coffeeChoice;
			system("cls");
		
			if (coffeeChoice == 0) {
				break;
			}	   
			else if (coffeeChoice == 1)
			{
				offerSugar();
				cout << "Your choice? " << endl;
				cin >> choiceSugar;
				if (choiceSugar == 1)
				{
					cout << "How many portions of sugar to add?" << endl;
					cin >> countPortionSugar;
					
					usedSugar = countPortionSugar * portionSugarWeight;
				}
				totalSugar -= usedSugar;
				//cout << "Rest of sugar " << totalSugar << endl;
				system("cls");
				cout << "Please, pay the drink fee: " << priceE << " BYN" << endl;
				cout << endl;
	    		byn += getMoney(priceE);
	    		makeCoffee();
	    		system("cls");
			}
	    	else if (coffeeChoice == 2)
			{
				offerSugar();
				cout << "Your choice? " << endl;
				cin >> choiceSugar;
				if (choiceSugar == 1)
				{
					cout << "How many portions of sugar to add?" << endl;
					cin >> countPortionSugar;
					
					usedSugar = countPortionSugar * portionSugarWeight;
				}
				totalSugar -= usedSugar;
				system("cls");
				cout << "Please, pay the drink fee: " << priceC << " BYN" << endl;
				cout << endl;
	    		byn += getMoney(priceC);
	    		makeCoffee();
	    		system("cls");
			}
			else if (coffeeChoice == 3)
			{
				offerSugar();
				cout << "Your choice? " << endl;
				cin >> choiceSugar;
				if (choiceSugar == 1)
				{
					cout << "How many portions of sugar to add?" << endl;
					cin >> countPortionSugar;
					
					usedSugar = countPortionSugar * portionSugarWeight;
				}
				totalSugar -= usedSugar;
				system("cls");
				cout << "Please, pay the drink fee: " << priceL << " BYN" << endl;
				cout << endl;
	    		byn += getMoney(priceL);
	    		makeCoffee();
	    		system("cls");
			}
			else {
				cout << "Please, input [0...4]!" << endl;
			}
			
			totalBYN += byn;	
	    	
		}
		else if (startChoice == 2)
		{
			passwordVerification();
			showServiceMenu();
			cout << "Your choice? ";
			cin >> serviceChoice;
			
			system("cls");
		}
		else if (startChoice == 0)
		{
			break;
		}
		else
		{
			cout << "Please, input [1/2]" << endl;
		}
		
	}
	return 0;
}

void showStartMenu()
{
	cout << "*** CoffeeBOX MENU ***" << endl;
	cout << endl;
	cout << "\t" << "Welcome!" << endl;
	cout << endl;
	cout << "1 - Choose coffee" << endl;
	cout << "2 - Service menu" << endl;
	cout << "0 - Exit" << endl;
	cout << endl;
}

void showCoffeeMenu()
{
	cout << "*** COFFEEbox MENU ***" << endl;
	cout << endl;
	cout << "1 - Espresso     2.5 BYN" << endl;	
	cout << "2 - Cappuccino   3.5 BYN" << endl;
	cout << "3 - Latte        3.0 BYN" << endl;	
	cout << "0 - Exit" << endl;
	cout << endl;
}

double getMoney(double price)
{
	double cash = 0.0;
	double sumCash = 0.0;
	double rest;
	double restPrice = price;
	while (sumCash < price)
	{
		cout << "Total: " << sumCash << " BYN" << endl;
		cout << endl;
		cout << "Attention! CoffeeBOX doesn't give change!!\n";
		cout << "You can deposit: 50 penny, 1 BYN, 2 BYN" << endl;
		cin >> cash;		
		
		rest = abs(restPrice - cash);
		sumCash += cash;
		restPrice = price - sumCash;
				
		cout << endl;	
		cout << "OK! " << cash << " BYN is received! You need to pay more " << rest << " BYN" << endl;			
		cout << endl;
	}
	system("cls");	
	return sumCash;
}

int passwordVerification()
{
	int pin = 1511;
	int userInput;
	
	while (userInput != pin)
	{
		cout << "Please, enter PIN: " << endl;
		cin >> userInput;
		if (userInput != pin)
			cout << "Invalid password! Please, try again!" << endl;		
	}
	system("cls");	
	return 0;
}
void showServiceMenu()
{
	cout << "*** COFFEEbox SERVICE MENU ***" << endl;
	cout << endl;
	//cout << "TOTAL BALANCE: " << byn << " BYN";
	cout << endl;
	cout << "1 - Show total balance" << endl;
	cout << "2 - Rest of the cups" << endl;
	cout << "3 - Take off all money" << endl;
	cout << "0 - Exit" << endl;
	cout << endl;
}

void makeCoffee()
{
	cout << "Please, wait! Your coffee is made..." << endl;
	cout << endl;
	//sleep_for(milliseconds(3000));
	cout << "Take your coffee! Bon appetit!" << endl;
}

void offerSugar()
{
	cout << "Do you want some sugar?" << endl;
	cout << endl;
	cout << "1 - Yes" << endl;
	cout << "0 - No" << endl;		
}
