#include <iostream>
#include <cstdlib>

using namespace std;

#define PIN 1151;

void showStartMenu();
void showCoffeeMenu();
void showServiceMenu();
int passwordVerification();
double getMoney(double price);
void makeCoffee();
void offerSugar();
int addSugars();

void serviceMenu();
void showBalance();
int restCups();
void takeOffAllMoney();

double totalBYN = 0.0; //����� ������ ������� � ����������

int main()
{
	double priceE = 2.50;
	double priceC = 3.50;
	double priceL = 3.00;

	double totalSugar = 1000.0;
	int maxCups = 100;
	int totalCups = maxCups;
	int usedCups = 0;

	int isBlockCoffeeBox = 0;

	while (true) {
		int startChoice;
		int coffeeChoice;
		int serviceChoice;
		int choiceSugar;
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
			else if (coffeeChoice == 1)
			{
				offerSugar();
				cout << "Your choice? " << endl;
				cin >> choiceSugar;
				system("cls");

				if (choiceSugar == 1)
				{
					totalSugar -= addSugars();
				}

				system("cls");
	    		byn += getMoney(priceE);
	    		makeCoffee();
	    		usedCups++;
	    		totalCups -= usedCups;
			}
	    	else if (coffeeChoice == 2)
			{
				offerSugar();
				cout << "Your choice? " << endl;
				cin >> choiceSugar;
				system("cls");
				if (choiceSugar == 1)
				{
					totalSugar -= addSugars();
				}

				system("cls");
	    		byn += getMoney(priceC);
	    		makeCoffee();
				usedCups++;
	    		totalCups -= usedCups;
			}
			else if (coffeeChoice == 3)
			{
				offerSugar();
				cout << "Your choice? " << endl;
				cin >> choiceSugar;
				system("cls");
				if (choiceSugar == 1)
				{
					totalSugar -= addSugars();
				}

				system("cls");
	    		byn += getMoney(priceL);
	    		makeCoffee();
	    		usedCups++;
	    		totalCups -= usedCups;
			}
			else {
				cout << "Please, input [0...3]!" << endl;
			}

			totalBYN += byn;

		}
		else if (startChoice == 2)
		{
			isBlockCoffeeBox = passwordVerification();
			showServiceMenu();


			cout << "Your choice? ";
			cin >> serviceChoice;

			system("cls");
			if (serviceChoice == 1)
			{
				cout << "\t" << "TOTAL BALANCE is " << totalBYN << " BYN" << endl;
			}
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
	system("cls");
	return 0;
}

void showStartMenu()
{
	cout << "   " << "*** CoffeeBOX MENU ***" << endl;
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
		cout << "   " << "Please, pay the drink fee: " << price << " BYN" << endl;
		cout << endl;
		cout << "You can deposit: 50 penny, 1 BYN, 2 BYN" << endl;
		cout << "ATTENTION! CoffeeBOX doesn't give change!\n";

		cout << "\t" << "  " << "TOTAL: " << sumCash << " BYN" << endl;
		cout << endl;
		cout << "Your fee: ";
		cin >> cash;

		sumCash += cash;
		restPrice = price - sumCash;

		system("cls");
	}
	return sumCash;
}


//return 1 if you enter incorrect pin 3 times
int passwordVerification()
{
	int pin = PIN;
	int userInput;
	int counter = 0;

	while (counter != 3)
	{
		cout << "Please, enter PIN: " << endl;
		cin >> userInput;
		if (userInput != pin) {
			cout << "Invalid password! Please, try again!" << endl;
			counter++;
		}
		else if (userInput == pin)
			break;
	}
	if (counter == 3)
		return 1;
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

void serviceMenu() {
	int serviceChoise = 0;
        int error = 0;

        while(true) {
                system("cls");
                showServiceMenu();

                cout << "Your choise: ";
                cin >> serviceChoise;
                if (serviceChoise == 1) {
                        showBalance();
                }
                else if (serviceChoise == 2) {
                        error = restCups();
                }
                else if (serviceChoise == 3) {
                        takeOffAllMoney();
                }
                else if (serviceChoise == 0) {
                        break;
                }


        }
}

void showBalance() {
	int choise = 0;

        while (true) {
                system("cls");
                cout << "*** COFFEEbox SERVICE MENU ***" << endl;
                cout << totalBYN << " rubles in a coffee machine" << endl;
                cout << "0 - Back to Service menu" << endl;
                cout << "Your choise: ";
                cin >> choise;
                if (choise == 0)
                        break;
        }
}

int restCups() {

	return 0;
}

void takeOffAllMoney() {

}

void makeCoffee()
{
	cout << "    " << "Your coffee is preparing..." << endl;
	cout << "|||||||||||||||||||||||||||||||||||" << endl;
	cout << "       " << "Coffee is ready!" << endl;
	cout << endl;
	cout << "          " << "Thank you!" << endl;
	cout << "       " << "Have a nice day!"<< endl;
	cout << endl;
}

void offerSugar()
{
	cout << "Do you want some sugar?" << endl;
	cout << endl;
	cout << "1 - Yes" << endl;
	cout << "0 - No" << endl;
}

int addSugars()
{
	int countPortionSugar;
	double usedSugar = 0.0;
	double portionSugarWeight = 5.0;

	cout << "How many sugars to add?" << endl;
	cin >> countPortionSugar;
	usedSugar = countPortionSugar * portionSugarWeight;
	return usedSugar;
}
