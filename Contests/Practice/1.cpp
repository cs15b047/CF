#include <bits/stdc++.h>
using namespace std ;
typedef long long int ll ;

vector<pair<ll,ll>> get_pos(string str){
	vector<pair<ll,ll>> ans;
	for(int i = 0;i < str.length();i++){
		if(str[i] != '.'){
			ll num = str[i] - '0';
			ans.push_back(make_pair(i, num));
		}
	}
	return ans;
}

int main(){
	ll t; scanf("%lld",&t);
	for(int q = 0;q <t;q++){
		char s[60]; scanf("%s",s);string str(s);
		vector<pair<ll,ll>> robots = get_pos(str);
		bool safe = true;
		ll sz = robots.size();
		for(int i = 0; i < sz;i++){
			if(i > 0){
				if((robots[i].first - robots[i].second) <= (robots[i - 1].first + robots[i - 1].second)){
					safe = false;
					break;
				}
			}
		}
		if(safe)printf("safe\n");
		else printf("unsafe\n");
	}
}