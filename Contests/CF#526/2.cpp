#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

int main(){
	ll n,s ; cin >> n >> s;
	vector<ll>v(n);
	for(int i=0;i<n;i++)cin >> v[i];
	sort(v.begin(),v.end());
	ll tot = 0 ;
	for(auto it:v)tot += it;
	if(s > tot)cout << -1 << endl ;
	else{
		if(s <= (tot - v[0]*n))cout << v[0] << endl;
		else{
			s  = s - (tot - v[0]*n);
			if(s % n == 0)cout << (v[0] - s/n) << endl ;
			else cout << (v[0] - s/n - 1) << endl ;
		}
	}
}