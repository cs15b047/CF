#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

int main() {
    ll n; cin >> n;
    vector<ll> a(n);for(int i=0;i<n;i++)cin >> a[i];
    set<ll>s;ll unq = 0;for(int i=0;i<n;i++)s.insert(a[i]);unq = s.size();
    if(unq == 1 || a.size() <= 2){
        cout << - 1<< endl;
    }
    else{
        vector<ll> b = a, c = a; sort(b.begin(), b.end()); sort(c.begin(), c.end(), greater<ll>());
        ll posdiff1 = 0, posdiff2 = 0;
        vector<ll> diff1, diff2;
        map<ll,ll> cnt;for(int i=0;i<n;i++)cnt[a[i]]++;
        for(int i=0;i<n;i++){
            if(b[i] != a[i]){posdiff1++;diff1.push_back(i);}
            if(c[i] != a[i]){posdiff2++;diff2.push_back(i);}
        }
        if(unq == 2 && a.size() == 3 && posdiff1 == 2 && posdiff2 == 2){
            cout << -1 << endl;
        }
        else{
            ll pos1, pos2;
            if(posdiff1 == 2 && posdiff2 == 2){
                for(int i=0;i<n;i++){if(cnt[a[i]] != n - 1){pos1 = i;break;}}
                for(int i=0;i<n;i++){
                    if(a[i] != a[pos1]){
                        if((pos1 == diff1[0] && i == diff1[1]) || (pos1 == diff1[1] && i == diff1[0]) || (pos1 == diff2[0] && i == diff2[1]) || (pos1 == diff2[1] && i == diff2[0])){}
                        else {pos2 = i;break;}
                    }
                }
            }
            else if(posdiff1 == 2){
                for(int i=0;i<n;i++){if(i != diff1[0]){pos1 = i;break;}}
                for(int i=0;i<n;i++){if((a[i] != a[pos1]) && !(pos1 == diff1[1] && i == diff1[0])){pos2 = i;break;}}
            }
            else if(posdiff2 == 2){
                for(int i=0;i<n;i++){if(i != diff2[0]){pos1 = i;break;}}            
                for(int i=0;i<n;i++){if((a[i] != a[pos1]) && !(pos1 == diff2[1] && i == diff2[0]) ){pos2 = i;break;}}
            }
            else {
                pos1 = 0;
                for(int i=0;i<n;i++){
                    if(a[i] != a[pos1]){
                        pos2 = i;break;
                    }
                }
            }
            cout << pos1 + 1 << " " << pos2 + 1 << endl;
        }
    }
    
    
    
}