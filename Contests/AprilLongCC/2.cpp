#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

int main(){
	ll t; cin >>t;
	for(int q = 0;q < t; q++){
		ll n; cin >> n;
		string str;cin >>str;char x;cin >> x;
		set<ll> locations;for(int i=0;i<str.length();i++){if(str[i] == x)locations.insert(i+1);}
		locations.insert(0);
		ll prev_it =0, answer = 0;
		for(auto it:locations){
			if(it == 0){prev_it = 0;continue;}
			else{
				answer += (it - prev_it) * (n - it + 1);
				prev_it = it;
			}
		}
		cout << answer << endl;
	}
}