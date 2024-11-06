#include <iostream>
#include <stdexcept>
#include <typeinfo>
#include <vector>
#include <fstream>
#include <ctime>
#include <list>
#include <stack>
#include <queue>
#include <deque>
#include <algorithm>
#include <tgmath.h>
#include <set>
#include <map>
#include <algorithm>

using namespace std;

template <typename T> float mod(T &dividend, T &divider) {
  int x = dividend / divider;
  return dividend - x * divider;
};

template <typename T> T sum(vector<T> &x) {
  T rtn = 0;
  for (typename vector<T>::iterator it = x.begin(); it != x.end(); ++it) {
    rtn += *it;
  }
  return rtn;
};

template <typename T> T mean(vector<T> &x) {
  float rtn = 0;
  for (typename vector<T>::iterator it = x.begin(); it != x.end(); ++it) {
    rtn += *it;
  }
  return rtn / x.size();
};

template <typename T, typename T2> int matchl(vector<T> &source, T2 &ptrn) {
  for (typename vector<T>::iterator i = source.begin(); i != source.end(); ++i) {
    if (*i == ptrn) {
      return 1;
    };
  };
  return 0;
};

template <typename T, typename T2> int match(vector<T> &source, T2 &ptrn) {
  int cnt = 0;
  for (typename vector<T>::iterator i = source.begin(); i != source.end(); ++i) {
    if (*i == ptrn) {
      return cnt;
    };
    cnt += 1;
  };
  return -1;
};

template <typename T> T min(vector<T> &x) {
  T rtn = x[0];
  for (typename vector<T>::iterator it = x.begin() + 1; it != x.end(); ++it) {
    if (rtn > *it) {
      rtn = *it;
    };
  };
  return rtn;
};

template <typename T> T max(vector<T> &x) {
  T rtn = x[0];
  for (typename vector<T>::iterator it = x.begin() + 1; it != x.end(); ++it) {
    if (rtn < *it) {
      rtn = *it;
    };
  };
  return rtn;
};

template <typename T> T match_max(vector<T> &x) {
  T cvl = x[0];
  int i = 1;
  int rtn = 0;
  for (typename vector<T>::iterator it = x.begin() + 1; it != x.end(); ++it) {
    if (cvl < *it) {
      cvl = *it;
      rtn = i;
    };
    i += 1;
  };
  return rtn;
};

template <typename T> T match_min(vector<T> &x) {
  T cvl = x[0];
  int i = 1;
  int rtn = 0;
  for (typename vector<T>::iterator it = x.begin() + 1; it != x.end(); ++it) {
    if (cvl > *it) {
      cvl = *it;
      rtn = i;
    };
    i += 1;
  };
  return rtn;
};

template <typename T, typename T2> auto grep(vector<T> &source, T2 &ptrn) {
  vector<int> rtn;
  int i = 0;
  for (typename vector<T>::iterator it = source.begin(); it != source.end(); ++it) {
    if (*it == ptrn) {
      rtn.push_back(i);
    };
    i += 1;
  };
  if (rtn.size() == 0) {
    rtn = {-1};
  };
  return rtn;
};

template <typename T> vector<T> unique(vector<T> &x) {
  vector<T> rtn = {x[0]};
  bool evr;
  for (typename vector<T>::iterator it = x.begin() + 1; it != x.end(); ++it) {
    evr = 0;
    for (typename vector<T>::iterator it2 = rtn.begin(); it2 != rtn.end(); ++it2) {
       if (*it2 == *it) {
         evr = 1;
         break;
       };
    };
    if (!evr) {
      rtn.push_back(*it);
    };
  };
  return rtn;
};


template <typename T, typename T2> vector<int> grepl(vector<T> &source, T2 &ptrn) {
  vector<int> rtn;
  rtn.resize(source.size());
  int i = 0;
  for (typename vector<T>::iterator it = source.begin(); it != source.end(); ++it) {
    if (*it == ptrn) {
      rtn[i] = 1;
    } else {
      rtn[i] = 0;
    };
    i++;
  };
  return rtn;
};

template <typename T> vector<T> reverse_out(vector<T> &x) {
  const int n = x.size() / 2;
  vector<T> rtn;
  rtn.resize(x.size());
  if (x.size() % 2 != 0) {
    rtn[n] = x[n];
  };
  const int spv = x.size() - 1;
  for (int i = 0; i < n; ++i) {
    rtn[i] = x[spv - i];
    rtn[spv - i] = x[i];
  };
  return rtn;
};

template <typename T> void reverse_in(vector<T> &x) {
  const int n = x.size() / 2;
  const int spv = x.size() - 1;
  T ref;
  for (int i = 0; i < n; ++i) {
    ref = x[i];
    x[i] = x[spv - i];
    x[spv - i] = ref;
  };
};

template <typename T> vector<T> rep_from_var(T &x, int &hmn) {
  vector<T> rtn;
  rtn.resize(hmn);
  for (int i = 0; i < hmn; ++i) {
    rtn[i] = x;
  };
  return rtn;
};

template <typename T> vector<T> rep(T x, int hmn) {
  vector<T> rtn;
  rtn.resize(hmn);
  for (int i = 0; i < hmn; ++i) {
    rtn[i] = x;
  };
  return rtn;
};

template <typename T> vector<T> reverse_out_standard(vector<T> &x) {
  vector<T> rtn;
  const int n = x.size();
  rtn.resize(n);
  const int spv = n - 1;
  for (int i = 0; i < n; ++i) {
    rtn[i] = x[spv - i];
  };
  return rtn;
};

template <typename T, typename T2, typename T3> vector<T> seq(T from, T2 const &to, T3 const &by) {
  const int n = (to - from) / by;
  vector<T> rtn;
  rtn.resize(n + 1);
  rtn[0] = from;
  from += by;
  for (int i = 1; i <= n; ++i) {
    rtn[i] = from;
    from += by;
  };
  return rtn;
};

template <typename TB> class Compv {
  private: 
    vector<TB> ref_vec;
    vector<bool> comp_v;
    int ref_lngth;
 
  public:
    void to_comp() {};
     
    template <typename T, typename... T2> void to_comp(vector<T>& var1, vector<T2>&... var2)
    {
      for (int i = 0; i < ref_lngth; ++i) {
        if (var1[i] != ref_vec[i] & comp_v[i] != 0) {
          comp_v[i] = 0;
        };
      };
      to_comp(var2...);
    };

    void assign_comp_v() {
      for (vector<bool>::iterator i = comp_v.begin(); i != comp_v.end(); ++i) {
        *i = 1;
      };
    };

    vector<bool> access_comp_v() {
      return comp_v;
    };

    void reinitiate(vector<TB> &x) {
      ref_lngth = x.size();
      for (int i = 0; i < ref_lngth; ++i) {
        comp_v[i] = 1;
      };
      bool shrk = 0;
      if (ref_vec > x) { 
        shrk = 1;
      };
      ref_vec = x;
      if (shrk) {
        ref_vec.shrink_to_fit();
      }
    };

    Compv(vector<TB> &x) {
      ref_lngth = x.size();
      comp_v.resize(ref_lngth, 1);
      ref_vec = x;
    };

    ~Compv() {}; 
};


