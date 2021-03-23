#include <bits/stdc++.h>
using namespace std;
using pii = pair <int,int>;
//�̵� �� �̹� ������ ����� �ٷ� �� ��ĥ �� ����
int n, ans;
int board[21][21];
int boardCopy[21][21];
int stat[5];
int dx[]={-1,0,1,0};
int dy[]={0,1,0,-1};
//dir = 0 : ��, 1 : ��, 2 : ��, 3 : �·� �̵�
void moveBlock(int dir){
    queue <pii> q; //��,��
    int isCombined[21][21];
    memset(isCombined,0,sizeof(isCombined));
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if(j < n-1 && boardCopy[j][i] != 0 && boardCopy[j][i] == boardCopy[j+1][i] ){
                q.push({boardCopy[j][i] + boardCopy[j+1][i],i});
                boardCopy[j][i] = 0;
                boardCopy[j+1][i] = 0;
                j++;
            }
            if(boardCopy[j][i])
                q.push({boardCopy[j][i],i});
        }
    }
    //q�� �� ����Ǿ� ����
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            boardCopy[i][j] = 0;
        }
    }
    //boardCopy�� �ٲ� �� ����
    int rowPivot = 0;
    int colPivot = 0; //���� � �� �� ���ʴ�
    while(!q.empty()){
        int val = q.front().first;
        int col = q.front().second;
        q.pop();
        if(colPivot != col) {colPivot = col,rowPivot = 0;}
        boardCopy[rowPivot++][col] = val;
    }
}

void copyBoard(){
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            boardCopy[i][j] = board[i][j];
        }
    }
}

int getMaxBlock(){
    int big = 0;
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
            big = max(big,boardCopy[i][j]);
    return big;
}

void rotateBoardCopy(){
    
}
void printBoardCopy(){
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++) cout << boardCopy[i][j] << ' ';
        cout << '\n';
    }
    cout << '\n';
}

int main(){
    cin >> n;
    //5�� �̵����� �ּ�
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cin >> board[i][j];
        }
    }
    //�� �̵� ������ 0,1,2,3���� ǥ����
    //i��° �̵��� �̵� ������ 1 2 1 2 1 �̷������� ǥ��
    //i��° �̵� ���� ���ϰ� �̵��ϱ�

    for(int i = 0; i < 4; i++){
        copyBoard();
        moveBlock(i);
        printBoardCopy();
    }
    // for(int movedStat = 0; movedStat < 1 << (2 * 5); movedStat++){
    //     copyBoard();
    //     for(int j = 0; j < 5; j++){

    //     }

    // }
}