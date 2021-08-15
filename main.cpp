/* Author: Allison Delgado
   Class: CS 202 Summmer 2021   
   main.cpp acts as a testing site to add
   and customize new instances of olympic sports.
   It utilizes Olympics.h.

   Last updated: Aug 14, 2021
 */


#include "Olympics.h"
#include <cstring>
#define START 5;
using namespace std;

void track(Track & tr);
void tennis(Tennis & tn);
void volleyball(VB & vb);
void choices();

int main(){
  cout << "Welcome to the Olympics! " << endl;
  choices();
  return 0;
}

void choices(){
  BST bst;
  Track tr;
  Tennis tn;
  VB vb;
  int choice;
  
  cout << "Select an option: " << endl;
  cout << "1 - Track and Field "<< endl;
  cout << "2 - Tennis" << endl;
  cout << "3 - Volleyball" << endl;
  cout << "> ";
  cin >> choice;
  cin.get();

  if(choice == 1){
    track(tr);
  } else if (choice == 2){
    tennis(tn);
  } else if (choice == 3){
    volleyball(vb);
  } else {
    cout << "That was not one of the choices. Quitting program." << endl;
    return;
  }
}

//track choices
void track(Track & tr){
  int choice = START;
  int meters = 0;

  do {
    cout << " " << endl;
    cout << "Select an option: " << endl;
    cout << "1 - set up a track event" << endl;
    cout << "2 - display your track event " << endl;
    cout << "3 - change your event" << endl;
    cout << "0 - go back" << endl;
    cout << "> ";
    cin >> choice;
    cin.get();

    if(choice == 1){
      tr.read();
    } else if(choice == 2){
      tr.display();
    } else if(choice == 3){
      cout << "How many meters is the new event you would like to run?" << endl;
      cout << "> ";
      cin >> meters;
      cin.get();
      tr.change_event(meters);
    } else if(choice == 0){
      choices();
    } else {
      cout << "That was not one of the choices!" << endl;
    }
  
  } while (choice != 0);
}

//Tennis choices
void tennis(Tennis & tn){
  int choice = START;
  do {
    cout << " " << endl;
    cout << "Select an option: " << endl;
    cout << "1 - set up a tennis event" << endl;
    cout << "2 - display your tennis event " << endl;
    cout << "3 - change the type of tennis match" << endl;
    cout << "0 - go back" << endl;
    cout << "> ";
    cin >> choice;
    cin.get();
    
    if(choice == 1){
      tn.read();
    } else if (choice == 2){
      tn.display();
    } else if (choice == 3){
      tn.change_type();
    } else if (choice == 0){
      choices();
    } else {
      cout << "That was not one of the choices." << endl;
    }
  } while (choice != 0);
}

//VB choices
void volleyball(VB & vb){
  int choice = START;
  do {
    cout << " " << endl;
    cout << "Select an option: " << endl;
    cout << "1 - set up a volleyball event" << endl;
    cout << "2 - display your volleyball event " << endl;
    cout << "3 - add players to the volleyball team" << endl;
    cout << "4 - remove players from the volleyball team" << endl;
    cout << "0 - go back" << endl;
    cout << "> ";
    cin >> choice;
    cin.get();
    
    if(choice == 1){
      vb.read();
    } else if (choice == 2){
      vb.display();
    } else if (choice == 3){
      int a = 0;
      string name;
      vector<string> vtr;
      
      cout << "Enter the amount of players you would like to " << endl;
      cout << "add to the current volleyball roster" << endl;
      cout << "> ";
      cin >> a;
      cin.ignore(1000, '\n');
      cout << "Enter in each player's name (1 at a time, separated by a newline)" << endl;

      for(int i = 0; i < a; i++){
	cout << "> ";
	getline(cin, name);
	vtr.push_back(name);
      }
      vb.add_players(vtr);
    } else if (choice == 4){
      int a = 0;
      string name;
      vector<string> vtr;
      
      cout << "Enter the amount of players you would like to " << endl;
      cout << "remove from the current volleyball roster" << endl;
      cout << "> ";
      cin >> a;
      cin.ignore(1000, '\n');
      cout << "Enter in each player's name (1 at a time, separated by a newline)" << endl;

      for(int i = 0; i < a; i++){
	cout << "> ";
	getline(cin, name);
	vtr.push_back(name);
      }
      vb.remove_players(vtr);
    } else if (choice == 0){
      choices();
    } else {
      cout << "That was not one of the choices." << endl;
    }
  } while (choice != 0);
}
