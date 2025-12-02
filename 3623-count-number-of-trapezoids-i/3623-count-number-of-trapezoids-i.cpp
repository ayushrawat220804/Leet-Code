/*
int points = [  ];
cartesian plane 
first let coordinates for corresponding y axis findout how many y1 x1 on that paritcular horizontal line x1,x4 = 2 points, 
best data structure for this is map , y axis contains key value contains count of how many points, after the count of horizontal lines then from that count trapazoids

for auto an it in map {
    int count = it.second;
    horizontal = count * (count -1)/2;
    result = result + horizontal *  total_previous_lines;
    total_previous_lines += horizontalines;

}
return result % (10^9 + 7);


time complexity : o(n)
space complexity : o(n)

*/
class Solution {
public:
    int M = 1e9+7;

    int countTrapezoids(vector<vector<int>>& points) {
        unordered_map<int,int>mp;
        for (auto &point : points){
            int y = point[1];
            mp[y]++;
        }
        long long result = 0;
        long long previous_horizontal_lines = 0;
        for (auto &it : mp){
            int count = it.second;
            long long horizontal_lines = (long long )count * ( count - 1) /2 ;
            result += horizontal_lines * previous_horizontal_lines;

            previous_horizontal_lines += horizontal_lines;
        
        }

        return result % M;
    }
};


