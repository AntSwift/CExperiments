typedef struct  
{
	int number;
	char* name;
	long balance; // stored in pence for simplicity.
} account;

typedef struct  
{
	int maxAccounts;
	account* accounts;
} bank;

void createAccount(bank* internalBank, int accountNumber, char* name, long openingBalance);

void transfer(account* from, account* to, long amount);

bank* createBank(int maxAccounts);

account* findAccount(bank* internalBank, int accountNumber);

int isNullAccount(account* compareAccount);

account* createEmptyAccount();