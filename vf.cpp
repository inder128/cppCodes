#include <iostream> 
using namespace std; 

struct Node { 
	int data; 
	struct Node* left, *right; 
	Node(int data) { 
		this->data = data; 
		left = right = NULL; 
	} 
}; 

void printInorder(struct Node* node, int *i, int *a) { 
	if (node == NULL) return; 
	printInorder(node->left, i, a); 
	a[(*i)++] = node->data;
	printInorder(node->right, i, a); 
} 

int main() { 
	// const int n=2, o=3;
	// int m=2;
	// int (*p)[n][o] = new int[m][n][o];
	// int (*q)[o];
	// int *r;
	// for (int i = 0; i < m; ++i){
	// 	q = p[i];
	// 	for (int j = 0; j < n; ++j){
	// 		r = q[j];
	// 		for (int k = 0; k < o; ++k)
	// 			cin>>r[k];
	// 	}
	// }
	// for (int i = 0; i < m; ++i){
	// 	q = p[i];
	// 	for (int j = 0; j < n; ++j){
	// 		r = q[j];
	// 		for (int k = 0; k < o; ++k)
	// 			cout<<r[k]<<" ";
	// 		cout<<"\n";
	// 	}
	// 	cout<<"\n";
	// 	cout<<"\n";
	// }
	int p[] = {1,2,3,4,5,6,7,8,9,0,11,12};
	int (*q)[3] = (int (*)[3])p;
	cout<<&p[3]<<endl;
	cout<<q+1<<endl;
	return 0; 
} 
