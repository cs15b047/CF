#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

int main(){
    ll n, m; scanf("%lld%lld",&n,&m);
    vector<vector<ll>> arr(m), positions(n + 1);for(int i=1;i<=n;i++)positions[i].resize(m);
    for(int i=0;i<m;i++){
        arr[i].resize(n + 1);
        for(int j = 1;j <= n; j++){
            ll num;scanf("%lld",&num);
            positions[num][i] = j;
            arr[i][j] = num;
        }
    }
    ll ans = 0;
    vector<bool> visited(n + 1, false);
    vector<ll> ans_end(n + 1, 0);
    for(int j = n;j >= 1; j--){
        bool go = true;
        ll curr = arr[0][j];
        if(!visited[curr]){
            visited[curr] = true;
            ll len = 1;
            vector<ll> pth;pth.push_back(curr);
            while(go){
                vector<ll> pos = positions[curr];
                ll num;
                for(int i=0;i<m;i++){
                    if(i == 0){
                        if(pos[i] == 1){
                            go = false; break;
                        } else {
                            num = arr[i][pos[i] - 1];
                        }
                    }
                    if(pos[i] == 1 || arr[i][pos[i] - 1] != num){
                        go = false;
                        break;
                    }
                }
                if(go){
                    len++;
                    curr = num;
                    pth.push_back(curr);
                    visited[curr] = true;
                }
            }
            for(int k = 0;k < pth.size();k++)ans_end[pth[k]] = len - k;
        }
    }
    for(int i=1;i<=n;i++)ans += ans_end[i];
    printf("%lld\n",ans);
}