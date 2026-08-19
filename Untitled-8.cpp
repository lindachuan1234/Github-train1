// BEGIN: main.cpp
#line 1 "main.cpp"
// BEGIN: my_template.hpp
#line 1 "my_template.hpp"
#if defined(LOCAL)
#include <my_template_compiled.hpp>
#else
#if defined(__GNUC__)
#include <bits/allocator.h>
#pragma GCC optimize("Ofast,unroll-loops")
// 環境によってはコンパイル成功かつ実行時エラー
#pragma GCC target("avx2,popcnt")
#endif
#include <bits/stdc++.h>
#include <cassert>

using namespace std;

using ll = long long;
using u8 = uint8_t;
using u16 = uint16_t;
using u32 = uint32_t;
using u64 = uint64_t;
using i128 = __int128;
using u128 = unsigned __int128;
using f128 = __float128;

template <class>
constexpr bool dependent_false = false;

template <class T>
constexpr T infty = [] {
  static_assert(dependent_false<T>, "infty<T> is not defined");
  return T{};
}();
template <>
constexpr int infty<int> = 1'010'000'000;
template <>
constexpr ll infty<ll> = 2'020'000'000'000'000'000;
template <>
constexpr u32 infty<u32> = infty<int>;
template <>
constexpr u64 infty<u64> = infty<ll>;
template <>
constexpr i128 infty<i128> = i128(infty<ll>) * 2'000'000'000'000'000'000;
template <>
constexpr double infty<double> = numeric_limits<double>::infinity();
template <>
constexpr long double infty<long double> =
    numeric_limits<long double>::infinity();

using pi = pair<ll, ll>;
using vi = vector<ll>;
template <class T>
using vc = vector<T>;
template <class T>
using vvc = vector<vc<T>>;
template <class T>
using vvvc = vector<vvc<T>>;
template <class T>
using vvvvc = vector<vvvc<T>>;
template <class T>
using pq_max = priority_queue<T>;
template <class T>
using pq_min = priority_queue<T, vector<T>, greater<T>>;

#define vv(type, name, h, ...) \
  vector<vector<type>> name(h, vector<type>(__VA_ARGS__))
#define vvv(type, name, h, w, ...)   \
  vector<vector<vector<type>>> name( \
      h, vector<vector<type>>(w, vector<type>(__VA_ARGS__)))
#define vvvv(type, name, a, b, c, ...)       \
  vector<vector<vector<vector<type>>>> name( \
      a, vector<vector<vector<type>>>(       \
             b, vector<vector<type>>(c, vector<type>(__VA_ARGS__))))

// https://trap.jp/post/1224/
#define FOR1(a) for (ll _ = 0; _ < ll(a); ++_)
#define FOR2(i, a) for (ll i = 0; i < ll(a); ++i)
#define FOR3(i, a, b) for (ll i = a; i < ll(b); ++i)
#define FOR4(i, a, b, c) for (ll i = a; i < ll(b); i += (c))
#define FOR1_R(a) for (ll i = ll(a) - 1; i >= ll(0); --i)
#define FOR2_R(i, a) for (ll i = ll(a) - 1; i >= ll(0); --i)
#define FOR3_R(i, a, b) for (ll i = ll(b) - 1; i >= ll(a); --i)
#define overload4(a, b, c, d, e, ...) e
#define overload3(a, b, c, d, ...) d
#define FOR(...) overload4(__VA_ARGS__, FOR4, FOR3, FOR2, FOR1)(__VA_ARGS__)
#define FOR_R(...) overload3(__VA_ARGS__, FOR3_R, FOR2_R, FOR1_R)(__VA_ARGS__)

#define all(x) (x).begin(), (x).end()
#define len(x) ll(x.size())
#define elif else if

#define eb emplace_back
#define mp make_pair
#define mt make_tuple
#define fi first
#define se second

#define stoi stoll

// require y > 0
template <typename T>
T floor(T x, T y) {
  return x / y - (x % y < 0);
}

// require y > 0
template <typename T>
T ceil(T x, T y) {
  return (x / y) + (x % y > 0);
}

// require y > 0
template <typename T>
T bmod(T x, T y) {
  T r = x % y;
  return (r < 0 ? r + y : r);
}

// require y > 0
template <typename T>
pair<T, T> divmod(T x, T y) {
  T q = x / y, r = x % y;
  if (r < 0) --q, r += y;
  return {q, r};
}

constexpr auto TEN = [] {
  array<u64, 20> A{};
  A[0] = 1;
  for (int i = 1; i < 20; ++i) A[i] = 10 * A[i - 1];
  return A;
}();

template <typename T, typename U>
T SUM(const U &A) {
  return std::accumulate(A.begin(), A.end(), T{});
}

#define MIN(v) *min_element(all(v))
#define MAX(v) *max_element(all(v))
template <class C, class T>
inline long long LB(const C &c, const T &x) {
  return lower_bound(c.begin(), c.end(), x) - c.begin();
}
template <class C, class T>
inline long long UB(const C &c, const T &x) {
  return upper_bound(c.begin(), c.end(), x) - c.begin();
}
#define UNIQUE(x) sort(all(x)), x.erase(unique(all(x)), x.end())

template <typename T>
T POP(deque<T> &que) {
  T a = que.front();
  que.pop_front();
  return a;
}
template <class T, class Container, class Compare>
T POP(priority_queue<T, Container, Compare> &que) {
  T a = que.top();
  que.pop();
  return a;
}
template <typename T>
T POP(vc<T> &que) {
  T a = que.back();
  que.pop_back();
  return a;
}

template <typename F>
ll binary_search(F check, ll ok, ll ng, bool check_ok = true) {
  if (check_ok) assert(check(ok));
  while (llabs(ok - ng) > 1) {
    auto x = (ng + ok) / 2;
    (check(x) ? ok : ng) = x;
  }
  return ok;
}
template <typename F>
double binary_search_real(F check, double ok, double ng, int iter = 100) {
  FOR(iter) {
    double x = (ok + ng) / 2;
    (check(x) ? ok : ng) = x;
  }
  return (ok + ng) / 2;
}

template <class T, class S>
inline bool chmax(T &a, const S &b) {
  T c = max<T>(a, b);
  bool changed = (c != a);
  a = c;
  return changed;
}
template <class T, class S>
inline bool chmin(T &a, const S &b) {
  T c = min<T>(a, b);
  bool changed = (c != a);
  a = c;
  return changed;
}

// ? は -1
vc<int> s_to_vi(const string &S, char first_char) {
  vc<int> A(S.size());
  FOR(i, S.size()) { A[i] = (S[i] != '?' ? S[i] - first_char : -1); }
  return A;
}

template <typename T, typename U>
vc<T> cumsum(const vc<U> &A, int off = 1) {
  int N = A.size();
  vc<T> B(N + 1);
  FOR(i, N) { B[i + 1] = B[i] + A[i]; }
  if (off == 0) B.erase(B.begin());
  return B;
}

// stable sort
template <typename T>
vc<int> argsort(const vc<T> &A) {
  vc<int> ids(len(A));
  iota(all(ids), 0);
  sort(all(ids),
       [&](int i, int j) { return (A[i] == A[j] ? i < j : A[i] < A[j]); });
  return ids;
}

// A[I[0]], A[I[1]], ...
template <typename T>
vc<T> rearrange(const vc<T> &A, const vc<int> &I) {
  vc<T> B(len(I));
  FOR(i, len(I)) B[i] = A[I[i]];
  return B;
}

template <typename T, typename... Vectors>
void concat(vc<T> &first, const Vectors &...others) {
  first.reserve(first.size() + (others.size() + ... + 0));
  (first.insert(first.end(), others.begin(), others.end()), ...);
}

// i128
template <class T, enable_if_t<is_same_v<T, i128>, int> = 0>
constexpr i128 abs(T x) {
  return x < 0 ? -x : x;
}

constexpr i128 gcd(i128 a, i128 b) {
  while (b != 0) {
    i128 c = a % b;
    a = b, b = c;
  }
  return abs(a);
}
#endif
// END: my_template.hpp
#line 2 "main.cpp"
// BEGIN: other/io.hpp
#line 1 "other/io.hpp"
#define FASTIO

// https://judge.yosupo.jp/submission/21623
namespace fastio {
static constexpr uint32_t SZ = 1 << 17;
char ibuf[SZ];
char obuf[SZ];
char out[100];
// pointer of ibuf, obuf
uint32_t pil = 0, pir = 0, por = 0;
bool input_eof = false;

template <class T>
constexpr bool is_signed_integer_v = is_signed_v<T> || is_same_v<T, i128>;

template <class T>
struct unsigned_integer {
  using type = make_unsigned_t<T>;
};
template <>
struct unsigned_integer<i128> {
  using type = u128;
};
template <>
struct unsigned_integer<u128> {
  using type = u128;
};
template <class T>
using unsigned_integer_t = typename unsigned_integer<T>::type;

[[noreturn]] inline void input_error(const char *message) {
  fputs(message, stderr);
  fputc('\n', stderr);
  exit(EXIT_FAILURE);
}

struct Pre {
  char num[10000][4];
  constexpr Pre() : num() {
    for (int i = 0; i < 10000; i++) {
      int n = i;
      for (int j = 3; j >= 0; j--) {
        num[i][j] = n % 10 | '0';
        n /= 10;
      }
    }
  }
} constexpr pre;

inline void load() {
  uint32_t n = pir - pil;
  memmove(ibuf, ibuf + pil, n);
  pil = 0;
  pir = n;
  if (input_eof) return;

  pir += fread(ibuf + pir, 1, SZ - pir, stdin);
  if (ferror(stdin)) input_error("fastio: input error");
  if (feof(stdin)) {
    input_eof = true;
    // Allows the last token to end exactly at EOF without a trailing
    // whitespace.
    if (pir < SZ) ibuf[pir++] = '\n';
  }
}

inline char get_char() {
  if (pil == pir) {
    load();
    if (pil == pir) input_error("fastio: unexpected EOF");
  }
  return ibuf[pil++];
}

inline void flush() {
  fwrite(obuf, 1, por, stdout);
  por = 0;
}

void rd(char &c) {
  do c = get_char();
  while (isspace(static_cast<unsigned char>(c)));
}

void rd(string &x) {
  x.clear();
  char c;
  do c = get_char();
  while (isspace(static_cast<unsigned char>(c)));
  do {
    x += c;
    c = get_char();
  } while (!isspace(static_cast<unsigned char>(c)));
}

template <typename T>
void rd_real(T &x) {
  string s;
  rd(s);
  x = stod(s);
}

template <typename T>
void rd_integer_slow(T &x) {
  char c;
  do c = get_char();
  while (c < '-');
  bool minus = 0;
  if constexpr (is_signed_integer_v<T>) {
    if (c == '-') {
      minus = 1, c = get_char();
    }
  }
  x = 0;
  assert('0' <= c && c <= '9');
  while ('0' <= c && c <= '9') {
    x = x * 10 + (c & 15), c = get_char();
  }
  assert(isspace(static_cast<unsigned char>(c)));
  if constexpr (is_signed_integer_v<T>) {
    if (minus) x = -x;
  }
}

template <typename T>
void rd_integer(T &x) {
  if (pil + 100 > pir) {
    load();
    if (pil + 100 > pir) {
      rd_integer_slow(x);
      return;
    }
  }
  char c;
  do c = ibuf[pil++];
  while (c < '-');
  bool minus = 0;
  if constexpr (is_signed_integer_v<T>) {
    if (c == '-') {
      minus = 1, c = ibuf[pil++];
    }
  }
  x = 0;
  assert('0' <= c && c <= '9');
  while ('0' <= c && c <= '9') {
    x = x * 10 + (c & 15), c = ibuf[pil++];
  }
  assert(isspace(static_cast<unsigned char>(c)));
  if constexpr (is_signed_integer_v<T>) {
    if (minus) x = -x;
  }
}

template <class T>
enable_if_t<is_integral_v<T> || is_same_v<T, i128> || is_same_v<T, u128>> rd(
    T &x) {
  rd_integer(x);
}

template <class T>
enable_if_t<is_floating_point_v<T> || is_same_v<T, f128>> rd(T &x) {
  rd_real(x);
}

template <class T, class U>
void rd(pair<T, U> &p) {
  rd(p.first), rd(p.second);
}
template <size_t N = 0, typename T>
void rd_tuple(T &t) {
  if constexpr (N < tuple_size<T>::value) {
    auto &x = get<N>(t);
    rd(x);
    rd_tuple<N + 1>(t);
  }
}
template <class... T>
void rd(tuple<T...> &tpl) {
  rd_tuple(tpl);
}

template <class T, size_t N>
void rd(array<T, N> &x) {
  for (auto &d : x) rd(d);
}
template <class T>
void rd(vc<T> &x) {
  for (auto &d : x) rd(d);
}

template <class... T>
void read(T &...x) {
  (rd(x), ...);
}

inline void wt_range(const char *s, size_t n) {
  size_t i = 0;
  while (i < n) {
    if (por == SZ) flush();
    size_t chunk = min(n - i, (size_t)(SZ - por));
    memcpy(obuf + por, s + i, chunk);
    por += chunk;
    i += chunk;
  }
}

void wt(const char c) {
  if (por == SZ) flush();
  obuf[por++] = c;
}
void wt(const char *s) { wt_range(s, strlen(s)); }
void wt(const string &s) { wt_range(s.data(), s.size()); }

template <typename T>
void wt_integer(T x) {
  if (por > SZ - 100) flush();
  using U = unsigned_integer_t<T>;
  U y = static_cast<U>(x);
  if constexpr (is_signed_integer_v<T>) {
    if (x < 0) {
      obuf[por++] = '-';
      y = U(0) - y;
    }
  }
  int outi;
  for (outi = 96; y >= 10000; outi -= 4) {
    memcpy(out + outi, pre.num[y % 10000], 4);
    y /= 10000;
  }
  if (y >= 1000) {
    memcpy(obuf + por, pre.num[y], 4);
    por += 4;
  } else if (y >= 100) {
    memcpy(obuf + por, pre.num[y] + 1, 3);
    por += 3;
  } else if (y >= 10) {
    int q = (y * 103) >> 10;
    obuf[por] = q | '0';
    obuf[por + 1] = (y - q * 10) | '0';
    por += 2;
  } else
    obuf[por++] = y | '0';
  memcpy(obuf + por, out + outi + 4, 96 - outi);
  por += 96 - outi;
}

template <typename T>
inline void wt_real(T x) {
  static char buf[1000];
  int n = std::snprintf(buf, sizeof(buf), "%.15f", (double)x);
  wt_range(buf, (size_t)n);
}

template <class T>
enable_if_t<is_integral_v<T> || is_same_v<T, i128> || is_same_v<T, u128>> wt(
    T x) {
  wt_integer(x);
}

template <class T>
enable_if_t<is_floating_point_v<T> || is_same_v<T, f128>> wt(T x) {
  wt_real(x);
}

inline void wt(bool b) { wt(static_cast<char>('0' + (b ? 1 : 0))); }

template <class T, class U>
void wt(const pair<T, U> &val) {
  wt(val.first);
  wt(' ');
  wt(val.second);
}
template <size_t N = 0, typename T>
void wt_tuple(const T &t) {
  if constexpr (N < tuple_size<T>::value) {
    if constexpr (N > 0) wt(' ');
    wt(get<N>(t));
    wt_tuple<N + 1>(t);
  }
}
template <class... T>
void wt(const tuple<T...> &tpl) {
  wt_tuple(tpl);
}
template <class T, size_t S>
void wt(const array<T, S> &val) {
  auto n = val.size();
  for (size_t i = 0; i < n; i++) {
    if (i) wt(' ');
    wt(val[i]);
  }
}
template <class T>
void wt(const vector<T> &val) {
  auto n = val.size();
  for (size_t i = 0; i < n; i++) {
    if (i) wt(' ');
    wt(val[i]);
  }
}

void print() { wt('\n'); }
template <class Head, class... Tail>
void print(Head &&head, Tail &&...tail) {
  wt(forward<Head>(head));
  ((wt(' '), wt(forward<Tail>(tail))), ...);
  wt('\n');
}

// gcc expansion. called automaticall after main.
void __attribute__((destructor)) _d() { flush(); }
}  // namespace fastio
using fastio::flush;
using fastio::print;
using fastio::read;

#if defined(LOCAL)
#define HDR "[DEBUG:", __func__, __LINE__, "]"
#define SHOW(...)                                                         \
  SHOW_IMPL(__VA_ARGS__, SHOW8, SHOW7, SHOW6, SHOW5, SHOW4, SHOW3, SHOW2, \
            SHOW1)                                                        \
  (__VA_ARGS__)
#define SHOW_IMPL(_1, _2, _3, _4, _5, _6, _7, _8, NAME, ...) NAME
#define SHOW1(x) print(HDR, #x, "=", (x)), flush()
#define SHOW2(x, y) print(HDR, #x, "=", (x), #y, "=", (y)), flush()
#define SHOW3(x, y, z) \
  print(HDR, #x, "=", (x), #y, "=", (y), #z, "=", (z)), flush()
#define SHOW4(x, y, z, w) \
  print(HDR, #x, "=", (x), #y, "=", (y), #z, "=", (z), #w, "=", (w)), flush()
#define SHOW5(x, y, z, w, v)                                                  \
  print(HDR, #x, "=", (x), #y, "=", (y), #z, "=", (z), #w, "=", (w), #v, "=", \
        (v)),                                                                 \
      flush()
#define SHOW6(x, y, z, w, v, u)                                               \
  print(HDR, #x, "=", (x), #y, "=", (y), #z, "=", (z), #w, "=", (w), #v, "=", \
        (v), #u, "=", (u)),                                                   \
      flush()
#define SHOW7(x, y, z, w, v, u, t)                                            \
  print(HDR, #x, "=", (x), #y, "=", (y), #z, "=", (z), #w, "=", (w), #v, "=", \
        (v), #u, "=", (u), #t, "=", (t)),                                     \
      flush()
#define SHOW8(x, y, z, w, v, u, t, s)                                         \
  print(HDR, #x, "=", (x), #y, "=", (y), #z, "=", (z), #w, "=", (w), #v, "=", \
        (v), #u, "=", (u), #t, "=", (t), #s, "=", (s)),                       \
      flush()
#else
#define SHOW(...)
#endif

#define INT(...)   \
  int __VA_ARGS__; \
  read(__VA_ARGS__)
#define LL(...)   \
  ll __VA_ARGS__; \
  read(__VA_ARGS__)
#define U32(...)   \
  u32 __VA_ARGS__; \
  read(__VA_ARGS__)
#define U64(...)   \
  u64 __VA_ARGS__; \
  read(__VA_ARGS__)
#define STR(...)      \
  string __VA_ARGS__; \
  read(__VA_ARGS__)
#define CHAR(...)   \
  char __VA_ARGS__; \
  read(__VA_ARGS__)
#define DBL(...)      \
  double __VA_ARGS__; \
  read(__VA_ARGS__)

#define VEC(type, name, size) \
  vector<type> name(size);    \
  read(name)
#define VV(type, name, h, w)                     \
  vector<vector<type>> name(h, vector<type>(w)); \
  read(name)

void YES(bool t = 1) { print(t ? "YES" : "NO"); }
void NO(bool t = 1) { YES(!t); }
void Yes(bool t = 1) { print(t ? "Yes" : "No"); }
void No(bool t = 1) { Yes(!t); }
void yes(bool t = 1) { print(t ? "yes" : "no"); }
void no(bool t = 1) { yes(!t); }
void YA(bool t = 1) { print(t ? "YA" : "TIDAK"); }
void TIDAK(bool t = 1) { YA(!t); }
void Alice(bool t = 1) { print(t ? "Alice" : "Bob"); }
void Bob(bool t = 1) { Alice(!t); }// END: other/io.hpp
#line 3 "main.cpp"

// BEGIN: ds/unionfind/unionfind.hpp
#line 1 "ds/unionfind/unionfind.hpp"

struct UnionFind {
  int n, n_comp;
  vc<int> dat; // par or (-size)
  UnionFind(int n = 0) { build(n); }

  void build(int m) {
    n = m, n_comp = m;
    dat.assign(n, -1);
  }

  void reset() { build(n); }

  int operator[](int x) {
    while (dat[x] >= 0) {
      int pp = dat[dat[x]];
      if (pp < 0) { return dat[x]; }
      x = dat[x] = pp;
    }
    return x;
  }

  ll size(int x) {
    x = (*this)[x];
    return -dat[x];
  }

  bool merge(int x, int y) {
    x = (*this)[x], y = (*this)[y];
    if (x == y) return false;
    if (-dat[x] < -dat[y]) swap(x, y);
    dat[x] += dat[y], dat[y] = x, n_comp--;
    return true;
  }

  vc<int> get_all() {
    vc<int> A(n);
    FOR(i, n) A[i] = (*this)[i];
    return A;
  }
};
// END: ds/unionfind/unionfind.hpp
#line 5 "main.cpp"
// BEGIN: mod/modint.hpp
#line 1 "mod/modint.hpp"
// BEGIN: mod/modint_common.hpp
#line 1 "mod/modint_common.hpp"

// BEGIN: other/bit.hpp
#line 1 "other/bit.hpp"

int popcnt(int x) { return __builtin_popcount(x); }
int popcnt(u32 x) { return __builtin_popcount(x); }
int popcnt(ll x) { return __builtin_popcountll(x); }
int popcnt(u64 x) { return __builtin_popcountll(x); }
int popcnt_sgn(int x) { return (__builtin_parity(unsigned(x)) & 1 ? -1 : 1); }
int popcnt_sgn(u32 x) { return (__builtin_parity(x) & 1 ? -1 : 1); }
int popcnt_sgn(ll x) { return (__builtin_parityll(x) & 1 ? -1 : 1); }
int popcnt_sgn(u64 x) { return (__builtin_parityll(x) & 1 ? -1 : 1); }
// (0, 1, 2, 3, 4) -> (-1, 0, 1, 1, 2)
int topbit(int x) { return (x == 0 ? -1 : 31 - __builtin_clz(x)); }
int topbit(u32 x) { return (x == 0 ? -1 : 31 - __builtin_clz(x)); }
int topbit(ll x) { return (x == 0 ? -1 : 63 - __builtin_clzll(x)); }
int topbit(u64 x) { return (x == 0 ? -1 : 63 - __builtin_clzll(x)); }
// (0, 1, 2, 3, 4) -> (-1, 0, 1, 0, 2)
int lowbit(int x) { return (x == 0 ? -1 : __builtin_ctz(x)); }
int lowbit(u32 x) { return (x == 0 ? -1 : __builtin_ctz(x)); }
int lowbit(ll x) { return (x == 0 ? -1 : __builtin_ctzll(x)); }
int lowbit(u64 x) { return (x == 0 ? -1 : __builtin_ctzll(x)); }

template <typename T>
T kth_bit(int k) {
  return T(1) << k;
}
template <typename T>
bool has_kth_bit(T x, int k) {
  return x >> k & 1;
}

template <typename UINT>
struct all_bit {
  UINT s;
  all_bit(UINT s) : s(s) {}
  struct iter {
    UINT s;
    int operator*() const { return lowbit(s); }
    void operator++() { s &= s - 1; }
    bool operator!=(nullptr_t) const { return s; }
  };
  iter begin() const { return {s}; }
  nullptr_t end() const { return nullptr; }
};

template <typename UINT>
struct all_subset {
  UINT s;
  all_subset(UINT s) : s(s) {}
  struct iter {
    UINT s, t;
    bool done = false;
    UINT operator*() const { return t; }
    void operator++() {
      done = (t == 0);
      t = (t - 1) & s;
    }
    bool operator!=(nullptr_t) const { return !done; }
  };
  iter begin() const { return {s, s}; }
  nullptr_t end() const { return nullptr; }
};

constexpr u64 full_mask(int n) { return n == 64 ? -1ULL : (1ULL << n) - 1; }// END: other/bit.hpp
#line 4 "mod/modint_common.hpp"

struct has_mod_impl {
  template <class T>
  static auto check(T &&x) -> decltype(x.get_mod(), std::true_type{});
  template <class T>
  static auto check(...) -> std::false_type;
};

template <class T>
class has_mod : public decltype(has_mod_impl::check<T>(std::declval<T>())) {};

template <typename mint>
mint fact(int n) {
  static const int mod = mint::get_mod();
  assert(0 <= n && n < mod);
  static vector<mint> dat = {1, 1};
  if (len(dat) <= n) {
    int now = len(dat);
    int m = min(mod, 1 << (topbit(n) + 1));
    dat.resize(m);
    FOR(i, now, m) dat[i] = dat[i - 1] * mint::raw(i);
  }
  return dat[n];
}

template <typename mint>
mint fact_inv(int n) {
  static const int mod = mint::get_mod();
  static vector<mint> dat = {1, 1};
  if (n < 0) return mint(0);
  if (len(dat) <= n) {
    int now = len(dat);
    int m = min(mod, 1 << (topbit(n) + 1));
    dat.resize(m);
    dat[m - 1] = fact<mint>(m - 1).inverse();
    FOR_R(i, now, m - 1) dat[i] = dat[i + 1] * mint::raw(i + 1);
  }
  return dat[n];
}

template <class mint, class... Ts>
mint fact_invs(Ts... xs) {
  return (mint(1) * ... * fact_inv<mint>(xs));
}

template <typename mint>
mint inv(int n) {
  static const int mod = mint::get_mod();
  assert(1 <= n && n < mod);
  return fact<mint>(n - 1) * fact_inv<mint>(n);
}

template <>
double inv<double>(int n) {
  assert(n != 0);
  return 1.0 / n;
}

template <typename mint, class Head, class... Tail>
mint multinomial(Head &&head, Tail &&...tail) {
  return fact<mint>(head) * fact_invs<mint>(std::forward<Tail>(tail)...);
}

template <typename mint>
mint C_dense(int n, int k) {
  assert(n >= 0);
  if (k < 0 || n < k) return 0;
  static vvc<mint> C;
  static int H = 0, W = 0;
  auto calc = [&](int i, int j) -> mint {
    if (i == 0) return (j == 0 ? mint(1) : mint(0));
    return C[i - 1][j] + (j ? C[i - 1][j - 1] : 0);
  };
  if (W <= k) {
    FOR(i, H) {
      C[i].resize(k + 1);
      FOR(j, W, k + 1) { C[i][j] = calc(i, j); }
    }
    W = k + 1;
  }
  if (H <= n) {
    C.resize(n + 1);
    FOR(i, H, n + 1) {
      C[i].resize(W);
      FOR(j, W) { C[i][j] = calc(i, j); }
    }
    H = n + 1;
  }
  return C[n][k];
}

template <typename mint, bool large = false, bool dense = false>
mint C(ll n, ll k) {
  assert(n >= 0);
  if (k < 0 || n < k) return 0;
  if constexpr (dense) return C_dense<mint>(n, k);
  if constexpr (!large) return multinomial<mint>(n, k, n - k);
  k = min(k, n - k);
  mint x(1);
  FOR(i, k) x *= mint(n - i);
  return x * fact_inv<mint>(k);
}

template <typename mint, bool large = false>
mint C_inv(ll n, ll k) {
  assert(n >= 0);
  assert(0 <= k && k <= n);
  if (!large) return fact_inv<mint>(n) * fact<mint>(k) * fact<mint>(n - k);
  return mint(1) / C<mint, 1>(n, k);
}

// [x^d](1-x)^{-n}
template <typename mint, bool large = false, bool dense = false>
mint C_negative(ll n, ll d) {
  assert(n >= 0);
  if (d < 0) return mint(0);
  if (n == 0) {
    return (d == 0 ? mint(1) : mint(0));
  }
  return C<mint, large, dense>(n + d - 1, d);
}// END: mod/modint_common.hpp
#line 3 "mod/modint.hpp"

template <int mod>
struct modint {
  static constexpr u32 umod = u32(mod);
  static_assert(umod < u32(1) << 31);
  u32 val;

  static modint raw(u32 v) {
    modint x;
    x.val = v;
    return x;
  }
  constexpr modint() : val(0) {}
  constexpr modint(u32 x) : val(x % umod) {}
  constexpr modint(u64 x) : val(x % umod) {}
  constexpr modint(u128 x) : val(x % umod) {}
  constexpr modint(int x) : val((x %= mod) < 0 ? x + mod : x){};
  constexpr modint(ll x) : val((x %= mod) < 0 ? x + mod : x){};
  constexpr modint(i128 x) : val((x %= mod) < 0 ? x + mod : x){};
  bool operator<(const modint &other) const { return val < other.val; }
  modint &operator+=(const modint &p) {
    if ((val += p.val) >= umod) val -= umod;
    return *this;
  }
  modint &operator-=(const modint &p) {
    if ((val += umod - p.val) >= umod) val -= umod;
    return *this;
  }
  modint &operator*=(const modint &p) {
    val = u64(val) * p.val % umod;
    return *this;
  }
  modint &operator/=(const modint &p) {
    *this *= p.inverse();
    return *this;
  }
  modint operator-() const { return modint::raw(val ? mod - val : u32(0)); }
  modint operator+(const modint &p) const { return modint(*this) += p; }
  modint operator-(const modint &p) const { return modint(*this) -= p; }
  modint operator*(const modint &p) const { return modint(*this) *= p; }
  modint operator/(const modint &p) const { return modint(*this) /= p; }
  bool operator==(const modint &p) const { return val == p.val; }
  bool operator!=(const modint &p) const { return val != p.val; }
  modint inverse() const {
    int a = val, b = mod, u = 1, v = 0, t;
    while (b > 0) {
      t = a / b;
      swap(a -= t * b, b), swap(u -= t * v, v);
    }
    return modint(u);
  }
  modint pow(ll n) const {
    if (n < 0) return inverse().pow(-n);
    assert(n >= 0);
    modint ret(1), mul(val);
    while (n > 0) {
      if (n & 1) ret *= mul;
      mul *= mul;
      n >>= 1;
    }
    return ret;
  }
  static constexpr int get_mod() { return mod; }
  // (n, r), r は 1 の 2^n 乗根
  static constexpr pair<int, int> ntt_info() {
    if (mod == 120586241) return {20, 74066978};
    if (mod == 167772161) return {25, 17};
    if (mod == 469762049) return {26, 30};
    if (mod == 754974721) return {24, 362};
    if (mod == 880803841) return {23, 211};
    if (mod == 943718401) return {22, 663003469};
    if (mod == 998244353) return {23, 31};
    if (mod == 1004535809) return {21, 582313106};
    if (mod == 1012924417) return {21, 368093570};
    if (mod == 1224736769) return {24, 1191450770};
    if (mod == 2013265921) return {27, 244035102};
    return {-1, -1};
  }
  static constexpr bool can_ntt() { return ntt_info().fi != -1; }
};

#ifdef FASTIO
template <int mod>
void rd(modint<mod> &x) {
  fastio::rd(x.val);
  x.val %= mod;
  // assert(0 <= x.val && x.val < mod);
}
template <int mod>
void wt(modint<mod> x) {
  fastio::wt(x.val);
}
#endif

using modint107 = modint<1000000007>;
using modint998 = modint<998244353>;
// END: mod/modint.hpp
#line 6 "main.cpp"

using mint = modint998;

mint solve(int N, vc<int> A) {
  vc<int> pos(N);
  FOR(i, N) pos[A[i]] = i;

  UnionFind uf(N);
  vc<int> S(N, 1);
  vc<int> lo(N);
  vc<pair<int, int>> range(N);
  FOR(i, N) range[i] = {i, i}, lo[i] = A[i];
  mint ANS = 1;

  auto mg = [&](int a, int b) -> void {
    // SHOW(a, b);
    a = uf[a], b = uf[b];
    assert(a != b);
    uf.merge(a, b);
    int c = uf[a];
    S[c] = S[a] + S[b];
    range[c] = {range[a].fi, range[b].se};
    lo[c] = min(lo[a], lo[b]);
  };

  FOR_R(x, N) {
    int i = pos[x];
    while (1) {
      auto [l, r] = range[uf[i]];
      // SHOW(l, r);
      if (l >= 2 && x < A[l - 1] && A[l - 1] > lo[uf[l - 2]]) {
        mg(l - 2, l);
        continue;
      }
      if (r + 2 < N && x < A[r + 1] && A[r + 1] > lo[uf[r + 2]]) {
        mg(r, r + 2);
        continue;
      }
      break;
    }
    ANS *= S[uf[i]];
    S[uf[i]] -= 1;
  }
  return ANS;
}

void test(int N) {
  vvc<int> P;
  {
    vc<int> A(N);
    FOR(i, N) A[i] = i;
    do {
      P.eb(A);
    } while (next_permutation(all(A)));
  }

  UnionFind uf(len(P));
  FOR(a, len(P)) {
    vc<int> A = P[a];
    FOR(i, 1, N - 1) {
      if (A[i - 1] < A[i] && A[i] > A[i + 1]) {
        swap(A[i - 1], A[i + 1]);
        int b = LB(P, A);
        swap(A[i - 1], A[i + 1]);
        uf.merge(a, b);
      }
    }
  }

  FOR(i, len(P)) {
    vc<int> A = P[i];
    mint god = uf.size(i);
    mint ans = solve(N, A);
    SHOW(A, god, ans);
    assert(god == ans);
  }
  print("N=", N, "OK");
  flush();
}

void solve() {
  INT(N);
  VEC(int, A, N);
  for (auto& x : A) --x;
  print(solve(N, A));
}

signed main() {
  // FOR(N, 1, 12) test(N);
  INT(T);
  FOR(T) solve();
}// END: main.cpp
