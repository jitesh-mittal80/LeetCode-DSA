class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        int n = numCourses;
        vector<vector<int>> adj(n);
        vector<int> ind(n, 0);
        vector<int> order;

        for(auto &p : prerequisites){
            int c = p[0];
            int pre = p[1];

            adj[pre].push_back(c);
            ind[c]++;
        }

        queue<int> q;
        for(int i = 0; i<n; i++){
            if(ind[i] == 0){
                q.push(i);
            }
        }

        while(!q.empty()){

            int c = q.front();
            q.pop();
            order.push_back(c);

            for(auto it : adj[c]){
                ind[it]--;
                if(ind[it] == 0){
                    q.push(it);
                }
            }
        }

        if(order.size() != n){
            return {};
        }
        return order;
    }
};