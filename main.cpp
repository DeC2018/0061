#include <iostream>
#include <vector>

using namespace std;

/**
 * Definition for singly-linked list.
 */
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if (!head || !head->next || k == 0)
            return head;

        ListNode* tail;
        int length = 1;
        for (tail = head; tail->next; tail = tail->next)
            ++length;
        tail->next = head;  // Circle the list

        const int t = length - k % length;
        for (int i = 0; i < t; ++i)
            tail = tail->next;
        ListNode* newHead = tail->next;
        tail->next = nullptr;

        return newHead;
    }
};

// Helper function to create a linked list from a vector
ListNode* createLinkedList(const vector<int>& nums) {
    if (nums.empty()) return nullptr;
    ListNode* head = new ListNode(nums[0]);
    ListNode* current = head;
    for (size_t i = 1; i < nums.size(); ++i) {
        current->next = new ListNode(nums[i]);
        current = current->next;
    }
    return head;
}

// Helper function to print a linked list
void printLinkedList(ListNode* head) {
    cout << "[";
    while (head) {
        cout << head->val;
        if (head->next) cout << ",";
        head = head->next;
    }
    cout << "]" << endl;
}

int main() {
    Solution solution;

    vector<int> nums1 = {1, 2, 3, 4, 5};
    int k1 = 2;
    ListNode* head1 = createLinkedList(nums1);
    cout << "Input: head = [1,2,3,4,5], k = 2" << endl;
    ListNode* result1 = solution.rotateRight(head1, k1);
    cout << "Output: ";
    printLinkedList(result1);

    vector<int> nums2 = {0, 1, 2};
    int k2 = 4;
    ListNode* head2 = createLinkedList(nums2);
    cout << "Input: head = [0,1,2], k = 4" << endl;
    ListNode* result2 = solution.rotateRight(head2, k2);
    cout << "Output: ";
    printLinkedList(result2);

    return 0;
}
