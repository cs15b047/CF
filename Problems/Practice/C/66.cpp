#include <bits/stdc++.h>
using namespace std ;

typedef long long int ll ;
int main(){
	ll w,m,tmp;cin>>w>>m;tmp=m;
	vector<int> coeffs_m(101);
	int i = 0 ;
	while(tmp != 0){
		coeffs_m[i] = tmp % w;
		tmp = tmp / w ;
		i++;
	}
	// for(auto it:coeffs_m)cout<<it <<" ";
	vector<int> n2(101);
	int flag = 1;
	for(i=0;i<=100;i++){
		if(coeffs_m[i] % w == 0){
			coeffs_m[i+1] += coeffs_m[i]/w;
			n2[i] = 0;
		}
		else if(coeffs_m[i] == w-1){coeffs_m[i+1]++;n2[i]=1;}
		else if(coeffs_m[i]==1){n2[i]=0;}
		else{
			flag = 0;
			break;
		}
	}
	// ll num=0;
	// for(auto it:n2)cout<<it <<" ";
	// for(i=0;i<=100;i++){
	// 	if(n2[i] != 0)num += (ll)pow(w,i)*(ll)n2[i] ;
	// }
	// cout << num << endl; 
	if(flag)cout << "YES"<<endl;
	else cout << "NO"<<endl;
}