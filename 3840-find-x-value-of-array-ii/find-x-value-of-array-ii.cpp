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

