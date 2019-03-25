#include <bits/stdc++.h>
using namespace std ;
typedef long long int ll ;
int main(){
	ll n,p;cin>>n>>p;
	vector<ll>b(n+1),d(n+1),indegree(n+1);
	for(int i=0;i<=n;i++){b[i]=0;indegree[i]=0;}
	for(int i=0;i<p;i++){
		ll src,dest,dia;scanf("%lld%lld%lld",&src,&dest,&dia);
		b[src] = dest;d[src]= dia;indegree[dest]++;
	}
	map<ll,bool>vis;vis.clear();
	map<ll,pair<ll,ll>> answer;answer.clear();
	ll ans=0;

	for(int i=1;i<=n;){
		while(i<=n && (vis.find(i) != vis.end() || indegree[i] != 0))i++;
		if(i > n)break;
	
		ll curr=i,mxm=1e9;
		if(b[i] == 0){vis[i]=1;continue;}

		while(vis.find(curr) == vis.end() && b[curr] != 0){
			vis[curr]=1;
			mxm = min(mxm, d[curr]);
			curr = b[curr];
		}
		vis[curr]=1;
		if(b[curr] == 0){
			ans++;
			answer[i] = make_pair(curr, mxm);
		}
	}
	cout << ans << endl;
	for(auto it: answer){
		cout << it.first << " " << it.second.first << " " << it.second.second << endl ;
	}
}