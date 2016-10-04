/*
@Copyright:LintCode
@Author:   zhouyx
@Problem:  http://www.lintcode.com/problem/merge-k-sorted-lists
@Language: C++
@Datetime: 16-10-01 08:00
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
/*
将每个list的最小节点放入一个 priority queue (min heap)中。
之后每从queue中取出一个节点，则将该节点在其list中的下一个节点插入，
以此类推直到全部节点都经过priority queue。
由于priority queue的大小为始终为k，而每次插入的复杂度是log k，
一共插入过nk个节点。时间复杂度为O(nklogk)，空间复杂度为O(k)。
*/
//http://en.cppreference.com/w/cpp/container/priority_queue
class Solution {
public:
//注意C++的STL中的priority queue默认是max heap，定义一个新的比较函数。
//将每个list的最小节点放入一个 priority queue (min heap)中。
    struct compNode {
        bool operator()(ListNode *p, ListNode *q) const {
            return p->val>q->val;
        }  
    };
    ListNode *mergeKLists(vector<ListNode *> &lists) {
        priority_queue<ListNode*, vector<ListNode*>, compNode> pq;
        //priority_queue<ListNode*, vector<ListNode*>, std::greater<int>> pq;
        ListNode *dummy = new ListNode(0), *tail = dummy;
        
        for(int i=0; i<lists.size(); i++) 
            if(lists[i]) pq.push(lists[i]);

        while(!pq.empty()) {
            tail->next = pq.top();
            tail = tail->next;
            pq.pop();
            if(tail->next) pq.push(tail->next);
        }
        
        return dummy->next;
    }
};

/*
类似merge sort，每次将所有的list两两之间合并，直到所有list合并成一个。
如果用迭代而非递归，则空间复杂度为O(1)。时间复杂度：
2n * k/2 + 4n * k/4 + ... + (2^x)n * k/(2^x) = nk * x
k/(2^x) = 1 -> 2^x = k -> x = log2(k)
所以时间复杂度为O(nklog(k))，与方法一相同。
*/
// class Solution {
// public:
//     /**
//      * @param lists: a list of ListNode
//      * @return: The head of one sorted list.
//      */
//     ListNode *mergeKLists(vector<ListNode*> &lists) {
//         // write your code here
//         if(lists.empty()) return NULL;
//         int end = lists.size()-1;
//         while(end>0) {
//             int begin = 0;
//             while(begin<end) {
//                 lists[begin] = mergeTwoLists(lists[begin], lists[end]);
//                 begin++;
//                 end--;
//             }
//         }
//         return lists[0];
//     }
    
//     ListNode *mergeTwoLists(ListNode *l1,ListNode *l2)
//     {
//          if(l1==NULL) return l2;
//          if(l2==NULL) return l1;
//          if(l1==NULL && l2==NULL) return NULL;
         
//          ListNode * dummy =new ListNode(0);
//          ListNode * p = dummy;
         
//          while(l1 && l2)
//          {
//              if(l1->val<l2->val) 
//               {
//               p->next=l1;
//               l1=l1->next;
//               }
//              else
//              {
//               p->next=l2;
//               l2=l2->next;
//              }
//              p=p->next;
//          }
//         p->next = l1 ? l1 : l2;
//         return dummy->next; 
//     }
// };
//http://bangbingsyb.blogspot.com/2014/11/leetcode-merge-k-sorted-lists.html
