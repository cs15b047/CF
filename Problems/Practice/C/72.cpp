#include <bits/stdc++.h>
using namespace std ;

typedef long long int ll ;
vector<set<ll>> adj;
vector<ll>cycle;
map<ll,bool> vis;
bool flag = 0;
void get_cycle(ll root, ll prev){
	vis[root] = true;
	cycle.push_back(root);
	for(auto nbh: adj[root]){
		if(flag == 1)return ;
		if(nbh != prev && vis.find(nbh) != vis.end()){
			flag = 1;
			cycle.push_back(nbh);
			int i=0;
			while(cycle[i] != nbh)i++;
			vector<ll> act_cycle(cycle.begin()+i+1,cycle.end());cycle = act_cycle;
			return;
		}
		else if(nbh != prev){
			get_cycle(nbh, root);
			if(flag == 1)return ;
		}
	}
	cycle.pop_back();
}

void delete_edges(vector<ll> orig_cyc){
	ll len = orig_cyc.size();
	for(int i=0;i<len;i++){
		adj[orig_cyc[i]].erase(orig_cyc[(i+1)%len]);
		adj[orig_cyc[(i+1)%len]].erase(orig_cyc[i]);
	}
}

int main(){
	ll n,m;cin>>n>>m;
	adj.clear();
	adj.resize(n+1);
	for(int i=1;i<=m;i++){
		ll s,d;cin>>s>>d;
		adj[s].insert(d);adj[d].insert(s);
	}
	map<int,int>visits;
	cycle.clear();vis.clear();flag=0;
	get_cycle(1,-1);
	vector<ll>orig_cyc = cycle;
	// for(auto it:orig_cyc)cout << it << " ";
	cout<< endl;
	if(flag == 1){
		adj[orig_cyc[0]].erase(orig_cyc[1]);
		adj[orig_cyc[1]].erase(orig_cyc[0]);
		cycle.clear();vis.clear();flag=0;
		get_cycle(1,-1);
		// for(auto it:cycle)cout << it << " ";
		// cout<< endl;
		if(flag == 1){
			cout << "NO"<<endl;
		}
		else{
			if(vis.size()==n)cout << "FHTAGN!"<<endl;
			else cout << "NO"<<endl;
		}
	}
	else{
		cout << "NO"<<endl;
	}



	

}