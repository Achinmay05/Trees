// Binary Tree Implementation
#include <iostream>

using namespace std;

struct Node{
    int data;
    Node* left;
    Node* right;
    
    Node(int val){
        data = val;
        left = right = NULL;
    }
};

void Print(Node* root){
    cout << root -> data << endl;
    cout << root -> right -> data << endl;
    cout << root -> left -> data << endl;
}

int main(){
    Node* root = new Node(1);
    root -> left = new Node(2);
    root -> right = new Node(3);
    
    root -> left -> right = new Node(5);
    Print(root);
}
