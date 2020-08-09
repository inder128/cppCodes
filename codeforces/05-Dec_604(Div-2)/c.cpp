#include <iostream>
#define PRIME 998244353
using namespace std;
int main(){
	int N, p;
	long long P = 0, Q = 1;
	for(cin >> N; N; N--){
		cin >> p;
		P = (P + Q) * 100 % PRIME;
		Q = Q * p % PRIME;
	}
	long long q = 1;
	for(long long mask = 1; mask <= PRIME-2; mask<<=1){
		if(mask & (PRIME-2))
			q = q * Q % PRIME;
		Q = Q * Q % PRIME;
	}
	cout << P * q % PRIME << endl;
}