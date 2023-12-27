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

int Makevector(const char* l){
	int n;
    int i = 0;
    int Rooms;
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

    
    try{
    Rooms = Algorithm(intervals);
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
	
	
    return Rooms;
}



int main() {
	
	const char* l =  "C:\\Users\\Admin\\Desktop\\final1.txt";
	std::vector <std::pair<int, int>> v = {{5, 10000000}, {3, 7}};
    std::cout << Algorithm(v) << std::endl; 
    std::cout << Makevector(l) << std::endl;
	
	
    return 0;
}
