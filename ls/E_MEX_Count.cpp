/*
问删除一个元素以后,mex有多少种取值
1 0 0 1 2
0 0 1 1 2 ---->0 1 1 2 /0 0 1 2/ 0 0 1 1------>3,3,2---->2种(mex=2或者3)
首先排序肯定不会影响答案,
假设当前删除x个,那么如果0的个数<=x个,则mex可以为0,如果1的个数<=x且至少可以留下1个0,则mex=1
    如果2的个数<=x,且至少可以留下1个0和1个1,那么mex=2
    .....
0 1 2 3 4 5
0 1 1 2 2 3
随着k的增加mex的种类数先增加后减少
统计多余元素,即这个元素出现了多次,即使我删除他也不会影响mex
统计每个元素出现了多少次
*/
#include<bits/stdc++.h>
using namespace std;
void solve(){
    int n;
    cin>>n;
    vector<int>a(n+1);
    set<int>s;
    map<int,int>mp;
    for(int i=1;i<=n;i++)cin>>a[i],s.insert(a[i]),mp[a[i]]++;
    sort(a.begin()+1,a.end());
    int nowmex=0;
    for(auto x:s){
        if(nowmex==x)nowmex++;
        else break;
    }
    int dy=0;//多余的字符,删掉无影响
    map<int,int>mp2;//mp[i]:有多少个<nowmex的数出现的次数为i
    for(auto [x,y]:mp){
        if(x<nowmex)dy+=y-1,mp2[y]++;
        else dy+=y;
    }
    int now=1;
    cout<<now<<" ";
    for(int i=1;i<=dy;i++){
        now+=mp2[i];
        cout<<now<<" ";
    }
    vector<int>res;
    for(int i=1;i<=nowmex;i++)res.push_back(i);
    reverse(res.begin(),res.end());
    for(auto x:res)cout<<x<<" ";
    cout<<'\n';
}
signed main(){
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    int T__=1;cin>>T__;
    while(T__--)solve();
    return 0;
}
