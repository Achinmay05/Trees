// DFS(Inorder, Preorder, Postorder)

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

void Inorder(Node* node){
    if(node == NULL){
        return;
    }
    
    Inorder(node -> left);
    cout << node->data << " ";
    Inorder(node -> right);
}

void Postorder(Node* node){
    if(node == NULL){
        return;
    }
    
    Postorder(node -> left);
    Postorder(node -> right);
    cout << node->data << " ";
}

void Preorder(Node* node){
    if(node == NULL){
        return;
    }
    
    cout << node->data << " ";
    Preorder(node -> left);
    Preorder(node -> right);
}

int main(){
    Node* root = new Node(1);
    root -> left = new Node(2);
    root -> right = new Node(3);
    
    // root -> left -> right = new Node(5);
    // Print(root);
    Inorder(root);
    Postorder(root);
    Preorder(root);
}
