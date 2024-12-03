

#include <iostream>
#include <string>
#include "BSTNode.hpp"
using namespace std;

BSTNode::BSTNode (string sp, string st, string inf) {
	left = NULL;
	right = NULL;
	parent = NULL;
	height = 1;
	animal = new Species(sp, st, inf);
}
BSTNode::BSTNode() {
	left = NULL;
	right = NULL;
	parent = NULL;
	height = 1;
	animal  = NULL;
}
BSTNode::~BSTNode(){
	cout <<"Deleting "<<animal->name<<endl;
}
void BSTNode::printNode(bool XtraInfo) {
	cout << animal->name <<" (" <<height <<") ";
	if (XtraInfo) {
		cout <<": "<< animal->status << endl;
		cout << animal->info;
	}
	cout << endl;

}



