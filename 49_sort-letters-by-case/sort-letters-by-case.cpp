/*
@Copyright:LintCode
@Author:   zhouyx
@Problem:  http://www.lintcode.com/problem/sort-letters-by-case
@Language: C++
@Datetime: 16-09-27 07:59
*/

class Solution {
public:
    /** 
     * @param chars: The letters array you should sort.
     */
    void sortLetters(string &letters) {
        // write your code here
        if(letters.empty()) return;
        int left = 0;
        int right = letters.size()-1;
        while(left<right)
        {
            while(islower(letters[left]))left++;
            while(isupper(letters[right]))right--;
            if(left<right)
            swap(letters[left++],letters[right--]);
        }
    }
};
