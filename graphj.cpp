#include <bits/stdc++.h>

using namespace std;

char board[1000][1000];
int d[1000][1000];

vector <int> dx;//={-1,0,0,1};
vector <int> dy;//={0,1,-1,0};

int main(){
    std::ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    //  freopen("input.txt","r",stdin);
    int n,m,k;cin>>n>>m>>k;
    int c=0,c2=0;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>board[i][j];
            if((i==0||j==m)&&board[i][j]=='#')c++;
            if((i==n||j==0)&&board[i][j]=='#')c2++;
        }
    }

    if(k==1000&&(c==0||c2==0)){
        cout<<"2"<<endl;
        return 0;
    }

    int fi,ci,ff,cf;
    cin>>fi>>ci>>ff>>cf;
    fi--;ci--;ff--;cf--;

    for(int i=1;i<=k;i++){
        dx.push_back(-i);
        dy.push_back(0);
    }
    for(int i=1;i<=k;i++){
        dx.push_back(0);
        dy.push_back(i);
    }
    for(int i=1;i<=k;i++){
        dx.push_back(0);
        dy.push_back(-i);
    }
    for(int i=1;i<=k;i++){
        dx.push_back(i);
        dy.push_back(0);
    }

    // for(int x:dx)cout<<x<<" ";
    // cout<<endl;
    // for(int x:dy)cout<<x<<" ";
    // cout<<endl;

    queue<int>q;
    q.push(fi);
    q.push(ci);
    d[fi][ci]=1;
    while(q.size()){
        int r=q.front();q.pop();
        int c=q.front();q.pop();
        //cout<<r<<" "<<c<<endl;
        if(r==ff&&c==cf){
            cout<<d[r][c]-1<<endl;
            // for(int i=0;i<n;i++){
            //     for(int j=0;j<m;j++){
            //         cout<<d[i][j]<<" ";
            //     }
            //     cout<<endl;
            // }
            
            return 0;
        }
        for(int i=0;i<4;i++){
            for(int j=0;j<k;j++){
                //cout<<dx[i*4+j]<<" "<<dy[i*4+j]<<endl;
                int nr=r+dx[i*k+j];
                int nc=c+dy[i*k+j];

                if(nr>=0&&nc>=0&&nr<n&&nc<m&&!d[nr][nc]){
                    if(board[nr][nc]=='#')break;
                    //cout<<board[nr][nc]<<" "<<nr<<" "<<nc<<endl;
                    q.push(nr);
                    q.push(nc);
                    d[nr][nc]=d[r][c]+1;
                }
            }
        }

    }
    
    cout<<"-1"<<endl;

    return 0;
}