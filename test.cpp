#include <iostream>
#include <vector>
#include <stack>
#include <set>
#include <map>
#include <unordered_set>

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

template <typename T>
void print_2class_vector(vector<vector<T>>& t2){
    for(int i=0; i<t2.size(); ++i) {
        print_vector(t2[i]);
    }
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
vector<int> spiralOrder(vector<vector<int>>& matrix) {
    if(matrix.size()==0) return {};
    vector<int> result;
    int m = matrix.size();
    int n = matrix[0].size();
    int l=0, r=n-1, u=0, d=m-1;
    int begin=0;
    while(begin<m*n) {
        for(int i=l; i<=r; ++i) {
            result.push_back(matrix[u][i]);
            begin++;
        }
        if(begin==m*n) return result;
        u++;
        for(int i=u; i<=d; ++i) {
            result.push_back(matrix[i][r]);
            begin++;
        }
        if(begin==m*n) return result;
        r--;
        for(int i=r; i>=l; --i) {
            result.push_back(matrix[d][i]);
            begin++;
        }
        if(begin==m*n) return result;
        d--;
        for(int i=d; i>=u; --i) {
            result.push_back(matrix[i][l]);
            begin++;
        }
        if(begin==m*n) return result;
        l++;
    }
    return result;
}

int main() {
    vector<vector<int>> matrix = {
            {1,2,3,4},{5,6,7,8},{9,10,11,12}
    };
    vector<int>result = spiralOrder(matrix);
    print_vector(result);
}