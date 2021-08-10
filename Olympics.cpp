/* Author: Allison Delgado
   Class: CS 202 Summer 2021
   Olympics.h contains the function prototypes 
   for the following classes: Sport, Track
   (track and field), Tennis, VB (volleyball),
   BST, B_Node, LLL, and L_Node.
   The athletes will be stored in a BST.  
   
   Last updated: Aug 6, 2021
 */

#include "Olympics.h"

//SPORT CLASS ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

//initialization list
Sport::Sport() : skills(""), history(""), medals(0){
  date = new char[7];
  time = new char[5];
}

//destructor
Sport::~Sport(){
  delete [] date;
  delete [] time;
  time = nullptr;
  date = nullptr;
}

//copy constructor
Sport::Sport(const Sport & source){
  date = new char[strlen(source.date) + 1];
  strcpy(date, source.date);
  time = new char[strlen(source.time) + 1];
  strcpy(time, source.time);
}

//fill in data
void Sport::read(){
  char d[7];
  char t[5];
  std::string s;
  std::string h;
  int m;
  
  std::cout << "What time does this event occur? " << std::endl;
  std::cout << "Enter the time in hhmm format " << std::endl;
  std::cout << "Ex: 4:30 would be 0430" << std::endl;
  std::cout << "> ";
  std::cin.get(t, 5);
  std::cin.get();
  std::cout << "What is the date of this event? " << std::endl;
  std::cout << "Enter the date in mmddyy format. " << std::endl;
  std::cout << "Ex: May 4, 2021 would be 050421" << std::endl;
  std::cout << "> ";
  std::cin.get(d, 7);
  std::cin.get();
  std::cout << "What kind of skills would this type of sport require?" << std::endl;
  std::cout << "> ";
  std::getline(std::cin, s);
  std::cout << "What is their history of competing at the olympics?" << std::endl;
  std::cout << "> ";
  std::getline(std::cin, h);
  std::cout << "How many medals have they won?" << std::endl;
  std::cout << "> ";
  std::cin >> m;
  std::cin.get();

  strcpy(date, d);
  strcpy(time, t);
  skills = s;
  history = h;
  medals = m;
}

//display data
void Sport::display() const{
  std::cout << "DATE: " << date[0] << date[1] << "/" << date[2] << date[3] << "/" << date[4] << date[5] << std::endl;
  std::cout << "TIME: " << time[0] << time[1] << ":" << time[2] << time[3] << std::endl;
  std::cout << "SKILLS: " << skills << std::endl;
  std::cout << "HISTORY: " << history << std::endl;
  std::cout << "MEDALS: " << medals << std::endl;
}

//compare the date
bool Sport::compare_d(char* d){
  if(strcmp(d, date) == 0){
    return true;
  }
  return false;
}

//compare the time
bool Sport::compare_t(char* t){
  if(strcmp(t, time) == 0){
    return true;
  }
  return false;
}

//overload ==
bool Sport::operator == (const Sport & sport){
  return (strcmp(date, sport.date) == 0) &&
    (strcmp(time, sport.time) == 0) && (skills == sport.skills)
    && (history == sport.history) && (medals == sport.medals);
}

//overload !=
bool Sport::operator != (const Sport & sport){
 return (strcmp(date, sport.date) != 0) &&
    (strcmp(time, sport.time) != 0) && (skills != sport.skills)
    && (history != sport.history) && (medals != sport.medals);
}
//TRACK AND FIELD CLASS ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

//initialization list
Track::Track() : athlete_name(""), distance(0){

}

//read in info
void Track::read(){
  std::string name;
  int meters = 0;
  
  std::cout << "What is the name of this track athlete? " << std::endl;
  std::getline(std::cin, name);
  std::cout << "How many meters is the event they are competing in?" << std::endl;
  std::cin >> meters;
  std::cin.get();

  athlete_name = name;
  distance = meters;
  Sport::read();
}

//print out athlete data
void Track::display(){
  std::cout << "Athlete: " << athlete_name << std::endl;
  std::cout << "Distance: " << distance << " meters " << std::endl;
  Sport::display();
}

//change which event they are competing in
void Track::change_event(int dist){
  distance = dist;
}

