class Node {
public:
    int key; 
    int data;
    Node* prev;
    Node* next;

    Node(int key, int data) {
        this->key = key;
        this->data = data;
        prev = NULL;
        next = NULL;
    }
};

class LRUCache {
    int capacity;
    Node* head;
    Node* tail;
    unordered_map<int, Node*> mp;

public:
    LRUCache(int capacity) {
        this->capacity = capacity;
        head = NULL;
        tail = NULL;
    }

    void deleteNode(Node* node) {
        if(node == NULL) return;

        if(node == head) head = head->next;
        if(node == tail) tail = tail->prev;

        if(node->prev) node->prev->next = node->next;
        if(node->next) node->next->prev = node->prev;

        node->prev = node->next = NULL;
    }

    void insertAtBeg(Node* node) {
        node->prev = NULL;
        node->next = head;

        if(head) head->prev = node;
        head = node;

        if(tail == NULL) tail = head; // first element case
    }

    int get(int key) {
        if(mp.find(key) == mp.end()) return -1;

        Node* node = mp[key];
        int ans = node->data;

        // Move node to front
        deleteNode(node);
        insertAtBeg(node);
        mp[key] = head;

        return ans;
    }

    void put(int key, int value) {
        if(mp.find(key) != mp.end()) {
            // update existing
            Node* node = mp[key];
            node->data = value;

            deleteNode(node);
            insertAtBeg(node);
            mp[key] = head;
        } 
        else {
            if(mp.size() == capacity) {
                // evict least recently used
                mp.erase(tail->key);
                Node* temp=tail;
                deleteNode(tail);
                delete temp;
            }

            Node* node = new Node(key, value);
            insertAtBeg(node);
            mp[key] = head;
        }
    }
};
