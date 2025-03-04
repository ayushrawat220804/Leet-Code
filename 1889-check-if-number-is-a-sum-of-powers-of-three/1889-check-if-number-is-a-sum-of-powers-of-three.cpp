class Solution {
public:
    bool checkPowersOfThree(int n) {
        int ispowergreater = 0;
        while ( pow(3, ispowergreater) <= n){
            ispowergreater++;
        }
        while (n > 0 ){
            if (n >= pow(3,ispowergreater)){
                n = n - pow(3,ispowergreater);
            }
            if ( n >= pow(3,ispowergreater)){
                return false;
            }
            ispowergreater--;

        }
        return true;
        
    }
};