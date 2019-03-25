#include <bits/stdc++.h>
using namespace std ;
typedef long long int ll ;

vector<ll>Ans,Not_9;

void precompute(){
	Ans.clear();Not_9.clear();
	Ans.resize(20);Not_9.resize(20);
	Ans[0] = 1;Not_9[0]=1; // ???
	Ans[1] = 9;Not_9[1] = 9 ;
	for(int i=1;i<=19;i++){
		Ans[i] = 8 * Not_9[i-1] + 1;
		Not_9[i] = 9 * Not_9[i-1] + 1;
	}
}

ll calc_ans(ll num){
	vector<ll>digits;
	ll tmp=num;
	while(tmp != 0){
		digits.push_back(tmp % 10);
		tmp = tmp / 10 ;
	}
	ll ans = 0;
	for(int i = digits.size()-1;i>=0;i--){
		ans += digits[i]*Ans[i] ;
	}	


}

int main(){
	ll t;cin>>t;
	precompute();
	for(int i=0;i<t;i++){
		ll f,l;cin>>f>>l;
		ll p1 = calc_ans(f),p2 = calc_ans(l);
	}
}