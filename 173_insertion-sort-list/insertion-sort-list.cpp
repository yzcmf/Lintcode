/*
@Copyright:LintCode
@Author:   zhouyx
@Problem:  http://www.lintcode.com/problem/insertion-sort-list
@Language: C++
@Datetime: 16-09-14 04:55
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
// -- My bubble sort solution for this problem;
// class Solution {
// public:
//     /**
//      * @param head: The first node of linked list.
//      * @return: The head of linked list.
//      */
//     ListNode *insertionSortList(ListNode *head) {
//         // write your code here
        
//         ListNode * p  = new ListNode(INT_MIN);
//         p->next = head;

//         while(p)
//         {
//         ListNode * l = p->next;
//         while(l)
//         {
//           if(p->val > l->val) 
//           swap(p->val,l->val);    
//           l = l->next;    
//         }
//         p = p->next;
//         }
        
//         return head;
//     }
// };

// -- Good reference insertion sort solution for this problem;
/*
拿出原list的头节点，用一个指针扫描新list直到找到插入位置，并插入。注意点：
1. 用dummy head来简化新list的头节点操作。
2. 由于插入节点需要依赖插入位置的前一节点。所以用指针p来查找新list节点时，
   始终用p->next来和要插入的节点比较，而不是用p来比较。
3. 注意当节点需要插入新list尾部的情况。
*/
class Solution {
public:
    ListNode *insertionSortList(ListNode *head) {
        ListNode *newHead = new ListNode(INT_MIN);
        //newHead list for storing the new values and using only from newHead->next;
        while(head) {
            ListNode *cur = head;//for the rest elements
            ListNode *p = newHead;//for the sort elements
            head = head->next;
            //Find the insertion position in the newHead list
            while(p->next && p->next->val<=cur->val) 
                p = p->next;
            //After the while loop: p->val < cur->val < p->next->val 
            
            // insert the cur between the p and p->next;
            cur->next = p->next;
            p->next = cur;
        }
      
        //Using only from newHead->next;
        head = newHead->next;
        //Delete the whole linkedlist from the newHead;
        delete newHead;
        return head;
    }
};