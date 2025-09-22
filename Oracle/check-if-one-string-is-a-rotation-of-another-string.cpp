#include <bits/stdc++.h>
using namespace std;
int isCyclicRotation(string &p, string &q) 
{
    string doubled = p + p;
    return doubled.find(q) != string::npos;
}