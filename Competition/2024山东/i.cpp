#include<bits/stdc++.h>
using namespace std;


int main(){
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t;
    cin >> t;
    while(t--){
        string s;
        cin >> s;
        int n = s.size();
        bool f = false;
        for(int i=0; i<s.size(); ++i){
            if(s[i] == s[(i+n-1)%n]){
                f = true;
                cout << i << endl;break;
            }
        }
        if(!f)
        cout << -1 <<endl;
    }


    return 0;
}