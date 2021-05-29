#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

int main(){
	ll t; cin >> t;
	for(int i = 0;i < t;i++){
		ll n; cin >> n;
		if(n == 2){
			cout << 1 << endl;
		} else if(n == 3){
			cout << 7 << endl;
		}
		else{
			if(n % 2 == 0){
				for(int i = 0;i < n/2;i++)printf("1");printf("\n");
			} else{
				printf("7");
				for(int i = 0;i < (n - 3)/2;i++)printf("1");printf("\n");
			}
		}
	}
}