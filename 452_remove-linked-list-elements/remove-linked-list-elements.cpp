/*
@Copyright:LintCode
@Author:   zhouyx
@Problem:  http://www.lintcode.com/problem/remove-linked-list-elements
@Language: C++
@Datetime: 16-09-13 05:37
*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    /**
     * @param head a ListNode
     * @param val an integer
     * @return a ListNode
     */
    // ListNode *removeElements(ListNode *head, int val) {
    //     // Write your code here
    //     if(head==NULL) return NULL;
    //     ListNode * dummy = new ListNode(0);
    //     dummy->next = head;
    //     ListNode * node = dummy;
    //     while(head->next && head)
    //     {
    //         if(val == head->val)
    //         {
    //             node->next = head->next;
    //         }
    //         else
    //         {
    //         node = node->next;
    //         }
    //         head = head->next;
    //     }
        
    //     //When the last one is the val and at this time
    //     //The head->next is NULL;
    //     if(val == head->val)
    //     {
    //      node->next = NULL;
    //     }

    //     return dummy->next;
    // }
    
    //
    ListNode *removeElements(ListNode *head, int val) {
    
        if(head == NULL) return NULL;
        ListNode * dummy = new ListNode(0);
        dummy->next = head;
        head = dummy;
        
        while(dummy->next)
        {
            if(val == dummy->next->val)
                dummy->next = dummy->next->next;
            else
                dummy = dummy->next;
        }
        
        return head->next;
        
    }
};