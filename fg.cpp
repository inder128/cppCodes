#include <iostream>
#include <unordered_map>
using namespace std;

struct Node {
    int key;
    int value;
    Node *next, *pre;
    Node(int key, int value) {
        this->key = key;
        this->value = value;
        next = pre = NULL;
    }
};


class LRUCache {
  private:
    static unordered_map<int, Node *> hsmap;
    static int capacity, count;
    static Node *head, *tail;

  public:
    LRUCache(int cap) {
        capacity = cap;
        count = 0;
    }

    static int get(int key) {
        Node* tmpnode = head;
        while(tmpnode != NULL and tmpnode->key!=key)
            tmpnode = tmpnode->next;
        return (tmpnode != NULL) ? tmpnode->value : -1;
    }

    static void show() {
        Node* tmpnode = head;
        // cout<<count<<" "<<capacity<<endl;
        // cout<<head->key<<" "<<tail->key<<endl;
        while(tmpnode != NULL){
            cout<<tmpnode->key<<"->"<<tmpnode->value<<"   ";
            tmpnode = tmpnode->next;
        }
        cout<<endl;
        return;
    }

    static void del(int key) {
        count--;
        if(count<=0){
          head = new Node(0, 0);
          tail = new Node(0, 0); 
          count = 0;
        } 
        else if(head->key==key){
            head = head->next;
            head->pre = NULL;
        }
        else if(tail->key==key){
            tail = tail->pre;
            tail->next = NULL;
        }
        else{
            Node* tmpnode = head;
            while(tmpnode != NULL and tmpnode->key!=key)
                tmpnode = tmpnode->next;
            (tmpnode->pre)->next = tmpnode->next;
        }   
        return;
    }

    static void set(int key, int value) {
        Node* newtmp = new Node(key, value);
        if(count==0){
            head = newtmp;
            tail = head;
            count++;
            return;
        }  

        Node* tmpnode = head;
        while(tmpnode != NULL and tmpnode->key!=key)
            tmpnode = tmpnode->next;
        if(tmpnode != NULL) del(tmpnode->key);

        
        tail->next = newtmp;
        newtmp->pre = tail;
        tail = newtmp;
        count++;
        
        if(count==capacity+1){
            head = head->next;
            head->pre = NULL;
            count--;
        }
    }
};


// Initializing static members
unordered_map<int, Node *> temp;
int LRUCache::capacity = 0;
Node *LRUCache::head = new Node(0, 0);
Node *LRUCache::tail = new Node(0, 0);
int LRUCache::count = 0;
unordered_map<int, Node *> LRUCache::hsmap = temp;

int main() {
    int t;
    cin >> t;
    while (t--) {

        int capacity;
        cin >> capacity;
        int queries;
        cin >> queries;

        LRUCache *cache = new LRUCache(capacity);
        // cache->show();
        while (queries--) {
            string q;
            cin >> q;
            if (q == "SET") {
                int key;
                cin >> key;
                int value;
                cin >> value;
                cache->set(key, value);
                cout<<"SET "<<key<<" "<<value<<" : ";
                cache->show();

            } else {
                int key;
                cin >> key;
                // cout << cache->get(key) << " ";
                // cout<<"GET "<<key<<" : ";
                // cache->show();
            }
        }

        cout << endl;
    }
    return 0;
} 