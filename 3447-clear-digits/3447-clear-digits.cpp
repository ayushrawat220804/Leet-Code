class Solution {
public:
    string clearDigits(string s) {
    while (any_of(s.begin(), s.end(), ::isdigit)) { // Continue while there are digits
        for (size_t i = 0; i < s.size(); i++) {
            if (isdigit(s[i])) { // Find the first digit
                if (i > 0) s.erase(i - 1, 1), i--; // Remove left-side character if exists
                s.erase(i, 1); // Remove the digit itself
                break; // Restart from the beginning
            }
        }
    }
    return s;



    }
};

/* 
first we delete first digit in the string 
in second example we have 3 as first digit so first we delete it also we delete 
its left side index in this case we have b, so first we will delete 3 and b it is 3b
then we will check the string now the string is c4
again in this case first we will check first integer digit then we delete it along with its left side index in this case we have c and 4 we will delete c4 
output will be empty null

same goes for eg - 
12ab3s2

1- 2ab2s
2- ab2
3- a

first iterate the whole string at once
then check digit in the string 
delete first digit then its left most element do this while digits = 0
*/