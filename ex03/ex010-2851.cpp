/*
 * Q4
 */

const int MOD = 1e9 + 7;
#define ll long long
#define ar array

namespace Hashing {

mt19937 rng((uint32_t) chrono::steady_clock::now().time_since_epoch().count());
uniform_int_distribution<int> BDIST(0.1 * MOD, 0.9 * MOD);
const ar<int, 2> base = {BDIST(rng), BDIST(rng)};

ar<int, 2> operator+ (ar<int, 2> a, ar<int, 2> b) {
	for (int i = 0; i < 2; ++i)
		if ((a[i] += b[i]) >= MOD)
			a[i] -= MOD;
	return a;
}
ar<int, 2> operator- (ar<int, 2> a, ar<int, 2> b) {
	for (int i = 0; i < 2; ++i)
		if ((a[i] -= b[i]) < 0)
			a[i] += MOD;
	return a;
}
ar<int, 2> operator* (ar<int, 2> a, ar<int, 2> b) {
	for (int i = 0; i < 2; ++i)
		a[i] = (ll)a[i] * b[i] % MOD;
	return a;
}
ar<int, 2> make_hash(char c) {
	return {c, c};
}

vector<ar<int, 2>> pows = {{1, 1}};
void extend(int len) {
	while(pows.size() <= len)
		pows.push_back(base * pows.back());
}

struct hstring {
	string s;
	vector<ar<int, 2>> pre = {{0, 0}};
	void add(string t) {
		s += t;
		for (char c : t)
			pre.push_back(base * pre.back() + make_hash(c));
	}
	ar<int, 2> hash(int l, int r) {
        if (l==r+1)
            return {0, 0};
		assert(0 <= l && l <= r && r < s.size());
		int len = r - l + 1;
		extend(len);
		return pre[r + 1] - pows[len] * pre[l];
	}
};

}
using namespace Hashing;

struct Mat {
	int n, m;
	vector<vector<int>> a;
	Mat() {}
	Mat(int n, int m) : n(n), m(m) {a.assign(n, vector<int>(m));}
	vector<int>& operator[](int i) {return a[i];}
	const vector<int>& operator[](int i) const {return a[i];}
	Mat operator*(const Mat& b) const {
		assert(m==b.n); Mat r(n, b.m);
		for (int i=0; i<n; ++i) for (int j=0; j<m; ++j) for (int k=0; k<b.m; ++k) r[i][k]=(r[i][k]+(ll)a[i][j]*b[j][k])%MOD;
		return r;
	};
};


class Solution {
public:
    int numberOfWays(string s, string t, long long k) {
        hstring hs, ht;
        hs.add(s);
        ht.add(t);
        vector<int> v;
        int n=s.size();
        for (int i=0; i<n; ++i)
            if (hs.hash(i, n-1)*pows[i]+hs.hash(0, i-1)==ht.hash(0, n-1))
                v.push_back(i);
        if (v.size()==0)
            return 0;
        ll x=v.size();
        // a -> (a+b)*x-a
        // b -> (a+b)*(n-x)-b
        Mat a(1, 2);
        a[0]={v[0]==0, v[0]!=0};
        Mat tr(2, 2);
        tr[0][0]=(x-1+MOD)%MOD;
        tr[0][1]=n-x;
        tr[1][0]=x;
        tr[1][1]=(n-x-1+MOD)%MOD;
        while(k) {
            if (k%2)
                a=a*tr;
            tr=tr*tr;
            k/=2;
        }
        return a[0][0];
    }
};
