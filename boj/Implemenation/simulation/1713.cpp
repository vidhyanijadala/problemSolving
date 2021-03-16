#include <bits/stdc++.h>
using namespace std;
int recommandStat[101]; //��õ ��
int pictureStat[21]; //���� �Խ� ��Ȳ
int old[101]; //���� ������ ����
int pictureCnt, n,m;

void updateTime(){
    for(int i = 1; i <= n; i++) 
        if(pictureStat[i]) 
            old[pictureStat[i]]++;
}

void updatePictureStat(int student, int i){
    old[pictureStat[i]] = 0;
    recommandStat[pictureStat[i]] = 0;
    pictureStat[i] = student;
}

void deletePicture(int minRec, int minCnt,int student){
    //��õ �� �� ���� �л� ���� ����, 
    if(minCnt == 1){
        for(int i = 1; i <= n; i++){
            if(recommandStat[pictureStat[i]] == minRec){
                updatePictureStat(student,i);
            }
        }
    }
    //�ƴ϶�� ���� ������ ���� ����
    else{
        int oldest = 0;
        int oldestIdx = 0;
        for(int i = 1; i <= n; i++){
            int num = recommandStat[pictureStat[i]];
            if(num == minRec){
                if(oldest < old[pictureStat[i]]){
                    oldest = old[pictureStat[i]];
                    oldestIdx = i;
                }
            }
        }
        updatePictureStat(student,oldestIdx);
    }
}

void insertPicture(int student){
    int minRec = 0x3f3f3f3f;
    int minCnt = 0;
    for(int i = 1; i <= n; i++) minRec= min(minRec,recommandStat[pictureStat[i]]); //�ּ���õ�� ã��
    for(int i = 1; i <= n; i++) if(minRec == recommandStat[pictureStat[i]]) minCnt++; //�ּ���õ���� ����� ã��
    deletePicture(minRec,minCnt,student);
}

bool isNewStudent(int student){
    for(int i = 1; i <= n; i++)
        if(pictureStat[i] == student) return false;
    return true;
}

int main(){
    cin >> n;
    cin >> m;
    for(int i = 0; i < m; i++){
        int studentNum;
        cin >> studentNum;
        recommandStat[studentNum]++;
        if(isNewStudent(studentNum)){
            pictureCnt++;
            if(pictureCnt > n) insertPicture(studentNum);
            else pictureStat[pictureCnt] = studentNum;
        }
        updateTime();
    }
    sort(pictureStat+1,pictureStat+1+n);
    for(int i = 1; i <= n; i++) 
        if(pictureStat[i])
            cout << pictureStat[i] << ' ';
}