// time complexity -o(n^2)
// space compleixity - o(n)

class Solution {
public:
    string removeOccurrences(string s, string part) {
        while (s.find(part) != string::npos) {
            size_t index = s.find(part);
            // Erase the found 'part' from string 's'
            s.erase(index, part.length());
        }
        return s;
        
    }
};

/*
given :
strings s and part

in this programme we have to remove elements of string part in string s
suppose we have two strings s and part 
s = hhowareusesea
part = how

in this example we have to remove string part in s 
here we 
how to perform it 
howareusesea
hareusesea is the answer

brute force approach 

first iterate the both the string 
then check does string part contain same letter in string s , with same word index is yes then remove it 
remove until no word is matching in string s 

another example 
youarenoomare , are

younoomare
younoom - answer


*/