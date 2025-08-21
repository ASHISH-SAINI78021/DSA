#include <bits/stdc++.h> 
int findSetBit(int n) {   
    if (n <= 1) return -1;
    if ((n&(n - 1)) != 0) return -1; // it is to check the power of 2
    int pos = 1;
    while (n > 1){
        n >>= 1; // right shift by 1.
        pos++;
    }

    return pos;
}

