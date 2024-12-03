#ifndef SPECIES_HPP_
#define SPECIES_HPP_

#include <iostream>
#include <stdlib.h>
using namespace std;

class Species {
	friend class BSTNode;
	friend class BST;
	friend class Interface;
	string name;
	string status;
	string info;
public:
	Species(string sp, string st, string inf);
	Species();
};




#endif /* SPECIES_HPP_ */
