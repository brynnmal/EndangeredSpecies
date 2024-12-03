

#ifndef BSTNODE_HPP_
#define BSTNODE_HPP_

#include <iostream>
#include <stdlib.h>
#include "Species.hpp"
using namespace std;

class BSTNode{
	friend class BST;
	friend class Interface;
	BSTNode *left;
	BSTNode *right;
	BSTNode *parent;
	Species *animal;
	int height;
public:
	BSTNode(string sp, string st, string inf);
	BSTNode();
	~BSTNode();
	void printNode(bool XtraInfo);
};




#endif /* BSTNODE_HPP_ */
