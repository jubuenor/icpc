#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;
 
struct _data{
    ll a,b,w;
};
 
const ll oo=LLONG_MAX/2;
ll dist[10000];
vector<_data> edges;
vector<ll> parents[10000];
vector<ll> path;
bool seen[10000];
 
void dfs(ll u,ll p){
    if(seen[u]&&u!=p)return;
    //cout<<u<<" ";
    seen[u]=true;
 
    for(ll v:parents[u]){
        if(!seen[v])
            dfs(v,p);
    }
 
    path.push_back(u);
}
 
 
int main(){
    int n,m;cin>>n>>m;
    for(int i=0;i<m;i++){
        ll a,b,w;
        cin >>a>>b>>w;
        edges.push_back({a,b,w});
    }
 
    for(int i=0;i<=n;i++){
        dist[i]=oo;
        parents[i].push_back(0);
    }
 
    int child;
    for(int i=0;i<n;i++){
        child=-1;
        for (auto &e :edges){
            ll daux=dist[e.b];
            dist[e.b]= min(dist[e.b],dist[e.a]+e.w);
            if(daux!=dist[e.b]){
                child=e.b;
                parents[e.b][0]=e.a;
            }
        }
    }
    //otra iteracion para ver si hay ciclos
    for (auto &e :edges){
        ll daux=dist[e.b];
        dist[e.b]= min(dist[e.b],dist[e.a]+e.w);
        if(daux!=dist[e.b]){
            parents[e.b][0]=e.a;
        }
    }
    if(child==-1){
        cout<<"NO"<<endl;
        return 0;
    }
    cout<<"YES"<<endl;
    //cout<<edges[child].a<<" "<<edges[child].b<<endl;
 
    //for(int i=1;i<=n;i++){
    //    cout<<i<<" ";
    //    for(int j=0;j<parents[i].size();j++)
    //        cout<<parents[i][j]<<" ";
    //    cout<<endl;
    //}
 
    //cout<<child<<endl;
    for(int i=0;i<n;i++){
        //cout<<child<<" ";
        child=parents[child][0];
    }
    //cout<<endl;
    //cout<<"DFS: "<<child<<endl;
    ll parent=child;
    while(true){
        //cout<<child<<"  ";
        child=parents[child][0];
        path.push_back(child);
        if(child == parent)
            break;
    }
    //dfs(child,child);
    //cout<<endl;
    reverse(path.begin(),path.end());
    path.push_back(path.front());
    for(int x:path)cout<<x<<" ";
 
    return 0;
}