#include <iostream>
#include <iomanip>		//for formatting of outputs
#include <stdlib.h>
#include <string.h>
#include <conio.h>
using namespace std;

int p=0;	//To keep a count of buses
class Bus 
{
	//Variables are private (class is private by default)
	int busn;		//Bus number
	string driver;		//Driver name
	string to; 			//Destination city code
	string from;		//Begins from
	string arrival;		//Arrival time
	string depart; 		//Departure time
	char seat[8][4][12];	//Seating chart
	int avail;		//number of seats available
	int fare;			//Cost of a ride
	
	public :
		void install();
		void empty();
		void bus_list();
		void seating();
		void booking();
		void cancel();
};

Bus bus[10];

void Bus :: install()
{
	system("cls");
	
	//If more buses can be added
	if (p<=10)
	{
		//Enter bus details
		cout << endl << endl << endl << endl << endl;
		cout << "\t\t\t\t\tEnter Bus Number : ";
		cin >> busn;
		cout << "\t\t\t\t\tEnter driver name : ";
		cin >> driver;
		cout << "\t\t\t\t\tFrom ? ";
		cin >> from;
		cout << "\t\t\t\t\tTo ? ";
		cin >> to;
		cout << "\t\t\t\t\tDeparture Time : ";
		cin >> depart;
		cout << "\t\t\t\t\tArrival Time : ";
		cin >> arrival;
		cout << "\t\t\t\t\tCharges : ";
		cin >> fare;
		
		//Set available seats to 32
		avail = 32;
		
		//Increase bus count pointer
		p++;
		
		//Set all seats of bus as empty
		empty();
	}
	
}

void Bus :: empty()
{
	for (int i=0 ; i<8 ; i++)
		for (int j=0 ; j<4 ; j++)
			strcpy(seat[i][j] , "Empty");
}

void Bus :: bus_list()
{
	//Clear screen for output
	system ("cls");
	
	//Formatted output
	cout << endl << endl << endl << endl;
	cout << "\t\t\t\t------------------------------------------------------------------------------------------------------------------------------" << endl;
	
	//List of information to display
	cout << "\t\t\t\t" << setw(10) << "Bus No.";
	cout << setw(16) << "Driver";
	cout << setw(12) << "From";
	cout << setw(12) << "To";
	cout << setw(20) << "Departure Time";
	cout << setw(18) << "Arrival Time";
	cout << setw(21) << "Seats Available";
	cout << setw(13) << "Charges" << endl;
	
	cout << "\t\t\t\t------------------------------------------------------------------------------------------------------------------------------" << endl;
	
	//Display info of each bus
	for (int i=0 ; i<p ; i++)	
	{
		cout << "\t\t\t\t" << setw(10) << bus[i].busn;
		cout << setw(16) << bus[i].driver;
		cout << setw(12) << bus[i].from;
		cout << setw(12) << bus[i].to;
		cout << setw(20) << bus[i].depart;
		cout << setw(18) << bus[i].arrival;
		cout << setw(21) << bus[i].avail;
		cout << setw(10) << "Rs." << bus[i].fare << endl;
	}
	
	cout << "\t\t\t\t------------------------------------------------------------------------------------------------------------------------------" << endl;
	cout << endl << endl << endl;
	
	cout << "\t\t\tPress Enter to continue : ";
	getch();
}

void Bus :: seating()
{
	int num; 
			
	system ("cls");
	cout << endl << endl << endl << endl << endl;
	
	//In case of wrong bus number we may need to come back at xyz
	back1:
	cout << "\t\t\t\tEnter bus number : ";
	cin >> num;
	
	//Comparing available bus numbers 
	int i;
	for (i=0 ; i<p ; i++)
		if (bus[i].busn == num)
			break;
	
	//Bus number not found
	if (i == p) 
	{
		cout << endl << "\t\t\t\tBus Number " << num << " does not exist!!" << endl;
		cout << "\t\t\t\tPress 1 to enter again." << endl <<"\t\t\t\tAny other number to go back to menu" << endl;
		cout << "\t\t\t\tYour choice ? ";
		int ch;
		cin >> ch;
		
		//If user wants to enter bus number again goto xyz
		if  (ch == 1)
			goto back1;
		else 
	 		return;
	}
	 
	//Bus number found
	//Displaying bus chart
	system ("cls");
	cout << endl << endl <<endl << endl;
	cout << "\t\t\t\t------------------------------------------------------------------------------------------" << endl ;
	cout << "\t\t\t\t                                    BUS NO. : " << bus[i].busn << endl;
	cout << "\t\t\t\t------------------------------------------------------------------------------------------" << endl << "\t\t\t\t" ;
	//Display occupants of 32 seats
	for (int k=0 ; k<32 ; k++)
	{
		cout << setw(3) << k+1 << ". " << setw(10) << seat[k/4][k%4] << "\t\t";
		//Change line after every 4 entries
		if ((k+1) % 4 == 0)
			cout << endl << "\t\t\t\t";
	}
	cout << "------------------------------------------------------------------------------------------" << endl ;
	
	//To hold the screen
	cout << "\t\t\tPress Enter to continue : ";
	getch();
}

void Bus :: booking()
{
	int num; 
			
	system ("cls");
	cout << endl << endl << endl << endl << endl;
	
	//In case of wrong bus number we may need to come back at xyz
	back2:
	cout << endl << "\t\t\t\tEnter bus number : ";
	cin >> num;
	
	//Comparing available bus numbers 
	int i;
	for (i=0 ; i<p ; i++)
		if (bus[i].busn == num)
			break;
	
	//Bus number not found
	if (i == p) 
	{
		cout << endl << "\t\t\t\tBus Number " << num << " does not exist!!" << endl;
		cout << "\t\t\t\tPress 1 to enter again." << endl <<"\t\t\t\tAny other number to go back to menu" << endl;
		cout << endl << "\t\t\t\tYour choice ? ";
		int ch;
		cin >> ch;
		
		//If user wants to enter bus number again goto xyz
		if  (ch == 1)
			goto back2;
		else 
	 		return;
	}
	
	if (bus[i].avail == 0)
	{
		cout << endl << endl << "\t\t\t\tSORRY! Bus Already full!!" << endl << endl;
		
		//To hold the screen
		cout << "\t\t\tPress Enter to continue : ";
		getch();
		return;
	}
	
	//Bus number found
	//Ask user for seat number. Mark in case user enters occupied seat number
	back3 :
	int sno;
	cout << endl << "\t\t\t\tEnter Seat number : ";
	cin >> sno;
	
	sno--; 	//Index value of seat number
	
	//If the seat entered by user is empty
	if (sno < 32 && sno >=0 && strcmp(bus[i].seat[sno/4][sno%4] , "Empty") == 0)
	{
		cout << "\n\t\t\t\tEnter Passenger's name : ";
		char name[10];
		cin >> name;
		strcpy(bus[i].seat[sno/4][sno%4] , name);
		bus[i].avail--;	//Reduce the number of available seats
		cout << endl << "\t\t\t\t---------------------------------------------------" ;
		cout << endl << "\t\t\t\t		 RS." << bus[i].fare << " CHARGED" ;
		cout << endl << "\t\t\t\t---------------------------------------------------" ;
		
		//To hold the screen
		cout << "\t\t\tPress Enter to continue : ";
		getch();
		return;
		
	}
	
	//Seat occupied
	else
	{
		//If User entered wrong seat number
		if (sno < 0 || sno > 31)
			cout << "\t\t\t\tThe BUS has only 32 seats!!" << endl << "\t\t\t\tEnter a valid seat number!!" << endl << endl;
		
		//Seat not occupied
		else
			cout << "\t\t\t\tSeat Occupied!!" << endl << "\t\t\t\tPick another seat !!" << endl << endl;
		
		//See if user wants to enter again
		cout << "\t\t\t\tPress 1 to enter again." << endl <<"\t\t\t\tAny other number to go back to menu" << endl;
		cout << "\t\t\t\tYour choice ? ";
		int ch;
		cin >> ch;
		
		//Check user's choice
		if (ch == 1)
			goto back3;
		else
			return;
	}
}

void Bus :: cancel()
{
	int num; 
			
	system ("cls");
	cout << endl << endl << endl << endl << endl;
	
	//In case of wrong bus number we may need to come back at xyz
	back2:
	cout << endl << "\t\t\t\tEnter bus number : ";
	cin >> num;
	
	//Comparing available bus numbers 
	int i;
	for (i=0 ; i<p ; i++)
		if (bus[i].busn == num)
			break;
	
	//Bus number not found
	if (i == p) 
	{
		cout << endl << "\t\t\t\tBus Number " << num << " does not exist!!" << endl;
		cout << "\t\t\t\tPress 1 to enter again." << endl <<"\t\t\t\tAny other number to go back to menu" << endl;
		cout << endl << "\t\t\t\tYour choice ? ";
		int ch;
		cin >> ch;
		
		//If user wants to enter bus number again goto xyz
		if  (ch == 1)
			goto back2;
		else 
	 		return;
	}
	
	//Bus number found
	//Ask user for seat number. Mark in case user enters occupied seat number
	back3 :
	int sno;
	cout << endl << "\t\t\t\tEnter Seat number : ";
	cin >> sno;
	
	sno--; 	//Index value of seat number
	
	//If the seat entered by user is empty
	if (sno < 32 && sno >=0 && strcmp(bus[i].seat[sno/4][sno%4] , "Empty") != 0)
	{
		strcpy(bus[i].seat[sno/4][sno%4] , "Empty");
		bus[i].avail++;	//Reduce the number of available seats
		cout << endl << "\t\t\t\t---------------------------------------------------" ;
		cout << endl << "\t\t\t\t		 RS." << bus[i].fare << " RETURNED" ;
		cout << endl << "\t\t\t\t---------------------------------------------------" ;
		
		//To hold the screen
		cout << "\t\t\tPress Enter to continue : ";
		getch();
		return;
		
	}
	
	//Seat occupied
	else
	{
		//If User entered wrong seat number
		if (sno < 0 || sno > 31)
			cout << "\t\t\t\tThe BUS has only 32 seats!!" << endl << "\t\t\t\tEnter a valid seat number!!" << endl << endl;
		
		//Seat not occupied
		else
			cout << "\t\t\t\tSeat already Empty !!" << endl << endl;
		
		//See if user wants to enter again
		cout << "\t\t\t\tPress 1 to enter again." << endl <<"\t\t\t\tAny other number to go back to menu" << endl;
		cout << "\t\t\t\tYour choice ? ";
		int ch;
		cin >> ch;
		
		//Check user's choice
		if (ch == 1)
			goto back3;
		else
			return;
	}
}

main()
{
	
	int ch;				//Choice of user
	
	while(1)
	{
		system ("cls");		//Clearing screen for our display
		//Display menu
		cout << endl << endl << endl << endl << endl;
		cout << "\t\t\t\t\t-----------------------------------------------------------------------" << endl;
		cout << "\t\t\t\t\t                           *BUS RESERVATION*" << endl;
		cout << "\t\t\t\t\t-----------------------------------------------------------------------" << endl;
		cout << "\t\t\t\t\t    1. INSTALL A BUS" << endl;
		cout << "\t\t\t\t\t    2. CHECK BUS LIST" << endl;
		cout << "\t\t\t\t\t    3. SEE THE SEATING CHART FOR A BUS" << endl;
		cout << "\t\t\t\t\t    4. BOOK A SEAT" << endl;
		cout << "\t\t\t\t\t    5. CANCEL BOOKING" << endl;
		cout << "\t\t\t\t\t    6. EXIT" << endl;
		cout << "\t\t\t\t\t-----------------------------------------------------------------------" << endl;
		cout << endl << endl << endl;
		
		//Input user's choice
		abc :
		cout << endl << "\t\t\t\t\tYour choice ? ";
		cin >> ch;
		
		//Call functions according to user's choice
		switch(ch)
		{
			case 1 : if (p<10)
						bus[p].install();
				break;
			
			case 2 : bus[0].bus_list();
				break;
			
			case 3 : bus[0].seating();
				break;
			
			case 4 : bus[0].booking();
				break;
				
			case 5 : bus[0].cancel();
				break;
				
			case 6 : cout << "\t\t\t\t\t.......EXIT......." << endl;
				return 0;
			
			default : cout << "\t\t\t\t\tIncorrect Input!!" << endl << "\t\t\t\t\tENTER AGAIN!!" << endl;
				goto abc;
		}
		
		
	}	
	
	return 0;
}
