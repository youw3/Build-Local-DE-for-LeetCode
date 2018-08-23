//
// Created by wei on 2018/8/14.
//

#include <iostream>
#include <vector>
#include <queue>
#include <string>
#include <algorithm>


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


int numTrees(int n) {
    vector<int> f(n+1, 0);

    f[0]=1;
    f[1]=1;
    for(int i=2; i<=n; ++i) {
        for (int k=1; k<=i; ++k) {
            f[i] += f[i-k] * f[k-1];
        }
    }
    return f[n];
}


// write your function of tree

int main() {
    cout<<numTrees(3)<<endl;

//    vector<string> s = {"1", "2", "3", "4", "5", "#", "7"};
//    TreeNode* btree = construct_tree(s, s.size());
}