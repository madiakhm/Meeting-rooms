#include <iostream>
#include <vector>
#include <map>
#include <algorithm>


int main() {
    int n;
    std::cin >> n;
    
    std::vector<std::pair<int, int>> intervals(n);
    for(int i = 0; i < n; i++) {
        std::cin >> intervals[i].first >> intervals[i].second;
    }
    sort(intervals.begin(), intervals.end()); 
    
    std::map<int, int> rooms; 
    int roomNumber = 1;
    
    for(auto interval : intervals) {
        auto it = rooms.lower_bound(interval.first);
        if(it == rooms.begin()) {

            rooms[interval.second] = roomNumber;
            std::cout << interval.first << " " << interval.second << " - " << roomNumber << std::endl;
            roomNumber++;
        } else {
            it--; 
            int room = it->second;
            rooms.erase(it); 
            rooms[interval.second] = room; 
            std::cout << interval.first << " " << interval.second << " - " << room << std::endl;
        }
    }
    std::cout << roomNumber - 1 << std::endl; 
    return 0;
}

