#include <bits/stdc++.h>
using namespace std;
using pii = pair<int,int>;
int n, m, d, ans, killedEnemy;

int boardCopy[20][20],board[20][20], ck[20][20], dist[20][20], killCount[20][20];


void print(){
    cout << '\n';
    for(int i = 1; i <= n ; i++){
        for(int j = 1; j <= m; j++){
            cout << boardCopy[i][j] << ' ';
        }
        cout << '\n';
    }
    for(int i = 1; i<= m; i++)
        cout << boardCopy[n+1][i] << ' ';
    cout << '\n';
}

void printD(){
    cout << '\n';
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            cout << dist[i][j] << ' ';
        }
        cout << '\n';
    }
}


void getDistanceFrom(int arcNum){
    memset(dist,0,sizeof(dist));
    //n+1,arcNum
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            if(!boardCopy[i][j]) continue;
            dist[i][j] = abs(n+1 - i) + abs(arcNum - j);
        }
    }
}

void killEnemy(){
    int cnt = 0x3f3f3f3f;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            if(!killCount[i][j]) continue;
            cnt = min(cnt,killCount[i][j]);
        }
    }
}

void countEnemyToKill(int col){
    int minDist = 0x3f3f3f3f;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            if(dist[i][j] > d || !dist[i][j]) continue;
            minDist = min(minDist,dist[i][j]);
        }
    }
    // cout << "DIST\n";
    // for(int i = 1; i <= n; i++){
    //     for(int j = 1; j <= m; j++){
    //         cout << dist[i][j] << ' ';

    //     }
    //     cout << '\n';
    // }
    for(int i = 1; i <= m; i++){
        for(int j = n; j >= 1; j--){
            if(minDist != dist[i][j]) continue;
            killCount[i][j]++;
        }
    }
}

void goDown(){
    for(int i = 1; i <= m; i++){
        for(int j = n; j >= 1; j--){
            if(!boardCopy[j][i]) continue;
            if(j==n) boardCopy[j][i] = 0;
            else{
                boardCopy[j][i] = 0;
                boardCopy[j+1][i] = 1;
            }
        }
    }
}

bool enemyExist(){
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            if(boardCopy[i][j]) return 1;
        }
    }
    return 0;
}

void copyBoard(){
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            boardCopy[i][j] = board[i][j];
        }
    }
}

void dfs(int depth, int idx){
    if(depth==3){
        killedEnemy = 0;
        copyBoard();
        while(enemyExist()){
            memset(killCount,0,sizeof(killCount));
            for(int arcNum = 1; arcNum <= m; arcNum++) {
                if(!boardCopy[n+1][arcNum]) continue;
                getDistanceFrom(arcNum);
                countEnemyToKill(arcNum);
                // cout << "BORDCOPY :";
                // print();
            }
            killEnemy();
            goDown();
            // cout << "GODOWN :";
            // print();
            ans = max(ans,killedEnemy);
        }

        return;
    }
    for(int i = idx; i <= m; i++){
        if(ck[n+1][i]) continue;
        ck[n+1][i] = 1;
        boardCopy[n+1][i] = 1;
        dfs(depth+1, i+1);
        boardCopy[n+1][i] = 0;
        ck[n+1][i] = 0;
    }
}

int main(){
    cin >> n >> m >> d;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            cin >> board[i][j];
        }
    }
    dfs(0,1);
    cout << ans << '\n';
}