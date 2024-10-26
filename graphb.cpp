#include <bits/stdc++.h>

using namespace std;
int n,m;

char board[1000][1000];
int d[1000][1000];
int dmonsters[1000][1000];

const int dx[]={-1,0,0,1};
const int dy[]={0,1,-1,0};
char s[]={'D','L','R','U'};


vector<char> steps;
vector<pair<int,int> > monsters;
vector<pair<int,int>> exits;

void bfs(){
    queue<int>q;
    for(pair<int,int> x:monsters){
        q.push(x.first);
        q.push(x.second);
        dmonsters[x.first][x.second]=1;
        
    }
    while(q.size()){
        int r=q.front();q.pop();
        int c=q.front();q.pop();
        for(int i=0;i<4;i++){
            int nr=r+dx[i];
            int nc=c+dy[i];
            if(nr>=0&&nc>=0&&nr<n&&nc<m&&board[nr][nc]=='.'&&!dmonsters[nr][nc]){
                q.push(nr);
                q.push(nc);
                dmonsters[nr][nc]=dmonsters[r][c]+1;
            }
        }
    }
}

void print_steps(int ff, int cf){
    int x=ff,y=cf;
    while(d[x][y]>1){
        for(int i=0;i<4;i++){
        int nr=x+dx[i];
        int nc=y+dy[i];
        if(nr>=0&&nc>=0&&nr<n&&nc<m&&d[nr][nc]==d[x][y]-1){
                steps.push_back(s[i]);
                x=nr;y=nc;
            }
        }
    }

    for(int i=d[ff][cf]-2;i>=0;i--)cout<<steps[i];

}

int main(){
    std::ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    //freopen("input.txt","r",stdin);
    cin>>n>>m;
    int fi,ci;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            char c;cin>>c;
            board[i][j]=c;
            if(c=='A'){
                board[i][j]='.';
                fi=i;ci=j;
            }
            if(c=='M'){
                board[i][j]='.';
                monsters.push_back({i,j});
            }
        }
    }
    queue<int>q;
    q.push(fi);
    q.push(ci);
    d[fi][ci]=1;

    
    while(q.size()){
        int r=q.front();q.pop();
        int c=q.front();q.pop();
        if(r==n-1||c==m-1||r==0||c==0){
            exits.push_back({r,c});            
        }
        for(int i=0;i<4;i++){
            int nr=r+dx[i];
            int nc=c+dy[i];
            if(nr>=0&&nc>=0&&nr<n&&nc<m&&board[nr][nc]=='.'&&!d[nr][nc]){
                q.push(nr);
                q.push(nc);
                d[nr][nc]=d[r][c]+1;
            }
        }

    }
    bfs();
    
    bool flag=false;
    int x,y;
    for(pair<int,int> e:exits){
        x=e.first,y=e.second;
        if(d[x][y]<dmonsters[x][y]||!dmonsters[x][y]){
            flag=true;
            break;
        }
    }
    if(!flag){
        cout<<"NO"<<endl;
        return 0;
    }

    cout<<"YES"<<endl;
    cout<<d[x][y]-1<<endl;

    print_steps(x,y); 

    return 0;
}
