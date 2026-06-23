#include<bits/stdc++.h>
using namespace std;
int m,n,k,know[100005],lq[100005],mlq,mlqp,tlq;
vector<int>que[100005];
int main(){
    cin>>m>>n>>k;
    for(int i=1;i<=n;i++){
        cin>>know[i];
    }
    for(int i=1;i<=n;i++){
        int add;
        cin>>add;
        que[know[i]].push_back(add);
    }
    
    for(int i=1;i<=m;i++){
        sort(que[i].begin(),que[i].end(),greater<int>());
        int cnt=0;
        while(cnt<k){
            if(lq[i]==que[i].size()){
                cout<<"-1";
                return 0;
            }
            cnt+=que[i][lq[i]++];
        }
        // lq[i]--;
        if(lq[i]>mlq){
            mlq=lq[i],mlqp=i;
        }
        tlq+=lq[i];
        // cout << tlq << " " << lq[i] << endl;
    }
    if(mlq>=n-que[mlqp].size()){
        cout<<"-1";
    }
    else{
        cout<<tlq;
    }
    return 0;
}