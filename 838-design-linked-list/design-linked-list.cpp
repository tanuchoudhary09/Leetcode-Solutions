class Node {
public:
    Node(int val){
        this->val=val;
    }
    int val;
    Node* next = nullptr;
};
class MyLinkedList {
public:
    Node* head = nullptr;
    MyLinkedList() {}

    int get(int index) {
        Node* temp = head;
        int idx = 0;
        while (temp) {
            if (idx == index)
                return temp->val;
            idx++;
            temp = temp->next;
        }
        return -1;
    }

    void addAtHead(int val) {
        Node* temp = new Node(val);
        if (!head)
            head = temp;
        else {
            temp->next = head;
            head = temp;
        }
    }

    void addAtTail(int val) {
        if (!head) {
            head = new Node(val);
            return;
        }
        Node* temp = head;
        while (temp->next) {
            temp = temp->next;
        }
        temp->next = new Node(val);
    }

    void addAtIndex(int index, int val) {
        if (index == 0) {
            addAtHead(val);
            return;
        }
        Node* temp = head;
        int idx = 0;
        while (temp) {
            if (idx == index - 1) {
                Node* temp2 = temp->next;
                temp->next = new Node(val);
                temp->next->next = temp2;
                return;
            }
            idx++;
            temp = temp->next;
        }
    }

    void deleteAtIndex(int index) {
        if (index == 0) {
            if(head)head = head->next;
            return;
        }
        Node* temp = head;
        int idx = 0;
        while (temp->next) {
            if (idx == index - 1) {
                temp->next = temp->next->next;
                return;
            }
            idx++;
            temp = temp->next;
        }
    }
};

/**
 * Your MyLinkedList object will be instantiated and called as such:
 * MyLinkedList* obj = new MyLinkedList();
 * int param_1 = obj->get(index);
 * obj->addAtHead(val);
 * obj->addAtTail(val);
 * obj->addAtIndex(index,val);
 * obj->deleteAtIndex(index);
 */