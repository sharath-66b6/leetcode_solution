class Solution {
 public:
  int lengthAfterTransformations(string s, int t) {
    constexpr int kMod = 1'000'000'007;
    vector<int> v1(26);

    for (const char c : s)
      ++v1[c - 'a'];

    while (t-- > 0) {
      vector<int> v2(26);
      for (int i = 0; i < 25; ++i)
        v2[i + 1] = v1[i];
      v2[0] = v1[25];
      v2[1] = (v2[1] + v1[25]) % kMod;
      v1 = move(v2);
    }

    return accumulate(v1.begin(), v1.end(), 0L) % kMod;
  }
};
