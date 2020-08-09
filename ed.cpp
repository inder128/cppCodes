#include<iostream>
using namespace std;

/* Link list Node */
struct Node {
  int data;
  struct Node *next;
  Node(int x) {
    data = x;
    next = NULL;
  }
};

int intersectPoint(struct Node* head1, struct Node* head2);

void append(struct Node** head_ref, struct Node **tail_ref, int new_data)
{
    struct Node* new_node = new Node(new_data);
    if (*head_ref == NULL)
        *head_ref = new_node;
    else
        (*tail_ref)->next = new_node;
    *tail_ref = new_node;
}

/* Driver program to test above function*/
int main()
{
    int T,i,n1, n2, n3,l,k;

    cin>>T;
    while(T--)
    {
        cin>>n1>>n2>>n3;

        struct Node *head1 = NULL,  *tail1 = NULL;
        for(i=1; i<=n1; i++)
        {
            cin>>l;
            append(&head1, &tail1, l);
        }
        struct Node *head2 = NULL,  *tail2 = NULL;
        for(i=1; i<=n2; i++)
        {
            cin>>l;
            append(&head2, &tail2, l);
        }
        struct Node *head3 = NULL,  *tail3 = NULL;
        for(i=1; i<=n3; i++)
        {
            cin>>l;
            append(&head3, &tail3, l);
        }

        if (tail1 != NULL)
        tail1->next = head3;
        if (tail2 != NULL)
        tail2->next = head3;

        cout << intersectPoint(head1, head2) << endl;
    }
    return 0;
}

// } Driver Code Ends
/* Linked List Node
struct Node {
  int data;
  struct Node *next;
  Node(int x) {
    data = x;
    next = NULL;
  }
}; */

/* Should return data of intersection point of two linked
   lists head1 and head2.
   If there is no intersecting point, then return -1. */
int intersectPoint(Node* head1, Node* head2)
{
    // Your Code Here
    int n=1 ,m=1, l=0;
    struct Node *tmp1 = head1;
    struct Node *tmp2 = head2;
    while(tmp1->next!=NULL){
        n++;
        tmp1 = tmp1->next;
    }
    while(tmp2->next!=NULL){
        m++;
        tmp2 = tmp2->next;
    }
    // cout<<n<<" "<<m<<"\n";
    tmp1 = head1;
    tmp2 = head2;
    if(m<n){
        while(l<n-m){
            l++;
            tmp1 = tmp1->next;
        }
    } else{
        while(l<m-n){
            l++;
            tmp2 = tmp2->next;
        }
    }
    // cout<<tmp1->data<<" "<<tmp2->data<<"\n";
    l = 0;
    while(tmp1!=NULL){
        if(tmp1==tmp2)
            {if(l==-1) l=tmp1->data;}
        else
            l=-1;
       tmp1 = tmp1->next; 
       tmp2 = tmp2->next; 
    }
    return l;
}
















