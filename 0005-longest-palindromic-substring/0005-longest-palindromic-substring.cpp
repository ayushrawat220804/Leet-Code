class Solution {
public:
    // check function 
    int check (string s , int p1, int p2, int &start, int &end){
        int count = 0;
        if ( p1 == p2 ){
            count++;
            p1--;
            p2++;
        }
        while (p1>=0 and p2<s.length()){
            if ( s[p1] != s[p2] ){
                start = p1+1;
                end = p2-1;
                return count;
            }
            else{
                p1--;
                p2++;
                count+=2;
            }
        }
        start=p1+1;
        end=p2-1;
        return count;
    }
    
    string longestPalindrome(string s) {
        int start = -1;
        int end = -1;
        int length = 0;
        int final_string = -1;
        int final_end = -1;
        
        for ( int i = 0; i<s.length(); i++ ){
            
            int x = check(s, i , i, start, end );
            
            if(x>length){
                length = x;
                final_string = start;
                final_end = end;
            }
            
            int y = check (s, i, i+1, start , end );
                
                if (y>length){
                    length = y;
                    final_string = start;
                    final_end = end;
                }
        }
        return s.substr(final_string,final_end-final_string+1);
    }
        
};