#include <stdlib.h>
#include "bank.h"

bank* createBank(int maxAccounts)
{
	bank* sampleBank;
	sampleBank = (bank*)malloc(sizeof(bank));
	sampleBank->maxAccounts = maxAccounts;

	sampleBank->accounts = (account*)calloc(maxAccounts, sizeof(account));

	// setup 5 sample accounts
	createAccount(sampleBank, 1, "Account 1", 2500);
	createAccount(sampleBank, 2, "Account 2", 100);
	createAccount(sampleBank, 3, "Account 3", 1750);
	createAccount(sampleBank, 4, "Account 4", 800000);
	createAccount(sampleBank, 5, "Account 5", 10);

	return sampleBank;
}

account* createEmptyAccount()
{
	account* emptyAccount;
	emptyAccount = (account*)calloc(1, sizeof(account));

	return emptyAccount;
}

int isNullAccount(account* compareAccount)
{
	return (compareAccount->number == createEmptyAccount()->number && compareAccount->name == createEmptyAccount()->name && compareAccount->balance == createEmptyAccount()->balance);
}

int getNextSlot(bank* internalBank)
{
	int idxAccounts;

	for (idxAccounts = 0; idxAccounts < internalBank->maxAccounts; idxAccounts++)
	{
		if(isNullAccount(&internalBank->accounts[idxAccounts]) == 1)
		{
			return idxAccounts;
		}
	}
}

///<summary>
///Creates an instance of account with the supplied opening balance and returns a pointer to it.
///</summary>
void createAccount(bank* internalBank, int accountNumber, char* name, long openingBalance) 
{
	int idxLocation;

	account* newAccount;

	newAccount = (account*)calloc(0, sizeof(account));

	newAccount->number = accountNumber;
	newAccount->name = name;
	newAccount->balance = openingBalance;

	idxLocation = getNextSlot(internalBank);
	internalBank->accounts[idxLocation] = *newAccount;
}

///<summary>
/// Moves the specified amount from the from account and deposits in the to account.
///</summary>
void transfer(account* from, account* to, long amount)
{
	from->balance = from->balance - amount;
	
	to->balance = to->balance + amount;
}

account* findAccount(bank* internalBank, int accountNumber)
{
	int idxAccounts;

	for (idxAccounts = 0; idxAccounts < internalBank->maxAccounts; idxAccounts++)
	{
		if((&internalBank->accounts[idxAccounts])->number == accountNumber)
		{
			return &internalBank->accounts[idxAccounts];
		}
	}

	return createEmptyAccount();
}