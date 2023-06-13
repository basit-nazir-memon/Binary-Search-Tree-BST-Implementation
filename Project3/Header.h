#pragma once
#include <iostream>
#include <fstream>
#include <string>

using namespace std;


class node {
public:
	int data;
	node* left;
	node* right;
};

class BST {
	node* root;
	int NoOfNodes(int&, node*);
	void checkNodeToDelete(int&, node*&);
	void deleteNode(node*&);
	void emptyTree(node*);
	void displayNode(string&, node*);
	void displayNodeInDescending(node*);
	void displayLessThan(int&, node*);
	void fill(node*);
	void writeFile(ofstream&, node*);
	/*void writeLeftRight(ofstream&, node*);
	void writeFile();*/
	void fillArray(node*, int*&);
	int findHeight(node*);
	void fillTree(node*, int*&, int&);
public:
	BST();
	//BST(string);
	BST(BST&);
	void writeFile(string);
	void readFile(string);
	//void readFile(string);
	void insert(int);
	int size();
	bool isEmpty();
	bool retrieve(int);
	void displayInOrder();
	void displayPreOrder();
	void displayPostOrder();
	void displayDescending();
	void remove(int);
	void empty();
	bool is_BST(node*);
	bool isBST() {
		return is_BST(root);
	}
	int findLevel();
	void displayLessThan(int num);
	BST& operator=(BST&);
	~BST();
};

