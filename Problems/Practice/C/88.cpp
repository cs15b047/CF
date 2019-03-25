// C. Color Stripe
// #135 -2 
// case for k = 2 and k > 2
#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
int main(){
    ll n,k;
    cin>>n>>k;
    char s[500001];scanf("%s",s);
    string str(s);

    // only 2 solns for k =2
    if(k == 2){
        string temp1 = str, temp2 = str;
        // soln 1
        ll ans1,ans2=0;
        for(int i=0;i<n;i++){
            char desired1 = (i%2==0)*'A' + (i%2==1)*'B';
            char desired2 = (i%2==0)*'B' + (i%2==1)*'A';
            if(temp1[i] == desired1);
            else{
                ans1++;
                temp1[i] = desired1;
            }
            if(temp2[i] == desired2);
            else{
                ans2++;
                temp2[i] = desired2;
            }
        }
        if(ans1 < ans2){
            cout << ans1 << endl;
            cout << temp1 << endl;
        }
        else{
            cout << ans2 << endl;
            cout << temp2 << endl;        
        }
    }
    else{
        map<ll,ll> start_parity;
        int i=0;
        ll ans = 0 ;
        while(i<n){
            int start = i;
            while(i < n && str[i] == str[start])i++;
            int len = (i - start);
            if(len % 2 == 0)ans += len / 2 ;
            if(len % 2 == 1)ans += (len - 1) / 2 ;
            // start_parity[start] = (len % 2) ;

            if(len % 2 == 1){
                for(int j=start + 1;j <= (start + len - 1); j += 2 ){
                    int index = str[j] - 'A';
                    // cout << j << " " << index << endl;
                    str[j] = 'A' + (index + 1) % k;
                }
            }
            else{
                int prev = -1, next = -1;
                if(start != 0)prev = str[start - 1] - 'A';
                char repl;
                for(int j = start; j <= start + len - 1; j += 2){
                    if(j == start){
                        if(prev == -1){
                            str[j] = 'A' + (str[j] - 'A' + 1) % k ;
                            repl = str[j];
                        }
                        else{
                            if((prev + 1) % k != (str[j] - 'A') )str[j] = 'A' + (prev + 1) % k;
                            else str[j] = 'A' + (str[j] - 'A' + 1) % k ;
                        }
                        repl = str[j];
                    }
                    else{
                        str[j] = repl ;
                    }
                }
            }
        }
        cout << ans << endl ;
        cout << str << endl ;
    }


}