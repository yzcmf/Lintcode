/*
@Copyright:LintCode
@Author:   zhouyx
@Problem:  http://www.lintcode.com/problem/insert-interval
@Language: C++
@Datetime: 16-09-15 21:19
*/

/**
 * Definition of Interval:
 * class Interval {
 * public:
 *     int start, end;
 *     Interval(int start, int end) {
 *         this->start = start;
 *         this->end = end;
 *     }
 * }
 */
class Solution {
public:
    /**
     * Insert newInterval into intervals.
     * @param intervals: Sorted interval list.
     * @param newInterval: new interval.
     * @return: A new interval list.
     */
    vector<Interval> insert(vector<Interval> &intervals, Interval newInterval) {
        // write your code here
        vector<Interval> res;
        bool isInsert = false;
        
        for(int i=0;i<intervals.size();i++)
        {
            // already insert newInterval
            if(isInsert) {  
                res.push_back(intervals[i]);
                continue;
            }
            
            // insert newInterval before current interval
            if(newInterval.end < intervals[i].start) {  
                res.push_back(newInterval);
                res.push_back(intervals[i]);
                isInsert = true;
                continue;
            }
            
            // newInterval after current interval
            if(newInterval.start > intervals[i].end)
            res.push_back(intervals[i]);
            
            // combine newInterval with current interval
            if(newInterval.start<=intervals[i].end && intervals[i].start<=newInterval.end) {
                newInterval.start = min(newInterval.start, intervals[i].start);
                newInterval.end = max(newInterval.end, intervals[i].end);
                continue;
            }
            
        }
        
        if(!isInsert) res.push_back(newInterval);//Handle the ending case;
        return res;
    }
};