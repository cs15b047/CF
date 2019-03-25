#include <bits/stdc++.h>
using namespace std ;
typedef long long int ll ;
vector<ll>d;
bool cmp(ll i1, ll i2){return d[i1] < d[i2];}
int main(){
	ll n,k;cin>>n>>k;
	d.resize(n+1);vector<ll>ind(n+1);for(int i=1;i<=n;i++)scanf("%lld",&d[i]);

	for(int i=1;i<=n;i++)ind[i]=i;
	stable_sort(ind.begin()+1,ind.end(),cmp);
	map<ll,vector<ll>> dist_pts;
	vector<set<ll>> adj(n+1);
	bool flag = 1;
	dist_pts[0].push_back(ind[1]);
	if(d[ind[1]] != 0 || d[ind[2]] == 0){
		flag = 0;
	}
	else{
		int j = 2;
		int curr_par_dist;
		curr_par_dist = 0;
		while(j <= n){
			while(j <= n && d[ind[j]] == curr_par_dist + 1){
				dist_pts[curr_par_dist + 1].push_back(ind[j]);
				j++;
			}
			vector<ll>vp=dist_pts[curr_par_dist],vc=dist_pts[curr_par_dist + 1];
			if(vc.size() == 0){
				flag = 0;
				break;
			}
			int it2 =0;
			for(int it1=0;it1 < vp.size();it1++){
				int tmp =0;
				while(it2 < vc.size()){
					if(curr_par_dist == 0 && tmp >= k)break;
					else if(curr_par_dist != 0 && tmp >= k-1)break;
					adj[vp[it1]].insert(vc[it2]);
					it2++;tmp++;
				}
			}
			if(it2 != vc.size()){
				flag =0;
				break;
			}
			curr_par_dist++;
		}
	}
	if(flag){
		ll edges = 0;
		for(int i=1;i<=n;i++)edges += adj[i].size();
		cout << edges << endl ;
		for(int i=1;i<=n;i++){
			for(auto it_set:adj[i]){
				cout << i << " " << it_set << endl;
			}
		}
	}
	else{
		cout << -1 << endl;
	}
}