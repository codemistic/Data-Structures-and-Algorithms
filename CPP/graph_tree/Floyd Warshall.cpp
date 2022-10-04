// Function of floyd Warshall algorithm

void floydWarshall(vector<vector<int>> &distance) // distance is the adjacency matrix of nodes 0 to n-1
  {
      int n=distance.size(),i,j,k;
      
      for(k=0;k<n;k++)
      {
          for(i=0;i<n;i++)
          {
              for(j=0;j<n;j++)
              {
                  if(distance[i][k]==INT_MAX || distance[k][j]==INT_MAX) continue;
                  else if(distance[i][k]+distance[k][j]<distance[i][j])
                  {
                      distance[i][j] = distance[i][k]+distance[k][j];
                  }
              }
          }
      }
      
    for(i=0;i<n;i++)
    {
        if(distance[i][i]<0) 
        {
            cout<<"Negative cycle present";
            return;
        }
    }
    
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            cout<<distance[i][j]<<" ";
        }
        cout<<endl;
    }
    
      return;
  }
