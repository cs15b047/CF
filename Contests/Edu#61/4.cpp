#include <bits/stdc++.h>
using namespace std ;

typedef long long int ll ;

int main(){
	ll n; cin >> n;
	string str;cin >> str;

	map<char,vector<ll>> positions;
	int flag = 0;
	ll ans = 0;
	while(str.length() > 0){
		flag = 0;
		positions.clear();
		for(int i=0;i<str.length();i++)positions[str[i]].push_back(i);
		for(auto it:positions){
			if(it.second.size() == 1){
				str.erase(str.begin() + *it.second.begin());
				flag = 1;
				ans++;
				break;
			}
		}
		if(flag == 1)continue;
		
		ll p1,p2,dis=1e18;
		for(auto it:positions){
			for(int i=0;i<it.second.size() - 1;i++){
				if(dis > it.second[i + 1] - it.second[i] - 1){
					dis = it.second[i+1] - it.second[i] - 1;
					p2 = it.second[i + 1] - 1;
					p1 = it.second[i] + 1;
				}
			}
		}
		if(dis > 0){
			str.erase(p1, dis);
			ans += dis;
		}
		else if(dis == 0){
			str.erase(str.begin() + p2 + 1);
		}
	}
	cout <<ans << endl;

}