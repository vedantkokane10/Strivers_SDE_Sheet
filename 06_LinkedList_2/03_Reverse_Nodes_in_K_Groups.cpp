/*
Given the head of a linked list, reverse the nodes of the list k at a time, and return the modified list.

Input: head = [1,2,3,4,5], k = 2
Output: [2,1,4,3,5]


Approach  - Write functions to find kths nodes and reverse of linkedlist

Iterate over the list find k nodes from current node and reverse  the sub list.
While doing so maintain prevNode and nextNode, prevNode will point to new tail of previous sublist of k size
which then points to head next new sublist, nextNode stores the next node after the kth node, 
Once a sublist is reversed if temp was head then head will point to kth node and prevNode to temp,
else prevNode next node will be kth node and prevNode will be set to temp.
Every time temp is set to nextNode.

If there is no sublist of k size then just check if prevNode has something or not if it has then attach the temp next to it
and break.


Dry Run!! to better understand.
*/


// TC -> O(N) + O(N) => O(2N)
ListNode* reverseKGroup(ListNode* head, int k) {
    ListNode* temp = head;
    ListNode* prevNode = NULL;
    ListNode* nextNode = NULL;
    while(temp != NULL){
        ListNode* kthNode = findKthNode(temp,k);
        if(kthNode == NULL){
            if(prevNode != NULL){
                prevNode->next = temp;
            }
            break;
        }

        // reverse operation
        nextNode = kthNode->next;
        kthNode->next = NULL;
        reverseList(temp);

        if(temp == head){
            head = kthNode;
            prevNode = temp;
        }
        else{
            prevNode->next = kthNode;
            prevNode = temp;
        }

        temp = nextNode;
    }   

    return head;
}
ListNode* findKthNode(ListNode* head,int k){
    int cnt = 1;
    ListNode* temp = head;
    while(temp != NULL && cnt != k){
        temp = temp->next;
        cnt++;
    }
    return temp;
}
ListNode* reverseList(ListNode* head) {
    ListNode* prevNode = NULL;
    ListNode* currentNode = head;
    ListNode* nextNode = NULL;
    while(currentNode != NULL){
        nextNode = currentNode->next;
        currentNode->next = prevNode;
        prevNode = currentNode;
        currentNode = nextNode;
    }
    return prevNode;
}
