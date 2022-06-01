**IDEA**
* Sort the times at which friends are made in ascending order
* simply keep on adding friendships into a DSU and keep track of the number of connected components
* the instant num_conn_components = 1, return the timestap of that friendship creation
​
**Validity**
Since the timestamps are sorted so result must eb the earliest. moreover DSU keeps track of the number of unique conn. components (starting from n and going down to 1)