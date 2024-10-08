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
    while(curr != NULL || !st.empty()){
        if(curr != NULL){
            st.push(curr);
            curr = curr -> left;
        }
        else{
            temp = st.top();
            if(temp == NULL){
                temp = st.top();
                st.pop();
                postorder.push_back(temp);
                while(!st.empty()) && temp == st.top() -> right){
                    temp = st.top();
                    st.pop();
                    postorder.push_back(temp -> val);
                    
        else{
            curr = temp;
        }
                }
            }
        }
    }
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
