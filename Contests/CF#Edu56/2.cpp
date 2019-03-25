#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

int main(){
	ll t; cin >> t;
	for(int i=0;i<t;i++){
		string str; cin >> str;
		map<char,int>counts;
		for(int i=0;i<str.length();i++){
			counts[str[i]]++;
		}
		if(counts.size() == 1)cout << -1 << endl;
		else{
			auto it1 = counts.begin();
			auto it2 = counts.rbegin();
			string ans = str; //init
			int l = str.length();
			ans[0] = it1->first; it1->second--;
			ans[l-1] = it2->first; it2->second--;			
			for(int i=1;i<l-1;i++){
				while(!counts.empty() && counts.begin()->second == 0)counts.erase(counts.begin()->first);
				ans[i] = counts.begin()->first; counts.begin()->second--;
			}
			cout << ans << endl ;
		}
	}
}