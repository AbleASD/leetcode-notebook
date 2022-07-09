/*
 * @Author: Able 
 * @Date: 2022-07-05 13:17:48 
 * @Last Modified by: Able
 * @Last Modified time: 2022-07-05 13:37:00
 * @link https://leetcode.cn/problems/my-calendar-i/ @endlink
 */

#include "bits/stdc++.h"
using namespace std;

class MyCalendar {   
public: 
    set<pair<int, int>> booked;
public:
    MyCalendar() {
        
    }
    
    bool book(int start, int end) {
        auto it = booked.lower_bound({end, 0}); // 下一个任务开始时间大于等结束时间
        if (it == booked.begin() || (--it)->second <= start) {
            booked.emplace(start, end); // 最早的任务或者 上一个任务的结束时间小于等于当前任务开始时间
            return true;
        }
        return false;
    }
};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(start,end);
 */