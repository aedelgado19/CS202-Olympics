/* Author: Allison Delgado
   Class: CS 202 Summmer 2021   
   main.cpp acts as a testing site to add
   and customize new instances of olympic sports.
   It utilizes Olympics.h.

   Last updated: Aug 6, 2021
 */


#include "Olympics.h"
#include <cstring>
#define START 5;
using namespace std;

void track();

int main(){
  //so far only has Track and BST
  cout << "Welcome to the Olympics! " << endl;

  track();
}

void track(){
  int choice = START;
  int meters = 0;
  Track t;
  
  do {
    cout << " " << endl;
    cout << "Select an option: " << endl;
    cout << "1 - set up a track event" << endl;
    cout << "2 - display your track event " << endl;
    cout << "3 - change your event" << endl;
    cout << "0 - quit" << endl;
    cout << "> ";
    cin >> choice;
    cin.get();

    if(choice == 1){

      t.read();
    } else if(choice == 2){
      t.display();
    } else if(choice == 3){
      cout << "How many meters is the new event you would like to run?" << endl;
      cout << "> ";
      cin >> meters;
      cin.get();
      t.change_event(meters);
    } else if(choice == 0){
      cout << "Goodbye!" << endl;
    } else {
      cout << "That was not one of the choices!" << endl;
    }
  
  } while (choice != 0);
}
