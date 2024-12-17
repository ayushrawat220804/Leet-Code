// Thank You CodeWithMIK
class Solution {
public:
    string repeatLimitedString(string s, int repeatLimit) {
        vector <int> count(26,0); // space complexity : 0(26)
        for(char &ch :s){ // time complexity : 0(n)
            count[ch - 'a']++;
        }
        string result;

        int i = 25;
        while(i >= 0){  // 0(26)
            if(count[i] == 0){
                i--;
                continue;
            }
            char ch ='a' + i;
            int frequency = min(count[i], repeatLimit);

            result.append(frequency, ch);
            count[i] = count[i] - frequency;

            if(count[i] > 0){
                int j = i - 1;
                while(j >= 0 && count[j] == 0){ // 0(26)
                    j--;
                }
                if(j<0){
                    break;
                }
                result.push_back('a' + j);
                count[j]--;
            }
        }
        return result;
        
    }
};