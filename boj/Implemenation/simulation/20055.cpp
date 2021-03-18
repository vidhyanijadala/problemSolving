#include <bits/stdc++.h>
using namespace std;
int n,k;
//������ 0 ~ n-1������ ��Ʈ
//�Ʒ����� n ~ 2*n-1������ ��Ʈ
struct square{
    int durability,robot;
};

void processOne(vector <square> &belt){
    vector <square> tmp(2*n);
    tmp[0].durability = belt[2*n-1].durability;
    tmp[0].robot = belt[2*n-1].robot;
   
    for(int i = 0; i < 2 * n - 1; i++){
        tmp[i+1].durability = belt[i].durability;
        tmp[i+1].robot = belt[i].robot;
    }
    belt = tmp;
    if(belt[n-1].robot) belt[n-1].robot = 0;
}
    

void processTwo(vector <square> &belt){
    vector<int>moved(2*n);
    //n-1ĭ�� �κ��� �̹� ���� ���� 0 ~ n-1���� �Ű��ָ��
    for(int i = n-2; i >= 0; i--){
        //����ĭ�� ������ ���̰� �κ��� ������ �Ű���.
        if(belt[i].robot && !belt[i+1].robot && belt[i+1].durability){
            belt[i+1].robot = 1;
            belt[i].robot = 0;
            if(belt[i+1].durability) belt[i+1].durability--;
        }
    }
    belt[n-1].robot = 0;
};

void processThree(vector <square> &belt){
    if(belt[0].durability && !belt[0].robot) {
        belt[0].robot = 1;
        belt[0].durability--;
    }
};

int getZeroDuration(vector <square> &belt){
    int cnt = 0;
    for(auto b : belt){
        if(!b.durability) cnt++;
    }
    return cnt;
}

void print(vector <square> &belt){
    cout << "belt : ";
    for(int i  =0; i < 2*n; i++){
        cout << belt[i].durability << ' ';
    }
    cout << '\n';
    cout << "robot : ";
    for(int i  =0; i < 2*n; i++){
        cout << belt[i].robot << ' ';
    }
    cout << '\n';
    cout << '\n';
}
int beltProcess(vector <square> &belt,int k){
    int processNum = 0;
    while(1){
        processNum++;
        processOne(belt); //ȸ��
        processTwo(belt);//�κ� �̵�
        processThree(belt);//�κ� �ø��� 
        if(getZeroDuration(belt) >= k) break;//0�������� k�� �̻��̸�
    }
    return processNum;
}

int main(){
    cin >> n >> k;
    vector <square> belt(2*n);
    for(int i = 0; i < 2 * n; i++) {
        int d;
        cin >> d;
        belt[i] = {d,0};
    }
    cout << beltProcess(belt,k) <<'\n';
}