#include <vector>
#include <functional>
#include <iostream>

using namespace std;

template<class T>
class permutator {
public:
    using array = vector<T>;
    using index = size_t;
    using body = function<bool (const array &)>;

private:
    static void recursive_permute_while(array & v, index l, index r, body b) {
        if (l == r) {
            if (!b(v)) {
                return;
            }
        } else {
            for (index i = l; i <= r; ++i) {
                swap(v[l], v[i]);
                recursive_permute_while(v, l+1, r, b);
                swap(v[l], v[i]);
            }
        }
    }

    static index factorial(index n) {
        index f = 1;
        for (index i = 2; i <= n; ++i) {
            f *= i;
        }
        cout << n << "! = " << f << endl;
        return f;
    }

    static void non_recursive_permute_while(array & v, index k, body b) {
        cout << "k=" << k << endl;
        for(index j = 1; j < v.size(); ++j) {
            swap(v[k % (j + 1)], v[j]); 
            k = k / (j + 1);
            //cout << "j=" << j << " k=" << k << endl;
            if (!b(v)) {
                return;
            }
        }
    }

    static void fast_permute_while(array & v, body b) {
        index i, n = v.size() - 1;
        int p;
        if (!b(v)) return;
        while (true) {
            for (i = n; i > 0; --i) { 
                if (v[i - 1] < v[i]) break;
            }
            //cout << "i=" << i << endl;
            if (!i) break;
            --i;
            for (p = n; p >= 0; --p) {
                if (v[i] < v[p]) break;
            }
            if (p < 0) break;
            //cout << "p=" << p << endl;
            swap(v[i], v[p]);
            for (++i, p = n; i < p; ++i, --p) swap(v[i], v[p]);
            if (!b(v)) break;
        }
    }

public:
    static void permute_while(array & a, body b) {
        //recursive_permute_while(v, 0, v.size() - 1, b);
        /*index f = factorial(a.size());
        for (index i = 0; i <= f; ++i) {
            array v = a;
            non_recursive_permute_while(v, i, b);
        }*/
        fast_permute_while(a, b);
    }

};


int main() {
    using perm = permutator<int>;
    perm::array a = {1, 2, 3, 4};
    perm::permute_while(a, [](const perm::array & a) {
            for (auto e : a) cout << e << " ";
            cout << endl;
            return true;
        });


    auto abs_perm = [](int n, int k) {
        perm::array v(n);
        for (perm::index i = 0; i < v.size(); ++i) {
            v[i] = i + 1;
        }
        bool total = true;
        perm::permute_while(v, [k, &total](const perm::array & a) {
                for (perm::index i = 0; i < a.size(); ++i) {
                    int d = a[i] - (i + 1);
                    if (abs(d) != k) return true;
                }
                for (auto e : a) {
                    cout << e << " ";
                }
                cout << endl;
                return total = false;
            });
        if (total) cout << -1 << endl;
    };
    
    cout << endl;

    abs_perm(2, 1);
    abs_perm(3, 0);
    abs_perm(3, 2);

    /*
    vector<int> arr;
    vector<int>::reverse_iterator it = arr.rbegin();
    while(it != arr.rend()) {
        *it;
        ++it;
    }
    */
    return 0;
}










