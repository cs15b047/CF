#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;

vector<ll> s,d,c;

class cmp{
public:
	bool operator () (const ll &a, const ll &b){
		return d[a] < d[b];
	}
};



int main(){
	ll n, m; cin >> n >> m;
	s.resize(m), d.resize(m), c.resize(m);for(int i = 0;i < m;i++)cin >> s[i] >> d[i] >> c[i];
	vector<ll> answer(n + 1, 0);
	vector<set<ll, cmp>> can_study(n + 1);
	// study time constraint
	for(int i = 0;i < m;i++){
		for(int j = s[i];j < d[i];j++){
			can_study[j].insert(i);
		}
	}
	// exam day constr
	for(int i = 0;i < m;i++){
		can_study[d[i]].clear();
		answer[d[i]] = m + 1;
	}

	vector<ll> days_done(m, 0);
	
	for(int i = 1;i <= n;i++){
		// study for upcoming exam, if not any, do nothing
		for(auto it: can_study[i]){
			if(days_done[it] < c[it]){
				answer[i] = it + 1;
				days_done[it]++;
				break;
			}
		}
	}
	bool done = true;
	for(int i = 0;i < m;i++){
		if(days_done[i] < c[i]){
			done = false;
			break;
		}
	}
	if(done){
		for(int i = 1;i <= n;i++)cout << answer[i] << " ";cout << endl;
	} else{
		cout << -1 << endl;
	}
}