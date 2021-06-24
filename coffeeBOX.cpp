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

int main()
{
	double totalBYN = 0.0; //общий баланс средств в кофемашине
	double priceE = 2.50;
	double priceC = 3.50;
	double priceL = 3.00;
	
	while (true) {
		int startChoice;
		int coffeeChoice;
		int serviceChoice;
				
		double byn = 0.0;
		
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
			/*else if (choice == 1)
			{
				passwordVerification();
			
			}*/	   
			else if (coffeeChoice == 2)
			{
				//
				cout << "Pay the drink fee: " << priceE << " BYN" << endl;
	    		byn += getMoney(priceE);
	    		makeCoffee();
			}
	    	else if (coffeeChoice == 3)
			{
				cout << "Pay the drink fee: " << priceC << " BYN" << endl;
	    		byn += getMoney(priceC);
	    		makeCoffee();
			}
			else if (coffeeChoice == 4)
			{
				cout << "Pay the drink fee: " << priceL << " BYN" << endl;
	    		byn += getMoney(priceL);
	    		makeCoffee();
	    		system("cls");
			}
			else {
				cout << "Please, input [0...4]!" << endl;
			}
			totalBYN += byn;	
	    	cout << "Balance COFFEEbox " << totalBYN << " BYN" << endl;
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
	cout << "*** COFFEEbox MENU ***" << endl;
	cout << endl;
	cout << "1 - Choose type of coffee" << endl;
	cout << "2 - Service menu" << endl;
	cout << "0 - Exit" << endl;
	cout << endl;
}

void showCoffeeMenu()
{
	cout << "*** COFFEEbox MENU ***" << endl;
	cout << endl;
	cout << "4 - Latte" << endl;
	cout << "3 - Cappuccino" << endl;
	cout << "2 - Espresso" << endl;
	//cout << "1 - Service menu" << endl;
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
		cout << "You can deposit: 50 penny, 1 BYN, 2 BYN" << endl;
		cout << "!! WARNING: COFFEEbox doesn't give change!!\n";
		cin >> cash;		
		
		rest = abs(restPrice - cash);
		sumCash += cash;
		restPrice = price - sumCash;		
			
		cout << "OK! " << cash << " BYN is received! You need do pay more " << rest << " BYN" << endl;		
		cout << "Total " << sumCash << " BYN" << endl;
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
	cout << "1 - Show total balance" << endl;
	cout << "2 - Rest of the cups" << endl;
	cout << "3 - Take off all money" << endl;
	//cout << "1 - Service menu" << endl;
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
