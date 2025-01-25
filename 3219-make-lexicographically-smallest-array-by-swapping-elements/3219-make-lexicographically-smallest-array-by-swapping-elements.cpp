
//Approach-2 (using sorting and grouping using unordered_map)
//T.C : ~O(n*logn)
//S.C : ~O(n)
class Solution {
public:
    vector<int> lexicographicallySmallestArray(vector<int>& nums, int limit) {
        int n = nums.size();

        vector<int> vec = nums;
        //sort the vec
        sort(begin(vec), end(vec));

        int groupNum = 0;
        unordered_map<int, int> numToGroup;
        numToGroup[vec[0]] = groupNum;

        unordered_map<int, list<int>> groupToList;
        groupToList[groupNum].push_back(vec[0]); //O(1)

        for(int i = 1; i < n; i++) {
            if(abs(vec[i] - vec[i-1]) > limit) {
                groupNum += 1;
            }

            numToGroup[vec[i]] = groupNum;
            groupToList[groupNum].push_back(vec[i]);
        }
        
        //Build the anwer - Merge the groups
        vector<int> result(n);
        for(int i = 0; i < n; i++) {
            int num = nums[i];
            int group = numToGroup[num];
            //smallest available number in this group
            result[i] = *groupToList[group].begin(); //use hogaya to delete kardo used element ko
            groupToList[group].pop_front();
        }

        return result;
    }
};