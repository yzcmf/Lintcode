/*
@Copyright:LintCode
@Author:   zhouyx
@Problem:  http://www.lintcode.com/problem/space-replacement
@Language: C++
@Datetime: 16-09-16 07:50
*/

class Solution {
public:
    /**
     * @param string: An array of Char
     * @param length: The true length of the string
     * @return: The true length of new string
     */
    int replaceBlank(char string[], int length) {
        // Write your code here
        if(length == 0) return 0;
        int len=length;

        for(int i=0;i<length;i++)
        {
            if(string[i]==' ')
            len += 2;
        }
        
        int res = len;
        string[len] = '\0';
        len--;
        
        for(int i=length-1;i>=0;i--)
        {
            if(string[i] == ' ')
            {
                string[len--]='0';
                string[len--]='2';
                string[len--]='%';
            }
            else 
            string[len--]=string[i];
        }
        
        return res;
        
    }
};  