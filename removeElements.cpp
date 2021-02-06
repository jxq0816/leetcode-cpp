//
// Created by jiangxingqi on 2021/2/6.
//

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
        ListNode* sentinel=new ListNode(0);
        sentinel->next=head;
        ListNode* pre=sentinel;
        ListNode* toDelete = nullptr;
        while(head){
            if(head->val==val){
                toDelete=head;
                pre->next=head->next;

                head=head->next;
                continue;
            }
            pre=head;
            head=head->next;
            if(toDelete!= nullptr){
                delete toDelete;
                toDelete=nullptr;
            }
        }

        return sentinel->next;
    }
};