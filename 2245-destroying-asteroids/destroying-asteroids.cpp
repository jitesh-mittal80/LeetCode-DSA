class Solution {
public:
    bool asteroidsDestroyed(int mass, vector<int>& asteroids) {
        long long currMass = mass;

        sort(asteroids.begin(), asteroids.end());

        for (int asteroid : asteroids) {
            if (asteroid > currMass)
                return false;

            currMass += asteroid;
        }

        return true;
    }
};