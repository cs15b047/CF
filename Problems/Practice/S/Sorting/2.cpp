#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;

int main(){
    ll n, m; cin >> n >> m;
    vector<ll> allowed(n + 1);for(int i=1;i<=n;i++)cin >> allowed[i];
    vector<ll> reqd(m + 1); for(int i=1;i<=m;i++)cin >> reqd[i];
    map<ll, bool> doneSubj;
    vector<ll> possible(n + 1, 0);
    for(int i=1;i<=n;i++){
        if(allowed[i] == 0){
            possible[i] = possible[i - 1];
            continue;
        }
        if (doneSubj[allowed[i]] == false) {
            doneSubj[allowed[i]] = true;
            possible[i] = possible[i - 1] + 1;
        } else {
            possible[i] = possible[i - 1];
        }
    }
    // for(int i=1;i<=n;i++)cout << possible[i] << " ";cout << endl;
    if(possible[n] != m){
        cout << -1 << endl;
    }
    else {
        ll left, right = n, mid;
        for(int i=1;i<=n;i++){
            if(possible[i] == m){
                left = i;
                break;
            }
        }
        bool can = false;
        while(left <= right) {
            // cout << left << " " << right << " " << mid << endl;
            // mid = ceil((float)(left + right)/ (float)2);
            mid = (left + right) / 2;
            map<ll, ll> schedule;
            set<ll> done;
            for(int i = mid;i >= 1; i--){
                if(done.find(allowed[i]) == done.end() && allowed[i] != 0){
                    schedule[i] = allowed[i];
                    done.insert(allowed[i]);
                }
                if(done.size() == m)break;
            }
            // for(auto it : schedule)cout << it.first << " " << it.second << endl;
            ll idx = 0;
            ll reqdDays = 0;
            bool canBeDone = true;
            for(auto it : schedule) {
                if(it.first - 1 - idx >= reqdDays + reqd[it.second]){
                    idx++;
                    reqdDays += reqd[it.second];
                    continue;
                } else{
                    canBeDone = false;
                    break;
                }
            }
            if(canBeDone){
                can = true;
                if(mid == right)break;
                right = mid;
            } else {
                left = mid + 1;
            }
        }
        if(can)cout << left << endl;
        else cout << -1 << endl;
    }
}