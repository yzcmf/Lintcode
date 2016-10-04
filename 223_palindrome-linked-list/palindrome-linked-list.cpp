/*
@Copyright:LintCode
@Author:   zhouyx
@Problem:  http://www.lintcode.com/problem/palindrome-linked-list
@Language: C++
@Datetime: 16-09-25 21:32
*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
// class Solution {
// public:
//     /**
//      * @param head a ListNode
//      * @return a boolean
//      */
//     bool isPalindrome(ListNode* head) {
//         //Write your code here
//         //Method one : find the midpoint and compare the first half with the second half;
//         //Method two : (reverse the second half);compare with the first half;
//         //Method three : (stack) push the first half;pop and compared with the second half;
//         if(head == NULL || head->next == NULL) return true;
        
//         ListNode *slow = head, *fast = head;
//         stack <int> s;
//         s.push(head->val);
        
//         while(fast->next && fast->next->next)
//         {
//             slow = slow->next;
//             fast = fast->next->next;
//             s.push(slow->val);
//         }
//         //fast and slow pointers to the head at first:
//         //For even nodes:fast wil reach the last second node: fast->next->next == NULL;
//         //For odd nodes:fast will reach the last node:fast->next == NULL;
//         if(fast->next == NULL) s.pop();//odd node: This value is the middle value 
        
//         //For the odd nodes: slow now pointer to the middle(len/2+1) 
//         //For the even nodes: slow now pointer to the one (len/2) 
//         //slow->next will become the beginning of next part;
//         while(slow->next)
//         {
//             slow = slow->next;
//             int tmp = s.top();
//             s.pop();
//             if(tmp!=slow->val) return false;
//         }
//         return true;
//     }
// };

class Solution {
public:
    /**
     * @param head a ListNode
     * @return a boolean
     */
    bool isPalindrome(ListNode* head) {
        // Write your code here
    if(head == NULL || head->next == NULL) return true;  
     
    ListNode* fast = head , *slow =head;
    while (fast->next && fast->next->next)
    {
        fast = fast->next->next;
        slow = slow->next;
    }
     
    if(fast->next == NULL)  fast = slow->next; 
    // If the node is odd, skip the middle node;
    else 
      fast=slow->next;
    slow = head;// now fast is in the middle and slow is the head;

    // reverse the post-half nodes
    
    ListNode* secHead = NULL;
    
    while(fast)
    {
        ListNode* r = fast->next;
        fast->next =secHead;
        secHead = fast;
        fast =r;
    }
    
    //Comparsion the two-parts;
    fast = secHead;
    while(fast)
    {
        if(fast->val != slow->val) return false;
        fast=fast->next;
        slow=slow->next;
    }
    
    return true;
    }
};