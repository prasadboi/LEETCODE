# SOLUTION
**PROBLEM : https://leetcode.com/problems/network-delay-time/submissions/**
* maintain a **timer** variable which keeps track of the time at which we arrive at a node
* maintain **entry_time[i]** which keeps track of when a node is entered.
* Keep in mind the fact that there could be a shorter/faster route to a particular node which is why we have the *else* statement in the dfs function.
* Simply run dfs and iff all nodes are traversed then return the max entry time of a node (ie find the time at which the last node was traversed). Otherwise return -1;
​