#include <iostream>
#include <vector>
#include <unordered_map>
#include <stack>
#include <set>
#include <map>

using namespace std;

template <typename T>
void print_vector(vector<T>& t) {
    if(t.empty()) {
        cout<<"[]"<<endl;
        return;
    }
    cout<<'[';
    for(int i=0; i<t.size()-1; ++i) {
        cout<< t[i]<< ",";
    }
    cout<<t[t.size()-1]<<']'<<endl;
}

struct ListNode{
    int val;
    ListNode *next;
    ListNode(int x): val(x), next(NULL){}
};

void addNode(ListNode *head, int val) {
    ListNode *node = new ListNode(val);
    if (!head) {
        head = node;
    }
    else {
        ListNode * temp = head;
        while(temp->next) {
            temp=temp->next;
        }
        temp->next=node;
    }
}

void printList(ListNode *head) {
    ListNode* temp = head;
    if(temp==NULL)
        cout<<"empty list"<<endl;
    else {
        cout<<temp->val;
        temp=temp->next;
        while(temp!=NULL) {
            cout<<"->"<<temp->val;
            temp=temp->next;
        }
        cout<<endl;
    }
}

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


//add your function
int search(vector<int>& nums, int target) {

}


int main() {
    
}