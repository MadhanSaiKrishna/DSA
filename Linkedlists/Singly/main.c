#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Node structure
struct Node {
    int data;
    struct Node* next;
};

typedef struct Node* Linkedlist;

void insertAtBeginning(struct Node** head, int value); // Function to insert a new node at the beginning of the list
void printList(struct Node* head);// Function to print the elements of the list
void insertAtEnd(struct Node** head, int value);//Function to insert a new node at the end of the list
void insertAtPosition(struct Node** head, int value, int position);//Function to insert a node at a position
void deleteFromBeginning(struct Node** head);//Function to delete a node from the beginning
void deleteFromEnd(struct Node** head);//Function to delete a node from the end
void deleteFromPosition(struct Node** head, int position);//Function to delete a node at a position
void reverseList(struct Node** head);//Function to reverse a list
int detectLoop(struct Node* head);//Function to detect a loop
struct Node* findMiddle(struct Node* head); //To find the middle element of a given linkedlist
struct Node* mergeSortedLists(struct Node* list1, struct Node* list2);//Merge two sorted linked lists into one sorted linked list.
void removeNthFromEnd(struct Node** head, int n);//Remove the N-th node from the end of a linked list in one pass.
int isPalindrome(struct Node* head);//Check if a linked list is a palindrome (reads the same forwards and backwards).
struct Node* rotateRight(struct Node* head, int k);//rotate a linked list to the right by k places.
void detectAndRemoveLoop(struct Node* head);//Detect and remove a loop in a linkedlist if any
struct Node* addTwoNumbers(struct Node* l1, struct Node* l2);//Given two linked lists representing two non-negative numbers, add them and return the result as a linked list.
struct Node* sortList(struct Node* head);//Sort a linked list in O(n log n) time using constant space complexity.






void insertAtBeginning(struct Node** head, int value) {
}


void printList(struct Node* head) {
}

int main() {
    return 0;
}
