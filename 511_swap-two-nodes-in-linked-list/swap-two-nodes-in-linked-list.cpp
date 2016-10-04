/*
@Copyright:LintCode
@Author:   zhouyx
@Problem:  http://www.lintcode.com/problem/swap-two-nodes-in-linked-list
@Language: C++
@Datetime: 16-09-28 01:14
*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
// --TLE 
// class Solution {
// public:
//     /**
//      * @param head a ListNode
//      * @oaram v1 an integer
//      * @param v2 an integer
//      * @return a new head of singly-linked list
//      */
//     ListNode* swapNodes(ListNode* head, int v1, int v2) {
//         // Write your code here
//         //Lazy method : swap just the v1 and v2 values not move the node;
//         if(head == NULL || head->next == NULL) return head;
        
//         ListNode* dummy = new ListNode(0);
//         dummy->next = head;
        
//         ListNode* p1 = new ListNode(0);
//         ListNode* p2 = new ListNode(0);
//         p1->next = head;
//         p2->next = head;
        
//         while(p1->next && p1->next->val != v1)
//         {
//             p1 = p1->next; 
//         }
        
//         while(p2->next && p2->next->val != v2)
//         {
//             p2 = p2->next; 
//         }
        
//         if(p1->next == NULL || p2->next == NULL) return head;
//         if(p1->next == p2)
//         {
//             p1->next = p2->next;
//             p2->next = p1;
//         }
//         if(p2->next == p1)
//         {
//             p2->next = p1->next;
//             p1->next = p2;
//         }
//         ListNode* p1_n  = p1->next; 
//         ListNode* p2_n  = p2->next; 
//         ListNode* p1_a  = p1->next->next;
//         ListNode* p2_a  = p2->next->next;
        
//         p1->next  = p2_n;
//         p2_n->next = p1_a;
//         p2->next = p1_n;
//         p1_n->next = p2_a;
       
//         return dummy->next;
//     }
// };
/*
我们的思路是遍历整个链表，如果cur的下一个结点存在，且等于v1或v2中的一个，
此时如果p1为空，说明这是要交换的第一个结点，我们将p1指向这个结点，
然后讲pre指向cur，交换操作需要记录要交换的结点的前一个位置，然后继续遍历，
当又遇到一个和v1或v2相等的结点，此时我们就需要交换了，我们用p2指向这个结点，
然后用临时变量t指向下一个结点，此时我们需要判断cur和p1是相等，
相等的话说明p1和p2是相邻的，我们只需要把p2移到p1前面去，
如果不相等，说明p1和p2之间还有元素，那么我们交换p1和p2的位置即可，
最后返回dummy->next即可:
*/
class Solution {
public:
    /**
     * @param head a ListNode
     * @oaram v1 an integer
     * @param v2 an integer
     * @return a new head of singly-linked list
     */
    ListNode* swapNodes(ListNode* head, int v1, int v2) {
        // Write your code here
        ListNode * dummy = new ListNode(0);
        dummy->next = head;
        ListNode *pre = dummy,*cur = dummy,*p1=NULL,*p2=NULL;
        
        while(cur->next)
        {
            if(cur->next->val == v1 || cur->next->val == v2)
            {
                if(!p1)//此时如果p1为空，说明这是要交换的第一个结点，我们将p1指向这个结点
                {
                    p1 = cur->next;
                    pre = cur;
                }
                else//当又遇到一个和v1或v2相等的结点，此时我们就需要交换了
                {
                 ListNode*t = cur->next->next;    
                 p2 = cur->next;//我们用p2指向这个结点，然后用临时变量t指向下一个结点
                 pre->next = p2;
                 if(cur == p1)//判断cur和p1是相等，相等的话说明p1和p2是相邻的
                 {
                  p2->next = p1;       
                  p1->next =t;
                  //我们只需要把p2移到p1前面去
                 }
                 else//如果不相等，说明p1和p2之间还有元素，那么我们交换p1和p2的位置即可
                 {
                     p2->next = p1->next;
                     cur->next = p1;
                     p1->next = t;
                 }
                 return dummy->next;
                }
            }
            //继续遍历
            cur = cur->next;
        }
        return dummy->next;
    }
};

//Good reference: http://www.cnblogs.com/grandyang/p/5493999.html