#include <bits/stdc++.h>
using namespace std ;
typedef long long int ll ;

int main(){
	ll t; cin >> t;
	for(int i=0;i<t;i++){
		string str; cin >> str;
		ll ups = 0;
		for(int j = 0;j < str.length();j++)ups += (str[j] == '1');
		if(ups % 2 == 0)cout << "LOSE" << endl;
		else cout << "WIN" << endl;
	}
}