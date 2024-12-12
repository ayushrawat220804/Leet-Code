// Thank You CodeStoryWithMIK

// brute force approach with sorting and max_heap
class Solution {
public:
    long long pickGifts(vector<int>& gifts, int k) {
        // Step 1: Initialize a max heap (priority queue) with the elements of the gifts array
        // Using max heap allows us to efficiently extract the largest element
        // Time Complexity: O(n) for heapify operation
        priority_queue<int> pq(begin(gifts), end(gifts)); // max_heap

        // Step 2: Calculate the total sum of all gifts initially
        // This will help us compute the remaining value after processing
        // Time Complexity: O(n) for iterating through the gifts array
        long long sum = 0;
        for (int &gift : gifts) { 
            sum = sum + gift; // Accumulate total sum
        }

        // Variable to track the sum of the differences due to gift modifications
        long long mysum = 0;

        // Step 3: Process the top k largest elements in the heap
        while (k--) { 
            // Extract the largest element from the heap
            // Time Complexity: O(1) for pq.top()
            int maxelement = pq.top(); 

            // Remove the largest element from the heap
            // Time Complexity: O(log(n)) for pq.pop()
            pq.pop();

            // Calculate the remaining gift value after taking its square root
            int remaining = sqrt(maxelement);

            // Add the difference between the original value and remaining value to mysum
            mysum = mysum + (maxelement - remaining);

            // Push the remaining value back into the heap
            // Time Complexity: O(log(n)) for pq.push()
            pq.push(remaining);
        }

        // Step 4: Return the total remaining sum after processing k gifts
        // The result is the initial sum minus the accumulated difference (mysum)
        return sum - mysum;
    }
};
