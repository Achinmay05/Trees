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

int dfsHeight(Node* root){
    if(root == NULL) return 0;
    int leftHeight = dfsHeight(root -> left);
    if(leftHeight == -1) return -1;
    int rightHeight = dfsHeight(root -> right);
    if(rightHeight == -1) return -1;
    
    if(abs(leftHeight - rightHeight) > 1) return -1;
    return max(leftHeight, rightHeight) + 1;
}

bool isBalanced(Node* root){
    return dfsHeight(root) != -1;
}

int main(){
     Node* root = new Node(1);
    root -> left = new Node(2);
    root -> right = new Node(3);
    
    if (isBalanced(root)) {
        cout << "The tree is balanced." << endl;
    } else {
        cout << "The tree is not balanced." << endl;
    }
}
