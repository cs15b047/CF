// Computing answer by rerooting tree at all nodes, in total linear time
// https://codeforces.com/problemset/problem/1324/F
#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;

ll num_vtx;
vector<ll> color;
vector<set<ll>> adj_list;

vector<ll> rooted_ans;
vector<ll> answer;

void take_input(){
	scanf("%lld",&num_vtx);

	rooted_ans.resize(num_vtx + 1);
	answer.resize(num_vtx + 1);

	color.clear(); color.resize(num_vtx + 1, 0);
	adj_list.clear(); adj_list.resize(num_vtx + 1);
	for(int i = 1;i <= num_vtx;i++) scanf("%lld",&color[i]);
	for(int i = 1;i <= num_vtx - 1;i++){
		ll src, dest; scanf("%lld%lld", &src, &dest);
		adj_list[src].insert(dest);
		adj_list[dest].insert(src);
	}
}

void populate_rooted_ans(ll node, ll parent){
	rooted_ans[node] = 2 *color[node] - 1;
	for(auto nbh: adj_list[node]){
		if(nbh != parent){
			populate_rooted_ans(nbh, node);
			rooted_ans[node] += max((ll)0, rooted_ans[nbh]);
		}
	}
}


void reroot(ll node, ll parent){
	answer[node] = rooted_ans[node];
	for(auto nbh: adj_list[node]){
		if(nbh != parent){
			// change root from node to nbh
			rooted_ans[node] -= max((ll)0, rooted_ans[nbh]);
			rooted_ans[nbh] += max((ll)0, rooted_ans[node]);
			
			reroot(nbh, node);
			
			// switch back
			rooted_ans[nbh] -= max((ll)0, rooted_ans[node]);
			rooted_ans[node] += max((ll)0, rooted_ans[nbh]);
		}
	}
}

void print(vector<ll>& vec){
	for(int i = 1;i < vec.size();i++){
		cout << vec[i] << " ";
	}
	cout << endl;
}

int main(){
	take_input();
	populate_rooted_ans(1, -1);
	// print(rooted_ans);
	reroot(1, -1);
	print(answer);

	
	return 0;
}