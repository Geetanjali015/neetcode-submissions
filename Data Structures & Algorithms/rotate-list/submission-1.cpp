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
    ListNode* rotateRight(ListNode* head, int k) {

        // If the list is empty, nothing to rotate → return NULL
        if(head == NULL)
            return NULL;

        // Start counting length from 1 because head already exists
        int listnum = 1;

        // 'tail' will move to the last node while counting length
        ListNode* tail = head;

        // Traverse until last node (whose next is NULL)
        while(tail->next != NULL){
            listnum++;          // Increment count for each node visited
            tail = tail->next;  // Move tail forward
        }

        // Now:
        // listnum = total number of nodes
        // tail = last node of the list

        // Connect last node to head → makes list circular
        // This helps avoid handling edge cases separately
        tail->next = head;

        // Reduce k because rotating more than length is redundant
        // Example: rotate 14 times on size 6 → same as rotate 2 times
        int effectiveRotation = k % listnum;

        // Find how many steps to move from current tail
        // to reach the NEW TAIL
        // Why?
        // If rotating right by 'r', new tail is (n - r) steps ahead
        int newh = listnum - effectiveRotation;

        // Move 'tail' forward to reach the new tail position
        for(int i = 0; i < newh; i++){
            tail = tail->next;
        }

        // The node after new tail becomes the new head
        head = tail->next;

        // Break the circular link to form final rotated list
        tail->next = NULL;

        // Return updated head
        return head;
    }
};