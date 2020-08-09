#include<iostream>
using namespace std;

/* Link list node */
struct node *reverse (struct node *head, int k);

struct node
{
    int data;
    struct node* next;
    
    node(int x){
        data = x;
        next = NULL;
    }
    
};

/* UTILITY FUNCTIONS */
/* Function to push a node */

/* Function to print linked list */
void printList(struct node *node)
{
    while (node != NULL)
    {
        printf("%d ", node->data);
        node = node->next;
    }
    printf("\n");
}

/* Drier program to test above function*/
int main(void)
{
    /* Start with the empty list */

     int t;
     cin>>t;
     
     while(t--)
     {
         struct node* head = NULL;
         struct node* temp = NULL;
         int n;
         cin >> n;
         
         for(int i = 0;i<n;i++){
            int value;
            cin >> value;
            if(i == 0)
            {
                head = new node(value);
                temp = head;
            }
            else
            {
                temp->next = new node(value);
                temp = temp->next;
            }
         }
        
        int k;
        cin>>k;
        head = reverse(head, k);

        printList(head);
    
     }
     
     return(0);

}

// } Driver Code Ends
/*
  Reverse a linked list
  The input list will have at least one element  
  Return the node which points to the head of the new LinkedList
  Node is defined as 
    struct node
    {
        int data;
        struct node* next;
    
        node(int x){
            data = x;
            next = NULL;
        }
    
  
    }*head;
*/


struct node *reverse (struct node *head, int k)
{ 
    // Complete this method
  struct node *tmp = head;
  struct node *tmp_head;
  int n=1, e, a[k];
  while(tmp->next!=NULL){
    tmp = tmp->next;
    n++;
  }
  tmp = head;
  for (int i = 0; i < n; i+=k)
  {
    tmp_head = tmp;
    e = (i+k<=n ? k : n%(i+k-1));
    for (int j = 0; j < e; ++j){
      a[j] = tmp->data;
      tmp = tmp->next;
    }
    for (int j = e-1; j >= 0; --j){
      tmp_head->data = a[j];
      tmp_head = tmp_head->next;
    }
  }
  return head;      
}





