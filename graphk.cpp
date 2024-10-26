#include <bits/stdc++.h>

using namespace std;

const int N=1e6;

vector<int> g[N];
vector<int> path;

int in_degree[N];
int out_degree[N];


void dfs(int u){
    while(!g[u].empty()){
        int v=g[u].back();
        g[u].pop_back();
        dfs(v);
        
    }
    path.push_back(u);
}

int main(){
    std::ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    //freopen("input.txt","r",stdin);
    int n,m;cin>>n>>m;
    for(int i=0;i<m;i++){
        int a,b;cin>>a>>b;
        g[a].push_back(b);
        in_degree[b]++;
        out_degree[a]++;
    }
    // verificar existenica de camino euleriano


    int c=0;
    for(int i=1;i<=n;i++){
        //cout<<i<<") "<<in_degree[i]<<" + "<<out_degree[i]<<" = "<<in_degree[i]+out_degree[i]<<endl;
        if((in_degree[i]+out_degree[i])%2==1){
            c++;
        }
    }
    //cout<<c<<endl;
    if(c!=2){
        cout<<"IMPOSSIBLE";
        return 0;
    }

    dfs(1);
    if(n>m&&path.size()!=m){
        cout<<"IMPOSSIBLE";
        return 0;
    }

    for(int i=path.size()-1;i>=0;i--)cout<<path[i]<<" ";


    return 0;
}