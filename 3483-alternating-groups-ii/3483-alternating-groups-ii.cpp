class Solution {
public:
    int numberOfAlternatingGroups(vector<int>& colors, int k) {
        int n = colors.size();
        int N = n + (k-1);
        for ( int i = 0; i < k-1; i++){
            colors.push_back(colors[i]); // handle wrap around circular array

        }
        int result = 0; 
        int i = 0;
        int j = 1; // because we have to check index j-1 for checking alternate
        while ( j < N){
            if (colors[j] == colors[j-1]){
                i = j;
                j++;
                continue;
            }
            if(j - i + 1 == k){
                result++;
                i++;
            }
            else{
                j++;
            }
        }
        return result;


    }
};