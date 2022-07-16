// Disjoint set union with size.
// Index begins from 1 to n.
struct DSU {
    vector<int> f, sz;
    DSU(int n): f(n + 1), sz(n + 1, 1) {
        for (int i = 1; i <= n; i++) {
            f[i] = i;
        }
    }
    // Returns the leader of the set containing x.
    int leader(int x) {
        if (f[x] != x) {
            f[x] = leader(f[x]);
        }
        return f[x];
    }
    // Whether or not x and y are in the same set.
    bool same(int x, int y) {
        return leader(x) == leader(y);
    }
    // Merge the sets containing x and y. If x and y are already
    // in the same set, returns false and do nothing.
    bool merge(int x, int y) {
        x = leader(x);
        y = leader(y);
        if (x == y) {
            return false;
        }
        sz[x] += sz[y];
        f[y] = x;
        return true;
    }
    // Returns the size of the set containing x.
    int size(int x) {
        return sz[leader(x)];
    }
};