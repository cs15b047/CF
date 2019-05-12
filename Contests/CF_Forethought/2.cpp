#include <bits/stdc++.h>
using namespace std ;
typedef long long int ll ;

int main(){
	char s[100002];scanf("%s",s);string str(s);
	string new_str = "";
	for(int i=0;i<str.length();i++){
		if(str[i] != 'a')new_str += str[i];
	}
	int flag = 1;
	ll len = new_str.length();
	if(new_str.length() != 0){
		if(new_str.length() % 2 != 0)flag = 0;
		else{
			for(int i =0,j=len/2;(i<len/2) && (j < len);i++,j++){
				if(new_str[i] != new_str[j]){flag = 0;break;}
			}
			if(flag == 1){
				for(int i=0;i<len/2;i++){
					if(new_str[len - 1 - i] != str[str.length() - 1 - i]){
						flag = 0;break;
					}
				}
			}
		}
	}
	if(flag == 1){
		cout << str.substr(0, str.length() - len/2) << endl;
	}
	else cout << ":(" << endl;
}