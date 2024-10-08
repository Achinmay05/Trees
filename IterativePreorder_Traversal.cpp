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

vector<int> IterativePreorder(Node* root){
    vector<int> preorder;
    if(root == NULL){
        return preorder;
    }
    stack <Node*> st;
    st.push(root);
    while(!st.empty()){
        root = st.top();
        st.pop();
        preorder.push_back(root -> data);
        if(root -> right != NULL){
            st.push(root -> right);
        }
        if(root -> left != NULL){
            st.push(root -> left);
        }
    }
    return preorder;
}

int main(){
    Node* root = new Node(1);
    root -> left = new Node(4);
    root -> right = new Node(5);
    root -> right -> right = new Node(8);
    root -> left -> left = new Node(3);
    root -> left -> right = new Node(7);
    root -> right -> left = new Node(6);

    vector<int> vec = IterativePreorder(root);
    for (const auto& item : vec) {
        cout << item << " ";
    }

}
