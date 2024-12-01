class Solution {
public:
    int binarysearch(vector<int> & arr, int target){
        int l = 0;
        int r = arr.size()-1;
        
        int mid;
        while( l <= r ){
            mid = l + (r-l)/2;
            if(arr[mid] == target){
                return mid;
            }
            else if (arr[mid] > target){
                r = mid-1;
            }
            else {
                l = mid+1;
            }
        }            
        return -1;
    }
    
    bool checkIfExist(vector<int>& arr) {
        int n = arr.size();
        sort(begin(arr), end(arr));
        for (int i = 0; i < n; i++){
            int j = binarysearch(arr, 2*arr[i]);
            
            if( j != -1 && j != i ){
                return true;
            }
        }
        return false;
    }
};