# IDEA
* Each node stores the xor value of its subtree
* Our job then remains to iterate through grps of 2 nodes (upon splitting we'll have 2 roots for the new components formed)every time for which we have 2 cases :-
* IF(Node A was a subroot of Node B). Therefore
* `in[nodeA] < in[nodeB] and out[nodeA] > out[nodeB]`
* Therefore : `xor for B = dp[nodeB], xor for the new A = dp[nodeA] xor dp[nodeB] // as node b subtree is now removed from the subtree of node A`
* `xor for the remaining = all ^ dp[nodeA]` as dp[nodeA] accounts for both dp[nodeB] and dp[nodeA]
* and VICE VERSA
* -------------------------------
* ELSE(Node B and Node A are not subroots of either one of them)
* `xor for B = dp[nodeB], xor for A = dp[nodeA]`
* ` xor for the remaining = all xor dp[nodeA] xor dp[nodeB]`
* `SCORE = max(xor for B, xor for A, rem xor) - min(xor for B, xor for A, rem xor)`
* `RES = min(RES, SCORE)`