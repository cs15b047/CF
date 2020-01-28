#include <bits/stdc++.h>
using namespace std ;
typedef long long int ll ;

int main(){
	ll t; scanf("%lld",&t);
	for(int q = 0;q < t;q++){
		ll n; scanf("%lld",&n);
		map<string, pair<ll,ll>> str_counts; str_counts.clear(); // pair has 0 and 1 counts
		for(int i = 0;i < n;i++){
			char s[10];scanf("%s",s);string str(s);
			int present; scanf("%d",&present);
			// cout << str << " " << present << endl;
			if(str_counts.find(str) == str_counts.end()){
				if(present == 0)str_counts[str] = make_pair(1, 0);
				else str_counts[str] = make_pair(0, 1);
			} else{
				if(present == 0)str_counts[str] = make_pair(str_counts[str].first + 1, str_counts[str].second);
				else str_counts[str] = make_pair(str_counts[str].first, str_counts[str].second + 1);
			}
		}
		ll answer = 0;
		// take maximum of 0 and 1 counts
		for(auto it: str_counts){
			answer += max(it.second.first, it.second.second);
		}
		printf("%lld\n",answer);
	}
}