/*
@Copyright:LintCode
@Author:   zhouyx
@Problem:  http://www.lintcode.com/problem/copy-list-with-random-pointer
@Language: C++
@Datetime: 16-09-21 02:01
*/

/**
 * Definition for singly-linked list with a random pointer.
 * struct RandomListNode {
 *     int label;
 *     RandomListNode *next, *random;
 *     RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
 * };
 */
// -- Space:O(1)
// -- Time :O(n)
class Solution {
public:
    /**
     * @param head: The head of linked list with a random pointer.
     * @return: A new head of a deep copy of the list.
     */
    RandomListNode *copyRandomList(RandomListNode *head) {
        // write your code here
        if(head == NULL) return NULL;
        
        RandomListNode * cur = head;
        
        //1.generate new List with node
        while(cur != NULL)
        {
            RandomListNode *newNode = new RandomListNode(cur->label);
            newNode->next = cur->next;
            cur->next = newNode;
            cur = cur->next->next;
        }
        //2. copy random
        cur = head;
        while(cur != NULL)
        {
            if(cur->random != NULL)
            {
                cur->next->random = cur->random->next;
            }
            cur = cur->next->next;
        }
        //3. split origianl and new List;
        RandomListNode *newHead = head->next;
        cur = head;
        while(cur!=NULL)
        {
            RandomListNode* newNode = cur->next;
            cur->next = cur->next->next;
            cur = cur->next;
            if(newNode->next != NULL)
            newNode->next = newNode->next->next;
        }
        return newHead;
    }
};

//http://www.kancloud.cn/kancloud/data-structure-and-algorithm-notes/73016