/*!
 * @description : Merge two sorted linked-lists
 */

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        if ( !l1 && !l2 ) { return nullptr; }
        if ( !l1 )        { return l2;      }
        if ( !l2 )        { return l1;      }
        
        ListNode* ret, *head;
        if (l1->val < l2->val) { ret = l1; l1 = l1->next; } 
        else                   { ret = l2; l2 = l2->next; }
        head = ret;
        
        while ( l1 && l2 ) {
            if ( l1->val <= l2->val ) { ret->next = l1; l1 = l1->next; }
            else                      { ret->next = l2; l2 = l2->next; }
            ret = ret->next;
        }
        
        ret->next = l1 ? l1 : l2;
        
        return head;
    }
};