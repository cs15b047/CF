#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
int main(){
	ll n; cin >> n;
	ll pos=0,neg=0,zer =0;
	vector<ll>a(n);
	for(int i=0;i<n;i++){
		cin >> a[i];
		pos += (a[i] > 0) ;
		neg += (a[i] < 0) ;
		zer += (a[i] == 0) ;
	}
	ll thr = (n/2 + (n % 2));
	if(pos >= thr)cout << 1 << endl;
	else if(neg >= thr)cout << -1 << endl;
	else cout << 0 << endl ;
}