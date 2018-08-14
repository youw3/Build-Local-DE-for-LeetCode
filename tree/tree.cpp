//
// Created by wei on 2018/8/14.
//

#include <iostream>
#include <vector>
#include <queue>
#include <string>


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
    vector<string> s = {"3", "9", "20", "#", "#", "15", "7"};
    TreeNode* btree = construct_tree(s, s.size());
}