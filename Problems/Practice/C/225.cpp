#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

bool possible;
ll n, m;
vector<set<ll>> adj_list;
vector<ll> assignment;
set<ll> set1, set2, set3, intmdt_set;

bool cmp(set<ll> st1, set<ll> st2){
	for(auto it:st2){
		if(adj_list[it] != st1){
			possible = false;
			return false;
		}
	}
	 return true;
}

// Phase I: Calculate set1 and union of set 2 and set3
void phase1(){
	if(!possible)return;
	for(int i = 1;i <= n;i++){
		if(adj_list[1].find(i) != adj_list[1].end()){
			intmdt_set.insert(i);
		} else{
			set1.insert(i);
		}
	}
	// check if set1 is valid:, ie. all have same nbhs  => those of 1
	bool poss = cmp(intmdt_set, set1);
	if(!poss){
		possible = false;
		return;
	}
	//assign
	for(auto it: set1)assignment[it] = 1;
}

void phase2(){
	if(!possible)return;
	// del all set1 edges
	for(auto it: intmdt_set){
		for(auto v1: set1)adj_list[it].erase(v1);
	}
	ll vtx = *intmdt_set.begin();
	for(auto it:intmdt_set){
		if(adj_list[vtx].find(it) != adj_list[vtx].end()){
			set3.insert(it);
		} else{
			set2.insert(it);
		}
	}
	// check if set2 is valid:, ie. all have same nbhs  => those of 1
	bool poss1 = cmp(set3, set2);
	bool poss2 = cmp(set2, set3);

	if(!poss1 || !poss2 || set3.empty()){
		possible = false;
		return;
	}

	possible = true;
	for(auto it:set2)assignment[it] = 2;
	for(auto it:set3)assignment[it] = 3;
}


int main(){
	scanf("%lld%lld",&n, &m);
	adj_list.resize(n + 1);
	assignment.resize(n + 1, -1);
	for(int i = 1; i <= m; i++){
		ll src, dest; scanf("%lld%lld",&src,&dest);
		adj_list[src].insert(dest);
		adj_list[dest].insert(src);
	}

	// if(m == 0){
	// 	for(int i = 1;i <= n; i++)cout << 1 << " ";cout << endl;
	// 	return 0;
	// }

	// init
	possible = true;

	// CHECK for 0 degrees of any vtx
	bool any_0_degree = false;
	for(int i = 1;i <= n;i++){
		if(adj_list[i].empty()){
			any_0_degree = true;
			possible = false;
			break;
		}
	}

	phase1();
	phase2();

	// for(auto it: set1)cout << it << " "; cout << endl;
	// for(auto it: set2)cout << it << " "; cout << endl;
	// for(auto it: set3)cout << it << " "; cout << endl;

	if(possible){
		for(int i = 1;i <= n;i++)cout << assignment[i] << " ";cout << endl;
	} else{
		cout << -1 << endl;
	}


}