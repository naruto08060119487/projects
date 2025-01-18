/* ------------------------------------------------------
CMP2811: Applied Programming Paradigms
Driver program for "LincBank" Assessment Item 2
Semester A 2024

During marking, we will use the exact same notation
as provided in the brief, so make sure you follow that guideline.

You should avoid removing parts of this driver program, but
add to it the necessary code to produce your implementation.

Good luck!
------------------------------------------------------ */
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <sstream>
#include <vector>
#include <cstring>
#include <iomanip>

#include "Account.h" //Base class for accounts
#include "current_account.h" // Derived class for current accounts
#include "savings_account.h" // Derived class for savings accounts
#include "Isa.h" // Derived class for ISA accounts
using namespace std;

///method to display account details
void displayAccountInfo(Account* acc) {
	cout << acc->getAccountType() << " Balance £" << fixed << setprecision(3) << acc->getBalance() << endl;
}

///Function to transfer funds between accounts
void transfer(vector<Account*>& acc,std::vector <std::string> parameters) {
	//handle fund transfer between accounts
	if(parameters.size()<4) {
		cout<<"Insufficient parameters, use[transfer <source account> <destination account> <amount>"<<endl;
	}
	else {
		// Uses
		const int source_acc_index = stoi(parameters[1]); //sets account to transfer from
		const int destination_acc_index = stoi(parameters[2]); //sets account to transfer to
		double amount = stod(parameters[3]); //amount to be transferred

		bool success = false;

		// Create pointers to source and destination accounts
		Account* source_account = nullptr;
		Account* destination_account = nullptr;

		// Conditions to handle errors and print out error message
		if(source_acc_index < 1 || source_acc_index > acc.size()|| destination_acc_index < 1 || destination_acc_index > acc.size()) {
			cout<<"Invalid account index"<<endl;
		}
		else if(amount<=0) {
			cout<<"Transfer amount must be greater than zero"<<endl;
		}
		else {
			success = true;
			source_account = acc[source_acc_index - 1]; //converting back to zero based index
			destination_account = acc[destination_acc_index - 1];

			if(success) {
				source_account->withdraw(amount); //withdraw from source account
				destination_account->deposit(amount); // Deposit into destination account
				cout<<"Transfer successful"<<endl;

				displayAccountInfo(source_account);
				source_account->displayTransactionHistory();

				displayAccountInfo(destination_account);
				destination_account->displayTransactionHistory();

			}
		}
	}
}

///Function to open accounts
void openAccount(vector<Account*>& accounts,std::vector <std::string> parameters) {
	if(parameters.size() < 2) {

			cout<<"Insufficient parameters, use[open <type> <opening_balance>"<<endl;
		}
	else {
		const int account_type = stoi(parameters[1]); //Determine account type
		//opens a savings account
		if(account_type == 2) {
			if(parameters.size() < 3) {
				cout<<"Insufficient parameters, use[open <2> <opening_balance>"<<endl;

			}
			else {
				try {
					double openingBalance = stod(parameters[2]);
					savings_account* savings = new savings_account(openingBalance);
					accounts.push_back(savings); //adds the opened account to the vector for holding all the accounts
					cout<<"Savings account created!"<<endl;

				}
				catch(const invalid_argument& e) {
					cout << "Invalid opening balance provided. Please provide a numeric value." << endl;
				}

			}
		}
		else if(account_type == 1) {

			// Opens current account(only one current account can be opened
			bool has_current_acc = false;
			for(const auto& acc : accounts) {
				if(dynamic_cast<current_account*>(acc) != nullptr) {
					has_current_acc = true;
					break;
				}
			}
			if(has_current_acc) {
				cout<<"you can only have one current account.A current account already exist"<<endl;
			}
			else {
				if(parameters.size() < 2) {
					cout<<"Insufficient parameters, use[open <1>  ]"<<endl;
				}
				else if(parameters.size() > 2) {
					cout<<"opening balance not required for current account"<< endl;
				}
				else {
					current_account* current = new current_account();
					accounts.push_back(current);
					cout<<"Current account created!"<<endl;
				}
			}

		}
		else if(account_type == 3) {

			// Opens ISA account(only one can be opened and minim balance os #1000)
			bool has_isa_acc = false;
			for(const auto& acc : accounts) {
				if(dynamic_cast<Isa*>(acc) != nullptr) {
					has_isa_acc = true;
					break;
				}
			}
			if(has_isa_acc) {
				cout<<"you can only have one ISA account.A ISA account already exist"<<endl;
			}
			else {
				if(parameters.size() < 3) {
					cout<<"Insufficient parameters, use[open <3> <opening_balance>(minimum of £1000)"<<endl;
				}
				else {
					try {
						double openingBalance = stod(parameters[2]);
						if(openingBalance < 1000) {
							cout<<"ISA initial balance must be >= £1000"<<endl;
						}
						else {
							Isa* isa = new Isa(openingBalance);
							accounts.push_back(isa);
							cout<<"ISA created!"<<endl;

						}

					}
					catch(const invalid_argument& e) {
						cout << "Invalid opening balance provided. Please provide a numeric value." << endl;
					}
					catch (const out_of_range& e) {
						cout << "Opening balance too Large" << endl;
					}

				}
			}

		}
		else {
			cout<< "unrecognised account, supported accounts: savings, current, ISA"<< endl;
		}
	}
}

///Function to view account details
void viewAccounts(vector<Account*>& accounts,std::vector <std::string> parameters, Account*& lastViewedAccount) {
	if(parameters.size() == 1) {
		if(accounts.empty()) {
			cout<<"No accounts available to view"<<endl;
		}
		else {
			for(auto & account : accounts) {
				displayAccountInfo(account);
				account->displayTransactionHistory();
				lastViewedAccount = nullptr;
			}
		}
	}
	else if(parameters.size() == 2) {
		try {
			int index = stoi(parameters[1]);
			if(index < 1 || index > accounts.size()) {
				cout<<"Invalid account index"<<endl;
			}
			else {
				lastViewedAccount = accounts[index - 1];

				displayAccountInfo(lastViewedAccount);

				accounts[index - 1]->displayTransactionHistory();  //conversion to zero based counting for precision
			}
		}catch(const invalid_argument& e) {
			cout<<"Invalid index provided enter a numeric value"<<endl;
		}
	}
	else {
		cout<< "invalid parameters, use [view] to display all account or [view<index>] to see specific account"<<endl;
	}
}

///Function to withdraw
void withdrawal(std::vector <std::string> &parameters, Account*& lastViewedAccount) {
	if(parameters.size() < 2) {
		cout<<"Insufficient parameters, use[withdraw <amount>]"<<endl;
	}
	else {
		double withdrawal_amount = stod(parameters[1]);
		if(withdrawal_amount<=0) {
			cout<<" withdrawal must be greater than zero"<<endl;
		}
		else if(lastViewedAccount) {
			lastViewedAccount->withdraw(withdrawal_amount);
			cout<< lastViewedAccount->getAccountType()<< " | Balance: £"<< fixed<<setprecision(2)<< lastViewedAccount->getBalance() <<endl;

			lastViewedAccount->displayTransactionHistory();
		}
		else {
			cout<<"No account viewed recently. Use the View command first "<<endl;
		}
	}

}

///Function to deposit
void deposit(std::vector <std::string> &parameters, Account*& lastViewedAccount) {
	if(parameters.size() < 2) {
		cout<<"Insufficient parameters, use[deposit <amount>]"<<endl;
	}
	else {
		double deposit_amount = stod(parameters[1]);
		if(deposit_amount<=0) {
			cout<<" deposit must be greater than zero"<<endl;
		}
		else if(lastViewedAccount) {
			lastViewedAccount->deposit(deposit_amount);
			cout<< lastViewedAccount->getAccountType()<< " | Balance: £"<< fixed<<setprecision(2)<< lastViewedAccount->getBalance() <<endl;
			lastViewedAccount->displayTransactionHistory();
		}
		else {
			cout<<"No account viewed recently. Use the View command first "<<endl;
		}


	}
}

///function to project balance on Savings or ISA accounts
void project(vector<Account*>& accounts,std::vector <std::string> parameters, Account*& lastViewedAccount) {
	if(parameters.size()<2) {
		cout<<"insufficient parameters. use project <time(time must be digits)> "<<endl;

	}
	else {
		// checks if the last viewed account is a current account and prints out a message
		bool lastViewedIsCurrent = false;
		for(const auto& acc : accounts) {
			current_account* current = dynamic_cast<current_account*>(acc);
			if(current!= nullptr && current == lastViewedAccount) {
				lastViewedIsCurrent = true;
				break;
			}
		}
		if(lastViewedIsCurrent) {
			cout<<"cannot project balance on a current account, please view another account using the <view> option"<<endl;
		}
		else {

			savings_account* saving = dynamic_cast<savings_account*>(lastViewedAccount);
			Isa* isa = dynamic_cast<Isa* >(lastViewedAccount);
			if(saving != nullptr) {
				double time = stod(parameters[1]);
				if( time <= 0) {
					cout<<"Invalid Input. time must be a positive value"<<endl;
				}
				else {
					saving->interestCalculator(time);
				}
			}
			else if(isa != nullptr) {
				double time = stod(parameters[1]);
				if( time <= 0) {
					cout<<"Invalid Input. time must be a positive value"<<endl;
				}
				else {
					isa->interestCalculator(time);
				}
			}
			else {
				cout<<"view a savings or ISA first"<<endl;
			}
		}
	}
}

///function to search for Transactions
void search(vector<Account*>& accounts,std::vector <std::string> parameters, Account*& lastViewedAccount) {
	if(parameters.size() < 2) {
		cout<<"Insufficient parameters, use[search <amount>]"<<endl;
	}
	else {
		double search_amount = stod(parameters[1]);
		if(search_amount <= 0) {
			cout<< "amount must be grater than zero"<< endl;
		}
		//displays the searched result for the last view account
		else if(lastViewedAccount) {
			lastViewedAccount->searchTransactions(search_amount);
			lastViewedAccount->displaySearch();
		}
		//displays the searched results across all opened accounts
		else {
			for(auto & account : accounts) {
				account->searchTransactions(search_amount);
				account->displaySearch();

			}
		}

	}
}
int main()
{
	// Declare essential variables for command handling
	std::vector <std::string> parameters;
    std::string userCommand;
	vector<Account*> accounts;
	Account* lastViewedAccount = nullptr; // Pointer to last viewed account
	// you may also want to store a collection of opened accounts here

	// Display initial welcome message and options
	cout << "~~~ Welcome to LincBank! ~~~" << std::endl;
	cout << "Options:" << std::endl;
	cout<< "open type initial_deposit: open a current (1), savings (2) or ISA (3) account: " << std::endl;
	cout<<" view [index]: view balance and recent transactions"<<endl;
	cout<< "withdraw sum: withdraw funds from most recently viewed account"<<endl;
	cout<< "deposit sum: deposit funds into most recently viewed account"<<endl;
	cout<<"transfer src dest sum: transfer funds between accounts"<<endl;
	cout<<"project years: project balance forward in time"<<endl;
	cout<<"exit: close this application"<<endl;
	cout<<"options: view these options again"<<endl;

	// Main loop to process user commands
    while (userCommand != "exit")
    {
		parameters.clear(); // clear ready for next command
		std::cout << std::endl << ">>> ";
		std::getline(std::cin, userCommand); // Read user input

		char* cstr = new char[userCommand.length() + 1]; // Parse user commands into individual tokens
		strcpy(cstr, userCommand.c_str());

		char* token;
		token = strtok(cstr, " ");

		while (token != NULL)
		{
			parameters.push_back(token);
			token = strtok(NULL, " ");
		}

		// Define all commands as per the brief
		std::string command = parameters[0];

		if (command.compare("options") == 0)
		{
			// display the various commands to the user
			std::cout << "Options:" << std::endl;
			cout<< "open type initial_deposit: open a current (1), savings (2) or ISA (3) account: " << std::endl;
			cout<<" view [index]: view balance and recent transactions"<<endl;
			cout<< "withdraw sum: withdraw funds from most recently viewed account"<<endl;
			cout<< "deposit sum: deposit funds into most recently viewed account"<<endl;
			cout<<"transfer src dest sum: transfer funds between accounts"<<endl;
			cout<<"project years: project balance forward in time"<<endl;
			cout<<"exit: close this application"<<endl;
			cout<<"options: view these options again"<<endl;
		}
		else if (command.compare("open") == 0)
		{
			// allow a user to open an account
			// e.g., Account* a = new Savings(...);
			// Opens a new account of type (current, savings, ISA)
			openAccount(accounts,parameters);

		}
		else if (command.compare("view") == 0)
		{
			// display an account according to an index (starting from 1)
			// alternatively, display all accounts if no index is provided
			viewAccounts(accounts, parameters, lastViewedAccount);
		}

		else if (command.compare("withdraw") == 0) {
			// allow user to withdraw funds from an account
			withdrawal(parameters, lastViewedAccount);
		}
		else if (command.compare("deposit") == 0)
		{
			// allow user to deposit funds into an account
			deposit(parameters,lastViewedAccount);
		}
		else if (command.compare("transfer") == 0)
		{

			// allow user to transfer funds between accounts
			// i.e., a withdrawal followed by a deposit!
			transfer(accounts, parameters);
		}
		else if (command.compare("project") == 0)
		{
			// compute compound interest t years into the future
			project(accounts,parameters,lastViewedAccount);
		}
		else if (command.compare("search") == 0)
		{
		//	allow users to search their account history for a transaction
		//  (this is a stretch task)
			search(accounts,parameters,lastViewedAccount);
		}

    }

	std::cout << "Press any key to quit...";
	std::getchar();
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started:
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
