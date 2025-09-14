#include <bits/stdc++.h> 
bool waterJug(int x, int y, int z)
{
	if (x + y < z) return false;
	// applying bfs
	using T = pair<int, int>;
	queue<T> q;
	set<T> st;
	q.push({0, 0});
	st.insert({0, 0});

	while (!q.empty()){
		auto front = q.front();q.pop();
		int currA = front.first;
		int currB = front.second;

		if (currA == z || currB == z || currA + currB == z) return true;

		vector<T> nextStates;
		// Fills Jug A
		nextStates.push_back({x, currB});
		// Fills Jug B
		nextStates.push_back({currA, y});
		// Empty Jug A => 0
		nextStates.push_back({0, currB});
		// Empty Jug B => 0
		nextStates.push_back({currA, 0});
		
		// Pouring A -> B
		int pourAB = min(currA, y - currB);
		nextStates.push_back({currA - pourAB, currB + pourAB});

		// Pouring B -> A
		int pourBA = min(x - currA, currB)
		nextStates.push_back({currA + pourBA, currB - pourBA});

		for (auto it : nextStates){
			if (st.find(it) == st.end()){
				st.insert(it);
				q.push(it);
			}
		}
	}

	return false;
} 