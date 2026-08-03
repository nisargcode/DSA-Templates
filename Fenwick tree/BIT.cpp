#include <bits/stdc++.h>
using namespace std;

struct BIT {
    int n;
    vector<long long> bit;
    vector<long long> arr;

    BIT(vector<int>& nums) {
        n = nums.size();
        arr.assign(n, 0);
        bit.assign(n + 1, 0);

        for (int i = 0; i < n; i++) {
            updateToVal(i, nums[i]);
        }
    }

    BIT(int n) {
        this->n = n;
        arr.assign(n, 0);
        bit.assign(n + 1, 0);
    }

    void updateToVal(int ind, long long val) {
        ind++;
        long long delta = val - arr[ind - 1];
        arr[ind - 1] = val;

        while (ind <= n) {
            bit[ind] += delta;
            ind += ind & -ind;
        }
    }

    void addVal(int ind, long long val) {
        ind++;
        arr[ind - 1] += val;

        while (ind <= n) {
            bit[ind] += val;
            ind += ind & -ind;
        }
    }

    long long query(int ind) {
        ind++;
        long long sum = 0;

        while (ind > 0) {
            sum += bit[ind];
            ind -= ind & -ind;
        }

        return sum;
    }

    long long sumRange(int left, int right) {
        if (left == 0) return query(right);
        return query(right) - query(left - 1);
    }
};

int main() {

}