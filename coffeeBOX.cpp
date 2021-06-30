#include <iostream>
#include <cstdlib>
#include <string>
#include <windows.h>

using namespace std;

#define PIN 1151;
#define MAX_CAP 700;

const double priceE = 2.70;
const double priceC = 3.20;
const double priceL = 3.00;

void showStartMenu();
int controlBalance(double sumCash, double price);
void showServiceMenu();
int passwordVerification();
void getMoney();
void makeCoffee();

void serviceMenu();
void showBalance();
int restCups();
void takeOffAllMoney();
void showMessage(string message);
void progressBar();

double totalBYN = 0.0; 
int totalCups = 7;
double byn = 0.0;

int main()
{
	int usedCups = 0;
	int startChoice;
	int isBlockCoffeeBox = 0;
	
	while (true) {
		
		int serviceChoice;

		showStartMenu();
		cout << "Your choice? ";
		cin >> startChoice;
		system("cls");
		
		if (startChoice == 1) {
			getMoney();			 
		}
		else if (startChoice == 2)
		{
			controlBalance(byn, priceE);
			makeCoffee();
			byn -= priceE;
			system("cls");
			usedCups++;
			totalCups -= usedCups;			
		}
		else if (startChoice == 3)
		{
			controlBalance(byn, priceC);
			makeCoffee();
			byn -= priceC;
			system("cls");
			usedCups++;
			totalCups -= usedCups;			
		}
		else if (startChoice == 4)
		{
			controlBalance(byn, priceL);
			makeCoffee();
			byn -= priceL;
			system("cls");
			usedCups++;
			totalCups -= usedCups;			
		}
		else if (startChoice == 5)
		{
			isBlockCoffeeBox = passwordVerification();
			if (isBlockCoffeeBox == 0)
				serviceMenu();
			else {
				showMessage("Your enter 3 times incorrect PIN. Coffee machine locked. Ask support service");
				break;
			}
		}
		else if (startChoice == 0)
		{
			sumCash = 0.0;
			break;
		}
		else
		{
			cout << "Please, input [0...5]" << endl;
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
	cout << "Your BALANCE: " << byn << " BYN" << endl;
	cout << "TOTAL BALANCE: " << totalBYN << " BYN" << endl;
	cout << endl;
	cout << "1 - Deposit money" << endl;
	cout << endl;
	cout << "2 - Espresso     " << priceE << " BYN" << endl;
	cout << "3 - Cappuccino   " << priceC << " BYN" << endl;
	cout << "4 - Latte        " << priceL << " BYN" << endl;
	cout << endl;
	
	cout << "5 - Service" << endl;
	cout << endl;
	cout << "0 - Exit" << endl;
	cout << endl;
}

int controlBalance(double byn, double price)
{
	while (byn < price)
	{
		cout << "\t" << "Not enough funds to pay for coffee!" << endl;
		getMoney();
	}
	return 0;
}

void getMoney()
{
	int choice = -1;

        while(true) {
                system("cls");
                showChoiceMoneyMenu();

                cout << "Your choice: ";
                cin >> choice;

                if (choice == 1) {
                        totalBYN += 0.1;
                        byn += 0.1;
                }
                else if (choice == 2) {
                        totalBYN += 0.2;
                        byn += 0.2;
                }
                else if (choice == 3) {
                        totalBYN += 0.5;
                        byn += 0.5;
                }
                else if (choice == 4) {
                        totalBYN += 1.0;
                        byn += 1.0;
                }
                else if (choice == 5) {
                        totalBYN += 2.0;
                        byn += 2.0;
                }
                else if (choice == 0) {
                        break;
                }
                else
                        ;
        }
}

void showChoiceMoneyMenu() {
        cout << "\t" << "** COFFEEbox deposit menu **" << endl;
	cout << endl;
        cout << "\t" << "\t" << "You balance is " << byn << " BYN" << endl;
	cout << endl;
	cout << "\t" << "ATTENTION! CoffeeBOX doesn't give change!\n";
	cout << endl;
	cout << "1 - Deposit 10 penny" << endl;
        cout << "2 - Deposit 20 penny" << endl;
        cout << "3 - Deposit 50 penny" << endl;
        cout << "4 - Deposit 1 BYN" << endl;
        cout << "5 - Deposit 2 BYN" << endl;
	cout << endl;
	cout << "0 - Exit" << endl;
	cout << endl;
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
	progressBar();
	cout << endl;
	cout << "       " << "Coffee is ready!" << endl;
	cout << endl;
	cout << "          " << "Thank you!" << endl;
	cout << "       " << "Have a nice day!"<< endl;
	cout << endl;
}

void progressBar() {
        cout << "[";
        for (int i = 0; i < 33; i++) {
           Sleep(100);
           cout << "*";
        }
        cout << "]";
}
