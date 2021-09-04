//
// Created by jiangxingqi on 2021/9/2.
//
//Definition for singly-linked list.
#include <iostream>
#include <vector>
#include<set>
using namespace std;
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        set<ListNode*> visited;
        while(head!= nullptr){
            if(visited.count(head)){
                return head;
            }
            visited.insert(head);
            head=head->next;
        }
        return nullptr;
    }
};