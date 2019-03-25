#include <bits/stdc++.h>
using namespace std ;
typedef long long int ll ;
ll p1=0;
ll gcd(ll a, ll b){
	if(b==0)return a; 
	return gcd(b,a%b);
}
ll is_pwr_2(ll num){
	for(int i=0;i<=20;i++){
		if((ll)pow(2,i) == num)return i;
	}
	return -1;
}
pair<ll,ll> make_pwr_2(ll num){
	ll ops=0;
	while(is_pwr_2(num) == -1){
		num = num/2;p1++;
	}
	return make_pair(num, is_pwr_2(num));
}
int main(){
	ll n;cin>>n;
	vector<ll>a(n);for(int i=0;i<n;i++)scanf("%lld",&a[i]);

	if(n == 1)cout << 0 << endl;
	else{
		p1=0;
		ll g = a[0];
		for(int i=1;i<n;i++)g = gcd(g,a[i]);
		for(int i=0;i<n;i++)a[i] = a[i]/g;

		ll pwr_cnt[30]={};
		for(int i=0;i<n;i++){
			pair<ll,ll> pow_num = make_pwr_2(a[i]);
			a[i] = pow_num.first;
			pwr_cnt[pow_num.second]++;
		}

		ll p2 = 1e18;
		for(ll i=0;i<30;i++){
			// if(pwr_cnt[i]==0)continue;
			ll tmp =0 ;
			for(ll j=0;j<30;j++){
				tmp += pwr_cnt[j]*abs(i-j);
			}
			p2 = min(p2, tmp);
		}
		cout << (p1+p2) << endl;
	}
}