int lcp(string a, string b){
	int n = a.length();
	int m = b.length();
	int i = 0; int j = 0;
	int count = 0;
	while (i < n && j < m){
		if (a[i] == b[j]){
			count++;
			i++;
			j++;
		}
		else break;
	}

	return count;
}
int minimumRequiredShifts(string a, string b){
	int n = a.length();
	int m = b.length();
	int maxi = 0;
	int answer = 0;
	for (int k = 0; k < m; k++){
		string rotated = b.substr(k) + b.substr(0, k);
		int count = lcp(rotated, a);
		if (count > maxi){
			maxi = count;
			answer = k;
		}
	}

	return answer;
}






