#include<iostream>
#include<iomanip>
#include <ctime>

using namespace std;
	
void displayCategory()
{
	cout << "-------------------------------------------------" <<  endl;
	cout << "|\tCategory\t|\tPrice \t\t\|" << endl;
    cout << "-------------------------------------------------" << endl;
    cout << "|\tAdult\t\t|\tRM 50.00 \t|" << endl;
    cout << "-------------------------------------------------" << endl;
    cout << "|\tChild\t\t|\tRM 30.00 \t|" << endl;
    cout << "-------------------------------------------------" << endl;
}

void displayMembercard()
{
	cout << "-------------------------------------------------" << endl;
	cout << "|\tMembercard\t|\tDiscount \t|" << endl;
	cout << "-------------------------------------------------" << endl;
	cout << "|\tYes\t\t|\t10% \t\t|" << endl;
	cout << "-------------------------------------------------" << endl;
	cout << "|\tNo\t\t|\t0% \t\t|" << endl;
	cout << "-------------------------------------------------" << endl;
}

void displayTotal(int child, int adult)
{
	cout << "Total ticket : " << child + adult << endl;
}

void displayTotalPrice1(int child)
{
	cout << "Child Price : " << child * 30 << endl;
}

void displayTotalPrice2(int adult)
{
	cout << "Adult Price : " << adult * 50 << endl;
}

int main()
{
	int child, adult;
	char membercard, choice;
	double totalPrice, money, money1, balance, amount;

	cout << "Welcome to FairyLand Theme Park." << endl;

	do
	{
		displayCategory();

		// input
		cout << "Enter the number of child : ";
		cin >> child;
		cout << "Enter the number of adult : ";
		cin >> adult;

		// member card
		displayMembercard();
		cout << "Do you have a membercard ? Enter the code [y/n] : ";
		cin >> membercard;

		// validate membercard input
		while((membercard != 'y' && membercard != 'Y') &&
			  (membercard != 'n' && membercard != 'N'))
		{
			cout << "Enter the correct code : ";
			cin >> membercard;
		}

		// calculate total price
		if(membercard == 'y' || membercard == 'Y')
		{
			cout << "You get 10% discount, congrats ! " << endl;
			totalPrice = ((child * 30) + (adult * 50)) * 0.9;
		}
		else
		{
			totalPrice = (child * 30) + (adult * 50);
		}

		cout << fixed << showpoint << setprecision(2);
		cout << "totalPrice = RM " << totalPrice << endl;

		// payment
		cout << "Enter the amount of your money to pay : ";
		cin >> money;

		if(money < totalPrice)
		{
			cout << "Opps!! Your amount is insufficient " << endl;
			amount = totalPrice - money;
			cout << "Please add RM " << amount << endl;
			cout << "Add your money again : ";
			cin >> money1;
			money = money + money1;
		}

		balance = money - totalPrice;
		
	    time_t now = time(0);
        now += 8 * 3600;   // Force Malaysia time (UTC +8)
        tm *ltm = gmtime(&now);
        
		int hour = ltm->tm_hour;
        string ampm = (hour >= 12) ? "PM" : "AM";
        hour = hour % 12;
        if (hour == 0) hour = 12;

		// receipt
		cout << "_____________________________________ " << endl;
		cout << "\n\n\nGenerating your bil ....\n " << endl;
		cout << "\t\t\t\t\t\t FAIRYLAND THEME PARK " << endl;
		cout << "\t\t\t\t\t\t GENTING SKYWORLD " << endl;
		cout << "\t\t\t\t\t\t GENTING HIGHLANDS " << endl;
		cout << "\t\t\t\t\t++++++++++++++++++++++++++++++++++++ " <<endl;
		cout << "Date     : "
             << ltm->tm_mday << "/"
             << 1 + ltm->tm_mon << "/"
             << 1900 + ltm->tm_year
             << "\t\t\t\t\t\tTime : "
             << setw(2) << setfill('0') << hour << ":"
             << setw(2) << setfill('0') << ltm->tm_min << " "
             << ampm << endl;

		cout << "\nYOUR TICKET INFORMATION : " << endl;
		cout << "--------------------------------------------------------------------------------------------------------- " << endl;
		cout << "|\t\tCATEGORY\t|\t\tQUANTITY\t\t|\tPRICE(RM)\t\t| " << endl;
		cout << "--------------------------------------------------------------------------------------------------------- " << endl;
		cout << "|\t\tCHILD\t\t|\t\t    " << child << "\t\t\t|\t\t " << child * 30 << "\t\t| " << endl;
		cout << "|\t\tADULT\t\t|\t\t    " << adult << "\t\t\t|\t\t " << adult * 50 << "\t\t| " << endl;
		cout << "--------------------------------------------------------------------------------------------------------- " << endl;
		cout << "\t\t\t\t\t\t\t\t\tTOTAL         : RM "  << totalPrice << endl;
		cout << "\t\t\t\t\t\t\t\t\tRECEIVED CASH : RM "  << money << endl;
		cout << "\t\t\t\t\t\t\t\t\tCHANGED       : RM "  << balance << endl;

		cout << "\n\t\tTHIS SERVES AS YOUR OFFICIAL RECEIPT " << endl;
		cout << "\t\tTHANK YOU, PLEASE COME AGAIN " << endl;
		cout << "\t\tVISIT US ALSO AT www.fairylandthemepark.com " << endl;

		displayTotal(child, adult);
		cout << "\n_____________________________________ " << endl;

		// repeat
		cout << "Do you want to continue ? (y/n): ";
		cin >> choice;

	} while(choice == 'y' || choice == 'Y');

	return 0;
}

