/*
@Copyright:LintCode
@Author:   zhouyx
@Problem:  http://www.lintcode.com/problem/first-bad-version
@Language: C++
@Datetime: 16-09-22 00:07
*/

/**
 * class SVNRepo {
 *     public:
 *     static bool isBadVersion(int k);
 * }
 * you can use SVNRepo::isBadVersion(k) to judge whether 
 * the kth code version is bad or not.
*/
class Solution {
public:
    /**
     * @param n: An integers.
     * @return: An integer which is the first bad version.
     */
    int findFirstBadVersion(int n) {
        // write your code here
        
        int start = 1 ,end = n;
        
        while(start + 1 <end)
        {
            int mid = (start + end)/2;
            
            if(SVNRepo::isBadVersion(mid)) end = mid;
            else
            start = mid;
        }
        
        if(SVNRepo::isBadVersion(start)) return start;
        else 
        return end;
    }
};
