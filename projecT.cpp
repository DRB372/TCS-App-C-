
#include<iostream>
#include<fstream>
#include<conio.h>
#include<string>
#include<time.h>
#include<windows.h>
using namespace std;
char un[30] ;
char pw[30];
char ch;
int sum = 0;
int max;
double CNIC;
int chk, fchk;
char username[30];
char password;
char  username1[30];
char password1;
char distance[30];
char TD[30];
char RW[30];
char RD[30];
char S_name[30];
char S_CNIC[30];
char S_address[30];
char S_cell_no[30];
char R_name[30];
char R_CNIC[30];
char R_address[30];
char R_cell_no[30];
bool is_logged;
void intro();
void NEWCUSTOMER();
void loginn();
void fun();
void select();
void edit();
void Register();
void delay(int m_seconds)
{
	clock_t show = m_seconds + clock();
	while (show > clock());
}
void updatinglogin();
void charcheck();
void LLL();
void intcheck();
string choice;
void read();
int main()
{
      {
		system("color 4A");
        cout<<"\n\n\n\n\n\n\n\n";      
		cout << "\t\t\t\t  PROJECT NAME  = |   TCS SYSTEM   |\n";
		cout << "\t\t\t\t     BSCS (C)   = |  1sT SEMESTER  |\n";
		cout << "\t\t\t\t                  |________________|";
        cout<<"\n\n\n";
	
		cout << "\t\t\t\t  SUBMITTED  TO = | Mr.ZAFAR KHATAK|\n";
		cout << "\t\t\t\t  SUBMITTED  BY = |     DAUD BUTT  | \n";
		cout << "\t\t\t\t                  |________________| \n";
	    cout << "\t\t\t \n";
		cout << "\t\t\t\n";
DON:
		cout << "PLEASE SELECT YOUR CHOICE: \n";
		cout << "\t\t\t\t                                         \n";
		cout << "1)  FOR LOGIN\n2)  FOR UPDATING LOGIN\n3)  EXIT" << endl;
		cin >> choice;
		if (choice == "1"){
			loginn();
		}
		else
		if (choice == "2"){
			updatinglogin();
}
		else
		{
			if (choice == "3"){
				cout << "\n";
				cout << "|   THANK YOU   |";
			}
			else
			{
				cout << "|   PLEASE ENTER A VALID STATEMENT   \n|";
				goto DON;
			}
		}
	}
}
int charcheck(char ch[])
{
	int i = 0;
	while (ch[i] != '\0'){
		if (isalpha(ch[i])){
			chk = 1;
			i++;
		}

		else{
			chk = 0;
			break;
		}
	}
	if (chk == 0){
		cout << "ONLY ALPHABETS ARE ALLOWED\n";
		return 0;
	}
else
	return 1;
}
int intcheck(char ch[])
{
	int i = 0;
	while (ch[i] != '\0'){
		if (isdigit(ch[i])){
			chk = 1;
			i++;
		}
		else{
			cout << "ONLY NUMBERS ARE ALLOWEd\n";
			return 0;
			break;
		}	
		}
	}
void loginn()
{
	string pass1 = "";
	string pass2 = "";
	system("color 8");
	cout << "\t\t\t\t                                         \n";
	cout << "\t\t\t\t                                         \n";
	cout << "\t\t\t\t                                         \n";
	cout << "|*-*-*-*-*-* PLEASE ENTER YOUR LOGIN*-*-*-*-*-*|" << endl;
DON1:
	ifstream kf("login.text");
	kf >> un >> pw;
	kf.close();
	cout << "|   ENTER USERNAME   |";
	do{
		cin.ignore();
		cin.getline(username, 30);
		fchk = charcheck(username);
	} while (fchk == 0);


	if (strcmp(username,un)!= 0){
		cout << "INVALID\n";
		goto DON1;
	}
	DON2:
		string pass3 = "";
		cout << "|   ENTER PASSWORD   |";
		password = _getch();
		while (password != 13){
			pass3.push_back(password);
			cout << '*';
			password = _getch();
		}
		if (pw != pass3)
		{
			cout << "INVALID\n";
			goto DON2;
		}
		else
		{
			cout << "\t\t\t\t                                         \n";
			cout << "\t\t\t\t                                         \n";
			cout << "******LOGIN SUCCESSFULLY*****\n";
			system("cls");
		}
		cout << "\n";
		cout << "\t\t\t\t                                         \n";
		cout << "\t\t\t\t                                         \n";
		cout << "\t\t\t\t |              TERMS AND CONDITIONS                 |\n";
		cout << "\t\t\t\t                                         \n";
		cout << "\t\t\t\t |   YOU HAVE TO ENTER SENDER AND RECIEVER DETAILS |\n";
		cout << "\t\t\t\t |   YOUR BILL IS ACOORDING TO WEIGHT AND DISTANCE   |\n";
		cout << "\t\t\t\t |   YOU HAVE TO ATTACH COPIES OF REQUIRED DOCUMENTS |\n";
		cout << "\t\t\t\t |   YOU MUST PAY YOUR BILL IN CASH                  |\n";
		cout << "\t\t\t\t                                         \n";
		cout << "\t\t\t\t                                         \n";
		select();
	}
void updatinglogin()
{
	system("color 5A");
	ifstream kf("login.text");
	kf >> un >> pw;
	kf.close();
DON3:
	cout << "|   ENTER YOUR OLD USERNAME   |";
	do{
		cin.ignore();
		cin.getline(username1, 30);
		fchk = charcheck(username1);
	} while (fchk == 0);
	if (strcmp(username1, un) != 0){
		cout << "INVALID\n";
		goto DON3;
	}
DON4:
	string pass4 = "";
	cout << "|   ENTER YOUR OLD PASSWORD   |";
	password1 = _getch();
	while (password1 != 13){
		pass4.push_back(password1);
		cout << '*';
		password1 = _getch();
	}
	if (pw != pass4){
		cout << "INVALID\n";
		goto DON4;
	}
cout << "1)UPDATING USERNAME\n2)UPDATING PASSWORD\n";
	cin >> choice;
	if (choice == "1"){
		cout << "|   ENTER NEW USERNAME   |";
		cin >> un;
		cout << "|-*-*-*-*-*SUCCESSFULLY CHANGED -*-*-*-*-*|";
		ofstream sd("login.text");
		sd << un << endl << pw << endl;
		sd.close();
		ifstream kf("login.text");
		kf >> un >> pw;
		kf.close();
	}
	else
	if (choice == "2"){
		 LLL();
	}
}
	void LLL()
	{
		cout << "| ENTER NEW PASSWORD |";
		cin >> pw;
			cout << "|-*-*-*-*-*SUCCESSFULLY CHANGED-*-*-*-*-*|";
		ofstream sd("login.text");
		sd << un << endl << pw  << endl;
		sd.close();
		ifstream kf("login.text");
		kf >> un >> pw;
		kf.close();
}
void select()
{
	cout << "\t\t\t\t                                         \n";
	cout << "1) NEW CUSTOMER\n2) EXIT\n";
	cout << "\t\t\t\t                                         \n";
	cout << "\t\t\t\t                                         \n";
	cout << "\t\t\t\t                                         \n";
	cout << "|  ENTER CHOICE  |";
	cin >> choice;
	if (choice == "1")
	{
		NEWCUSTOMER();
	}else
	if (choice == "2"){
		cout << "THANLK YOU\n";
	}
else
{
	cout << "ENTER A VALID STATEMENT\n";
}
}
void NEWCUSTOMER()
{
	cout << "*****ENTER DETAIL OF SENDER*****";
	cout << "NAME IS=" << endl;
	do{
		cin.ignore();
		cin.getline(S_name, 30);
		fchk = charcheck(S_name);
	} while (fchk == 0);
	cout << "ADRESS IS=" << endl;
	cin >> S_address;
	cout << "CNIC NUMBER IS=" << endl;
	do{
		cin.ignore();
		cin >> S_CNIC;
		fchk = intcheck(S_CNIC);
	} while (fchk == 0);
	cout << "CELL NUMBER IS=" << endl;
	do{
		cin >> S_cell_no;
		fchk = intcheck(S_cell_no);
	} while (fchk == 0);
	cout << "|   SENDER DETAILS ARE   |\n";
	cout << "\n";
	cout << "NAME IS=" << S_name << endl;
	cout << "CNIC NUMBER IS==" << S_CNIC << endl;
	cout << "ADDRESS IS=" << S_address << endl;
	cout << "CELL NUMBER IS=" << S_cell_no << endl;
	cout << "************************************************************************************************************\n";
	delay(2000);
	system("cls");
	cout << "*****ENTER DETAIL OF RECIEVER*****";
	cout << "NAME IS=" << endl;
	do{
		cin.ignore();
		cin.getline(R_name, 30);
		fchk = charcheck(R_name);
	} while (fchk == 0);
	cout << "ADRESS IS=" << endl;
	cin >> R_address;
	cout << "CNIC NUMBER IS=" << endl;
	do{
		
		cin >> R_CNIC;
		fchk = intcheck(R_CNIC);
	} while (fchk == 0);
	cout << "CELL NUMBER IS=" << endl;
	do{
		cin >> R_cell_no;
		fchk = intcheck(R_cell_no);
	} while (fchk == 0);
	cout << "|   RECIEVER DETAILS ARE   |\n";
	cout << "\n";
	cout << "NAME IS=" << R_name << endl;
	cout << "CNIC NUMBER IS==" << R_CNIC << endl;
	cout << "ADDRESS IS=" << R_address << endl;
	cout << "CELL NUMBER IS=" << R_cell_no << endl;
	cout << "\n\n";
	cout << "************************************************************************************************************\n";
	delay(2000);
	system("cls");
	char product[100][25];
	int Weight[100], j;
	cout << "**********************************\n";
	cout << "ENTER AMOUNT OF PRODUCTS=";
	cin >> j;
	for (int i = 1; i <= j; i++){
		cout << "NAME OF\t" << i << " PRODUCT=";
		do{
			cin.ignore();
			cin >> product[i];
			fchk = charcheck(product[i]);
		} while (fchk == 0);
		cout << "ENTER WEIGHT IN KG=";
		cin >> Weight[j];
		cout << endl;
		sum = sum + Weight[j];
	}
	cout << "TOTAL WEIGHT IS=" << sum << endl;
	cout << "********************************\n";
	float distance;
	double TD, RW, RD;

	cout << "ENTER DISTANCE IN KM =";
	cin >> distance;
            RW = sum * 5;
	RD = distance * 10;
	TD = RW + RD;
	cout << "YOUR BILL IS=" << TD << endl;
	ofstream L("DATA.text");
	L << S_name << "\t" << S_CNIC << "\t" << S_address << "\t" << S_cell_no;
	L << "\t" << R_name << "\t" << R_CNIC << "\t" << R_address << "\t" << R_cell_no;

	L << "\t" << RW << "\t" << RD << "\t" << TD << endl;
	L.close();

cout << "********************************\n";
	select();
}

