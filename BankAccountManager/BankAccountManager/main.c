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
	int accountNumber;
	int openBalance;
	account* newAccount;

	char* accountName[80];

	printTitle("Open an account");

	accountNumber = (int)malloc(sizeof(int));
	openBalance = 0;

	printf("Enter an account number:\n");
	scanf_s ("%i", &accountNumber);

	printf("Enter an account name:\n");
	scanf_s("%s", accountName);

	createAccount(internalBank, accountNumber, *accountName, 0);
}

void displayAccount(bank* internalBank) 
{
	int accountNumber;
	account* foundAccount;

	printTitle("Display an account");

	accountNumber = (int)malloc(sizeof(int));

	printf("Enter an account number:\n");
	scanf_s ("%i", &accountNumber);

	
	foundAccount = findAccount(internalBank, accountNumber);

	printAccount(foundAccount);
}

void listAccounts(bank* internalBank) 
{
	int idxAccount;
	int freeCount;

	freeCount = 0;
	
	printTitle("All Accounts");

	for (idxAccount = 0; idxAccount < internalBank->maxAccounts; idxAccount++)
	{
		account* currAccount = &internalBank->accounts[idxAccount];

		if(isNullAccount(currAccount) == 0)
		{
			printAccount(currAccount);
		}
		else 
		{
			freeCount++;
		}
	}

	printf("%i free spaces\n", freeCount);
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
	internalBank = createBank(1000);

	mainMenu(internalBank);

	return 0;
}