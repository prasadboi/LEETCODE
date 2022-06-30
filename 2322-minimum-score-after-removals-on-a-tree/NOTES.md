# IDEA
* Each node stores the xor value of its subtree
* Our job then remains to iterate through the edges (this information is stored via a structure "**last[]**") and find the solution that satisfies the conditions
* *NOTE :* the negation of a XOR is also XOR