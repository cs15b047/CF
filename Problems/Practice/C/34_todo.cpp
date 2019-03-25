#include <bits/stdc++.h>
using namespace std ;

typedef long long int ll ;
int main()
{
	ll n,k;cin >>n >>k ;
	scanf("%s",s);
	string str(s);	

	ll j=0;
	map<ll,ll> a_patch_s,a_patch_e,b_patch_s,b_patch_e ;
	vector<ll> a_loc,b_loc ;
	while(j < n){
		ll strt = j,curr=j ;		
		while(curr < n && str[curr] == str[strt]){
			if(str[curr] == 'a')a_loc.push_back(curr);
			else b_loc.push_back(curr);
			curr++;
		}
		if(s[strt] == 'a'){
			a_patch_s[strt] = curr - 1;
			a_patch_e[curr-1] = strt;
		}
		else{
			b_patch_s[strt] = curr - 1;
			b_patch_e[curr-1] = strt;
		}
		j = curr ;
	}
	
	if(k == 0)
	{		
	}

	for(auto it: b_patch_s){
		ll start,end;
		if(it.first == 0)start = 0;
		else start = a_patch_e[it.first-1];
		ll b_end ;		
		
		ll first_loc = lower_bound(b_loc.begin(),b_loc.end(),it.first) - b_loc.begin();
		if(first_loc + k - 1 >= b_loc.size() - 1){
			end = n - 1;
		}
		else{
			b_end = b_loc[first_loc + k - 1] ;
			if(s[b_end+1] == 'a'){
				end = a_patch_s[b_end+1];
			}
		}
	}

}