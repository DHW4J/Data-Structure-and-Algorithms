vector<int> bfsOfGraph(int V, vector<int> adj[]) {
        vector<int> result;
        vector<bool> visited(V+1,false);
        queue<int> q;
        visited[0]=true;
        q.push(0);
        while(q.empty()==false){
            int u = q.front();
            q.pop();
            result.push_back(u);
            for(int k: adj[u]){
                if(visited[k]==false){
                    visited[k]=true;
                    q.push(k);
                }
            }
            
        }
        return result;
    }
