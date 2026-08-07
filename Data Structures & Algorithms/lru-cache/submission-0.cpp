class Node {
public:
    int key;
    int value;
    Node* prev;
    Node* next;

    Node(int k, int v) {
        key = k;
        value = v;
        prev = next = nullptr;
    }
};

class LRUCache {
public:
    unordered_map<int,Node*> mp;
    int capacity = 0;
    Node* head;
    Node* tail;

    LRUCache(int capacity) {
        this->capacity = capacity;
        head = new Node(-1,-1);
        tail = new Node(-1,-1);
        head->next = tail;
        tail->prev = head;
    }
    
    int get(int key) {
        if(mp.find(key) != mp.end()){
            remove(mp[key]);
            insert(mp[key]);
            return mp[key]->value;
        } else {
            return -1;
        }
    }
    
    void put(int key, int value) {
        if(mp.find(key) != mp.end()){
            mp[key]->value = value;
            remove(mp[key]);
            insert(mp[key]);
        } else {
            if(mp.size() == capacity){
                Node* erase = head->next;
                remove(erase);
                mp.erase(erase->key);
                delete erase;
            }
            Node* node = new Node(key,value);
            mp[key] = node;
            insert(node);
        }
    }

    // hàm insert vô cuối
    void insert(Node* node){
        tail->prev->next = node;
        node->prev = tail->prev;
        node->next = tail;
        tail->prev = node;
    }

    void remove(Node* node){
        node->prev->next = node->next;
        node->next->prev = node->prev;
        // node hiện tại chưa bị xóa vẫn còn next , prev
    }
};
