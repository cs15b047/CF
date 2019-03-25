#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
int main(){
	ll n; scanf("%lld",&n);
	vector<ll> a(2*n);
	map<ll,set<ll>>locn;
	for(int i=0;i<2*n;i++){
		scanf("%lld",&a[i]);
		locn[a[i]].insert(i + 1);
	}

	vector<ll> loc1(n + 1), loc2(n + 1);
	loc1[0] = 1;loc2[0] = 1;
	for(auto it:locn){
		loc1[it.first] = *(it.second.begin());
		loc2[it.first] = *(it.second.rbegin());
	}
	ll answer = 0;
	for(int i=1;i<= n;i++){
		answer += abs(loc1[i] - loc1[i-1]);
		answer += abs(loc2[i] - loc2[i-1]);
	}
	cout << answer << endl;

}