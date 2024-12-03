#include "Interface.hpp"

#include <iostream>
#include <stdlib.h>
#include <fstream>
#include <string>
#include <sstream>
using namespace std;


Interface::Interface(string name, bool Xtra) {
	fn = name;
	tree = new BST(Xtra);
	readFile();
}


void Interface::Menu() {
	char c = 'a';
	while (c != 'q') {
		cout <<endl<<"****************************************************"<<endl;
		cout <<"Choose Option:\n  a\tLook up Species\n  b\tAdd a Species to the Endangered List\n  c\tRemove a species from the Endangered List\n  d\tUpdate the Species Status\n e\tPrint the Species Tree\n  q\tquit"<< endl;
		cin >> c;
		switch (c) {
		case 'a': {
			cout << "What species do you want to look up?"<<endl;
			string l;
			cin >> l;
			BSTNode *t = tree->find(l);
			if (t == NULL) {
				cout << l <<" not in endangered list.  " << endl;
			}
			else {
				t->printNode(tree->Xt);
			}
			break;
		}
		case 'b':{
			string name;
			string status;
			string info;
			cout << "Enter Species: "<<endl;
			cin >> name;
			cout << "Enter Status (EX = Extinct\n EW = Extinct in the Wild\n T1 = Critically Threatened\n T2 = Threatened\n NT=Near Threatened\n Vulnerable = VU\n LC = Least Concern\n " << endl;
			cin >> status;
			cout << "Enter species info: ";
			cin.ignore();
			getline(cin, info);

			if (tree->insert(name, status, info )) {
				cout << endl <<name << " inserted successfully "<<endl;
			}
			else {
				BSTNode *t = tree->find(name);
				t->printNode(false);
				cout << "... already in tree with " << endl;
			}
			break;
		}
		case 'c': {
			cout << "Enter Species: "<<endl;
			string l;
			cin >> l;
			BSTNode *t = tree->remove(l);
			if (t == NULL) {
				cout << endl  << l << " not in tree " << endl;
			}
			else {
				t->printNode(false);
				cout << " ...has been removed. "<<endl;
			}
			break;
		}
		case 'd': {
			cout << "Enter Species: "<<endl;
			string l;
			cin >> l;
			cout << "Enter Status (EX = Extinct\n EW = Extinct in the Wild\n T1 = Critically Threatened\n T2 = Threatened\n NT=Near Threatened\n Vulnerable = VU\n LC = Least Concern\n " << endl;
			string status;
			cin >> status;
			tree->updateStatus(l,status);
			break;
		}
		case 'e': {
			cout << "Choose a for pre, b for in, or c for post-order\t";
			char k;
			cin >> k;
			cout << endl;
			cout << "************************************************"<<endl;
			if (k == 'a') {
				cout << "*********** Printing Tree Pre Order ************"<<endl;
				cout << "************************************************"<<endl;
				tree->printTreePre();
			}
			else if (k == 'b') {
				cout << "*********** Printing Tree In Order *************"<<endl;
				cout << "************************************************"<<endl;
				tree->printTreeIO();
			}
			if (k == 'c') {
				cout << "*********** Printing Tree Post Order ***********"<<endl;
				cout << "************************************************"<<endl;
				tree->printTreePost();
			}

			break;
		}
	}
	}
}

void Interface::strip(string s, string arr[]) {
	const char* Splitter = "|";
	const char* EndChar = "|";
	size_t start = 0;
	int len;
	for (int i = 0; i < 3; i++) {
		len = s.length();
		s = s.substr(start,len-start+1);
		size_t end = s.find_first_of(EndChar);
		s = s.substr(start,len-start+1);
		end = s.find_first_of(EndChar);
		if (end > 0){
			arr[i] = s.substr(0,end);
			s = s.substr(end+1, len-end);
		}
	}
	return;
}
void Interface::readFile() {
	ifstream file(fn.c_str());
	string arr[3];
	string j;
	getline(file,j);
	int x = 0;
	while (!file.eof()&& x < 10) {
		strip(j, arr);
		cout << arr[0]<< ", " << arr[1] << ", " << arr[2] << endl;
		// for testing as I read in - you can comment this out you've gotten things working
		tree->insert(arr[0], arr[1], arr[2]);
		getline(file,j);
		x++;
	}
	tree->printTreeIO();
	return;
}


