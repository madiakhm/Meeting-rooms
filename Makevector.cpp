#include <algorithm>
#include <vector>
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

   
    
    return intervals;
}
