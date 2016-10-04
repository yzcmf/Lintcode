/*
@Copyright:LintCode
@Author:   zhouyx
@Problem:  http://www.lintcode.com/problem/flatten-list
@Language: C++
@Datetime: 16-09-13 08:09
*/

/**
 * // This is the interface that allows for creating nested lists.
 * // You should not implement it, or speculate about its implementation
 * class NestedInteger {
 *   public:
 *     // Return true if this NestedInteger holds a single integer,
 *     // rather than a nested list.
 *     bool isInteger() const;
 *
 *     // Return the single integer that this NestedInteger holds,
 *     // if it holds a single integer
 *     // The result is undefined if this NestedInteger holds a nested list
 *     int getInteger() const;
 *
 *     // Return the nested list that this NestedInteger holds,
 *     // if it holds a nested list
 *     // The result is undefined if this NestedInteger holds a single integer
 *     const vector<NestedInteger> &getList() const;
 * };
 */
class Solution {
public:
    // @param nestedList a list of NestedInteger
    // @return a list of integer
    vector<int> flatten(vector<NestedInteger> &nestedList) {
        // Write your code here
        vector<int> res;
        //Using auto make sure there is an ending
        //No need to know what the length is -- Using auto;
        for(auto node : nestedList)
        {
            if(node.isInteger())
              res.push_back(node.getInteger());
            else
            {
               vector<NestedInteger> sub_list = node.getList(); 
               auto temp = flatten(sub_list);
               res.insert(res.end(),temp.begin(),temp.end());
            }
        }
        return res;
    }
};