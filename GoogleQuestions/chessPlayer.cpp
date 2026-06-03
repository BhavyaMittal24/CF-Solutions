There is a chess contest between N players. Each chess player has a distinct rank (positive integer number from 1 to N). 
We assume that in a chess game between two players, the higher ranked player always wins. 
The rank remains constant during the contest.
 Best player would have rank 1 and worst player would have rank N. Rank 1 > Rank N

Unfortunately, we don't know the player ranks. But we know the outcome of M games in the following format:

Player #1 won against #2
Player #2 won against #4
...

Given the results of M games above, please find all players whose ranks can be precisely determined and report their ranks.

Example:

N=5 M=5
Player #4 won against #3 (Player #4 is the winner in the match b/w Player #4 & #3)
Player #4 won against #2
Player #3 won against #2
Player #1 won against #2
Player #2 won against #5
Answer: The rank of 2 players can be determined precisely:

player #2(rank is 4): they lost to players #1, #3, #4 and won against player #5;

player #5(rank is 5): they lost to player #2 and we know that player #2 has already lost to #1, #3, and #4.



WinAgainst[i] : {5}
  
LoseAgainst[i] : {1,3,4}

winAgains.size() + loseagainst.size() == n-1 :  i can know the rank for i : : 3+1 = 4

// go over and if win against size is 1 : then assing the rank as 4+1 = 5


// from the m edges right ? 

// 1 2 3 4 5 6

// winagaint.size() == 1 || loseagainst.size() = 1 : 


n = 5

 ranks : 1 3 4 5 2

 players 1 2 3 4 5

 5

 1 3
 3 4
 2 4
 1 5
 2 3

 3 -. lose against {1,2}

 5 - lose against {1}

 4 loses againsr {2}



 // i need to find the right rank order

ranks in sorted order

1 5 2 3 4

1 5 2 3 4
1 2 5 3 4
2 1 5 3 4
2 1 3 5 4

// i cn find all possible topoloigcla sorts and base don that 

1 3 4 are the ones : where it is same

// toposort difference 

// indegree[i] == 0 , push all those nides

// i -> x neighbours : 

// rough ordering


// fixed for sure : some edges

u1-> v1
u2 -> v2
.. find an ordering where u1 comes before v1 lways 



Follow Up Question #1: What ifs
What if...

the results of the M rounds can be contradictory? How to detect the contradiction?
Follow Up Question #2: Linear Solution
You can find the algorithm in the answer tab. Here are talking points that might be helpful:

What is topological sort? If we can generate all topological sort outputs, how does it help to our solution?
Why is this not a feasible solution? How many possible outputs are there?
What might go wrong if we just sample some of the outputs (e.g. only sample 2 different topological sort outputs), can you think of some examples?
In Kahn's topological sorting algorithm, we iteratively remove nodes without any incoming edges one-by-one. When we are going to remove a node:
If there are other nodes that have no incoming edges, what does it mean?
Conversely, if the node is the only node that has no incoming edges, what does it mean? How is this related to the reachability set?
For a precised-ranked player, what condition will hold when we are going remove it from the graph? Is the condition sufficient?


Follow Up Question #1: What ifs
What if...

the results of the M rounds can be contradictory? How to detect the contradiction?
Follow Up Question #2: Linear Solution
You can find the algorithm in the answer tab. Here are talking points that might be helpful:

What is topological sort? If we can generate all topological sort outputs, how does it help to our solution?
Why is this not a feasible solution? How many possible outputs are there?
What might go wrong if we just sample some of the outputs (e.g. only sample 2 different topological sort outputs), can you think of some examples?
In Kahn's topological sorting algorithm, we iteratively remove nodes without any incoming edges one-by-one. When we are going to remove a node:
If there are other nodes that have no incoming edges, what does it mean?
Conversely, if the node is the only node that has no incoming edges, what does it mean? How is this related to the reachability set?
For a precised-ranked player, what condition will hold when we are going remove it from the graph? Is the condition sufficient?
Look out for these aspects in the candidate’s responses

First, note that the problem can be converted into a directed graph, with the players as the nodes and the games as the edges. In particular, note that this graph is a directed acyclic graph, or DAG for short.

For a certain player X, X's rank can be determined if and only if the following property is true: for every other player Y, either player X is known to rank higher than player Y, or player Y is known to rank higher than player X (otherwise one can build two rankings compatible with the existing data where X has different ranks).

To that end, we can find which vertices in the graph the vertex corresponding to X is reachable from and which ones are reachable from X. For instance, we can do that by running a depth-first search (O(N+M) operations times the cost of merging such vertex sets, typically proportional to N). We will run it twice, first using the original edges. Since it's a DAG, we can compute rank[x] - the number of vertices reachable from the vertex x. This can be done using dynamic programming in the DFS visit postorder, corresponding to the topological ordering of the DAG (see the DFS solution below). Then using reverse edges, we can compute reverse_rank[x] - number of vertices from which we can reach vertex x. We can determine the rank of player X if and only if rank[x] + reverse_rank[x] == N - 1, i.e. vertex X is comparable to all other vertices.

Alternate approach: Floyd-Warshall in O(N^3) overall to build the transitive closure of the graph, then check if a given vertex is connected to every other in either direction. (In other words, we are basically interested in the sum of in- and outdegrees of each vertex in that transitive closure.)

Python using DFS (with reachability sets) and adjacency lists
def players_with_precise_rank(n: int, games: Iterable[Tuple[int, int]]):
  graph = collections.defaultdict(list)
  reverse_graph = collections.defaultdict(list)
  for winner, loser in games:
    graph[winner].append(loser)
    reverse_graph[loser].append(winner)

  def compute_ranks(graph):
    reachable = [None] * n

    def dfs(vertex):
      # Note: Assuming high enough recursion limit.
      if reachable[vertex] is not None:
        return
      reachable[vertex] = set()
      for neighbor in graph[vertex]:
        dfs(neighbor)
        reachable[vertex].add(neighbor)
        reachable[vertex] |= reachable[neighbor]

    for vertex in range(n):
      dfs(vertex)
    return [len(dominated) for dominated in reachable]

  ranks = compute_ranks(graph)
  reverse_ranks = compute_ranks(reverse_graph)

  ans = {}
  for i in range(n):
    if ranks[i] + reverse_ranks[i] == n - 1:
      ans[i] = reversed_ranks[i] + 1
  return ans
C++ using DFS (with reachability sets) and adjacency lists
void dfs(const vector<vector<int>>& graph, int src,
         map<int,set<int>>& reachable, map<int,bool>& vis) {
    if(vis[src]) {
      return;
    }
    vis[src] = true;
    for(auto child: graph[src]) {
        dfs(graph,child,reachable,vis);
        reachable[src].insert(child);

        // if child has some reachable node, than appending it to src
        if(reachable[child].size()!=0){
            reachable[src].insert(reachable[child].begin(),reachable[child].end());
        }
    }
    return;
}
map<int,int> computeRank(int N, const vector<vector<int>>& g) {
    map<int,int> rank;
    map<int,bool> vis;
    map<int,set<int>> reachable;

    for(int i = 0; i < N ; i++) {
        if(!vis[i]) {
          dfs(g, i, reachable, vis);
        }
    }

    for(auto it : reachable){
        rank[it.first] = it.second.size();
    }
    return rank;
}
map<int,int> findRank(int N, const vector<pair<int,int>>& games) {
    vector<vector<int>> g(N);
    vector<vector<int>> rev_g(N);
    map<int,int> rank;
    map<int,int> rev_rank;

    for(auto it: games) {
        g[it.first].push_back(it.second);
        rev_g[it.second].push_back(it.first);
    }

    rank = computeRank(N, g);