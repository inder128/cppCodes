// bst optimising problem

#include <iostream> 

using namespace std;

class node{
	public:
		int v;
		int s;
		int e;
};


int main()
{
	int n;
	cin>>n;
	int v[n], f[n], s[n][n];
	node m[n][n];
	for (int i = 0; i < n; ++i)
		cin>>v[i];
	for (int i = 0; i < n; ++i){
		cin>>f[i];
		s[i][i] = f[i];
	}
	for (int i = 1; i < n; ++i){
		for (int j = 0; j < n-i; ++j){
			s[j][j+i] = s[j][j+i-1] + f[j+i];
			s[j+i][j] = s[j+i-1][j] + f[j+i];
		}
	}
	for (int i = 0; i < n; ++i){
		m[i][i].v = f[i];
		m[i][i].s = 1; m[i][i].e = 1;
	}
	for (int i = 1; i < n; ++i){
		for (int j = 0; j < n-i; ++j){
			m[j][j+i].v = m[j][j+i-1].v + (m[j][j+i-1].e+1)*f[j+i];
			m[j][j+i].e = m[j][j+i-1].e+1;
			m[j][j+i].s = m[j][j+i-1].s;
			if(min(m[j+1][j+i].v + (m[j+1][j+i].s+1)*f[j], m[j][j+i].v) == m[j+1][j+i].v + (m[j+1][j+i].s+1)*f[j]){
				m[j][j+i].v = m[j+1][j+i].v + (m[j+1][j+i].s+1)*f[j];
				m[j][j+i].s = m[j+1][j+i].s+1;
				m[j][j+i].e = m[j+1][j+i].e;
			}
			if(min(m[j][j+i-1].v + s[j][j+i], m[j][j+i].v) == m[j][j+i-1].v + s[j][j+i]){
				m[j][j+i].v = m[j][j+i-1].v + s[j][j+i];
				m[j][j+i].s = m[j][j+i-1].s+1;
				m[j][j+i].e = 1;
			}
			if(min(m[j+1][j+i].v + s[j][j+i], m[j][j+i].v) == m[j+1][j+i].v + s[j][j+i]){
				m[j][j+i].v = m[j+1][j+i].v + s[j][j+i];
				m[j][j+i].s = 1;
				m[j][j+i].e = m[j+1][j+i].e+1;
			}
		}
	}
	cout<<m[0][n-1].v<<endl;
    return 0;
}





// int main()
// {
// 	int n;
// 	cin>>n;
// 	int v[n], f[n], s[n][n];
// 	node m[n][n];
// 	for (int i = 0; i < n; ++i)
// 		cin>>v[i];
// 	for (int i = 0; i < n; ++i){
// 		cin>>f[i];
// 		s[i][i] = f[i];
// 	}
// 	for (int i = 1; i < n; ++i){
// 		for (int j = 0; j < n-i; ++j){
// 			s[j][j+i] = s[j][j+i-1] + f[j+i];
// 			s[j+i][j] = s[j+i-1][j] + f[j+i];
// 		}
// 	}
// 	for (int i = 0; i < n; ++i){
// 		m[i][i].v = f[i];
// 		m[i][i].s = 1; m[i][i].e = 1;
// 	}
// 	for (int i = 1; i < n; ++i){
// 		for (int j = 0; j < n-i; ++j){
// 			if(m[j][j+i-1].e==1){
// 				if(min(s[j][j+i], 2*f[j+i]) == s[j][j+i]){
// 					m[j][j+i].v = m[j][j+i-1].v + s[j][j+i];
// 					m[j][j+i].e = 1;
// 					m[j][j+i].s = m[j][j+i-1].s + 1;
// 				} else{
// 					m[j][j+i].v = m[j][j+i-1].v + 2*f[j+i];
// 					m[j][j+i].e = 2;
// 					m[j][j+i].s = m[j][j+i-1].s;
// 				}
// 			} else{
// 				m[j][j+i].v = m[j][j+i-1].v + (m[j][j+i-1].e+1)*f[j+i];
// 				m[j][j+i].e = m[j][j+i-1].e+1;
// 				m[j][j+i].s = m[j][j+i-1].s;
// 			}
// 			if(m[j+1][j+i].s==1){
// 				if(min(m[j+1][j+i].v + min(s[j][j+i], 2*f[j]), m[j][j+i].v) == m[j+1][j+i].v + s[j][j+i]){
// 					m[j][j+i].v = m[j+1][j+i].v + s[j][j+i];
// 					m[j][j+i].s = 1;
// 					m[j][j+i].e = m[j+1][j+i].e + 1;
// 				} else if(min(m[j+1][j+i].v + 2*f[j], m[j][j+i].v) == m[j+1][j+i].v + 2*f[j]){
// 					m[j][j+i].v = m[j+1][j+i].v + 2*f[j];
// 					m[j][j+i].s = 2;
// 					m[j][j+i].e = m[j+1][j+i].e;
// 				}
// 			} else if(min(m[j+1][j+i].v + (m[j+1][j+i].s+1)*f[j], m[j][j+i].v) == m[j+1][j+i].v + (m[j+1][j+i].s+1)*f[j]){
// 				m[j][j+i].v = m[j+1][j+i].v + (m[j+1][j+i].s+1)*f[j];
// 				m[j][j+i].s = m[j+1][j+i].s+1;
// 				m[j][j+i].e = m[j+1][j+i].e;
// 			}
// 			if(min(m[j][j+i-1].v + s[j][j+i], m[j][j+i].v) == m[j][j+i-1].v + s[j][j+i]){
// 				m[j][j+i].v = m[j][j+i-1].v + s[j][j+i];
// 				m[j][j+i].s = m[j][j+i-1].s+1;
// 				m[j][j+i].e = 1;
// 			}
// 			if(min(m[j+1][j+i].v + s[j][j+i], m[j][j+i].v) == m[j+1][j+i].v + s[j][j+i]){
// 				m[j][j+i].v = m[j+1][j+i].v + s[j][j+i];
// 				m[j][j+i].s = 1;
// 				m[j][j+i].e = m[j+1][j+i].e+1;
// 			}
// 		}
// 	}
// 	cout<<m[0][n-1].v<<endl;
//     return 0;
// }




// int main()
// {
// 	int n;
// 	cin>>n;
// 	int v[n], f[n], s[n][n];
// 	node m[n][n];
// 	for (int i = 0; i < n; ++i)
// 		cin>>v[i];
// 	for (int i = 0; i < n; ++i){
// 		cin>>f[i];
// 		s[i][i] = f[i];
// 	}
// 	for (int i = 1; i < n; ++i){
// 		for (int j = 0; j < n-i; ++j){
// 			s[j][j+i] = s[j][j+i-1] + f[j+i];
// 			s[j+i][j] = s[j+i-1][j] + f[j+i];
// 		}
// 	}
// 	for (int i = 0; i < n; ++i){
// 		m[i][i].v = f[i];
// 		m[i][i].s = 1; m[i][i].e = 1;
// 	}
// 	cout<<endl;
// 	for (int i = 1; i < n; ++i){
// 		for (int j = 0; j < n-i; ++j){
// 			cout<<"i: "<<i<<" j: "<<j<<"\n";
// 			if(m[j][j+i-1].e==1){
// 				if(min(s[j][j+i], 2*f[j+i]) == s[j][j+i]){
// 					m[j][j+i].v = m[j][j+i-1].v + s[j][j+i];
// 					m[j][j+i].e = 1;
// 					m[j][j+i].s = m[j][j+i-1].s + 1;
// 					cout<<m[j][j+i].v<<" a\n";
// 				} else{
// 					m[j][j+i].v = m[j][j+i-1].v + 2*f[j+i];
// 					m[j][j+i].e = 2;
// 					m[j][j+i].s = m[j][j+i-1].s;
// 					cout<<m[j][j+i].v<<" b\n";
// 				}
// 			} else{
// 				m[j][j+i].v = m[j][j+i-1].v + (m[j][j+i-1].e+1)*f[j+i];
// 				m[j][j+i].e = m[j][j+i-1].e+1;
// 				m[j][j+i].s = m[j][j+i-1].s;
// 				cout<<m[j][j+i].v<<" c\n";
// 			}
// 			if(m[j+1][j+i].s==1){
// 				if(min(m[j+1][j+i].v + min(s[j][j+i], 2*f[j]), m[j][j+i].v) == m[j+1][j+i].v + s[j][j+i]){
// 					m[j][j+i].v = m[j+1][j+i].v + s[j][j+i];
// 					m[j][j+i].s = 1;
// 					m[j][j+i].e = m[j+1][j+i].e + 1;
// 					cout<<m[j][j+i].v<<" d\n";
// 				} else if(min(m[j+1][j+i].v + 2*f[j], m[j][j+i].v) == m[j+1][j+i].v + 2*f[j]){
// 					m[j][j+i].v = m[j+1][j+i].v + 2*f[j];
// 					m[j][j+i].s = 2;
// 					m[j][j+i].e = m[j+1][j+i].e;
// 					cout<<m[j][j+i].v<<" e\n";
// 				}
// 			} else if(min(m[j+1][j+i].v + (m[j+1][j+i].s+1)*f[j], m[j][j+i].v) == m[j+1][j+i].v + (m[j+1][j+i].s+1)*f[j]){
// 				m[j][j+i].v = m[j+1][j+i].v + (m[j+1][j+i].s+1)*f[j];
// 				m[j][j+i].s = m[j+1][j+i].s+1;
// 				m[j][j+i].e = m[j+1][j+i].e;
// 				cout<<m[j][j+i].v<<" f\n";
// 			}
// 			if(min(m[j][j+i-1].v + s[j][j+i], m[j][j+i].v) == m[j][j+i-1].v + s[j][j+i]){
// 				m[j][j+i].v = m[j][j+i-1].v + s[j][j+i];
// 				m[j][j+i].s = m[j][j+i-1].s+1;
// 				m[j][j+i].e = 1;
// 				cout<<m[j][j+i].v<<" g\n";
// 			}
// 			if(min(m[j+1][j+i].v + s[j][j+i], m[j][j+i].v) == m[j+1][j+i].v + s[j][j+i]){
// 				m[j][j+i].v = m[j+1][j+i].v + s[j][j+i];
// 				m[j][j+i].s = 1;
// 				m[j][j+i].e = m[j+1][j+i].e+1;
// 				cout<<m[j][j+i].v<<" h\n";
// 			}
// 		}
// 	}
// 	cout<<endl;cout<<endl;
// 	for (int i = 0; i < n; ++i){
// 		for (int j = 0; j < n; ++j){
// 			cout<<s[i][j]<<" ";
// 		}
// 		cout<<endl;
// 	}
// 	cout<<endl;cout<<endl;	
// 	for (int i = 0; i < n; ++i){
// 		for (int j = 0; j < n; ++j){
// 			if(j<i) 
// 				cout<<"0 ";
// 			else
// 				cout<<m[i][j].v<<" ";
// 		}
// 		cout<<endl;
// 	}
// 	cout<<endl;cout<<endl;
// 	for (int i = 0; i < n; ++i){
// 		for (int j = 0; j < n; ++j){
// 			if(j<i) 
// 				cout<<"0 ";
// 			else
// 				cout<<m[i][j].s<<" ";
// 		}
// 		cout<<endl;
// 	}
// 	cout<<endl;cout<<endl;
// 	for (int i = 0; i < n; ++i){
// 		for (int j = 0; j < n; ++j){
// 			if(j<i) 
// 				cout<<"0 ";
// 			else
// 				cout<<m[i][j].e<<" ";
// 		}
// 		cout<<endl;
// 	}
// 	cout<<endl;cout<<endl;		
// 	cout<<m[0][n-1].v<<endl;
//     return 0;
// }