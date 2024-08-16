class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};

Node* copyRandomList(Node* head) {
    unordered_map<Node* ,Node*> mp;
    Node* dummyHead = new Node(-1);
    Node* temp = head;
    Node* temp2 = dummyHead;
    while(temp != NULL){
        Node* newNode = new Node(temp->val);
        mp[temp] = newNode;
        temp2->next = newNode;
        temp2 = temp2->next;
        temp = temp->next;

    }
    temp = head;
    temp2 = dummyHead->next;

    while(temp != NULL){
        if(temp->random != NULL){
            Node* randomPointer = temp->random;
            temp2->random = mp[randomPointer];
        }
        temp = temp->next;
        temp2 = temp2->next;
    }


    return dummyHead->next;
}
