class Solution {
public:

    struct Fenwick {
        int n;
        vector<long long> bit;

        Fenwick(int n) {
            this->n = n;
            bit.assign(n + 1, 0);
        }

        void update(int i, long long val) {
            for (; i <= n; i += i & -i)
                bit[i] += val;
        }

        long long query(int i) {
            long long sum = 0;

            for (; i > 0; i -= i & -i)
                sum += bit[i];

            return sum;
        }

        // Find the smallest index whose prefix sum >= k
        int kth(int k) {
            int idx = 0;

            for (int step = 1 << 17; step > 0; step >>= 1) {
                int next = idx + step;

                if (next <= n && bit[next] < k) {
                    idx = next;
                    k -= bit[next];
                }
            }

            return idx + 1;
        }
    };

    long long minOperations(vector<int>& nums, int x, int k) {

        int n = nums.size();

        // Coordinate compression
        vector<int> vals = nums;

        sort(vals.begin(), vals.end());

        vals.erase(
            unique(vals.begin(), vals.end()),
            vals.end()
        );

        int m = vals.size();

        Fenwick countBIT(m);
        Fenwick sumBIT(m);

        // Add an element to both Fenwick Trees
        auto add = [&](int val, int delta) {
            int id = lower_bound(
                vals.begin(), vals.end(), val
            ) - vals.begin() + 1;

            countBIT.update(id, delta);
            sumBIT.update(id, 1LL * val * delta);
        };

        // Build initial window
        for (int i = 0; i < x; i++) {
            add(nums[i], 1);
        }

        vector<long long> cost(n - x + 1);

        long long windowSum = 0;

        for (int i = 0; i < x; i++)
            windowSum += nums[i];

        // Calculate cost of every window
        for (int i = 0; i <= n - x; i++) {

            // Find median
            int medianId = countBIT.kth((x + 1) / 2);

            long long median = vals[medianId - 1];

            // Count and sum of elements <= median
            long long cnt = countBIT.query(medianId);
            long long leftSum = sumBIT.query(medianId);

            // Minimum operations
            cost[i] =
                median * cnt - leftSum
                + (windowSum - leftSum)
                - median * (x - cnt);

            // Slide window
            if (i < n - x) {
                add(nums[i], -1);
                add(nums[i + x], 1);

                windowSum += nums[i + x] - nums[i];
            }
        }

        // Dynamic Programming with rolling arrays
        const long long INF = 1e18;

        vector<long long> prev(n + 1, 0);
        vector<long long> curr(n + 1, INF);

        for (int t = 1; t <= k; t++) {

            fill(curr.begin(), curr.end(), INF);

            for (int i = 1; i <= n; i++) {

                // Skip current element
                curr[i] = curr[i - 1];

                // Select a window ending at i
                if (i >= x && prev[i - x] != INF) {

                    curr[i] = min(
                        curr[i],
                        prev[i - x] + cost[i - x]
                    );
                }
            }

            prev.swap(curr);
        }

        return prev[n];
    }
};
