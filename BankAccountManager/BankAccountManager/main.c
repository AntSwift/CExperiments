#include <stdlib.h>
#include <stdio.h>
#include "bank.h"

///<summary>
///Prints basic account information to the console. 
///</summary>
void printAccount(account* account)
{
	printf("%s balance: %d\n\n", account->name, account->balance);
}

void printTitle(char* title) 
{
	system ("\n\n\n");
	printf("---------------------------------------------\n");
	printf("%s\n", title);
	printf("---------------------------------------------\n");
}

void openAccount(bank* internalBank) 
{
	printTitle("Open an account");
}

void displayAccount(bank* internalBank) 
{
	printTitle("Display an account");
}

void listAccounts(bank* internalBank) 
{
	int idxAccount;
	
	printTitle("All Accounts");

	for (idxAccount = 0; idxAccount < internalBank->maxAccounts; idxAccount++)
	{
		account* currAccount = &internalBank->accounts[idxAccount];

		printAccount(currAccount);
	}
}

void mainMenu(bank* internalBank)
{
	int input;
	input = (int)malloc(sizeof(int));

	while(input != 9)
	{
		printTitle("Main Menu");
	
		printf("1. Open an account\n");
		printf("2. Display an account\n");
		printf("3. List accounts\n");
		printf("9. Quit\n\n");

		scanf_s ("%i", &input);

		switch(input) 
		{
			case 1:
				openAccount(internalBank);
				break;
			case 2:
				displayAccount(internalBank);
				break;
			case 3:
				listAccounts(internalBank);
				break;
			case 9:
				break;
			default:
				printf("Invalid input!\n");
				break;
		}
	}
}

int main()
{
	bank* internalBank;
	internalBank = createBank(10);

	mainMenu(internalBank);

	return 0;
}