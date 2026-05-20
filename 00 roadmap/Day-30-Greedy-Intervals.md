---
day: 30
topic: Greedy & Intervals
tags:
  - roadmap
  - dsa/topics/greedy
  - dsa/topics/intervals
created: 2026-05-20
---
# Day 30 - Greedy & Intervals

## Lý thuyết

### Greedy = locally optimal -> globally optimal

Cần chứng minh:
- **Greedy choice property**: chọn local optimal dẫn đến global optimal
- **Optimal substructure**: bài con cũng optimal

### Khi nào greedy hoạt động

- Sort theo tiêu chí phù hợp
- Khi DP phức tạp nhưng có pattern đơn giản
- Khi exchange argument chứng minh được

### Activity Selection

Chọn nhiều activity nhất không overlap.

```cpp
// Sort theo end time, chọn activity end sớm nhất
int activitySelection(vector<pii>& intervals) {
    sort(all(intervals), [](pii a, pii b) {
        return a.second < b.second;
    });
    int count = 0, lastEnd = INT_MIN;
    for (auto& [s, e] : intervals) {
        if (s >= lastEnd) {
            count++;
            lastEnd = e;
        }
    }
    return count;
}
```

### Merge Intervals

```cpp
vector<vector<int>> merge(vector<vector<int>>& intervals) {
    sort(all(intervals));
    vector<vector<int>> ans;
    for (auto& iv : intervals) {
        if (!ans.empty() && iv[0] <= ans.back()[1]) {
            ans.back()[1] = max(ans.back()[1], iv[1]);
        } else {
            ans.push_back(iv);
        }
    }
    return ans;
}
```

### Insert Interval

```cpp
vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newI) {
    vector<vector<int>> ans;
    int i = 0, n = intervals.size();
    // Add intervals trước newI
    while (i < n && intervals[i][1] < newI[0]) ans.push_back(intervals[i++]);
    // Merge với newI
    while (i < n && intervals[i][0] <= newI[1]) {
        newI[0] = min(newI[0], intervals[i][0]);
        newI[1] = max(newI[1], intervals[i][1]);
        i++;
    }
    ans.push_back(newI);
    while (i < n) ans.push_back(intervals[i++]);
    return ans;
}
```

### Meeting Rooms II

Min phòng họp cần thiết.

```cpp
// Sweep line: events tại mỗi start (+1) và end (-1)
int minMeetingRooms(vector<vector<int>>& meetings) {
    vector<pii> events;
    for (auto& m : meetings) {
        events.push_back({m[0], 1});
        events.push_back({m[1], -1});
    }
    sort(all(events), [](pii a, pii b) {
        if (a.first != b.first) return a.first < b.first;
        return a.second < b.second;  // -1 trước +1
    });
    int rooms = 0, max_rooms = 0;
    for (auto& [t, type] : events) {
        rooms += type;
        max_rooms = max(max_rooms, rooms);
    }
    return max_rooms;
}
```

### Minimum Number of Arrows

Sort theo end, chọn arrow ở end của interval đầu tiên.

```cpp
int findMinArrowShots(vector<vector<int>>& points) {
    sort(all(points), [](auto& a, auto& b) { return a[1] < b[1]; });
    int arrows = 1;
    int last = points[0][1];
    for (int i = 1; i < points.size(); i++) {
        if (points[i][0] > last) {
            arrows++;
            last = points[i][1];
        }
    }
    return arrows;
}
```

### Patterns

#### Sort by start vs sort by end

| Sort by | Use case |
|---------|----------|
| End time | Max non-overlapping intervals |
| Start time | Merge intervals |
| Length | Sometimes |

#### Two heaps cho scheduling

Min-heap cho available, max-heap cho upcoming.

## Practice

### Easy

- [ ] Assign Cookies (LC #455)
- [ ] Lemonade Change (LC #860)
- [ ] Best Time to Buy and Sell Stock II (LC #122)

### Medium

- [ ] Merge Intervals (LC #56)
- [ ] Insert Interval (LC #57)
- [ ] Non-overlapping Intervals (LC #435)
- [ ] Meeting Rooms II (LC #253)
- [ ] Minimum Number of Arrows (LC #452)
- [ ] Gas Station (LC #134)
- [ ] Hand of Straights (LC #846)
- [ ] Partition Labels (LC #763)
- [ ] Task Scheduler (LC #621)
- [ ] Jump Game II (LC #45)

### Hard

- [ ] Minimum Number of Taps (LC #1326)
- [ ] Video Stitching (LC #1024)

## Mistakes thường gặp

- Greedy nhưng không đúng - thử counterexample trước
- Sort sai tiêu chí
- Edge case: empty input, 1 element

---

**Next**: [[Day-31-Bit-Manipulation]]
