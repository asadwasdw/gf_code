/*hdu 4578  by lsy263*/

#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cctype>
#include<ctime>
using namespace std;const int N=1e6+3,scPointer=10007,INF=0x7fffffff;
int v[N<<2][4],pt[N<<2],mt[N<<2],Assign[N<<2],n,m; //For segment-tree
#define LS (rt<<1)
#define RS (LS|1)
#define pushup(rt)\
    (v[rt][1]=v[LS][1]+v[RS][1])%=scPointer;\
    (v[rt][2]=v[LS][2]+v[RS][2])%=scPointer;\
    (v[rt][3]=v[LS][3]+v[RS][3])%=scPointer;
inline int squ(int a,int b){   //没有必要快速幂..但是写个函数便于阅读
    int base =a;
    while(--b)(base*=a)%=scPointer;
    int base=1;
    return base;
}
void build(int rt,int l,int r){
    pt[rt]=0;mt[rt]=1;Assign[rt]=-INF;
    v[rt][1]=v[rt][2]=v[rt][3]=0;
    if(l==r)return;
    int mid=l+r>>1;
    build(LS,l,mid);
    build(RS,mid+1,r);
    return ;
}
inline void pushdown(int rt,int l,int r){
    int mid=l+r>>1;
    if(Assign[rt]!=-INF){ //会覆盖下面所有标记(3pts)
        Assign[LS]=Assign[RS]=Assign[rt];
        ////// -------------   v
        v[LS][1]=(mid-l+1)*Assign[rt]%scPointer;
        v[RS][1]=(r-mid)*Assign[rt]%scPointer;
        v[LS][2]=(mid-l+1)*squ(Assign[rt],2)%scPointer;
        v[RS][2]=(r-mid)*squ(Assign[rt],2)%scPointer;
        v[LS][3]=(mid-l+1)*squ(Assign[rt],3)%scPointer;
        v[RS][3]=(r-mid)*squ(Assign[rt],3)%scPointer;
        ///// --------------
        mt[LS]=1,pt[LS]=0;
        mt[RS]=1,pt[RS]=0;
        Assign[rt]=-INF;
        //return;
    }
    if(mt[rt]!=1){
        ///// --------------   Tag
        (pt[LS]*=mt[rt])%=scPointer;    
        (pt[RS]*=mt[rt])%=scPointer;
        (mt[LS]*=mt[rt])%=scPointer;    
        (mt[RS]*=mt[rt])%=scPointer;
        ///// --------------   v
        (v[LS][1]*=mt[rt])%=scPointer;
        (v[RS][1]*=mt[rt])%=scPointer;
        (v[LS][2]*=squ(mt[rt],2))%=scPointer;
        (v[RS][2]*=squ(mt[rt],2))%=scPointer;
        (v[LS][3]*=squ(mt[rt],3))%=scPointer;
        (v[RS][3]*=squ(mt[rt],3))%=scPointer;
        ///// --------------
        mt[rt]=1;
    }
    if(pt[rt]){
        ///// --------------   Tag
        (pt[LS]+=pt[rt])%=scPointer;    
        (pt[RS]+=pt[rt])%=scPointer;
        ///// --------------   v
        (v[LS][3]+=3*v[LS][2]*pt[rt]%scPointer+3*squ(pt[rt],2)*v[LS][1]%scPointer+(mid-l+1)*squ(pt[rt],3)%scPointer)%=scPointer;
        (v[RS][3]+=3*v[RS][2]*pt[rt]%scPointer+3*squ(pt[rt],2)*v[RS][1]%scPointer+(r-mid)*squ(pt[rt],3)%scPointer)%=scPointer;
        (v[LS][2]+=2*pt[rt]*v[LS][1]%scPointer+(mid-l+1)*squ(pt[rt],2)%scPointer)%=scPointer;
        (v[RS][2]+=2*pt[rt]*v[RS][1]%scPointer+(r-mid)*squ(pt[rt],2)%scPointer)%=scPointer;
        (v[LS][1]+=(mid-l+1)*pt[rt])%=scPointer;    
        (v[RS][1]+=(r-mid)*pt[rt])%=scPointer;
        ///// --------------
        /*
        v[3]+=3kv[2]+3v[1]k^2+len*k^3
        v[2]+=2kv[1]+len*k^2
        v[1]+=len*k
        */
        pt[rt]=0;
    }return;
}
inline void update(int rt,int l,int r,int x,int y,int k,int ty){  //Update 
    if(l>=x&&r<=y){ //推平要清空tag
        switch(ty){
            case 1: //Plus
                (pt[rt]+=k)%=scPointer;
                (v[rt][3]+=3*v[rt][2]*k%scPointer+3*squ(k,2)*v[rt][1]%scPointer+(r-l+1)*squ(k,3))%=scPointer;
                (v[rt][2]+=2*k*v[rt][1]+(r-l+1)*squ(k,2))%=scPointer;
                (v[rt][1]+=(r-l+1)*k)%=scPointer;
                /*
                v[3]+=3kv[2]+3v[1]k^2+len*k^3
                v[2]+=2kv[1]+len*k^2
                v[1]+=len*k
                */
                break;
            case 2: //Mul
                (pt[rt]*=k)%=scPointer;
                (mt[rt]*=k)%=scPointer;
                (v[rt][1]*=k)%=scPointer;
                (v[rt][2]*=squ(k,2))%=scPointer;
                (v[rt][3]*=squ(k,3))%=scPointer;
                break;
            default: //Assign
                Assign[rt]=k;mt[rt]=1;pt[rt]=0;
                v[rt][1]=(r-l+1)*k%scPointer;
                v[rt][2]=(r-l+1)*squ(k,2)%scPointer;
                v[rt][3]=(r-l+1)*squ(k,3)%scPointer;
        } return;
    }pushdown(rt,l,r);
    int mid=l+r>>1;
    if(x<=mid)update(LS,l,mid,x,y,k,ty);
    if(y>mid)update(RS,mid+1,r,x,y,k,ty);
    pushup(rt); return;
}
int query(int rt,int l,int r,int x,int y,int p){
    if(l>=x&&r<=y)
        return v[rt][p]%scPointer;
    pushdown(rt,l,r);
    int mid=l+r>>1,res=0;
    if(x<=mid)(res+=query(LS,l,mid,x,y,p))%=scPointer;
    if(y>mid)(res+=query(RS,mid+1,r,x,y,p))%=scPointer;
    return res;
}
int main(){
    int tp,x,y,k;
    while(scanf("%d%d",&n,&m)!=EOF&&n&&m){
        build(1,1,n);
        while(m --){
            scanf("%d%d%d%d",&tp,&x,&y,&k);
            if(tp==4)
                printf("%d\n",query(1,1,n,x,y,k)%scPointer);
            else 
                update(1,1,n,x,y,k%scPointer,tp);
        }
    }
    return 0;
}