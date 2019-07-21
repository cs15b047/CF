#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

int main(){
    char s[1000001];
    scanf("%s",s);string str(s);
    vector<ll> cnts;
    int i = 0;
    while(i < str.length() && str[i] != 'v')i++;
    while(i < str.length()){
        ll strt = i; 
        while(i < str.length() && str[i] == 'v')i++;
        if(i != strt)cnts.push_back(i - strt);
        ll strt2 = i;
        while(i < str.length() && str[i] != 'v')i++;
        if(i != strt2)cnts.push_back(i - strt2);
    }
    // for(auto it: cnts)cout << it << " ";cout << endl;
    if(!cnts.empty() && cnts.size() % 2 == 0)cnts.pop_back();
    vector<ll> suff_sum(cnts.size());
    ll sz = cnts.size();
    for(int i = sz - 1;i >= 0; i--){
        if((i != sz - 1) && (i % 2 == 0)){
            suff_sum[i] = suff_sum[i + 2] + (cnts[i] - 1) ;
        } else if((i == sz - 1) && (i % 2 == 0)){
            suff_sum[i] = cnts[i] - 1;
        } else  if((i % 2 != 0) && (i == sz - 2)){
            suff_sum[i] = suff_sum[i + 1] * cnts[i];
        } else  if((i % 2 != 0) && (i != sz - 2)){
            suff_sum[i] = suff_sum[i + 2] + suff_sum[i + 1] * cnts[i];
        }
    }
    ll ans = 0;
    for(int i=0;i < sz - 2;i+=2){
        ans += (cnts[i] - 1)*suff_sum[i + 1];
    }
    cout << ans << endl;
}