#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

int main(){
	ll t; cin >> t;
	for(int q = 0;q < t; q++){
		string s, t; cin >> s >> t;

		map<char, vector<ll>> char_posns;
		for(int i = 0;i < s.length();i++){
			char_posns[s[i]].push_back(i);
		}
		// for(auto it: char_posns){
		// 	cout << it.first << " :";
		// 	for(auto it2: it.second)cout << it2 << " ";cout << endl;
		// }
		ll ptr_t = 0, ptr_s;
		ll answer = 0;
		while(ptr_t < t.length()){
			if(char_posns.find(t[ptr_t]) == char_posns.end()){
				answer = -1;
				break;
			}
			ptr_s = char_posns[t[ptr_t]][0];
			ptr_t++;
			while(ptr_t < t.length()){
				if(char_posns.find(t[ptr_t]) == char_posns.end()){
					answer = -1;
					break;
				}
				auto it = upper_bound(char_posns[t[ptr_t]].begin(), char_posns[t[ptr_t]].end(), ptr_s);
				if(it == char_posns[t[ptr_t]].end()){
					break;
				}
				ptr_s = *it;
				ptr_t++;
			}
			if(answer == -1)break;
			answer++;
		}
		cout << answer << endl;
	}
}