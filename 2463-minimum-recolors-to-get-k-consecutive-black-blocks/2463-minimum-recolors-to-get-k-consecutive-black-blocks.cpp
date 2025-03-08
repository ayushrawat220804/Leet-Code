class Solution {
public:
    int minimumRecolors(string blocks, int k) {
        int n = blocks.size();
        int result = k;
        for ( int i = 0; i <= n-k; i++){
            int w = 0;
            for ( int j = i; j <i+k; j++ ){
                if(blocks[j] == 'W'){
                    w++;
                }
            }
            result = min(result, w);
        }
        return result;

        
    }
};