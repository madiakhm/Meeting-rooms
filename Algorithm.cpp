#include <iostream>
#include <vector>
#include <map>
#include <algorithm>


int Algorithm(std::vector<std::pair<int, int>> intervals){
	sort(intervals.begin(), intervals.end());
	
	for (int i = 0; i < intervals.size(); i++)
    { 
			if( intervals[i].second < 0 || intervals[i].first < 0){
				return -1;
			}
			if( intervals[i].second > 1000000 || intervals[i].first > 999999){
				return -2;
			}
			if( intervals[i].second < intervals[i].first ){
				return -3;
			}
          
    }
	std::map<int, int> rooms; 
    int roomNumber = 1;
    
    for(auto interval : intervals) {
        auto it = rooms.lower_bound(interval.first);
        if(it == rooms.begin()) {

            rooms[interval.second] = roomNumber;
            roomNumber++;
        } else {
            it--; 
            int room = it->second;
            rooms.erase(it); 
            rooms[interval.second] = room; 
        }
    }
    return roomNumber -1;
}
