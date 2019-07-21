#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

int main(){
    char s[1000001];scanf("%s",s); string str(s);

    if(str.length() <= 3){
        cout << str[0] << endl;
    } else {
        vector<char> first_half;
        stack<char> sec_half;
        ll ptr1 = 0, ptr2 = str.length() - 1;
        while(ptr2 - ptr1 + 1 >= 4){
            if((str[ptr1] == str[ptr2]) || (str[ptr1] == str[ptr2 - 1])){
                first_half.push_back(str[ptr1]);sec_half.push(str[ptr1]);
            } else if((str[ptr1 + 1] == str[ptr2]) || (str[ptr1 + 1] == str[ptr2 - 1])){
                first_half.push_back(str[ptr1 + 1]);sec_half.push(str[ptr1 + 1]);
            }
            ptr1 += 2; ptr2 -= 2;
        }
        if((ptr2 - ptr1 + 1 <= 3) && (ptr2 - ptr1 + 1 > 0))first_half.push_back(str[ptr1]);
        while(!sec_half.empty()){
            first_half.push_back(sec_half.top());
            sec_half.pop();
        }
        string str = "";for(auto it: first_half)str += it;
        cout << str << endl;
    }

}