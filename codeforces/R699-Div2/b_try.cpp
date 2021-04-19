int solve(){
	int last_boulder = -1;
	for(auto it = pos.begin();it != pos.end();it++){
		int f = it->first;
		int l = it->second;

		cout << "f: " << f << ", s: " << l << endl;
		if (l == n+1 and k > 0) return -1;

		set<int> curr_pos;
		int total_need = 0;
		for(int i = l;i >= f;i--){
			total_need = h[l+1] - h[i];
		}
		if (total_need <= k) {
			k -= total_need;
			continue;
		}
	
		cout << endl;
	}
	return last_boulder;
}
