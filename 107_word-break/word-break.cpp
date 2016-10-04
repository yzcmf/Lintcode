/*
@Copyright:LintCode
@Author:   zhouyx
@Problem:  http://www.lintcode.com/problem/word-break
@Language: C++
@Datetime: 16-10-01 09:54
*/

/*
看到这题第一反应是DFS枚举查找，直到“探”到string尾部则算成功。
但题目并不要求给出是如何break的，而只要判断是否能break。
对这类判断“是”与“否”的可以用DFS暴力解决的题，
可以尝试用DP做book keeping中间判断状态，避免DFS的反复搜索。
比如这题，可以用一个数组DP记录S[0:i]是否能break。

DP[i]：S[0:i-1]是否能被break。例如DP[1]表示s[0]是否能被break。
DP[0] = true
DP[i] = true if and only if:
1. 存在一个i-1>=k>=0，使s[k:i-1]存在于dict中。
2. s[0: k-1]可以被break，即DP[k] = true。
*/
class Solution {
public:
    /** * @param s: A string s * @param dict: A dictionary of words dict */
    bool wordBreak(string s, unordered_set<string> &dict) {
        // write your code here
        int len=s.size();
        if(len==0) return true;
        if(dict.size()==0) return false;
        
        int maxLen=0;
        for(string str:dict)
        if(str.size()>maxLen) 
        maxLen=str.size();

        vector<bool> res(len+1,false);
        res[0]=true;//suppose the first one is true;
        //res[i]:the s[0:i-1] can be broken;
        
        for(int i=1;i<=len;i++){
            for(int j=i-1;j>=0;j--){
                if(i-j>maxLen) break;
                bool flag= res[j] && dict.find(s.substr(j,i-j))!=dict.end();
                if(flag){
                    res[i]=true;//s[0:j-1]可以被break, 即res[i] = true;
                    break;
                }
            }
        }
        return res[len];
    }
};