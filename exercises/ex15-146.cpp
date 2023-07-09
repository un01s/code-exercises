/*
 * leetcode 146 LRU cache
 * least recently used cache
 *
 */

#include <iostream>
#include <unordered_map>

using namespace std;

// doubly linked list node
class Node {
public:
    int key;
    int value;
    Node *prev;
    Node *next;
    Node(int k, int v) {
        key = k;
        value = v;
    }
};

class LRUCache {
private:
    int cap;
    Node* head;
    Node* tail;
    unordered_map<int, Node*> keyNodeMap;

    void addNode(Node* n) {
        Node* beforeTail = tail->prev;

        beforeTail->next = n;
        n->next = tail;
        tail->prev = n;
        n->prev = beforeTail;
    }

    void removeNode(Node* n) {
        Node* prevNode = n->prev;
        Node* nextNode = n->next;

        prevNode->next = nextNode;
        prevNode->prev = prevNode;
    }
public:
    LRUCache(int capacity) {
        cap = capacity;
        head = new Node(0, 0);    
        tail = new Node(0, 0);
        
        head->next = tail;
        tail->prev = head;    
    }
    
    int get(int key) {
        if(keyNodeMap.find(key) == keyNodeMap.end()) {
            // not cached
            return -1;
        }
        Node* oldNode = keyNodeMap.at(key);
        removeNode(oldNode);
        addNode(oldNode);

        return oldNode->value;
    }
    
    void put(int key, int value) {
        if(keyNodeMap.find(key) == keyNodeMap.end()) {
            Node* newNode = new Node(key, value); // cache
            keyNodeMap[key] = newNode;
            addNode(newNode);
        } else {
            Node* oldNode = keyNodeMap.at(key);
            oldNode->value = value;
            removeNode(oldNode);
            addNode(oldNode);
        }
        if(keyNodeMap.size() > cap) {
            Node* nodeToRemove = head->next;
            keyNodeMap.erase(nodeToRemove->key);
            removeNode(nodeToRemove);
        }
    }
};

int main() {
 
    LRUCache* cache = new LRUCache(2);
    cache->put(1, 1);
    cache->put(2, 2);
    cout << cache->get(1) << endl; 	// 1
    cache->put(3, 3);
    cout << cache->get(2) << endl;	// -1 not found
    cache->put(4, 4);
    cout << cache->get(1) << endl; 	// -1
    cout << cache->get(3) << endl; 	// 3
    cout << cache->get(4) << endl; 	// 4

    return 0;
}
