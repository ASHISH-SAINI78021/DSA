#include <bits/stdc++.h> 
using namespace std;

vector<vector<int>> multiplyMatrices(vector<vector<int>> &mat1, vector<vector<int>> &mat2)
{
    int a = mat1.size();        // rows in mat1
    int b = mat1[0].size();     // cols in mat1
    int c = mat2.size();        // rows in mat2
    int d = mat2[0].size();     // cols in mat2

    // If invalid multiplication
    if (b != c) return {{0}};

    vector<vector<int>> ans(a, vector<int>(d, 0));

    for (int i = 0; i < a; i++) {
        for (int k = 0; k < d; k++) {
            for (int j = 0; j < b; j++) {
                ans[i][k] += mat1[i][j] * mat2[j][k];
            }
        }
    }

    return ans;
}
