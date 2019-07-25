#include <bits/stdc++.h>
using namespace std ;
typedef long long int ll;

int main(){
	char s[500001];scanf("%s",s);string str1(s);scanf("%s",s);string str2(s);
	ll z1 = 0, o1 = 0, z2 = 0, o2 = 0;
	for(int i=0;i<str1.length();i++){z1 += str1[i]=='0';o1+=str1[i]=='1';}
	for(int i=0;i<str2.length();i++){z2 += str2[i]=='0';o2+=str2[i]=='1';}
	// cout << z1 << " " << o1 << " " << z2 << " " << o2 << endl;
	if(z2 > z1 || o2 > o1){
		cout << str1 << endl;
	} else {
		vector<ll> lps(str2.length(), 0);
		lps[0] = 0;
		for(int i=1;i < str2.length();i++){			
			ll j = i;
			while(j > 0){
				if(str2[i] != str2[lps[j - 1]]){
					j = lps[j - 1];
				} else{
					lps[i] = lps[j - 1] + 1;
					break;
				}
			}
		}
		ll len = lps[str2.length() - 1];
		string str = "";
		str += str2;
		z1 -= z2; o1 -= o2;
		ll further_z = 0, further_o = 0;
		for(int i=len;i < str2.length();i++){further_z += str2[i]=='0';further_o += str2[i]=='1';}
		while(z1 >= further_z && o1 >= further_o){
			str += str2.substr(len, str2.length() - len);
			z1 -= further_z;
			o1 -= further_o;
		}
		for(int i=0;i < z1;i++)str += '0';
		for(int i=0;i < o1;i++)str += '1';
		cout << str << endl;
	}
}