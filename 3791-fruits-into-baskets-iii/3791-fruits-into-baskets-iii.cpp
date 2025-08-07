class SegmentTree {
public:
    SegmentTree(vector<int>& nums) : n(nums.size()), tree(n * 4) {
        build(0, 0, n - 1, nums);
    }

    void update(int i, int val) { update(i, val, 0, 0, n - 1); }

    int queryFirst(int t) { return query(t, 0, 0, n - 1); }

private:
    int n;
    vector<int> tree;
    void build(int ind, int start, int end, vector<int>& nums) {
        if (start == end) {
            tree[ind] = nums[start];
            return;
        }

        int mid = (start + end) / 2;
        build(2 * ind + 1, start, mid, nums);
        build(2 * ind + 2, mid + 1, end, nums);
        tree[ind] = max(tree[2 * ind + 1], tree[2 * ind + 2]);
    }

    void update(int tind, int val, int ind, int start, int end) {
        if (start == end) {
            tree[ind] = val;
            return;
        }

        int mid = (start + end) / 2;
        if (tind <= mid)
            update(tind, val, 2 * ind + 1, start, mid);
        else
            update(tind, val, 2 * ind + 2, mid + 1, end);

        tree[ind] = max(tree[2 * ind + 1], tree[2 * ind + 2]);
    }

    int query(int t, int ind, int start, int end) {
        if (tree[ind] < t)
            return -1;
        if (start == end) {
            update(start, -1);
            return start;
        }

        int mid = (start + end) / 2;
        int leftchild = tree[2 * ind + 1];
        return leftchild >= t ? query(t, 2 * ind + 1, start, mid)
                              : query(t, 2 * ind + 2, mid + 1, end);
    }
};

class Solution {
public:
    int numOfUnplacedFruits(vector<int>& fruits, vector<int>& baskets) {
        int ans = 0;
        SegmentTree tree(baskets);

        for (const int fruit : fruits)
            if (tree.queryFirst(fruit) == -1)
                ++ans;

        return ans;
    }
};
