#include <bits/stdc++.h>
using namespace std ;
typedef long long int ll ;
char s[300002];
int main(){
	ll n; scanf("%lld",&n);
	scanf("%s",s);string str(s);
	ll opn=0, clos=0,ques=0;
	for(int i=0;i<n;i++){
		if(str[i] == '(')opn++;
		else if(str[i] == ')')clos++;
		if(str[i] == '?')ques++;
	}
	ll tot_offset = opn - clos;
	int flag = 1;
	if((n % 2 == 1) || (ques < abs(tot_offset)) || str[n - 1] == '(')flag = 0;
	else{
		ll n_clos = (ques + tot_offset)/2, n_op = (ques - tot_offset)/2 ;
		ll offset = 0;
		for(int i=1;i<=n;i++){
			if(str[i - 1] == '?'){
				if(n_op != 0){n_op--;str[i-1] = '(';offset++;}
				else if(n_clos != 0){n_clos--;str[i-1] = ')';offset--;}
				else {flag = 0;break;}
			}
			else if(str[i-1] == '(')offset++;
			else offset--;
			if(offset < 0 || ((offset == 0) && (i < n))){flag = 0;break;}
		}
		if(offset != 0)flag = 0;
	}
	if(flag == 1)cout << str << endl;
	else cout << ":(" << endl;
}