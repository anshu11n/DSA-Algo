#include<bits/stdc++.h>
using namespace std;
#define ll long long

// Doubly linked list, hashmap, head and tail node* pointer

struct Node{
    int key, val;
    Node* prev;
    Node* next;

    Node(int key, int val){
        this->key = key;
        this->val = val;
        this->next=NULL;
        this->prev=NULL;
    }
};

class LRUCache {
    unordered_map<int, Node*> hash;
    int cap;

    Node* head = new Node(-1, -1);
    Node* tail = new Node(-1, -1);

    void deleteNode(Node* &node){
        Node* prevNode = node->prev;
        Node* nextNode = node->next;

        prevNode->next = nextNode;
        nextNode->prev = prevNode;

        node->next=NULL;
        node->prev=NULL;
    }

    void insertAfterHead(Node* &node, Node* &head){
        Node* nextNode = head->next;
        head->next = node;
        node->prev = head;
        node->next = nextNode;
        nextNode->prev = node;
    }

public:
    LRUCache(int capacity) {
        cap = capacity;
        hash.clear();
        head->next = tail;
        tail->prev = head;
    }
    
    int get(int key) {
        if(hash.find(key) == hash.end()){
            return -1;
        }

        int num = hash[key]->val;
        Node* node = hash[key];
        deleteNode(node);
        insertAfterHead(node, head);

        return num;
    }
    
    void put(int key, int value) {
        if(hash.find(key) == hash.end()){
            if(hash.size() == cap && hash.size() != 0){
                Node* delNode = tail->prev; 
                deleteNode(delNode);
                hash.erase(delNode->key);
            }

            Node* newNode = new Node(key, value);
            hash[key] = newNode;
            insertAfterHead(newNode, head);
        }else{
            Node* node = hash[key];
            hash[key]->val = value;
            deleteNode(node);
            insertAfterHead(node, head);
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */

void solve(){
    
}

int main(){
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    int t;
    cin>>t;
    while(t--){
        solve();
    }
    return 0;
}