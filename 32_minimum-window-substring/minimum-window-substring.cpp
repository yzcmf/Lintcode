/*
@Copyright:LintCode
@Author:   zhouyx
@Problem:  http://www.lintcode.com/problem/minimum-window-substring
@Language: C++
@Datetime: 16-09-26 23:38
*/

class Solution {
public:
    string minWindow(string S, string T) {
        if (T.size() > S.size()) return "";
        string res = "";
        int left=0,count=0,minLen=S.size()+1;
        map<char,int>ht;
        //我们最开始先扫描一遍T，把对应的字符及其出现的次数存到哈希表中。
        for (int i = 0; i < T.size(); i++) {
            // if (ht.find(T[i]) != ht.end()) ht[T[i]]++;
            // else ht[T[i]] = 1;
             ht[T[i]]++;
        }
        
        for (int right = 0; right < S.size(); right++) {
            //然后开始遍历S，遇到T中的字符，就把对应的哈希表中的value减一
            if (ht.find(S[right]) != ht.end()) {
                ht[S[right]]--;
                //Hash table's value is not less than 0
                //If the char in T is not less than 0, means it belongs to T
                //Thus we count the char for once;
                if (ht[S[right]] >= 0) count++;
                //直到包含了T中的所有的字符。
                while (count == T.size()) {
                    //纪录一个字串并更新最小字串值
                    if (right - left + 1 < minLen) {
                        minLen = right - left + 1;
                        res = S.substr(left, minLen);
                    }
                    //如果某个在T中的字符出现的次数大于哈希表中的value，
                    //则也可以跳过该字符。
                    if (ht.find(S[left]) != ht.end()) {
                        ht[S[left]]++;
                        if (ht[S[left]] > 0) count--;
                    }
                    //将子窗口的左边界向右移，略掉不在T中的字符
                    left++;
                }
            }
        }
        return res;
    }
};
//http://www.cnblogs.com/grandyang/p/4340948.html