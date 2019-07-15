#include <bits/stdc++.h>
using namespace std ;
typedef long long int ll ;

int main(){
	ll n; cin >> n;
	vector<ll> starts(26, 0);for(int i=0;i<n;i++){string str; cin >> str; starts[str[0]-'a']++;}
	ll answer = 0;
	for(int i=0;i<26;i++){
		if(starts[i] > 0){
			ll x1 = starts[i]/2, x2 = starts[i] - x1;
			answer += (x1*(x1 - 1))/2 + (x2*(x2 - 1))/2 ;
		}
	}
	cout << answer << endl;
}