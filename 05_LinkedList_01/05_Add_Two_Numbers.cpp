/*
You are given two non-empty linked lists representing two non-negative integers. 
The digits are stored in reverse order, and each of their nodes contains a single digit. Add the two numbers and return the sum as a linked list.
You may assume the two numbers do not contain any leading zero, except the number 0 itself.

Ex - 
Input: l1 = [2,4,3], l2 = [5,6,4]
Output: [7,0,8]
Explanation: 342 + 465 = 807.

*/

ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
    ListNode* head = new ListNode(-1);
    ListNode* temp = head;
    int carry = 0;
    while(l1 != NULL && l2 != NULL){
        int currentSum = l1->val + l2->val + carry;
        int digit = 0;
        if(currentSum >= 10){
            digit = currentSum % 10;
            carry = 1;
        }
        else{
            digit = currentSum;
            carry = 0;
        }
        ListNode* newNode = new ListNode(digit);
        temp->next = newNode;
        temp = temp->next;
        l1 = l1->next;
        l2 = l2->next;
    }
    while(l1){
        int currentSum = l1->val + carry;
        int digit = 0;
        if(currentSum >= 10){
            digit = currentSum % 10;
            carry = 1;
        }
        else{
            digit = currentSum;
            carry = 0;
        }
        ListNode* newNode = new ListNode(digit);
        temp->next = newNode;
        temp = temp->next;
        l1 = l1->next;
    }
    while(l2){
        int currentSum = l2->val + carry;
        int digit = 0;
        if(currentSum >= 10){
            digit = currentSum % 10;
            carry = 1;
        }
        else{
            digit = currentSum;
            carry = 0;
        }
        ListNode* newNode = new ListNode(digit);
        temp->next = newNode;
        temp = temp->next;
        l2 = l2->next;
    }
    if(carry){
        ListNode* newNode = new ListNode(carry);
        temp->next = newNode;
        temp = temp->next;
    }
    return head->next;
}
ListNode* reverse(ListNode* head){
    ListNode* current = head;
    ListNode* previousNode = NULL;
    ListNode* nextNode = NULL;
    while(current != NULL){
        nextNode = current->next;
        current->next = previousNode;
        previousNode = current;
        current = nextNode;
    } 
    return previousNode;
}
