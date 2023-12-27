#include <iostream>
#include <vector>
#include <map>
#include "Makevector.cpp"

int Algorithm(const char* l){
	std::vector<std::pair<int, int>> intervals;
	
	try{
	intervals = Makevector(l);
	sort(intervals.begin(), intervals.end()); 
	}
	
	catch(const negativeHours& n){
		return -1;
	}
	
	catch(const maxHours& m){
		return -2;
	}
	catch(const  incorrect& i){
		return -3;
	}
	catch(const notFile& f){
		return -4;
	}
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
    return roomNumber -1;
}
