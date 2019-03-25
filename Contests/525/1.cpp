#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

int main(){
	ll x;cin >>x;
	int flag = 0;
	for(int a = 1;a<=x;a++){
		for(int b = 1;b <= a;b++){
			if(((a*b) > x) && ((a/b) < x) && ((a%b)==0)){
				cout << a << " " << b << endl;
				flag = 1;
				break;
			}
		}
		if(flag == 1)break;
	}
	if(flag==0)cout << -1 << endl;
}