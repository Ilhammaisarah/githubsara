#include<iostream>
#include<iomanip>

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
	int child, adult, counter=0;
	char membercard, y, n;
	double totalPrice, totalPay, money, money1, balance, totalPrice1, totalPrice2, amount;
	cout << "Welcome to FairyLand Theme Park." << endl;
	
	//category
	while(counter < 1000)
	{
	displayCategory();
	
	//input
	cout << "Enter the number of child : ";
	cin >> child;
	cout << "Enter the number of adult : ";
	cin >> adult;
	
	//asking customer for a membercard
	displayMembercard();
	cout << "Do you have a membercard ? Enter the code [y/n] : ";
	cin >> membercard;
	
	//calculate the total price
	do
	{
	     while((membercard != 'y' && membercard != 'Y') && (membercard != 'n' && membercard != 'N'))	
		{
			cout << "Enter the correct code : ";
		    cin >> membercard;
		}
		     if(membercard == 'y' || membercard == 'Y')
	             {
		             cout << "You get 10% discount, congrats ! " << endl;	
		             cout << fixed << showpoint << setprecision(2);
		             totalPrice = ((child * 30) + (adult * 50)) - (((child * 30) + (adult * 50)) * 0.1);
		             cout << "totalPrice=RM" << totalPrice << endl;
	            }
	
	        else if(membercard == 'n' || membercard == 'N')
	            {
		             totalPrice=(child * 30) + (adult * 50);
		             cout << "totalPrice=RM" << totalPrice << endl;
	            }
	}while(( membercard == 'y' || membercard == 'Y') && ( membercard == 'n' || membercard == 'N'));
	
	//calculate the balance after payment
	
	cout << "Enter the amount of your money to pay : ";
	cin >> money;
	if(money < totalPrice)
   	{
	    cout << "Opps!! Your amount is insufficient " << endl;
		amount = totalPrice - money;
		cout << "Please add RM " << amount << endl;
		cout << "Add your money again : ";
		cin >> money1;
		balance = (money + money1) - totalPrice;
		money = money1 + money;
	}
	    
	else if(money > totalPrice)
	{
	    balance = money - totalPrice;
		money = money;
	}
		
	//full receipt
	cout << "_____________________________________ " << endl;
	cout << fixed << showpoint << setprecision(2);
	cout << "\n\n\nGenerating your bil ....\n " << endl;
	cout << "\t\t\t\t\t\t FAIRYLAND THEME PARK " << endl;
	cout << "\t\t\t\t\t\t GENTING SKYWORLD " << endl;
	cout << "\t\t\t\t\t\t GENTING HIGHLANDS " << endl;
	cout << "\t\t\t\t\t\t       " << endl;
	cout << "\t\t\t\t\t++++++++++++++++++++++++++++++++++++ " <<endl;
	cout << "Date     : 25 JUNE 2022\t\t\t\t\t\t\t\t\tTime : 8.15p.m. " << endl;
	cout << "\n\nYOUR TICKET INFORMATION : " << endl;
	cout << "--------------------------------------------------------------------------------------------------------- " << endl;
	cout << "|\t\tCATEGORY\t|\t\tQUANTITY\t\t|\tPRICE(RM)\t\t| " << endl;
	cout << "--------------------------------------------------------------------------------------------------------- " << endl;
	cout << "|\t\tCHILD\t\t|\t\t    " << child << "\t\t\t|\t\t " << child * 30 << "\t\t| " << endl;
	cout << "|\t\tADULT\t\t|\t\t    " << adult << "\t\t\t|\t\t " << adult * 50 << "\t\t| " << endl;
	cout << "--------------------------------------------------------------------------------------------------------- " << endl;
	cout << "\t\t\t\t\t\t\t\t\tTOTAL         : RM "  << totalPrice << endl;
	cout << "\t\t\t\t\t\t\t\t\tRECEIVED CASH : RM "  << money << endl;
	cout << "\t\t\t\t\t\t\t\t\tCHANGED       : RM "  << balance << endl;
	cout << "\n\n\n\t\t\t\t\t  THIS SERVES AS YOUR OFFICIAL RECEIPT " << endl;
	cout << "\t\t\t\t\t      THANK YOU, PLEASE COME AGAIN " << endl;
	cout << "\t\t\t\t\tVISIT US ALSO AT www.fairylandthemepark.com " << endl;
	displayTotal(child, adult);
	cout << "\n_____________________________________ " << endl;
	
	counter++;
	
    }
    
	return 0;
		
}
