#include <iostream>
#include <string>
#include <ncurses.h>
//#include <conio.h> //uncomment this line

using namespace std;

void pressAnyKey(string message) {
	cout << endl << message << endl << endl;
	cout << "<Press any key to continue>";
	string test; cin >> test; cout << endl;//this is for testing since im using linux (this line should be deleted)
	//char c = getch(); //uncomment this line
}

//-------------------------------------------------
// This utility function reads an integer
// from the input stream. If the user
// enters something that is not a number,
// it detects this error condition, clear
// everything and returns -1. Otherwise,
// it returns the number entered by the user.
//-------------------------------------------------
int getOptionFromUser() {
	int inputValue;
	
	cin >> inputValue;
	if (cin.fail() == true) {
		cin.clear(); // clearing error flags
		//cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Flushing input stream
		return(-1);
	}
	else {
		return(inputValue);
	}
}

struct observations{
	int id;
	string state, county;
	int totalVote, demoVote, repuVote;
	double demoShare;
	bool empty = true;

	void print(){
		char printer[72];
		string ID = to_string(id);
		for(int i = 0; i < 72; i++){
			if(i>=0 && i < 5) {
				printer[i];
			} 
			else if(i >= 6 && i <= 11){
				if(i-6 + state.length)
					printer[i] = state[i];
				else 
					printer [i] = ' ';
			}
			else if(i == 5 || i == 12 || i == 27 || i ==  40 || i == 51 || i == 61){
				printer[i] = ' '; //WhiteSpace
			}
		}//UNDONE
		//cout << "----- ------ -------------- ------------ ---------- --------- ---------" << endl;

		cout << id << " " << state << " " << 
		county << " " << totalVote << " " << 
		demoVote << " " << repuVote <<  " " << demoShare << endl;
	}
};


observations getbyID(observations array[100], int ID){
	//Linear Search for the ID
	for(int i = 0; i<100; i++){
			if(array[i].empty == false && array[i].id == ID){
				return array[i]; //returns the found observation 
		}
	}
	observations notfound = {0,"","",0,0,0,true};
	return notfound; //returns an empty observation if not found
}
void getbyState(observations array[100], string state){
	//Linear Search for the state
	for(int i = 0; i<100; i++){
			if(!array[i].empty && array[i].state.compare(state)==0){
				array[i].print(); //it prints the results
		}
	}
}
observations getbyCounty(observations array[100], string county){
	//Linear Search for the state
	for(int i = 0; i<100; i++){
			if(array[i].empty == false && array[i].county.compare(county)==0){
				return array[i]; //returns the found observation 
		}
	}
	observations notfound = {0,"","",0,0,0,true};
	return notfound; //returns an empty observation if not found
}

void displayData(observations array[100]){
		cout << "ID    State  County         Total Votes  Dem Votes  Rep Votes Dem share" << endl;
		cout << "----- ------ -------------- ------------ ---------- --------- ---------" << endl;
		for(int i = 0; i<100; i++){
			if(array[i].empty == false){
				array[i].print();
			}
		}
		cout << "-----------------------------------------------------------------------" << endl;
		pressAnyKey("");
}
void displayObservation(observations array[100]){
	int ID;
	cout << "Enter the observation id: ";
	cin >> ID;
	cout << "-------------------------------------------------" << endl;
	observations found = getbyID(array, ID);
	if(!found.empty){
			cout << "ID           : " + found.id << endl;
			cout << "STATE        : " + found.state << endl;
			cout << "COUNTY       : " + found.county << endl;
			cout << "TOTAL V      : " + found.totalVote << endl;
			cout << "DEM VOTES    : " + found.demoVote << endl;
			cout << "REP VOTES    : " + found.repuVote << endl;
			cout << "DEM SHARE    : "; printf("%lf", found.demoShare); cout << endl;
			
	}
	else{
		cout << "Did not find any observation with that id!" << endl;
	}
}
observations displayAdd(observations array[100]){
	//this returns the observation to be added
	int id, totalVote, demoVote, repuVote;;
	string state;
	char county[40];
	double demoShare;

	cout << "Enter observation id  : ";
	cin >> id;
	cout << "Enter state           : ";
	cin >> state;
	cout << "Enter county          : ";
	cin.ignore(); //this is to avoid cin.getline() to read the printline
	cin.getline(county,40); //this will include whitespaces
	cout << "Enter total votes     : ";
	cin >> totalVote;
	cout << "Enter dem votes       : ";
	cin >> demoVote;
	cout << "Enter rep votes       : ";
	cin >> repuVote;
	cout << "Enter dem share       : ";
	cin >> demoShare;
	cout << "-------------------------------------------------" << endl;

	observations adder = {id, state, county, totalVote, demoVote, repuVote, demoShare, false};
	if(!getbyID(array, id).empty){
		observations notfound = {id,"","",0,0,0,true};
		return notfound; //returns an empty observation if there is an observation with that ID
	}
	return adder;
}
observations displayDelete(observations array[100]){
	int id;
	cout << "DELETING AN OBSERVATION";
	cout << "-------------------------------------------------" << endl;
	cout << "Enter observation id: ";
	cin >> id;
	cout << "-------------------------------------------------" << endl;
	return getbyID(array, id);
}
void displayState(observations array[100]){
	string state;
	cout << "Enter the observation state: ";
	cin >> state;
	cout << "-------------------------------------------------" << endl << endl;
	cout << "ID    State  County         Total Votes  Dem Votes  Rep Votes Dem share" << endl;
	cout << "----- ------ -------------- ------------ ---------- --------- ---------" << endl;
	getbyState(array, state);
}
void displayCounty(){

}
void loadFile(){

}
void displayHistrogram(){

}
void centralTendency(){

}
int main() {
	observations array[100];
	int size = 0; //this keep the number of Elements in the array
	int option;
	bool done = false;

	while(!done) {
		//system("cls");
		cout << "CoRe Data Analyzer APPLICATION " << endl;
		cout << "--------------------------" << endl;
		cout << "1. Display Data Frame " << endl;
		cout << "2. Display an observation" << endl;
		cout << "3. Add an observation" << endl;
		cout << "4. Delete an observation" << endl;
		cout << "5. Find observation by state " << endl;
    	cout << "6. Find observation by county" << endl;
		cout << "7. Save observation to file" << endl;
		cout << "8. Load observation from file" <<endl;
		cout << "9. Create Histogram" << endl;
		cout << "10. Calculate Measures of Central Tendency" << endl;
		cout << "11. Exit application" << endl;
		cout << "--------------------------" << endl;
		cout << "Enter option number: ";

		option = getOptionFromUser();
		
		switch(option) {
			case 1:
				displayData(array);
				break;
				

			case 2:
				cout << "DISPLAYING AN OBSERVATION" << endl;
				cout << "-------------------------------------------------" << endl;
				displayObservation(array);
				cout << "-------------------------------------------------";
				pressAnyKey("");
				break;

			case 3:
				
			cout << "ADDING AN OBSERVATION" << endl;
			cout << "-------------------------------------------------" << endl;
				//this means the array is full
				if(size >= 100){
					cout << "Your Data frame is full!";
				}
				//this means we can add to the array 
				else{
				observations adder = displayAdd(array);
					//this means the id already exist
					if(adder.empty){
					cout << "The observation " + adder.id;
					cout << " already exists!" << endl;
					}
					//we can add the observation
					else{
					array[size] = displayAdd(array);
					size++;
					cout << array[size-1].county + " was added successfully!" << endl;
					}
				}
				cout << "-------------------------------------------------";
				pressAnyKey("");
				break;

			case 4:
				int id;
				cout << "DELETING AN OBSERVATION" << endl;
				cout << "-------------------------------------------------" << endl;
				cout << "Enter observation id: ";
				cin >> id;
				cout << "-------------------------------------------------" << endl;
				//this means the ID was not found
				if(getbyID(array, id).empty){
					cout << "Did not find observation with that id!";
				}
				//delete the observation
				else{
					cout << "deleting" + getbyID(array, id).state + getbyID(array,id).county + "..."<< endl;
					//this will keep the observation in the array from index 0 to size-1
					bool realocate = false;
					for(int i = 0; i < 99; i++){
						if(array[i].id == id || (realocate && !array[i+1].empty)){
							array[i] = array[i+1];
							realocate = true;
						}
					}
					size --;
					cout << "Done!";

				}
				cout << "-------------------------------------------------";
				pressAnyKey("");
				break;

			case 5:
				
				pressAnyKey("");
				break;
			
			case 6:
				break;

			case 7:
				break;
			
			case 8:
				break;

			case 9:
				break;

			case 10:
				break;

			case 11:
				done = true;
				break;

			default:
				pressAnyKey("Invalid option!");
				break;
		}
	}

	return(0);
}