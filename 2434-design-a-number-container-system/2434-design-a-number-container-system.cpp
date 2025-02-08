//Approach-1 (Using two maps : map of int, int and map of int, set)
//T.C : O(log(n))
//S.C : O(n)
class NumberContainers {
public:
    //Space : O(n)
    unordered_map<int, int> idxToNum;
    unordered_map<int, set<int>> numToIdx;

    NumberContainers() {
        //do nothing    
    }
    
    void change(int index, int number) {
        if(idxToNum.count(index)) { //O(1)
            int prevNum = idxToNum[index];
            numToIdx[prevNum].erase(index); //O(log(n))
            if(numToIdx[prevNum].empty()) {
                numToIdx.erase(prevNum); //O(1)
            }
        }


        idxToNum[index] = number;
        numToIdx[number].insert(index); //O(log(n))

    }
    
    int find(int number) {
        if(numToIdx.count(number)) { //O(1)
            return *numToIdx[number].begin(); //O(1)
        }

        return -1;    
    }
};

