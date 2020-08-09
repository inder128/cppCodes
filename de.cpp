#include <iostream>
using namespace std;

struct Node{
    int data;
    struct Node * next;
    struct Node * bottom;
    
    Node(int x){
        data = x;
        next = NULL;
        bottom = NULL;
    }
    
};


void printList(Node *Node)
{
    while (Node != NULL)
    {
        printf("%d ", Node->data);
        Node = Node->bottom;
    }
}

Node* flatten (Node* root);

int main(void) {

    int t;
    cin>>t;
    while(t--){
    int n,m,flag=1,flag1=1;
    struct Node * temp=NULL;
    struct Node * head=NULL;
    struct Node * pre=NULL;
    struct Node * tempB=NULL;
    struct Node * preB=NULL;
        cin>>n;
        int work[n];
        for(int i=0;i<n;i++)
            cin>>work[i];
        for(int i=0;i<n;i++){
            m=work[i];
            --m;
            int data;
            scanf("%d",&data);
            temp = new Node(data);
            temp->next = NULL;
            temp->bottom = NULL;
            
            if(flag){
                head = temp;
                pre = temp;
                flag = 0;
                flag1 = 1;
            }
            else{
                pre->next = temp;
                pre = temp;
                flag1 = 1;
            }
            for(int j=0;j<m;j++){
                
                int temp_data;
                scanf("%d",&temp_data);
                tempB = new Node(temp_data);

                if(flag1){
                    temp->bottom=tempB;
                    preB=tempB;
                    flag1=0;
                }
                else{
                    preB->bottom=tempB;
                    preB=tempB;
                }
            }
        }
           Node *fun = head;
           Node *fun2=head;

            Node* root = flatten(head);
            printList(root);
            cout<<endl;

    }
    return 0;
}
// } Driver Code Ends
/* Node structure  used in the program

struct Node{
    int data;
    struct Node * next;
    struct Node * bottom;
    
    Node(int x){
        data = x;
        next = NULL;
        bottom = NULL;
    }
    
};
*/

/*  Function which returns the  root of 
    the flattened linked list. */
Node *flatten(Node *root)
{
   // Your code here
    int c = 0;
    struct Node *tmpr = root;
    struct Node *tmpb;

    while(tmpr!=NULL){
        tmpb = tmpr;
        while(tmpb!=NULL){
            c++;
            tmpb = tmpb->bottom;
        }
        tmpr = tmpr->next;
    }

    int a[c];


    c=0;
    tmpr = root;

    while(tmpr!=NULL){
        tmpb = tmpr;
        while(tmpb!=NULL){
            a[c] = tmpb->data;
            c++;
            tmpb = tmpb->bottom;
        }
        tmpr = tmpr->next;
    }

    sort(a, a+c);

    root = new Node(a[0]);
    tmpr = root;

    for (int i = 1; i < c; ++i){
        tmpr->bottom = new Node(a[i]);
        tmpr = tmpr->bottom;
    }

    return root;
}











