#include <bits/stdc++.h>

using namespace std;
int k = 30;
struct bohr_vrtx {
    int next_vrtx[k];
    int pat_num;
    bool flag;
};

vector <bohr_vrtx> bohr;

bohr_vrtx make_bohr_vrtx() {
    bohr_vrtx v;
    //(255)=(2^8-1)=(все единицы в каждом байте памяти)=(-1 в дополнительном коде целого 4-байтного числа int)
    memset(v.next_vrtx, 255, sizeof(v.next_vrtx));
    v.flag = false;
    return v;
}

void bohr_ini() {
    //добавляем единственную вершину - корень
    bohr.push_back(make_bohr_vrtx());
}

void add_string_to_bohr(const string &s) {
    int num = 0; //начинаем с корня
    for (int i = 0; i < s.length(); i++) {
        char ch = s[i] - 'a'; //получаем номер в алфавите
        if (bohr[num].next_vrtx[ch] == -1) { //-1 - признак отсутствия ребра
            bohr.push_back(make_bohr_vrtx());
            bohr[num].next_vrtx[ch] = bohr.size() - 1;
        }
        num = bohr[num].next_vrtx[ch];
    }
    bohr[num].flag = true;
    pattern.push_back(s);
    bohr[num].pat_num = pattern.size() - 1;
}

bool is_string_in_bohr(const string &s) {
    int num = 0;
    for (int i = 0; i < s.length(); i++) {
        char ch = s[i] - 'a';
        if (bohr[num].next_vrtx[ch] == -1) {
            return false;
        }
        num = bohr[num].next_vrtx[ch];
    }
    return true;
}

int main() {
}
