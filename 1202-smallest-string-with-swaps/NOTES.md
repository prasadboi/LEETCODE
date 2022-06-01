# IDEA
### BASIS
* Say there is string "jhgsby"
* say you're given [0, 3], [2, 3] i.e. pos 0 can swap with pos 3, pos 2 can swap with pos 3
* Then there exists only one final lexicographically smallest ordering ("g_js__") of these positions
* Hence we can think of these as a bunch of interdependent / connected components
* SO lets put them in a DSU. bwahahahaha ( little scam only)

### ALGO
* So our solution could be something like this :
* Find all the sets of "connected" characters
* Sort each set of connected characters, and place this sorted set instead of the original pos. of the characters that belong to this set
* Do this for every set
* This should yield lexicographically smallest string (under the given restraints) as a  result.
