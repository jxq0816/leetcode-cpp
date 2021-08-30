//
// Created by jiangxingqi on 2021/8/29.
//
//Definition for singly-linked list.
#include <iostream>
#include <string>
#include <vector>
using namespace std;
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* insertionSortList(ListNode* head) {
        if(head == nullptr){
            return nullptr;
        }
        ListNode* dummyHead=new ListNode(0);
        dummyHead->next=head;
        ListNode* lastSorted=head;
        ListNode* curr=head->next;
        while (curr!= nullptr){
            if(lastSorted->val<=curr->val){
                lastSorted=lastSorted->next;
            }else{
                ListNode* pre=dummyHead;
                while(pre->next->val<=curr->val){
                    pre=pre->next;
                }
                lastSorted->next=curr->next;
                curr->next=pre->next;
                pre->next=curr;
            }
            curr=lastSorted->next;
        }
        return dummyHead->next;
    }
};
int main() {
    Solution solution;
    ListNode* head=new ListNode(4);
    ListNode* node=new ListNode(2);
    ListNode* node2=new ListNode(1);
    ListNode* node3=new ListNode(3);
    node3->next=nullptr;
    node2->next=node3;
    node->next=node2;
    head->next=node;
    ListNode* rs=solution.insertionSortList(head);
    while(rs){
        cout << rs->val<<',';
        rs=rs->next;
    }
    cout<<endl;
    return 0;
}