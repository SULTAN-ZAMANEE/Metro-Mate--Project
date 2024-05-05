#include<iostream>
#include<string>
#include<fstream>
#include<ctime>
#include <cstdio> // For rename function  --> Musab
#include <chrono>

using namespace std;
using namespace std::chrono;

int NumberOfDataInTheArray = 0, numberOfCustomersWithinTheFile = 0, numberOfAdmensWithinTheFile = 0, size = 100, blueSize = 35, redSize = 18, greenSize = 23, chakIn, chakInIndex, chakOut, chakOutIndex, tmp;
string inLine, outLine;
const string admensPassword = "Metro_officials";
int customerIndex, admenIndex,Balance,stage,wallet,Edit, RorE, checkEdit;
char ChooseSubscribtion = '0', PublicPeriod;
string FullNameOfSubs[] = { "Student","Public","Wallet" };
int PriceStudent[] = { 33,41,50,65 };
int PricePubMonth[] = { 230,290,340,450 };
int PricePubYear[] = { 1500,2500,3500,4500 };
string StudenEdit, PublicEdit, WalletEdit;//for editing names
int redLineStations_size = 18;
int greenLineStations_size = 23;
int blueLineStations_size = 35;
int max_id = 72;


int CoA = 0, Id; // 1 for Customer, 2 for Admin
string username, password, codeA, codeB, code1;
// all function
int CAmenu(); // frist menu (Custumer or Admin) user choice betwen be custumer or admin
int Lmenu(int);// secon menu (loing or register) user choice betwen be loing or register
void Cmenu(int count); // custumer menu for custumer functions
void Amenu();// admin menu for admin functions
bool login();// login function (check if user registered)
int registerUser(int); // register function (make new file for user )
void code();// password for check if user is Admin named code
void ccode();// (change code function) by Admin
bool admenslogin();
int registerAdmen(int );
void addNewCustomer();
void ThreeMonthsEx();//function to display the expirtion time
void OneYearEx();//function to display the expirtion time
void OneMonthEx();//function to display the expirtion time
void ViewSub();//to view subscribtion
void StudentSub();//student subuscribtion
void PublicSub();//public subuscribtion
void WalletSub();//wallet subuscribtion
void subscriptions();//subscrib
void SubscribtionsEdit(int y);
int FindStation(metro_station LineStations[], string station_name, int no_of_stations);//mahmoud
void addstation(string station_name);//mahmoud

struct user {//????? ?????? ???????? 
	string type, password, name;
	int id, balans;

}*users = new user[100];

struct admen {//????? ?????? ???????? 
	string password, name;
	int id;

}*Admens = new admen[100];


struct metro_station {
	int id;
	string name;
	string line;
}*greenLineStations = new metro_station[greenSize], * blueLineStations = new metro_station[blueSize], * redLineStations = new metro_station[redSize];


// =========================== Start Musab Part ==================================

//int CoA = 0,; // 1 for Customer, 2 for Admin
//string username, password, codeA, codeB, code1;
   // all function // frist menu (Custumer or Admin) user choice betwen be custumer or admin
// int Lmenu();// secon menu (loing or register) user choice betwen be loing or register
// void Cmenu();// custumer menu for custumer functions
// void Amenu();// admin menu for admin functions
// bool login();// login function (check if user registered)
// void registerUser(); // register function (make new file for user )
// void code();// password for check if user is Admin named code
// void ccode();// (change code function) by Admin




int Lmenu(int X, int user = 1) {// secon menu (loing or register) user choice betwen be loing or register
	string choice;
	cout << "\n@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n";
	cout << "                Login Menu       \n";
	cout << "             * welcome *    \n";
	cout << "========================================\n\n";
	cout << " 1. Login\n";    // login func
	cout << " 2. Register\n"; // register func
	cout << "\n0. GO back to C.A menu\n"; // end program
	cout << "\n========================================\n\n";
	cout << " Enter your choice: ";
	cin >> choice;
	// tmp = X;
	if (user == 1) {
		if (choice == "1") {// if user choice login, going login function
			login();
		}
		else if (choice == "2") {// if user choice  register , going  register function
			addNewCustomer();
		}
		else if (choice == "0") {// if user choice  going back to Customer or Admin menu , going U.A menu 
			cout << " don !...\n";
			// break;
		}
		else {
			cout << "Invalid choice!\n";
			system("cls");
			return Lmenu (X,user);
		}
	}
	else {
		if (choice == "1") {// if user choice login, going login function
			admenslogin();
		}
		else if (choice == "2") {// if user choice  register , going  register function
			registerAdmen(X);
		}
		else if (choice == "0") {// if user choice  going back to Customer or Admin menu , going U.A menu 
			cout << " don !...\n";
			// break;
		}
		else {
			cout << "Invalid choice!\n";
			Lmenu(X,user);
		}
	}
	return 0;
}

void Cmenu(int count) {// custumer menu for custumer functions
	string choice;
	cout << "\n&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&\n";
	cout << "                  main menu\n";
	cout << "           * welcome " << users[customerIndex].name << " * " << endl;
	cout << "========================================\n";
	cout << "Enter the number of the thing you want to do:- \n";
	cout << " 1. If you want to go somewhere\n";
	cout << " 2. Information about your subscription\n";
	cout << " \n0. GO back to login menu.....\n";
	cout << "\n========================================\n\n";
	cout << " Enter your choice: ";
	cin >> choice;
	if (choice == "1") {// if user choice  going back to login menu , going login menu
		cout << "End The Program. Exiting...\n";
		Lmenu(numberOfCustomersWithinTheFile, count);
	} // add new function for user menu......................................................................
	else if (choice == "2")
	{
			cout << "Enter\n 1. to subscribe\n 2.view subscribtion\n";
			cin >> choice;
			if (choice == "1")
			{
				subscriptions();
			}
			else if (choice == "2")
			{
				ViewSub();
			}
			else
			{
				cout << "invalid";
				choice = "0";
			}
		Cmenu(customerIndex);
	}
	else {
		cout << "Invalid choice!\n\n";
		Cmenu(customerIndex);
	}
}

void Amenu() {// admin menu for admin functions
	string choice;
	cout << "\n%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%\n";
	cout << "                  Admin menu\n";
	cout << "           * welcome " << username << " * " << endl;
	cout << "========================================\n";
	cout << "             What Well We Do \n\n";
	cout << " 1. change password( code )\n";
	cout << " 2. anything\n";
	cout << " \n0. GO back to login menu.....\n";
	cout << "\n========================================\n\n";
	cout << " Enter your choice: ";
	cin >> choice;
	if (choice == "0") {// if user choice  going back to login menu , going login menu
		cout << "End The Program. Exiting...\n";
		Lmenu(0,1);
	}
	else if (choice == "1") {// for change password ( code ) ,going ccode fun  (change code function)
		ccode();
	} // add new function for user menu......................................................................
	else {
		cout << "Invalid choice!\n\n";
		Amenu();
	}
}

bool login() {// login function (check if user registered)
	string un, pw;// for comparison betweem un & username and pw & password
	char answer;
	cout << "Enter the ID: ";
	cin >> Id;
	cout << "\nEnter The Username: ";
	cin >> username;
	cout << "Enter The Password: ";
	cin >> password;

	for (int i = 0; i <= numberOfCustomersWithinTheFile; i++) {
		if (Id != users[i].id) {
			continue;

		}
		else {
			customerIndex = i;
			if (users[i].name == username && users[i].password == password) {// if user login successfuly
				cout << "Login successful!" << endl;
				if (CoA == 1) // going Customer menu if user choice it
					Cmenu(customerIndex);
				else if (CoA == 2) // going Admin menu if user choice it
					Amenu();
				return true;
			}
			else if (users[i].name == username && users[i].password != password) {// username correct but password wrong
				cout << "Invalid password !" << endl;
				cout << "if you whant continue press \"y\"";
				cin >> answer;
				if (answer == 'y' || answer == 'Y')
					login();
				else
					Lmenu(0,1);
			}
			else {
				cout << "Invalid username or password!" << endl;
				cout << "if you whant continue press \"y\"";
				cin >> answer;
				if (answer == 'y' || answer == 'Y')
					login();
				else
					Lmenu(0,1);
			}
		}
	}
	cout << "this is invalude \"ID\" \nPlease Enter your \"ID\" again";

	return true;
}
bool admenslogin() {// login function (check if user registered)
	string un, pw;// for comparison betweem un & username and pw & password
	char answer;
	cout << "Enter the ID: ";
	cin >> Id;
	cout << "\nEnter The Username: ";
	cin >> username;
	cout << "Enter The Password: ";
	cin >> password;

	for (int i = 0; i <= numberOfAdmensWithinTheFile; i++) {
		if (Id != Admens[i].id) {
			continue;

		}
		else {
			admenIndex = i;
			if (Admens[i].name == username && Admens[i].password == password) {// if user login successfuly
				cout << "Login successful!" << endl;
				if (CoA == 1) // going Customer menu if user choice it
					Cmenu(admenIndex);
				else if (CoA == 2) // going Admin menu if user choice it
					Amenu();
				
			}
			else if (Admens[i].name == username && Admens[i].password != password) {// username correct but password wrong
				cout << "Invalid password !" << endl;
				cout << "if you whant continue press \"y\"";
				cin >> answer;
				if (answer == 'y' || answer == 'Y')
					admenslogin();
				
				else
					Lmenu(0,1);
			}
			else {
				cout << "Invalid username or password!" << endl;
				cout << "if you whant continue press \"y\"";
				cin >> answer;
				if (answer == 'y' || answer == 'Y')
					admenslogin();
				else
					Lmenu(0,1);
				
			}
		}
	}
	cout << "this is invalude \"ID\" \nPlease Enter your \"ID\" again";

	return true;
}

int registerUser(int usersNumber) { // register function (make new file for user)
	users[usersNumber].id = users[usersNumber - 1].id + 1;
	string un, pw;// for comparison betweem un & username and pw & password
	cout << "\nEnter your name: ";
	cin >> users[usersNumber].name;
	cout << "Enter your Password: ";
	cin >> users[usersNumber].password;
	cout << "Enter \"Password\" again to confirm:  ";
	cin >> pw;
	if (pw == users[usersNumber].password) {
		cout << "The account has been created successfully\n";
		numberOfCustomersWithinTheFile++;
		Cmenu(usersNumber);  // I subtracted "one" so that it would be the same as the "index" of the new customer
	}
	else {
		cout << "The two passwords are not the same.\nPlease enter the same password this time";
		registerUser(usersNumber);
	}


	// if (un == username) {// if user exsit before user can't add same name user name
	//     cout << "Username was Registered! \n";
	//     Lmenu();
	// }
	// else {
	//     ofstream file;// creat new file (account)
	//     // file.open(username + ".txt");
	//     if (!file.is_open()) {
	//         cout << "Error creating user file!" << endl;
	//         Lmenu();
	//     }
	//     file << username << endl << password;// write username in frist line and password in scond line
	//     file.close();
	//     cout << "...Done!\n";

	//     if (CoA == 1)// going Customer menu if user choice it
	//         Cmenu();
	//     else if (CoA == 2) // going Admin menu if user choice it
	//         Amenu();
	// }
	return 0;
}


int registerAdmen(int admensNumber) { // register function (make new file for user)
	users[admensNumber].id = users[admensNumber - 1].id + 1;
	string un, pw;// for comparison betweem un & username and pw & password
	cout << "\nEnter your name: ";
	cin >> users[admensNumber].name;
	cout << "Enter your Password: ";
	cin >> users[admensNumber].password;
	cout << "Enter \"Password\" again to confirm:  ";
	cin >> pw;
	if (pw == users[admensNumber].password) {
		cout << "The account has been created successfully\n";
		numberOfAdmensWithinTheFile++;
		Cmenu(admensNumber);  // I subtracted "one" so that it would be the same as the "index" of the new customer
	}
	else {
		cout << "The two passwords are not the same.\nPlease enter the same password this time";
		registerUser(admensNumber);
	}


	// if (un == username) {// if user exsit before user can't add same name user name
	//     cout << "Username was Registered! \n";
	//     Lmenu();
	// }
	// else {
	//     ofstream file;// creat new file (account)
	//     // file.open(username + ".txt");
	//     if (!file.is_open()) {
	//         cout << "Error creating user file!" << endl;
	//         Lmenu();
	//     }
	//     file << username << endl << password;// write username in frist line and password in scond line
	//     file.close();
	//     cout << "...Done!\n";

	//     if (CoA == 1)// going Customer menu if user choice it
	//         Cmenu();
	//     else if (CoA == 2) // going Admin menu if user choice it
	//         Amenu();
	// }

	return 0;
}

void code() {// password for check if user is Admin named code
	string name;//to read name code file
	cout << "\nEnter the Admens code: ";
	cin >> code1;//enter password


	for (int i = 0; i <= 5; i++) {
		if (code1 == admensPassword) {//check the password add by user and the orginel password
			CoA = 2;// if the password correct make CoA = 2 <= (for Admen menu)
			Lmenu(0,1);//frist go login menu to add user account
		}
		else if (i == 5) {
			cout << "You have entered the wrong password more than 5 times\n";
			cout << "==========================";
		}
		else
			cout << "Wrong code\n=============================================\nPlease enter the correct password:- ";//if password wrong go back
	}
}

void ccode() {// (change code function) by Admin
	string adminUsername = "admin"; // Assuming the admin username is fixed as "admin"
	string oldPassword, newPassword;

	cout << "Enter the old password (old code): ";
	cin >> oldPassword;

	if (oldPassword != codeA) {// Check if the entered password matches the admin's current password
		cout << "Incorrect password!" << endl;// if password add wrong go back to Amenu
		Amenu();
	}

	cout << "Enter the new password (new code): ";// if password crrect add the new password
	cin >> newPassword;

	codeA = newPassword;   // Update the admin's password

	ofstream outFile("admin.txt");// Write the new password to the admin's password file
	if (!outFile.is_open()) {
		cout << "Error: Unable to open password file for writing!" << endl;
		Amenu();
	}
	outFile << adminUsername << endl << codeA;
	outFile.close();

	cout << "Password changed successfully!" << endl;
}

// =========================== End Musab Part ====================================

// &&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&

// =========================== Start Taha Part ===================================

#define bathOfCustmerDataFile "Custmer Data.txt"
#define bathOfAdmenDataFile "Admen Data.txt"
#define bathOfBlueLineStationsFile "blue Line Stations.txt"
#define bathOfRedLineStationsFile "Red Line Stations.txt"
#define bathOfGreenLineStationsFile "Green Line Stations.txt"
void chakOutStation();

//int NumberOfDataInTheArray = 0, size = 100,blueSize = 35,redSize = 18, greenSize = 23;

//struct user {//????? ?????? ???????? 
//	string type, password, name;
//	int id, balans;
//
//}*users = new user[size];

//struct metro_station{
//	int id;
//	string name;
//	string line;
//}* greenLineStations = new metro_station[greenSize],* blueLineStations = new metro_station[blueSize], * redLineStations = new metro_station[redSize];

void list() {
	cout << "what do you want to do:\n";
	cout << "	to edit		-->	1\n";
	cout << "	to delete	-->	2\n";
	cout << "	for display	-->	3\n";
}

void saveCustomerData() {
	fstream DataStorage;
	DataStorage.open(bathOfCustmerDataFile, ios::out);
	//	int i = 0;


	if (!DataStorage.is_open()) {
		cout << "you have an error";
	}
	else {

		for (int i = 0; i < numberOfCustomersWithinTheFile; i++) {
			if (users[i].id > 0) {
				DataStorage << users[i].id << "		";
				DataStorage << users[i].name << "		";
				DataStorage << users[i].password << "		";
				if (!(users[i].balans < 0))
					DataStorage << users[i].balans << "\n";
				else
					DataStorage << 0 << "\n";
			}
			else
				continue;
		}
		cout << "The new data has been saved successfully\n";
		DataStorage.close();
	}
}

void saveAdmenDataToFile() {
	fstream DataStorage;
	DataStorage.open(bathOfAdmenDataFile, ios::out);
	int i = 0;


	if (!DataStorage.is_open()) {
		cout << "you have an error";
	}
	else {

		for (int i = 0; i < numberOfAdmensWithinTheFile; i++) {
			if (Admens[i].id > 0) {
				DataStorage << Admens[i].id << "	";
				DataStorage << Admens[i].name << "		";
				DataStorage << Admens[i].password << "\n";
			}
			else
				continue;
		}
		cout << "The new data has been saved successfully\n";
		DataStorage.close();
	}
}


void IncludeGreenStationsData() {
	fstream DataStorage;
	DataStorage.open(bathOfGreenLineStationsFile, ios::in);
	int i = 0, ID;
	// user *users = new user[size];

	if (!DataStorage.is_open()) {
		cout << "you have an error";
	}
	else {
		// cout <<"begin... \n";
		while (i < greenSize && !DataStorage.eof()) {

			DataStorage >> ID;
			if (i == 0 && ID > 0) {
				greenLineStations[i].id = ID;
				DataStorage >> greenLineStations[i].name;
				DataStorage >> greenLineStations[i].line;
				i++;
			}
			else if (ID > 0 && ID != greenLineStations[i - 1].id) {
				greenLineStations[i].id = ID;
				DataStorage >> greenLineStations[i].name;
				DataStorage >> greenLineStations[i].line;
				// cout << "User1.["<<i + 1<<"] Done\n";
				i++;
			}
			else {
				continue;
			}

		}
		i = 0;
		cout << "ID		" << "Name		" << "Line\n";
		for (i; i < greenSize; i++) {
			cout << greenLineStations[i].id << "	";
			cout << greenLineStations[i].name << "		";
			cout << greenLineStations[i].line << "\n";

		}

		DataStorage.close();
	}
}

void saveGreenStationsData() {
	fstream DataStorage;
	DataStorage.open(bathOfGreenLineStationsFile, ios::out);
	int i = 0;

	if (!DataStorage.is_open()) {
		cout << "you have an error";
	}
	else {

		// cout << greenLineStations[0].id <<"	";
		// cout << greenLineStations[0].name <<"		";
		// cout << greenLineStations[0].line <<"\n";
		for (int i = 0; i < greenSize; i++) {
			if (greenLineStations[i].id > 0) {
				DataStorage << greenLineStations[i].id << "	";
				DataStorage << greenLineStations[i].name << "		";
				DataStorage << greenLineStations[i].line << "\n";
				cout << "Station.[" << i + 1 << "] Done\n";
			}
			else
				continue;
		}
		cout << "The new data has been saved successfully\n";
		DataStorage.close();
	}
}
void saveRedStationsData() {
	fstream DataStorage;
	DataStorage.open(bathOfRedLineStationsFile, ios::out);
	int i = 0;

	if (!DataStorage.is_open()) {
		cout << "you have an error";
	}
	else {

		// cout << greenLineStations[0].id <<"	";
		// cout << greenLineStations[0].name <<"		";
		// cout << greenLineStations[0].line <<"\n";
		for (int i = 0; i < redSize; i++) {
			if (redLineStations[i].id > 0) {
				DataStorage << redLineStations[i].id << "	";
				DataStorage << redLineStations[i].name << "		";
				DataStorage << redLineStations[i].line << "\n";
				cout << "Station.[" << i + 1 << "] Done\n";
			}
			else
				continue;
		}
		cout << "The new data has been saved successfully\n";
		DataStorage.close();
	}
}
void saveBlueStationsData() {
	fstream DataStorage;
	DataStorage.open(bathOfBlueLineStationsFile, ios::out);
	int i = 0;

	if (!DataStorage.is_open()) {
		cout << "you have an error";
	}
	else {

		// cout << greenLineStations[0].id <<"	";
		// cout << greenLineStations[0].name <<"		";
		// cout << greenLineStations[0].line <<"\n";
		for (int i = 0; i < blueSize; i++) {
			if (blueLineStations[i].id > 0) {
				DataStorage << blueLineStations[i].id << "	";
				DataStorage << blueLineStations[i].name << "		";
				DataStorage << blueLineStations[i].line << "\n";
				cout << "Station.[" << i + 1 << "] Done\n";
			}
			else
				continue;
		}
		cout << "The new data has been saved successfully\n";
		DataStorage.close();
	}
}

void addNewCustomer() {
	numberOfCustomersWithinTheFile++;
	cout << "enter the \"ID\" of new user: 	";
	cin >> users[numberOfCustomersWithinTheFile - 1].id;
	cout << "enter the \"Name\" of new user: 	";
	cin >> users[numberOfCustomersWithinTheFile - 1].name;
	cout << "enter the \"Password\" of new user: 	";
	cin >> users[numberOfCustomersWithinTheFile - 1].password;
	Cmenu(0);

}

void copyCustomerDataFromTheFile() {
	fstream DataStorage;
	DataStorage.open(bathOfCustmerDataFile, ios::in);
	int i = 0, ID;
	// user *users = new user[size];

	if (!DataStorage.is_open()) {
		cout << "you have an error";
	}
	else {
		// cout <<"begin... \n";
		while (i < 100 && !DataStorage.eof()) {
			++NumberOfDataInTheArray;

			string line;
			DataStorage >> ID;
			if (ID > 0 && ID != users[i - 1].id) {
				users[i].id = ID;
				DataStorage >> users[i].name;
				DataStorage >> users[i].password;
				DataStorage >> users[i].balans;
				getline(DataStorage, line);
				// cout << "User1.["<<++i<<"] Done\n";
				i++;
			}
			else {
				getline(DataStorage, line);
				continue;
			}

		}
		i = 0;
		cout << "ID		" << "Name		" << "Password	" << "Balans\n";
		for (int i = 0; i < NumberOfDataInTheArray; i++) {
			cout << users[i].id << "	";
			cout << users[i].name << "		";
			cout << users[i].password << "		";
			cout << users[i].balans << "\n";

		}

		DataStorage.close();
	}

}

void copyAdmenDataFromTheFile() {
	fstream DataStorage;
	DataStorage.open(bathOfAdmenDataFile, ios::in);
	int i = 0, ID;
	// user *users = new user[size];

	if (!DataStorage.is_open()) {
		cout << "you have an error";
	}
	else {
		// cout <<"begin... \n";
		while (i < 100 && !DataStorage.eof()) {
			++numberOfAdmensWithinTheFile;

			string line;
			DataStorage >> ID;
			if (ID > 0 && ID != Admens[i - 1].id) {
				Admens[i].id = ID;
				DataStorage >> Admens[i].name;
				DataStorage >> Admens[i].password;
				// DataStorage>> users[i].balans;
				getline(DataStorage, line);
				cout << "User1.[" << i + 1 << "] Done\n";
				i++;
			}
			else {
				getline(DataStorage, line);
				continue;
			}

		}
		i = 0;
		cout << "ID		" << "Name		" << "Password\n";
		for (int i = 0; i < numberOfAdmensWithinTheFile; i++) {
			cout << Admens[i].id << "	";
			cout << Admens[i].name << "		";
			cout << Admens[i].password << "		";
			//  cout << users[i].balans <<"\n";

		}

		DataStorage.close();
	}

}

void EidetcustomerAccounts() {
	int ans;
	cout << "Enter the ID of the person you want to edit: ";
	cin >> Id;
	for (int i = 0; i < numberOfCustomersWithinTheFile; i++) {
		if (Id == users[i].id) {
			cout << "What do you want to modify in \"" << users[i].name << "\" data?:-\n for \"ID\" Enter 	-->		1\nfor \"password\" Enter 	-->		2\nfor \"name\" Enter 	-->		3\n";
			cin >> ans;
			if (ans == 1) {
				cout << "ID		" << "Name		" << "Password\n";
				cout << users[i].id << "	";
				cout << users[i].name << "		";
				cout << users[i].password << "\n";
				cout << "Enter a new \"ID\" for " << users[i].name << " :- ";
				cin >> users[i].id;
			}
			else if (ans == 2) {
				cout << "ID		" << "Name		" << "Password\n";
				cout << users[i].id << "	";
				cout << users[i].name << "		";
				cout << users[i].password << "\n";
				cout << "Enter a new \"password\" for " << users[i].name << ":- ";
				cin >> users[i].password;
			}
			else if (ans == 3) {
				cout << "ID		" << "Name		" << "Password\n";
				cout << users[i].id << "	";
				cout << users[i].name << "		";
				cout << users[i].password << "\n";
				cout << "Enter a new \"Name\" for " << users[i].name << ":- ";
				cin >> users[i].name;
			}
			else {
				cout << "invalide value\n";
				--i;
			}
		}
	}
}

void deleteCustomerAccounts() {
	cout << "Enter the \"ID\" of the person you want to delet: ";
	int ans;
	cin >> ans;
	for (int i = 0; i <= numberOfCustomersWithinTheFile; i++) {
		if (ans == users[i].id) {
			users[i].id = -1;
			users[i].name.clear();
			users[i].password.clear();
			cout << "This user has been successfully deleted\n";
		}
	}
}


void theJourney() {
	int I;
	cout << "There are three lines:-\n";
	cout << "1. from \"New El-Marg\" to \"Helwan\"\n";
	cout << "2. from \"Shubra\" to \"Sakyat Makky\"\n";
	cout << "3. from \"adly_mansor\" to \"Kit_Kat\"\n";
	cout << "--------------------------------------------------\n";
	cout << "Which line are you on now? 1 Or 2 Or 3:- ";
	cin >> I;
	if (I == 1) {
		inLine = "blue";
		cout << "ID		" << "Name\n";
		for (int i = 0; i < blueSize; i++) {
			cout << blueLineStations[i].id << "	";
			cout << blueLineStations[i].name << "\n";
		}
		cout << "Enter \"0\" to go back \nEnter the \"ID\" of the station you are on now :";
		cin >> chakIn;
		if (chakIn == 0)
			theJourney();
		else {
			for (int i = 0; i < blueSize; i++) {
				if (chakIn == blueLineStations[i].id)
					chakInIndex = i;
			}
			chakOutStation();
		}
	}
	else if (I == 2) {
		inLine = "red";
		cout << "ID		" << "Name\n";
		for (int i = 0; i < redSize; i++) {
			cout << redLineStations[i].id << "	";
			cout << redLineStations[i].name << "\n";
		}
		cout << "Enter \"0\" to go back \nEnter the \"ID\" of the station you are on now :";
		cin >> chakIn;
		if (chakIn == 0)
			theJourney();
		else {
			for (int i = 0; i < redSize; i++) {
				if (chakIn == blueLineStations[i].id)
					chakInIndex = i;
			}
			chakOutStation();
		}
	}
	else if (I == 3) {
		inLine = "green";
		cout << "ID		" << "Name\n";
		for (int i = 0; i < greenSize; i++) {
			cout << greenLineStations[i].id << "	";
			cout << greenLineStations[i].name << "\n";

		}
		cout << "Enter \"0\" to go back \nEnter the \"ID\" of the station you are on now :";
		cin >> chakIn;
		if (chakIn == 0)
			theJourney();
		else {
			for (int i = 0; i < greenSize; i++) {
				if (chakIn == greenLineStations[i].id)
					chakInIndex = i;
			}
			chakOutStation();
		}
	}
	else {
		cout << "invalide value\nPlease choose from the numbers specified for you\n";
		theJourney();
	}
}


void chakOutStation() {
	int I;
	cout << "There are three lines:-\n";
	cout << "1. from \"New El-Marg\" to \"Helwan\"\n";
	cout << "2. from \"Shubra\" to \"Sakyat Makky\"\n";
	cout << "3. from \"adly_mansor\" to \"Kit_Kat\"\n";
	cout << "--------------------------------------------------\n";
	cout << "Which line do you want to go to? 1 Or 2 Or 3:- ";
	cin >> I;
	if (I == 1) {
		outLine = "blue";
		cout << "ID		" << "Name\n";
		for (int i = 0; i < blueSize; i++) {
			cout << blueLineStations[i].id << "	";
			cout << blueLineStations[i].name << "\n";
		}
		cout << "Enter \"0\" to go back \nEnter the \"ID\" of The station you want to go to :";
		cin >> chakOut;
		if (chakOut == 0)
			chakOutStation();
		else {
			for (int i = 0; i < blueSize; i++) {
				if (chakOut == blueLineStations[i].id)
					chakOutIndex = i;
			}
		}
		// chakOutStation();
	}
	else if (I == 2) {
		outLine = "red";
		cout << "ID		" << "Name\n";
		for (int i = 0; i < redSize; i++) {
			cout << redLineStations[i].id << "	";
			cout << redLineStations[i].name << "\n";
		}
		cout << "Enter \"0\" to go back \nEnter the \"ID\" of The station you want to go to :";
		cin >> chakOut;
		if (chakOut == 0)
			chakOutStation();
		else {
			for (int i = 0; i < redSize; i++) {
				if (chakOut == redLineStations[i].id)
					chakOutIndex = i;
			}
		}
		// chakOutStation();
	}
	else if (I == 3) {
		outLine = "green";
		cout << "ID		" << "Name\n";
		for (int i = 0; i < greenSize; i++) {
			cout << greenLineStations[i].id << "	";
			cout << greenLineStations[i].name << "\n";

		}
		cout << "Enter \"0\" to go back \nEnter the \"ID\" of The station you want to go to :";
		cin >> chakOut;
		if (chakOut == 0)
			chakOutStation();
		else {
			for (int i = 0; i < greenSize; i++) {
				if (chakOut == greenLineStations[i].id)
					chakOutIndex = i;
			}
		}
		// chakOutStation();
	}
	else {
		cout << "invalide value\nPlease choose from the numbers specified for you\n";
		theJourney();
	}
}



// =========================== End Taha Part ====================================

// &&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&

// =========================== Start Diaa Part ==================================

void subscriptions() {
	cout << "enter your balance:";
	cin >> Balance;
	do {
		cout << "Enter\n";
		cout << "1. for" << " " << FullNameOfSubs[0] << " " << "subscribtion" << "\n";
		cout << "2. for" << " " << FullNameOfSubs[1] << " " << "subscribtion" << "\n";
		cout << "3. for" << " " << FullNameOfSubs[2] << " " << "subscribtion" << "\n";
		cin >> ChooseSubscribtion;
		if (ChooseSubscribtion == '1')//student sub
		{
			StudentSub();
			"\n";
			ThreeMonthsEx();
		}
		else if (ChooseSubscribtion == '2') //public sub
		{
			PublicSub();

		}
		else if (ChooseSubscribtion == '3')//wallet sub
		{
			WalletSub();
			//func to display the exprition date
		}
		/*else if (ChooseSubscribtion == 'q' || ChooseSubscribtion == 'Q')
		{
			cout << "Exiting the program...";
			exit(0); // Exit the program
		}
		/*else if (ChooseSubscribtion == 'r' || ChooseSubscribtion == 'R')
		{
			cout << "retrnt to home page";

		}*/
		else
		{
			cout << "invalid  3  input   3\n";
		}
	} while (!(ChooseSubscribtion == '1' || ChooseSubscribtion == '2' || ChooseSubscribtion == '3'));
}
void SubscribtionsEdit(int y)
{
	do
	{
		cout << "do you want to edit(1) or remove(2)";
		cin >> RorE;
		if (RorE == 1)
		{
			cout << "enter 1 to edit the student sub 2 for public and 3 waller";
			cout << "which sub you want to edit:";

			cin >> Edit;
			if (Edit == 1)
			{
				cout << "enter new name:";
				cin >> StudenEdit;
				FullNameOfSubs[0] = StudenEdit;
				cout << "(Editing completed)";
			}
			else if (Edit == 2)
			{
				cout << "enter new name:";
				cin >> PublicEdit;
				FullNameOfSubs[1] = PublicEdit;
				cout << "(Editing completed)";
			}
			else if (Edit == 3)
			{
				cout << "enter new name:";
				cin >> WalletEdit;
				FullNameOfSubs[2] = WalletEdit;
				cout << "(Editing completed)";
			}
		}
		else if (RorE == 2)
		{
			cout << "enter 1 to remove the student sub 2 for public and 3 waller";
			cout << "which sub you want to remove:";

			cin >> Edit;
			if (Edit == 1)
			{
				FullNameOfSubs[0] = "";
				cout << "(removal completed)";
			}
			else if (Edit == 2)
			{
				FullNameOfSubs[1] = "";
				cout << "(removal completed)";
			}
			else if (Edit == 3)
			{
				FullNameOfSubs[2] = "";
				cout << "(removal completed)";
			}
		}
		cout<<"\ndo you want to check\n";
		cin >> Edit;
		if (Edit==1)
		{
			for (int i = 0; i < sizeof(FullNameOfSubs); i++)
			{
				cout << FullNameOfSubs[i];
			}
		}
		else
		{
			break;
		}
		
	} while ((Edit == 0));
}
void PublicSub()
{
	do
	{
		cout << "\nEnter\n 1. for a month public subscribtion\n 2. for a year public subscribtion\n";
		cin >> PublicPeriod;
		if (PublicPeriod == '1' )
		{
			do
			{
				cout << "\n(press 0 to go back)\n" << "\nyou have 60 trips\n" << "which stage:";
				cin >> stage;
				if (stage == 1)
				{
					if (Balance < PricePubMonth[0])
					{
						cout << "you don't have enough more";
					}
					else
					{
						cout << PricePubMonth[0] << "LE will be deducted from your ball\n";
						Balance -= PricePubMonth[0];
						cout << "(subscription compleataed )\n";
						OneMonthEx();
						break;
					}
				}
				else if (stage == 2)
				{
					if (Balance < PricePubMonth[1])
					{
						cout << "you don't have enough more";
					}
					else
					{
						cout << PricePubMonth[1] << "LE will be deducted from your ball\n";
						Balance -= PricePubMonth[1];
						cout << "(subscription compleataed )\n";
						OneMonthEx();
						break;
					}
				}
				else if (stage == 3)
				{
					if (Balance < PricePubMonth[2])
					{
						cout << "you don't have enough more";
					}
					else
					{
						cout << PricePubMonth[2] << "LE will be deducted from your ball\n";
						Balance -= PricePubMonth[2];
						cout << "(subscription compleataed )\n";
						OneMonthEx();
						break;
					}
				}
				else if (stage == 4)
				{
					if (Balance < PricePubMonth[3])
					{
						cout << "you don't have enough more";
					}
					else
					{
						cout << PricePubMonth[3] << "LE will be deducted from your ball\n";
						Balance -= PricePubMonth[3];
						cout << "(subscription compleataed )\n";
						OneMonthEx();
						break;
					}
				}
				else if (stage == 0)
				{
					ChooseSubscribtion = '0';
					break;
				}
				else
				{
					cout << "invalid   3   input   3\n";
				}
				//func to display the exprition date

			} while ((stage >= 0) || (stage <= 4));
		}
		else if (PublicPeriod == '2')
		{
			cout << "\n(press 0 to go back)\n" << "\nyou have 730 trips\n" << "which stage:";

			do
			{
				cin >> stage;
				if (stage == 1)
				{
					if (Balance < PricePubYear[0])
					{
						cout << "you don't have enough more";
						cout << "enter 0 to go back or enter other stage #";
						continue;
					}
					else
					{
						cout << PricePubYear[0] << "LE will be deducted from your bal\n";
						Balance -= PricePubYear[0];
						cout << "(subscription compleataed )\n";
						OneYearEx();
						break;
					}
				}
				else if (stage == 2)
				{
					if (Balance < PricePubYear[1])
					{
						cout << "you don't have enough more";
						cout << "enter 0 to go back or enter other stage #";
						continue;
					}
					else
					{
						cout << PricePubYear[1] << "LE will be deducted from your bal\n";
						Balance -= PricePubYear[1];
						cout << "(subscription compleataed )\n";
						OneYearEx();
						break;
					}
				}
				else if (stage == 3)
				{
					if (Balance < PricePubYear[2])
					{

						cout << "you don't have enough more";
						cout << "enter 0 to go back or enter other stage #";
						continue;
					}
					else
					{
						cout << PricePubYear[2] << "LE will be deducted from your bal\n";
						Balance -= PricePubYear[2];
						cout << "(subscription compleataed )\n";
						OneYearEx();
						break;
					}
				}
				else if (stage == 4)
				{
					if (Balance < PricePubYear[3])
					{
						cout << "you don't have enough more";
						cout << "enter 0 to go back or enter other stage #";
						continue;
					}
					else
					{
						cout << PricePubYear[3] << "LE will be deducted from your bal\n";
						Balance -= PricePubYear[3];
						cout << "(subscription compleataed )\n";
						OneYearEx();
						break;
					}
				}
				else if (stage == 0)
				{
					ChooseSubscribtion = 0;
					break;
				}
				else
				{
					cout << "invalid   2    input   2\n";
				}
				//func to display the exprition date


			} while ((stage >= 0) || (stage <= 4));
		}
		else
		{
			cout << "invalid  1  input   1";
		}
	} while (!(PublicPeriod == '1' || PublicPeriod == '2'));
}
void StudentSub()
{
	do
	{
		cout << "\n(press 0 to go back)\n" << "\nyou have 180 trips\n" << "what stage:";
		cin >> stage;
		if (stage == 1)
		{
			if (Balance < PriceStudent[0])
			{
				cout << "you dont have enough money";
			}
			else
			{
				cout << PriceStudent[0] << "LE will be deducted from your balance\n";
				Balance -= PriceStudent[0];
				cout << "(subscription compleataed )";
				break;
			}
		}
		else if (stage == 2)
		{
			if (Balance < PriceStudent[1])
			{
				cout << "you dont have enough money";
			}
			else
			{
				cout << PriceStudent[1] << "LE will be deducted from your balance\n";
				Balance -= PriceStudent[1];
				cout << "(subscription compleataed )";
				break;
			}
		}
		else if (stage == 3)
		{
			if (Balance < PriceStudent[2])
			{
				cout << "you dont have enough money";
			}
			else
			{
				cout << PriceStudent[2] << "LE will be deducted from your balance\n";
				Balance -= PriceStudent[2];
				cout << "(subscription compleataed )";
				break;
			}
		}
		else if (stage == 4)
		{
			if (Balance < PriceStudent[3])
			{
				cout << "you dont have enough money";
			}
			else
			{
				cout << PriceStudent[3] << "LE will be deducted from your balance\n";
				Balance -= PriceStudent[3];
				cout << "(subscription compleataed )";
				break;
			}
		}
		else if (stage == 0)
		{
			//cout << "Exiting the program...";
			//exit(0); // Exit the program
			ChooseSubscribtion = '0';
			break;
		}
		else
		{
			cout << "\ninvalid   0  input   0\n";
			//cout << "press 0 to go back";
		}

	} while ((stage >= 0) || (stage <= 4));//(stage == 1 || stage == 2  || stage == 3 || stage == 4));
}
void WalletSub()
{
	while (true)
	{
		cout << "\n(press 0 to go back)\n" << "\nenter your amount(amount max=400)\n";
		cin >> wallet;
		if (wallet <= Balance)
		{
			if (wallet > 400)
			{
				cout << "amount not allowed";
				wallet = '0';

				//break;
			}
			else if (wallet <= 400)
			{
				if (wallet % 2 != 0)
				{
					cout << "has to be multiple of 10";
					//break;
					//wallet = '0';
				}
				else if (wallet != 0 && wallet % 2 == 0)
				{
					Balance -= wallet;
					cout << "(subscription compleataed )\n";
					break;
				}
				else if (wallet == 0)
				{
					ChooseSubscribtion = '0'; break;
				}
			}
		}
		else if (wallet > Balance)
		{
			cout << "you dont have enough $$$!";
			wallet = '0';
		}
	}
}
void ViewSub()
{
	if (ChooseSubscribtion == '1')
	{
		cout << "you are sub to" << " " << FullNameOfSubs[0] << " " << "subscribtion\n";
	}
	else if (ChooseSubscribtion == '2')
	{
		cout << "you are sub to" << " " << FullNameOfSubs[1] << " " << "subscribtion\n";
	}
	else if (ChooseSubscribtion == '3')
	{
		cout << "you are sub to" << " " << FullNameOfSubs[2] << " " << "subscribtion\n";

	}
}
void ThreeMonthsEx() {
	// Get the current system time point
	auto now = system_clock::now();

	// Convert the current time point to a time_t object
	time_t now_time = system_clock::to_time_t(now);

	// Output the current date
	char timeStr[26];
	ctime_s(timeStr, sizeof timeStr, &now_time);

	// Add 3 months to the current time point
	auto future_time = now + hours(24 * 30 * 3); // Assuming 30 days per month

	// Convert the future time point to a time_t object
	time_t future_time_t = system_clock::to_time_t(future_time);

	// Output the future date
	ctime_s(timeStr, sizeof timeStr, &future_time_t);
	cout << "expiration date: " << timeStr;

}
void OneYearEx() {
	// Get the current system time point
	auto now = system_clock::now();

	// Convert the current time point to a time_t object
	time_t now_time = system_clock::to_time_t(now);

	// Output the current date
	char timeStr[26];
	ctime_s(timeStr, sizeof timeStr, &now_time);

	// Add 1 year to the current time point
	auto future_time = now + hours(24 * 365); // Assuming 365 days per year

	// Convert the future time point to a time_t object
	time_t future_time_t = system_clock::to_time_t(future_time);

	// Output the future date
	ctime_s(timeStr, sizeof timeStr, &future_time_t);
	cout << "expiration date: " << timeStr;

}
void OneMonthEx() {
	// Get the current system time point
	auto now = system_clock::now();

	// Convert the current time point to a time_t object
	time_t now_time = system_clock::to_time_t(now);

	// Output the current date
	char timeStr[26];
	ctime_s(timeStr, sizeof timeStr, &now_time);

	// Add 30 days to the current time point to simulate adding a month
	auto future_time = now + hours(24 * 30);

	// Convert the future time point to a time_t object
	time_t future_time_t = system_clock::to_time_t(future_time);

	// Output the future date
	ctime_s(timeStr, sizeof timeStr, &future_time_t);
	cout << "expiration date: " << timeStr;

}

// =========================== End Diaa Part ====================================

// &&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&

// =========================== Start Fares Part =================================


void IncludeBlueStationsData() {
	fstream DataStorage;
	DataStorage.open(bathOfBlueLineStationsFile, ios::in);
	int i = 0, ID;

	if (!DataStorage.is_open()) {
		cout << "Error: Unable to open the file" << endl;
		return;
	}

	while (i < blueSize && DataStorage >> ID >> blueLineStations[i].name >> blueLineStations[i].line) {
		blueLineStations[i].id = ID;
		i++;
	}

	cout << "ID\t\tName\t\tLine\n";
	for (int j = 0; j < i; j++) {
		cout << blueLineStations[j].id << "\t\t";
		cout << blueLineStations[j].name << "\t\t";
		cout << blueLineStations[j].line << "\n";
	}

	DataStorage.close();
}

void IncludeRedStationsData() {
	fstream DataStorage;
	DataStorage.open(bathOfRedLineStationsFile, ios::in);
	int i = 0, ID;

	if (!DataStorage.is_open()) {
		cout << "Error: Unable to open the file" << endl;
		return;
	}

	while (i < redSize && DataStorage >> ID) {
		DataStorage.ignore(); // ����� ������� ��� ����� ���� ������
		getline(DataStorage, redLineStations[i].name, '\t'); // ����� ��� ������ ��� ������
		getline(DataStorage, redLineStations[i].line); // ����� �� ������
		redLineStations[i].id = ID;
		i++;
	}

	cout << "ID\t\tName\t\tLine\n";
	for (int j = 0; j < i; j++) {
		cout << redLineStations[j].id << "\t\t";
		cout << redLineStations[j].name << "\t\t";
		cout << redLineStations[j].line << "\n";
	}

	DataStorage.close();
}

// =========================== End Fares Part ===================================

// &&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&

// =========================== Start Mohammed Part ==============================
// =========================== End Mohammed Part ================================

// &&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&

// =========================== Start Mahmoud Part ===============================
int FindStation(metro_station LineStations[], string station_name, int no_of_stations) {
	int st_id = -1;
	for (int i = 0; i < no_of_stations; i++) {
		if (LineStations[i].name == station_name) {
			return LineStations[i].id;
		}
	}
	return st_id;
}

void addstation(string station_name)
{
	int ans;
	int st_id = max_id + 1;
	int is_in_Red_Line = -1;
	int is_in_Green_Line = -1;
	int is_in_Blue_Line = -1;

	is_in_Green_Line = FindStation(greenLineStations, station_name, greenLineStations_size);
	is_in_Red_Line = FindStation(redLineStations, station_name, redLineStations_size);
	is_in_Blue_Line = FindStation(blueLineStations, station_name, blueLineStations_size);
	cout << "in which line you want to add your station? " << endl;
	cout << "1- red\n2- green\n3-blue\n";
	cin >> ans;

	int i;
	if (ans == 1) {
		if (is_in_Red_Line > -1) {
			cout << "station " << station_name << " already exist on The Red Line with id " << is_in_Red_Line << endl;
		}
		else {
			if (is_in_Green_Line > -1) st_id = is_in_Green_Line;
			else if (is_in_Blue_Line > -1) st_id = is_in_Blue_Line;
			else max_id += 1;
			redLineStations[redLineStations_size].id = st_id;
			redLineStations[redLineStations_size].name = station_name;
			redLineStations_size++;
			//check

			cout << "Enter {1}to check:";
			cin >> checkEdit;
			if (x == 1)
			{
				for (i = 0; i < redLineStations_size; i++) {
					cout << redLineStations[i].id << "  " << redLineStations[i].name << " \n";
				}//end for
			}
			cout << "station " << station_name << " added to Red Line" << endl;
		}// end of else
	}// end of if
	else if (ans == 2) {
		if (is_in_Green_Line > -1) {
			cout << "station " << station_name << " already exist on The Green Line with id " << is_in_Green_Line << endl;
		}
		else {
			if (is_in_Red_Line > -1) st_id = is_in_Red_Line;
			else if (is_in_Blue_Line > -1) st_id = is_in_Blue_Line;
			else max_id += 1;
			greenLineStations[greenLineStations_size].id = st_id;
			greenLineStations[greenLineStations_size].name = station_name;
			greenLineStations_size++;

			cout << "Enter {1}to check:";
			cin >> checkEdit;
			if (x == 1) {

				for (i = 0; i < greenLineStations_size; i++) {
					cout << greenLineStations[i].id << "  " << greenLineStations[i].name << " \n";
				}//end for

			}
			cout << "station " << station_name << " added to Green Line" << endl;
		}// end of else
	}// end of if
	else if (ans == 3) {
		if (is_in_Blue_Line > -1) {
			cout << "station " << station_name << " already exist on The Green Line with id " << is_in_Blue_Line << endl;
		}
		else {
			if (is_in_Red_Line > -1) st_id = is_in_Red_Line;
			else if (is_in_Green_Line > -1) st_id = is_in_Green_Line;
			else max_id += 1;
			blueLineStations[blueLineStations_size].id = st_id;
			blueLineStations[blueLineStations_size].name = station_name;
			blueLineStations_size++;

			cout << "Enter {1}to check:";
			cin >> checkEdit;
			if (x == 1) {

				for (i = 0; i < blueLineStations_size; i++) {
					cout << blueLineStations[i].id << "  " << blueLineStations[i].name << " \n";
				}//end for

			}
			cout << "station " << station_name << " added to Blue Line" << endl;
		}// end of else
	}// end of if
	else {
		cout << "invalid number\n";
		addstation(station_name);
	}
}


// =========================== End Mahmoud Part =================================

// &&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&

// =============================== Main Function ============================================

int main() {
	bool x = 0;
	copyCustomerDataFromTheFile();
	IncludeBlueStationsData();
	IncludeRedStationsData();
	IncludeGreenStationsData();
	copyAdmenDataFromTheFile();


	//	theJourney();
	do {// frist menu (Custumer or Admin menu) user choice betwen be custumer or admin
		int choice;
		system("cls");
		cout << "\n########################################\n";
		cout << "          Customer or Admin Menu       \n";
		cout << "             * welcome *    \n";
		cout << "========================================\n\n";
		cout << " 1. Customer\n";
		cout << " 2. Admin\n";
		cout << " 0. Quit/Exit from program\n"; // end program
		cout << "\n========================================\n\n";
		cout << " Enter your choice: ";
		cin >> choice;
	

		if (choice == 1) {// for going Customer menu after login menu
			CoA = 1; //make CoA = 1 ,this varibel going to Lmenu and going to if staetment for going Cmenu if it =1 or Amenu if it = 2
	system("cls");
			Lmenu(numberOfCustomersWithinTheFile,1);
		}
		else if (choice == 2) {// for going Admin menu after login menu

			code();// frist check if user know the password
		}
		else if (choice == 0) { // if user want exit the program
			cout << "End The Program. Exiting...\n";
			system("cls");
			exit(0);
		}
		else {
			cout << "Invalid choice!\n\n";
			system("cls");
			// return CAmenu();
			x = 1;
		}

	} while (x == true);

	 saveCustomerData();
	// saveAdmenDataToFile();
	// saveGreenStationsData();
	// saveRedStationsData();
	// saveBlueStationsData();
//    delete []users;

	return 0;
}
