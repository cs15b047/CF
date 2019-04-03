#include <bits/stdc++.h>
using namespace std ;
typedef long long int ll ;

int main(){
	ll n; cin >> n;
	vector<ll> parent(n + 1);for(int i=2;i<=n;i++)cin >> parent[i];parent[1] = -1;

	vector<ll> pth;
	ll curr = n;
	while(curr != -1){
		pth.push_back(curr);
		curr = parent[curr];
	}
	reverse(pth.begin(),pth.end());
	for(auto it:pth)cout << it << " ";
}