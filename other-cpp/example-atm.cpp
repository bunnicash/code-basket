#include <iostream>
using namespace std; 

void mainMenu() {
	cout << "1. Check Balance" << endl;
	cout << "2. Deposit" << endl;
	cout << "3. Withdraw" << endl;
	cout << "4. Logout" << endl;
}

int main() {
	int option;
	double balance = 0;
	
	do {
		mainMenu();
		cout << "Select: ";
		cin >> option;
		system("clear");
		
		switch (option) {
			case 1:cout << "Balance: " << balance << "€" << endl; break;
			case 2:cout << "Deposit: ";
				double depositX; 
				cin >> depositX;
				balance += depositX;
				break;
			case 3:cout << "Withdraw: ";
				double withdrawX; 
				cin >> withdrawX;
				if(withdrawX<=balance)
					balance -= withdrawX;
				else
					cout << "Withdrawal exceeds balance" << endl; 
				break;
		}
		
	} while (option!=4);
	system("echo -e Logging out...\n");
	return 0;
}
