/* Author: Allison Delgado
   Class: CS 202 Summer 2021
   Olympics.h contains the function prototypes
   for the following classes: Sport, Track 
   (track and field), Tennis, VB (volleyball),
   BST, B_Node, LLL, and L_Node.
   The athletes will be storesd in a BST.

   Last updated: Aug 5, 2021
 */

#include <iostream>
#include <cstring>
#include <vector>

//base class: Sport
class Sport {
public:
  Sport();
  ~Sport();
  Sport(const Sport & source);
  void read();
  void display() const;
  bool compare(char* d); //compare date
  bool compare(char* t); //compare time

  Sport operator == (const Sport &);
  Sport operator != (const Sport &);
private:
  char* date; //represented in 6 digits (mm/dd/yy)
  char* time; //represented in 4 digits (hh/mm)
  std::vector<std::string> skills;
  std::string history;
  int medals;
};

//track and field class
class Track : public Sport {
public:
  Track();
  ~Track();
  void read();
  void display();

  
private:
  std::string athlete_name;
  int distance;
};

//tennis class
class Tennis : public Sport {
public:
  Tennis();
  ~Tennis();
  void display();
private:
  int type; //1 = singles tennis, 2 = doubles tennis
  std::string athlete_name;
};

//volleyball class
class VB : public Sport {
public:
  VB();
  ~VB();
  void display();

  VB operator += (const VB &);
private:
  std::vector<std::string> players;
};

// ***************** DATA STRUCTURE CLASSES **************

class BST {
public:
  BST();
  ~BST();
  BST(const BST & source);

  //wrapper functions:
  void insert(B_Node & to_add);
  void remove(B_Node *& to_remove);
  void display();
  void remove_all();

  L_Node operator + (const L_Node &) const;
  L_Node operator = (const L_Node &);

private:
  //recursive versions:
  void insert(B_Node *& current, B_Node *& to_add);
  void remove(B_Node *& current, B_Node *& to_remove);
  void display(B_Node * current);
  void remove_all(A_Node *& current);
  B_Node * root;
};

//each node in the BST is a B_Node
class B_Node {
public:
  B_Node();
  B_Node(const LLL & source);
  B_Node *& go_left();
  B_Node *& go_right();
  void set_next(B_Node * node);

  bool operator == (const L_Node &) const;
  bool operator != (const L_Node&) const;

private:
  B_Node * left;
  B_Node * right;
};

//each node in the LLL is an L_Node
class L_Node {
public:
  L_Node();
  L_Node(const Athlete & source);
  L_Node *& go_next();
  void set_next(L_Node *& n);

  bool operator == (const L_Node &) const;
  bool operator != (const L_Node&) const;
  
private:
  L_Node * next;
};

//holds the races/events the athlete is competing in
class LLL {
public:
  LLL();
  LLL(const LLL & source);
  ~LLL();

  //wrapper functions:
  void insert(L_Node & to_add);
  void remove(L_Node *& to_remove);
  void display();
  void remove_all();

  L_Node operator + (const L_Node &) const;
  L_Node operator = (const L_Node &);
  L_Node operator [] (const L_Node &);
private:
  //recursive versions:
  void remove(L_Node *& cur, std::string to_remove);
  void display(L_Node * cur);
  void remove_all(L_node *& cur);
  L_Node * head;
};
