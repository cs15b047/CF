#include <bits/stdc++.h>
using namespace std ;

typedef long long int ll ;

int main()
{
	int n;cin >> n ;
	string str;cin >> str ;
	vector<ll> s0,s1 ;

	int i = 0 ;
	ll ans = 0 ;
	while(i < n){
		int strt = i,j = i ;
		while(j < n && str[j] == str[strt])j++ ;
		if(j - strt >= 2){
			if(str[strt] == '1')s1.push_back(j - strt) ;
			else if(str[strt] == '0')s0.push_back(j - strt) ;
		}
		ans++;
		i = j ;
	}
	if(s0.size() + s1.size() >= 2)cout << ans + 2 <<endl ;
	else if((s0.size() == 1 && s0[0] >= 3) || (s1.size() == 1 && s1[0] >= 3)){
		cout << ans + 2 <<endl ;
	}
	else if((s0.size() == 1 && s0[0] == 2) || (s1.size() == 1 && s1[0] == 2)){
		cout << ans + 1 <<endl ;
	}
	else{
		cout << ans <<endl ;	
	}
}