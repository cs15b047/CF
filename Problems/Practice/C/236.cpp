#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

int main(){
	ll num_vtx, num_edges;
	cin >> num_vtx >> num_edges;
	vector<set<ll>> adj_list(num_vtx + 1), reverse_adj_list(num_vtx + 1);
	ll src, dest;
	for(int i = 0;i < num_edges;i++){
		cin >> src >> dest;
		adj_list[src].insert(dest);
		reverse_adj_list[dest].insert(src);
	}

	ll pth_len;
	cin >> pth_len;
	vector<ll> pth(pth_len);
	for(int i = 0;i < pth_len;i++)
		cin >> pth[i];

	// dist of all nodes to dest
	vector<ll> dist(num_vtx + 1, -1);
	queue<ll> q;
	dist[pth.back()] = 0;
	q.push(pth.back());
	while(!q.empty()){
		ll top = q.front();
		q.pop();
		for(auto nbh: reverse_adj_list[top]){
			if(dist[nbh] == -1){
				dist[nbh] = dist[top] + 1;
				q.push(nbh);
			}
		}
	}
	// calc optimal nbhs at each point in the path and calc ans based on that
	ll mnm_ans = 0, mxm_ans = 0;
	for(int i = 0;i < pth_len - 1;i++){
		// cout << pth[i] <<": ";
		set<ll> opt_nbhs;opt_nbhs.clear();
		for(auto nbh: adj_list[pth[i]]){
			if(dist[nbh] == (dist[pth[i]] - 1)){
				opt_nbhs.insert(nbh);
			}
		}
		// for(auto it:opt_nbhs)cout << it << " ";cout << endl;

		bool optimal = (dist[pth[i + 1]] == (dist[pth[i]] - 1));

		if(!optimal)
			mnm_ans++;
		mxm_ans += (((ll)(opt_nbhs.size()) - (ll)optimal) != 0);
	}
	cout << mnm_ans << " " << mxm_ans << endl;
}