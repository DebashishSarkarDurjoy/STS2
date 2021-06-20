/*
 * The following code is provided for you to complete the programming tasks for 300103 DSA final examination
 * You may use, add, modify or delete any part of the code. Some parts of the code are hints.
 * You may ignore or replace any of them with your own implementation
 */

#include<iostream>
#include<fstream>
#include<cstdlib>
#include<iomanip>
#include<ctime>
#include <string>
#include <set>
#include <vector>
#include <queue>

using namespace std;

#include "AVL_ADT.h"
#include "AVL_ADT_Ext.h"

//Provided code. You may use, modify or delete it
struct Name {
	string first_name;
	string last_name;

    void display() {
	cout << first_name << " " << last_name << endl;
    }
};

//Provided code. You may use, modify or delete it
struct Data {
	int key;
	Name name;
};

//Provided code. You may use, modify or delete it
void print(Data ss) {
	cout << ss.key << ": " << ss.name.first_name << " " << ss.name.last_name
			<< endl;
}

int main() {
	srand(time(0));
	AVLTreeExt<Data, int> tree;

	//The following code is for testing only. Replace it with your own implementation

    cout <<"Output from testing code:" << endl;
	Data newItem;
	newItem.key = rand()%100 + 100;
	newItem.name.first_name = "Dongmo";
	newItem.name.last_name = "Zhang";
	tree.AVL_Insert(newItem);
	tree.AVL_Traverse(print);

	// End of the testing code

	return 0;
}
