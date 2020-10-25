#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

vector<ll> arr;

class cmp{
public:
	bool operator()(ll idx1, ll idx2){
		return arr[idx1] < arr[idx2];
	}
};

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	ll n, k; cin >> n >> k;
	arr.resize(n);for(int i = 0;i < n;i++)cin >> arr[i];
	set<ll, cmp> remn_ele;for(int i = 0;i < n;i++)remn_ele.insert(i);

	vector<ll> nxt(n);for(int i = 0;i < n;i++)nxt[i] = i + 1;
	vector<ll> prev(n);for(int i = 0;i < n;i++)prev[i] = i - 1;
	vector<ll> team(n);
	ll remn = n, step = 0;
	while(remn > 0){
		ll strt_idx = *remn_ele.rbegin();
		remn_ele.erase(strt_idx);
		team[strt_idx] = step;
		remn--;

		ll fwd, bck;
		ll curr = strt_idx;
		for(int i = 0;i < k;i++){
			if(nxt[curr] < n){
				remn_ele.erase(nxt[curr]);
				team[nxt[curr]] = step;
				remn--;

				curr = nxt[curr];
			} else break;
		}
		fwd = nxt[curr];

		curr = strt_idx;
		for(int i = 0;i < k;i++){
			if(prev[curr] >= 0){
				remn_ele.erase(prev[curr]);
				team[prev[curr]] = step;
				remn--;
				
				curr = prev[curr];
			} else break;
		}
		bck = prev[curr];
		if(bck >= 0 && bck < n){
			nxt[bck] = fwd;
		}
		if(fwd >= 0 && fwd < n){
			prev[fwd] = bck;
		}

		step = (step + 1) % 2;
	}
	string answer = "";
	for(auto it:team)cout << it + 1;cout << endl;

}