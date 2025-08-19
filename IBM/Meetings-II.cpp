#include <bits/stdc++.h> 
int minRooms(vector<vector<int>> intervals)
{
    int n = intervals.size();
    vector<int> start;
    vector<int> end;
    for (int i = 0; i < n; i++){
        start.push_back(intervals[i][0]);
        end.push_back(intervals[i][1]);
    }

    sort(start.begin(), start.end());
    sort(end.begin(), end.end());
    int i = 0; int j = 0; int rooms = 0;
    int maxi = 0;
    while (i < n){
        if (start[i] < end[j]){
            rooms++;
            i++;
        }
        else {
            rooms--;
            j++;
        }
        maxi = max(maxi, rooms);
    }

    return rooms;
}