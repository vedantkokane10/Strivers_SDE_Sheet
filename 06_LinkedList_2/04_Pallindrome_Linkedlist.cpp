/*
Given the head of a singly linked list, return true if it is a palindrome or false otherwise.

Input: head = [1,2,2,1]
Output: true

Appraoch - 
Find middle element and then reverse the list after middle element,
keep pointers to head and at element next to middle node
iterate compare if they are equal if not return false
At end return true as the list is pallindrome
*/


bool isPalindrome(ListNode* head) {
    ListNode* slow = head;
    ListNode* fast = head;
    while(fast != NULL && fast->next != NULL){
        fast = fast->next->next;
        slow = slow->next;
    }
    ListNode* temp1 = head;
    ListNode* temp2 = reverse(slow);
    while(temp2 != NULL){
        if(temp1->val != temp2->val){
            return 0;
        }
        temp1 = temp1->next;
        temp2 = temp2->next;
    }
    return 1;
}

ListNode* reverse(ListNode* head){
    ListNode* current = head;
    ListNode* nextNode = NULL;
    ListNode* prevNode = NULL;

    while(current != NULL){
        nextNode = current->next;
        current->next = prevNode;
        prevNode = current;
        current = nextNode;
    }
    return prevNode;
}
