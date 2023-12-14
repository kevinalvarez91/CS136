/*
   Kevin Alvarez 
   CS 136
   30 November 2023

   Write a program that stores a series of numbers in a binary tree. Then have the 
   program insert the values into a quene in ascending order. Dequeue the values and
   display them on the screeen to confirm they were stored in the proper order. Using 
   binary tree, with speific order as it is easier to transverse and get the values
   in ascending order. 

 */

#include <iostream>
#include <queue>

using namespace std;

class Node {
public:
		int data; //creating a binary tree who's data is type int, we could also do with obj
		Node* left;//left child
		Node* right;//right child

		//default constructor
		Node()
		{
			cout << "Invalid number of arguments";
			return;
		}

		//constructor
		Node(int value){
			data = value;
			left = nullptr;
			right = nullptr;

		}
};

//binary search insert function
Node* insert(Node* root, int data) {
	if (root == nullptr) {
		return new Node(data);
	}

	if (data > root->data){
		root-> right = insert(root->right, data);
	} else{
		root->left = insert(root->left, data);
	}


	return root;
}

//to print regular values, that are not in ascending order
void regularPrint(Node* root) {
	if (root == nullptr) {
		return;
	}
	//using a small queue to just store values in regular order
	queue<Node*> resultant;
	resultant.push(root);

	//REM
	while (resultant.empty() != true) {
		Node* now = resultant.front();
		resultant.pop();

		cout << now->data << " ";

		if (now->left != nullptr) {
			resultant.push(now->left);
		}

		if (now->right != nullptr) {
			resultant.push(now->right);
		}
	}
}

//to push values into the queue in ascending order
void queueresult(Node* root, queue<int>& main){
	if (root == nullptr)
	{
		return;
	}
	else {
		//left first because left has smaller number using recursion
		queueresult(root->left, main);
		main.push(root->data);
		queueresult(root->right, main);

	}
}

//deallocation function
void deleteRoot(Node* root){
	if (root == nullptr){
		return;
	}

	deleteRoot(root->left);
	deleteRoot(root->right);
	delete root;
}


int main(){
	//parent on top, child lower, the lines are edges. children can not be connected, with edges
	//root node is a node that doesn't have a parent, so the orginal node
	//leaf node is a node that doesn't have any children, so end node 
	Node* root = nullptr;
	int input, num;

	cout << "How many values do you wish to insert? ";
	cin >> num;
	cout << "Enter values to insert into binary tree: " << endl;
	for (int i = 0; i < num; i++){
		cin >> input;
		root = insert(root, input);

	}

	cout << "Regular Binary Tree(Not ascending): ";
	regularPrint(root);
	cout << "\n";

	// Creating a queue to store values in ascending order
	queue<int> resultantQueue;

	queueresult(root, resultantQueue);

	cout << "Values in ascending order: ";
	while (!resultantQueue.empty())
	{
		cout << resultantQueue.front() << " ";
		//remove the old front, to replace with the new front
		resultantQueue.pop();

	}
	cout << "\n";


	//in order to deallocate the memory
	deleteRoot(root);

	return 0;



}
/* OUTPUT
   kevinalvarez@Kevins-MacBook CS136 % g++ lab4v2.cpp
   kevinalvarez@Kevins-MacBook CS136 % ./a.out
   How many values do you wish to insert? 5
   Enter values to insert into binary tree: 
   2
   1
   3
   4
   5
   Regular Binary Tree(Not ascending): 2 1 3 4 5 
   Values in ascending order: 1 2 3 4 5 


 */
