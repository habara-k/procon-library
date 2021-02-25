---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: lib/graph/primal_dual.cpp
    title: lib/graph/primal_dual.cpp
  - icon: ':heavy_check_mark:'
    path: lib/template.cpp
    title: lib/template.cpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/6/GRL_6_B
    links:
    - https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/6/GRL_6_B
  bundledCode: "#line 1 \"test/graph/primal_dual/primal_dual.test.cpp\"\n#define PROBLEM\
    \ \"https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/6/GRL_6_B\"\n\n#line\
    \ 1 \"lib/template.cpp\"\n\n\n#include <bits/stdc++.h>\nusing namespace std;\n\
    \n#define REP(i,n) for (int i=0; i<(n); ++i)\n#define ALL(x) begin(x),end(x)\n\
    #define DUMP(x) cerr<<#x<<\" = \"<<(x)<<endl\n\nstruct fast_ios {\n    fast_ios()\
    \ {\n        std::cin.tie(nullptr);\n        ios::sync_with_stdio(false);\n  \
    \      cout << fixed << setprecision(20);\n    };\n} fast_ios_;\n\nusing ll =\
    \ long long;\n\ntemplate<class T>\nbool chmin(T &a, T b) {\n    if (a > b) { a\
    \ = b; return true; }\n    return false;\n}\ntemplate<class T>\nbool chmax(T &a,\
    \ T b) {\n    if (a < b) { a = b; return true; }\n    return false;\n}\n\ntemplate<class\
    \ T>\nostream &operator<<(ostream &os, const vector<T> &v);\ntemplate<class T,\
    \ class U>\nostream &operator<<(ostream &os, const pair<T, U> &p);\ntemplate<class\
    \ T, class U>\nostream &operator<<(ostream &os, const map<T, U> &mp);\n\ntemplate<class\
    \ T>\nostream &operator<<(ostream &os, const vector<T> &v) {\n    os << '[';\n\
    \    REP(i, v.size()) {\n        if (i) os << ',';\n        os << v[i];\n    }\n\
    \    return os << ']';\n}\n\ntemplate<class T, class U>\nostream &operator<<(ostream\
    \ &os, const pair<T, U> &p) {\n    return os << '(' << p.first << ' ' << p.second\
    \ << ')';\n}\n\ntemplate<class T, class U>\nostream &operator<<(ostream &os, const\
    \ map<T, U> &mp) {\n    os << '{';\n    for (const auto &p : mp) {\n        os\
    \ << p << endl;\n    }\n    return os << '}';\n}\n\nconst int INF = numeric_limits<int>::max();\n\
    const ll LINF = numeric_limits<ll>::max();\n\ntemplate<class T>\nstruct edge {\n\
    \    int from, to; T cost;\n    edge(int to, T cost) :\n        from(-1), to(to),\
    \ cost(cost) {}\n    edge(int from, int to, T cost) :\n        from(from), to(to),\
    \ cost(cost) {}\n};\n\n\n#line 2 \"lib/graph/primal_dual.cpp\"\n\ntemplate<typename\
    \ flow_t, typename cost_t>\nstruct PrimalDual {\n    // O(FElogV)\n    struct\
    \ edge {\n        int to, rev;\n        flow_t cap;\n        cost_t cost;\n  \
    \      edge(int to, flow_t cap, cost_t cost, int rev) :\n                to(to),\
    \ cap(cap), cost(cost), rev(rev) {}\n    };\n\n    vector<vector<edge>> g;\n \
    \   const int sz;\n    const cost_t INF;\n\n    PrimalDual(int V, cost_t INF)\
    \ : g(V), sz(V), INF(INF) {}\n\n    void add_edge(int s, int t, flow_t cap, cost_t\
    \ cost) {\n        g[s].emplace_back(t, cap,  cost, (int)g[t].size());\n     \
    \   g[t].emplace_back(s,   0, -cost, (int)g[s].size() - 1);\n    }\n\n    void\
    \ dijkstra(\n            vector<cost_t>& dist,\n            vector<int>& prevv,\n\
    \            vector<int>& preve,\n            const vector<cost_t>& potential,\
    \ int s)\n    {\n        dist.assign(sz, INF);\n        prevv.assign(sz, -1);\n\
    \        preve.assign(sz, -1);\n        using Pi = pair<cost_t, int>;\n      \
    \  priority_queue<Pi, vector<Pi>, greater<Pi>> que;\n        que.emplace(0, s);\n\
    \        dist[s] = 0;\n        while (!que.empty()) {\n            cost_t cost;\
    \ int v;\n            std::tie(cost, v) = que.top();\n            que.pop();\n\
    \            if (dist[v] < cost) continue;\n            for (int i = 0; i < g[v].size();\
    \ ++i) {\n                edge &e = g[v][i];\n\n                if (e.cost ==\
    \ INF or e.cost == -INF) continue;\n\n                cost_t nextCost =\n    \
    \                    dist[v] + e.cost + potential[v] - potential[e.to];\n    \
    \            if (e.cap > 0 and dist[e.to] > nextCost) {\n                    dist[e.to]\
    \ = nextCost;\n                    prevv[e.to] = v, preve[e.to] = i;\n       \
    \             que.emplace(dist[e.to], e.to);\n                }\n            }\n\
    \        }\n    }\n\n    cost_t min_cost_flow(int s, int t, flow_t f) {\n    \
    \    cost_t ret = 0;\n        vector<cost_t> potential(sz, 0);\n\n        while\
    \ (f > 0)\n        {\n            vector<cost_t> dist;\n            vector<int>\
    \ prevv, preve;\n            dijkstra(dist, prevv, preve, potential, s);\n\n \
    \           if (dist[t] == INF) return -1;\n\n            for (int v = 0; v <\
    \ sz; ++v) potential[v] += dist[v];\n\n            flow_t diff = f;\n        \
    \    for (int v = t; v != s; v = prevv[v]) {\n                diff = min(diff,\
    \ g[prevv[v]][preve[v]].cap);\n            }\n            f -= diff;\n       \
    \     ret += diff * potential[t];\n\n            for (int v = t; v != s; v = prevv[v])\
    \ {\n                edge &e = g[prevv[v]][preve[v]], &re = g[v][e.rev];\n   \
    \             e.cap -= diff;\n                re.cap += diff;\n            }\n\
    \        }\n\n        return ret;\n    }\n};\n#line 4 \"test/graph/primal_dual/primal_dual.test.cpp\"\
    \n\nint main() {\n    int n, m, f; cin >> n >> m >> f;\n    PrimalDual<int,int>\
    \ graph(n, numeric_limits<int>::max());\n    for (int i = 0; i < m; ++i) {\n \
    \       int u, v, c, d; cin >> u >> v >> c >> d;\n        graph.add_edge(u, v,\
    \ c, d);\n    }\n    int ans = graph.min_cost_flow(0, n-1, f);\n    cout << ans\
    \ << endl;\n}\n"
  code: "#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/6/GRL_6_B\"\
    \n\n#include \"../../../lib/graph/primal_dual.cpp\"\n\nint main() {\n    int n,\
    \ m, f; cin >> n >> m >> f;\n    PrimalDual<int,int> graph(n, numeric_limits<int>::max());\n\
    \    for (int i = 0; i < m; ++i) {\n        int u, v, c, d; cin >> u >> v >> c\
    \ >> d;\n        graph.add_edge(u, v, c, d);\n    }\n    int ans = graph.min_cost_flow(0,\
    \ n-1, f);\n    cout << ans << endl;\n}\n"
  dependsOn:
  - lib/graph/primal_dual.cpp
  - lib/template.cpp
  isVerificationFile: true
  path: test/graph/primal_dual/primal_dual.test.cpp
  requiredBy: []
  timestamp: '2021-02-25 17:59:51+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/graph/primal_dual/primal_dual.test.cpp
layout: document
redirect_from:
- /verify/test/graph/primal_dual/primal_dual.test.cpp
- /verify/test/graph/primal_dual/primal_dual.test.cpp.html
title: test/graph/primal_dual/primal_dual.test.cpp
---
