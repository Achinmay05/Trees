#include <iostream>
#include<stack>
#include<vector>

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

vector<int> IterativeInorder(Node* root){
    stack<Node*> st;
    Node* node = root;
    vector<int> inorder;
    while(true){
        if(node != NULL){
            st.push(node);
            node = node -> left;
        }
        else{
            if(st.empty() == true) break;
            node = st.top();
            st.pop();
            inorder.push_back(node -> data);
            node = node -> right;
        }
    }
    return inorder;
}

int main(){
    Node* root = new Node(1);
    root -> left = new Node(4);
    root -> right = new Node(5);
    root -> right -> right = new Node(8);
    root -> left -> left = new Node(3);
    root -> left -> right = new Node(7);
    root -> right -> left = new Node(6);

    vector<int> vec = IterativeInorder(root);
    for (const auto& item : vec) {
        cout << item << " ";
    }

}
