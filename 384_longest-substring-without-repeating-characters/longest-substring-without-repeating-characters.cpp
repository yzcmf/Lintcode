/*
@Copyright:LintCode
@Author:   zhouyx
@Problem:  http://www.lintcode.com/problem/longest-substring-without-repeating-characters
@Language: C++
@Datetime: 16-09-23 13:17
*/

// -- LTE
// class Solution {
// public:
//     /**
//      * @param s: a string
//      * @return: an integer 
//      */
//     int lengthOfLongestSubstring(string s) {
//         // write your code here
//         //map<char,int>ht;
//         //ht[s[i]] =1; -- mark as existed for each element in s;
//         //ht[s[i]]++; -- mark for the frequence for each element;
//         //map<char,bool>ht;-- mark as existed for each element in s;
        
//         if(s.empty()) return 0;
//         map<char,int>ht;
//         int max_len = 1;
        
//         for(int i=0;i<s.size();i++)
//         ht[s[i]] =1;
        
        
//         for(int i=0;i<s.size();i++)
//         {
//             int j=i;
//             while(j<s.size()) 
//             {
//             if(ht[s[j]] == 0) break;
//             ht[s[j]]=0;
//             j++;
//             }
//             for(int k=i;k<j;k++) ht[s[k]]=1;
//             max_len=max(max_len,j-i);
//         }
        
//         return max_len;
//     }
// };
class Solution {
public:
    /**
     * @param s: a string
     * @return: an integer 
     */
    int lengthOfLongestSubstring(string s) {
        // write your code here
        int i=0,j=0;
        int max_len=0;
        map<char,bool>ht;//false by default;
        
        while((i<s.size()) && (j<s.size()))
        {
            if(ht[s[j]] == false)//s[j] has not occurred in S[i..j-1]
            {
                ht[s[j]] = true;
                max_len = max(max_len,j-i+1);
                j++;
            }
            else if(ht[s[j]] == true)//s[j] has occurred in S[i..j-1]
            {
              ht[s[i]] = false;        
              //max_len = max(max_len,j-i);
              i++;    
            }
        }
        return max_len;
    }
};