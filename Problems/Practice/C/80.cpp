#include <bits/stdc++.h>
using namespace std ;
typedef long long int ll ;
vector<vector<ll>> adj;
int main(){
	ll n;scanf("%lld",&n);
	adj.clear();adj.resize(n+1);
	vector<ll> a(n+1);for(int i=1;i<=n;i++)scanf("%lld",&a[i]);
	for(int i=1;i<n;i++){
		ll s,d;
		scanf("%lld%lld",&s,&d);
		adj[s].push_back(d);adj[d].push_back(s);
	}
	map<ll,ll> cst_vtx;
	for(int i=1;i<=n;i++)cst_vtx[a[i]+2]++;
	ll ans = 1e18;
	for(int i=1;i<=n;i++){
		vector<ll> nbhs = adj[i];
		map<ll,ll> tmp;tmp.clear();
		
		tmp[a[i]+2]--;
		tmp[a[i]]++;
		for(auto it:nbhs){
			tmp[a[it]+2]--;
			tmp[a[it]+1]++;
		}
		// cout << i << endl;
		// for(auto it: tmp)cout << it.first << " " << it.second << endl ;

		ll p1 = 1e18,p2=1e18;
		for(auto it = tmp.rbegin();it != tmp.rend();it++){
			if(it->second + cst_vtx[it->first] > 0){
				p1 = min(p1, it->first);
				break;
			}
		}
		for(auto it = cst_vtx.rbegin();it != cst_vtx.rend();it++){
			if(it->second + tmp[it->first] > 0){
				p2 = min(p2, it->first);
				break;
			}
		}
		ans = min(ans,max(p1,p2));
		
		// ans = min(ans, cst_vtx.rbegin()->first);

		// cst_vtx[a[i]]--;
		// if(cst_vtx[a[i]]==0)cst_vtx.erase(a[i]);
		// cst_vtx[a[i]+2]++;
		// for(auto it:nbhs){
		// 	cst_vtx[a[it]+1]--;
		// 	if(cst_vtx[a[it]+1]==0)cst_vtx.erase(a[it]+1);
		// 	cst_vtx[a[it]+2]++;
		// }
	}

	printf("%lld\n",ans );





}