# Eulerian Path Algorithm
* Starting from any vertex we keep following the unused edges until we get stcuk at certain vertex where we have no more unvisited outgoing edges
* We then Backtrack to the nearest neighbour nodes in the current path that has unused edges and repeat process until all edges have been used
* The first vertex we got stuck at would end point of our Eulerian path. So if we follow all stuck points backwards we could reconstruct the Eulerian path.
​
# Algo (pseudocode)
```
dfs(node)
{
while(graph[node.size() > 0])
{
// we have some edges that are still unvisited from this node
nextNode = graph[node][0]
// we have decided to traverse the first of these edges
// hence we can a. - mark this as visited, b. remove this from the list of available edges
graph[node].erase(graph[node].begin())
dfs(node);
}
route.push_back(node);
}
​
main()
{
// given a graph with edges from a node sorted in order
// ( for lexicographically least case scenario as req by our problem statement)
// Eulerian path starts out of src node
dfs(src);
return route.reverse()
}
​
```