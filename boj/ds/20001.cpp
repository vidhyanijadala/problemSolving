#include <bits/stdc++.h>
using namespace std;
queue <string> q;
string s;
int main(){
    while(1){
        getline(cin, s);
        if(s == "������ ����� ��") break;
        else if(s == "����") q.push(s);
        else if(s == "������"){
            if(q.empty()) {
                q.push("����");
                q.push("����");
            }
            else q.pop();
        } 
    }
   
    if(!q.empty()) cout << "����";
    else cout << "�������� �����";
}