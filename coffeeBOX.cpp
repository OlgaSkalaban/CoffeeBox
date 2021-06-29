#include <iostream>
#include <cstdlib>
#include <string>
#include <windows.h>

using namespace std;

#define PIN 1151;
#define MAX_CAP 700;

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
void showMassage(string massage);
void progresBar();

double totalBYN = 0.0; //����� ������ ������� � ����������
int totalCups = 7;
double byn = 0.0;

int main()
{
	double priceE = 2.50;
	double priceC = 3.50;
	double priceL = 3.00;

	double totalSugar = 1000.0;
	int maxCups = 100;
	int usedCups = 0;

	int isBlockCoffeeBox = 0;

	while (true) {
		int startChoice;
		int coffeeChoice;
		int serviceChoice;
		int choiceSugar;

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
			if (isBlockCoffeeBox == 0)
				serviceMenu();
			else {
				showMassage("Your enter 3 times incorrect PIN. Coffe machine locked. Ask support service");
				break;
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
			Sleep(1000);
		}
		else if (userInput == pin)
			break;
		system("cls");
	}
	if (counter == 3)
		return 1;
	else
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

/*error
1 - You add cups less than 0
2 - Sum totalCups and new cups more than 700
*/
void serviceMenu() {
	int serviceChoise = -1;
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

		if (error == 1) {
			showMassage("You add cups less than 0");
		}
		else if (error == 2) {
			showMassage("You add cups more than can contain coffee machine");
		}
        }
}

void showMassage(string massage) {
	int choise = -1;
	system("cls");
	cout << massage << endl;
	cout << "0 - Back" << endl;
	cout << "Your choise: ";
	cin >> choise;
}

void showBalance() {
	int choise = -1;

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
	int addCups = 0;
        int maxForCheck = MAX_CAP;
        system("cls");
        cout << "*** COFFEEbox SERVICE MENU ***" << endl;
        cout << totalCups << " cups in a coffee machine" << endl;
	cout << "0 - Back to Service menu" << endl;
        cout << "Your choise: ";
        cin >> addCups;
        if (addCups < 0) {
                return 1;
        }
        else if ((addCups + totalCups) > maxForCheck){
                return 2;
        }
        else {
                totalCups += addCups;
                return 0;
        }
}

void takeOffAllMoney() {
	totalBYN = 0.0;
        byn = 0.0;
        int choise = 0;
        while (true) {
                system("cls");
                cout << "*** COFFEEbox SERVICE MENU ***" << endl;
                cout << "You take all money in a coffee machine. Total balance is " << totalBYN << endl;
                cout << "0 - Back to Service menu" << endl;
                cout << "Your choise: ";
                cin >> choise;
                if (choise == 0)
                        break;
        }
}

void makeCoffee()
{
	cout << "    " << "Your coffee is preparing..." << endl;
	progresBar();
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

void progresBar() {
        cout << "[";
        for (int i = 0; i < 100; i++) {
           Sleep(100);
           cout << "*";
        }
        cout << "]";
}
