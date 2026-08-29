class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        int n = numCourses;
        vector<vector<int>> adj(n);
        vector<int> ind(n, 0);

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

        int completed = 0;

        while(!q.empty()){

            int c = q.front();
            q.pop();
            completed++;

            for(auto it : adj[c]){
                ind[it]--;
                if(ind[it] == 0){
                    q.push(it);
                }
            }
        }

        return n == completed;
    }
};