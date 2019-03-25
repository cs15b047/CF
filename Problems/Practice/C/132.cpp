#include <bits/stdc++.h>
using namespace std ;
typedef long long int ll ;

int main(){
	ll n; scanf("%lld",&n);
	vector<ll> a(n+1);vector<bool>visited(n+1);
	for(int i=1;i<=n;i++)scanf("%lld",&a[i]) ;
	for(int i=1;i<=n;i++)visited[i] = 0;

	vector<ll> set_repr1, set_repr2;

	map<ll,bool>v2;
	for(int i=1;i<=n;i++){
		if(!visited[i]){
			ll curr = i;
			v2.clear();
			while(visited[curr] == 0 && v2[curr] == 0){
				// cout << curr << endl;
				visited[curr] = 1;v2[curr] = 1;
				curr = a[curr];
			}
			if(v2[curr] == 1){
				if(a[curr] == curr)set_repr1.push_back(curr);
				else set_repr2.push_back(curr);
			}
		}
	}
	// cout << set_repr2.size() << " " << set_repr1.size() << endl;
	ll answer = (ll)set_repr2.size() + max((ll)set_repr1.size() - 1, (ll)0);

	if(!set_repr2.empty()){
		for(int i=0;i<(ll)set_repr2.size() - 1;i++)a[set_repr2[i]] = set_repr2[i + 1];
		if(set_repr1.empty())a[set_repr2.back()] = set_repr2.back();
		else a[set_repr2.back()] = set_repr1[0];
	}
	for(int i=0;i<(ll)set_repr1.size() - 1;i++)a[set_repr1[i]] = set_repr1[i + 1];

	printf("%lld\n",answer );
	for(int i=1;i<=n;i++)cout << a[i] << " ";cout << endl;

}