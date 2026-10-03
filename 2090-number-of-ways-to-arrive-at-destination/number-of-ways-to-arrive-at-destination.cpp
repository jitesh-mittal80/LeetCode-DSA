class Solution {
public:
    int countPaths(int n, vector<vector<int>>& roads) {

        vector<vector<pair<int, int>>> adj(n);

        for(auto road : roads){
            int from = road[0];
            int to = road[1];
            int time = road[2];

            adj[from].push_back({to, time});
            adj[to].push_back({from, time});
        }

        const int MOD = 1e9 + 7;

        priority_queue<
            pair<long long, int>,
            vector<pair<long long, int>>,
            greater<pair<long long, int>>
        > pq;

        vector<long long> dist(n, LLONG_MAX);
        vector<int> ways(n, 0);

        dist[0] = 0;
        ways[0] = 1;

        pq.push({0, 0});

        while(!pq.empty()){

            long long t = pq.top().first;
            int node = pq.top().second;
            pq.pop();

            if(t > dist[node])
                continue;

            for(auto it : adj[node]){

                int nextn = it.first;      
                int eweight = it.second; 
                long long newTime = t + eweight;

                if(newTime < dist[nextn]){

                    dist[nextn] = newTime;

                    ways[nextn] = ways[node];

                    pq.push({newTime, nextn});
                }

                else if(newTime == dist[nextn]){

                    ways[nextn] =
                        (ways[nextn] + ways[node]) % MOD;
                }
            }
        }

        return ways[n - 1];
    }
};