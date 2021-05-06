#include <bits/stdc++.h>
using namespace std;
int board[51][51], boardCopy[51][51],ck[10];
int n, m, k, ans=0x3f3f3f3f;
vector <int> comb;
vector <vector<int>> op;

void rotate(int x1, int y1, int x2, int y2){
    int curVal = boardCopy[x1][y1];
    //��� ��������
    for(int i = y1+1; i <= y2; i++)
        swap(curVal,boardCopy[x1][i]);
    //���� �Ʒ���
    for(int i = x1+1; i <= x2; i++)
        swap(curVal,boardCopy[i][y2]);
    //�ϴ� ��������
    for(int i = y2-1; i >= y1; i--)
        swap(curVal, boardCopy[x2][i]);
    //���� �������
    for(int i = x2 - 1; i >= x1; i--)
        swap(curVal, boardCopy[i][y1]);
}

int getMinValFromRow(){
    int minVal = 0x3f3f3f3f;
    for(int i = 1; i <= n; i++){
        int sum = 0;
        for(int j = 1; j <= m; j++) sum += boardCopy[i][j];
        minVal = min(minVal,sum);
    }
    return minVal;
}

void copyBoard(){
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++) {
            boardCopy[i][j] = board[i][j];
        }
    }
}

void dfs(int depth){
    if(depth == k){
        copyBoard();
        for(auto &c : comb){
            vector <int> range = op[c];
            for(int i = 0; i < range[4]; i++)
                rotate(range[0] + i,range[1] + i,range[2] - i,range[3] - i);
        }
        ans = min(ans,getMinValFromRow());
        return;
    }

    for(int i = 0; i < k; i++){
        if(ck[i]) continue;
        ck[i] = 1;
        comb.push_back(i);
        dfs(depth+1);
        comb.pop_back();
        ck[i] = 0;
    }

}

int main(){
    cin >> n >> m >> k;
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= m; j++)
            cin >> board[i][j];

    for(int i = 0; i < k; i++){
        int r,c,s,x1,y1,x2,y2;
        cin >> r >> c >> s;
        x1 = r-s;
        y1 = c-s;
        x2 = r+s;
        y2 = c+s;
        op.push_back({x1,y1,x2,y2,s});
    }

    dfs(0);
    cout << ans << '\n';
}