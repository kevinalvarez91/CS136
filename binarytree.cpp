#include <iostream>
#include <queue>

using namespace std;

struct Node {
    int data; //creating a binary tree who's data is type int
    Node* left;//left child
    Node* right;//right child

};

Node* createNode(int data)
{
    Node* newNode = new Node();
    newNode->data = data;
    newNode->left =newNode->right =nullptr;
    return newNode;
}


int main(){
//parent on top, child lower, the lines are edges. children can not be connected, with edges
//root node is a node that doesn't have a parent, so the orginal node
//leaf node is a node that doesn't have any children


    Node* root = createNode(1);
    root->left=createNode(2);
    root->right=createNode(3);
    root->left->left=createNode(4);
    







}