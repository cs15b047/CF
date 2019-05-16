#include <bits/stdc++.h>
using namespace std ;
typedef long long int ll ;

int main(){
	ll t; cin >> t;
	for(int i=0;i<t;i++){
		ll n; cin >> n;
		string str; cin >> str;
		int flag = 1;
		ll idx = -1;
		if(n < 11)flag = 0;
		else{
			for(int j = 0;j < n; j++){
				if(str[j] == '8'){idx = j;break;}
			}
			if(idx == -1)flag = 0;
			else if(n - idx >= 11){
				flag = 1;
			}
			else flag = 0;
		}
		if(flag)cout << "YES"<< endl;
		else cout << "NO"<< endl;
	}
}
