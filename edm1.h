#include <iostream>
#include <vector>
#include <typeinfo>
#include <fstream>

template <typename T> float mod(T &dividend, T &divider) {
  int x = dividend / divider;
  return dividend - x * divider;
};

template <typename T> T sum(std::vector<T> &x) {
  T rtn = 0;
  for (typename std::vector<T>::iterator it = x.begin(); it != x.end(); ++it) {
    rtn += *it;
  }
  return rtn;
};

template <typename T> T mean(std::vector<T> &x) {
  float rtn = 0;
  for (typename std::vector<T>::iterator it = x.begin(); it != x.end(); ++it) {
    rtn += *it;
  }
  return rtn / x.size();
};

template <typename T, typename T2> int matchl(std::vector<T> &source, T2 &ptrn) {
  for (typename std::vector<T>::iterator i = source.begin(); i != source.end(); ++i) {
    if (*i == ptrn) {
      return 1;
    };
  };
  return 0;
};

template <typename T, typename T2> int match(std::vector<T> &source, T2 &ptrn) {
  int cnt = 0;
  for (typename std::vector<T>::iterator i = source.begin(); i != source.end(); ++i) {
    if (*i == ptrn) {
      return cnt;
    };
    cnt += 1;
  };
  return -1;
};

template <typename T> T min(std::vector<T> &x) {
  T rtn = x[0];
  for (typename std::vector<T>::iterator it = x.begin() + 1; it != x.end(); ++it) {
    if (rtn > *it) {
      rtn = *it;
    };
  };
  return rtn;
};

template <typename T> T max(std::vector<T> &x) {
  T rtn = x[0];
  for (typename std::vector<T>::iterator it = x.begin() + 1; it != x.end(); ++it) {
    if (rtn < *it) {
      rtn = *it;
    };
  };
  return rtn;
};

template <typename T> T match_max(std::vector<T> &x) {
  T cvl = x[0];
  int i = 1;
  int rtn = 0;
  for (typename std::vector<T>::iterator it = x.begin() + 1; it != x.end(); ++it) {
    if (cvl < *it) {
      cvl = *it;
      rtn = i;
    };
    i += 1;
  };
  return rtn;
};

template <typename T> T match_min(std::vector<T> &x) {
  T cvl = x[0];
  int i = 1;
  int rtn = 0;
  for (typename std::vector<T>::iterator it = x.begin() + 1; it != x.end(); ++it) {
    if (cvl > *it) {
      cvl = *it;
      rtn = i;
    };
    i += 1;
  };
  return rtn;
};

template <typename T, typename T2> auto grep(std::vector<T> &source, T2 &ptrn) {
  std::vector<int> rtn;
  int i = 0;
  for (typename std::vector<T>::iterator it = source.begin(); it != source.end(); ++it) {
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

template <typename T> std::vector<T> unique(std::vector<T> &x) {
  std::vector<T> rtn = {x[0]};
  typename std::vector<T>::iterator it2;
  bool evr;
  for (typename std::vector<T>::iterator it = x.begin() + 1; it != x.end(); ++it) {
    evr = 0;
    for (it2 = rtn.begin(); it2 != rtn.end(); ++it2) {
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

template <typename T, typename T2> std::vector<int> grepl(std::vector<T> &source, T2 &ptrn) {
  std::vector<int> rtn;
  rtn.resize(source.size());
  int i = 0;
  for (typename std::vector<T>::iterator it = source.begin(); it != source.end(); ++it) {
    if (*it == ptrn) {
      rtn[i] = 1;
    } else {
      rtn[i] = 0;
    };
    i++;
  };
  return rtn;
};

template <typename T> std::vector<T> reverse_out(std::vector<T> &x) {
  const int n = x.size() / 2;
  std::vector<T> rtn;
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

template <typename T> void reverse_in(std::vector<T> &x) {
  const int n = x.size() / 2;
  const int spv = x.size() - 1;
  T ref;
  for (int i = 0; i < n; ++i) {
    ref = x[i];
    x[i] = x[spv - i];
    x[spv - i] = ref;
  };
};

template <typename T> std::vector<T> rep_from_var(T &x, int &hmn) {
  std::vector<T> rtn;
  rtn.resize(hmn);
  for (int i = 0; i < hmn; ++i) {
    rtn[i] = x;
  };
  return rtn;
};

template <typename T> std::vector<T> rep(T x, int hmn) {
  std::vector<T> rtn;
  rtn.resize(hmn);
  for (int i = 0; i < hmn; ++i) {
    rtn[i] = x;
  };
  return rtn;
};

template <typename T> std::vector<T> reverse_out_standard(std::vector<T> &x) {
  std::vector<T> rtn;
  const int n = x.size();
  rtn.resize(n);
  const int spv = n - 1;
  for (int i = 0; i < n; ++i) {
    rtn[i] = x[spv - i];
  };
  return rtn;
};

template <typename T, typename T2, typename T3> std::vector<T> seq(T from, T2 const &to, T3 const &by) {
  const int n = (to - from) / by;
  std::vector<T> rtn;
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
    std::vector<TB> ref_vec;
    std::vector<bool> comp_v;
    int ref_lngth;
 
  public:
    void to_comp() {};
     
    template <typename T, typename... T2> void to_comp(std::vector<T>& var1, std::vector<T2>&... var2)
    {
      for (int i = 0; i < ref_lngth; ++i) {
        if (var1[i % ref_lngth] != ref_vec[i] & comp_v[i] != 0) {
          comp_v[i] = 0;
        };
      };
      to_comp(var2...);
    };

    void assign_comp_v() {
      for (std::vector<bool>::iterator i = comp_v.begin(); i != comp_v.end(); ++i) {
        *i = 1;
      };
    };

    std::vector<bool> access_comp_v() {
      return comp_v;
    };

    void reinitiate(std::vector<TB> &x) {
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

    Compv(std::vector<TB> &x) {
      ref_lngth = x.size();
      comp_v.resize(ref_lngth, 1);
      ref_vec = x;
    };

    ~Compv() {}; 
};

bool any(std::vector<bool> &x) {
  for (std::vector<bool>::iterator i = x.begin(); i != x.end(); ++i) {
    if (*i == 1) {
      return 1;
    };
  };
  return 0;
};

bool all(std::vector<bool> &x) {
  for (std::vector<bool>::iterator i = x.begin(); i != x.end(); ++i) {
    if (*i == 0) {
      return 0;
    };
  };
  return 1;
};

template <typename T, typename T2> std::vector<bool> comp2(std::vector<T> &x, std::vector<T2> &x2) {
  std::vector<bool> rtn_v;
  rtn_v.resize(x.size(), 1);
  int n = x2.size();
  for (int i = 0; i < x.size(); ++i) {
    if (x[i] != x2[i % n]) {
      rtn_v[i] = 0;
    };
  };
  return rtn_v;
};

int int_lngth(int &x) {
  float x2 = x;
  int i = 0;
  while (x2 >= 1) {
    x2 /= 10;
    i +=1;
  };
  return i;
}

int edm1_si(std::string &x) {
  int rtn = int(x[0]) - 48;
  int n = x.size();
  for (int i = 1; i < n; ++i) {
    rtn *= 10;
    rtn += (int(x[i]) - 48);
  };
  return rtn;
}

float edm1_sf2(std::string &x) {
  float rtn = int(x[0]) - 48;
  int n = x.size();
  int i = 1;
  int m = 1;
  while (int(x[i]) != 46) {
    rtn *= 10;
    rtn += (int(x[i]) - 48);
    i += 1;
  };
  i += 1;
  while (i < n) {
    m *= 10;
    rtn *= 10;
    rtn += (int(x[i]) - 48);
    i += 1;
  };
  return rtn / m;
};

float edm1_sf(std::string &x) {
  float rtn = int(x[0]) - 48;
  int n = x.size();
  int i = 1;
  int m = 1;
  while (int(x[i]) != 46) {
    rtn *= 10;
    rtn += (int(x[i]) - 48);
    i += 1;
  };
  i += 1;
  float c;
  while (i < n) {
    m *= 10;
    rtn += (float(x[i]) - 48) / m;
    i += 1;
  };
  return rtn;
};

double edm1_sd(std::string &x) {
  double rtn = int(x[0]) - 48;
  int n = x.size();
  int i = 1;
  int m = 1;
  while (int(x[i]) != 46) {
    rtn *= 10;
    rtn += (int(x[i]) - 48);
    i += 1;
  };
  i += 1;
  while (i < n) {
    m *= 10;
    rtn *= 10;
    rtn += (int(x[i]) - 48);
    i += 1;
  };
  return rtn / m;
};

template <typename T> void sort_desc_in(std::vector<T> &x) {
  int n = x.size();
  int i = 1;
  T ref;
  while (i < n) {
    if (x[i] > x[i - 1]) {
      ref = x[i];
      x[i] = x[i - 1];
      x[i - 1] = ref;
      if (i > 1) {
        i-= 1;
      };
    } else {
      i+= 1;
    };
  };
};

template <typename T> void sort_asc_in(std::vector<T> &x) {
  int n = x.size();
  int i = 1;
  T ref;
  while (i < n) {
    if (x[i] < x[i - 1]) {
      ref = x[i];
      x[i] = x[i - 1];
      x[i - 1] = ref;
      if (i > 1) {
        i-= 1;
      };
    } else {
      i+= 1;
    };
  };
};

template <typename T> std::vector<T> sort_asc_out(std::vector<T> &x) {
  std::vector<T> rtn = x;
  int n = x.size();
  int i = 1;
  T ref;
  while (i < n) {
    if (rtn[i] < rtn[i - 1]) {
      ref = rtn[i];
      rtn[i] = rtn[i - 1];
      rtn[i - 1] = ref;
      if (i > 1) {
        i -= 1;
      } else {
        i += 1;
      };
    } else {
      i += 1;
    };
  };
  return rtn;
};

template <typename T> std::vector<T> sort_desc_out(std::vector<T> &x) {
  std::vector<T> rtn = x;
  int n = x.size();
  int i = 1;
  T ref;
  while (i < n) {
    if (rtn[i] > rtn[i - 1]) {
      ref = rtn[i];
      rtn[i] = rtn[i - 1];
      rtn[i - 1] = ref;
      if (i > 1) {
        i -= 1;
      } else {
        i += 1;
      };
    } else {
      i += 1;
    };
  };
  return rtn;
};

template <typename T> std::vector<std::vector<T>> t(std::vector<std::vector<T>> &x) {
  int nrow = x.size();
  int ncol = x[0].size();
  std::vector<std::vector<T>> matr;
  matr.resize(ncol);
  int i2;
  for (int i = 0; i < ncol; ++i) {
    matr[i].resize(nrow);
    for (i2 = 0; i2 < nrow; ++i2) {
      matr[i][i2] = x[i2][i];
    };
  };
  return matr; 
};

template <typename T> void t_in_square(std::vector<std::vector<T>> &x) {
  T ref;
  int n  = x.size();
  int i2;
  for (int i = 0; i < n; ++i) {
    for (i2 = i + i; i2 < n; ++i2) {
      ref = x[i][i2];
      x[i][i2] = x[i2][i];
      x[i2][i] = ref;
    };
  };
};

template <typename T> void print_matr(std::vector<std::vector<T>> &x) {
  int i;
  int i2;
  int i3;
  int lngth;
  int n = x.size();
  int n2 = x[0].size();
  std::cout << "   ";
  for (i = 0; i < n; ++i) {
    lngth = std::to_string(i).length();
    for (i3 = 0; i3 < 8 - lngth; ++i3) {
      std::cout << " ";
    };
    std::cout << "[" << i << "]";
  };
  std::cout << "\n";
  for (int i2 = 0; i2 < n2; ++i2) {
    std::cout << ":" << i2 << ":";
    for (i = 0; i < n; ++i) {
      if (i != 0) {
        for (i3 = 0; i3 < std::to_string(i2).length() - 1; ++i3) {
          std::cout << " "; 
        };
      };
      lngth = std::to_string(x[i][i2]).length() + std::to_string(i2).length() - 1;
      for (i3 = 0; i3 < 10 - lngth; ++i3) {
        std::cout << " ";
      };
      std::cout << x[i][i2];
    };
    std::cout << "\n";
  };
};

template <typename T> void abs_matrin(std::vector<std::vector<T>> &x) {
  typename std::vector<T>::iterator i2;
  for (typename std::vector<std::vector<T>>::iterator i = x.begin(); i != x.end(); ++i) {
    for (i2 = i->begin(); i2 != i->end(); ++i2) {
      if (*i2 < 0) {
        *i2 *= -1;
      };
    };
  };
};

template <typename T> std::vector<std::vector<T>> abs_matrout(std::vector<std::vector<T>> &x) {
  std::vector<std::vector<T>> rtn = x;
  int i2 = 0;
  int n = x.size();
  int n2 = x[0].size();
  for (int i = 0; i < n; ++i) {
    for (i2 = 0; i2 < n2; ++i2) {
      if (x[i][i2] < 0) {
        rtn[i][i2] = -1 * x[i][i2];
      };
    };
  };
  return rtn;
};

template <typename T> void abs_vin(std::vector<T> &x) {
  for (typename std::vector<T>::iterator i = x.begin(); i != x.end(); ++i) {
    if (*i < 0) {
      *i *= -1;
    };
  };
};

template <typename T> std::vector<T> abs_vout(std::vector<T> &x) {
  std::vector<T> rtn = x;
  for (typename std::vector<T>::iterator i = rtn.begin(); i != rtn.end(); ++i) {
    if (*i < 0) {
      *i *= -1;
    };
  };
  return rtn;
};

template <typename T> std::vector<T> abs_voutb(std::vector<T> &x) { //index approach
  std::vector<T> rtn = x;
  int n = x.size();
  for (int i = 0; i < n; ++i) {
    if (x[i] < 0) {
      rtn[i] *= -1;
    };
  };
  return rtn;
};

template <typename T> void print_nvec(std::vector<T> &x) {
  int n = x.size();
  int r = 1;
  int i;
  int cmax = 1;
  int cl;
  for (i = 0; i < n; ++i) {
    cl = std::to_string(x[i]).length();
    if (cl > cmax) {
      cmax = cl;
    };
  }; 
  int ref_delta = std::to_string(n).length();
  for (i = 0; i < ref_delta - 1; ++i) {
    std::cout << " ";
  };
  std::cout << ":" << 0 << ": ";
  for (i = 0; i < n; ++i) {
    if ((i + 1) % 25 == 0) {
      std::cout << "\n";
      for (cl = 0; cl < ref_delta - std::to_string(r * 25).length(); ++cl) {
        std::cout << " ";
      };
      std::cout << ":" << r * 25 << ": ";
      r += 1;
      if ((i + 1) == n) {
        std::cout << x[i];
      };
    } else {
      std::cout << x[i] << " ";
      for (cl = 0; cl < cmax - std::to_string(x[i]).length(); ++cl) {
        std::cout << " ";
      };
    };
  };
  std::cout << "\n";
};

void print_svec(std::vector<std::string> &x) {
  int n = x.size();
  int r = 1;
  int i;
  int cmax = 1;
  int cl;
  std::string ref_str;
  for (i = 0; i < n; ++i) {
    ref_str = x[i];
    cl = ref_str.length();
    if (cl > cmax) {
      cmax = cl;
    };
  }; 
  int ref_delta = std::to_string(n).length();
  for (i = 0; i < ref_delta - 1; ++i) {
    std::cout << " ";
  };
  std::cout << ":" << 0 << ": ";
  for (i = 0; i < n; ++i) {
    if ((i + 1) % 18 == 0) {
      std::cout << "\n";
      for (cl = 0; cl < ref_delta - std::to_string(r * 18).length(); ++cl) {
        std::cout << " ";
      };
      std::cout << ":" << r * 18 << ": ";
      r += 1;
      if ((i + 1) == n) {
        std::cout << x[i];
      };
    } else {
      std::cout << x[i] << " ";
      ref_str = x[i];
      for (cl = 0; cl < cmax - ref_str.length(); ++cl) {
        std::cout << " ";
      };
    };
  };
  std::cout << "\n";
};


