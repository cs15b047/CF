#include <bits/stdc++.h>
using namespace std ;

typedef long long int ll ;

string to_binary_string(ll x){
	string str = "";
	if(x == 0)str = "0";
	else{
		while(x!=0){
			str += to_string(x % 2);
			x = x /2;
		}		
	}
	reverse(str.begin(),str.end());
	return str ;
}

ll str_to_num(string str){
	ll ans = 0;
	for(int i = str.length()-1;i>=0;i--){
		ans += (str[i]-'0')*(ll)pow(2,str.length()-1-i) ;
	}
	return ans;
}

string to_dig_string(ll x){
	string str = "";
	if(x == 0){
		str = "0";
	}
	else{
		while(x != 0){
			str += to_string(x % 2) ;
			x = x / 10;
		}
	}
	reverse(str.begin(),str.end());
	str = to_binary_string(str_to_num(str)) ;
	return str;
}


int main()
{
	ll t;cin>>t;
	map<ll,ll> cnt ;
	map<string, ll> mymap ;

	for(ll i=0;i<t;i++)
	{
		string str ;cin >> str ;
		if(str == "+" || str == "-"){
			ll ele;cin >> ele ;
			string dig_s = to_dig_string(ele);
			if(str == "+")mymap[dig_s]++ ;
			if(str == "-"){
				mymap[dig_s]--;				
			}
		}
		else{
			string cmp;cin>>cmp ;
			ll q = str_to_num(cmp);
			string query = to_binary_string(q);
			ll ans = mymap[query];
			cout << ans << endl;
		}
	}

	return 0;
}