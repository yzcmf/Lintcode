/*
@Copyright:LintCode
@Author:   zhouyx
@Problem:  http://www.lintcode.com/problem/string-to-integer-ii
@Language: C++
@Datetime: 16-09-30 08:38
*/

class Solution {
public:
    /**
     * @param str: A string
     * @return An integer
     */
    int atoi(string str) {
        // write your code here
        bool isNeg = true;
        unsigned long long ret = 0;
        
        int i=0;
        // skip leading white spaces
        while(str[i]==' ') i++;
        
        // first none white space char must be +- or digit
        if(!isdigit(str[i]) && str[i]!='+' && str[i]!='-') return 0;
        
        // for +-, next char must be digit
        if(str[i]=='+' || str[i]=='-') {
            if(!isdigit(str[i+1])) return 0;
            if(str[i]=='-') isNeg = false;
            i++;
        }
        
        while(isdigit(str[i])) {
            ret = ret*10 + (str[i] - '0');
            if(ret>(unsigned long long)INT_MAX)
                return isNeg ? INT_MAX : INT_MIN;
            i++;
        }
        return isNeg ? (int)ret : -(int) ret;
    }
};
//http://bangbingsyb.blogspot.com/2014/11/leetcode-string-to-integer-atoi.html
// class Solution {
// public:
//     int atoi(const char *str) {
//         bool isNeg = false;
//         unsigned long long ret = 0;
        
//         // skip leading white spaces
//         while(*str==' ') str++;
        
//         // first none white space char must be +- or digit
//         if(!isdigit(*str) && *str!='+' && *str!='-') return 0;
        
//         // for +-, next char must be digit
//         if(*str=='+' || *str=='-') {
//             if(!isdigit(*(str+1))) return 0;
//             if(*str=='-') isNeg = true;
//             str++;
//         }
        
//         while(isdigit(*str)) {
//             ret = ret*10 + (*str - '0');
//             if(ret>(unsigned long long)INT_MAX)
//                 return isNeg ? INT_MIN : INT_MAX;
//             str++;
//         }
//         return isNeg ? -(int)ret : (int) ret;
//     }
// };