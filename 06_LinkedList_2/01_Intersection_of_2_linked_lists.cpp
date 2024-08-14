/*
Given the heads of two singly linked-lists headA and headB, return the node at which the two lists intersect.
If the two linked lists have no intersection at all, return null.


Input: intersectVal = 8, listA = [4,1,8,4,5], listB = [5,6,1,8,4,5], skipA = 2, skipB = 3
Output: Intersected at '8'

Approach -
First find length of both the lists then check who is longer list
Maintain 2 pointers for both lists 
Find same starting position for both the lists (node from which both list have same length) 
and then iterate and find the intersection.
*/

ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
    ListNode* temp1 = headA;
    ListNode* temp2 = headB;
    int length1 = 1;
    int length2 = 1;
    while(temp1->next != NULL){
        length1++;
        temp1 = temp1->next;
    }
    while(temp2->next != NULL){
        length2++;
        temp2 = temp2->next;
    }
    if(temp1 != temp2){
        return NULL;
    }
    cout<<length1<<" "<<length2<<endl;

    temp1 = headA;
    temp2 = headB;
    if(length1 > length2){
        int startLength = max(length1,length2) - min(length1,length2);
        while(startLength != 0){
            temp1 = temp1->next;
            startLength--;
        }

        while(temp1 != temp2){
            temp1 = temp1->next;
            temp2 = temp2->next;
        }
        return temp1;
    }
    else{
        int startLength = max(length1,length2) - min(length1,length2);
        while(startLength != 0){
            temp2 = temp2->next;
            startLength--;
        }
        while(temp1 != temp2){
            temp1 = temp1->next;
            temp2 = temp2->next;
        }
        return temp1;
    }
    

    
    return NULL;
}
