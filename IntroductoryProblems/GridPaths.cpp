// https://cses.fi/paste/4d82d34e3d954a178abf62/
#pragma GCC optimize("Ofast,unroll-loops")
#include <iostream>
using namespace std;
string s; 
const int sz = 7;
// D, U, L, R

int move_y[] = {1, -1, 0, 0};
int move_x[] = {0, 0, -1, 1};
bool visited[sz + 2][sz + 2];

int dfs (pair<int, int> v = {1, 1}, int len = 0) {
    auto [y, x] = v;
    if (visited[y][x] == true) return 0;
    if (y == sz && x == 1) {
        if (len == sz * sz - 1)
            return 1;
        return 0;
    }
    if (len == sz * sz - 1) return 0;
    bool neigh[4];
    for (int i = 0; i < 4; i++) {
        int dy = move_y[i];
        int dx = move_x[i];
        neigh[i] = visited[y + dy][x + dx];
    }
    if (neigh[0] == neigh[1] &&
        neigh[2] == neigh[3] &&
        neigh[1] != neigh[2])
        return 0;
    int tmp_ans = 0;
    visited[y][x] = true;
    for (int i = 0; i < 4; i++) {
        if (s[len] == '?' || s[len] - '0' == i) {
            int dy = move_y[i];
            int dx = move_x[i];
            if (visited[y + dy][x + dx] == true) continue;
            tmp_ans += dfs({y + dy, x + dx}, len + 1);
        }
    }
    visited[y][x] = false;
    return tmp_ans;
};

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin >> s;
    for (int i = 0; i < sz + 2; i++) {
        visited[0][i] = true;
        visited[i][0] = true;
        visited[8][i] = true;
        visited[i][8] = true;
    }
    for (auto &c : s) {
        if (c == '?') continue;
        else if (c == 'D') c = '0';
        else if (c == 'U') c = '1';
        else if (c == 'L') c = '2';
        else if (c == 'R') c = '3';
    }
    cout << dfs() << endl;
}
