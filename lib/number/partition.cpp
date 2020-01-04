#include "../template.cpp"

// Partition function
// Partition(k, n) := the number of cases
//            to split n balls(not distinguished)
//            into k boxes(not distinguished)
template<typename Ring>
Ring Partition(int k, int n) {
    vector<vector<Ring>> part(k+1, vector<Ring>(n+1));
    part[0][0] = 1;
    for (int i = 1; i <= k; ++i) {
        for (int j = 0; j <= n; ++j) {
            if (j-i >= 0) {
                part[i][j] = part[i-1][j] + part[i][j-i];
            } else {
                part[i][j] = part[i-1][j];
            }
        }
    }
    return part[k][n];
}

