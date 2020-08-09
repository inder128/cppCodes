// #pragma GCC optimize("Ofast")
// #pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")

#include <bits/stdc++.h>
#define ALL(s) (s).begin(), (s).end()
#define rALL(s) (s).rbegin(), (s).rend()
#define sz(s) (int)(s).size()
#define mkp make_pair
#define pb push_back
#define sqr(s) ((s) * (s))

using namespace std;

typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
typedef unsigned int ui;



void solve() {
	int n;
	cin >> n;
	vector<int> ans;
	int s = (int)sqrtl(n);
	cout<<"\n s: " << s << " \n";
	for (int i = 0; i <= s; i++)
		ans.pb(i);
	for (int i = 1; i <= s; i++)
		ans.pb(n / i);
	sort(ALL(ans));
	ans.resize(unique(ALL(ans)) - ans.begin());
	cout << sz(ans) << endl;
	for (int &x : ans)
		cout << x << " ";
	cout << endl;
}

int main() {
	

	int t;
	cin >> t;
	while (t--)
		solve();
}