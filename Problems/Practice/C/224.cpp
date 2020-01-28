#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

bool is_subset(ll num1, ll num2){
	return (((num1 & num2) ^ num1) == 0) ;
}

int main(){
	ll n; scanf("%lld",&n);
	vector<ll> algo_sets(n), skills(n);
	for(int i = 0;i < n;i++)scanf("%lld",&algo_sets[i]);
	for(int i = 0;i < n;i++)scanf("%lld",&skills[i]);
	map<ll, vector<ll>> set_ele;
	for(int i = 0;i < n;i++){
		set_ele[algo_sets[i]].push_back(i);
	}

	// calc info for each distinct algo set
	vector<ll> distinct_sets, cnts, sum_skills;
	for(auto it:set_ele){
		distinct_sets.push_back(it.first);
		cnts.push_back(it.second.size());
		ll tmp = 0;
		for(auto idx: it.second){
			tmp += skills[idx];
		}
		sum_skills.push_back(tmp);
	}

	ll sz = distinct_sets.size();
	queue<ll> q;
	vector<bool> visited(sz, false);
	for(int i = 0;i < sz;i++){
		if(cnts[i] > 1){
			q.push(i);
			visited[i] = true;
		}
	}
	ll answer = 0;
	while(!q.empty()){
		ll top = q.front(); q.pop();
		answer += sum_skills[top];
		for(int i = 0; i < sz; i++){
			if(!visited[i] && is_subset(distinct_sets[i], distinct_sets[top])){
				q.push(i);
				visited[i] = true;
			}
		}
	}
	cout << answer << endl;
}