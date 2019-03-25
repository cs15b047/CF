#include <bits/stdc++.h>
using namespace std ;

typedef long long int ll ;

int main(){
	ll m;cin>>m;
	ll q= 100000000000;
	for(int i=0;i<m;i++){
		ll tmp;
		scanf("%lld",&tmp);
		q = min(q,tmp);
	}
	ll n;cin>>n;
	vector<ll>a(n);
	for(int i=0;i<n;i++)scanf("%lld",&a[i]);

	sort(a.begin(),a.end(),greater<ll>());

	int curr = 0 ;
	ll ans = 0;
	while(curr < n){
		int temp = curr ; 
		while(temp < n && temp < curr + q){
			ans += a[temp];
			temp++;
		}
		curr += (q + 2);
	}

	cout<< ans << endl ;


}