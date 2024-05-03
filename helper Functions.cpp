#include<iostream>
#include<sstream>
#include<string>
#include<fstream>

using namespace std;

#define bathOfCustmerDataFile "Data Storage\\Custmer Data.txt"
#define bathOfAdmenDataFile "Data Storage\\Admen Data.txt"
#define bathOfBlueLineStationsFile "Data Storage\\blue Line Stations.txt"
#define bathOfRedLineStationsFile "Data Storage\\Red Line Stations.txt"
#define bathOfGreenLineStationsFile "Data Storage\\Green Line Stations.txt"


 int NumberOfDataInTheArray = 0,chakIn,chakOut,
 numberOfUsersWithinTheFile = 0,
 numberOfAdmensWithinTheFile = 0,
  size = 100,ID,blueSize = 35,
  redSize = 18,greenSize = 23;
string inLine,outLine;
struct user {//????? ?????? ???????? 
	string type, password, name;
	int id, balans;

}*users = new user[size];
struct admen {//????? ?????? ???????? 
	string password, name;
	int id;

}*Admens = new admen[size];
// ============================= Diaa =======================================

struct metro_station{
	int id;
	string name;
	string line;
}* greenLineStations = new metro_station[greenSize],* blueLineStations = new metro_station[blueSize], * redLineStations = new metro_station[redSize];
string in, out;
metro_station* s = new metro_station[100];

// // Green Line Stations
// metro_station greenLineStations[] = {
// 	{1, "adly_mansor", "green"},
// 	{2, "Hikestep", "green"},
// 	{3, "Omar_ibn_Al-khattab", "green"},
// 	{4, "Qoba", "green"},
// 	{5, "Hisham_Barakat", "green"},
// 	{6, "El-Nozha", "green"},
// 	{7, "El-Shams_Club", "green"},
// 	{8, "Alf_Masken", "green"},
// 	{9, "Heliopolis", "green"},
// 	{10, "Haroun", "green"},
// 	{11, "Al_Ahram", "green"},
// 	{12, "Koleyet_El_Banat", "green"},
// 	{13, "Stadium", "green"},
// 	{14, "Fair_Zone", "green"},
// 	{15, "Abbassia", "green"},
// 	{16, "Abdou_Pasha", "green"},
// 	{17, "El_Geish", "green"},
// 	{18, "Bab_El_Shaaria", "green"},
// 	{19, "Attaba", "green"},		// Repeated station name red
// 	{20, "Nasser", "green"},		// Repeated station name blue
// 	{21, "Maspero", "green"},
// 	{22, "Safaa_Hegazy", "green"},
// 	{23, "Kit_Kat", "green"}
// };

// // Blue Line Stations
// metro_station blueLineStations[] = {
// 	{24, "New_El-Marg", "blue"},
// 	{25, "El-Marg", "blue"},
// 	{26, "Ezbet_El-Nakhl", "blue"},
// 	{27, "Ain_Shams", "blue"},
// 	{28, "El-Matareyya", "blue"},
// 	{29, "Helmiet_El-Zaitoun", "blue"},
// 	{30, "Hadayeq_El-Zaitoun", "blue"},
// 	{31, "Saray_El-Qobba", "blue"},
// 	{32, "Hammamat_El-Qobba", "blue"},
// 	{33, "Kobri_El-Qobba", "blue"},
// 	{34, "Manshiet_El-Sadr", "blue"},
// 	{35, "El-Demerdash", "blue"},
// 	{36, "Ghamra", "blue"},
// 	{37, "Al-Shohadaa", "blue"},  // Repeated station name red
// 	{38, "Orabi", "blue"},
// 	{20, "Nasser", "blue"},        // Repeated station name green
// 	{39, "Sadat", "blue"},         // Repeated station name red
// 	{40, "Saad_Zaghloul", "blue"},
// 	{41, "Sayyeda_Zeinab", "blue"},
// 	{42, "El-Malek_El-Saleh", "blue"},
// 	{43, "Mar_Girgis", "blue"},
// 	{44, "El-Zahraa", "blue"},
// 	{45, "Dar_El-Salam", "blue"},
// 	{46, "Hadayeq_El-Maadi", "blue"},
// 	{47, "Maadi", "blue"},
// 	{48, "Sakanat_El-Maadi", "blue"},
// 	{49, "Tora_El-Balad", "blue"},
// 	{50, "Kozzika", "blue"},
// 	{51, "Tora_El-Asmant", "blue"},
// 	{52, "El-Maasara", "blue"},
// 	{53, "Hadayeq_Helwan", "blue"},
// 	{54, "Wadi_Hof", "blue"},
// 	{55, "Helwan_University", "blue"},
// 	{56, "Ain_Helwan", "blue"},
// 	{57, "Helwan", "blue"}
// };

// Red Line Stations
// metro_station redLineStations[] = {
// 	{58, "Shubra", "red"},
// 	{59, "Koleyet El Zeraat", "red"},
// 	{60, "El Mazallat", "red"},
// 	{61, "El Khalafawy", "red"},
// 	{62, "St. Teresa", "red"},
// 	{63, "Rod El Farag", "red"},
// 	{64, "Massara", "red"},
// 	{37, "Al Shohadaa", "red"},  // Repeated station name blue
// 	{19, "Attaba", "red"},		// Repeated station name green
// 	{65, "M. Naguib", "red"},
// 	{39, "Sadat", "red"},       // Repeated station name blue
// 	{66, "Opera", "red"},
// 	{67, "Dokki", "red"},
// 	{68, "El Boghdady", "red"},
// 	{69, "Faysal", "red"},
// 	{70, "Giza", "red"},
// 	{71, "Om El Masryeen", "red"},
// 	{72, "Sakyat Makky", "red"}
// };


void copyDataFromTheFile (){
	fstream DataStorage;
	DataStorage.open(bathOfCustmerDataFile,ios::in);
	int i = 0, ID;
	// user *users = new user[size];
	
	if(!DataStorage.is_open()){
		cout << "you have an error";
	}else{	
		// cout <<"begin... \n";
		while(i < size && !DataStorage.eof()){
			++NumberOfDataInTheArray;

			string line;
			DataStorage>> ID;
			if(ID > 0 && ID != users[i - 1].id){
			users[i].id = ID;
			DataStorage>> users[i].name;
			DataStorage>> users[i].password;
			DataStorage>> users[i].balans;
			getline(DataStorage , line);
			// cout << "User1.["<<++i<<"] Done\n";
			i++;
			}else{
				getline(DataStorage , line);
				continue;	
			}
			
		}
	 	i = 0;
	 	cout <<"ID		"<< "Name		" << "Password	" << "Balans\n";
	 	for(int i = 0;i < NumberOfDataInTheArray;i++){
			cout << users[i].id <<"	";
			cout << users[i].name <<"		";
			cout << users[i].password <<"		";
			 cout << users[i].balans <<"\n";
			
		}
		
		DataStorage.close();
	}
	
}
void copyAdmenDataFromTheFile (){
	fstream DataStorage;
	DataStorage.open(bathOfAdmenDataFile,ios::in);
	int i = 0, ID;
	// user *users = new user[size];
	
	if(!DataStorage.is_open()){
		cout << "you have an error";
	}else{	
		// cout <<"begin... \n";
		while(i < size && !DataStorage.eof()){
			++numberOfAdmensWithinTheFile;

			string line;
			DataStorage>> ID;
			if(ID > 0 && ID != Admens[i - 1].id){
			Admens[i].id = ID;
			DataStorage>> Admens[i].name;
			DataStorage>> Admens[i].password;
			// DataStorage>> users[i].balans;
			getline(DataStorage , line);
			cout << "User1.["<<i+1<<"] Done\n";
			i++;
			}else{
				getline(DataStorage , line);
				continue;	
			}
			
		}
	 	i = 0;
	 	cout <<"ID		"<< "Name		" << "Password\n";
	 	for(int i = 0;i < numberOfAdmensWithinTheFile;i++){
			cout << Admens[i].id <<"	";
			cout << Admens[i].name <<"		";
			cout << Admens[i].password <<"		";
			//  cout << users[i].balans <<"\n";
			
		}
		
		DataStorage.close();
	}
	
}

void saveadmenDataToFile(){
	fstream DataStorage;
	DataStorage.open(bathOfAdmenDataFile,ios::out);
	int i = 0;
	
	
	if(!DataStorage.is_open()){
		cout << "you have an error";
	}else{	

	 	for(int i = 0;i < numberOfAdmensWithinTheFile;i++){
	 		if(Admens[i].id > 0){
				DataStorage << Admens[i].id <<"	";
				DataStorage << Admens[i].name <<"		";
				DataStorage << Admens[i].password <<"\n";
			}else
				continue;
		}
		cout << "The new data has been saved successfully\n";
		DataStorage.close();
	}
}
void saveDataToFile(){
	fstream DataStorage;
	DataStorage.open(bathOfCustmerDataFile,ios::out);
	int i = 0;
	
	
	if(!DataStorage.is_open()){
		cout << "you have an error";
	}else{	

	 	for(int i = 0;i < NumberOfDataInTheArray;i++){
	 		if(users[i].id > 0){
				DataStorage << users[i].id <<"	";
				DataStorage << users[i].name <<"		";
				DataStorage << users[i].password <<"\n";
			}else
				continue;
		}
		cout << "The new data has been saved successfully\n";
		DataStorage.close();
	}
}

void saveGreenStationsDataToFile(){
	fstream DataStorage;
	DataStorage.open(bathOfGreenLineStationsFile,ios::out);
	int i = 0;
	
	if(!DataStorage.is_open()){
		cout << "you have an error";
	}else{	

				// cout << greenLineStations[0].id <<"	";
				// cout << greenLineStations[0].name <<"		";
				// cout << greenLineStations[0].line <<"\n";
	 	 for(int i = 0;i < greenSize;i++){
	 	 	if(greenLineStations[i].id > 0){
		 		DataStorage << greenLineStations[i].id <<"	";
		 		DataStorage << greenLineStations[i].name <<"		";
		 		DataStorage << greenLineStations[i].line <<"\n";
		 		 cout << "Station.["<<i+1<<"] Done\n";
		 	}else
		 		continue;
		 }
		cout << "The new data has been saved successfully\n";
		DataStorage.close();
	}
}
void saveRedStationsDataToFile(){
	fstream DataStorage;
	DataStorage.open(bathOfRedLineStationsFile,ios::out);
	int i = 0;
	
	if(!DataStorage.is_open()){
		cout << "you have an error";
	}else{	

				// cout << greenLineStations[0].id <<"	";
				// cout << greenLineStations[0].name <<"		";
				// cout << greenLineStations[0].line <<"\n";
	 	 for(int i = 0;i < redSize;i++){
	 	 	if(redLineStations[i].id > 0){
		 		DataStorage << redLineStations[i].id <<"	";
		 		DataStorage << redLineStations[i].name <<"		";
		 		DataStorage << redLineStations[i].line <<"\n";
		 		 cout << "Station.["<<i+1<<"] Done\n";
		 	}else
		 		continue;
		 }
		cout << "The new data has been saved successfully\n";
		DataStorage.close();
	}
}
void saveBlueStationsDataToFile(){
	fstream DataStorage;
	DataStorage.open(bathOfBlueLineStationsFile,ios::out);
	int i = 0;
	
	if(!DataStorage.is_open()){
		cout << "you have an error";
	}else{	

				// cout << greenLineStations[0].id <<"	";
				// cout << greenLineStations[0].name <<"		";
				// cout << greenLineStations[0].line <<"\n";
	 	 for(int i = 0;i < blueSize;i++){
	 	 	if(blueLineStations[i].id > 0){
		 		DataStorage << blueLineStations[i].id <<"	";
		 		DataStorage << blueLineStations[i].name <<"		";
		 		DataStorage << blueLineStations[i].line <<"\n";
		 		 cout << "Station.["<<i+1<<"] Done\n";
		 	}else
		 		continue;
		 }
		cout << "The new data has been saved successfully\n";
		DataStorage.close();
	}
}

void EidetUseraccounts(){
   int ans;
	cout <<"Enter the ID of the person you want to edit: ";
 	cin >>ID;
	for(int i = 0;i < NumberOfDataInTheArray;i++){
		if(ID == users[i].id){
			cout <<"What do you want to modify in \"" << users[i].name << "\" data?:-\n for \"ID\" Enter 	-->		1\nfor \"password\" Enter 	-->		2\nfor \"name\" Enter 	-->		3\n";
			cin >> ans;
			if(ans == 1){
				cout <<"ID		"<< "Name		" << "Password\n";
				cout << users[i].id <<"	";
				cout << users[i].name <<"		";
				cout << users[i].password <<"\n";
				cout <<"Enter a new \"ID\" for "<< users[i].name <<" :- ";
				cin >> users[i].id;
			}
			else if(ans == 2){
				cout <<"ID		"<< "Name		" << "Password\n";
				cout << users[i].id <<"	";
				cout << users[i].name <<"		";
				cout << users[i].password <<"\n";
				cout <<"Enter a new \"password\" for "<< users[i].name <<":- ";
				cin >> users[i].password;
			}
			else if(ans == 3){
				cout <<"ID		"<< "Name		" << "Password\n";
				cout << users[i].id <<"	";
				cout << users[i].name <<"		";
				cout << users[i].password <<"\n";
				cout <<"Enter a new \"Name\" for "<< users[i].name <<":- ";
				cin >> users[i].name;
			}else{
				cout <<"invalide value\n";
				--i;
			}
		}
	}
}

void chakOutStation(){
	int I;
	cout <<"There are three lines:-\n";
	cout <<"1. from \"New El-Marg\" to \"Helwan\"\n";
	cout <<"2. from \"Shubra\" to \"Sakyat Makky\"\n";
	cout <<"3. from \"adly_mansor\" to \"Kit_Kat\"\n";
	cout <<"--------------------------------------------------\n";
	cout <<"Which line do you want to go to? 1 Or 2 Or 3:- ";
	cin >> I;
	if (I == 1){
		outLine = "blue";
		cout <<"ID		"<< "Name\n";
		for(int i = 0;i < blueSize;i++){
			cout << blueLineStations[i].id <<"	";
			cout << blueLineStations[i].name <<"\n";
		}
		cout <<"Enter \"0\" to go back \nEnter the \"ID\" of The station you want to go to :";
		cin >> chakOut;
		if(chakOut == 0)
			chakOutStation();
		else{
			for(int i = 0;i < blueSize;i++){
				if(chakOut == blueLineStations[i].id )
					chakOutIndex = i;
			}
		}
			// chakOutStation();
	}else if(I == 2){
		outLine = "red";
		cout <<"ID		"<< "Name\n";
		for(int i = 0;i < redSize;i++){
			cout << redLineStations[i].id <<"	";
			cout << redLineStations[i].name <<"\n";
		}
		cout <<"Enter \"0\" to go back \nEnter the \"ID\" of The station you want to go to :";
		cin >> chakOut;
		if(chakOut == 0)
			chakOutStation();
		else{
			for(int i = 0;i < redSize;i++){
				if(chakOut == redLineStations[i].id )
					chakOutIndex = i;
			}
		}
			// chakOutStation();
	}else if(I == 3){
		outLine = "green";
		cout <<"ID		"<< "Name\n";
		for(int i = 0;i < greenSize;i++){
			cout << greenLineStations[i].id <<"	";
			cout << greenLineStations[i].name <<"\n";
			
		}
		cout <<"Enter \"0\" to go back \nEnter the \"ID\" of The station you want to go to :";
		cin >> chakOut;
		if(chakOut == 0)
			chakOutStation();
		else{
			for(int i = 0;i < greenSize;i++){
				if(chakOut == greenLineStations[i].id )
					chakOutIndex = i;
			}
		}
			// chakOutStation();
	}else{
		cout <<"invalide value\nPlease choose from the numbers specified for you\n";
		theJourney();
	}
}

void IncludeGreenStationsData (){
	fstream DataStorage;
	DataStorage.open(bathOfGreenLineStationsFile,ios::in);
	int i = 0, ID;
	// user *users = new user[size];
	
	if(!DataStorage.is_open()){
		cout << "you have an error";
	}else{	
		// cout <<"begin... \n";
		while(i < greenSize && !DataStorage.eof()){

			DataStorage>> ID;
			if(ID > 0 && ID != greenLineStations[i - 1].id){
			greenLineStations[i].id = ID;
			DataStorage>> greenLineStations[i].name;
			DataStorage>> greenLineStations[i].line;
			// cout << "User1.["<<++i<<"] Done\n";
			i++;
			}else{
				continue;	
			}
			
		}
	 	i = 0;
	 	cout <<"ID		"<< "Name		" << "Line\n";
	 	for(int i ;i < greenSize;i++){
			cout << greenLineStations[i].id <<"	";
			cout << greenLineStations[i].name <<"		";
			cout << greenLineStations[i].line <<"\n";
			
		}
		
		DataStorage.close();
	}
}
void IncludeBlueStationsData (){
	fstream DataStorage;
	DataStorage.open(bathOfBlueLineStationsFile,ios::in);
	int i = 0, ID;
	// user *users = new user[size];
	
	if(!DataStorage.is_open()){
		cout << "you have an error";
	}else{	
		 cout <<"begin1... \n";
		while(i <= blueLineStations[blueSize-1].id && !DataStorage.eof()){
			

			DataStorage>> ID;
			if (i == 0){
				blueLineStations[i].id = ID;
				DataStorage>> blueLineStations[i].name;
				DataStorage>> blueLineStations[i].line;
				// cout << "User1.["<<++i<<"] Done\n";
				i++;	
			}
			if((i > 0) &&(ID > 0 )&& (ID != blueLineStations[i - 1].id)){
				blueLineStations[i].id = ID;
				DataStorage>> blueLineStations[i].name;
				DataStorage>> blueLineStations[i].line;
				// cout << "User1.["<<++i<<"] Done\n";
				i++;
			}else{
				continue;	
			}
			
		}
	 	i = 0;
	 	cout <<"ID		"<< "Name		" << "Line\n";
	 	for(int i ;i < blueSize;i++){
			cout << blueLineStations[i].id <<"	";
			cout << blueLineStations[i].name <<"		";
			cout << blueLineStations[i].line <<"\n";
			
		}
		
		DataStorage.close();
	}
}
void IncludeRedStationsData (){
	fstream DataStorage;
	DataStorage.open(bathOfRedLineStationsFile,ios::in);
	int i = 0, ID;
	// user *users = new user[size];
	
	if(!DataStorage.is_open()){
		cout << "you have an error";
	}else{	
		while(i < sizeof(redLineStations) && !DataStorage.eof()){
			// cout <<"begin33... \n";

			DataStorage>> ID;
			if (i == 0){
				redLineStations[i].id = ID;
				DataStorage>> redLineStations[i].name;
				DataStorage>> redLineStations[i].line;
				 cout << "User1.["<<i+1<<"] Done\n";
				i++;
			}else if(ID > 0 && ID != redLineStations[i - 1].id){
				cout << ID <<"===========\n";
				redLineStations[i].id = ID;
				DataStorage>> redLineStations[i].name;
				DataStorage>> redLineStations[i].line;
				 cout << "User1.["<<i+1<<"] Done\n";
				i++;
			}else{
				continue;	
			}
			
		}
	 	i = 0;
	 	cout <<"ID		"<< "Name		" << "Line\n";
	 	for(i ;i < redSize;i++){
			cout << redLineStations[i].id <<"	";
			cout << redLineStations[i].name <<"		";
			cout << redLineStations[i].line <<"\n";
			
		}
		
		DataStorage.close();
	}
}
void theJourney(){
	int I;
	cout <<"There are three lines:-\n";
	cout <<"1. from \"New El-Marg\" to \"Helwan\"\n";
	cout <<"2. from \"Shubra\" to \"Sakyat Makky\"\n";
	cout <<"3. from \"adly_mansor\" to \"Kit_Kat\"\n";
	cout <<"--------------------------------------------------\n";
	cout <<"Which line are you on now? 1 Or 2 Or 3:- ";
	cin >> I;
	if (I == 1){
		inLine = "blue";
		cout <<"ID		"<< "Name\n";
		for(int i = 0;i < blueSize;i++){
			cout << blueLineStations[i].id <<"	";
			cout << blueLineStations[i].name <<"\n";
		}
		cout <<"Enter \"0\" to go back \nEnter the \"ID\" of the station you are on now :";
		cin >> chakIn;
		if(chakIn == 0)
			theJourney();
		else{
			for(int i = 0;i < blueSize;i++){
				if(chakIn == blueLineStations[i].id )
					chakInIndex = i;
			}
			chakOutStation();
		}
	}else if(I == 2){
		inLine = "red";
		cout <<"ID		"<< "Name\n";
		for(int i = 0;i < redSize;i++){
			cout << redLineStations[i].id <<"	";
			cout << redLineStations[i].name <<"\n";
		}
		cout <<"Enter \"0\" to go back \nEnter the \"ID\" of the station you are on now :";
		cin >> chakIn;
		if(chakIn == 0)
			theJourney();
		else{
			for(int i = 0;i < redSize;i++){
				if(chakIn == blueLineStations[i].id )
					chakInIndex = i;
			}
			chakOutStation();
		}
	}else if(I == 3){
		inLine = "green";
		cout <<"ID		"<< "Name\n";
		for(int i = 0;i < greenSize;i++){
			cout << greenLineStations[i].id <<"	";
			cout << greenLineStations[i].name <<"\n";
			
		}
		cout <<"Enter \"0\" to go back \nEnter the \"ID\" of the station you are on now :";
		cin >> chakIn;
		if(chakIn == 0)
			theJourney();
		else{
			for(int i = 0;i < greenSize;i++){
				if(chakIn == greenLineStations[i].id )
					chakInIndex = i;
			}
			chakOutStation();
		}
	}else{
		cout <<"invalide value\nPlease choose from the numbers specified for you\n";
		theJourney();
	}
}

void chakOutStation(){
	int I;
	cout <<"There are three lines:-\n";
	cout <<"1. from \"New El-Marg\" to \"Helwan\"\n";
	cout <<"2. from \"Shubra\" to \"Sakyat Makky\"\n";
	cout <<"3. from \"adly_mansor\" to \"Kit_Kat\"\n";
	cout <<"--------------------------------------------------\n"
	cout "Which line do you want to go to? 1 Or 2 Or 3";
	cin >> I;
	if (I == 1){
		cout <<"ID		"<< "Name\n";
		for(int i = 0;i < ;i++){
			cout << blueLineStations[i].id <<"	";
			cout << blueLineStations[i].name <<"\n";
		}
		cout <<"Enter \"0\" to go back \nEnter the \"ID\" of The station you want to go to :";
		cin >> chakOut;
		if(chakOut == 0)
			chakOutStation();
		else
			calcStations(chakInIndex,chakOutIndex)
			// chakOutStation();
	}else if(I == 2){
		cout <<"ID		"<< "Name\n";
		for(int i = 0;i < ;i++){
			cout << redLineStations[i].id <<"	";
			cout << redLineStations[i].name <<"\n";
		}
		cout <<"Enter \"0\" to go back \nEnter the \"ID\" of The station you want to go to :";
		cin >> chakOut;
		if(chakOut == 0)
			chakOutStation();
		else
			// chakOutStation();
	}else if(I == 3){
		cout <<"ID		"<< "Name\n";
		for(int i = 0;i < ;i++){
			cout << greenLineStations[i].id <<"	";
			cout << greenLineStations[i].name <<"\n";
			
		}
		cout <<"Enter \"0\" to go back \nEnter the \"ID\" of The station you want to go to :";
		cin >> chakOut;
		if(chakIn == 0)
			chakOutStation();
		else
			// chakOutStation();
	}else{
		cout "invalide value\nPlease choose from the numbers specified for you\n";
		theJourney();
	}
}

void calcStations(int In,int Out){
	int stations, tmp = 0;
	if(inLine == "blue" && outLine != "blue"){
		stations = 0;
		if(outLine == "red"){
			if(chakIn < 37){
				for(i = In; i < 15; i++){
					
					if(blueLineStations[i].id == 37){
						if(chakOut < 64){
							for(int j = 6; j >= 0; j--){
								
								if(redLineStations[j].id == chakOut ){
									stations += tmp;
									break;
								}else{
									tmp ++;
								}
							}
						}
						break;
					}else{
						stations ++;
					}
						
				}
			}else if(chakIn > 39){
				for(i = In; i > 17; i--){
					
					if(blueLineStations[i].id == 39){
						if(chakOut > 66){
							for(int j = 12; j < 18; j++){
								
								if(redLineStations[j].id == chakOut ){
									stations += tmp;
									break;
								}else{
									tmp ++;
								}
							}
						}
						break;
					}else{
						stations ++;
					}
				}
			}else{
				stations += 2;
			}
			// =========================================//
			if(stations > 0 && stations <= 9){
				if(users[customerIndex].balance >= 6){
					users[customerIndex].balance -= 6;
				}
			}else if(stations > 9 && stations <= 16){
				if(users[customerIndex].balance >= 8){
					users[customerIndex].balance -= 8;
				}
			}else if(stations > 16 && stations <= 23){
				if(users[customerIndex].balance >= 12){
					users[customerIndex].balance -= 12;
				}
			}else{
				if(users[customerIndex].balance >= 15){
					users[customerIndex].balance -= 15;
				}
			}
		}else{
			if(chakIn < 38){
				for(i = In; i <= 16; i++){
					
					if(blueLineStations[i].id == 20){
						if(chakOut < 19){
							for(int j = 17; j >= 0; j--){
								
								if(greenLineStations[j].id == chakOut ){
									stations += tmp;
									break;
								}else{
									tmp ++;
								}
							}
						}
						break;
					}else{
						stations ++;
					}
						
				}
			}else{
				for(i = In; i >= 15; i--){
					
					if(blueLineStations[i].id == 20){
						if(chakOut >= 19){
							for(int j = 19; j < 23; j++){
								
								if(greenLineStations[j].id == chakOut ){
									stations += tmp;
									break;
								}else{
									tmp ++;
								}
							}
						}
						break;
					}else{
						stations ++;
					}
				}
			}

			// ==========================================
			if(stations > 0 && stations <= 9){
				if(users[customerIndex].balance >= 6){
					users[customerIndex].balance -= 6;
				}
			}else if(stations > 9 && stations <= 16){
				if(users[customerIndex].balance >= 8){
					users[customerIndex].balance -= 8;
				}
			}else if(stations > 16 && stations <= 23){
				if(users[customerIndex].balance >= 12){
					users[customerIndex].balance -= 12;
				}
			}else{
				if(users[customerIndex].balance >= 15){
					users[customerIndex].balance -= 15;
				}
			}
		}
	}else if(inLine == "red" && outLine != "red"){
		if(outLine =="green"){
			if(chakIn < 64){
				for(int i = In; i < 9; i++){
					
					if(redLineStations[i].id == 19){
						if(chakOut >= 20){
							for(int j = 20; j <= 23; j++){
								
								if(greenLineStations[j].id == chakOut ){
									stations += tmp;
									break;
								}else{
									tmp ++;
								}
							}
						}
						break;
					}else{
						stations ++;
					}
						
				}
			}else{
				// for(int i = 9)
			}
		}else{

		}
		// =========================================//
		if(stations > 0 && stations <= 9){
			if(users[customerIndex].balance >= 6){
				users[customerIndex].balance -= 6;
			}
		}else if(stations > 9 && stations <= 16){
			if(users[customerIndex].balance >= 8){
				users[customerIndex].balance -= 8;
			}
		}else if(stations > 16 && stations <= 23){
			if(users[customerIndex].balance >= 12){
				users[customerIndex].balance -= 12;
			}
		}else{
			if(users[customerIndex].balance >= 15){
				users[customerIndex].balance -= 15;
			}
		}
	}else if(inLine == "green" && outLine != "green"){
		if(outLine == "red"){

		}else{

		}
		// =========================================//
		if(stations > 0 && stations <= 9){
			if(users[customerIndex].balance >= 6){
				users[customerIndex].balance -= 6;
			}
		}else if(stations > 9 && stations <= 16){
			if(users[customerIndex].balance >= 8){
				users[customerIndex].balance -= 8;
			}
		}else if(stations > 16 && stations <= 23){
			if(users[customerIndex].balance >= 12){
				users[customerIndex].balance -= 12;
			}
		}else{
			if(users[customerIndex].balance >= 15){
				users[customerIndex].balance -= 15;
			}
		}
	}else{
		if(In > Out){
			
			stations = (In - Out);
			if(stations > 0 && stations <= 9){
				if(users[customerIndex].balance >= 6){
					users[customerIndex].balance -= 6;
				}
			}else if(stations > 9 && stations <= 16){
				if(users[customerIndex].balance >= 8){
					users[customerIndex].balance -= 8;
				}
			}else if(stations > 16 && stations <= 23){
				if(users[customerIndex].balance >= 12){
					users[customerIndex].balance -= 12;
				}
			}else{
				if(users[customerIndex].balance >= 15){
					users[customerIndex].balance -= 15;
				}
			}
		}else{
			
			stations = (Out - In);
			if(stations > 0 && stations <= 9){
				if(users[customerIndex].balance >= 6){
					users[customerIndex].balance -= 6;
				}
			}else if(stations > 9 && stations <= 16){
				if(users[customerIndex].balance >= 8){
					users[customerIndex].balance -= 8;
				}
			}else if(stations > 16 && stations <= 23){
				if(users[customerIndex].balance >= 12){
					users[customerIndex].balance -= 12;
				}
			}else{
				if(users[customerIndex].balance >= 15){
					users[customerIndex].balance -= 15;
				}
			}
		}
	
	}
}

// ============================== Muasab ================================================

// #include <iostream>
// #include <fstream>// read files
// #include <string>
// #include <cstdio> // For rename function
// using namespace std;

// int CoA = 0; // 1 for Customer, 2 for Admin
// string username, password, codeA, codeB, code1;
//    // all function
// int CAmenu(); // frist menu (Custumer or Admin) user choice betwen be custumer or admin
// int Lmenu();// secon menu (loing or register) user choice betwen be loing or register
// void Cmenu();// custumer menu for custumer functions
// void Amenu();// admin menu for admin functions
// bool login();// login function (check if user registered)
// void registerUser(); // register function (make new file for user )
// void code();// password for check if user is Admin named code
// void ccode();// (change code function) by Admin

// // int main() {
// //     CAmenu();
// //     return 0;
// // }

// int CAmenu() {  // frist menu (Custumer or Admin menu) user choice betwen be custumer or admin
//     string choice;
//     cout << "\n########################################\n";
//     cout << "          Customer or Admin Menu       \n";
//     cout << "             * welcome *    \n";
//     cout << "========================================\n\n";
//     cout << " 1. Customer\n"; 
//     cout << " 2. Admin\n";    
//     cout << " 0. Quit/Exit from program\n"; // end program
//     cout << "\n========================================\n\n";
//     cout << " Enter your choice: ";
//     cin >> choice;

//     if (choice == "1") {// for going Customer menu after login menu
//         CoA = 1; //make CoA = 1 ,this varibel going to Lmenu and going to if staetment for going Cmenu if it =1 or Amenu if it = 2
//         Lmenu(); 
//     }
//     else if (choice == "2") {// for going Admin menu after login menu
//         code();// frist check if user know the password
//     }
//     else if (choice == "0") { // if user want exit the program
//         cout << "End The Program. Exiting...\n";
//         exit(0);
//     }
//     else {
//         cout << "Invalid choice!\n\n";
//         return CAmenu();
//     }

//     return 0;
// }

// int Lmenu() {// secon menu (loing or register) user choice betwen be loing or register
//     string choice;
//     cout << "\n@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n";
//     cout << "                Login Menu       \n";
//     cout << "             * welcome *    \n";
//     cout << "========================================\n\n";
//     cout << " 1. Login\n";    // login func
//     cout << " 2. Register\n"; // register func
//     cout << "\n0. GO back to C.A menu\n"; // end program
//     cout << "\n========================================\n\n";
//     cout << " Enter your choice: ";
//     cin >> choice;

//     if (choice == "1") {// if user choice login, going login function
//         login();
//     }
//     else if (choice == "2") {// if user choice  register , going  register function
//         registerUser();
//     }
//     else if (choice == "0") {// if user choice  going back to Customer or Admin menu , going U.A menu 
//         cout << " don !...\n";
//         CAmenu();
//     }
//     else {
//         cout << "Invalid choice!\n\n";
//         return Lmenu();
//     }

//     return 0;
// }

// void Cmenu() {// custumer menu for custumer functions
//     string choice;
//     cout << "\n&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&\n";
//     cout << "                  main menu\n";
//     cout << "           * welcome " << username << " * " << endl;
//     cout << "========================================\n";
//     cout << "             What Well We Do \n\n";
//     cout << " 1. anything\n";
//     cout << " 2. anything\n";
//     cout << " \n0. GO back to login menu.....\n";
//     cout << "\n========================================\n\n";
//     cout << " Enter your choice: ";
//     cin >> choice;
//     if (choice == "0") {// if user choice  going back to login menu , going login menu
//         cout << "End The Program. Exiting...\n";
//         Lmenu();
//     } // add new function for user menu......................................................................
//     else {
//         cout << "Invalid choice!\n\n";
//         Cmenu();
//     }
// }

// void Amenu() {// admin menu for admin functions
//     string choice;
//     cout << "\n%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%\n";
//     cout << "                  Admin menu\n";
//     cout << "           * welcome " << username << " * " << endl;
//     cout << "========================================\n";
//     cout << "             What Well We Do \n\n";
//     cout << " 1. change password( code )\n";
//     cout << " 2. anything\n";
//     cout << " \n0. GO back to login menu.....\n";
//     cout << "\n========================================\n\n";
//     cout << " Enter your choice: ";
//     cin >> choice;
//     if (choice == "0") {// if user choice  going back to login menu , going login menu
//         cout << "End The Program. Exiting...\n";
//         Lmenu();
//     }
//     else if (choice == "1") {// for change password ( code ) ,going ccode fun  (change code function)
//         ccode();
//     } // add new function for user menu......................................................................
//     else {
//         cout << "Invalid choice!\n\n";
//         Amenu();
//     }
// }

// bool login() {// login function (check if user registered)
//     string un, pw;// for comparison betweem un & username and pw & password
//     cout << "\nEnter The Username: ";
//     cin >> username;
//     cout << "Enter The Password: ";
//     cin >> password;

//     ifstream read(username + ".tlxt");// read username file
//     if (!read.is_open()) {// user name wrong or dose not exist
//         cout << "Username does not exist!" << endl;
//         Lmenu();
//     }

//     getline(read, un);// read frist line and name it un
//     getline(read, pw);//read second line and name it pw

//     if (un == username && pw == password) {// if user login successfuly
//         cout << "Login successful!" << endl;
//         if (CoA == 1) // going Customer menu if user choice it
//             Cmenu();
//         else if (CoA == 2) // going Admin menu if user choice it
//             Amenu();
//         return true;
//     }
//     else if (un == username && pw != password) {// username correct but password wrong
//         cout << "Invalid password !" << endl;
//         Lmenu();
//     }
//     else {
//         cout << "Invalid username or password!" << endl;
//         Lmenu();
//     }
// }

// void registerUser() { // register function (make new file for user)
//     string un, pw;// for comparison betweem un & username and pw & password
//     cout << "\nSelect a Username: ";
//     cin >> username;
//     cout << "Select a Password: ";
//     cin >> password;

//     ifstream read(username + ".txt");// read file for check username exsit
//     getline(read, un);
//     getline(read, pw);

//     if (un == username) {// if user exsit before user can't add same name user name
//         cout << "Username was Registered! \n";
//         Lmenu();
//     }
//     else {
//         ofstream file;// creat new file (account)
//         file.open(username + ".txt");
//         if (!file.is_open()) {
//             cout << "Error creating user file!" << endl;
//             Lmenu();
//         }
//         file << username << endl << password;// write username in frist line and password in scond line
//         file.close();
//         cout << "...Done!\n";

//         if (CoA == 1)// going Customer menu if user choice it
//             Cmenu();
//         else if (CoA == 2) // going Admin menu if user choice it
//             Amenu();
//     }
// }

// void code() {// password for check if user is Admin named code
//     string name;//to read name code file
//     cout << "\nEnter the code: ";
//     cin >> code1;//enter password

//     ifstream read("admin.txt");// read code file

//     if (!read.is_open()) {
//         cout << "Code does not exist!" << endl;
//         CAmenu();
//     }
//     getline(read, name);//read frist line
//     getline(read, codeA);// read scond line
 
//     if (code1 == codeA) {//check the password add by user and the orginel password
//         CoA = 2;// if the password correct make CoA = 2 <= (for Admen menu)
//         Lmenu();//frist go login menu to add user account
//     }
//     else
//         cout << "Wrong code\n";//if password wrong go back
//     CAmenu();
// }

// void ccode() {// (change code function) by Admin
//     string adminUsername = "admin"; // Assuming the admin username is fixed as "admin"
//     string oldPassword, newPassword;

//     cout << "Enter the old password (old code): ";
//     cin >> oldPassword;

//     if (oldPassword != codeA) {// Check if the entered password matches the admin's current password
//         cout << "Incorrect password!" << endl;// if password add wrong go back to Amenu
//         Amenu();
//     }

//     cout << "Enter the new password (new code): ";// if password crrect add the new password
//     cin >> newPassword;

//     codeA = newPassword;   // Update the admin's password

//     ofstream outFile("admin.txt");// Write the new password to the admin's password file
//     if (!outFile.is_open()) {
//         cout << "Error: Unable to open password file for writing!" << endl;
//         Amenu();
//     }
//     outFile << adminUsername << endl << codeA;
//     outFile.close();

//     cout << "Password changed successfully!" << endl;
// }


int main(){
//	 IncludeGreenStationsData ();
	 IncludeRedStationsData ();
//	IncludeBlueStationsData ();
	// saveGreenStationsDataToFile();
	// saveRedStationsDataToFile();
	// saveBlueStationsDataToFile();
//	 copyDataFromTheFile();
	// EidetUseraccounts();
	// deleteUseraccounts();
	// saveDataToFile();
	return 0;
}
