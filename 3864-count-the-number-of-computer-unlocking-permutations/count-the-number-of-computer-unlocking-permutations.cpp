class Solution {
public:
    long long mod = 1000000007;

    long long countRecursive(vector<int>& arr, int a) {
        if (a == arr.size())
            return 1;

        if (arr[a] <= arr[0])
            return 0;

        return (a * countRecursive(arr, a + 1)) % mod;
    }

    int countPermutations(vector<int>& complexity) {
        return (int) countRecursive(complexity, 1);
    }
};