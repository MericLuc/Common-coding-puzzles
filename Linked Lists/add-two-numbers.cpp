/*!
 * @description : You are given two non-empty linked lists 
 * representing two non-negative integers. 
 * The digits are stored in reverse order, and each of their nodes 
 * contains a single digit. 
 * Add the two numbers and return the sum as a linked list.
 */

// You may assume the two numbers do not contain any leading zero, except the number 0 itself.
 *

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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int       curSum(0), carry(0);
        ListNode* curNode(nullptr), *newNode(nullptr), *frontNode(nullptr);
        while ( l1 || l2 ) {
            curSum = carry;
            
            if ( l1       ) { curSum += l1->val; l1 = l1->next;   } 
            if ( l2       ) { curSum += l2->val; l2 = l2->next;   }
            
            newNode = new ListNode(curSum%10);
            
            if ( !curNode ) { frontNode     = newNode; }
            else            { curNode->next = newNode; }
            
            curNode = newNode;
            carry   = curSum/10;
        }
        
        if ( carry ) { curNode->next = new ListNode(carry, 0); }
        return frontNode;
    }
};