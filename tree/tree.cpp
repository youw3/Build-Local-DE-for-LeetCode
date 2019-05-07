#include <iostream>
#include <vector>
#include <queue>
#include <string>
#include <algorithm>
#include <set>
#include <stack>
#include <iterator>


using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

TreeNode* construct_tree(vector<string> &data, int index)
{
    TreeNode* pNode = NULL;

    if(index < data.size() && data[index] != "#")  //数组中"#" 表示该节点为空
    {
        pNode = new TreeNode(stoi(data[index]));
        pNode->left = construct_tree(data, 2 * index + 1);  //将二叉树按照层序遍历, 依次标序号, 从0开始
        pNode->right = construct_tree(data, 2 * index + 2);
    }
    return pNode;
}

TreeNode* Tree(vector<string> &data) {
    return construct_tree(data, 0);
}


void level_order(TreeNode* root) {
    if(root==NULL) return;
    TreeNode* p = root;
    queue<TreeNode*> q;
    q.push(p);
    while(!q.empty()) {
        p = q.front();
        q.pop();
        cout<<p->val<<endl;
        if(p->left) {
            q.push(p->left);
        }
        if(p->right) {
            q.push(p->right);
        }
    }
}
// write your function of tree

void PostorderTravel(TreeNode* root) {
    cout << "PostorderTravel: ";
    if (root == NULL)
        return;
    TreeNode* tree = root;
    stack<TreeNode*> stk1, stk2;
    stk1.push(tree);
    while (stk1.empty() == false) {
        tree = stk1.top();
        stk1.pop();
        stk2.push(tree);
        if (tree->left)
            stk1.push(tree->left);
        if (tree->right)
            stk1.push(tree->right);
    }

    while (stk2.empty() == false) {
        cout << stk2.top()->val << " ";
        stk2.pop();
    }
    cout << endl;
}

void fun(TreeNode* root, vector<int> &v) {
    if(!root) return;
    fun(root->left, v);
    v.push_back(root->val);
    fun(root->right, v);
}

TreeNode* construct(vector<int>&v, int i) {
    if(i<v.size()) {
        TreeNode* t = new TreeNode(v[i]);
        t->right = construct(v, i+1);
        return t;
    }
}

TreeNode* fun(vector<int>& nums, int start, int end) {
    if(start>end) return NULL;
    int middle = start+(end-start)/2;
    TreeNode* root = new TreeNode (nums[middle]);
    root->left = fun(nums, start, middle-1);
    root->right = fun(nums, middle+1, end);
    return root;
}

TreeNode* sortedArrayToBST(vector<int>& nums) {
    return fun(nums, 0, nums.size()-1);
}


int main() {
    vector<int>v1={-10,-3,0,5,9};
    sortedArrayToBST(v1);
}