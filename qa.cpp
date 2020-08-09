#include<iostream>
using namespace std;

/* Link list Node */
struct Node {
    int data;
    struct Node* next;

    Node(int x){
        data = x;
        next = NULL;
    }
};

void append(struct Node** head_ref, struct Node **tail_ref, int new_data){
    struct Node* new_node = new Node(new_data);  
    // (new x) returns the addres of x.
    // Node(x) doesn't return addres of a Node, it returns Node itself.
    // new_node is an addres to a node.
    
    if (*head_ref == NULL)
       *head_ref = new_node;
    else
       (*tail_ref)->next = new_node;
    *tail_ref = new_node;
    // cout<<tail_ref<<" "<<*tail_ref<<" "<<(*tail_ref)->data<<" "<<(*(*tail_ref)).data<<"\n";
    // tail_ref (a double pointer to a Node) is addres which contains x. x is a addres which contains a Node.
    // (*tail_ref)->data means 'data' variable of the data structure stored at the addres '(*tail_ref)'.
    // (*(*tail_ref)).data means 'data' variable of the data structure '(*(*tail_ref))'.
}


/* Function to get the middle of the linked list*/
int getMiddle(struct Node *head);

/* Driver program to test above function*/
int main(){
    int T,i,n,l;
    cin>>T;
    while(T--){
        struct Node *head = NULL,  *tail = NULL;
        cin>>n;
        for(i=1;i<=n;i++){
            cin>>l;
            append(&head, &tail, l);
        }
    printf("%d\n", getMiddle(head));
    }
    return 0;
}


int getMiddle(Node *head){
    struct Node* tmp_node = head;
    struct Node* mid_node = head;
    while(1){
        head = head->next;
        if(head==NULL) break;
        mid_node = mid_node->next;
        head = head->next;
        if(head==NULL) break;
    }
    return mid_node->data;
}