class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights,
                          int src, int dst, int k) {

        priority_queue<
            tuple<int, int, int>,
            vector<tuple<int, int, int>>,
            greater<tuple<int, int, int>>
        > pq;

        vector<vector<pair<int, int>>> adj(n);

        for (auto flight : flights) {
            int from = flight[0];
            int to = flight[1];
            int price = flight[2];

            adj[from].push_back({to, price});
        }

        vector<vector<int>> dist(
            n,
            vector<int>(k + 2, 1e9)
        );

        dist[src][0] = 0;

        pq.push({0, src, 0});

        while (!pq.empty()) {

            auto [cost, node, flightsUsed] = pq.top();
            pq.pop();

            if (node == dst)
                return cost;

            if (flightsUsed == k + 1)
                continue;

            for (auto [nextNode, price] : adj[node]) {

                int newCost = cost + price;
                int newFlights = flightsUsed + 1;

                if (newCost < dist[nextNode][newFlights]) {

                    dist[nextNode][newFlights] = newCost;

                    pq.push({
                        newCost,
                        nextNode,
                        newFlights
                    });
                }
            }
        }

        return -1;
    }
};