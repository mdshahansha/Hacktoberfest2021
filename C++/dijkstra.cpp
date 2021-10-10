#include <iostream>
using namespace std;
#include<bits/stdc++.h>

int findVertex(int *weight,bool* visited,int n)
{
    int minVertex=-1;
    for(int i=0;i<n;i++)
    {
        if(!visited[i] && (minVertex==-1 || weight[i]<weight[minVertex]))
        {
            minVertex=i;
        }
    }
    return minVertex;
}

void dijkstra(int **edges,int n)
{
    int *distance=new int[n];
    bool *visited=new bool[n];
    
    for(int i=0;i<n;i++)
    {
        visited[i]=false;
        distance[i]=INT_MAX;
    }
    
    distance[0]=0;
    
    for(int i=0;i<n;i++)
    {
        int minVertex=findVertex(distance,visited,n);
    visited[minVertex]=true;
    for(int j=0;j<n;j++)
    {
        if(edges[minVertex][j]!=0 && !visited[j])
        {
          int dist=distance[minVertex]+edges[minVertex][j];
            if(dist <distance[j])
            {
            	distance[j]=dist;    
            }
        }
     }
    }
    
    for(int i=0;i<n;i++)
    {
        cout<<i<<" "<<distance[i]<<endl;
	}
}
int main()
{
  int V, E, tempX, tempY;
  cin >> V >> E;

  /*

  	   Write Your Code Here
	   Complete the Rest of the Program
	   You have to Print the output yourself
	 
  */
  
int **edges=new int*[V];
    for(int i=0;i<V;i++)
    {
        edges[i]=new int[V];
        for(int j=0;j<V;j++)
        {
            edges[i][j]=0;
        }
    }
    
    for(int i=0;i<E;i++)
    {
        int f,s,weight;
        cin>>f>>s>>weight;
        edges[f][s]=weight;
        edges[s][f]=weight;
    }
    
    cout<<endl;
	dijkstra(edges,V);
    
    
    for(int i=0;i<V;i++)
    {
        delete [] edges[i];
    }
    
    delete  []edges;
    
  return 0;
}
