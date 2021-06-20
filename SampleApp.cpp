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
	//srand(time(0));
	srand(2021);
	AVLTreeExt<Data, int> tree;

	//The following code is for testing only. Replace it with your own implementation
	vector<int> randNums;
	vector<int> container;
	int temp;
	for (int i = 100; i <= 200; i++) {
		container.push_back(i);
	}
	for (int i = 0; i < 10; i++) {
		temp = rand()%10;
		randNums.push_back(container[temp]);
		container.erase(container.begin() + temp);
	}
	// for (int i = 0; i < randNums.size(); i++) {
	// 	cout << randNums[i] << endl;
	// }
	ifstream inFile;
	string fileName = "names.txt";
  //------open the file---------
  	inFile.open(fileName);
    if (!inFile) {
        cout << "Unable to open file";
        exit(1); // terminate with error
    }
  //----------------------------
	string x;
	int counter = 0;
	int index = 0;
	string fName, lName;
	set<pair<int, pair<string, string>>> fullNames;
	while (inFile >> x) {
		if (counter == 0) {
			fName = x;
			counter++;
			continue;
		}
		else if (counter == 1) {
			lName = x;
			Data newItem;
			newItem.key = container[index];
			newItem.name.first_name = fName;
			newItem.name.last_name = lName;
			fullNames.insert({container[index], {fName, lName}});
			tree.AVL_Insert(newItem);
			counter = 0;
			index++;
		}

	}

  //   cout <<"Output from testing code:" << endl;
	// Data newItem;
	// newItem.key = rand()%100 + 100;
	// newItem.name.first_name = "Dongmo";
	// newItem.name.last_name = "Zhang";
	// tree.AVL_Insert(newItem);
	// tree.AVL_Traverse(print);

	// End of the testing code

	inFile.close();
	tree.AVL_Traverse(print);
	cout << endl;
	tree.AVL_TraverseD(print);
	cout << endl;

	// for (auto it = fullNames.begin(); it != fullNames.end(); it++) {
	// 	cout << it->first << ":" << it->second.first << " " << it->second.second << endl;
	// }

	AVLTreeExt<Data, int> newTree;
	for (auto it = fullNames.begin(); it != fullNames.end(); it++) {
		Data newItem;
		newItem.key = it->first;
		newItem.name.first_name = it->second.first;
		newItem.name.last_name = it->second.second;
		newTree.AVL_InsertLN(newItem);
	}
	newTree.AVL_Traverse(print);


	return 0;
}
