

/*
Given an array of meeting time intervals consisting of start and end times [[s1,e1],[s2,e2],...] 

find the minimum number of conference rooms required.

For example,
Given [[0, 30],[5, 10],[15, 20]],
return 2.
*/

//Related topics: Heap, Greedy, Sort

//Using priority queue (12 ms)
class Solution {
public:
    int minMeetingRooms(vector<Interval>& intervals) {
        auto cmp = [](const Interval& a, const Interval& b) {
            return a.start < b.start;
        };
        
        sort(intervals.begin(), intervals.end(), cmp);
        
        priority_queue<int, vector<int>, greater<int>> q;
        
        for (auto interval : intervals) {
            if (!q.empty() && interval.start >= q.top()) {
                q.pop();
            }
            q.push(interval.end);
        }
        
        return q.size();
    }
};



https://discuss.leetcode.com/topic/20971/c-o-n-log-n-584-ms-3-solutions

//Stephen (14 ms)

int minMeetingRooms(vector<Interval>& intervals) {
    vector<int> starts, ends;
    for (auto i : intervals) {
        starts.push_back(i.start);
        ends.push_back(i.end);
    }
    sort(begin(starts), end(starts));
    sort(begin(ends), end(ends));
    int e = 0, rooms = 0, available = 0;
    for (int start : starts) {
        while (ends[e] <= start) {
            ++e;
            ++available;
        }
        available ? --available : ++rooms;
    }
    return rooms;
}
