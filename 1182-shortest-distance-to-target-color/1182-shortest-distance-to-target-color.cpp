class Solution {
public:
    vector<int> shortestDistanceColor(vector<int>& colors, vector<vector<int>>& queries) {
    int n = colors.size();
	vector<vector<int>> dist(n, vector<int> (3, INT_MAX));

	//Two passes: [0, n) ++ and [n-1, -1) --
	for(auto [first, last, step] : {tuple(0, n, 1), tuple(n-1, -1, -1)} ){
		vector<int> prev = {INT_MAX, INT_MAX, INT_MAX};
		for(int i=first; i!=last; i+=step){
			for(int c=0; c<3; ++c)
				if(colors[i] == c+1)//stored colors are 1-index
					dist[i][c] = 0;
				else
					dist[i][c] = min(dist[i][c], prev[c]==INT_MAX ? INT_MAX : prev[c]+1);
			prev = dist[i];
		}
	}

	vector<int> ans;
	for(auto& q : queries){
		int d = dist[q[0]][q[1]-1];
		if(d == INT_MAX) d = -1;
		ans.push_back(d);
	}
	return ans;
    }
};