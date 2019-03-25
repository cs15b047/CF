#include <bits/stdc++.h>
using namespace std ;

typedef long long int ll ;

int main(){
	ll c1,c2,c3,c4;cin >> c1 >> c2 >> c3 >> c4;
	if(c1 == c4){
		if(c1 == 0 && c3 > 0){
			cout << 0 << endl;
		}
		else{
			cout << 1 << endl;
		}
	}
	else{
		cout << 0 << endl;
	}
}