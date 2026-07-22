class Solution {
  public:
    int minDeletions(vector<int>& arr) {
        // code here
        vector<int> lis;

        for (int num : arr) {

            if (lis.empty() || num > lis.back()) {
                lis.push_back(num);
            } else {

                auto it = lower_bound(lis.begin(), lis.end(), num);

                *it = num;
            }
        }

        return arr.size() - lis.size();
    }
};