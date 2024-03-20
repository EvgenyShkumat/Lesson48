#include <iostream>
#include <string>
using namespace std;

class BankAccount {
public:
	string name;
	int balance;
	
	string getInfo() {
		string s = "Name: " + name;
		s += ", balance = " + to_string(balance);

		return s;
	}

	void withdraw(int amount) {
		if (amount <= balance) {
			balance -= amount;
		}
	}

	void replenish(int amount) {
		balance += amount;
	}
};

string get_best_account_name(BankAccount* accounts, int size) {
	BankAccount max = accounts[0];

	for (int i = 1; i < size; i++)
	{
		if (max.balance < accounts[i].balance) {
			max = accounts[i];
		}
	}

	return max.name;
}

int main() {
	const int size = 2;

	BankAccount accounts[size];

	accounts[0].name = "georgiy";
	accounts[0].balance = 1000;

	accounts[1].name = "j";
	accounts[1].balance = 5000;

	accounts[0].replenish(5000);
	accounts[1].withdraw(10000);

	for (int i = 0; i < size; i++)
	{
		cout << accounts[i].getInfo() << endl;
	}

	cout << get_best_account_name(accounts, size);

	return 0;
}