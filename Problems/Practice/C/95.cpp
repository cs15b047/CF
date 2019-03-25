// D. Love Rescue $464 - 2
// Form graph of letters needing to be connected
#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

int main(){
	ll n;cin>>n;
	char s1[100001],s2[100001];scanf("%s%s",s1,s2);string str1(s1),str2(s2);

	map<char,ll> char_map;
	vector<pair<char,char>> sequence;sequence.clear();
	pair<char,char> pair;
	
	for(int i=0;i<26;i++)char_map[('a'+i)] = 0;
	ll cnt = 1, ans=0;
	for(int i=0;i<n;i++){
		pair = make_pair(s1[i],s2[i]);
		if(s1[i] == s2[i]){}
		else if(char_map[s1[i]] == 0 && char_map[s2[i]] == 0){
			char_map[s1[i]] = char_map[s2[i]] = cnt;
			cnt++;
			ans++;
			sequence.push_back(pair);
		}
		else if(char_map[s1[i]] == 0 && char_map[s2[i]] != 0){
			char_map[s1[i]] = char_map[s2[i]];
			ans++;
			sequence.push_back(pair);
		}
		else if(char_map[s2[i]] == 0 && char_map[s1[i]] != 0){
			char_map[s2[i]] = char_map[s1[i]];
			ans++;
			sequence.push_back(pair);
		}
		else if(char_map[s2[i]] != char_map[s1[i]]){
			ll to_be_changed = char_map[s1[i]], changed = char_map[s2[i]];
			for(auto &it: char_map){
				if(it.second == to_be_changed){
					it.second = changed;
				}
			}
			sequence.push_back(pair);
			ans++;
		}
		else if(char_map[s2[i]] == char_map[s1[i]]){}
	}
	printf("%lld\n",ans );
	for(auto it:sequence)printf("%c %c\n",it.first,it.second );

}