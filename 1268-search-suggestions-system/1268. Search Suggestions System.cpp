class Solution {
public:
    vector<vector<string>> suggestedProducts(vector<string>& products,
                                             string searchWord) {
        sort(products.begin(), products.end());

        vector<vector<string>> ans;
        string prefix;

        for (char c : searchWord) {
            prefix += c;

            auto it = lower_bound(products.begin(), products.end(), prefix);

            vector<string> curr;

            for (int i = 0; i < 3 && it + i != products.end(); i++) {
                if ((it + i)->compare(0, prefix.size(), prefix) == 0)
                    curr.push_back(*(it + i));
                else
                    break;
            }

            ans.push_back(curr);
        }

        return ans;
    }
};
