#include <iostream>
#include <vector>
using namespace std;

// struct TreeNode* getNewNode();
// void addChild();

struct TreeNode{
    int data;
    vector<TreeNode*> children;
};

TreeNode* getNewNode(int data){
    TreeNode* newNode = new TreeNode();
    newNode -> data = data;
    return newNode;
}

void addChild(TreeNode* node, int data){
    TreeNode* newNode = getNewNode(data);
    node -> children.push_back(newNode);
}

void Print(TreeNode* root){
    cout << root -> data << endl;
    cout << root -> children[0] -> data << endl;
    cout << root -> children[1] -> data << endl;
    cout << root -> children[0] -> children[0] -> data << endl;
    cout << root -> children[1] -> children[0] -> data << endl;
}

int main(){
    TreeNode* root;
    root = getNewNode(3);
    addChild(root, 5);
    addChild(root, 4);
    
    addChild(root -> children[0], 15);
    addChild(root -> children[1], 10);
    Print(root);
}
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    


