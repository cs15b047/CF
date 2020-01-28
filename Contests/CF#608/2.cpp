#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;

string str;

pair<ll,vector<ll>> calc(char to_be_repl, char repl){
	ll ptr = 0;
	ll cnt = 0;
	vector<ll> pos; pos.clear();
	ll len = str.length();
	while(ptr < len){
		// go till find a W inside
		while(ptr < len && str[ptr] != to_be_repl)ptr++;
		if(ptr >= len)break;
		// invert that
		str[ptr] = repl;
		// invert next
		if(str[ptr + 1] == to_be_repl)str[ptr + 1] = repl;
		else str[ptr + 1] = to_be_repl;
		// store details
		cnt++;
		pos.push_back(ptr);
		ptr++;
	}
	return make_pair(cnt, pos);
}

int main(){
	ll n; cin >> n;
	cin >> str;
	ll w = 0, b = 0;
	ll len = str.length();
	for(int i = 0; i < len;i++){
		if(str[i] == 'W')w++;
		else b++;
	}
	if((w % 2 != 0) && (b % 2 != 0)){
		cout << -1 << endl;
	} else{
		pair<ll, vector<ll>> ans;
		if(w % 2 == 0){
			ans = calc('W', 'B');
		} else{
			ans = calc('B', 'W');
		}
		cout << ans.first << endl;
		for(auto it: ans.second)cout << it + 1 <<" ";cout << endl;
	}
}