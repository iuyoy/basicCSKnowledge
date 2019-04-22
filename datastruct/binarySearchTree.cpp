#include <bits/stdc++.h>
using namespace std;

// count same value
struct BSTNode {
    int val;
    int count;
    BSTNode *left;
    BSTNode *right;
    BSTNode(int x) : val(x), count(1), left(NULL), right(NULL) {}
};

BSTNode* insert(BSTNode *root, int val) {
    if (root == nullptr)
        return new BSTNode(val);
    else if (val < root->val)
        root->left = insert(root->left, val);
    else if (val == root->val)
        root->count++;
    else
        root->right = insert(root->right, val);
    return root;
}
bool search(BSTNode *root, int val) {
    if (root == nullptr)
        return false;
    else if (val < root->val)
        return search(root->left, val);
    else if (val == root->val)
        return true;
    else
        return search(root->right, val);
}




void lowDisplayBST(BSTNode* root){
    if(root == nullptr) return;
    queue<BSTNode*> q({root, nullptr});
    while(q.size()){
        BSTNode* temp = q.front();
        q.pop();
        if(temp == nullptr){
            cout << endl;
            if(q.size()) q.push(nullptr);
            continue;
        }
        cout << temp->val << " ";
        if(temp->left != nullptr) q.push(temp->left);
        if(temp->right != nullptr) q.push(temp->right);
    }
}

int main() { 
    BSTNode* root = nullptr;
    vector<int> nums = {1,2,3,4,5};
    for(auto num:nums)
        root = insert(root, num);
    lowDisplayBST(root);
    return 0; 
}