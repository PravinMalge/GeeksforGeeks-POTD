class Solution {
public:
    int minSoldiers(vector<int>& arr, int k) {
        int n = arr.size();
        int need = (n + 1) / 2; // ceil(n / 2)

        int luckyCount = 0;
        vector<int> cost;

        for (int soldiers : arr) {
            if (soldiers % k == 0) {
                luckyCount++;
            } else {
                cost.push_back(k - (soldiers % k));
            }
        }

        if (luckyCount >= need) return 0;

        sort(cost.begin(), cost.end());

        int soldiersToAdd = 0;
        int makeLucky = need - luckyCount;

        for (int i = 0; i < makeLucky; i++) {
            soldiersToAdd += cost[i];
        }

        return soldiersToAdd;
    }
};