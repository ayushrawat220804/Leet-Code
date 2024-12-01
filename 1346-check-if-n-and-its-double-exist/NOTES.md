// method 1 : Brute force approach
class Solution {
public:
bool checkIfExist(vector<int>& arr) {
int n = arr.size();
for (int i = 0; i < n; i++){
for ( int j = 0; j < n; j++) {
if ( i != j && arr[i] == 2*arr[j]){
return true;
}
}
}
return false;
}
};
​
// methon 2 : Unordered_map/Set
class Solution {
public:
bool checkIfExist(vector<int>& arr) {
int n = arr.size();
unordered_set<int> st;
​
for (int i = 0; i < n; i++) {
if (st.find(arr[i] * 2) != st.end()) {
return true;
} else if (arr[i]%2 == 0 && st.find(arr[i]/2) != st.end()){
return true;
}