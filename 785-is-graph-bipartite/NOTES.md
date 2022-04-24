# SOLUTION
* The graph is bipartite
* This means that if **node** belongs to set A then all the nodes connected to node A i.e. all the nodes in **graph[node]** belong to set B.
* We can keep track of whether a node has been - visited (non zsero), not visited (zero), A(1), B(2) - during our DFS traversal.