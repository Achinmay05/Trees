#include <iostream>
#include <vector>
#include <queue>

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

vector<vector<int>> levelOrderTraversal(Node* root){
    vector<vector<int>> ans;
    if(root == NULL){
        return ans;
    }
    queue<Node*> q;
    q.push(root);
    
    while(!q.empty()){
        vector<int> level;
        for(int i = 0; i < q.size(); i++){
            Node* node = q.front();
            q.pop();
            if(node -> left != NULL) q.push(node -> left);
            if(node -> right != NULL) q.push(node -> right);
            level.push_back(node -> data);
        }
        ans.push_back(level);
    }
    return ans;
}

int main(){
    Node* root = new Node(1);
    root -> left = new Node(4);
    root -> right = new Node(5);
    root -> right -> right = new Node(8);
    root -> left -> left = new Node(3);
    root -> left -> right = new Node(7);
    root -> right -> left = new Node(6);

    vector<vector<int>> vec = levelOrderTraversal(root);
    for (const auto& row : vec) {
        for (const auto& elem : row) {
            cout << elem << " ";
        }
    }

}
