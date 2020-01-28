#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

int main(){
	ll len; cin >> len;
	string str1, str2; cin >> str1 >> str2;

	ll start = 0, end = len - 1;
	while(str1[start] == str2[start]){start++;}
	while(str1[end] == str2[end]){end--;}

	ll answer = 0;
	if(start == end){
		answer = 2;
	} else {
		string substr1, substr2;
		bool cond1 = (str1.substr(start, end - start) == str2.substr(start + 1, end - start)), cond2 = (str2.substr(start, end - start) == str1.substr(start + 1, end - start));
		answer = cond1 + cond2;
	}
	cout << answer << endl;
}