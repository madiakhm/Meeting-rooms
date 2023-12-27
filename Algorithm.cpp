#include <iostream>
#include <vector>
#include <map>
#include <fstream>
#include "Makevector.cpp"

void Algorithm(const char* l){
	std::vector<std::pair<int, int>> intervals;
	const char* o = "C:\\Users\\Admin\\Desktop\\output.txt";
	std::ofstream out(o);
	
	try{
	intervals = Makevector(l);
	sort(intervals.begin(), intervals.end()); 
	}
	
	catch(const negativeHours& n){
		out << "negative Hours" << std::endl;
		return;
	}
	
	catch(const maxHours& m){
		out << "max Hours" << std::endl;
		return;
	}
	catch(const  incorrect& i){
		out << "incorrect" << std::endl;
		return ;
	}
	catch(const notFile& f){
		out << "not File" << std::endl;
		return;
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
   out << roomNumber - 1 << std::endl;
   out.close();
}
