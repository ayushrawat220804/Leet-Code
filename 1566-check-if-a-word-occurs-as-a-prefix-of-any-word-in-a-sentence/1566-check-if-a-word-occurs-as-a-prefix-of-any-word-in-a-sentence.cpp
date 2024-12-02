class Solution {
public:
    int isPrefixOfWord(string sentence, string searchWord) {
        istringstream stream(sentence); // Stream to split the sentence
        string word;
        int index = 0;

        while (stream >> word) { // Extract words from the sentence
            index++;
            if (word.find(searchWord) == 0) { // Check if searchWord is a prefix
                return index;
            }
        }

        return -1;

    }
};