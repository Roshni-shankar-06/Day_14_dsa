struct Node {
  int remain[5] = {0};
  int prod = 1;
};

class SegmentTree {
 public:
  explicit SegmentTree(const vector<int>& nums, int k)
      : n(nums.size()), k(k), tree(4 * n) {
    build(nums, 0, 0, n - 1);
  }

  // Updates nums[i] to val.
  void update(int i, int val) {
    update(0, 0, n - 1, i, val);
  }

  // Returns the result of the range query from nums[i..j].
  Node query(int i, int j) const {
    return query(0, 0, n - 1, i, j);
  }

 private:
  const int n;        // the size of the input array
  const int k;        // the modulo value
  vector<Node> tree;  // the segment tree

  void build(const vector<int>& nums, int cur, int left, int right) {
    if (left == right) {
      tree[cur].remain[nums[left]] = 1;
      tree[cur].prod = nums[left];
      return;
    }
    const int mid = (left + right) / 2;
    build(nums, 2 * cur + 1, left, mid);
    build(nums, 2 * cur + 2, mid + 1, right);
    tree[cur] = merge(tree[2 * cur + 1], tree[2 * cur + 2]);
  }

  void update(int treeIndex, int lo, int hi, int i, int val) {
    if (lo == hi) {
      for (int j = 0; j < k; ++j)
        tree[treeIndex].remain[j] = 0;
      tree[treeIndex].remain[val] = 1;
      tree[treeIndex].prod = val;
      return;
    }

