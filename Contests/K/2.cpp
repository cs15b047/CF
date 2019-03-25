#include <bits/stdc++.h>
using namespace std ;

typedef long long int ll ;

int main(){
	ll t;scanf("%lld",&t);
	for(int q=0;q<t;q++){
		ll v,e;scanf("%lld%lld",&v,&e);
		vector<vector<pair<ll,ll>>>adj(v+1);
		map<ll,ll> store;
		for(int i=0;i<e;i++){
			ll s,d,cst;scanf("%lld%lld%lld",&s,&d,&cst);
			adj[s].push_back(make_pair(cst,d));
			adj[d].push_back(make_pair(cst,s));
			if(cst == 0){store[s] = d ;store[d] = s ;}
		}
		for(int i=1;i<=v;i++){
			sort(adj[i].begin(),adj[i].end());
		}
		map<ll,vector<ll>> edges ;
		for(int i=1;i<=v;i++){
			ll nbh = adj[i][0].second;
			edges[i].push_back(nbh);
			if(adj[i][0].first != 0 && store.find(nbh) != store.end())
				edges[i].push_back(store[nbh]);
		}
		// for(int i=1;i<=v;i++){
		// 	cout << i << " "<< edges[i][0] << " ";
		// }
		// cout << endl ;

		map<ll,bool> vis ;
		map<ll,ll> comp ;
		int curr = 1,curr_comp=0;
		while(vis.size() < v){
			int tmp = 1;
			while(vis.find(tmp) != vis.end())tmp++;
			curr = tmp ;
			map<ll,bool> vis2;
			vis2.clear();
			vis2[curr] = true;
			int flag = 0;
			vector<ll>pth;pth.clear();
			pth.push_back(curr);
			ll trgt = -1;
			while(1){
				if(vis.find(edges[curr][0]) == vis.end() && vis2.find(edges[curr][0]) == vis2.end()){
					vis2[edges[curr][0]] = true;					
					// cout << curr << endl ;
					pth.push_back(edges[curr][0]);
					curr = edges[curr][0] ;
				}
				else if(vis.find(edges[curr][0]) == vis.end() && vis2.find(edges[curr][0]) != vis2.end()){					
					break ;
				}
				else{
					flag = 1;
					trgt = comp[edges[curr][0]];
					break ;
				}
			}
			// cout << pth.size()<<endl;
			// for(auto it: pth)cout << it << " ";
			// cout <<endl;
			// cout<< flag << endl ;
			for(auto it: pth)vis[it] = true;
			if(flag == 0){
				for(auto it: pth)comp[it] = curr_comp;
				curr_comp++;
			}
			else{
				for(auto it: pth)comp[it] = trgt;
			}
		}
		// cout<<"#COmp="<<curr_comp<<endl;
		ll ans = 1 ;
		for(auto it: edges){
			if(it.second.size() == 2)ans *= 2;
		}
		ans = ans * (ll)pow(2, curr_comp) ;
		printf("Case #%d: %lld\n",(q+1),ans );
	}
}