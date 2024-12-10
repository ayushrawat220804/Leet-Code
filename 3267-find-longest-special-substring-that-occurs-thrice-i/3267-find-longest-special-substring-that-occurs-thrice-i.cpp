// Thank you CodeStoryWIthMIK
// approach 1

class Solution {
public:
    int maximumLength(string s) {
        int n = s.length();

        unordered_map <string, int> mp; // "substring, int"
        
        for (int i = 0; i < n; i++){
        string current = "";
            for (int j = i; j < n; j++){
                if (current.empty() || current.back() == s[j]){
                    current.push_back(s[j]);
                    mp[current] = mp[current] + 1;
                } else {
                    break;
                }
            }
        }
        int result = 0;
        for (auto &it : mp){
            string str = it.first;
            int count = it.second;
            if (count >= 3 && str.length() > result){
                result = str.length();
            }
        }
        return result == 0 ? -1 : result;

    }
};