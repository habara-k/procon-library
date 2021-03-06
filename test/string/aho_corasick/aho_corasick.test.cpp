#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=2212"

#include "../../../lib/string/aho_corasick.cpp"

int main() {
    map<char,int> dy, dx;
    dy['U'] = -1, dy['R'] = 0, dy['D'] = 1, dy['L'] = 0;
    dx['U'] = 0, dx['R'] = 1, dx['D'] = 0, dx['L'] = -1;

    while (true) {
        int n, m; cin >> n >> m;
        if (n == 0) break;
        vector<string> board(n);
        int si, sj;
        for (int i = 0; i < n; ++i) {
            cin >> board[i];
            for (int j = 0; j < m; ++j) {
                if (board[i][j] == 'S') {
                    si = i, sj = j;
                }
            }
        }

        AhoCorasick<26,'A'> aho;
        int P; cin >> P;
        for (int i = 0; i < P; ++i) {
            string p; cin >> p;
            aho.add(p, i);
        }
        aho.build();

        using Node = int;

        queue<tuple<int,int,int,Node>> que;
        que.emplace(si, sj, 0, aho.trie.root);
        map<tuple<int,int,Node>,bool> used;
        used[make_tuple(si, sj, aho.trie.root)] = true;

        int ans = -1;

        while (!que.empty()) {
            int i, j, d; Node now;
            tie(i, j, d, now) = que.front(); que.pop();
            if (board[i][j] == 'G') {
                ans = d;
                break;
            }
            for (char dir : { 'U', 'R', 'D', 'L' }) {
                Node tmp = now;
                int y = i + dy[dir], x = j + dx[dir];
                if (y < 0 or n <= y or x < 0 or m <= x or
                        board[y][x] == '#') continue;

                while (aho[tmp].next[dir - 'A'] == -1) {
                    tmp = aho[tmp].next[aho.FAIL];
                }
                tmp = aho[tmp].next[dir - 'A'];
                if (aho[tmp].accept.size()) {
                    continue;
                }
                if (!used[make_tuple(y, x, tmp)]) {
                    used[make_tuple(y, x, tmp)] = true;
                    que.emplace(y, x, d + 1, tmp);
                }
            }
        }

        cout << ans << endl;
    }
    return 0;
}
