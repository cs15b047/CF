#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
vector<ll>lefts,rights;
bool comp(ll i1,ll i2){
	ll a,b;
	if(i1 < 0)a=lefts[-i1-1];else a = rights[i1-1];
	if(i2 < 0)b=lefts[-i2-1];else b = rights[i2-1];
	return ((a<b) || ((a==b) && (i1 < i2)));
}


int main(){
	ll t;cin>>t;
	for(int i=0;i<t;i++){
		ll n,q;scanf("%lld%lld",&n,&q);
		vector<ll>x(n),y(n),z(q),k(q);
		lefts.resize(n);rights.resize(n);
		ll a1,a2,a3,b1,b2,b3,c1,c2,c3,m1,m2,m3;
		scanf("%lld%lld%lld%lld%lld%lld",&x[0],&x[1],&a1,&b1,&c1,&m1);
		scanf("%lld%lld%lld%lld%lld%lld",&y[0],&y[1],&a2,&b2,&c2,&m2);
		scanf("%lld%lld%lld%lld%lld%lld",&z[0],&z[1],&a3,&b3,&c3,&m3);

		for(int j=2;j<n;j++){
			x[j] = (x[j-1]*a1 + x[j-2]* b1 + c1) % m1;
			y[j] = (y[j-1]*a2 + y[j-2]* b2 + c2) % m2;
		}
		for(int j=2;j<q;j++){
			z[j] = (z[j-1]*a3 + z[j-2]* b3 + c3) % m3;
		}
		for(int j=0;j<n;j++){
			lefts[j] = min(x[j],y[j]) + 1;
			rights[j] = max(x[j],y[j]) + 1;
		}
		for(int j=0;j<q;j++){
			k[j] = z[j] + 1;
		}

		sort(lefts.begin(),lefts.end());
		sort(rights.begin(),rights.end());

		vector<ll> boundaries(2*n);
		for (int j = 1; j <=n; ++j){
			boundaries[2*(j-1)] = (j);
			boundaries[2*j-1] = (-j);
		}

		sort(boundaries.begin(),boundaries.end(),comp);

		map<ll,ll> cnt_bnd, num_intrs,prefix,prefix_rev;
		ll curr = 1;
		ll coord;
		if(boundaries[0] < 0)coord = lefts[-boundaries[0]-1];
		else coord = rights[boundaries[0]-1] ;
		prefix[coord] = 1;
		cnt_bnd[coord]++;
		for(int j=1;j<boundaries.size();j++){
			if(boundaries[j] < 0)coord = lefts[-boundaries[j]-1];
			else coord = rights[boundaries[j]-1] ;
			auto it = prefix.rbegin();
			prefix[coord] = it->second + (coord - it->first) * curr + (boundaries[j] < 0);
			cnt_bnd[coord] = max(curr + (boundaries[j] < 0), cnt_bnd[coord]);
			curr += (boundaries[j] < 0) - (boundaries[j] > 0) ;
			num_intrs[coord] = curr;
		}
		// for(auto it:prefix)cout<< it.first << " " << it.second << endl;
		// for(auto it:cnt_bnd)cout<< it.first << " " << it.second << endl;
		// for(auto it:num_intrs)cout<< it.first << " " << it.second << endl;

		ll sum =0, tot=0;
		for(auto it:prefix){
			prefix_rev[it.second] = it.first;
		}
		tot = prefix.rbegin()->second ;
		for(int j=0;j<q;j++){
			if(k[j] > tot)continue;
			ll pos = tot - k[j] + 1;
			// cout << pos << endl ;
			auto it = prefix_rev.lower_bound(pos);
			auto it_prev = it;it_prev--;
			// cout << it->first <<  " " << it->second << " " << cnt_bnd[it->second] << " " << it_prev->first + cnt_bnd[it_prev->second] << endl ;
			if(it->first - cnt_bnd[it->second] < pos)sum += it->second * (j+1) ;
			else if(pos <= it_prev->first ){
				sum += it_prev->second *(j+1);
			}
			else{
				ll intrs = num_intrs[it_prev->second] ;
				ll strt = it_prev->first + 1, stop = it->first - cnt_bnd[it->second];
				// cout << "strt:"<<strt <<" "<<" stop:"<<stop<<endl;
				ll offset = ceil((pos - it_prev->first)/(double)intrs);
				ll myans = it_prev->second + offset;
				// cout << offset<< " " << myans << endl;
				sum += myans *(j+1);
			}
		}
		// cout << "Case #" << (i+1) << ": " << sum << endl;
		printf("Case #%d: %lld\n",i+1,sum);
		fflush(stdout);
	}	
}