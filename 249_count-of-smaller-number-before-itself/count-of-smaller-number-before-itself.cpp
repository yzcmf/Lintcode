/*
@Copyright:LintCode
@Author:   zhouyx
@Problem:  http://www.lintcode.com/problem/count-of-smaller-number-before-itself
@Language: C++
@Datetime: 16-09-30 09:17
*/

class Solution {
public:
   /**
     * @param A: An integer array
     * @return: Count the number of element before this element 'ai' is 
     *          smaller than it and return count number array
     */
    // 线段树，动态添加的意思，每次向线段树里面添加一个数，接着再查询一个区间
    // 有多少个数
    // 很巧妙，是动态的去做，不是做好再静态查找
    
    class TreeNode{
    public:
        TreeNode(int _start, int _end) :
            start(_start), end(_end), left(nullptr), right(nullptr),
            cnt(0) {}
    
        int start, end;
        TreeNode *left, *right;
        int cnt;
    };
    
    TreeNode *build(int start, int end){
        if (start > end) return nullptr;
        if (start == end) return new TreeNode(start, end);
        
        int mid = start + ((end - start) >> 1);
        
        auto root = new TreeNode(start, end);
        root->left = build(start, mid);
        root->right = build(mid + 1, end);
        
        return root;
    }
    
    void modify(TreeNode *root, int idx){
        if (root == nullptr) return;
        
        if (root->start == root->end && root->start == idx){
            ++(root->cnt);
            return;
        }
        
        int mid = root->start + ((root->end - root->start) >> 1);
        if (mid >= idx) modify(root->left, idx);
        else modify(root->right, idx);
        
        root->cnt = root->left->cnt + (root->right ? root->right->cnt : 0);
    }
    
    int query(TreeNode *root, int start, int end){
        if (root->end < start || root->start > end) return 0;
        if (root->start >= start && root->end <= end)
            return root->cnt;
            
        int mid = root->start + ((root->end - root->start) >> 1);
        if (mid >= end) return query(root->left, start, end);
        if (mid < start) return query(root->right, start, end);
        
        int leftRes = query(root->left, start, mid);
        int rightRes = query(root->right, mid + 1, end);
        
        return leftRes + rightRes;
    }
    
    // 这个题有超出范围的数据... 坑...
    vector<int> countOfSmallerNumberII(vector<int> &A) {
        // write your code here
        TreeNode *root = build(0, 20000);
        vector<int> res;
        
        for (auto n : A){
            auto cnt = query(root,0,n-1);
            res.push_back(cnt);
            modify(root,n);
        }
        
        return res;
    }
};
//common solution:http://www.cnblogs.com/EpisodeXI/p/4585770.html;

// class Solution {
// public:
//   /**
//      * @param A: An integer array
//      * @return: Count the number of element before this element 'ai' is 
//      *          smaller than it and return count number array
//      */
//     int lowbit(int n) {
//         return n & (-n);
//     }
    
//     int sum(vector<int> &c, int n) {
//         int sum = 0;
//         while (n > 0) {
//             sum += c[n];
//             n -= lowbit(n);
//         }
//         return sum;
//     }
    
//     void add(vector<int> &c, int i, int x) {
//         while (i < c.size()) {
//             c[i] += x;
//             i += lowbit(i);
//         }
//     }
    
//     vector<int> countOfSmallerNumberII(vector<int> &A) {
//         // write your code here
//         vector<int> c(A.size() + 1, 0);
//         vector<int> res(A.size()), B(A);
//         map<int, int> mp;
//         sort(B.begin(), B.end());
//         for (int i = 0; i < B.size(); ++i) {
//             mp[B[i]] = i + 1;
//         }
//         for (int i = 0; i < A.size(); ++i) {
//             res[i] = sum(c, mp[A[i]] - 1);
//             add(c, mp[A[i]], 1);
//         }
//         return res;
//     }
// };

//We could use the BS insertion method :Count of Smaller Number after itself;
//Tree-Array solutions: http://www.cnblogs.com/easonliu/p/4575645.html;
//Other solutions:https://github.com/kamyu104/LintCode/blob/master/C%2B%2B/count-of-smaller-number-before-itself.cpp