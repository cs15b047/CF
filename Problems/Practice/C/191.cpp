// D. Credit Card  CF# Edu 33 - 2
// Keep range of amount that can be present with person by depositing in periods of checking. Keep mxm as d
// If start of range is > d --> Not possible to do task
#include <bits/stdc++.h>
using namespace std ;
typedef long long int ll ;

int main(){
	ll n,d; cin >> n >> d;
	vector<ll> amount(n + 1);for(int i=1;i<=n;i++)cin >> amount[i];
	pair<ll,ll> range = make_pair(0,0);
	ll counts = 0,flag=1;
	for(int i=1;i<=n;i++){
		if(amount[i] != 0){range.first += amount[i];range.second += amount[i];}
		else{
			if(range.first < 0 && range.second < 0){
				counts++;
				range = make_pair(0, d);
			}
			else if(range.first < 0 && range.second >= 0)range.first = 0;
		}
		if(range.first > d){flag = 0;break;}
		range.second = min(d, range.second);
	}
	if(flag == 0)cout << -1 << endl;
	else{
		cout << counts << endl;
	}
}