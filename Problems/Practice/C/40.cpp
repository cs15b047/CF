#include <bits/stdc++.h>
using namespace std ;

typedef long long int ll ;
vector<ll>l,r;
bool comp_l(ll a, ll b){
	return l[a] < l[b] ;
}
bool comp_r(ll a, ll b){
	return r[a] < r[b] ;
}

int main()
{
	ll n;cin>>n;

	if(n <= 2)cout << "YES"<<endl;
	else{
		vector<ll>ind_l(n),ind_r(n);
		l.resize(n);r.resize(n);
		for(int i=0;i<n;i++)scanf("%lld%lld",&l[i],&r[i]);
		for(int i=0;i<n;i++){ind_r[i]=i;ind_l[i]=i;}

		stable_sort(ind_l.begin(),ind_l.end(),comp_l);
		stable_sort(ind_r.begin(),ind_r.end(),comp_r);

		vector<ll> sort_l(n);
		for(int i=0;i<n;i++)sort_l[i] = l[ind_l[i]];
		int flag = 1;
		for(int i=0;i<n;i++){
			ll tbs = r[ind_r[i]];
			ll loc = upper_bound(sort_l.begin(),sort_l.end(),tbs) - sort_l.begin();
			ll common = loc - i;
			if(common > 2){
				cout << "NO" << endl ;
				flag = 0;
				break ;
			}
		}
		if(flag)cout << "YES" << endl ;
	}
}