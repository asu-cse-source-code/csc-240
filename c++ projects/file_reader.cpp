/*********************************************************
Austin Spencer
PROGRAM 12 
CSC 240
This program will read and display text from a file
I tried using the jetengines example as a skeleton for this project
However, my compiler wasn't liking data[].teamName and wanted me
to use data[]->teamName
I dont understand why that is.
Also, I kept getting linker command failed error which I wasn't able to figure out, 
unfortunately.
*********************************************************/
#include <fstream>
#include <iostream>
using namespace std;

const int MAXLINE = 501;

struct NBAData
{
   char teamName[81];
	char cityName[81];
	int stadiumCapacity;
	int yearFounded;


};
void loadNBAData( NBAData *data[], int& numTeams );
float computeAverage( NBAData *data[], int numTeams );
void displayAboveAverage( NBAData *data[], int numTeams, float averageScore );
void displayAllTeams(NBAData *teams[], int numTeams);
//void displaySelectedRecord(NBAData *data[], int numTeams, char selectedRecord);

int main ( ){
    NBAData *data[100];
    int numTeams;
    int userInput;
    float averageScore;
    char selectedRecord;

    loadNBAData( data, numTeams );
          
    do{
        cout << "What would you like to do? Enter 0 1 2 or 3 " << endl;
        cout << "0: Display the entire data file." << endl;
        cout << "1: Display a selected record in the data file, specified by user" << endl;
        cout << "2: Display the result of a cumulative value (the average) computed\n";
        cout << "over a user-specified subset of the data file" << endl;
        cout << "3: Exit the program" << endl;
        cin >> userInput;
   
   		if (userInput == 0) {
   
            displayAllTeams( data, numTeams);
   
   		} else if (userInput == 1) {
            
            cout << "Which data type would you like displayed?" << endl;
            cout << "Please enter specific team name" << endl;
            cin >> selectedRecord;

            //displaySelectedRecord( data, numTeams, selectedRecord);


   		} else if (userInput == 2) {
   
            cout << "What average would you like to calculate? "<<endl;
            cout << "Please enter a number"<< endl;
            cin >> averageScore;
            averageScore = computeAverage( data, numTeams );
            displayAboveAverage( data, numTeams, averageScore );
   
   		} else{
            cout << "INVALID INPUT HUMAN"<< endl;
        } 
	} while (userInput != 3);
    return 0;
}
/*
void displaySelectedRecord(NBAData *data[], int numTeams, char selectedRecord){
    int count;
    int validName = 0;

    for (count = 0; count < numTeams; count++){
        if (data[count]->teamName == selectedRecord){

            cout << data[count]->yearFounded
                << "\t" << data[count]->teamName
                << "\t" << data[count]->cityName 
                << "\t" << data[count]->stadiumCapacity << endl;
            validName = 1;
        }
    }
    if (validName == 0){
        cout << "That was not a team in our data base.";
    }
}

*/
void loadNBAData ( NBAData *data[], int& numTeams){

    fstream infile;

    infile.open( "NBAteams.txt", ios::in );
    numTeams = 0;
    infile >> data[numTeams]->yearFounded;

    while ( data[numTeams]->yearFounded != 0 )
    {
                
        infile >> data[ numTeams ]->teamName;
        infile >> data[ numTeams ]->cityName;
        infile >> data[ numTeams ]->stadiumCapacity;
        
        ++numTeams;

        infile >> data[ numTeams ]->yearFounded;

    }
    infile.close();
    }
float computeAverage( NBAData *data[], int count )
{
    int ix;
    float sum, average;

    sum = 0;
    for ( ix = 0; ix < count; ++ix )
        sum = sum + data[ix]->stadiumCapacity;

    if ( count > 0 )
        average = sum / count;
    else
        average = 0;

    return average;
}


void displayAboveAverage( NBAData *data[], int numTeams, 
                          float averageScore )
{
  int ix;

  cout << endl << endl << "Above-average Planets" << endl << endl;


  for ( ix = 0; ix < numTeams; ++ix )
  {
    if ( data[ix]->yearFounded > averageScore )
    {
        cout << data[ix]->yearFounded 
            << "\t" << data[ix]->teamName 
            << "\t" << data[ix]->cityName 
            << "\t" << data[ix]->stadiumCapacity << endl;
    }
  }

  cout << endl << "Average Score=" << averageScore << endl << endl;
}


void displayAllTeams(NBAData *data[], int numTeams) {
   int count;
		
        cout << "Year Founded" << "\t"
            << "Team Name" << "\t"
            << "City Name" << "\t"
            << "Stadium Capacity" << endl;
		for (count = 0; count < numTeams; ++count) {
            cout << data[count]->yearFounded 
                << "\t" << data[count]->teamName 
                << "\t" << data[count]->cityName 
                << "\t" << data[count]->stadiumCapacity << endl;
		}
}
