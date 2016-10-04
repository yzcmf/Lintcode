/*
@Copyright:LintCode
@Author:   zhouyx
@Problem:  http://www.lintcode.com/problem/graph-valid-tree
@Language: C++
@Datetime: 16-09-22 04:31
*/

//Good reference:http://www.cnblogs.com/grandyang/p/5257919.html
//Taken from:http://blog.csdn.net/pointbreak1/article/details/48796691
class Solution{  
public:  
    bool validTree(int n, vector<vector<int>>& edges) {  
        vector<int> root(n, -1);  
        for(int i = 0; i < edges.size(); i++) {  
            int root1 = find(root, edges[i][0]);  
            int root2 = find(root, edges[i][1]);  
            if(root1 == root2)  
                return false;  
            root[root1] = root2;  
        }  
        return edges.size() == n - 1;  
    }  
      
    int find(vector<int> &root, int e) {  
        if(root[e] == -1)  
            return e;  
        else  
            find(root, root[e]);  
    }  
};  