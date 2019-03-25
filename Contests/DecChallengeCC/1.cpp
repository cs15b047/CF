#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

int main(){
	ll 	N,r; cin >> N >> r ;
	for(int i=0;i<N;i++){
		ll R;cin >> R;
		if(R>=r)cout << "Good boi" << endl;
		else cout << "Bad boi" << endl;
	}
}