/*
@Copyright:LintCode
@Author:   zhouyx
@Problem:  http://www.lintcode.com/problem/reorder-list
@Language: C++
@Datetime: 16-09-30 01:09
*/

/**
 * Definition of ListNode
 * class ListNode {
 * public:
 *     int val;
 *     ListNode *next;
 *     ListNode(int val) {
 *         this->val = val;
 *         this->next = NULL;
 *     }
 * }
 */
class Solution {
public:
    /**
     * @param head: The first node of linked list.
     * @return: void
     */
    void reorderList(ListNode *head) {
        // write your code here
        if (head == NULL || head->next == NULL) return;

        ListNode *first = head;
        int len= 0;
        while (first != NULL) {
            first = first->next;
            len++;
        }

        first = head;
        for (int i = 1; i < len - i; i++) {
            ListNode *beforeTail = first;
            for (int j = i; j < len - i; j++) {
                beforeTail = beforeTail->next;
            }

            ListNode *temp = first->next;
            first->next = beforeTail->next;
            first->next->next = temp;
            beforeTail->next = NULL;
            first = temp;
        }
        
        
        
    }
};


