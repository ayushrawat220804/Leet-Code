/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        // Create a new ListNode to store the result
        ListNode* l3 = new ListNode();
        int carry = 0; // Initialize carry to 0
        ListNode* head = l3; // Keep the head of the result list

        // Traverse both lists while both have nodes
        while (l1 && l2) {
            // Calculate the sum of the current nodes' values and the carry
            int value = l1->val + l2->val + carry;
            carry = value / 10; // Update carry for the next iteration
            l3->next = new ListNode(value % 10); // Create a new node with the digit value
            l3 = l3->next; // Move to the next node in the result list
            l1 = l1->next; // Move to the next node in l1
            l2 = l2->next; // Move to the next node in l2
        }

        // If l1 has remaining nodes, process them
        while (l1) {
            int value = l1->val + carry; // Add carry to the current node's value
            carry = value / 10; // Update carry
            l3->next = new ListNode(value % 10); // Create a new node with the digit value
            l3 = l3->next; // Move to the next node in the result list
            l1 = l1->next; // Move to the next node in l1
        }

        // If l2 has remaining nodes, process them
        while (l2) {
            int value = l2->val + carry; // Add carry to the current node's value
            carry = value / 10; // Update carry
            l3->next = new ListNode(value % 10); // Create a new node with the digit value
            l3 = l3->next; // Move to the next node in the result list
            l2 = l2->next; // Move to the next node in l2
        }

        // If there's any carry left, add a new node with the carry value
        if (carry) {
            l3->next = new ListNode(carry);
        }

        // Return the next node of the dummy head, which is the actual start of the result list
        return head->next;
    }
};
