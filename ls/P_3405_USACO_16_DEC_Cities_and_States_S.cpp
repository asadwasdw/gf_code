#include<bits/stdc++.h>
using namespace std;
int n,ans;
const int N=2e5+5;
string c[N],s[N];
int main(){
        cin>>n;
        for(int i=1;i<=n;i++){ 
                cin>>c[i]>>s[i];
        }
        for(int i=1;i<=n;i++){
                for(int j=1;j<i;j++){
                        if(c[i].substr(0,2)==s[j] && c[j].substr(0,2)==s[i]){
                                ans++;
                        }
                }
        }
        cout<<ans<<"\n";
        return 0;
}