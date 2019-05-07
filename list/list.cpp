//
// Created by wei on 2018/8/14.
//

#include <iostream>
#include <vector>

using namespace std;

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


//add your function of list
