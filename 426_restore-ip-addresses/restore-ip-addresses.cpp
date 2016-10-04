/*
@Copyright:LintCode
@Author:   zhouyx
@Problem:  http://www.lintcode.com/problem/restore-ip-addresses
@Language: C++
@Datetime: 16-09-30 01:25
*/

/*
思路：
一个有效的IP地址由4个数字组成，
每个数字在0-255之间。
对于其中的2位数或3位数，不能以0开头。
所以对于以s[i]开头的数字有3种可能：
1. s[i]
2. s[i:i+1],s[i]!=0;
3. s[i:i+2],s[i]!=0,且s[i:i+2] <= 255
*/
class Solution {
public:
    /**
     * @param s the IP string
     * @return All possible valid IP addresses
     */
    vector<string> restoreIpAddresses(string s) {
        vector<string> ipComb;
        vector<string> ipNum;
        findIPAddr(s, 0, ipNum, ipComb);
        return ipComb;
    }
    
    void findIPAddr(string &s, int index, vector<string> &ipNum, vector<string> &ipComb) {
        if(ipNum.size()==4 && index==s.size()) {
                string ipAddr = ipNum[0];
                for(int i=1; i<4; i++) 
                    ipAddr += ("."+ipNum[i]);
                ipComb.push_back(ipAddr);
            return;
        }
        
        string curNum;
        for(int i=index; i<s.size() && i<index+3; i++) {
            curNum.push_back(s[i]);
            if(isValidNum(curNum)) {
                ipNum.push_back(curNum);
                findIPAddr(s, i+1, ipNum, ipComb);
                ipNum.pop_back();
            }
        }
    }
    
    bool isValidNum(string s) {
        if(s.size()==1) return true;
        if(s.size()==2 && s[0]!='0') return true;
        if(s.size()==3 && s[0]!='0'&& stoi(s)<=255) return true;
        return false;
    }
    
};
//Good reference: http://bangbingsyb.blogspot.com/2014/11/leetcode-restore-ip-addresses.html