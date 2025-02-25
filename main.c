#include <stdio.h>
#include <stdlib.h>

/**
 * Definition for singly-linked list.
 */
struct ListNode {
    int val;
    struct ListNode *next;
};

struct ListNode* rotateRight(struct ListNode* head, int k) {
    if (head == NULL || head->next == NULL || k == 0)
        return head;

    struct ListNode *tail = head;
    int length = 1;
    while (tail->next) {
        tail = tail->next;
        length++;
    }
    tail->next = head;  // Circle the list

    int t = length - k % length;
    for (int i = 0; i < t; ++i)
        tail = tail->next;
    struct ListNode* newHead = tail->next;
    tail->next = NULL;

    return newHead;
}

// Helper function to create a linked list from an array
struct ListNode* createLinkedList(int* nums, int size) {
    if (size == 0) return NULL;
    struct ListNode* head = (struct ListNode*)malloc(sizeof(struct ListNode));
    head->val = nums[0];
    head->next = NULL;
    struct ListNode* current = head;
    for (int i = 1; i < size; ++i) {
        current->next = (struct ListNode*)malloc(sizeof(struct ListNode));
        current = current->next;
        current->val = nums[i];
        current->next = NULL;
    }
    return head;
}

// Helper function to print a linked list
void printLinkedList(struct ListNode* head) {
    printf("[");
    while (head) {
        printf("%d", head->val);
        if (head->next) printf(",");
        head = head->next;
    }
    printf("]\n");
}

int main() {
    int nums1[] = {1, 2, 3, 4, 5};
    int k1 = 2;
    struct ListNode* head1 = createLinkedList(nums1, 5);
    printf("Input: head = [1,2,3,4,5], k = 2\n");
    struct ListNode* result1 = rotateRight(head1, k1);
    printf("Output: ");
    printLinkedList(result1);

    int nums2[] = {0, 1, 2};
    int k2 = 4;
    struct ListNode* head2 = createLinkedList(nums2, 3);
    printf("Input: head = [0,1,2], k = 4\n");
    struct ListNode* result2 = rotateRight(head2, k2);
    printf("Output: ");
    printLinkedList(result2);

    return 0;
}
