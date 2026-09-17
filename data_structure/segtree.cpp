// time: query - O(log(n)), update - O(log(n)), build - O(n)
// memory - O(n)

struct segtree {
    int n;
    vecll tree;
    // segtree(int n) {
    //     this->n = n;
    //     tree.assign(4 * n, 0);
    // }
    segtree(const vecll& a) {
        n = a.size();
        tree.assign(4 * n, 0);
        build(a, 1, 0, n - 1);
    }
    
    void build(const vecll& a, int v, int tl, int tr) {
        if (tr - tl == 0) {
            tree[v] = a[tl];
        }
        else {
            int tm = (tl + tr) / 2;
            build(a, 2 * v, tl, tm);
            build(a, 2 * v + 1, tm + 1, tr);
            tree[v] = tree[2 * v] + tree[2 * v + 1];
        }
    }
    void update(int v, int tl, int tr, int pos, ll value) {
        if (tr - tl == 0) {
            tree[v] = value;
        }
        else {
            int tm = (tl + tr) / 2;
            if (pos <= tm) {
                update(2 * v, tl, tm, pos, value);
            }
            else {
                update(2 * v + 1, tm + 1, tr, pos, value);
            }
            tree[v] = tree[2 * v] + tree[2 * v + 1];
        }
    }

    ll query(int v, int tl, int tr, int l, int r) {
        if (l > tr || r < tl) {
            return 0;
        }
        
        if (l <= tl && tr <= r) {
            return tree[v];
        }

        int tm = (tr + tl) / 2;
        return query(2 * v, tl, tm, l, r) + query(2 * v + 1, tm + 1, tr, l, r);
    }
    
    void update(int pos, ll value) {
        update(1, 0, n - 1, pos, value)
    }

    ll query(int l, int r) {
        