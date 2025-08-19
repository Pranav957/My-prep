class Node {
public:
    int key, value, freq;
    Node* prev;
    Node* next;

    Node(int k, int v) {
        key = k;
        value = v;
        freq = 1; // every new node starts with frequency 1
        prev = next = NULL;
    }
};

class DLList {
public:
    int size;
    Node* head;
    Node* tail;

    DLList() {
        head = new Node(0, 0);
        tail = new Node(0, 0);
        head->next = tail;
        tail->prev = head;
        size = 0;
    }

    void addFront(Node* node) {
        node->next = head->next;
        node->prev = head;
        head->next->prev = node;
        head->next = node;
        size++;
    }

    void removeNode(Node* node) {
        node->prev->next = node->next;
        node->next->prev = node->prev;
        size--;
    }

    Node* removeLast() {
        if (size > 0) {
            Node* node = tail->prev;
            removeNode(node);
            return node;
        }
        return NULL;
    }
};

class LFUCache {
    int capacity, minFreq;
    unordered_map<int, Node*> mp;           // key → node
    unordered_map<int, DLList*> freqList;  // freq → list of nodes

public:
    LFUCache(int capacity) {
        this->capacity = capacity;
        minFreq = 0;
    }

    int get(int key) {
        if (mp.find(key) == mp.end()) return -1;

        Node* node = mp[key];
        updateFreq(node);
        return node->value;
    }

    void put(int key, int value) {
        if (capacity == 0) return;

        if (mp.find(key) != mp.end()) {
            Node* node = mp[key];
            node->value = value;
            updateFreq(node);
        } else {
            if (mp.size() == capacity) {
                // remove least frequently used node
                DLList* list = freqList[minFreq];
                Node* toRemove = list->removeLast();
                mp.erase(toRemove->key);
            }

            Node* node = new Node(key, value);
            mp[key] = node;
            if (freqList.find(1) == freqList.end()) 
                freqList[1] = new DLList();
            freqList[1]->addFront(node);
            minFreq = 1;
        }
    }

private:
    void updateFreq(Node* node) {
        int oldFreq = node->freq;
        freqList[oldFreq]->removeNode(node);

        if (oldFreq == minFreq && freqList[oldFreq]->size == 0) {
            minFreq++;
        }

        node->freq++;
        if (freqList.find(node->freq) == freqList.end())
            freqList[node->freq] = new DLList();
        freqList[node->freq]->addFront(node);
    }
};
