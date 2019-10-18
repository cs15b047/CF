#include <bits/stdc++.h>
using namespace std ;

typedef long long int ll ;

vector<ll> parent;

vector<ll> get_pth(ll node){
	vector<ll> ans;
	ll curr = node;
	while(curr != 0){
		ans.push_back(curr);
		curr = parent[curr];
	}
	reverse(ans.begin(), ans.end());
	return ans;
}

int main()
{
	ll n, sum_val; cin >> n >> sum_val;
	parent.resize(n + 1, 0);
	vector<ll> value(n + 1);
	for(int i = 1;i <= n;i++){
		ll side, par, val;
		cin >> par >> side >> val;
		parent[i] = par;
		value[i] = val;
	}
	map<ll,ll> val_node;
	for(int i = 1;i<=n;i++)
		val_node[value[i]] = i;

	ll ans = 1e18;
	for(int i = 1;i <= n;i++){
		ll other_val = sum_val - value[i];
		if(val_node.find(other_val) != val_node.end() && other_val != value[i]){
			ll other_node = val_node[other_val];
			vector<ll> pth1 = get_pth(i), pth2 = get_pth(other_node);
			ll ptr1 = 0, ptr2 = 0;
			while(ptr1 < pth1.size() && ptr2 < pth2.size() && pth1[ptr1] == pth2[ptr2]){
				ptr1++;ptr2++;
			}
			ll tmp = 0;
			for(int i = ptr1;i < pth1.size();i++)
				tmp += value[pth1[i]];
			for(int i = ptr2;i < pth2.size();i++)
				tmp += value[pth2[i]];

			// common ele
			ptr1--;tmp += value[pth1[ptr1]];
			ans = min(ans, tmp);
		}
	}
	if(ans == 1e18)ans = -1;
	cout << ans << endl;
}