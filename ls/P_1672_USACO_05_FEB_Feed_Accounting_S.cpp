#include<bits/stdc++.h>
using namespace std;
int c,f1,f2,d,ans,s[105],t[105],a[20005];
int main(){
    cin >> c >> f1 >> f2 >> d;
    for(int i = 1;i <= c;i++){
        cin >> s[i] >> t[i];
        a[s[i]]++;
        a[t[i] + 1]--;
    }
    for(int i = 1;i <= d;i++){
        a[i] += a[i - 1];
    }
    ans = f1;
    for(int i = 1;i <= d;i++){
        if(ans == f2){
            cout << i;
            return 0;
        }
        ans -= a[d - i - 1];
    }
    return 0;
}
//TVT