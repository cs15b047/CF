#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

int main(){
	ll n; cin >> n ;
	vector<ll>a(n);for(int i=0;i<n;i++)scanf("%lld",&a[i]);	
	int imposs = 0;
	map<ll,ll> ans_cnt;
	for(auto it:a)ans_cnt[it]++;
	map<ll,vector<ll>> ans_index;
	for(int i=0;i<n;i++)ans_index[a[i]].push_back(i);

	if(n == 1 && a[0] == 0)cout<<"Possible\n" << 1 << endl ;
	else if(n == 1 && a[0] != 0)cout<<"Impossible" << endl ;
	else{
		int type = 0;
		vector<ll>answer;answer.clear();answer.resize(n);
		for(auto it:ans_cnt){
			if(it.first + it.second == n){
				for(auto ind:ans_index[it.first])answer[ind] = type + 1;
				type++;
			}
			else if(it.second % (n - it.first) == 0){
				ll interval = it.second / (n - it.first) ;
				int curr = 0;
				for(int i=0;i<interval;i++){
					ll cnt = n - it.first;
					int j = 0;
					while(j < cnt){
						int index = ans_index[it.first][curr + j];
						answer[index] = type + 1;
						j++;
					}
					curr += cnt ;
					type++;
				}
			}
			else{
				imposs = 1;
			}
			if(imposs == 1)break;
		}
		if(imposs == 1)cout << "Impossible" << endl;
		else{
			cout << "Possible" << endl ;
			for(auto it:answer)cout << it << " ";cout << endl;
		}
	}

}