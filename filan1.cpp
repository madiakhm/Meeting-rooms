#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <fstream>

int main() {
	int n;
    int i = 0;
    std::pair<int, int> p;
    std::ifstream in("final1.txt"); 
    std::vector<std::pair<int, int>> intervals;
    
  
    intervals.push_back(p);
    if (in.is_open())
    {
        while (in >>  intervals[i].first >> intervals[i].second)
        { 
			intervals.push_back(p);
            i++;
        }
    }
    in.close();

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

