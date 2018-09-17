#include <iostream>
#include <vector>
#include <queue>
#include <string>
#include <algorithm>
#include <set>
#include <stack>


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


vector<vector<int>>allRes;
vector<int> tmp;

void dfsFind(TreeNode* node, int left){
    tmp.push_back(node->val);
    if(left-node->val == 0 && !node->left && !node->right)
        allRes.push_back(tmp);
    else {
        if(node->left) dfsFind(node->left, left-node->val);
        if(node->right) dfsFind(node->right, left-node->val);
    }
    tmp.pop_back();
}



vector<vector<int>> FindPath(TreeNode* root,int expectNumber) {
    if(root)
        dfsFind(root, expectNumber);
    return allRes;
}

template <typename T>
void print_vector(vector<T>& t) {
//    cout<<'[';
    for(int i=0; i<t.size()-1; ++i) {
        cout<< t[i]<< " ";
    }
    cout<<t[t.size()-1]<<endl;
}

int main() {
    vector<string> v={"6","3","1","#","#","4","1","#"
    ,"#","#","#","#","#","#","1"};
//    vector<string> v={"5","#","1","#","#","2","#"};
    TreeNode* t = Tree(v);
    vector<vector<int>> result=FindPath(t, 9);
    for(int i=0; i<result.size(); ++i) {
        print_vector(result[i]);
    }
}