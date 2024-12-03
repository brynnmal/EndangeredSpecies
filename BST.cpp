#include "BST.hpp"
#include <iostream>
#include <stdlib.h>
using namespace std;

/**************************************************************/
/* These are the methods you are to write for a BST           */
/* More Detailed Instructions can be found in the doc and in  */
/* the BST.hpp file                                           */
/**************************************************************/

BST::BST(string n, string st, string descr, bool Xtra) {
	BSTNode *first = new BSTNode(n, st, descr);
	root = first;
	Xt = Xtra;
}

bool BST::insert(string n, string st, string descr) {
	BSTNode *newest = new BSTNode(n, st, descr);
	if(root == NULL) {
		root = newest;
		return true;
	}
	BSTNode *current = root;
	BSTNode *parent = NULL;
	while(current != NULL) {
		parent = current;
		if(newest->animal->name < current->animal->name) {
			current = current->left;
		}else if (newest->animal->name > current->animal->name) {
			current = current->right;
		}else {
			return false;
		}
	}
	if(newest->animal->name < parent->animal->name) {
		parent->left = newest;
	}else {
		parent->right = newest;
	}
	newest->parent = parent;
	setHeight(newest);
	return true;
}

BSTNode *BST::find(string n) {
	BSTNode	*current = root;
	while(current != NULL){
    	if(current->animal->name == n){
          break;
        }
        if(n > current->animal->name){
        	current = current->right;
        }else{
        	current = current->left;
        }
    }
	if(current == NULL) {
		cout<< n + ":Not Found"<<endl;
	}else {
		cout<<"Found:" + n<<endl;
	}
    return current;
}

void BST::updateStatus(string name, string st) {
	BSTNode	*current = root;
	while(current != NULL){
		if(current->animal->name == name){
			break;
		}
		if(name > current->animal->name){
			current = current->right;
		}else{
			current = current->left;
		}
	}
	current->animal->status = st;
}
void BST::printTreeIO(BSTNode *tmp) {
	if(tmp->left != NULL) {
		printTreeIO(tmp->left);
	}
	cout<<tmp->animal->name<<endl;
	if(tmp->right != NULL) {
		printTreeIO(tmp->right);
	}
}

void BST::printTreePre(BSTNode *tmp) {
	//have to use print node method?
	cout << tmp->animal->name << endl;
	if(tmp->left != NULL) {
		printTreePre(tmp->left);
	}
	if(tmp->right != NULL){
		printTreePre(tmp->right);
	}
}


void BST::printTreePost(BSTNode *tmp) {
	if(tmp->left != NULL) {
		printTreePost(tmp->left);
	}
	if(tmp->right != NULL) {
		printTreePost(tmp->right);
	}
    cout<<tmp->animal->name<<endl;
}

void BST::setHeight(BSTNode *tmp) {
	BSTNode *parent = tmp;
	while(parent->parent != NULL) {
		tmp = parent;
		parent = parent->parent;
		if (parent->height < (tmp->height + 1)) {
			parent->height += 1;
		}
	}//pass in child of remove if no child pass in parent
}

BSTNode *BST::removeNoKids(BSTNode *tmp) {
	BSTNode *parent = tmp->parent;
	if(parent->left == tmp) {
		parent->left = NULL;
	}else if(parent->right == tmp) {
		parent->right = NULL;
	}
	setHeight(tmp->parent);
	tmp->parent = NULL;
	return tmp;
}

BSTNode *BST::removeOneKid(BSTNode *tmp,bool leftFlag) {
	BSTNode *child;
	if(leftFlag) {
		child = tmp->left;
	}else {
		child = tmp->right;
	}
	if(tmp->parent->left == tmp) {
		tmp->parent->left = child;
		child->parent = tmp->parent;
	}else if(tmp->parent->right == tmp) {
		tmp->parent->right = child;
		child->parent = tmp->parent;
	}
	tmp->parent ==NULL;
	tmp->left = NULL;
	tmp->right = NULL;
	return tmp;
}
BSTNode *BST::remove(string s) {
	BSTNode *animal = find(s);
	if(animal->left == NULL && animal->right == NULL) {
		removeNoKids(animal);
	}else if(animal->left == NULL && animal->right != NULL) {
		removeOneKid(animal, false);
	}else if(animal->left != NULL && animal->right == NULL) {
		removeOneKid(animal, true);
	}else {
		BSTNode *current = animal->right;
		BSTNode *parent = animal->parent;
		BSTNode *special = NULL;
		while(current != NULL) {
			special = current;
			current = current->left;
		}
		if(parent->left == animal) {
			if(special->right != NULL) {
				removeOneKid(special, false);
			}
			parent->left = special;
			//special->parent->left = NULL;
			special->parent = parent;
			special->left = animal->left;
			special->right = animal->right;
		}else if(parent->right == animal) {
			if(special->right != NULL) {
				removeOneKid(special, false);
			}
			parent->right = special;
			//special->parent->left = NULL;
			special->parent = parent;
			special->left = animal->left;
			special->right = animal->right;

		} //check slide becuase what if there is a right child of our leftmost
		//come HEREEEEEEE
		setHeight(special);
	}
	animal->parent = NULL;
	animal->left = NULL;
	animal->right = NULL;
	return animal;
}

/**************** Written for you  ***********************/

BST::BST(bool Xtra) {
	root = NULL;
	Xt = Xtra;
}


void BST::clearTree() {
	if (root == NULL) {
		cout << "Tree already empty" << endl;
	}
	else {
		cout << endl << "Clearing Tree:" << endl;
		clearTree(root);
		root = NULL;
	}
}
void BST::clearTree(BSTNode *tmp) {
	if (tmp == NULL) {
		return;
	}
	else {
		clearTree(tmp->left);
		clearTree(tmp->right);
		tmp->printNode(Xt);
		delete(tmp);
	}
}
void BST::printTreePost() {
	if (root == NULL ) {
		cout << "Empty Tree" << endl;
	}
	else {
		cout << endl<<"Printing PostOrder:" <<endl;
		printTreePost(root);
	}
}

void BST::printTreePre() {
	if (root == NULL ) {
		cout << "Empty Tree" << endl;
	}
	else {
		cout << endl<<"Printing PreOrder:" <<endl;
		printTreePre(root);
	}
}

void BST::printTreeIO() {
	if (root == NULL ) {
		cout << "Empty Tree" << endl;
	}
	else {
		cout << endl<<"Printing In Order:" <<endl;
		printTreeIO(root);
	}
}






