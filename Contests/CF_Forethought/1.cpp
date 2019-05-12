#include <bits/stdc++.h>
using namespace std ;
typedef long long int ll ;

int main(){
	string str;	cin >> str;
	ll cnt = 0;
	for(int i=0;i<str.length();i++){
		if(str[i] == 'a')cnt++;
	}
	if(cnt > str.length()/2)cout << str.length() << endl;
	else cout << 2*cnt - 1 << endl;
}