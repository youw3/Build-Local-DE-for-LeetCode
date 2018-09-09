//
// Created by wei on 2018/8/14.
//

#include <iostream>
#include <vector>
#include <queue>
#include <string>
#include <algorithm>
#include <set>


using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

TreeNode* construct_tree(vector<string> dat, int len) {
    TreeNode* root = NULL;
    int index = 0;
    if (len>0) {
        root = new TreeNode(stoi(dat[index]));
    } else {
        return NULL;
    }

    queue<TreeNode*> nodes;
    nodes.push(root);
    index++;

    while(index < len) {
        if(!nodes.empty()) {
            TreeNode* root = nodes.front();
            if(index<len) {
                if(dat[index] != "#") {
                    root->left = new TreeNode(stoi(dat[index]));
                    nodes.push(root->left);
                }
                index++;
            }
            if(index<len) {
                if(dat[index] != "#") {
                    root->right = new TreeNode(stoi(dat[index]));
                    nodes.push(root->right);
                }
                index++;
            }
            nodes.pop();
        }
    }
    return root;
}



// write your function of tree

int main() {
    vector<int>pre = {1,2,4,7,3,5,6,8};
    vector<int>vin = {4,7,2,1,5,3,8,6};
}