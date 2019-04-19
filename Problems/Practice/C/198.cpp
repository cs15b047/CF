#include <bits/stdc++.h>
using namespace std ;
typedef long long int ll ;

int main(){
	ll n; cin >> n;vector<ll> wts_before(n + 1), prefix_wts(n+1,0);for(int i=1;i<=n;i++)cin >> wts_before[i];
	for(int i=1;i<=n;i++)prefix_wts[i] =prefix_wts[i-1] + wts_before[i];
	ll k;cin >> k;vector<ll> wts_after(n + 1);for(int i=1;i<=k;i++)cin >> wts_after[i];

	vector<pair<ll,ll>> mapping;
	ll p1=1,p2=1, p3=1;
	int flag = 1;
	while(p2 <= n && p3 <= k){
		while(prefix_wts[p2] - prefix_wts[p1 - 1] < wts_after[p3]){p2++;}
		if(prefix_wts[p2] - prefix_wts[p1 - 1] != wts_after[p3]){flag = 0;break;}
		mapping.push_back(make_pair(p1,p2));
		p3++;p1 = p2 + 1;p2 = p1;
	}
	if(p2 <= n || p3 <= k){flag = 0;}
	reverse(mapping.begin(),mapping.end());
	vector<vector<pair<ll,string>>> glob_ans;
	if(flag == 1){
		for(auto it: mapping){
			ll l = it.first,r = it.second;
			ll mxm = 0;for(ll i=l;i<=r;i++)mxm = max(mxm, wts_before[i]);

			ll start = -1, low = -1;
			for(ll i=r;i>=l;i--){
				if(wts_before[i] == mxm){
					if(i == r && i - 1 >= l && wts_before[i-1] < mxm){start = i;low=i-1;break;}
					else if(i == l && i + 1 <= r && wts_before[i + 1] < mxm){start = i;low=i+1;break;}
					else if(i < r && i > l){
						if(wts_before[i + 1] < mxm){start = i;low = i + 1;break;}
						else if(wts_before[i - 1] < mxm){start = i;low = i - 1;break;}
					}
				}
			}
			if((start == -1 || low == -1) && (l != r)){flag = 0;break;}
			else{
				if(l != r){
					ll myindex = start, lefts = start - l, rights = r - start ;
					vector<pair<ll,string>> local_ans;local_ans.clear();
					if(low < start){myindex--;local_ans.push_back(make_pair(start,"L"));lefts--;}
					else{local_ans.push_back(make_pair(start,"R"));rights--;}
					for(ll i = 1;i<=rights;i++)local_ans.push_back(make_pair(myindex, "R"));
					for(ll i = myindex ;i > l;i--)local_ans.push_back(make_pair(i, "L"));
					glob_ans.push_back(local_ans);
				}
			}
		}
	}

	if(flag == 1){
		cout << "YES" << endl;
		for(auto segment:glob_ans){
			for(auto ele:segment){
				cout << ele.first <<  " " << ele.second << endl;
			}
		}
	}
	else cout << "NO" << endl;
}