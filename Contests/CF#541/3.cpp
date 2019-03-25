#include <bits/stdc++.h>
using namespace std ;
typedef long long int ll ;

int main(){
	ll n; cin >> n;
	vector<ll> a(n);
	for(int i=0;i<n;i++)cin >>a[i];
	sort(a.begin(), a.end());
	vector<ll>ans;
	for(int i =0;i<n;i+=2)ans.push_back(a[i]);
	for(int i = n - 1 - (((n-1) % 2) == 0);i>=1;i-=2)ans.push_back(a[i]);
	for(auto it:ans)cout << it<<" " ;
}