#include <bits/stdc++.h>
using namespace std ;
typedef long long int ll ;
vector<ll> a;
bool cmp(ll x, ll y){return a[x]<a[y];}
int main(){
	ll n;cin>>n;
	vector<ll>ind(n+1);
	a.resize(n+1);
	for(int i=1;i<=n;i++)cin>>a[i];
	for(int i=1;i<=n;i++)ind[i]=i;
	sort(ind.begin()+1, ind.end(),cmp);
	// for(auto it: ind)cout << it <<" ";
	// cout<<endl;
	bool win[100001]={},vis[100001]={};
	vis[ind[n]]=1;
	win[ind[n]]=0;
	for(int i=n-1;i>=1;i--){
		vis[ind[i]] =1;
		ll index = ind[i];
		ll val = i;
		ll k = -(index/val);
		if(index + k*val <=0)k++;
		// cout << i<<" " << index << " "<<val <<" "<<k <<endl;
		for(;index + k*val <= n;k++){
			if(k==0)continue;
			if(vis[index+k*val]==1 && win[index+k*val]==0){
				win[index] = 1;
				break;
			}
		}
	}
	for(int i=1;i<=n;i++){
		if(win[i])cout << "A";
		else cout << "B";
	}
	cout <<endl ;
	
}