class Node{
    public:
    int value;
    Node* next;
    
    Node(int val)
    {
        value = val;
    }
};

class MyLinkedList {
public:
    int size;
    Node* head;
    MyLinkedList() {
        head = NULL;
        size = 0;       
    }
    
    int get(int index) {
        if(index < 0 || index >= size)
            return -1;
        Node* curr = head;
        for(int i = 0; i < index; i++)
            curr = curr->next;
        return curr->value;
    }
    
    void addAtHead(int val) {
        addAtIndex(0, val);
    }
    
    void addAtTail(int val) {
       addAtIndex(size, val); 
    }
    
    void addAtIndex(int index, int val) {
        if(index < 0 || index > size)
            return;
        size++;
        Node* node = new Node(val);
        if(index == 0)
        {
            if(!head)
            {
                head = node;
            }
            else
            {
                node->next = head;
                head = node;
            }
        }
        else
        {
            Node* curr = head;
            for(int i = 0; i < index-1; i++)
            {
                curr = curr->next;
            }
            node->next = curr->next;
            curr->next = node;
        }
    }
    
    void deleteAtIndex(int index) {
        if(index < 0 || index >= size)
            return;
        size--;
        if(index == 0)
        {
            Node* temp = head;
            head = head->next;
            delete(temp);
        }
        else
        {
            Node* curr = head;
            for(int i = 0; i < index-1; i++)
            {
                curr = curr->next;
            }
            Node* temp = curr->next;
            curr->next = curr->next->next;
            delete(temp);
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