#include <bits/stdc++.h>
using namespace std ;
typedef long long int ll ;

int main(){
	ll t;cin >> t;
	for(int x = 1;x <= t;x++){
		ll n; cin >> n;
		vector<vector<ll>> elements;
		vector<ll> init;for(int i=1;i<=n;i++)init.push_back(i);
		elements.push_back(init);
		int all_ones = (init.size() == 1);
		ll ans = 0, val;
		while(all_ones == 0){
			vector<vector<ll>> new_ele;
			for(int i=0;i < elements.size();i++){
				vector<ll> first,second;first.clear();second.clear();
				ll sz = elements[i].size();
				for(int j=0;j<sz/2;j++)first.push_back(elements[i][j]);
				for(int j=sz/2;j<sz;j++)second.push_back(elements[i][j]);
				new_ele.push_back(first);new_ele.push_back(second);
			}
			vector<ll> comp1, comp2;comp1.clear();comp2.clear();
			int temp_all_ones = 1;
			for(int i=0;i < new_ele.size();i++){
				if(i % 2 == 0){
					for(int j=0;j<new_ele[i].size();j++)comp1.push_back(new_ele[i][j]);
				}
				else{
					for(int j=0;j<new_ele[i].size();j++)comp2.push_back(new_ele[i][j]);	
				}
				if(new_ele[i].size() > 1)temp_all_ones = 0;
			}
			cout << comp1.size() << " " << comp2.size() << " " ;
			for(auto it:comp1)cout << it << " ";for(auto it:comp2)cout << it << " ";
			cout << endl; fflush(stdout);
			cin >> val;
			ans = max(ans, val);
			if(temp_all_ones == 1){all_ones = 1;break;}
			elements.clear();
			elements = new_ele;
		}
		cout << "-1 " << ans << endl;fflush(stdout);
	}
}