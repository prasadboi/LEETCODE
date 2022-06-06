## APPROACH
* Extracting dependency rules from the input. For example "A must be before C", "X must be before D", or "E must be before B".
* Putting the dependency rules into a graph with letters as nodes and dependencies as edges (an adjacency list is best).
* Topologically sorting the graph nodes.