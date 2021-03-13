#include <bits/stdc++.h>
using namespace std;
using pii = pair<int,int>;
int picture[501][501];
int visited[501][501];
int dx[4] = {0,0,-1,1};
int dy[4] = {-1,1,0,0};
int areaCnt, maxArea;
int n,m;

int bfs(int i, int j){
    queue <pii> q;
    visited[i][j] = 1;
    q.push({i,j});
    int area = 1;
    while(!q.empty()){
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        for(int i = 0; i < 4; i++){
            int nx = x + dx[i];
            int ny = y + dy[i];
            if(0 > nx || nx >= n || 0 > ny || ny >= m) continue;
            if(visited[nx][ny] || !picture[nx][ny]) continue;
            visited[nx][ny] = 1;
            area++;
            q.push({nx,ny});
        }
    }
    return area;
}

int main(){
    cin >> n >> m;
    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++)
            cin >> picture[i][j];

    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(!visited[i][j] && picture[i][j]){
                areaCnt++;
                maxArea = max(maxArea,bfs(i,j));
            }
        }
    }

    cout << areaCnt << '\n';
    cout << maxArea << '\n';
}