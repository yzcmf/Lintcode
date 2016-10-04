/*
@Copyright:LintCode
@Author:   zhouyx
@Problem:  http://www.lintcode.com/problem/letter-combinations-of-a-phone-number
@Language: C++
@Datetime: 16-09-23 01:41
*/

class Solution {
public:
    /**
     * @param digits A digital string
     * @return all posible letter combinations
     */
    vector<string>letterCombinations(string& digits) {
        // Write your code here
        vector<string>allSol;
        string Sol;
        if(digits.empty()) return allSol;
        string dict[] = {"abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
        letterCombinationsDFS(digits,dict,0,Sol,allSol);
        return allSol;
    }
    
    void letterCombinationsDFS(string digits, string dict[],int level, string Sol, 
                               vector<string>& allSol)
    {
        if(level == digits.size()) allSol.push_back(Sol);
        else
        {
            string s = dict[digits[level]-'2'];
            for(int i=0;i<s.size();i++)
            {
                Sol.push_back(s[i]);
                letterCombinationsDFS(digits,dict,level+1,Sol,allSol);
                Sol.pop_back();
            }
        }
        
    }
};