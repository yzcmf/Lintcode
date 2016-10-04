/*
@Copyright:LintCode
@Author:   zhouyx
@Problem:  http://www.lintcode.com/problem/merge-intervals
@Language: C++
@Datetime: 16-09-15 02:54
*/

/**
 * Definition of Interval:
 * classs Interval {
 *     int start, end;
 *     Interval(int start, int end) {
 *         this->start = start;
 *         this->end = end;
 *     }
 */
class Solution {
public:
    /**
     * @param intervals: interval list.
     * @return: A new interval list.
     */
    struct comp{
        bool operator()(const Interval &a , const Interval &b) const
        {
            return a.start<b.start;
        }
    };  
    
    vector<Interval> merge(vector<Interval> &intervals) {
        // write your code here
        sort(intervals.begin(),intervals.end(),comp());
        vector<Interval> res;
        for(int i=0;i<intervals.size();i++)
        {
            //No-overlap;
            if(res.empty() || res.back().end < intervals[i].start)
            res.push_back(intervals[i]);
            //Over-lap;
            else
            {
              res.back().end = max(intervals[i].end,res.back().end);
            }
        }
        return res;
    }
};