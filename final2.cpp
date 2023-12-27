#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <fstream>

struct negativeHours{
	int n = -1;
};
struct maxHours{
	int m = -2;
};
struct incorrect{
	int i = -3;
};
struct notFile{
	int f = -4;
};
auto Makevector(const char* l){
	int n;
    int i = 0;
    std::pair<int, int> p;
    std::ifstream in(l); 
    std::vector<std::pair<int, int>> intervals;
    
    intervals.push_back(p);
    if (in.is_open())
    {
        while (in >>  intervals[i].first >> intervals[i].second)
        { 
			if( intervals[i].second < 0 || intervals[i].first < 0){
				throw negativeHours();
			}
			if( intervals[i].second > 1000000 || intervals[i].first > 999999){
				throw maxHours();
			}
			if( intervals[i].second < intervals[i].first ){
				throw incorrect();
			}
			intervals.push_back(p);
            i++;
        }
    }else{
		throw notFile();
	}
    in.close();

    sort(intervals.begin(), intervals.end()); 
    
    return intervals;
}

int Algorithm(const char* l){
	std::vector<std::pair<int, int>> intervals;
	
	try{
	intervals = Makevector(l);
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

int main() {
	
	const char* l = "C:\\Users\\Admin\\Desktop\\final1.txt";
    std::cout <<  Algorithm(l) << std::endl; 
	
	
    return 0;
}

