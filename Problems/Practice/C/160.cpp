#include <bits/stdc++.h>
using namespace std ;
typedef long long int ll ;

int main(){
	ll n,m; scanf("%lld%lld",&n,&m);
	vector<ll> arr(n + 1);for(int  i=1;i<=n;i++)scanf("%lld",&arr[i]);
	vector<ll> l(m),r(m),x(m);
	for(int i=0;i<m;i++)scanf("%lld%lld%lld",&l[i],&r[i],&x[i]);

	vector<ll> nxt(n + 1);
	nxt[n] = -1;
	for(int i=n-1;i>=1;i--){
		if(arr[i] == arr[i + 1])nxt[i] = nxt[i + 1];
		else nxt[i] = i + 1;
	}

	vector<ll> answers(m);
	for(int i=0;i<m;i++){
		if(arr[l[i]] != x[i])answers[i] = l[i];
		else{
			if(nxt[l[i]] > r[i] || nxt[l[i]] == -1)answers[i] = -1;
			else answers[i] = nxt[l[i]];
		}
	}
	for(auto it : answers)cout << it << endl;

}