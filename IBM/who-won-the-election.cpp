#include <bits/stdc++.h>
using namespace std;

string electionResult(string voters) {
    int n = voters.size();
    int countA = 0, countB = 0;

    // Precompute nearest A to the right (that can move left)
    vector<int> nearestA(n, -1);
    int lastA = -1;
    for (int i = n - 1; i >= 0; i--) {
        if (voters[i] == 'A') lastA = i;
        nearestA[i] = lastA;
    }

    // Precompute nearest B to the left (that can move right)
    vector<int> nearestB(n, -1);
    int lastB = -1;
    for (int i = 0; i < n; i++) {
        if (voters[i] == 'B') lastB = i;
        nearestB[i] = lastB;
    }

    // Decide ownership
    for (int i = 0; i < n; i++) {
        if (voters[i] == 'A') countA++;
        else if (voters[i] == 'B') countB++;
        else {
            int leftB = nearestB[i];
            int rightA = nearestA[i];

            int distB = (leftB == -1 ? 1e9 : i - leftB);
            int distA = (rightA == -1 ? 1e9 : rightA - i);

            if (distA < distB) countA++;
            else if (distB < distA) countB++;
            // if equal ? neutral, skip
        }
    }

    if (countA > countB) return "A";
    else if (countB > countA) return "B";
    else return "Coalition";
}
