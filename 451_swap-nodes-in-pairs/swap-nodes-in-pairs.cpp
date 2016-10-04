/*
@Copyright:LintCode
@Author:   zhouyx
@Problem:  http://www.lintcode.com/problem/swap-nodes-in-pairs
@Language: C++
@Datetime: 16-09-16 10:31
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
     * @return a ListNode
     */
    ListNode* swapPairs(ListNode* head) {
        // Write your code here
        
        // -- Swap only the vals;
        ListNode*pre = head;
        ListNode*cur = head->next;
        
        while(cur && cur->next)
        {
            swap(pre->val,cur->val);
            pre = cur->next;
            cur = pre->next;
        }
        
        //Handle the ending case;
        if(cur)
        swap(pre->val,cur->val);
        
        return head;
        
    }
};