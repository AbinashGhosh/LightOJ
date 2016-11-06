/*
Algorithm: BFS/DFS
There is an unlimited supply of commando troops for the mission, so we can assign one commando
for destroying one building. So, the i'th commando have to:
1. Start from the building s and go to the i'th building
2. From the i'th building, go to building d
So, we have to calculate (shortest path from s to i) + (shortest path from d to i)
for all commandos, and find the maximum value among these.
*/
