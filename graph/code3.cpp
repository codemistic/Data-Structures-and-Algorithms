/*
Comparison in adjaceny List or matrix

Adjacency List
1. this takes size upto O(v+E)/O(V+2*E) for directed and undirected graph respectively.
2. Finding if there is a edge between two vertices is O(degree(node)) or O(v) as it can be connected to all other nodes.
3. finding degree of any vertex is O(E) / O(V) because maximum it can be connected with all other vertices
    but in maximum cases it is sparse matrix so it would be really less compared to matrix.
4. Adding an edge: O(1) as we have to do one pushback operation
5. Removing an Edge: O(V)/O(E) because a number can be connected with all other nodes other than itself 
6. Adding a vertex: we just have to pushback a new node to the vector so O(1).
7. Removing a vertex: So here first of all we need all the edges of that vertex to be removed so that would be
    O(E) then we need to remove that vertex from the main vector and it would be O(V) so total would be O(V+E);

Adjacency Matrix
1. This takes upto v^2 size.
2. Finding if there is a edge between two vertices is O(1).
3. Finding degree would be O(V).
4. Adding an edge: O(1) as we have to make mat[i][j] = 1.
5. Removing an Edge: O(1) as we have to make mat[i][j] = 0.
6. Adding a vertex: It will take O(v^2);
7. Removing a vertex: It will take O(v^2);


*/