class Solution {
public:
    #define vvll vector<vector<long long int>>
    #define vb vector<bool>
    #define vll vector<long long int>
    #define vi vector<int>
    #define ll long long int
    
    // ll get_height(int src, vb &vis, vvll &graph)
    // {
    //     vis[src] = true;
    //     if(graph[src].size() == 0) return 0;
    //     ll res = 0;
    //     for(auto i : graph[src])
    //     {
    //         if(!vis[i])
    //         {
    //             res = max(res, get_height(i, vis, graph) + 1);
    //         }
    //     }
    //     return res;
    // }
    
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        vvll graph(n);
        vll indegree(n, 0);
        for(auto i : edges){
            graph[i[0]].push_back(i[1]);
            graph[i[1]].push_back(i[0]);
            indegree[i[0]]++;
            indegree[i[1]]++;
        }
        vi ans;
        
        
        
        
//         O(N^2) solution:
        
//         ll minH = INT_MAX;
//         for(int i = 0; i < n; i++){
//             vb vis(n, false);
//             ll h = get_height(i,vis, graph);
//             if(minH > h){
//                 ans.clear();
//                 minH = h;
//             }
//             if(minH == h){
//                 ans.push_back(i);
//             }
//         }
        
//         return ans;
        
        
        
        
        
        
        
        // O(N) solution
        
        // note : the number of said "centroids" for a tree like graph is no more than 2
        
        // implementing topSort via BFS/levelOrderTraversal
        
        queue<ll> q;
        for(int i = 0; i < n; i++){
            if(indegree[i] == 1){
                indegree[i]--;
                q.push(i);
            }
        }
//         that level which is inner most must be the nodes which are closest to all other nodes (on avg)
//         like a level order traversal i'm going level by level deeper into the tree
//         to do that i maintain an indegree vector which i keep updating. indegree[i] == 1 next inner layer
        while(!q.empty()){
            int s = q.size();
            ans.clear();
            for(int i=0; i<s;i++){
                int curr = q.front(); 
                indegree[curr]--;
                q.pop();
                ans.push_back(curr);
                for(auto child : graph[curr]){
                    //For each node, attached to the leaf nodes, 
                    // we decrement the indegree i.e remove the leaf nodes connected to them. 
                    // We keep on doing this until we reach the middle nodes.
                    if(indegree[child]){
                        indegree[child]--;
                        if(indegree[child]==1) q.push(child);  
                    }
                }
            }
        }
        if(n==1) ans.push_back(0); //If there is only 1 node in the graph, the min height is 0, with root being '0'
        return ans;
        
    }
};