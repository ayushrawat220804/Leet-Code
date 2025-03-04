class Solution {
public:
    bool checkPowersOfThree(int n) {
        int ispowergreater = 0; 
        while ( pow(3, ispowergreater) <= n){
            ispowergreater++; // finds maxium power needed for n , till crosses n
        }
        while (n > 0 ){
            if (n >= pow(3,ispowergreater)){
                n = n - pow(3,ispowergreater); // make the power-- single times
            }
            if ( n >= pow(3,ispowergreater)){ 
                return false;  // if its still greater the needed n , return false;
                // because we can't take power multiple times
                // like 2^1, 2^2 is fine , but 2^1 then 2^1 is repeats wronge
            }
            ispowergreater--;

        }
        return true;
        
    }
};