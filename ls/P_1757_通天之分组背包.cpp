#include <bits/stdc++.h>
using namespace std;
int n,m;
int dp[110][1001];
int w[1101],v[1101],c[1001];
vector<int> id[110];
int main(){
    cin>>m>>n;
    int len=-1;
    for(int i=1;i<=n;i++){
        int tmp=0;
        cin>>w[i]>>v[i]>>tmp;
        id[tmp].push_back(i);
        len=max(len,tmp);
    }
    for(int i=1;i<=len;i++){
        for(int j=m;j>=1;j--){
            for(int k=0;k<id[i].size();k++){
                int z=id[i][k];
                if(j>=w[z]){
                    dp[i][j]=max(dp[i][j],dp[i-1][j-w[z]]+v[z]);
                } else {
                    dp[i][j] = dp[i - 1][j];
                }
            }
        }
    }
    cout<<dp[len][m]<<endl;
}