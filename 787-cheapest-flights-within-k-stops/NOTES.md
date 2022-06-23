# Dijkstra + modification sol.
* If we choose to proceed via Dijkstra's solution :
* We need to keep in mind that we canNOT discard d[v] with number of stops less than the target as it may help in attaining the final solution.
* Hence the update rule becomes :
* ```
if(stops > k) continue;
for(auto v : graph[u])
{
if(stops < k)
q.insert({d_u + uv_wt, v, stops  +1})
}
```
* whereas earlier it was :
```
for(auto v : graph[u])
if(dist[v] > dist[u] + uv_wt)
{
{
q.erase({dist[v], v});
dist[v] = dist[u] + uv_wt;
q.insert({dist[v], v}) ;
}
}
```