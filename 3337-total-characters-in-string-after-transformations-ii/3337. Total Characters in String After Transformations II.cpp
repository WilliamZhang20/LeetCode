static constexpr int L = 26; // # letters
static constexpr int mod = 1e9+7;

struct Matrix {
    int a[L][L];
    Matrix() {
        memset(a, 0, sizeof(a));
    }
    Matrix(const Matrix& rhs) {
        for(int i=0; i<L; i++) {
            for(int j = 0; j < L; ++j) {
                a[i][j] = rhs.a[i][j];
            }
        }
    }
    Matrix& operator=(const Matrix& rhs) {
        if(this != &rhs) {
            for(int i=0; i<L; i++) {
                for(int j = 0; j < L; ++j) {
                    a[i][j] = rhs.a[i][j];
                }
            }
        }
        return *this;
    }
};

Matrix operator*(const Matrix& u, const Matrix& v) {
    Matrix w;
    for (int i = 0; i < L; ++i) {
        for (int j = 0; j < L; ++j) {
            for (int k = 0; k < L; ++k) {
                w.a[i][j] =
                    (w.a[i][j] + (long long)u.a[i][k] * v.a[k][j]) % mod;
            }
        }
    }
    return w;
}

// identity matrix
Matrix I() {
    Matrix w;
    for (int i = 0; i < L; ++i) {
        w.a[i][i] = 1;
    }
    return w;
}

// matrix exponentiation by squaring
Matrix quickmul(const Matrix& x, int y) {
    Matrix ans = I(), cur = x;
    while(y) {
        if(y & 1) {
            ans = ans * cur;
        }
        cur = cur * cur;
        y >>= 1;
    }
    return ans;
}

class Solution {
public:
    int lengthAfterTransformations(string s, int t, vector<int>& nums) {
        Matrix T;
        for(int i=0; i<26; ++i) {
            for(int j=1; j<=nums[i]; ++j) {
                T.a[(i + j) % 26][i] = 1;
            }
        }
        Matrix res = quickmul(T, t); // calculate t'th power
        int ans = 0;
        vector<int> f(26);
        for(char ch : s) {
            ++f[ch - 'a'];
        }
        for(int i=0; i<26; ++i) {
            for(int j=0; j<26; ++j) {
                ans = (ans + (long long)res.a[i][j] * f[j]) % mod;
            }
        }
        return ans;
    }
};