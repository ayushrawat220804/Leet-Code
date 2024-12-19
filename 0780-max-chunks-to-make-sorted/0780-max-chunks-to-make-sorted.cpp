// Thanks To CodeWithMIK
// Time Complexity : 0(n)
// Space Complexity : 0(n)
class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
        int n = arr.size();

        vector<int> prefixMax(begin(arr), end(arr));
        vector<int> suffixMin(begin(arr), end(arr));

        for(int i = 1; i<n; i++){
            prefixMax[i] = max(prefixMax[i], prefixMax[i-1]);
        }

        for(int i = n-2; i>= 0; i--){
            suffixMin[i] = min(suffixMin[i], suffixMin[i+1]);
        }

        int count_chunks = 0;
        for(int i = 0; i<n; i++){
            int phelekaMax = i > 0 ? prefixMax[i-1] : -1;
            int baadkaMin = suffixMin[i];

            if(phelekaMax < baadkaMin){
                count_chunks++;
            }
        }
        return count_chunks;

    }
};