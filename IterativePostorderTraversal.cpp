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

vector<int> IterativePostorderTraversal(Node* root){
    vector<int> postorder;
    if(root ==NULL) return postorder;
    stack<Node*> st1, st2;
    st1.push(root);
    while(!st1.empty()){
        root = st1.top();
        st1.pop();
        st2.push(root);
        if(root -> left != NULL){
            st1.push(root -> left);
        }
        if(root -> right != NULL){
            st1.push(root -> right);
        }
    }
    while(!st2.empty()){
        postorder.push_back(st2.top() -> data);
        st2.pop();
    }
    return postorder;
}

int main(){
    Node* root = new Node(1);
    root -> left = new Node(4);
    root -> right = new Node(5);
    root -> right -> right = new Node(8);
    root -> left -> left = new Node(3);
    root -> left -> right = new Node(7);
    root -> right -> left = new Node(6);

    vector<int> vec = IterativePostorderTraversal(root);
    for (const auto& item : vec) {
        cout << item << " ";
    }

}
