/*
@Copyright:LintCode
@Author:   zhouyx
@Problem:  http://www.lintcode.com/problem/rotate-image
@Language: C++
@Datetime: 16-09-27 06:35
*/

/*
对于90度的翻转有很多方法，一步或多步都可以解，我们先来看一种直接的方法，对于当前位置，计算旋转后的新位置，然后再计算下一个新位置，第四个位置又变成当前位置了，所以这个方法每次循环换四个数字，如下所示：

1  2  3               7  2  1           7  4  1

4  5  6      -->      4  5  6　　 -->   8  5  2　　

7  8  9               9  8  3　　　　　 9  6  3
*/
//http://fisherlei.blogspot.com/2013/01/leetcode-rotate-image.html
//diagonal(\) mirror : swap(matrix[i][j],matrix[n-1-i][n-1-j]);
//Anti-diagonal(/) mirror : swap(matrix[i][j],matrix[n-1-j][n-1-i]);
//Horizontal(-) mirror: swap(matrix[i][j],matrix[n-1-i][j]);
//Vertical(|) mirror: swap(matrix[i][j],matrix[i][n-1-j]);
//90 degree(clockwise) mirror:swap(matrix[i][j],matrix[n-1-j][i]);
//90 degree(anti-clockwise) mirror:swap(matrix[i][j],matrix[j][n-1-i]);

class Solution {
public:
    /**
     * @param matrix: A list of lists of integers
     * @return: Void
     */
    void rotate(vector<vector<int>> &matrix) {
        // write your code here
        int n = matrix.size();
        //i<n/2; -- using only half is enough;
        for(int i=0;i<n;i++)
        {
            // j is for the circle;
            for(int j=i;j<n-1-i;j++)
            {
                int temp = matrix[i][j];
                matrix[i][j] = matrix[n-1-j][i];
                matrix[n-1-j][i] = matrix[n-1-i][n-1-j];
                matrix[n-1-i][n-1-j] = matrix[j][n-1-i];
                matrix[j][n-1-i] = temp;
            }
        }
        
        return; 
    }
};


// class Solution{
// public:
//     /**
//      * @param matrix: A list of lists of integers
//      * @return: Void
//      */
//     void rotate(vector<vector<int>> &matrix) {
//         int n = matrix.size();
//         // Anti-diagonal mirror.
//         for (int i=0;i<n;i++) {
//             for (int j=0;j<n-i;j++) {
//                 swap(matrix[i][j], matrix[n-1-j][n-1-i]);
//             }
//         }
//         // Horizontal mirror.
//         for (int i=0;i<n/2;i++) {
//             for (int j=0;j<n;j++) {
//                 swap(matrix[i][j], matrix[n-1-i][j]);
//             }
//         }
//     }
// };
//http://fisherlei.blogspot.com/2013/01/leetcode-rotate-image.html