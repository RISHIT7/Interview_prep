#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<pair<int,int>>> adj(n+1,vector<pair<int,int>>{} );
        for(auto x:times){
            adj[x[0]].push_back({x[1],x[2]});
        }

        vector<int> dist(n+1,1e9);
        dist[k]=0;
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
        pq.push({0,k});

        while(!pq.empty()){
            int node=pq.top().second;
            int dis=pq.top().first;
            pq.pop();

            for(auto x:adj[node]){
                int adjNode=x.first;
                int adjDist=x.second;
                if(dis+adjDist < dist[adjNode]){
                    dist[adjNode]=dis+adjDist;
                    pq.push({adjDist+dis,adjNode});
                }
            }
        }
        int ans=-1;
        for(int i=1;i<=n;i++){
            ans=max(ans,dist[i]);
        }
        if(ans==1e9){return -1;}
        return ans;
    }
};