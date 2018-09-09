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

ListNode* deleteDuplication(ListNode* pHead)
{
    if(!pHead||!pHead->next) return pHead;
    ListNode dummy(-1);
    ListNode* prev = &dummy;
    prev->next = pHead;
    ListNode* cur = pHead;
    while(cur->next) {
        if(cur->val==cur->next->val) {
            int red_value = cur->val;
            while(cur&&red_value==cur->val) {
                ListNode* tmp = cur;
                cur = cur->next;
                delete tmp;
            }
            prev->next = cur;
            if(!cur) {
                return pHead;
            }
        } else {
            prev = cur;
            cur = cur->next;
        }
    }
    return dummy.next;
}
//add your function of list

int main() {
    ListNode *l1 = new ListNode(3);
    addNode(l1, 3);
    printList(deleteDuplication(l1));
}