/*
@Copyright:LintCode
@Author:   zhouyx
@Problem:  http://www.lintcode.com/problem/reorder-array-to-construct-the-minimum-number
@Language: C++
@Datetime: 16-09-27 03:37
*/

class Solution {
public:
    /**
     * @param nums n non-negative integer array
     * @return a string
     */
    static bool comp(const int &i,const int &j) {
            return to_string(i) + to_string(j) < to_string(j) + to_string(i);
    }
    
    string minNumber(vector<int>& nums) {
        // Write your code here
        sort(nums.begin(), nums.end(),comp);
        string min_num;
        for (auto i : nums) min_num.append(to_string(i));
        int i = 0;
        while (i < min_num.size()-1 && min_num[i] == '0') i++;
        return min_num.empty() ? "0" : min_num.substr(i);
        
    }
};

//https://github.com/kamyu104/LintCode/blob/master/C++/reorder-array-to-construct-the-minimum-number.cpp