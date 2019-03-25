#include <bits/stdc++.h>
using namespace std ;

typedef long long int ll ;

void add_cut(map<ll,set<ll>>& len_loc_x, map<ll,ll>&loc_len_x, ll loc){
	auto it_x = loc_len_x.lower_bound(loc);it_x--;
	ll loc_to_be_changed = it_x->first ;ll old_len = it_x->second ;	
	ll new_len = old_len - (loc - loc_to_be_changed) ;

	loc_len_x[loc] = new_len ;
	loc_len_x[loc_to_be_changed] = loc - loc_to_be_changed ;
	
	len_loc_x[new_len].insert(loc);
	len_loc_x[old_len].erase(loc_to_be_changed) ;
	if(len_loc_x[old_len].empty())len_loc_x.erase(old_len);
	len_loc_x[(loc - loc_to_be_changed)].insert(loc_to_be_changed) ;
}


int main(){
	ll w,h,n;cin>>w>>h>>n;
	map<ll,set<ll>> len_loc_x, len_loc_y ;
	map<ll,ll> loc_len_x,loc_len_y;

	len_loc_x[w].insert(0);
	len_loc_y[h].insert(0);
	loc_len_x[0] = w;
	loc_len_y[0] = h ;

	for(int i=0;i<n;i++)
	{
		char d; ll loc; cin>> d >> loc ;
		if(d == 'H')add_cut(len_loc_y,loc_len_y,loc);
		else if(d == 'V')add_cut(len_loc_x,loc_len_x,loc);
		ll max_w = len_loc_x.rbegin()->first;
		ll max_h = len_loc_y.rbegin()->first;
		cout << max_h* max_w << endl ;
	}


}