
#include <bits/stdc++.h>
using namespace std;



class Solution {
  public:
    void recursion(vector<int>& arr, int n, int i, int sum, vector<int>& ans) {
    // Base case: If we've processed all elements, push the sum to ans
    if (i == n) {
        ans.push_back(sum);
        return;
    }
    
    // Include the current element in the subset (add arr[i] to the sum)
    recursion(arr, n, i + 1, sum + arr[i], ans);
    
    // Exclude the current element from the subset (don't add arr[i] to the sum)
    recursion(arr, n, i + 1, sum, ans);
}

vector<int> subsetSums(vector<int> arr, int n) {
    vector<int> ans;
    
    // Call the recursive function starting from index 0 and sum 0
    recursion(arr, n, 0, 0, ans);
    
    return ans;
}

};



int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;
        vector<int> arr(N);
        for (int i = 0; i < N; i++) {
            cin >> arr[i];
        }
        Solution ob;
        vector<int> ans = ob.subsetSums(arr, N);
        sort(ans.begin(), ans.end());
        for (auto sum : ans) {
            cout << sum << " ";
        }
        cout << endl;
    
cout << "~" << "\n";
}
    return 0;
}
