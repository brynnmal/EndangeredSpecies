

#ifndef BST_HPP_
#define BST_HPP_

#include "BSTNode.hpp"
#include <iostream>
#include <stdlib.h>
using namespace std;

class BST {
	friend class Interface;
	BSTNode *root;
	bool Xt;

public:
	BST(bool Xtra);
	BST(string s, string st, string info, bool Xtra);  // updated
	bool insert(string n, string s, string info);  //updated
	BSTNode *find(string s);
	void printTreeIO();
	void printTreeIO(BSTNode *n);
	void printTreePre();
	void printTreePre(BSTNode *n);
	void printTreePost();
	void printTreePost(BSTNode *n);
	void clearTree();
	void clearTree(BSTNode *tmp);
	void updateStatus(string name, string st);
	BSTNode *removeNoKids(BSTNode *tmp);
	BSTNode *removeOneKid(BSTNode *tmp, bool leftFlag);
	BSTNode *remove(string s);
	void setHeight(BSTNode *n);
};






#endif /* BST_HPP_ */
