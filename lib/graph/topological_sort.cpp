#include "../template.cpp"

vector<int> topological_sort(const vector<vector<int>>& G)
{
    int n = G.size();
    vector<int> num(n), ord;
    for (int i = 0; i < n; ++i) {
        for (int u : G[i]) ++num[u];
    }
    stack<int> st;
    for(int i = 0; i < n; ++i) {
        if (num[i] == 0) st.push(i);
    }
    while (!st.empty()) {
        int i = st.top(); st.pop();
        ord.push_back(i);
        for (int u : G[i]) {
            --num[u];
            if (num[u] == 0) st.push(u);
        }
    }
    return ord;
}
