#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

vector<ll> c, t;
bool cmp1(ll a, ll b){
    return c[a] > c[b];
}

int main(){
    ll n, k; cin >> n >> k;
    double tot = 0.0;
    c.resize(n);t.resize(n);
    for(int i=0;i<n;i++){cin >> c[i] >> t[i];tot+=(double)c[i];}

    vector<ll> s, p;for(int i=0;i<n;i++){if(t[i] == 1)s.push_back(i);else p.push_back(i);}
    sort(s.begin(), s.end(), cmp1);
    sort(p.begin(), p.end(), cmp1);
    
    double base = 0.0;
    for(int i=0; i < min(k, (ll)s.size()) ;i++)
        base += (double)(c[s[i]]) / (double)2 ;
    if(s.size() >= k){
        if(!p.empty())base = base - (double)(c[s[k - 1]] - min(c[s.back()], c[p.back()])) / (double)2;
        else base = base - (double)(c[s[k - 1]] - c[s.back()]) / (double)2;
    }
    tot -= base;
    printf("%.1f\n", tot);
    for(auto &it: s)it++;
    for(auto &it: p)it++;
    if(s.size() >= k){
        for(int i=1;i<=k - 1; i++){
            printf("1 %lld\n",s[i-1]);
        }
        printf("%lld ", n - (k - 1));
        for(int i = k; i <= s.size();i++)printf("%lld ", s[i - 1]);
        for(auto it: p)printf("%lld ", it);
    } else{
        for(int i=1;i<=s.size(); i++){
            printf("1 %lld\n",s[i-1]);
        }
        for(int i = 0; i < k - s.size() - 1 ;i++){
            printf("1 %lld\n", p[i]);
        }
        printf("%lld ", p.size() - (k - s.size() - 1));
        for(int i = k - s.size() - 1; i < p.size();i++){
            printf("%lld ", p[i]);
        }
    }

}