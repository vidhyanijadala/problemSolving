#include <bits/stdc++.h>
using namespace std;
struct Trie {
    bool finish;    //������ ������ ǥ������
    Trie* next[26];    //26���� ���ĺ��� ���� Ʈ����
    Trie() : finish(false) {
        memset(next, 0, sizeof(next));
    }
    ~Trie() {
        for (int i = 0; i < 26; i++)
            if (next[i])
                delete next[i];
    }
    void insert(const char* key) {
        if (*key == '\0')
            finish = true;    //���ڿ��� ������ ������ ��� ǥ��
        else {
            int curr = *key - 'A';
            if (next[curr] == NULL)
                next[curr] = new Trie();    //Ž���� ó���Ǵ� ������ ��� �����Ҵ�
            next[curr]->insert(key + 1);    //���� ���� ����
        }
    }
    Trie* find(const char* key) {
        if (*key == '\0')return this;//���ڿ��� ������ ��ġ�� ��ȯ
        int curr = *key - 'A';
        if (next[curr] == NULL)return NULL;//ã�� ���� �������� ����
        return next[curr]->find(key + 1); //���� ���ڸ� Ž��
    }
};

