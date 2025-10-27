#include <iomanip>
#include <iostream>
#include <vector>
#include <unordered_set>
#include <unordered_map>
#include <deque>
#include <cmath>
#include <chrono>
#include <thread>
#include <map>
#include <fstream>
#include <typeinfo>
#include <stdexcept>
#include <regex>

#if __cplusplus >= 202002L
#include <variant>
#include <span>
#endif

#ifdef __CUDACC__

#include <cublas_v2.h>
#include <cuda_runtime.h>
#include <type_traits>

#endif

#if 0
//@I Stylished documentation is available <a href="https://julienlargetpiet.tech/static/files/fulgurance.html">here</a>
//@I In current development.
//@I This framework provides functions for statistical analysis, machine learning, parsing and data manipulation with its own implementation of matrices and dataframes. Other tools can be found at fulgurance_tools part.
//@I The framework is developped with C++ 14 but should work properly with 11 and 17 and furthers.
//@G2 Philosophy
//@I Dataframes implementation is a class. All functions that will transform 'voidly' (internaly) the relative data are built in the class. All functions that copy and transform the relative data are extern to classes.
//@I Matrices are built with the Matrix class.
//@X

//@L1 Commun functions  
//@L2 On elements
//@L3 Standard operations

//@T mod
//@U template &lt;typename T&gt; double mod(T &amp;dividend, T &amp;divider)
//@X
//@D Returns the mod of 2 number (int, float or double)
//@A a : is an the dividend (int, float, double)
//@A b : is the divider (int, float, double)
//@X
//@E float a = 45.216;
//@E float b = 3.2164;
//@E mod(a, b)
//@E 0.186401
//@X
#endif

template <typename T> double mod(T &dividend, T &divider) {
  int x = dividend / divider;
  return dividend - x * divider;
};

#if 0
//@T int_lngth
//@U int int_lngth(const int &x)
//@X
//@D Returns the length of an int.
//@A x : is an int
//@X
//@E int a = 896;
//@E int_lngth(a);
//@E 3
//@X
#endif 

int int_lngth(const int &x) {
  float x2 = x;
  int i = 0;
  while (x2 >= 1) {
    x2 /= 10;
    i +=1;
  };
  return i;
}

#if 0
//@T roundout
//@U template &lt;typename T&gt; T roundout(T x, int n)
//@X
//@D Returns a rounded value with decimal precision.
//@A x : is an int, float, double
//@A n : is an int indicating the decimal precision
//@X
//@E float x = 34.476;
//@E int n = 2;
//@E float out = roundout(x, n);
//@E 34.48
//@E n = 0;
//@E out = roundout(x, n);
//@E 34
//@E n = -1;
//@E out = roundout(x, n)
//@E 30
//@X
#endif

template <typename T> T roundout(T x, int n) {
  unsigned int mlt = 1;
  int binc;
  if (n > -1) {
    for (unsigned int i = 0; i < n; ++i) {
      mlt *= 10;
    };
    x *= mlt;
    binc = x;
    if (x - binc > 0.5) {
      binc += 1;
    };
    return (double)binc / mlt;
  } else {
    n *= -1;
    for (unsigned int i = 0; i < n; ++i) {
      mlt *= 10;
    };
    x /= mlt;
    binc = x;
    if (x - binc > 0.5) {
      binc += 1;
    };
    return (double)binc * mlt;
  };
};

#if 0
//@T roundin
//@U template &lt;typename T&gt; void roundin(T &x, int n)
//@X
//@D Transforms the input value to a rounded value with decimal precision.
//@A x : is an int, float, double
//@A n : is an int indicating the decimal precision
//@X
//@E float x = 34.476
//@E int n = 2;
//@E roundin(x, n);
//@E 34.48
//@E n = 0;
//@E x = 67.754;
//@E roundin(x, n);
//@E 68
//@E n = -1;
//@E roundin(x, n);
//@E 70
//@X
#endif

template <typename T> void roundin(T &x, int n) {
  unsigned int mlt = 1;
  int binc;
  if (n > -1) {
    for (unsigned int i = 0; i < n; ++i) {
      mlt *= 10;
    };
    x *= mlt;
    binc = x;
    if (x - binc > 0.5) {
      binc += 1;
    };
    x = (double)binc / mlt;
  } else {
    n *= -1;
    for (unsigned int i = 0; i < n; ++i) {
      mlt *= 10;
    };
    x /= mlt;
    binc = x;
    if (x - binc > 0.5) {
      binc += 1;
    };
    x = (double)binc * mlt;
  };
};

#if 0
//@T randint
//@U auto randint(const int &min, const int max, int seed = -1)
//@X
//@D Returns a pseudo-random number between min and max.
//@A min : is an int
//@A max : is a max
//@A seed : is an int that determines the pseudo-random output, defaults to -1, so the seed will be randomly picked up by default, if you want to determine the output, choose a seed between 0 and 9.
//@X
//@E int min = -300;
//@E int max = 100;
//@E randint(min, max);
//@E -14
//@E randint(min, max);
//@E -231
//@E // If you want to generate a float just do:
//@E double x = randint(min, max);
//@E min = 0;
//@E max = 900;
//@E x += randint(min, max) / 1000;
//@E -13.257
//@X
#endif 

int randint(const int &min, const int max, int seed = -1) {
  unsigned int cnt = 0;
  unsigned long int mlc = 1;
  unsigned int offset;
  if (abs(max) > abs(min)) {
    offset = abs(max);
  } else {
    offset = abs(min);
  };
  while (offset >= 1) {
    offset /= 10;
    cnt += 1;
  };
  double rtn;
  unsigned int cur_val;
  long unsigned int cur_valint;
  unsigned int cnt2 = 0;
  std::vector<int> vec = {4, 8, 1, 2, 9, 0, 5, 3, 6, 7};
  unsigned int addr;
  unsigned int delta = (max - min) + 1;
  unsigned int post_rtn;
  if (seed == -1) {
    auto now = std::chrono::system_clock::now();
    auto duration = now.time_since_epoch();
    rtn = std::chrono::duration_cast<std::chrono::milliseconds>(duration).count();
    rtn /= 10;
    mlc = rtn;
    rtn -= mlc;
    rtn *= 10;
    post_rtn = rtn;
    if (rtn - post_rtn > 0.5) {
      post_rtn += 1;
    };
  } else {
    rtn = (int)seed;
  };
  if (mlc % 9 == 0) {
    addr = 3;
  } else if (mlc % 7 == 0) {
    addr = 4;
  } else if (mlc % 8 == 0) {
    addr = 7;
  } else if (mlc % 6 == 0) {
    addr = 9;
  } else if (mlc % 3 == 0) {
    addr = 13;
  } else if (mlc % 4 == 0) {
    addr = 1;
  } else if (mlc % 2 == 0) { 
    addr = 8;
  } else {
    addr = 5;
  };
  cnt2 = 1;
  cur_val = rtn;
  while (cnt2 < cnt) {
    cur_valint = pow(cur_val, 2);
    cur_val = vec[(cur_valint + addr) % 10];
    post_rtn *= 10;
    post_rtn += cur_val;
    cnt2 += 1;
  };
  cur_valint = post_rtn;
  return (cur_valint % delta) + min;
};

#if 0
//@T logn
//@U template &lt;typename T, typename T2&gt; double logn(T &val, T2 &base) 
//@X
//@D Returns the logarithm of any positive number to any base. This generalizes the <code>log(value) / log(base)</code> method.
//@A val : is the value of the logarith base n (must be positive)
//@A base : is the base of the logarithm
//@X
//@E double val = 2.63;
//@E int base = 10;
//@E logn(val, base);
//@E 0.419956 
//@E base = 2;
//@E 1.39506 
//@X
#endif

template <typename T, typename T2> double logn(T &val, T2 &base) {
  return log(val) / log(base);
};

#if 0
//@T Facto
//@U unsigned int Facto(unsigned int x)
//@X
//@D Returns the factorial of a positive integer.
//@A x : is a unsigned integer
//@X
//@E Facto(7);
//@E 5040
//@E Facto(0);
//@E 1
//@X
#endif 

unsigned int Facto(unsigned int x) {
  if (x == 0) {
    return 1;
  };
  unsigned int rtn = x;
  x -= 1;
  while (x > 1) {
    rtn *= x;
    x -= 1;
  };
  return rtn;
};

#if 0
//@T Comb
//@U double Comb(double r, double n)
//@X
//@D Returns the result of the combination formula for given parameters.
//@A r : is the number of objects choosen among the set 
//@A n : is the number of objects in the set
//@X
//@E Comb(2, 5);
//@E 10
//@E Comb(5, 12);
//@E 792
//@X
#endif 

double Comb(double r, double n) {
  if ((long unsigned int)n % 2 == 0) {
    if (r > n / 2) {
      r = n - r;
    };
  } else if ((long unsigned int)n / 2 + 1 < r) {
    r = n - r;
  };
  double rslt = n / r;
  r -= 1;
  n -= 1;
  while (r > 0) {
    rslt *= (n / r);
    r -= 1;
    n -= 1;
  };
  return rslt;
};

#if 0
//@L3 String to int, float, double

//@T si
//@U int si(const std::string &x)
//@X
//@D Returns a std::string that can be converted to an int, to an int.
//@A x : is a stl string that can be converted to an int
//@X
//@E std::string a = "341";
//@E int out = si(a);
//@E 341
//@X
#endif 

int si(const std::string &x) {
  int rtn = int(x[0]) - 48;
  const int n = x.size();
  for (int i = 1; i < n; ++i) {
    rtn *= 10;
    rtn += (int(x[i]) - 48);
  };
  return rtn;
}

#if 0
//@T sf
//@U float sf(const std::string &x)
//@X
//@D Returns a converted std::string that can be converted to a float, to a float. Produces the same results than <code>stof</code>.
//@A x : is a stl string that can be converted to a float
//@X
//@E std::string a = "44.23";
//@E float out = sf(a);
//@E 44.23
//@X
#endif

float sf(const std::string &x) { // same results as stof
  float rtn = int(x[0]) - 48;
  const int n = x.size();
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
    rtn += (float(x[i]) - 48) / m;
    i += 1;
  };
  return rtn;
};

#if 0
//@T sf2
//@U float sf2(const std::string &x)
//@X
//@D Returns a converted std::string that can be converted to a float, to a float. Uses another algorithm than <code>edm1_sf</code>.
//@A x : is a stl string that can be converted to a float
//@X
//@E std::string a = "44.23";
//@E float out = sf2(a);
//@E 44.23
//@X
#endif

float sf2(const std::string &x) {
  float rtn = int(x[0]) - 48;
  const int n = x.size();
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

#if 0
//@T stod
//@U double stod(const std::string &x)
//@X
//@D Returns a converted std::string, that can be converted to a double, to a double.
//@A x : is a stl string
//@X 
//@E std::string a = "4566.132214";
//@E double out = stod(a);
//@E 4566.132214
//@X
#endif

double stod(const std::string &x) {
  double rtn = int(x[0]) - 48;
  const int n = x.size();
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

#if 0
//@L3 Int, double, to string

//@T itos
//@U std::string itos(unsigned int x) 
//@X
//@D Returns the input integer as a std string.
//@A : is an unsigned int
//@X
//@E itos(45897);
//@E "45897"
//@X
#endif

std::string itos(unsigned int x) {
  unsigned int cnt;
  unsigned int mlt_val = 1;
  std::string rtn_str = "";
  while (mlt_val <= x) {
    cnt = 0;
    while (x % (10 * mlt_val) != 0) {
      x = x - mlt_val;
      cnt += 1;
    };
    mlt_val *= 10;
    rtn_str = char(cnt + 48) + rtn_str;
  };
  return rtn_str;
};

#if 0
//@L2 Can be num ?

//@T can_be_nb
//@U bool can_be_nb(std::string &x)
//@X
//@D Returns a boolean, 1 if the input <code>std::string</code> can be converted to a number (int, float...), 0 if not.
//@A x : is the input std::string 
//@X
//@E std::string inpt_str = "15.69596";
//@E bool rslt = can_be_nb(inpt_str);
//@E std::cout &lt;&lt; rslt &lt;&lt; "\n";
//@E 
//@E 1
//@E
//@E inpt_str = "1569596";
//@E rslt = can_be_nb(inpt_str);
//@E std::cout &lt;&lt; rslt &lt;&lt; "\n";
//@E 
//@E 1
//@E
//@E inpt_str = "1569T596";
//@E rslt = can_be_nb(inpt_str);
//@E std::cout &lt;&lt; rslt &lt;&lt; "\n";
//@E
//@E 0
//@E
//@E inpt_str = "15.69.596";
//@E rslt = can_be_nb(inpt_str);
//@E std::cout &lt;&lt; rslt &lt;&lt; "\n";
//@E
//@E 0
//@E
//@X
#endif

bool can_be_nb(std::string &x) {
  const unsigned int n = x.length();
  std::string numeric_v = "0123456789";
  if (x[0] == '.' || x[n - 1] == '.') {
    return 0;
  };
  bool alrd_point = 0;
  unsigned int i2;
  char cur_chr;
  for (unsigned int i = 0; i < n; ++i) {
    if (x[i] == '.') {
      if (!alrd_point) {
        alrd_point = 1;
      } else {
        return 0;
      };
    } else {
      cur_chr = x[i];
      i2 = 0;
      while (i2 < 10) {
        if (cur_chr == numeric_v[i2]) {
          break;
        };
        i2 += 1;
      };
      if (i2 == 10) {
        return 0;
      };
    };
  };
  return 1;
};

#if 0
//@T can_be_flt_dbl
//@U bool can_be_flt_dbl(std::string &x)
//@X
//@D Returns a boolean, 1 if the input <code>std::string</code> can be converted to a float or double, 0 if not.
//@A x : is the input std::string 
//@X
//@E std::string inpt_str = "15.69596";
//@E bool rslt = can_be_flt_dbl(inpt_str);
//@E std::cout &lt;&lt; rslt &lt;&lt; "\n";
//@E 
//@E 1
//@E
//@E inpt_str = "1569596";
//@E rslt = can_be_flt_dbl(inpt_str);
//@E std::cout &lt;&lt; rslt &lt;&lt; "\n";
//@E 
//@E 0
//@E
//@E inpt_str = "1569T596";
//@E rslt = can_be_flt_dbl(inpt_str);
//@E std::cout &lt;&lt; rslt &lt;&lt; "\n";
//@E
//@E 0
//@E
//@E inpt_str = "15.69.596";
//@E rslt = can_be_flt_dbl(inpt_str);
//@E std::cout &lt;&lt; rslt &lt;&lt; "\n";
//@E
//@E 0
//@E
//@X
#endif

bool can_be_flt_dbl(std::string &x) {
  const unsigned int n = x.length();
  std::string numeric_v = "0123456789";
  if (x[0] == '.' || x[n - 1] == '.') {
    return 0;
  };
  bool alrd_point = 0;
  unsigned int i2;
  char cur_chr;
  for (unsigned int i = 0; i < n; ++i) {
    if (x[i] == '.') {
      if (!alrd_point) {
        alrd_point = 1;
      } else {
        return 0;
      };
    } else {
      cur_chr = x[i];
      i2 = 0;
      while (i2 < 10) {
        if (cur_chr == numeric_v[i2]) {
          break;
        };
        i2 += 1;
      };
      if (i2 == 10) {
        return 0;
      };
    };
  };
  if (alrd_point) {
    return 1;
  } else {
    return 0;
  };
};

#if 0
//@L2 On std::vector&lt;Type&gt;
//@L3 Statistical functions

//@T sum
//@U template &lt;typename T&gt; T sum(const std::vector&lt;T&gt; &x)
//@X
//@D Returns the sum of all elements in a vector (int, float, double, bool).
//@A x : is a stl vector (int, float, double, bool)
//@X
//@E std::vector&lt;double&gt; vec = {1.434, 22.3322, 32423.097};
//@E double out = sum(vec);
//@E 32446.8632 
//@X
#endif 

template <typename T> double sum(const std::vector<T> &x) {
  double rtn = 0;
  for (typename std::vector<T>::const_iterator it = x.begin(); it != x.end(); ++it) {
    rtn += *it;
  };
  return rtn;
};

#if 0
//@T Mean
//@U template &lt;typename T&gt; T Mean(const std::vector&lt;T&gt; &x) 
//@X
//@D Returns the mean of all elements in a vector (int, float, double, bool).
//@A x : is a stl vector (int, float, double, bool)
//@X
//@E std::vector&lt;int&gt; vec = {1, 4, 2};
//@E double out = Mean(vec);
//@E 2.333333
//@X
#endif

template <typename T> T Mean(const std::vector<T> &x) {
  float rtn = 0;
  for (typename std::vector<T>::const_iterator it = x.begin(); it != x.end(); ++it) {
    rtn += *it;
  }
  return rtn / x.size();
};

#if 0
//@T quantile
//@U template &lt;typename T, typename T2&gt; double quantile(std::vector&lt;T&gt; &x, T2 &prob, double precision = 0.001)
//@X
//@D Returns the quantile value for a given probability between 0 and 1 for an input stl vector (int, float, double, bool). If you just want to calculate median, the <code>med()</code> function is more straight forward.
//@A x : stl vector (int, float, double, bool), must be ascendly sorted
//@A prob : is the probability(float, double)
//@A precision : is a double value representing the accuracy of the result. The lower the value is, higher the accuracy will be.
//@X
//@E std::vector&lt;int&gt; vec = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
//@E std::vector&lt;int&gt; vec2 = {1, 2, 3, 4};
//@E double prob = 0.89;
//@E quantile(vec2, prob);
//@E 3.67188
//@E prob = 0.65;
//@E quantile(vec, prob);
//@E 6.84375 
//@X
#endif

template <typename T, typename T2> double quantile(std::vector<T> &x, T2 &prob, double precision = 0.001) {
  double n = x.size();
  double pre_rnd = (n - 1) * prob;
  unsigned int idx = pre_rnd;
  if (pre_rnd - idx > 0.5) {
    idx += 1;
  };
  const unsigned int fidx = idx;
  double l_lim = prob - precision;
  double h_lim = prob + precision;
  double cur_vl = idx / (n - 1);
  double rtn_val = x[idx];
  double rtn_val2;
  double divider = 2;
  if (cur_vl < l_lim) {
    rtn_val2 = (x[idx + 1] - x[idx]) / divider;
  } else if (cur_vl > l_lim) {
    rtn_val2 = (x[idx] - x[idx - 1]) / divider;
  };
  while (cur_vl < l_lim || cur_vl > h_lim) {
    if (cur_vl < l_lim) {
      idx += idx;
      idx += 1;
      n += (n - 1);
      rtn_val += rtn_val2;
    } else {
      idx += idx;
      idx -= 1;
      n += (n - 1);
      rtn_val -= rtn_val2;
    };
    cur_vl = idx / (n - 1);
    rtn_val2 /= 2;
  };
  return rtn_val;
};

#if 0
//@T med
//@U template &lt;typename T&gt; double med(std::vector&lt;T&gt; &x)
//@X
//@D Returns the median of a stl vector (int, float, double, bool). 
//@A x : is an stl vector (int, float, double, bool), must be ascendly sorted
//@X
//@E std::vector&lt;int&gt; vec = {1, 2, 3, 4};
//@E double out = med(vec);
//@E 2.5
//@X
#endif

template <typename T> double med(std::vector<T> &x) {
  const unsigned int n = x.size();
  const unsigned int idx = (n - 1) * 0.5;
  if (n % 2 == 0) {
    double rslt = x[idx] + x[idx + 1];
    return rslt / 2;
  } else {
    return(x[idx]);
  };
};

#if 0
//@T cor
//@U template &lt;typename T, typename T2&gt; double cor(const std::vector&lt;T&gt; &x, const std::vector&lt;T2&gt; &x2)
//@X
//@D Returns the correlation between two variables / two stl vectors (int, float, double, bool)
//@A x : is an stl vector (int, float, double, bool)
//@A x2 : is an stl vector (int, float, double, bool)
//@X
//@E std::vector&lt;int&gt; vec1 = {1, 2, 3, 4, 5, 6};
//@E std::vector&lt;int&gt; vec2 = {-6, -5, -4, -3, -2, -1};
//@E double out = cor(vec1, vec2);
//@E 1
//@X
#endif

template <typename T, typename T2> double cor(const std::vector<T> &x, const std::vector<T2> &x2) {
  double m1 = x[0];
  double m2 = x2[0];
  int n = x.size();
  int i;
  for (i = 1; i < n; ++i) {
    m1 += x[i];
    m2 += x2[i];
  };
  m1 /= n;
  m2 /= n;
  double c1 = (x[0] - m1);
  double c2 = (x2[0] - m2);
  double d1 = c1 * c2;
  double s1 = c1 * c1;
  double s2 = c2 * c2;
  for (i = 1; i < n; ++i) {
    c1 = (x[i] - m1);
    c2 = (x2[i] - m2);
    d1 += (c1 * c2);
    s1 += (c1 * c1);
    s2 += (c2 * c2);
  };
  double rtn = d1 / sqrt(s1 * s2);
  return rtn;
};

#if 0
//@T Sd
//@U template &lt;typename T&gt; double Sd(std::vector&lt;T&gt; &x)
//@X
//@D Returns the standard deviation of a stl vector (int, float, double, bool).
//@A x : is an stl vector (int, float, double, bool)
//@X
//@E std::vector&lt;int&gt; vec = {1, 2, 2, 3, 3, 3, 4, 4, 5};
//@E double out = Sd(vec);
//@E 1.224745
//@X
#endif

template <typename T> double Sd(std::vector<T> &x) {
  unsigned int i;
  const double n = x.size();
  double mean = x[0];
  for (i = 1; i < n; ++i) {
    mean += x[i];
  };
  mean /= n;
  double delta_sq = 0;
  for (i = 0; i < n; ++i) {
    delta_sq += pow(x[i] - mean, 2);
  };
  return pow(delta_sq / n, 0.5);
};

#if 0
//@L4 Uniform distribution

//@T dunif
//@U template &lt;typename T&gt; std::vector&lt;double&gt; dunif(std::vector&lt;T&gt; &x, double &min, double &max)
//@X
//@D Returns the probability distribution of the uniform distribution.
//@A x : is a vector containing all the values you want the probability from
//@A min : is the minimum of the uniform distribution 
//@A max : is the maximum of the uniform distribution
//@X
//@E double min = -2;
//@E double max = 10;
//@E std::vector&lt;double&gt; vec = {-7, -2, 3.5, 8, 12, 56};
//@E std::vector&lt;double&gt; out = dunif(vec, min, max);
//@E print_nvec(out);
//@E :0: 0 0.0833333 0.0833333 0.0833333 0 0
//@X
#endif 

template <typename T> std::vector<double> dunif(std::vector<T> &x, double &min, double &max) {
  double cur_prob = 1 / (max - min);
  std::vector<double> rtn_v;
  for (double i : x) {
    if (i >= min & i <= max) {
      rtn_v.push_back(cur_prob);
    } else {
      rtn_v.push_back(0);
    }
  };
  return rtn_v;
};

#if 0
//@T punif
//@U template &lt;typename T&gt; std::vector&lt;double&gt; punif(std::vector&lt;T&gt; &x, double &min, double &max, double step = 0.01)
//@X
//@D Returns the cumulative probablity distribution of the uniform distribution.
//@A x : is a vector containing the values you want the cumulative probability from, must be ascendly sorted
//@A min : is the minimum of the probability distribution
//@A max : is the maximum of the probability distribution
//@A step : the lower it is, the more accurate the result gets
//@X
//@E double min = -2;
//@E double max = 10;
//@E std::vector&lt;double&gt; vec = {-7, -2, 3.5, 8, 12, 56};
//@E std::vector&lt;double&gt; out = punif(vec, min, max);
//@E print_nvec(out);
//@E :0: 0 0.000833333 0.459167 0.834167 1 1
//@X
#endif 

template <typename T> std::vector<double> punif(std::vector<T> &x, double &min, double &max, double step = 0.01) {
  double cur_prob = 0;
  double ref_prob = 1 / (max - min) * step;
  std::vector<double> rtn_v;
  unsigned int i = 0;
  const unsigned int n = x.size();
  while (x[i] < min) {
    i += 1;
    rtn_v.push_back(0);
  };
  double lst_x = x[i];
  while (i < n) {
    if (x[i] <= max) {
      while (lst_x <= x[i]) {
        cur_prob += ref_prob;
        lst_x += step;
      };
      rtn_v.push_back(cur_prob);
    } else {
      while (i < n) {
        rtn_v.push_back(1);
        i+= 1;
      };
      return rtn_v;
    }
    i += 1;
  };
  return rtn_v;
};

#if 0
//@T qunif
//@U std::vector&lt;double&gt; qunif(std::vector&lt;double&gt; &x, double &min, double &max)
//@X
//@D Returns the quantile of the uniform distribution.
//@A x : is the probability vector 
//@A min : is the minimum of the uniform distribution
//@A max : is the maximum of the uniform distribution
//@X
//@E double min = -2;
//@E double max = 10;
//@E std::vector&lt;double&gt; vec = {-7, -2, 3.5, 8, 12, 56};
//@E std::vector&lt;double&gt; vec2 = {0.2, 0.4, 0.5, 0.6, 0.75};
//@E std::vector&lt;double&gt; out = qunif(vec2, min, max);
//@E print_nvec(out);
//@E :0: 3.6 5.2 6 6.8 8
//@X
#endif

std::vector<double> qunif(std::vector<double> &x, double &min, double &max) {
  double coeff = 1 / (max - min);
  std::vector<double> rtn_v;
  for (double i : x) {
    rtn_v.push_back(i / coeff + min);
  };
  return rtn_v;
};

#if 0
//@T runif
//@U std::vector&lt;double&gt; unif(unsigned int &n, double &min, double &max, double noise = 0.1, int seed = -1)
//@X
//@D Returns a stl double vector containing pseudo-random uniform distribution between a min and max.
//@A n : is the number of elements of the output stl vector
//@A min : is the minimum of the uniform distribution
//@A max : is the maximum of the uniform distribution
//@A noise : is the noise in the returnde uniform distribution 
//@A seed : is an int, controlling the output values, defaults to -1, so by default the function returns pseudo-random uniform distribution. If you want to manually control the output, enter a positive int for this parameter.
//@X
//@E unsigned int n = 1500;
//@E double min = 1;
//@E double max = 55;
//@E std::vector&lt;double&gt; out = unif(n, min, max);
//@E print_nvec(out);
//@E :0: 1  1.03701  1.07557  1.10951  1.14757  1.18151  1.21957  1.25351  1.29157  1.32551  1.36357  1.39751  1.43557  1.46951  1.50757  1.54151  1.57957  1.61351  1.65157  1.68551  1.72357  1.75751  1.79557  1.82951  
//@E ...
//@E :1475: 54.1015 54.1396 54.1735 54.2116 54.2455 54.2836 54.3175 54.3556 54.3895 54.4276 54.4615 54.4996 54.5335 54.5716 54.6055 54.6436 54.6775 54.7156 54.7495 54.7876 54.8215 54.8596 54.8935 54.9316 
//@E :1500: 55
//@X
#endif

std::vector<double> runif(unsigned &n, double &min, double &max, double noise = 0.1, int seed = -1) {
  long double step;
  unsigned long int valint = 1;
  unsigned int i;
  if (seed == -1) {
    auto now = std::chrono::system_clock::now();
    auto duration = now.time_since_epoch();
    step = std::chrono::duration_cast<std::chrono::milliseconds>(duration).count();
    step /= 10;
    valint = step;
    step -= valint;
    step *= 10;
    if (step == 0) {
      i = 1;
      while (valint % i != 0) {
        i+= 1;
      };
      step += i;
    };
  } else {
    step = seed;
  };
  double cur_step = (max - min) / n;
  std::vector<double> rtn_v;
  rtn_v.reserve(n);
  std::vector<int> ref_vec = {5, 3, 1, 6, 8, 2, 4, 7, 9}; 
  unsigned int addr;
  if (valint % 9 == 0) {
    addr = 3;
  } else if (valint % 7 == 0) {
    addr = 4;
  } else if (valint % 8 == 0) {
    addr = 7;
  } else if (valint % 6 == 0) {
    addr = 9;
  } else if (valint % 3 == 0) {
    addr = 13;
  } else if (valint % 4 == 0) {
    addr = 1;
  } else if (valint % 2 == 0) { 
    addr = 8;
  } else {
    addr = 5;
  };
  unsigned long int Step = step;
  unsigned int lst_val;
  rtn_v.push_back(min);
  for (i = 1; i < n - 1; ++i) {
    lst_val = ref_vec[Step % 9] + addr;
    rtn_v.push_back(noise * cur_step * sin(lst_val) + min + cur_step * i);
    Step += lst_val;
  };
  rtn_v.push_back(max);
  return rtn_v;
};

#if 0
//@L4 Normal distribution

//@T rnorm
//@U std::vector&lt;double&gt; rnorm(unsigned int &n, double &mean, double &sd, double noise = 0.05, int seed = -1) 
//@X
//@D Returns a pseudo-random normal distribution as a double stl vector. Note, if you can it is preferable to choose the smallest standard deviation possible to increase speed. Example: N(14, 10) -&gt; N(1.4, 1).
//@A n : is the number of elements in the output stl vector
//@A mean : is the mean of the normal distribution
//@A sd : is the standard deviation of the normal distribution
//@A noise : is the noise, defaults to 0.05
//@A seed : is an int that dictates the result, defaults to -1, so by default the output is pseudo-random
//@X
//@E unsigned int n = 10000;
//@E double sd = 250;
//@E double mean = 155;
//@E std::vector&lt;double&gt; out;
//@E double result;
//@E out = rnorm(n, mean, sd);
//@E Sd(out);
//@E 250.6228
//@E Mean(out);
//@E 154.9945
//@M example.jpg 
//@X
#endif 

std::vector<double> rnorm(unsigned int &n, double &mean, double &sd, double noise = 0.05, int seed = -1) {
  long double step;
  unsigned long int valint = 1;
  unsigned int i;
  bool evenval;
  if (n % 2 == 0) {
    evenval = 0;
  } else {
    evenval = 1;
    n += 1;
  };
  if (seed == -1) {
    auto now = std::chrono::system_clock::now();
    auto duration = now.time_since_epoch();
    step = std::chrono::duration_cast<std::chrono::milliseconds>(duration).count();
    step /= 10;
    valint = step;
    step -= valint;
    step *= 10;
    if (step == 0) {
      i = 1;
      while (valint % i != 0) {
        i+= 1;
      };
      step += i;
    };
  } else {
    step = seed;
  };
  std::vector<int> ref_vec = {5, 3, 1, 6, 8, 2, 4, 7, 9}; 
  unsigned int addr;
  long double n2 = n;
  long double prob_step = 1 / n2;
  if (valint % 9 == 0) {
    addr = 3;
  } else if (valint % 7 == 0) {
    addr = 4;
  } else if (valint % 8 == 0) {
    addr = 7;
  } else if (valint % 6 == 0) {
    addr = 9;
  } else if (valint % 3 == 0) {
    addr = 13;
  } else if (valint % 4 == 0) {
    addr = 1;
  } else if (valint % 2 == 0) { 
    addr = 8;
  } else {
    addr = 5;
  };
  std::vector<double> rtn_v = {};
  rtn_v.reserve(n);
  double cur_prob = 0;
  double x_step = 1 / n2;
  double x_step2 = 0;
  unsigned int cur_n = 0;
  unsigned int Step = step;
  double cur_noise;
  double cnst = 1 / (sd * sqrt(2 * M_PI));
  while (cur_n < n) {
    cur_prob += cnst * exp(-0.5 * (x_step2 / sd) * (x_step2 / sd)) * x_step;
    while ((cur_prob - prob_step) >= 0) {
      Step += ref_vec[Step % 9] + addr;
      cur_noise = sin(Step) * noise * x_step2;
      rtn_v.push_back(mean + x_step2 + cur_noise);
      Step += ref_vec[Step % 9] + addr;
      cur_noise = sin(Step) * noise * x_step2;
      rtn_v.push_back(mean - x_step2 + cur_noise);
      cur_prob -= prob_step;
      cur_n += 2;
    };
    x_step2 += x_step;
  };
  if (evenval) {
    rtn_v.pop_back();
  };
  return rtn_v;
};

#if 0
//@T rnorm2 
//@U std::vector&lt;double&gt; rnorm2(unsigned int &n, double &mean, double &sd, double noise = 0.05, int seed = -1)
//@X
//@D Same as <code>norm()</code>, but faster and less accurate.
//@A n : is the number of elements in the output stl vector
//@A mean : is the mean of the normal distribution
//@A sd : is the standard deviation of the normal distribution
//@A noise : is the noise, defaults to 0.05
//@A seed : is an int that dictates the result, defaults to -1, so by default the output is pseudo-random
//@X
//@E unsigned int n = 10000;
//@E double sd = 50;
//@E double mean = 155;
//@E std::vector&lt;double&gt; out;
//@E double result;
//@E out = rnorm2(n, mean, sd);
//@E Sd(out);
//@E 42.06729
//@E Mean(out);
//@E 155.0009
//@M example2.jpg 
//@X
#endif

std::vector<double> rnorm2(unsigned int &n, double &mean, double &sd, double noise = 0.05, int seed = -1) {
  long double step;
  bool evenval;
  if (n % 2 == 0) {
    evenval = 0;
  } else {
    evenval = 1;
  };
  unsigned long int valint = 1;
  unsigned int i;
  if (seed == -1) {
    auto now = std::chrono::system_clock::now();
    auto duration = now.time_since_epoch();
    step = std::chrono::duration_cast<std::chrono::milliseconds>(duration).count();
    step /= 10;
    valint = step;
    step -= valint;
    step *= 10;
    if (step == 0) {
      i = 1;
      while (valint % i != 0) {
        i+= 1;
      };
      step += i;
    };
  } else {
    step = seed;
  };
  std::vector<int> ref_vec = {5, 3, 1, 6, 8, 2, 4, 7, 9}; 
  unsigned int addr;
  long double n2 = n;
  long double prob_step = 1 / n2;
  if (valint % 9 == 0) {
    addr = 3;
  } else if (valint % 7 == 0) {
    addr = 4;
  } else if (valint % 8 == 0) {
    addr = 7;
  } else if (valint % 6 == 0) {
    addr = 9;
  } else if (valint % 3 == 0) {
    addr = 13;
  } else if (valint % 4 == 0) {
    addr = 1;
  } else if (valint % 2 == 0) { 
    addr = 8;
  } else {
    addr = 5;
  };
  std::vector<double> rtn_v = {};
  rtn_v.reserve(n);
  double cur_prob = 0;
  double x_step = 1 / n2;
  double x_step2 = 0;
  unsigned int cur_n = 0;
  unsigned int Step = step;
  double cur_noise;
  double cnst = 1 / (sd * sqrtl(2 * M_PI));
  while (cur_n < n) {
    cur_prob += cnst * exp2f(-0.5 * (x_step2 / sd) * (x_step2 / sd)) * x_step;
    while ((cur_prob - prob_step) >= 0) {
      Step += ref_vec[Step % 9] + addr;
      cur_noise = sin(Step) * noise * x_step2;
      rtn_v.push_back(mean + x_step2 + cur_noise);
      Step += ref_vec[Step % 9] + addr;
      cur_noise = sin(Step) * noise * x_step2;
      rtn_v.push_back(mean - x_step2 + cur_noise);
      cur_prob -= prob_step;
      cur_n += 2;
    };
    x_step2 += x_step;
  };
  if (evenval) {
    rtn_v.pop_back();
  };
  return rtn_v;
};

#if 0
//@T qnorm1
//@U template &lt;typename T, typename T2&gt; double qnorm1(T &mean, T2 &sd, double &val, double offset_prob = 0.05)
//@X
//@D Returns the quantile value for a given theoretical normal distribution. There is an offset probability input that tells the most offset probability the function has to takein count in order to return the quantile value.
//@A mean : is the mean of the normal distribution
//@A sd : is the standard deviation of the normal distribution
//@A val : is the quantile percentage (between 0 and 1)
//@A offset_prob : is the probability from which is no longer not taken in count by the function in order to return a coherent value
//@X
//@E double mean = 12;
//@E double sd = 2;
//@E std::vector&lt;double&gt; vec = {0.33, 0.40, 0.45, 0.5, 0.55};
//@E std::vector&lt;double&gt; out = qnorm1(vec, mean, sd);
//@E print_nvec(out);
//@E :0: 10.8688 11.3346 11.6673 12 12.3327 
//@X
#endif 

template <typename T, typename T2> std::vector<double> qnorm1(std::vector<double> &val, T &mean, T2 &sd, double offset_prob = 0.05) {
  std::vector<double> rtn_v = {};
  rtn_v.reserve(val.size());
  double intr_val = log(offset_prob * sd * pow((2 * M_PI), 0.5));
  double offset;
  if (intr_val < 0) {
    offset = pow(-2 * intr_val, 0.5) * sd;
  } else {
    offset = pow(2 * intr_val, 0.5) * sd;
  };
  double addr = mean - offset;
  offset *= 2;
  for (std::vector<double>::iterator it = val.begin(); it != val.end(); ++it) {
    rtn_v.push_back(offset * *it + addr);
  };
  return rtn_v;
};

#if 0
//@T qnorm2
//@U template &lt;typename T, typename T2&gt; double qnorm1(T &mean, T2 &sd, double &val, double offset_prob = 0.05)
//@X
//@D Returns the quantile value for a given theoretical normal distribution. This algorithm may be more precise than qnorm1 but takes slightly longer times to compute.
//@A mean : is the mean of the normal distribution
//@A sd : is the standard deviation of the normal distribution
//@A x : are the quantile percentage (between 0 and 1), must be ascendly sorted
//@A step : is the accuracy, the lower it is, the more precise it gets
//@X
//@E double mean = 12;
//@E double sd = 2;
//@E std::vector&lt;double&gt; vec = {0.33, 0.40, 0.45, 0.5, 0.55};
//@E std::vector&lt;double&gt; out = qnorm2(vec, mean, sd);
//@E print_nvec(out);
//@E :0: 9.92 10.85 11.48 12.11 12.74 
//@X
#endif

std::vector<double> qnorm2(std::vector<double> &x, double mean, double sd, double step = 0.01) {
  double cur_prob;
  double cur_step;
  std::vector<double> rtn_v = {};
  cur_step = step;
  cur_prob = (std::exp(-0.5 * std::pow((cur_step - mean) / sd, 2)) / (sd * std::sqrt(2 * M_PI))) * step;
  for (double qtl : x) {
    while (cur_prob < qtl) {
      cur_prob += (std::exp(-0.5 * std::pow((cur_step - mean) / sd, 2)) / (sd * std::sqrt(2 * M_PI))) * step;
      cur_step += step;
    };
    rtn_v.push_back(cur_step);
  };
  return rtn_v;
};

#if 0
//@T dnorm
//@U template &lt;typename T&gt; std::vector&lt;double&gt; dnorm(std::vector&lt;T&gt; &x, double &mean, double &sd, double step = 1)
//@X
//@D Returns the density function of a given normal distribution as an stl double vector.
//@A x : is an stl vector of values you want the probability from
//@A mean : is the mean of the normal distribution
//@A sd : is the standard deviation of the normal distribution
//@A step : the step of each element you want the probability from, see examples. Defaults to 1, so it ouputs the same result as the <code>dnorm()</code> function in R by default.
//@X
//@E double mean = 12;
//@E double sd = 2;
//@E std::vector&lt;double&gt; vec = {1, 8.5, 9, 9.5, 10, 10.5, 11, 11.5, 12, 12.5, 13, 13.5, 14};
//@E std::vector&lt;double&gt; vec2 = {9, 10, 11, 12, 13, 14};
//@E std::vector&lt;double&gt; out = dnorm(vec, mean, sd, 0.5);
//@E print_nvec(out);
//@E :0: 0.0323794 0.0456623 0.0604927 0.0752844 0.0880163 0.096667 0.0997356 0.096667 0.0880163 0.0752844 0.0604927 
//@E out = dnorm(vec2, mean, sd, 1);
//@E :0: 0.0647588 0.120985 0.176033 0.199471 0.176033 0.120985 
//@X
#endif

template <typename T> std::vector<double> dnorm(std::vector<T> &x, double &mean, double &sd, double step = 1) {
  std::vector<double> rtn_v = {};
  const double divider = (sd * pow(2 * M_PI, 0.5));
  for (typename std::vector<T>::iterator i = x.begin(); i != x.end(); ++i) {
    rtn_v.push_back((exp(-0.5 * pow(((mean - *i) / sd), 2))) / divider * step);
  };
  return rtn_v;
};

#if 0
//@T pnorm
//@U template &lt;typename T&gt; std::vector&lt;double&gt; pnorm(std::vector&lt;T&gt; &x, double &mean, double &sd, double step = 0.01)
//@X
//@D Returns the cumulative distribution function of a given normal distribution.
//@A x : is an stl vector containing all the elements you want the function distribution to be calculated with, must be ascendly sorted
//@A mean : is the mean of the normal distribution
//@A sd : is the standard deviation of the normal distribution
//@A step : the lower it is the higher the accuracy is
//@X
//@E double mean = 15;
//@E double sd = 2;
//@E std::vector&lt;double&gt; vec = {13, 13.5, 14, 14.5, 15, 15.5, 16, 18};
//@E std::vector&lt;double&gt; out = pnorm(vec, mean, sd);
//@E print_nvec(out);
//@E :0: 0.00120985 0.0693298 0.151367 0.24421 0.342947 0.441622 0.534291 0.774818
//@X
#endif

template <typename T> std::vector<double> pnorm(std::vector<T> &x, double &mean, double &sd, double step = 0.01) {
  std::vector<double> rtn_v = {};
  const double divider = (sd * powf(2 * M_PI, 0.5));
  double lst_val = 0;
  double lst_x = x[0];
  for (double cur_x : x) {
    while (lst_x <= cur_x) {
      lst_val += (expf(-0.5 * powf(((lst_x - mean) / sd), 2))) / divider * step;
      lst_x += step;
    };
    rtn_v.push_back(lst_val);
  };
  return rtn_v;
};

#if 0
//@L4 Binomial

//@T dbinom 
//@U std::vector&lt;double&gt; dbinom(std::vector&lt;unsigned int&gt; &k, unsigned int &n, double &p)
//@X
//@D Returns the probability function of a binomial distribution as an stl double vector.
//@A x : is an stl unsigned int vector containing all the x's
//@A n : is the size of the set
//@A p : is the probability of success
//@X
//@E std::vector&lt;unsigned int&gt; vec = {39, 40, 41, 42, 43, 44, 45, 46, 47, 48};
//@E unsigned int n = 100;
//@E double p = 0.45;
//@E std::vector&lt;double&gt; out = dbinom(vec, n, p); 
//@E print_nvec(out);
//@E  :0: 0.03875 0.0483929 0.0580423 0.066859 0.0739653 0.0785867 0.0801904 0.0785867 0.0739653 0.066859 0.0580423 0.0483929
//@X
#endif

std::vector<double> dbinom(std::vector<unsigned int> &k, unsigned int n, double &p) {
  std::vector<double> rslt = {};
  unsigned int cur_k;
  int numerator = n;
  unsigned int lst_n = n;
  unsigned int denumerator1;
  unsigned int denumerator2;
  double frct;
  double q = 1 - p;
  double mean = n * p;
  double sd = std::sqrt(n * p * q);
  if (n * p < 6 || n * q < 6) {
    n -= 1;
    while (n > 1) {
      numerator *= n;
      n -= 1;
    };
    for (unsigned int i : k) {
      denumerator1 = i;
      cur_k = i - 1;
      while (cur_k > 1) {
        denumerator1 *= cur_k;
        cur_k -= 1;
      };
      denumerator2 = lst_n - i;
      cur_k = lst_n - i - 1;
      while (cur_k > 1) {
        denumerator2 *= cur_k;
        cur_k -= 1;
      };
      frct = numerator / (denumerator1 * denumerator2);
      rslt.push_back(frct * std::pow(p, i) * std::pow(q, (lst_n - i)));
    };
    return rslt;
  } else {
    for (unsigned int i : k) {
      rslt.push_back(1/(sd * std::sqrt(2 * M_PI)) * std::exp(-0.5 * std::pow((i - mean) / sd, 2)));
    };
    return rslt;
  };
};

//@T pbinom 
//@U std::vector&lt;double&gt; pbinom(std::vector&lt;unsigned int&gt; &k, unsigned int &n, double &p)
//@X
//@D Returns the cumulative distribution function of <b>range</b> P(X = {x1,x2...}) as an stl double vector.
//@A k : is an stl unsigned int vector containing all the k's, must be ascendly sorted
//@A n : is the size of the set
//@A p : is the probability of success
//@X
//@E unsigned int n = 10;
//@E double p = 0.5;
//@E std::vector&lt;unsigned int&gt; vec = {3, 5, 7};
//@E std::vector&lt;double&gt; out = pbinom(vec, n, p);
//@E print_nvec(out);
//@E :0: 0.117188 0.568359 0.890625
//@X

std::vector<double> pbinom(std::vector<unsigned int> &k, unsigned int n, double &p) {
  std::vector<double> rslt = {};
  unsigned int cur_k;
  int numerator = n;
  int lst_n = n;
  const unsigned int ref_n = n;
  unsigned int denumerator1;
  unsigned int denumerator2;
  double frct;
  double q = 1 - p;
  double mean = n * p;
  double sd = std::sqrt(n * p * q);
  double cur_val = 0;
  unsigned int lst_k = k[0];
  const unsigned int target_n = n - lst_k;
  if (n * p < 6 || n * q < 6) {
    n -= 1;
    while (n > 1) {
      numerator *= n;
      n -= 1;
    };
    denumerator1 = lst_k;
    cur_k = lst_k - 1;
    while (cur_k > 1) {
      denumerator1 *= cur_k;
      cur_k -= 1;
    };
    denumerator2 = numerator;
    while (lst_n > target_n) {
      denumerator2 /= lst_n;
      lst_n -= 1;
    };
    for (unsigned int i : k) {
      while (lst_k <= i) {
        frct = numerator / (denumerator1 * denumerator2);
        cur_val += frct * std::pow(p, lst_k) * std::pow(q, (ref_n - lst_k));
        lst_k += 1;
        denumerator2 /= lst_n;
        denumerator1 *= lst_k;
        lst_n -= 1;
      };
      rslt.push_back(cur_val);
    };
    return rslt;
  } else {
    for (unsigned int i : k) {
      while (lst_k <= i) {
        cur_val += (std::exp(-0.5 * std::pow((lst_k - mean) / sd, 2))) / (sd * std::sqrt(2 * M_PI));
        lst_k += 1;
      };
      rslt.push_back(cur_val);
    };
    return rslt;
  };
};

//@T qbinom
//@U std::vector&lt;unsigned int&gt; qbinom(std::vector&lt;double&gt; &pvec, unsigned int &n, double &p)
//@X
//@D Returns the quantiles of a binomial distribution. 
//@A pvec : is an stl vector of probabilities, must be ascendly sorted
//@A n : is size of the set, as an unsigned int
//@A p : is the probability of success, as a double
//@X
//@E std::vector&lt;double&gt; vec3 = {0.3, 0.4, 0.5, 0.6, 0.7};
//@E unsigned int n = 100;
//@E double prob = 0.55;
//@E std::vector&lt;unsigned int&gt; out = qbinom(vec3, n, prob);
//@E print_nvec(out);
//@E :0: 47 48 50 51 52 54
//@X

std::vector<unsigned int> qbinom(std::vector<double> &pvec, unsigned int &n, double &p) {
  std::vector<unsigned int> rtn_v = {};
  double cur_prob = 0;
  double lst_prob;
  double q = 1 - p;
  double mean = n * p;
  double sd = std::sqrt(n * p * (1 - p));
  unsigned int i = 1;
  double fct;
  unsigned int numerator = n;
  unsigned int denumerator = 1;
  unsigned int denumerator2;
  unsigned inv_k = n - 1;
  int cur_k;
  if (n * p < 6 || n * q < 6) {
    cur_k = n - 1;
    while (cur_k > 1) {
      numerator *= cur_k;
      cur_k -= 1;
    };
    for (double cur_p : pvec) {
      while (cur_prob < cur_p) {
        denumerator *= i;
        denumerator2 = inv_k;
        cur_k = inv_k - 1;
        while (cur_k > 1) {
          denumerator2 *= cur_k;
          cur_k -= 1;
        };
        fct = (double)numerator / (denumerator * denumerator2);
        lst_prob = cur_prob;
        cur_prob += fct * pow(p, i) * pow(q, inv_k);
        i += 1;
        inv_k -= 1;
      };
      if (abs(cur_p - lst_prob) < abs(cur_p - cur_prob)) {
        rtn_v.push_back(i - 1);
      } else {
        rtn_v.push_back(i);
      };
    };
  } else {
    for (double cur_p : pvec) {
      while (cur_prob < cur_p) {
        lst_prob = cur_prob;
        cur_prob += (std::exp(-0.5 * pow((i - mean) / sd, 2))) / (sd * std::sqrt(2 * M_PI));
        i += 1;
      };
      if (abs(cur_p - lst_prob) < abs(cur_p - cur_prob)) {
        rtn_v.push_back(i - 1);
      } else {
        rtn_v.push_back(i);
      };
    };
  };
  return rtn_v;
};

//@T rbinom 
//@U std::vector&lt;unsigned int&gt; rbinom(unsigned int &n, unsigned int size, double p)
//@X
//@D Returns pseudo-random values of binomial distribution.
//@A n : is the number of observations
//@A size : is the size of the individuals
//@A p : is the probability of success
//@X
//@E unsigned int size = 100;
//@E double p = 0.5;
//@E unsigned int n = 60;
//@E std::vector&lt;unsigned int&gt; out = rbinom(n, size, p);
//@E print_nvec(out);
 //@E :0: 58 42 42 42 59 59 41 41 61 61 39 39 67 67 
 //@E 35 35 50 50 50 50 50 50 50 50
//@E :25: 50 50 50 50 50 50 50 50 50 50 50 50 50 50 
//@E 50 50 50 50 50 50 50 50 50 50
//@E :50: 50 50 50 50 50 50 50 50 50 50
//@E Mean(out);
//@E 49
//@E Sd(out);
//@E 5.90141
//@E std::sqrt(size * p * (1 - p));
//@E 5
//@X

//@L4 Poisson

//@T dpois
//@U std::vector&lt;double&gt; dpois(std::vector&lt;int&gt; &k, int &lambda)
//@X
//@D Returns the poisson probability distribution. 
//@A k : is the vector containing the k values
//@A lambda : is the mean
//@X
//@E int lambda = 500;
//@E std::vector&lt;int&gt; vec2 = {492, 500, 520};
//@E std::vector&lt;double&gt; out = dpois(vec2, lambda);
//@E print_nvec(out);
//@E :0: 0.0167352 0.0178412 0.0119593
//@X

std::vector<double> dpois(std::vector<int> &k, int &lambda) {
  double cur_prob;
  std::vector<double> rtn_v = {};
  unsigned int denumerator;
  const double numerator = std::exp(-lambda);
  int idx_k;
  double sd = std::sqrt(lambda);
  if (lambda < 6) {
    cur_prob = 0;
    for (int cur_k : k) {
      denumerator = cur_k;
      idx_k = cur_k - 1;
      while (idx_k > 1) {
        denumerator *= idx_k;
        idx_k -= 1;
      };
      cur_prob = numerator * std::pow(lambda, cur_k) / denumerator;
      rtn_v.push_back(cur_prob);
    };
  } else {
    for (int cur_k : k) {
      cur_prob = std::exp(-0.5 * std::pow((cur_k - lambda) / sd, 2)) / (sd * std::sqrt(2 * M_PI));
      rtn_v.push_back(cur_prob);
    };
  };
  return rtn_v;
};

//@T ppois
//@U std::vector&lt;double&gt; ppois(std::vector&lt;int&gt; &k, int &lambda)
//@X
//@D Returns the poisson cumulative probability distribution. 
//@A k : is the vector containing the k values
//@A lambda : is the mean
//@X
//@E int lambda = 500;
//@E std::vector&lt;int&gt; vec2 = {492, 500, 520};
//@E std::vector&lt;double&gt; out = ppois(vec2, lambda);
//@E print_nvec(out);
//@E :0: 0.0167352 0.157008 0.468481
//@X

std::vector<double> ppois(std::vector<int> &k, int &lambda) {
  double cur_prob = 0;
  std::vector<double> rtn_v = {};
  unsigned int denumerator;
  const double numerator = std::exp(-lambda);
  int idx_k;
  double sd = std::sqrt(lambda);
  int lst_k = k[0];
  if (lambda < 6) {
    denumerator = lst_k;
    idx_k = lst_k - 1;
     while (idx_k > 1) {
       denumerator *= idx_k;
       idx_k -= 1;
     };
    for (int cur_k : k) {
      while (lst_k <= cur_k) {
        cur_prob += numerator * std::pow(lambda, lst_k) / denumerator;
        lst_k += 1;
        denumerator *= lst_k;
      };
      rtn_v.push_back(cur_prob);
    };
  } else {
    for (int cur_k : k) {
      while (lst_k <= cur_k) {
        cur_prob += std::exp(-0.5 * std::pow((lst_k - lambda) / sd, 2)) / (sd * std::sqrt(2 * M_PI));
        lst_k += 1;
      };
      rtn_v.push_back(cur_prob);
    };
  };
  return rtn_v;
};

//@T qpois
//@U std::vector&lt;unsigned int&gt; qpois(std::vector&lt;double&gt; &p, int &lambda)
//@X
//@D Returns the quantile of the poisson distribution
//@A p : is the vector of probabilities
//@A lambda : is the mean
//@X
//@E std::vector&lt;double&gt; vec = {0.22, 0.5, 0.7};
//@E int lambda = 500;
//@E std::vector&lt;unsigned int&gt; out = qpois(vec, lambda);
//@E :0: 483 500 512
//@X

std::vector<unsigned int> qpois(std::vector<double> &p, int &lambda) {
  double cur_prob = 0;
  std::vector<unsigned int> rtn_v = {};
  unsigned int denumerator;
  const double numerator = std::exp(-lambda);
  int idx_k;
  double sd = std::sqrt(lambda);
  double lst_prob = 0;
  int lst_k = 1;
  if (lambda < 6) {
    denumerator = lst_k;
    idx_k = lst_k - 1;
     while (idx_k > 1) {
       denumerator *= idx_k;
       idx_k -= 1;
     };
    for (double cur_p : p) {
      while (cur_prob < cur_p) {
        lst_prob = cur_prob;
        cur_prob += numerator * std::pow(lambda, lst_k) / denumerator;
        lst_k += 1;
        denumerator *= lst_k;
      };
      if (abs(cur_prob - cur_p) < abs(lst_prob - cur_p)) {
        rtn_v.push_back(lst_k);
      } else {
        rtn_v.push_back(lst_k - 1);
      };
    };
  } else {
    for (double cur_p : p) {
      while (cur_prob < cur_p) {
        lst_prob = cur_prob;
        cur_prob += std::exp(-0.5 * std::pow((lst_k - lambda) / sd, 2)) / (sd * std::sqrt(2 * M_PI));
        lst_k += 1;
      };
      if (abs(cur_prob - cur_p) < abs(lst_prob - cur_p)) {
        rtn_v.push_back(lst_k);
      } else {
        rtn_v.push_back(lst_k - 1);
      };
    };
  };
  return rtn_v;
};

//@T rpois
//@U std::vector&lt;unsigned int&gt; rpois(unsigned int &n, unsigned int lambda)
//@X
//@D
//@A n : is the number of observations
//@A lambda : is the mean
//@X
//@E unsigned int lambda = 100;
//@E unsigned int n = 60;
//@E std::vector&lt;unsigned int&gt; out = rpois(n, lambda);
//@E print_nvec(out);
//@E  :0: 114 86  86  86  115 115 85  
//@E 85  85  116 116 84  84  119 119 
//@E 83  83  120 120 79  79  133 133 67
//@E :25: 100 100 100 100 100 100 100 
//@E 100 100 100 100 100 100 100 100 100 
//@E 100 100 100 100 100 100 100 100
//@E :50: 101 101 101 101 101 101 101 101 
//@E 101 101
//@E Mean(out);
//@E 99
//@E Sd(out);
//@E 13.0799
//@E std::sqrt(lambda);
//@E 10
//@X

//@L4 Exponential distribution

//@T dexp
//@U std::vector&lt;double&gt; dexp(std::vector&lt;double&gt; &x, double &rate)
//@X
//@D Returns the probability distribution of the exponential distribution
//@A x : is the vector containing the values you want the probability from
//@A rate : is the rate value for the exponential distribution, given by 1 / mean
//@X
//@E double rate = 0.2;
//@E std::vector&lt;double&gt; vec = {1, 2, 3, 4, 5, 6};
//@E std::vector&lt;double&gt; out = dexp(vec, rate);
//@E print_nvec(out);
//@E :0: 0.163746 0.134064 0.109762 0.0898658 0.0735759 0.0602388
//@X

std::vector<double> dexp(std::vector<double> &x, double &rate) {
  std::vector<double> rtn_v = {};
  for (double i : x) {
    rtn_v.push_back(rate * std::exp(-rate * i));
  };
  return rtn_v;
};

//@T pexp
//@U std::vector&lt;double&gt; pexp(std::vector&lt;double&gt; &x, double &rate, double step = 0.01)
//@X
//@D Returns the cumulative probability distribution for the exponential distribution.
//@A x : is the vector of the values you want the cumulative probability distribution from, must be ascendly sorted
//@A rate : is the rate for the exponential distribution
//@A step : the lower it is the more accurate the result will be
//@X
//@E :0: 0.00163746 0.148559 0.271287 0.37067 0.452038 0.518657
//@X

std::vector<double> pexp(std::vector<double> &x, double &rate, double step = 0.01) {
  std::vector<double> rtn_v = {};
  double cur_prob;
  double lst_prob = 1 - std::exp(-rate * (x[0] - step));
  for (double i : x) {
    cur_prob = 1 - std::exp(-rate * i) - lst_prob;
    rtn_v.push_back(cur_prob);
  };
  return rtn_v;
};

//@T qexp
//@U std::vector&lt;double&gt; qexp(std::vector&lt;double&gt; &p, double &rate)
//@X
//@D Returns the quantile of the exponential probability distribution
//@A p : is the vector of probabilities
//@A rate : is the rate of the exponential distribution
//@X
//@E double rate = 0.2;
//@E std::vector&lt;double&gt; vec2 = {0.1, 0.2, 0.3, 0.4, 0.5, 0.75};
//@E std::vector&lt;double&gt; out = qexp(vec2, rate);
//@E print_nvec(out);
//@E :0: 0.526803 1.11572 1.78337 2.55413 3.46574 6.93147
//@X

std::vector<double> qexp(std::vector<double> &p, double &rate) {
  std::vector<double> rtn_v = {};
  const unsigned int n = p.size();
  rtn_v.reserve(n);
  for (double i : p) {
    rtn_v.push_back(-std::log(1 - i) / rate);
  };
  return rtn_v;
};

//@T rexp
//@U std::vector&lt;double&gt; rexp(unsigned int &n, double rate)
//@X
//@D Returns a pseudo-random distribution of the exponential distribution
//@A n : is the number of observations
//@A rate : is the rate of the exponential distribution
//@X
//@E double rate = 0.2;
//@E unsigned int n = 100;
//@E std::vector&lt;double&gt; out = rexp(n, rate);
//@E print_nvec(out);
//@E :0: 13.2 13.2 2.79385  2.79385  2.79385  
//@E 13.6804 13.6804 4.10504  4.10504  15.9378 
//@E 15.9378 5.60406  5.60406  21.5331 21.5331 
//@E 10.4864 10.4864 5.20657  5.20657  5.20657  
//@E 5.20657  5.20657  5.20657  5.20657
//@E :25: 5.20657  5.20657  5.20657  5.20657  5.20657  
//@E 4.80913  4.80913  4.80913  4.80913  4.80913  4.80913  
//@E 4.80913  4.80913  4.80913  4.80913  4.80913  4.80913  
//@E 4.80913  4.80913  5.3978  5.3978  5.3978  5.3978  5.3978
//@E :50: 5.3978  5.3978  5.3978  5.3978  5.3978  4.57492  
//@E 4.57492  4.57492  4.57492  4.57492  4.57492  4.57492
//@E 4.57492  4.57492  4.57492  4.57492  4.57492  5.58841  
//@E 5.63733  5.63733  5.63733  5.63733  5.63733  5.63733
//@E :75: 5.63733  5.63733  4.35393  4.35393  4.35393  4.35393  
//@E 4.35393  4.35393  4.35393  4.35393  4.35393  4.35393  
//@E 4.35393  5.82063  5.82063  5.82063  5.82063  5.82063  
//@E 5.82063  5.82063  5.82063  4.19025  4.19025  4.19025
//@E :100: 4.19025
//@E Mean(out);
//@E 5.94307
//@E Sd(out);
//@E 4.29426
//@X

//@L4 Cauchy

//@T dcauchy
//@U std::vector&lt;double&gt; dcauchy(std::vector&lt;double&gt; &x, double location = 0, double scale = 1)
//@X
//@D Returns the probability distribution of the cauchy distribution.
//@A x : is the vector of values you want the probability from
//@A location : is the x coordinate
//@A scale : is the t coordinate
//@X
//@E double location = 0;
//@E double scale = 1;
//@E std::vector&lt;double&gt; vec = {-2, -1, 0, 1, 2, 4};
//@E std::vector&lt;double&gt; out = dcauchy(vec, location, scale);
//@E print_nvec(out);
//@E :0: 0.063662 0.159155 0.31831 0.159155 0.063662 0.0187241
//@X

std::vector<double> dcauchy(std::vector<double> &x, double location = 0, double scale = 1) {
  std::vector<double> rtn_v = {};
  rtn_v.reserve(x.size());
  for (double i : x) {
    rtn_v.push_back(1 / (scale * M_PI * (1 + std::pow((i - location) / scale, 2))));
  };
  return rtn_v;
};

//@T pcauchy
//@U std::vector&lt;double&gt; pcauchy(std::vector&lt;double&gt; &x, double location = 0, double scale = 1)
//@X
//@D Returns the cumulative probability distribution of the cauchy distribution (starts from first value).
//@A x : is the vector of values you want the cumulative probability from
//@A location : is the x coordinate
//@A scale : is the t coordinate
//@A step : the lowest it is the more accurate the result gets
//@X
//@E double location = 0;
//@E double scale = 1;
//@E std::vector&lt;double&gt; vec = {-2, -1, 0, 1, 2, 4};
//@E std::vector&lt;double&gt; out = pcauchy(vec, location, scale);
//@E print_nvec(out);
//@E :0: 0.000634083 0.10305 0.35305 0.60305 0.705467 0.775071 
//@X

std::vector<double> pcauchy(std::vector<double> &x, double location = 0, double scale = 1, double step = 0.01) {
  std::vector<double> rtn_v = {};
  rtn_v.reserve(x.size());
  double ref_prob = atan((x[0] - step - location) / scale) / M_PI + 0.5;
  for (double i : x) {
    rtn_v.push_back(atan((i - location) / scale) / M_PI + 0.5 - ref_prob);
  };
  return rtn_v;
};

//@T qcauchy 
//@U std::vector&lt;double&gt; qcauchy(std::vector&lt;double&gt; &p, double location = 0, double scale = 1)
//@X
//@D Returns the quantile of the cauchy probability distribution
//@A p : is the vector containing the probabilities
//@A location : is the x coordiante
//@A scale : is the y coordinate
//@X
//@E double location = 0;
//@E double scale = 1;
//@E std::vector&lt;double&gt; vec = {0.1, 0.25, 0.4, 0.5, 0.63, 0.78};
//@E std::vector&lt;double&gt; out = qcauchy(vec, location, scale);
//@E print_nvec(out);
//@E :0: -3.07768 -1 -0.32492 0  0.432739  1.20879
//@X

std::vector<double> qcauchy(std::vector<double> &p, double location = 0, double scale = 1) {
  std::vector<double> rtn_v = {};
  rtn_v.reserve(p.size());
  for (double i : p) {
    rtn_v.push_back(std::tan((i * 2 * M_PI - M_PI) / 2));
  };
  return rtn_v;
};

//@T rcauchy
//@U std::vector&lt;double&gt; rcauchy(unsigned int n, double x = 0, double y = 1)
//@X
//@D Returns a pseudo-random generation of numbers following a cauchy distribution.
//@A n : is the number of numbers to generate
//@A x : is the x coordinate
//@A y : is the y coordinate
//@X
//@E int ref_min = -2;
//@E double location = -4;
//@E double scale = 8;
//@E unsigned int n = 100;
//@E std::vector&lt;double&gt; out = rcauchy(n, location, scale);
//@E std::vector&lt;bool&gt; out2 = supcmp(out, ref_min);
//@E sum(out2);
//@E 42 
//@X

std::vector<double> rcauchy(unsigned int n, double x = 0, double y = 1) {
  std::vector<double> rtn_v = {};
  double wait_val;
  double cur_wait_val;
  auto now = std::chrono::system_clock::now();
  auto duration = now.time_since_epoch();
  unsigned int i2;
  for (int i = 0; i < n; ++i) {
    now = std::chrono::system_clock::now();
    duration = now.time_since_epoch();
    wait_val = std::chrono::duration_cast<std::chrono::microseconds>(duration).count() % 100;
    if ((int)wait_val % 9 == 0) {
      std::this_thread::sleep_for(std::chrono::microseconds(9));
    } else if ((int)wait_val % 8 == 0) {
      std::this_thread::sleep_for(std::chrono::microseconds(8));
    } else if ((int)wait_val % 6 == 0) {
      std::this_thread::sleep_for(std::chrono::microseconds(6));
    } else if ((int)wait_val % 5 == 0) {
      std::this_thread::sleep_for(std::chrono::microseconds(5));
    } else if ((int)wait_val % 3 == 0) {
      std::this_thread::sleep_for(std::chrono::microseconds(3));
    } else if ((int)wait_val % 2 == 0) {
      std::this_thread::sleep_for(std::chrono::microseconds(2));
    } else {
      std::this_thread::sleep_for(std::chrono::microseconds(1));
    };
    for (i2 = 0; i2 < 2; ++i2) {
      now = std::chrono::system_clock::now();
      duration = now.time_since_epoch();
      cur_wait_val = std::chrono::duration_cast<std::chrono::microseconds>(duration).count() % 100;
      wait_val *= cur_wait_val;
      if ((int)wait_val % 9 == 0) {
        std::this_thread::sleep_for(std::chrono::microseconds(9));
      } else if ((int)wait_val % 8 == 0) {
        std::this_thread::sleep_for(std::chrono::microseconds(8));
      } else if ((int)wait_val % 6 == 0) {
        std::this_thread::sleep_for(std::chrono::microseconds(6));
      } else if ((int)wait_val % 5 == 0) {
        std::this_thread::sleep_for(std::chrono::microseconds(5));
      } else if ((int)wait_val % 3 == 0) {
        std::this_thread::sleep_for(std::chrono::microseconds(3));
      } else if ((int)wait_val % 2 == 0) {
        std::this_thread::sleep_for(std::chrono::microseconds(2));
      } else {
        std::this_thread::sleep_for(std::chrono::microseconds(1));
      };
    };
    if (i % 2 != 0) {
      wait_val *= -1;
    };
    rtn_v.push_back(tan(wait_val) * y + x);
  };
  return rtn_v;
};

//@L4 Gamma distribution

//@T dgamma
//@U std::vector&lt;double&gt; dgamma(std::vector&lt;double&gt; &x, double &shape, double &rate)
//@X
//@D Returns the gamma density probability distribution. Uses a normal law of mean = 1/rate * shape and sd = 1/rate * sqrt(shape) to approximate for shape value greater than 171
//@A x : is the input vector composed of the x values
//@A shape : is the alpha value
//@A rate : is the rate value (lambda or 1/theta)
//@X
//@E std::vector&lt;double&gt; vec = {6444, 6666, 6888};
//@E double shape = 3333;
//@E double rate = 0.5;
//@E std::vector&lt;double&gt; out = dgamma(vec, shape, rate);
//@E print_nvec(out);
//@E :0: 0.000544178 0.00345511 0.000544178
//@X

std::vector<double> dgamma(std::vector<double> &x, double &shape, double &rate) {
  std::vector<double> rtn_v = {};
  double divided;
  const double divider = tgamma(shape);
  const double shape_minus = shape - 1;
  const double ref_mult = pow(rate, shape);
  const double scale = 1 / rate;
  const double mean = shape * scale;
  const double sd = pow(shape, 0.5) * scale;
  const double divided2 = sd * pow(6.28318530717959, 0.5);
  if (shape < 172) {
    for (double val : x) {
      divided = pow(val, shape_minus) * exp(-rate * val) * ref_mult;
      rtn_v.push_back(divided / divider);
    };
  } else {
    for (double val : x) {
      rtn_v.push_back(exp(-0.5 * pow((val - mean) / sd, 2)) / divided2);
    };
  };
  return rtn_v;
};

//@T pgamma
//@U std::vector&lt;double&gt; pgamma(std::vector&lt;double&gt; &x, double &shape, double &rate, double step)
//@X
//@D Returns the gamma cmulative probability distribution between an interval (first x value to last x value)
//@A x : is the input x values, must be ascendly sorted
//@A shape : is the alpha value
//@A rate : is the lambda value, 1/theta
//@A step : the lower it is, the more accurate the result will be at a computational cost
//@X
//@E std::vector&lt;double&gt; vec = {6444, 6555, 6666, 6888};
//@E double shape = 3333;
//@E double rate = 0.5;
//@E double step = 0.1;
//@E std::vector&lt;double&gt; out = pgamma(vec, shape, rate, step);
//@E print_nvec(out);
//@E :0: 5.44178e-05 0.141121 0.473211 0.946151
//@X

std::vector<double> pgamma(std::vector<double> &x, double &shape, double &rate, double &step) {
  std::vector<double> rtn_v = {};
  //double divided;
  const double divider = tgamma(shape);
  const double shape_minus = shape - 1;
  const double ref_mult = pow(rate, shape);
  const double scale = 1 / rate;
  const double mean = shape * scale;
  const double sd = pow(shape, 0.5) * scale;
  const double divided2 = sd * pow(6.28318530717959, 0.5);
  double cnt = x[0];
  double cur_rslt = 0;
  if (shape < 172) {
    for (double val : x) {
      while (cnt < val) {
        cur_rslt += pow(cnt, shape_minus) * exp(-rate * cnt) * ref_mult / divider * step;
        cnt += step;
      };
      cur_rslt += pow(cnt, shape_minus) * exp(-rate * cnt) * ref_mult / divider * step;
      rtn_v.push_back(cur_rslt);
    };
  } else {
    for (double val : x) {
      while (cnt < val) {
        cur_rslt += exp(-0.5 * pow((cnt - mean) / sd, 2)) / divided2 * step;
        cnt += step;
      };
      cur_rslt += exp(-0.5 * pow((cnt - mean) / sd, 2)) / divided2 * step;
      rtn_v.push_back(cur_rslt);
    };
  };
  return rtn_v;
};

//@T qgamma
//@U std::vector&lt;double&gt; qgamma(std::vector&lt;double&gt; &x, double &shape, double &rate, double step)
//@X
//@D Returns the quantile value of the gamma probability distribution
//@A x : is the input vector of probabilities, must be ascendly sorted
//@A shape : is the alpha value
//@A rate : is the lambda value (1 / theta)
//@A step : the lower it is, the more accurate the result will be at a cmputational cost
//@X
//@E std::vector&lt;double&gt; vec = {0.26, 0.45, 0.5, 0.6, 0.88};
//@E double shape = 3333;
//@E double rate = 0.5;
//@E double step = 0.1;
//@E std::vector&lt;double&gt; out = qgamma(vec, shape, rate, step);
//@E print_nvec(out);
//@E :0: 6591.86 6651.56 6666.06 6695.36 6801.76
//@X

std::vector<double> qgamma(std::vector<double> &x, double &shape, double &rate, double &step) {
  std::vector<double> rtn_v = {};
  //double divided;
  const double divider = tgamma(shape);
  const double shape_minus = shape - 1;
  const double ref_mult = pow(rate, shape);
  const double scale = 1 / rate;
  const double mean = shape * scale;
  const double sd = pow(shape, 0.5) * scale;
  const double divided2 = sd * pow(6.28318530717959, 0.5);
  double cur_x = 0;
  double cur_proba = 0;
  if (shape < 172) {
    for (double val : x) {
      while (cur_proba < val) {
        cur_proba += pow(cur_x, shape_minus) * exp(-rate * cur_x) * ref_mult / divider * step;
        cur_x += step;
      };
      rtn_v.push_back(cur_x);
    };
  } else {
    for (double val : x) {
      while (cur_proba < val) {
        cur_proba += exp(-0.5 * pow((cur_x - mean) / sd, 2)) / divided2 * step;
        cur_x += step;
      };
      rtn_v.push_back(cur_x);
    };
  };
  return rtn_v;
};

//@T rgamma
//@U std::vector&lt;double&gt; rgamma(unsigned int &n, double &shape, double &rate, double step)
//@X
//@D Generates pseudo-random variables that follow a gamma probability distribution
//@A n : is the number of observations, more than 1
//@A shape : is the alpha value
//@A rate : is the lambda (1 / theta)
//@A step : the lower it is, the more the result will be accurate, at a computational cost
//@X
//@E unsigned int n = 100;
//@E double shape = 3333;
//@E double rate = 0.25;
//@E double step = 0.01;
//@E std::vector<double> out = rgamma(n, shape, rate, step);
//@E print_nvec(out);
//@E :0: 12794.8 12857.7 12897.7 12927.7 12952.2 12973 12991.2 
//@E 13007.5 13022.4 13036.1 13048.8 13060.7 13071.9 13082.5 13092.7
//@E 13102.4 13111.7 13120.6 13129.3 13137.7 13145.8 13153.7 13161.4
//@E 13168.9
//@E :25: 13183.4 13190.5 13197.4 13204.2 13210.9 13217.5 13224 13230.4
//@E 13236.8 13243 13249.2 13255.4 13261.5 13267.5 13273.5 13279.5
//@E 13285.4 13291.3 13297.1 13303 13308.8 13314.6 13320.4 13326.2
//@E :50: 13337.8 13343.6 13349.4 13355.2 13361 13366.9 13372.7 13378.6
//@E 13384.6 13390.5 13396.5 13402.6 13408.6 13414.8 13421 13427.3
//@E 13433.6 13440 13446.5 13453.1 13459.8 13466.6 13473.5 13480.6
//@E :75: 13495.1 13502.6 13510.3 13518.2 13526.4 13534.7 13543.4 
//@E 13552.4 13561.7 13571.3 13581.5 13592.1 13603.3 13615.3 13628 
//@E 13641.6 13656.5 13672.8 13691 13711.9 13736.3 13766.3 13806.3
//@E 13869.2
//@E :100: 13276.2
//@X

std::vector<double> rgamma(unsigned int &n, double &shape, double &rate, double step) {
  std::vector<double> rtn_v = {};
  //double divided;
  const double ref_proba_step = (double)1 / n;
  double proba_cnt = ref_proba_step;
  const double divider = tgamma(shape);
  const double shape_minus = shape - 1;
  const double ref_mult = pow(rate, shape);
  const double scale = 1 / rate;
  const double mean = shape * scale;
  const double sd = pow(shape, 0.5) * scale;
  const double divided2 = sd * pow(6.28318530717959, 0.5);
  double cur_x = 0;
  double cur_proba = 0;
  double lst_val1;
  double lst_val2;
  auto now = std::chrono::system_clock::now();
  auto duration = now.time_since_epoch();
  double cur_time = std::chrono::duration_cast<std::chrono::microseconds>(duration).count() % 100;
  if ((int)cur_time % 2 == 0) {
    step += cur_time / 100 * 0.2 * step;
  } else {
    step -= cur_time / 100 * 0.2 * step;
  };
  if (shape < 172) {
    for (unsigned int i = 0; i < n; ++i) {
      while (cur_proba < proba_cnt) {
        cur_proba += pow(cur_x, shape_minus) * exp(-rate * cur_x) * ref_mult / divider * step;
        cur_x += step;
      };
      proba_cnt += ref_proba_step;
      rtn_v.push_back(cur_x);
    };
  } else {
    for (unsigned int i = 1; i < n; ++i) {
      while (cur_proba < proba_cnt) {
        cur_proba += exp(-0.5 * pow((cur_x - mean) / sd, 2)) / divided2 * step;
        cur_x += step;
      };
      proba_cnt += ref_proba_step;
      rtn_v.push_back(cur_x);
    };
  };
  lst_val1 = rtn_v[(int)cur_time % (n - 1)];
  lst_val2 = rtn_v[(int)cur_time * 5 % (n - 1)];
  rtn_v.push_back(0.5 * (lst_val1 + lst_val2));
  return rtn_v;
};

//@L4 Beta distribution

//@T dbeta
//@U std::vector&lt;double&gt; dbeta(std::vector&lt;double&gt; &x, double &a, double &b, double normalisation_step = 1)
//@X
//@D Returns the beta density probability distribution
//@A x : is the vector of the probabilities
//@A a : is alpha, number of successes
//@A b : is beta, the number of failures
//@A normalisation_step : is the probability unit of the x vector
//@X
//@E double a = 40;
//@E double b = 60;
//@E std::vector&lt;double&gt; vec = {0, 0.1, 0.2, 0.3, 0.4, 0.5, 0.6, 0.7, 0.8, 1};
//@E double step = 0.005;
//@E std::vector&lt;double&gt; out = dbeta(vec, a, b, step);
//@E print_nvec(out);
//@E :0: 0 1.24746e-15 1.1697e-06 0.00428754 0.0410157 
//@E 0.00547615 1.23346e-05 1.87358e-10 1.06384e-18 0
//@X

std::vector<double> dbeta(std::vector<double> &x, double &a, double &b, double normalisation_step = 0.1) {
  std::vector<double> rtn_v = {};
  const double divider = std::beta(a + 1, b + 1);
  for (double val : x) {
    rtn_v.push_back(normalisation_step * std::pow(val, a) * std::pow(1 - val, b) / divider);    
  };
  return rtn_v;
};

//@T pbeta
//@U std::vector&lt;double&gt; pbeta(std::vector&lt;double&gt; &x, double &a, double &b, double step = 0.01)
//@X
//@D Returns the beta cumulative probability distribution, of an interval of the first input value to the last input value (from the input vector of probabilities)
//@A x : is the vector of the probabilities, must be ascendly sorted
//@A a : is alpha, the number of successes
//@A b : is beta, the number of failures
//@A step : the lower this value is, the more accurate the result will be at a computational cost
//@X
//@E double a = 40;
//@E double b = 60;
//@E std::vector&lt;double&gt; vec = {0, 0.1, 0.2, 0.3, 0.4, 0.5, 0.6, 0.7, 0.8, 1};
//@E double step = 0.005;
//@E std::vector&lt;double&gt; out = pbeta(vec, a, b, step);
//@E print_nvec(out);
//@E :0: 0 2.65054e-16 1.23119e-06 0.0129867 0.468685 0.974149 
//@E 0.999966 1 1 1
//@X

std::vector<double> pbeta(std::vector<double> &x, double &a, double &b, double step = 0.01) {
  std::vector<double> rtn_v = {};
  const double divider = std::beta(a + 1, b + 1);
  double cnt = x[0];
  double cur_rslt = step * std::pow(cnt, a) * std::pow(1 - cnt, b) / divider;
  for (double val : x) {
    while (cnt < val) {
      cur_rslt += step * std::pow(cnt, a) * std::pow(1 - cnt, b) / divider;
      cnt += step;
    };
    rtn_v.push_back(cur_rslt);
  };
  return rtn_v;
};

//@T qbeta
//@U std::vector&lt;double&gt; qbeta(std::vector&lt;double&gt; &x, double &a, double &b, double step = 0.01)
//@X
//@D Returns the quantile of given probabilities according to the beta probability distribution
//@A x : is the vector of probabilities you want the probabilities from
//@A a : is alpha, the number of successes
//@A b : is beta, the number of failures
//@A step : the lower this value is, the more accurate the result will be at a computational cost
//@X
//@E double a = 40;
//@E double b = 60;
//@E std::vector&lt;double&gt; vec = {0.3, 0.55, 0.9, 0.99};
//@E double step = 0.005;
//@E std::vector&lt;double&gt; out = qbeta(vec2, a, b, step);
//@E print_nvec(out);
//@X

std::vector<double> qbeta(std::vector<double> &x, double &a, double &b, double step = 0.01) {
  std::vector<double> rtn_v = {};
  const double divider = std::beta(a + 1, b + 1);
  double cur_x = 0;
  double cur_proba = 0;
  for (double val : x) {
    while (cur_proba < val) {
      cur_proba += step * std::pow(cur_x, a) * std::pow(1 - cur_x, b) / divider;
      cur_x += step;
    };
    rtn_v.push_back(cur_x);
  };
  return rtn_v;
};

//@T rbeta
//@U std::vector&lt;double&gt; rbeta(unsigned int &n, double &a, double &b, double step = 0.01)
//@X
//@D Returns pseudo-ranomly value that follow a beta probability distribution
//@A n : is the number of observations, values to generate
//@A a : is alpha, the number of successes
//@A b : is beta, the number of failures
//@A step : the lower this value is, the more accurate the result will be. Have to be lowered if the output starts having clone values, it can happen when n is very high
//@X
//@E double a = 40;
//@E double b = 60;
//@E std::vector&lt;double&gt; vec = {0.3, 0.55, 0.9, 0.99};
//@E double step = 0.005;
//@E unsigned int n = 100;
//@E std::vector&lt;double&gt; out = rbeta(n, a, b, step);
//@E print_nvec(out);
//@E :0: 0.29716 0.31027 0.31901 0.32338 0.32775 0.33212
//@E 0.33649 0.34086 0.34086 0.34523 0.34523 0.3496 0.35397
//@E 0.35397 0.35397 0.35834 0.35834 0.36271 0.36271 0.36708
//@E 0.36708 0.36708 0.37145 0.37145
//@E :25: 0.37582 0.37582 0.37582 0.38019 0.38019 0.38019 
//@E 0.38456 0.38456 0.38456 0.38893 0.38893 0.38893 0.38893
//@E 0.3933 0.3933 0.3933 0.39767 0.39767 0.39767 0.39767 
//@E 0.40204 0.40204 0.40204 0.40641
//@E :50: 0.40641 0.40641 0.41078 0.41078 0.41078 0.41515 
//@E 0.41515 0.41515 0.41515 0.41952 0.41952 0.41952 0.42389
//@E 0.42389 0.42389 0.42389 0.42826 0.42826 0.42826 0.43263
//@E 0.43263 0.43263 0.437 0.437
//@E :75: 0.44137 0.44137 0.44574 0.44574 0.44574 0.45011 0.45011
//@E 0.45448 0.45448 0.45448 0.45885 0.46322 0.46322 0.46759
//@E 0.46759 0.47196 0.47633 0.47633 0.4807 0.48507 0.49381 0.49818
//@E 0.50692 0.52003
//@E :100: 0.3933
//@X

std::vector<double> rbeta(unsigned int &n, double &a, double &b, double step = 0.01) {
  double proba_step = (double)1 / n;
  double proba_cnt = proba_step;
  auto now = std::chrono::system_clock::now();
  auto duration = now.time_since_epoch();
  double now_time = std::chrono::duration_cast<std::chrono::microseconds>(duration).count() % 100;
  if ((int)now_time % 2 == 0) {
    step += 0.2 * step * now_time / 100;
  } else {
    step -= 0.2 * step * now_time / 100;
  };
  std::vector<double> rtn_v = {};
  const double divider = std::beta(a + 1, b + 1);
  double cur_x = 0;
  double cur_proba = 0;
  double lst_val1;
  double lst_val2;
  for (unsigned int i = 1; i < n; ++i) {
    while (cur_proba < proba_cnt) {
      cur_proba += step * std::pow(cur_x, a) * std::pow(1 - cur_x, b) / divider;
      cur_x += step;
    };
    proba_cnt += proba_step;
    rtn_v.push_back(cur_x);
  };
  lst_val1 = rtn_v[(int)now_time % (n - 1)];
  lst_val2 = rtn_v[(int)(now_time * 5) % (n - 1)];
  rtn_v.push_back(0.5 * (lst_val1 + lst_val2));
  return rtn_v;
};

//@L4 Chi Square distribution

//@T dchisq
//@U std::vector&lt;double&gt; dchisq(std::vector&lt;double&gt; &x, double &degf)
//@X
//@D Returns the chi square density probability function
//@A x : is the input vector of quantiles
//@A degf : is the degree of freedom
//@X
//@E std::vector&lt;double&gt; vec = {180, 200, 210, 250, 290, 310};
//@E double degf = 240;
//@E std::vector&lt;double&gt; out = dchisq(vec, degf);
//@E print_nvec(out);
//@E :0: 0.000263702 0.00333664 0.00747074 0.0157848 
//@E 0.00152353 0.000193457
//@X

std::vector<double> dchisq(std::vector<double> &x, double &degf) {
  std::vector<double> rtn_v = {};
  double mid_degf = degf / 2;
  const double divider = pow(2, mid_degf) * std::tgamma(mid_degf);
  const double mid_degf_min = mid_degf - 1;
  const double mean = degf;
  const double sd = std::pow(2 * degf, 0.5);
  if (mid_degf < 172) {
    for (double val : x) {
      rtn_v.push_back((pow(val, mid_degf_min) * std::exp(-0.5 * val)) / divider);
    };
  } else {
    for (double val : x) {
      rtn_v.push_back(std::exp(-0.5 * std::pow((val - mean) / sd, 2)) / (sd * std::pow(2 * M_PI, 0.5)));
    };
  };
  return rtn_v;
};

//@T pchisq
//@U std::vector&lt;double&gt; pchisq(std::vector&lt;double&gt; &x, double &degf, double step = 0.05)
//@X
//@D Returns the chi square cumulative probability function
//@A x : is the input vector of quantiles, must be ascendly sorted
//@A degf : is the degree of freedom
//@A step : the lower this value is the more accurate the result will be at a computational cost
//@X
//@E std::vector&lt;double&gt; vec = {180, 200, 210, 250, 290, 310};
//@E double degf = 240;
//@E std::vector&lt;double&gt; out = pchisq(vec, degf);
//@E print_nvec(out);
//@E :0: 1.31851e-05 0.0266942 0.0790938 0.682744 
//@E 0.983524 0.996995
//@X

std::vector<double> pchisq(std::vector<double> &x, double &degf, double step = 0.05) {
  std::vector<double> rtn_v = {};
  double mid_degf = degf / 2;
  const double divider = pow(2, mid_degf) * std::tgamma(mid_degf);
  const double mid_degf_min = mid_degf - 1;
  const double mean = degf;
  const double sd = std::pow(2 * degf, 0.5);
  double cur_x = x[0];
  double cur_proba = 0;
  if (mid_degf < 172) {
    for (double val : x) {
      while (cur_x <= val) {
        cur_proba += (step * pow(cur_x, mid_degf_min) * std::exp(-0.5 * cur_x)) / divider;
        cur_x += step;
      };
      rtn_v.push_back(cur_proba);
    };
  } else {
    for (double val : x) {
      while (cur_x <= val) {
        cur_proba += step * std::exp(-0.5 * std::pow((cur_x - mean) / sd, 2)) / (sd * std::pow(2 * M_PI, 0.5));
        cur_x += step;
      };
      rtn_v.push_back(cur_proba);
    };
  };
  return rtn_v;
};

//@T qchisq
//@U std::vector&lt;double&gt; qchisq(std::vector&lt;double&gt; &x, double &degf, double step = 0.05)
//@X
//@D Returns the probability of the input quantile values
//@A x : is the input vector of probabilities, must be ascendly sorted
//@A degf : is the degree of freedom
//@A step : th lower this value is the more accurate the result will be at a computational cost
//@X
//@E std::vector&lt;double&gt; vec2 = {0.2, 0.45, 0.56, 0.69, 0.88};
//@E double degf = 240;
//@E std::vector&lt;double&gt; out = qchisq(vec2, degf);
//@E print_nvec(out);
//@E :0: 221.45 236.65 242.7 250.4 266
//@X

std::vector<double> qchisq(std::vector<double> &x, double &degf, double step = 0.05) {
  std::vector<double> rtn_v = {};
  double mid_degf = degf / 2;
  const double divider = pow(2, mid_degf) * std::tgamma(mid_degf);
  const double mid_degf_min = mid_degf - 1;
  const double mean = degf;
  const double sd = std::pow(2 * degf, 0.5);
  double cur_x = 0;
  double cur_proba = 0;
  if (mid_degf < 172) {
    for (double val : x) {
      while (cur_proba < val) {
        cur_proba += (step * pow(cur_x, mid_degf_min) * std::exp(-0.5 * cur_x)) / divider;
        cur_x += step;
      };
      rtn_v.push_back(cur_x);
    };
  } else {
    for (double val : x) {
      while (cur_proba < val) {
        cur_proba += step * std::exp(-0.5 * std::pow((cur_x - mean) / sd, 2)) / (sd * std::pow(2 * M_PI, 0.5));
        cur_x += step;
      };
      rtn_v.push_back(cur_x);
    };
  };
  return rtn_v;
};

//@T rchisq
//@U std::vector&lt;double&gt; rchisq(unsigned int &n, double &degf, double step = 0.05)
//@X
//@D Returns pseudo-random values that follow a chi square probability distribution
//@A n : is the number of observations
//@A degf : is the degree of freedom
//@A step : the lower it is the more accurate the result is. Have to be lowered if the output begins to have clone values. It can happen if n is very high
//@X
//@E unsigned int n = 100;
//@E double degf = 240;
//@E std::vector<double> out = rchisq(n, degf);
//@E print_nvec(out);
//@E :0: 192.049 197.248 200.571 203.09 205.181 206.95 
//@E 208.558 209.951 211.238 212.417 213.542 214.614 215.579 
//@E 216.544 217.402 218.313 219.117 219.921 220.671 221.422 
//@E 222.172 222.869 223.566 224.262
//@E :25: 225.602 226.246 226.889 227.478 228.122 228.711 
//@E 229.301 229.89 230.48 231.07 231.606 232.195 232.785 
//@E 233.321 233.91 234.446 234.982 235.572 236.108 236.644 
//@E 237.18 237.77 238.306 238.842
//@E :50: 239.914 240.503 241.039 241.575 242.165 242.701 
//@E 243.29 243.826 244.416 244.952 245.542 246.131 246.721 
//@E 247.31 247.9 248.543 249.133 249.776 250.419 251.062 251.706 
//@E 252.349 253.046 253.742
//@E :75: 255.19 255.94 256.69 257.441 258.245 259.102 259.96 260.871 
//@E 261.782 262.801 263.819 264.891 266.017 267.25 268.536 269.93 
//@E 271.43 273.146 275.022 277.166 279.738 282.901 287.189 293.942
//@E :100: 223.914
//@X

std::vector<double> rchisq(unsigned int &n, double &degf, double step = 0.05) {
  auto now = std::chrono::system_clock::now();
  auto duration = now.time_since_epoch();
  double now_time = std::chrono::duration_cast<std::chrono::microseconds>(duration).count() % 100;
  if ((int)now_time % 2 == 0) {
    step += 0.3 * step * now_time / 100;
  } else {
    step -= 0.3 * step * now_time / 100;
  };
  std::vector<double> rtn_v = {};
  double mid_degf = degf / 2;
  const double divider = pow(2, mid_degf) * std::tgamma(mid_degf);
  const double mid_degf_min = mid_degf - 1;
  const double mean = degf;
  const double sd = std::pow(2 * degf, 0.5);
  double cur_x = 0;
  double cur_proba = 0;
  const double ref_proba = (double)1 / n;
  double proba_cnt = ref_proba;
  double last_val1;
  double last_val2;
  if (mid_degf < 172) {
    for (unsigned int i = 1; i < n; ++i) {
      while (cur_proba < proba_cnt) {
        cur_proba += (step * pow(cur_x, mid_degf_min) * std::exp(-0.5 * cur_x)) / divider;
        cur_x += step;
      };
      proba_cnt += ref_proba;
      rtn_v.push_back(cur_x);
    };
  } else {
    for (unsigned int i = 1; i < n; ++i) {
      while (cur_proba < proba_cnt) {
        cur_proba += step * std::exp(-0.5 * std::pow((cur_x - mean) / sd, 2)) / (sd * std::pow(2 * M_PI, 0.5));
        cur_x += step;
      };
      proba_cnt += ref_proba;
      rtn_v.push_back(cur_x);
    };
  };
  last_val1 = rtn_v[(int)now_time % (n - 1)];
  last_val2 = rtn_v[(int)now_time * 5 % (n - 1)];
  rtn_v.push_back(0.5 * (last_val1 + last_val2));
  return rtn_v;
};

//@T test_chisq_fit
//@U bool test_chisq_fit(std::vector&lt;double&gt; theoretical, std::vector&lt;double&gt; observed, double a_value = 0.05, double step = 0.05)
//@X
//@D Performs a chi square goodness of fit test. Returns 1 if the observed values fit the observed values at a given p_value, 0 else
//@A theoretical : is the vector containing all the theoretical data
//@A observed : is the vector containing all the observed data
//@A a_value : is the significance level
//@A step : the lower this value is the more accurate the result wil be at a computational cost
//@X
//@E std::vector<double> theoretical = {20, 20, 30, 40, 60, 30};
//@E std::vector<double> observed = {30, 14, 34, 45, 57, 20};
//@E double a_value = 0.05;
//@E bool out = test_chisq_fit(theoretical, observed, a_value);
//@E 0 // the observed data does not fit the theoretical data
//@X

//@T test_chisq_independance
//@U bool test_chisq_independance(std::vector&lt;std::vector&lt;double&gt;&gt; &matr, double a_value = 0.05, double step = 0.05)
//@X
//@D Performs a chi square independance test. Returns 0 if the variables are independant, 1 else
//@A matr is the input matrice (observed values)
//@A a_value : is the significance level (the greater it is the more likely the 2 variables will be percieved as independant) 
//@A step : the lower this value is the more accurate the result will be at a computational cost
//@X
//@E std::vector&lt;std::vector&lt;double&gt;&gt; matr = {{8, 16, 11, 10}, 
//@E                                            {9, 27, 22, 16}, 
//@E                                            {7, 13, 8, 12},
//@E                                            {9, 13, 12, 7}};
//@E print_matr(matr);
//@E double step = 0.05;
//@E double a_value = 0.05;
//@E bool out = test_chisq_independance(matr, a_value, step);
//@E 0 // the variables are independant
//@X

//@L4 Geometric distributions

//@T dgeom
//@U std::vector&lt;double&gt; dgeom(std::vector&lt;unsigned int&gt; &x, double &p)
//@X
//@D Returns the geometric density probability distribution
//@A x : is the input vector of quantiles, representing the number of failures before success
//@A p : is the probability of success
//@X
//@E std::vector&lt;unsigned int&gt; vec = {2, 3, 4, 5};
//@E double p = (double)1 / 6;
//@E std::vector&lt;double&gt; out = dgeom(vec, p);
//@E print_nvec(out);
//@E :0: 0.115741 0.0964506 0.0803755 0.0669796
//@X

std::vector<double> dgeom(std::vector<unsigned int> &x, double &p) {
  std::vector<double> rtn_v = {};
  rtn_v.reserve(x.size());
  const double failure = 1 - p;
  for (unsigned int val : x) {
    rtn_v.push_back(std::pow(failure, val) * p);
  };
  return rtn_v;
};

//@T pgeom
//@U std::vector&lt;double&gt; pgeom(std::vector&lt;unsigned int&gt; &x, double &p)
//@X
//@D Returns the geometric cumulative probability distribution (interval between firts value in vector and last, see example)
//@A x : is the input vector of quantiles, representing the number of failures before success, must be ascendly sorted
//@A p : is the probability of success
//@X
//@E std::vector&lt;unsigned int&gt; vec = {2, 3, 4, 5};
//@E double p = (double)1 / 6;
//@E std::vector&lt;double&gt; out = pgeom(vec, p);
//@E print_nvec(out);
//@E :0: 0.115741 0.212191 0.292567 0.359546
//@X

std::vector<double> pgeom(std::vector<unsigned int> &x, double &p) {
  std::vector<double> rtn_v = {};
  const unsigned int n = x.size();
  rtn_v.reserve(n);
  const double failure = 1 - p;
  double cnt = x[0];
  double cur_prob = std::pow(failure, cnt) * p;
  rtn_v.push_back(cur_prob);
  if (n > 1) {
    cnt += 1;
    for (unsigned int i = 1; i < n; ++i) {
      while (cnt - 1 < x[i]) {
        cur_prob += std::pow(failure, cnt) * p;
        cnt += 1;
      };
      rtn_v.push_back(cur_prob);
    };
  };
  return rtn_v;
};

//@T qgeom
//@U std::vector&lt;unsigned int&gt; qgeom(std::vector&lt;double&gt; &x, double &p)
//@X
//@D Returns the quantiles of the input probabilities according to a geometric probability distribution
//@A x : is the input vector of probabilities, must be ascendly sorted
//@A p : is the probability of success
//@X
//@E std::vector&lt;double&gt; vec2 = {0.2, 0.3, 0.5, 0.52, 0.6, 0.85};
//@E double p = (double)1 / 6;
//@E std::vector&lt;unsigned int&gt; out = qgeom(vec2, p);
//@E print_nvec(out);
//@E :0: 1  1  3  4  5  10
//@X

std::vector<unsigned int> qgeom(std::vector<double> &x, double &p) {
  std::vector<unsigned int> rtn_v = {};
  const unsigned int n = x.size();
  rtn_v.reserve(n);
  const double failure = 1 - p;
  double cnt = 0;
  double cur_prob = 0;
  for (double val : x) {
    while (cur_prob < val) {
      cur_prob += std::pow(failure, cnt) * p;
      cnt += 1;
    };
    rtn_v.push_back(cnt - 1);
  };
  return rtn_v;
};

//@T rgeom
//@U std::vector&lt;unsigned int&gt; rgeom(unsigned int &n, double &p)
//@X
//@D Returns pseudo-randomly generated values that follow a geometric distribution
//@A n : is the number of observations
//@A p : is the probability of success
//@X
//@E double p = (double)2 / 9;
//@E unsigned int n = 100;
//@E std::vector&lt;unsigned int&gt; out = rgeom(n, p);
//@E print_nvec(out);
//@E :0: 8  13 3  0  4  2  0  4  2  11 4  1  12 3  9  
//@E 5  2  10 15 7  0  5  7  2
//@E :25: 8  4  3  9  17 2  10 5  2  1  4  8  12 6  1  
//@E 5  6  9  4  2  0  5  2  1
//@E :50: 8  2  6  1  13 6  0  4  7  1  4  7  1  5  1  
//@E 4  3  9  4  2  10 5  2  10
//@E :75: 1  12 3  8  17 2  9  4  2  11 6  8  3  6  0  
//@E 5  7  10 5  2  2  3  1  13
//@E :100: 6
//@X

//@L4 Hypergeometric distribution

//@T dhyper
//@U std::vector&lt;double&gt; dhyper(std::vector&lt;int&gt; &x, unsigned int &n_ones, unsigned int &n_others, int &n_trials)
//@X
//@D Returns the hypergeometric probability distribution
//@A x : is the vector of quantiles
//@A n_ones : is the number of desired elements in the set
//@A n_others : is the number of undesired elements in the set
//@A n_trials : is the number of drawns
//@X
//@E unsigned int n_others = 1300;
//@E unsigned int n_ones = 415;
//@E std::vector&lt;int&gt; x = {150, 190, 400};
//@E int n_trials = 555;
//@E std::vector&lt;double&gt; out  = dhyper(x, n_ones, n_others, n_trials);
//@E print_nvec(out);
//@E :0: 0.00807227 1.69452e-11 4.42674e-236
//@X

std::vector<double> dhyper(std::vector<int> &x, unsigned int &n_ones, unsigned int &n_others, int &n_trials) {
  std::vector<double> rtn_v;
  unsigned int n_tot;
  double n_ones_left;
  double cur_prob;
  const int ref_n_tot = n_ones + n_others;
  if (n_trials > ref_n_tot) {
    return {0};
  };
  const int ref_n_ones = n_ones;
  int i;
  double divided_trial;
  int goal_bottom;
  for (int n_desired : x) {
    if (n_desired <= n_trials) {
      divided_trial = n_trials;
      n_tot = ref_n_tot;
      n_ones_left = ref_n_ones;
      i = n_desired;
      if (i > 0) {
        cur_prob = n_ones_left / n_tot * divided_trial / i;
        n_ones_left -= 1;
        n_tot -= 1;
        i -= 1;
        divided_trial -= 1;
        while (i > 0) {
          cur_prob *= (n_ones_left / n_tot) * divided_trial / i;
          divided_trial -= 1;
          n_ones_left -= 1;
          n_tot -= 1;
          i -= 1;
        };
      } else {
        cur_prob = 1;
      };
      goal_bottom = n_desired - n_trials;
      while (i > goal_bottom) {
        cur_prob *= (1 - n_ones_left / n_tot);
        n_tot -= 1;
        i -= 1;
      };
      rtn_v.push_back(cur_prob);
    } else {
      rtn_v.push_back(0);
    };
  };
  return rtn_v;
};

//@T phyper
//@U std::vector&lt;double&gt; phyper(std::vector&lt;int&gt; &x, unsigned int &n_ones, unsigned int &n_others, int &n_trials)
//@X
//@D Returns the cumulative hypergeometric distribution (interval between the first value of the input quantiles and last value)
//@A x : is the vector of qualtiles
//@A n_ones : is the number of desired elements in the set
//@A n_others : is the number of undesired elements in the set
//@A n_trials : is the number of drawns
//@X
//@E unsigned int n_others = 1300;
//@E unsigned int n_ones = 415;
//@E std::vector&lt;int&gt; x = {0, 150};
//@E 
//@E int n_trials = 555;
//@E
//@E std::vector&lt;double&gt; out_v = phyper(x, n_ones, n_others, n_trials);
//@E
//@E print_nvec(out_v);
//@E
//@E :0: 2.59543e-84 0.973988
//@E
//@X

std::vector<double> phyper(std::vector<int> &x, unsigned int &n_ones, unsigned int &n_others, int &n_trials) {
  std::vector<double> rtn_v;
  unsigned int n_tot;
  double n_ones_left;
  double cur_prob;
  double rtn_prob = 0;
  unsigned int cnt = 0;
  const int ref_n_tot = n_ones + n_others;
  if (n_trials > ref_n_tot) {
    return {0};
  };
  const int ref_n_ones = n_ones;
  const unsigned int n = x.size();
  int i;
  double divided_trial;
  int goal_bottom;
  const int stop_val = x[x.size() - 1];
  int n_desired = x[0];
  if (n_desired > n_trials) {
    return {};
  };
  while (n_desired <= stop_val) {
    divided_trial = n_trials;
    n_tot = ref_n_tot;
    n_ones_left = ref_n_ones;
    i = n_desired;
    if (i > 0) {
      cur_prob = n_ones_left / n_tot * divided_trial / i;
      n_ones_left -= 1;
      n_tot -= 1;
      i -= 1;
      divided_trial -= 1;
      while (i > 0) {
        cur_prob *= (n_ones_left / n_tot) * divided_trial / i;
        divided_trial -= 1;
        n_ones_left -= 1;
        n_tot -= 1;
        i -= 1;
      };
    } else {
      cur_prob = 1;  
    };
    goal_bottom = n_desired - n_trials;
    while (i > goal_bottom) {
      cur_prob *= (1 - n_ones_left / n_tot);
      n_tot -= 1;
      i -= 1;
    };
    rtn_prob += cur_prob;
    if (n_desired == x[cnt]) {
      rtn_v.push_back(rtn_prob);
      cnt += 1;
    };
    n_desired += 1;
  };
  return rtn_v;
};

//@T qhyper
//@U std::vector&lt;unsigned int&gt; qhyper(std::vector&lt;double&gt; &x, unsigned int &n_ones, unsigned int &n_others, int &n_trials)
//@X
//@D Returns the quantiles of the input probabilities according to the hypergeometric probability distribution.
//@A x : is the vector of the input probabilities, must be ascendly sorted
//@A n_ones : is the number of desired elements in the set
//@A n_others : is the number of undesired elements in the set
//@A n_trials : is the number of drawns
//@X
//@E unsigned int n_others = 1300;
//@E unsigned int n_ones = 415;
//@E std::vector&lt;double&gt; x = {0.05, 0.12, 0.35, 0.36, 0.36, 0.56, 0.78};
//@E 
//@E int n_trials = 555;
//@E
//@E std::vector&lt;unsigned int&gt; out_v = qhyper(x, n_ones, n_others, n_trials);
//@E
//@E print_nvec(out_v);
//@E
//@E :0: 121 124 131 131 131 135 139
//@X

std::vector<unsigned int> qhyper(std::vector<double> &x, unsigned int &n_ones, unsigned int &n_others, int &n_trials) {
  std::vector<unsigned int> rtn_v;
  unsigned int n_tot;
  double n_ones_left;
  double cur_prob;
  double rtn_prob = 0;
  double lst_rtn_prob = 0;
  const int ref_n_tot = n_ones + n_others;
  if (n_trials > ref_n_tot) {
    return {0};
  };
  const int ref_n_ones = n_ones;
  const unsigned int n = x.size();
  int i;
  double divided_trial;
  double p_delta1;
  double p_delta2;
  int goal_bottom;
  unsigned int n_desired = 0;
  const int stop_val = x[x.size() - 1];
  for (double p_desired : x) {
    while (rtn_prob < p_desired) {
      lst_rtn_prob = rtn_prob;
      divided_trial = n_trials;
      n_tot = ref_n_tot;
      n_ones_left = ref_n_ones;
      i = n_desired;
      if (i > 0) {
        cur_prob = n_ones_left / n_tot * divided_trial / i;
        n_ones_left -= 1;
        n_tot -= 1;
        i -= 1;
        divided_trial -= 1;
        while (i > 0) {
          cur_prob *= (n_ones_left / n_tot) * divided_trial / i;
          divided_trial -= 1;
          n_ones_left -= 1;
          n_tot -= 1;
          i -= 1;
        };
      } else {
        cur_prob = 1;  
      };
      goal_bottom = n_desired - n_trials;
      while (i > goal_bottom) {
        cur_prob *= (1 - n_ones_left / n_tot);
        n_tot -= 1;
        i -= 1;
      };
      rtn_prob += cur_prob;
      n_desired += 1;
    };
    p_delta1 = p_desired - lst_rtn_prob;
    p_delta2 = rtn_prob - p_desired;
    if (p_delta1 < p_delta2) {
      rtn_v.push_back(n_desired - 1);
    } else {
      rtn_v.push_back(n_desired);
    };
  };
  return rtn_v;
};

//@T rhyper
//@U std::vector&lt;unsigned int&gt; rhyper(unsigned int &n_obs, unsigned int &n_ones, unsigned int n_others, int &n_trials)
//@X
//@D Returns pseudo-randomly generated values that follow a hypergeometric distribution
//@A n_obs : is the number of observations
//@A n_ones : is the number of desired elements in the set
//@A n_others : is the number of undesired elements in the set
//@A n_trials : is the number of drawns
//@X
//@E unsigned int n_others = 1300;
//@E unsigned int n_ones = 415;
//@E 
//@E int n_trials = 555;
//@E unsigned int n_obs = 12;
//@E
//@E std::vector&lt;unsigned int&gt; out_v = rhyper(n_obs, n_ones, n_others, n_trials);
//@E
//@E print_nvec(out_v);
//@E
//@E :0: 129 133 136 139 143 149 124 129 133 136 139 143
//@X

//@L3 Operations between vectors

//@T add_vout
//@U template &lt;typename T, typename T2&gt; std::vector&lt;T&gt; add_vout(std::vector&lt;T&gt; x, T2 &to_add)
//@X
//@D Adds a value to all elements of the input vector, returns the vector.
//@A x : is the input vector
//@A to_add : is the value to add
//@X
//@E std::vector&lt;double&gt; inv = {2, 5, 1, 4};
//@E double val = 4.3;
//@E std::vector&lt;double&gt; outv = add_vout(inv, val);
//@E print_nvec(outv);
//@E :0: 6.3 9.3 5.3 8.3
//@X

template <typename T, typename T2> std::vector<T> add_vout(std::vector<T> x, T2 &to_add) {
  for (unsigned int i = 0; i < x.size(); ++i) {
    x[i] += to_add;
  };
  return x;
};

//@T subs_vout
//@U template &lt;typename T, typename T2&gt; std::vector&lt;T&gt; subs_vout(std::vector&lt;T&gt; x, T2 &to_subs)
//@X
//@D Substracts a value to all elements of the input vector, returns the vector.
//@A x : is the input vector
//@A to_substract : is the value to substract
//@X
//@E std::vector&lt;double&gt; inv = {2, 5, 1, 4};
//@E double val = 4.3;
//@E std::vector&lt;double&gt; outv = subs_vout(inv, val);
//@E print_nvec(outv);
//@E :0: -2.3 0.7  -3.3 -0.3
//@X

template <typename T, typename T2> std::vector<T> subs_vout(std::vector<T> x, T2 &to_subs) {
  for (unsigned int i = 0; i < x.size(); ++i) {
    x[i] -= to_subs;
  };
  return x;
};

//@T mult_vout
//@U template &lt;typename T, typename T2&gt; std::vector&lt;T&gt; mult_vout(std::vector&lt;T&gt; x, T2 &to_mult)
//@X
//@D Multiplicates a value to all elements of the input vector, returns the vector.
//@A x : is the input vector
//@A to_multiplicate : is the value to multiplicate
//@X
//@E std::vector&lt;double&gt; inv = {2, 5, 1, 4};
//@E double val = 4.3;
//@E std::vector&lt;double&gt; outv = mult_vout(inv, val);
//@E print_nvec(outv);
//@E :0: 8.6  21.5 4.3  17.2
//@X

template <typename T, typename T2> std::vector<T> mult_vout(std::vector<T> x, T2 &to_mult) {
  for (unsigned int i = 0; i < x.size(); ++i) {
    x[i] *= to_mult;
  };
  return x;
};

//@T divide_vout
//@U template &lt;typename T, typename T2&gt; std::vector&lt;T&gt; divide_vout(std::vector&lt;T&gt; x, T2 &to_divide)
//@X
//@D Divides a value to all elements of the input vector, returns the vector.
//@A x : is the input vector
//@A to_divide : is the value to divide
//@X
//@E std::vector&lt;double&gt; inv = {2, 5, 1, 4};
//@E double val = 4.3;
//@E std::vector&lt;double&gt; outv = divide_vout(inv, val);
//@E print_nvec(outv);
//@E :0: 0.465116 1.16279 0.232558 0.930233
//@X

template <typename T, typename T2> std::vector<T> divide_vout(std::vector<T> x, T2 &to_divide) {
  for (unsigned int i = 0; i < x.size(); ++i) {
    x[i] /= to_divide;
  };
  return x;
};

//@T add_vin
//@U template &lt;typename T, typename T2&gt; void add_vin(std::vector&lt;T&gt; &x, T2 &to_add)
//@X
//@D Adds a value to all elements of the input vector.
//@A x : is the input vector
//@A to_add : is the value to add
//@X
//@E std::vector&lt;double&gt; inv = {2, 5, 1, 4};
//@E double val = 4.3;
//@E add_vin(inv, val);
//@E print_nvec(inv);
//@E :0: 6.3 9.3 5.3 8.3
//@X

template <typename T, typename T2> void add_vin(std::vector<T> &x, T2 &to_add) {
  for (unsigned int i = 0; i < x.size(); ++i) {
    x[i] += to_add;
  };
};

//@T subs_vin
//@U template &lt;typename T, typename T2&gt; void subs_vin(std::vector&lt;T&gt; &x, T2 &to_subs)
//@X
//@D Substracts a value to all elements of the input vector.
//@A x : is the input vector
//@A to_subs : is the value to substract
//@X
//@E std::vector&lt;double&gt; inv = {2, 5, 1, 4};
//@E double val = 4.3;
//@E subs_vin(inv, val);
//@E print_nvec(inv);
//@E :0: -2.3 0.7  -3.3 -0.3
//@X

template <typename T, typename T2> void subs_vin(std::vector<T> &x, T2 &to_subs) {
  for (unsigned int i = 0; i < x.size(); ++i) {
    x[i] -= to_subs;
  };
};

//@T mult_vin
//@U template &lt;typename T, typename T2&gt; void mult_vin(std::vector&lt;T&gt; &x, T2 &to_mult)
//@X
//@D Multiplicates a value to all elements of the input vector.
//@A x : is the input vector
//@A to_mult : is the value to multiplicate
//@X
//@E std::vector&lt;double&gt; inv = {2, 5, 1, 4};
//@E double val = 4.3;
//@E mult_vin(inv, val);
//@E print_nvec(inv);
//@E :0: 8.6  21.5 4.3  17.2
//@X

template <typename T, typename T2> void mult_vin(std::vector<T> &x, T2 &to_mult) {
  for (unsigned int i = 0; i < x.size(); ++i) {
    x[i] *= to_mult;
  };
};

//@T divide_vin
//@U template &lt;typename T, typename T2&gt; void divide_vin(std::vector&lt;T&gt; &x, T2 &to_divide)
//@X
//@D Divides a value to all elements of the input vector.
//@A x : is the input vector
//@A to_divide : is the value to divide
//@X
//@E std::vector&lt;double&gt; inv = {2, 5, 1, 4};
//@E double val = 4.3;
//@E divide_vin(inv, val);
//@E print_nvec(inv);
//@E :0: 0.465116 1.16279 0.232558 0.930233
//@X

template <typename T, typename T2> void divide_vin(std::vector<T> &x, T2 &to_divide) {
  for (unsigned int i = 0; i < x.size(); ++i) {
    x[i] /= to_divide;
  };
};

//@T add_v2out
//@U template &lt;typename T, typename T2&gt; std::vector&lt;T&gt; 
//@U                 add_v2out(std::vector&lt;T&gt; x, 
//@U                 std::vector&lt;T2&gt; &x2)
//@X
//@D Add corresponding elements of 2 vectors, returns vector.
//@A x : is the first vector
//@A x2 : is the second vector
//@X
//@E std::vector&lt;double&gt; inv = {2, 5, 1, 4};
//@E std::vector&lt;double&gt; inv2 = {2, 5};
//@E 
//@E double val = 4.3;
//@E 
//@E std::vector&lt;double&gt; outv = add_v2out(inv, inv2);
//@E 
//@E print_nvec(outv);
//@E :0: 4 10 3 9
//@X

template <typename T, typename T2> std::vector<T> add_v2out(std::vector<T> x, 
                std::vector<T2> &x2) {
  const unsigned int n = x.size();
  const unsigned int n2 = x2.size();
  for (unsigned int i = 0; i < n; ++i) {
    x[i] += x2[i % n2];
  };
  return x;
};

//@T subs_v2out
//@U template &lt;typename T, typename T2&gt; std::vector&lt;T&gt; 
//@U                 subs_v2out(std::vector&lt;T&gt; x, 
//@U                 std::vector&lt;T2&gt; &x2)
//@X
//@D Substracts corresponding elements of 2 vectors, returns vector.
//@A x : is the first vector
//@A x2 : is the second vector
//@X
//@E std::vector&lt;double&gt; inv = {2, 5, 1, 4};
//@E std::vector&lt;double&gt; inv2 = {2, 5};
//@E 
//@E double val = 4.3;
//@E 
//@E std::vector&lt;double&gt; outv = subs_v2out(inv, inv2);
//@E 
//@E print_nvec(outv);
//@E :0: 0  0  -1 -1
//@X

template <typename T, typename T2> std::vector<T> subs_v2out(std::vector<T> x, 
                std::vector<T2> &x2) {
  const unsigned int n = x.size();
  const unsigned int n2 = x2.size();
  for (unsigned int i = 0; i < n; ++i) {
    x[i] -= x2[i % n2];
  };
  return x;
};

//@T mult_v2out
//@U template &lt;typename T, typename T2&gt; std::vector&lt;T&gt; 
//@U                 mult_v2out(std::vector&lt;T&gt; x, 
//@U                 std::vector&lt;T2&gt; &x2)
//@X
//@D Multiplies corresponding elements of 2 vectors, returns vector.
//@A x : is the first vector
//@A x2 : is the second vector
//@X
//@E std::vector&lt;double&gt; inv = {2, 5, 1, 4};
//@E std::vector&lt;double&gt; inv2 = {2, 5};
//@E 
//@E double val = 4.3;
//@E 
//@E std::vector&lt;double&gt; outv = mult_v2out(inv, inv2);
//@E 
//@E print_nvec(outv);
//@E :0: 4  25 2  20
//@X

template <typename T, typename T2> std::vector<T> mult_v2out(std::vector<T> x, 
                std::vector<T2> &x2) {
  const unsigned int n = x.size();
  const unsigned int n2 = x2.size();
  for (unsigned int i = 0; i < n; ++i) {
    x[i] *= x2[i % n2];
  };
  return x;
};

//@T divide_v2out
//@U template &lt;typename T, typename T2&gt; std::vector&lt;T&gt; 
//@U                 divide_v2out(std::vector&lt;T&gt; x, 
//@U                 std::vector&lt;T2&gt; &x2)
//@X
//@D Divides corresponding elements of 2 vectors, returns vector.
//@A x : is the first vector
//@A x2 : is the second vector
//@X
//@E std::vector&lt;double&gt; inv = {2, 5, 1, 4};
//@E std::vector&lt;double&gt; inv2 = {2, 5};
//@E 
//@E double val = 4.3;
//@E 
//@E std::vector&lt;double&gt; outv = divide_v2out(inv, inv2);
//@E 
//@E print_nvec(outv);
//@E :0: 1 1 0.5 0.8
//@X

template <typename T, typename T2> std::vector<T> divide_v2out(std::vector<T> x, 
                std::vector<T2> &x2) {
  const unsigned int n = x.size();
  const unsigned int n2 = x2.size();
  for (unsigned int i = 0; i < n; ++i) {
    x[i] /= x2[i % n2];
  };
  return x;
};

//@T add_v2in
//@U template &lt;typename T, typename T2&gt; void add_v2in(std::vector&lt;T&gt; &x, 
//@U                 std::vector&lt;T2&gt; &x2)
//@X
//@D Adds corresponding elements of 2 vectors. 
//@A x : is the first vector
//@A x2 : is the second vector
//@X
//@E 
//@E std::vector&lt;double&gt; inv = {2, 5, 1, 4};
//@E std::vector&lt;double&gt; inv2 = {2, 5};
//@E 
//@E double val = 4.3;
//@E 
//@E add_v2in(inv, inv2);
//@E 
//@E print_nvec(inv);
//@E :0: 4  10 3  9
//@X

template <typename T, typename T2> void add_v2in(std::vector<T> &x, 
                std::vector<T2> &x2) {
  const unsigned int n = x.size();
  const unsigned int n2 = x2.size();
  for (unsigned int i = 0; i < n; ++i) {
    x[i] += x2[i % n2];
  };
};

//@T subs_v2in
//@U template &lt;typename T, typename T2&gt; void subs_v2in(std::vector&lt;T&gt; &x, 
//@U                 std::vector&lt;T2&gt; &x2)
//@X
//@D Substract corresponding elements of 2 vectors. 
//@A x : is the first vector
//@A x2 : is the second vector
//@X
//@E 
//@E std::vector&lt;double&gt; inv = {2, 5, 1, 4};
//@E std::vector&lt;double&gt; inv2 = {2, 5};
//@E 
//@E double val = 4.3;
//@E 
//@E subs_v2in(inv, inv2);
//@E 
//@E print_nvec(inv);
//@E :0: 0  0  -1 -1
//@X

template <typename T, typename T2> void subs_v2in(std::vector<T> &x, 
                std::vector<T2> &x2) {
  const unsigned int n = x.size();
  const unsigned int n2 = x2.size();
  for (unsigned int i = 0; i < n; ++i) {
    x[i] -= x2[i % n2];
  };
};

//@T mult_v2in
//@U template &lt;typename T, typename T2&gt; void mult_v2in(std::vector&lt;T&gt; &x, 
//@U                 std::vector&lt;T2&gt; &x2)
//@X
//@D Multiplies corresponding elements of 2 vectors. 
//@A x : is the first vector
//@A x2 : is the second vector
//@X
//@E 
//@E std::vector&lt;double&gt; inv = {2, 5, 1, 4};
//@E std::vector&lt;double&gt; inv2 = {2, 5};
//@E 
//@E double val = 4.3;
//@E 
//@E mult_v2in(inv, inv2);
//@E 
//@E print_nvec(inv);
//@E :0: 4  25 2  20
//@X

template <typename T, typename T2> void mult_v2in(std::vector<T> &x, 
                std::vector<T2> &x2) {
  const unsigned int n = x.size();
  const unsigned int n2 = x2.size();
  for (unsigned int i = 0; i < n; ++i) {
    x[i] *= x2[i % n2];
  };
};

//@T divide_v2in
//@U template &lt;typename T, typename T2&gt; void divide_v2in(std::vector&lt;T&gt; &x, 
//@U                 std::vector&lt;T2&gt; &x2)
//@X
//@D Adds corresponding elements of 2 vectors. 
//@A x : is the first vector
//@A x2 : is the second vector
//@X
//@E 
//@E std::vector&lt;double&gt; inv = {2, 5, 1, 4};
//@E std::vector&lt;double&gt; inv2 = {2, 5};
//@E 
//@E double val = 4.3;
//@E 
//@E divide_v2in(inv, inv2);
//@E 
//@E print_nvec(inv);
//@E
//@E :0: 1 1 0.5 0.8
//@E
//@X

template <typename T, typename T2> void divide_v2in(std::vector<T> &x, 
                T2 &x2) {
  const unsigned int n = x.size();
  const unsigned int n2 = x2.size();
  for (unsigned int i = 0; i < n; ++i) {
    x[i] /= x2[i % n2];
  };
};

//@L3 Min - Max

#if 0
//@T min
//@U template &lt;typename T&gt; T min(const std::vector&lt;T&gt; &x)
//@X
//@D Returns the min element from a vector (int, float, double, bool)
//@D For finding the index of the min element refer <a href="#match_min">here</a>
//@A x : is a stl vector (int, float, double, bool)
//@X
//@E std::vector&lt;int&gt; vec = {4, 1, -7};
//@E int out  = min(vec);
//@E -7
//@X
#endif

template <typename T> T min(const std::vector<T> &x) {
  T rtn = x[0];
  for (typename std::vector<T>::const_iterator it = x.begin() + 1; it != x.end(); ++it) {
    if (rtn > *it) {
      rtn = *it;
    };
  };
  return rtn;
};

#if 0
//@T max
//@U template &lt;typename T&gt; T max(const std::vector&lt;T&gt; &x)
//@X
//@D Returns the max element from a vector (int, float, double, bool)
//@D For finding the index of the min element refer <a href="#match_max">here</a>
//@A x : is a stl vector (int, float, double, bool)
//@X
//@E std::vector&lt;int&gt; vec = {4, 1, -7};
//@E int out  = max(vec);
//@E 4
//@X
#endif

template <typename T> T max(const std::vector<T> &x) {
  T rtn = x[0];
  for (typename std::vector<T>::const_iterator it = x.begin() + 1; it != x.end(); ++it) {
    if (rtn < *it) {
      rtn = *it;
    };
  };
  return rtn;
};

//@L3 Mixing 
//@L4 Heuristic (slightly slower)

//@T mixout
//@U template &lt;typename T&gt; void mixout(std::vector&lt;T&gt; &x)
//@X
//@D Returns a stl vector with its elements at different indexes pseudo-randomly chosen.
//@A x : is an stl vector of any type
//@X
//@E std::vector&lt;int&gt; vec;
//@E for (int i = 0; i &lt; 100; ++i) {
//@E   vec.push_back(i);
//@E };
//@E std::vector&lt;int&gt; out = mixout(vec);
//@E print_nvec(out);
//@E   :0: 66 10 51 47 46 57 13 6  85 40 28 55 42 91 61 34 63 12 23 19 79 62 35 84 
//@E  :25: 43 5  54 17 93 90 0  73 9  18 49 71 20 89 70 41 4  56 22 45 2  29 88 31 
//@E  :50: 65 3  75 25 94 77 52 78 39 87 83 27 1  15 24 44 76 99 58 95 92 68 97 26 
//@E  :75: 64 74 11 80 81 69 59 38 8  7  50 14 98 36 82 60 72 32 96 33 37 30 53 67 
//@E :100: 48
//@X

template <typename T> std::vector<T> mixout(std::vector<T> x) {
  auto now = std::chrono::system_clock::now();
  auto duration = now.time_since_epoch();
  double addr = std::chrono::duration_cast<std::chrono::milliseconds>(duration).count();
  addr /= 10;
  unsigned long int valint = addr;
  unsigned int addr2;
  int post_addr;
  if (valint % 9 == 0) {
    addr2 = 3;
  } else if (valint % 7 == 0) {
    addr2 = 4;
  } else if (valint % 8 == 0) {
    addr2 = 7;
  } else if (valint % 6 == 0) {
    addr2 = 9;
  } else if (valint % 3 == 0) {
    addr2 = 13;
  } else if (valint % 4 == 0) {
    addr2 = 1;
  } else if (valint % 2 == 0) { 
    addr2 = 8;
  } else {
    addr2 = 5;
  };
  addr -= valint;
  addr *= 10;
  post_addr = addr;
  if (addr - post_addr > 0.5)  {
    post_addr += 1;
  };
  unsigned long long int v;
  long double n = x.size();
  const unsigned int n2 = n;
  n += 0.5 * n;
  T switchr;
  double mlt = 1;
  while (mlt < n2) {
    mlt *= 10;
  };
  for (unsigned long long int i = 0; i < n2; ++i) {
    switchr = x[i];
    v = abs(sin((((i + 1) * mlt) / n))) * n2 + post_addr + addr2;
    v = v % n2;
    x[i] = x[v];
    x[v] = switchr;
  };
  return x;
};

//@T mixin
//@U template &lt;typename T&gt; void mixin(std::vector&lt;T&gt; &x)
//@X
//@D Transforms a stl vector with its elements at different indexes pseudo-randomly chosen.
//@A x : is an stl vector of any type
//@X
//@E std::vector&lt;int&gt; vec;
//@E for (int i = 0; i &lt; 100; ++i) {
//@E   vec.push_back(i);
//@E };
//@E mixin(vec);
//@E print_nvec(vec);
//@E   :0: 66 10 51 47 46 57 13 6  85 40 28 55 42 91 61 34 63 12 23 19 79 62 35 84 
//@E  :25: 43 5  54 17 93 90 0  73 9  18 49 71 20 89 70 41 4  56 22 45 2  29 88 31 
//@E  :50: 65 3  75 25 94 77 52 78 39 87 83 27 1  15 24 44 76 99 58 95 92 68 97 26 
//@E  :75: 64 74 11 80 81 69 59 38 8  7  50 14 98 36 82 60 72 32 96 33 37 30 53 67 
//@E :100: 48
//@X

template <typename T> void mixin(std::vector<T> &x) {
  auto now = std::chrono::system_clock::now();
  auto duration = now.time_since_epoch();
  double addr = std::chrono::duration_cast<std::chrono::milliseconds>(duration).count();
  addr /= 10;
  unsigned long int valint = addr;
  unsigned int addr2;
  int post_addr;
  if (valint % 9 == 0) {
    addr2 = 3;
  } else if (valint % 7 == 0) {
    addr2 = 4;
  } else if (valint % 8 == 0) {
    addr2 = 7;
  } else if (valint % 6 == 0) {
    addr2 = 9;
  } else if (valint % 3 == 0) {
    addr2 = 13;
  } else if (valint % 4 == 0) {
    addr2 = 1;
  } else if (valint % 2 == 0) { 
    addr2 = 8;
  } else {
    addr2 = 5;
  };
  addr -= valint;
  addr *= 10;
  post_addr = addr;
  if (addr - post_addr > 0.5) {
    post_addr += 1;
  };
  unsigned long long int v;
  long double n = x.size();
  const unsigned int n2 = n;
  n += 0.5 * n;
  T switchr;
  double mlt = 1;
  while (mlt < n2) {
    mlt *= 10;
  };
  for (unsigned long long int i = 0; i < n2; ++i) {
    switchr = x[i];
    v = abs(sin((((i + 1) * mlt) / n))) * n2 + post_addr + addr2;
    v = v % n2;
    x[i] = x[v];
    x[v] = switchr;
  };
};

//@L4 Deterministic (slightly faster)

//@T mixoutd
//@U template &lt;typename T&gt; std::vector&lt;T&gt; mixoutd(std::vector&lt;T&gt; x)
//@X
//@D Returns a stl vector with its elements at different indexes. The function is determinitic based on the size of the input stl vector.
//@A x : is an stl vector of any type
//@X
//@E std::vector&lt;int&gt; vec;
//@E for (int i = 0; i &lt; 100; ++i) {
//@E   vec.push_back(i);
//@E };
//@E std::vector&lt;int&gt; out = mixoutd(vec);
//@E print_nvec(out);
//@E   :0: 93 65 90 45 1  41 51 79 28 13 18 84 68 37 77 22 15 29 44 9  6  47 36 57 
//@E  :25: 14 24 26 46 56 96 33 61 54 59 5  73 34 76 75 71 11 78 92 31 48 50 55 49 
//@E  :50: 52 17 89 21 0  81 64 82 39 67 53 40 63 66 83 97 99 42 2  86 85 80 60 72 
//@E  :75: 20 87 27 4  35 19 10 88 43 98 38 8  30 69 58 23 16 95 32 94 91 70 74 62 
//@E :100: 25
//@X

template <typename T> std::vector<T> mixoutd(std::vector<T> x) {
  unsigned long long int v;
  long double n = x.size();
  const unsigned int n2 = n;
  n += 0.5 * n;
  T switchr;
  double mlt = 1;
  while (mlt < n2) {
    mlt *= 10;
  };
  for (unsigned long long int i = 0; i < n2; ++i) {
    switchr = x[i];
    v = abs(sin((((i + 1) * mlt) / n))) * n2;
    v = v % n2;
    x[i] = x[v];
    x[v] = switchr;
  };
  return x;
};

//@T mixind
//@U template &lt;typename T&gt; std::vector&lt;T&gt; mixind(std::vector&lt;T&gt; &x)
//@X
//@D Transforms a stl vector with its elements at different indexes. The function is determinitic based on the size of the input stl vector.
//@A x : is an stl vector of any type
//@X
//@E std::vector&lt;int&gt; vec;
//@E for (int i = 0; i < 100; ++i) {
//@E   vec.push_back(i);
//@E };
//@E mixind(vec);
//@E print_nvec(vec);
//@E   :0: 93 65 90 45 1  41 51 79 28 13 18 84 68 37 77 22 15 29 44 9  6  47 36 57 
//@E  :25: 14 24 26 46 56 96 33 61 54 59 5  73 34 76 75 71 11 78 92 31 48 50 55 49 
//@E  :50: 52 17 89 21 0  81 64 82 39 67 53 40 63 66 83 97 99 42 2  86 85 80 60 72 
//@E  :75: 20 87 27 4  35 19 10 88 43 98 38 8  30 69 58 23 16 95 32 94 91 70 74 62 
//@E :100: 25
//@X

template <typename T> void mixind(std::vector<T> &x) {
  unsigned long long int v;
  long double n = x.size();
  const unsigned int n2 = n;
  n += 0.5 * n;
  T switchr;
  double mlt = 1;
  while (mlt < n2) {
    mlt *= 10;
  };
  for (unsigned long long int i = 0; i < n2; ++i) {
    switchr = x[i];
    v = abs(sin((((i + 1) * mlt) / n))) * n2;
    v = v % n2;
    x[i] = x[v];
    x[v] = switchr;
  };
};

//@L3 Print

//@T print_nvec
//@U template &lt;typename T&gt; void print_nvec(const std::vector&lt;T&gt; &x, int untl = -1) 
//@X
//@D Print a stl vector (int, float, double, bool)
//@A x : stl vector (int, float, double, bool)
//@A untl : is an int idicating how many elements must be printed, defaults to -1, so by default all elements will be printed
//@X
//@E std::vector&lt;int&gt; vec = {12, 2, 4534, 7, -78, 12122};
//@E for (int i = 0; i &lt; 50; ++i) { vec.push_back(i); }
//@E print_nvec(vec);
//@E  :0: 12    2     4534  7     -78   12122 0     1     2     3
//@E :10: 4     5     6     7     8     9     10    11    12    13
//@E :20: 14    15    16    17    18    19    20    21    22    23
//@E :30: 24    25    26    27    28    29    30    31    32    33
//@E :40: 34    35    36    37    38    39    40    41    42    43
//@E :50: 44    45    46    47    48    49
//@M print_nvec.jpg
//@X

template <typename T> void print_nvec(const std::vector<T> &x, int untl = -1) {
  unsigned int r = 1;
  int i;
  int cmax = 1;
  int cl;
  unsigned int Untl;
  if (untl == -1) {
    Untl = x.size();
  } else {
    Untl = untl;
  };
  for (i = 0; i < Untl; ++i) {
    cl = std::to_string(x[i]).length();
    if (cl > cmax) {
      cmax = cl;
    };
  }; 
  int ref_delta = std::to_string(Untl).length();
  for (i = 0; i < ref_delta - 1; ++i) {
    std::cout << " ";
  };
  std::cout << ":" << 0 << ": ";
  for (i = 0; i < Untl; ++i) {
    if ((i + 1) % 10 == 0) {
      std::cout << x[i] << " ";
      for (cl = 0; cl < cmax - std::to_string(x[i]).length(); ++cl) {
        std::cout << " ";
      };
      std::cout << "\n";
      for (cl = 0; cl < ref_delta - std::to_string(r * 10).length(); ++cl) {
        std::cout << " ";
      };
      std::cout << ":" << r * 10 << ": ";
      r += 1;
    } else {
      std::cout << x[i] << " ";
      for (cl = 0; cl < cmax - std::to_string(x[i]).length(); ++cl) {
        std::cout << " ";
      };
    };
  };
  std::cout << "\n";
};

//@T print_svec
//@U template &lt;typename T&gt; void print_nvec(const std::vector&lt;T&gt; &x, int untl = -1) 
//@X
//@D Print a stl vector (int, float, double, bool)
//@A x : stl vector (int, float, double, bool)
//@A untl : is an int idicating how many elements must be printed, defaults to -1, so by default all elements will be printed
//@X
//@E std::vector&lt;std::string&gt; vec2 = {"peugeot", "wolkswagen", "honda", "renault", "stellantis"};
//@E for (int i = 0; i &lt; 20; ++i) { vec2.push_back("yesss"); }
//@E print_svec(vec2);
//@E  :0: peugeot    wolkswagen honda      renault    stellantis yesss      yesss      yesss
//@E  :8: yesss      yesss      yesss      yesss      yesss      yesss      yesss      yesss
//@E :16: yesss      yesss      yesss      yesss      yesss      yesss      yesss      yesss
//@E :24: yesss
//@M print_svec.jpg
//@X

void print_svec(const std::vector<std::string> &x, int untl = -1) {
  int r = 1;
  int i;
  int cmax = 1;
  int cl;
  std::string ref_str;
  unsigned int Untl;
  if (untl == -1) {
    Untl = x.size();
  } else {
    Untl = untl;
  };
  for (i = 0; i < Untl; ++i) {
    ref_str = x[i];
    cl = ref_str.length();
    if (cl > cmax) {
      cmax = cl;
    };
  }; 
  const int ref_delta = std::to_string(Untl).length();
  for (i = 0; i < ref_delta - 1; ++i) {
    std::cout << " ";
  };
  std::cout << ":" << 0 << ": ";
  for (i = 0; i < Untl; ++i) {
    if ((i + 1) % 8 == 0) {
      std::cout << x[i] << " ";
      ref_str = x[i];
      for (cl = 0; cl < cmax - ref_str.length(); ++cl) {
        std::cout << " ";
      };
      std::cout << "\n";
      for (cl = 0; cl < ref_delta - std::to_string(r * 8).length(); ++cl) {
        std::cout << " ";
      };
      std::cout << ":" << r * 8 << ": ";
      r += 1;
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

//@L3 Absolute values

//@T abs_vin
//@U template &lt;typename T&gt; void abs_vin(std::vector&lt;T&gt; &x) 
//@X
//@D Converts the elements of a vector to absolute values.
//@A x : is a stl vector (int, float, double, bool)
//@X 
//@E std::vector&lt;int&gt; vec = {1, -5, -7, 3};
//@E abs_vin(vec);
//@E {1, 5, 7, 3}
//@X

template <typename T> void abs_vin(std::vector<T> &x) {
  for (typename std::vector<T>::iterator i = x.begin(); i != x.end(); ++i) {
    if (*i < 0) {
      *i *= -1;
    };
  };
};

//@T abs_vout
//@U template &lt;typename T&gt; void abs_vout(std::vector&lt;T&gt; &x) 
//@X
//@D Returns the input vector with all of its elements converted to absolute values.
//@A x : is a stl vector (int, float, double, bool)
//@X 
//@E std::vector&lt;int&gt; vec = {1, -5, -7, 3};
//@E std::vector&lt;unsigned int&gt; out = abs_vout(vec);
//@E {1, 5, 7, 3}
//@X

template <typename T> std::vector<T> abs_vout(const std::vector<T> &x) {
  std::vector<T> rtn = x;
  for (typename std::vector<T>::iterator i = rtn.begin(); i != rtn.end(); ++i) {
    if (*i < 0) {
      *i *= -1;
    };
  };
  return rtn;
};

#if 0
//@T abs_voutb
//@U template &lt;typename T&gt; std::vector&lt;T&gt; abs_voutb(const std::vector&lt;T&gt; &x) 
//@X
//@D Returns the input vector with all of its elements converted to absolute values.
//@D uses another algorithm than <a href="#abs_vout">abs_vout</a>, with indices instead of iterators.
//@A x : is a stl vector (int, float, double)
//@X
//@E std::vector&lt;int&gt; vec = {-45, 23, 21, -6, 45};
//@E std::vector&lt;unsigned int&gt; out = abs_voutb(vec);
//@E {45, 23, 21, 6, 45}
//@X
#endif

template <typename T> std::vector<T> abs_voutb(const std::vector<T> &x) { //index approach
  std::vector<T> rtn = x;
  const int n = x.size();
  for (int i = 0; i < n; ++i) {
    if (x[i] < 0) {
      rtn[i] *= -1;
    };
  };
  return rtn;
};

//@L3 Match

//@T matchl
//@U template &lt;typename T, typename T2&gt; bool matchl(const std::vector&lt;T&gt; &source, const T2 &ptrn)
//@X
//@D Returns 1 if the pattern is found in the stl vector, 0 if not. (returns bool)
//@A source : is an stl vector
//@A ptrn : is the pattern 
//@X
//@E std::vector&lt;std::string&gt; vec = {"yess", "no", "maybe", "euuh", "maybe"};
//@E std::string ptrn = "maybe";
//@E bool out = matchl(vec, ptrn);
//@E 1
//@X

template <typename T, typename T2> bool matchl(const std::vector<T> &source, const T2 &ptrn) {
  for (typename std::vector<T>::const_iterator i = source.begin(); i != source.end(); ++i) {
    if (*i == ptrn) {
      return 1;
    };
  };
  return 0;
};

//@T match
//@U template &lt;typename T, typename T2&gt; unsigned int match(const std::vector&lt;T&gt; &source, const T2 &ptrn)
//@X
//@D Returns the index of the pattern in the vector, -1 if not found.
//@A source : is an stl vector
//@A ptrn : is the pattern 
//@X
//@E std::vector&lt;std::string&gt; vec = {"yess", "no", "maybe", "euuh", "maybe"};
//@E std::string ptrn = "maybe";
//@E unsigned int out = matchl(vec, ptrn);
//@E 2
//@X

template <typename T, typename T2> int match(const std::vector<T> &source, const T2 &ptrn) {
  int cnt = 0;
  for (typename std::vector<T>::const_iterator i = source.begin(); i != source.end(); ++i) {
    if (*i == ptrn) {
      return cnt;
    };
    cnt += 1;
  };
  return -1;
};

//@T match_max
//@U template &lt;typename T&gt; unsigned int match_max(const std::vector&lt;T&gt; &x) 
//@X
//@D Returns the index of the maximum value in a stl vector (int, float, double, bool).
//@A x : is an stl vector (int, float, double)
//@X
//@E std::vector&lt;int&gt; vec = {3, 1, -7, 23, 21};
//@E unsigned int out = match_max(vec);
//@E 3
//@X

template <typename T> unsigned int match_max(const std::vector<T> &x) {
  T cvl = x[0];
  int i = 1;
  int rtn = 0;
  for (typename std::vector<T>::const_iterator it = x.begin() + 1; it != x.end(); ++it) {
    if (cvl < *it) {
      cvl = *it;
      rtn = i;
    };
    i += 1;
  };
  return rtn;
};

//@T match_min
//@U template &lt;typename T&gt; unsigned int match_min(const std::vector&lt;T&gt; &x) 
//@X
//@D Returns the index of the minimum value in a stl vector (int, float, double, bool).
//@A x : is an stl vector (int, float, double)
//@X
//@E std::vector&lt;int&gt; vec = {3, 1, -7, 23, 21};
//@E unsigned int out = match_min(vec);
//@E 2
//@X

template <typename T> unsigned int match_min(const std::vector<T> &x) {
  T cvl = x[0];
  int i = 1;
  int rtn = 0;
  for (typename std::vector<T>::const_iterator it = x.begin() + 1; it != x.end(); ++it) {
    if (cvl > *it) {
      cvl = *it;
      rtn = i;
    };
    i += 1;
  };
  return rtn;
};

//@T match_n
//@U template typename &lt;T&gt;
//@U std::vector&lt;unsigned int &gt;
//@U match_n(const std::vector&lt;T&gt;& x, const std::vector&lt;T&gt;& ptrn)
//@X
//@D Returns all the first index of occurence of all input elements in a set.
//@A x : is the input set (where are the elements to be found)
//@A ptrn : is the vector containing all the elements to match
//@X
//@E
//@E
//@E std::vector&lt;std::string&gt; vec1 = {"az", "pp", "mm", "ff", "ff", "uv"};
//@E
//@E  std::vector&lt;std::string&gt; vec2 = {"ff", "ff", "mm"};
//@E
//@E  std::vector&lt;unsigned int&gt; vecout = match_n(vec1, vec2);
//@E :0: 3 3 2
//@X

template <typename T> std::vector<unsigned int> match_n(const std::vector<T>& x, const std::vector<T>& ptrn) {
  unsigned int i2;
  std::vector<unsigned int> rtn_v(ptrn.size());
  for (unsigned int i = 0; i < ptrn.size(); i += 1) {
    i2 = 0;
    T cur_ptrn = ptrn[i];
    while (x[i2] != cur_ptrn) {
      i2 += 1;
      if (i2 == x.size()) {
        break;
      };
    };
    rtn_v[i] = i2;
  };
  return rtn_v;
};

//@L3 Grep

//@T grep
//@U template &lt;typename T, typename T2&gt; std::vector&lt;unsigned int&gt; grep(const std::vector&lt;T&gt; &source, const T2 &ptrn) 
//@X
//@D Returns the indices of a pattern inside a stl vector.
//@A source : is an stl vector
//@A ptrn : is the pattern
//@X
//@E std::vector&lt;std::string&gt; vec = {"yess", "no", "maybe", "euuh", "maybe"};
//@E std::string ptrn = "maybe";
//@E std::vector&lt;unsigned int&gt; out = grep(vec, ptrn);
//@E {3 4}
//@X

template <typename T, typename T2> std::vector<unsigned int> grep(const std::vector<T> &source, const T2 &ptrn) {
  std::vector<unsigned int> rtn;
  int i = 0;
  for (typename std::vector<T>::const_iterator it = source.begin(); it != source.end(); ++it) {
    if (*it == ptrn) {
      rtn.push_back(i);
    };
    i += 1;
  };
  if (rtn.size() == 0) {
    rtn = {static_cast<unsigned int>(-1)};
  };
  return rtn;
};

//@T grepl
//@U template &lt;typename T, typename T2&gt; std::vector&lt;bool&gt; grepl(const std::vector&lt;T&gt; &source, const T2 &ptrn) 
//@X
//@D Returns a boolean vector where O corresponds to a non match with the pattern andthe corresponding elements of the stl vector. 1 represents a match.
//@A source : is an stl vector
//@A ptrn : is the pattern
//@X
//@E std::vector&lt;std::string&gt; vec = {"yess", "no", "maybe", "euuh", "maybe"};
//@E std::string ptrn = "maybe";
//@E std::vector&lt;bool&gt; out = grep(vec, ptrn);
//@E {0 0 1 0 1}
//@X

template <typename T, typename T2> std::vector<bool> grepl(const std::vector<T> &source, const T2 &ptrn) {
  std::vector<bool> rtn;
  rtn.resize(source.size());
  int i = 0;
  for (typename std::vector<T>::const_iterator it = source.begin(); it != source.end(); ++it) {
    if (*it == ptrn) {
      rtn[i] = 1;
    };
    i++;
  };
  return rtn;
};

//@L3 Unique

//@T unique
//@U template &lt;typename T&gt; std::vector&lt;T&gt; unique(const std::vector&lt;T&gt; &x) 
//@X
//@D Returns a stl vector with unique elements from an input stl vector.
//@A x : is an stl vector
//@X 
//@E std::vector&lt;int&gt; vec = {1, 2, 3, 4, 4, 5, 6, 6};
//@E std::vector&lt;int&gt; out = unique(vec);
//@E {1, 2, 3, 4, 5, 6}
//@X 

template <typename T> std::vector<T> unique(const std::vector<T> &x) {
  std::vector<T> rtn = {x[0]};
  typename std::vector<T>::iterator it2;
  bool evr;
  for (typename std::vector<T>::const_iterator it = x.begin() + 1; it != x.end(); ++it) {
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

//@L3 Reverse

//@T reverse_out
//@U template &lt;typename T&gt; std::vector&lt;T&gt; reverse_out(const std::vector&lt;T&gt; &x)
//@X
//@D Returns a reverse stl vector from an input stl vector.
//@A x : is an stl vector
//@X
//@E std::vector&lt;std::string&gt; vec = {"he", "ll", "o"};
//@E std::vector&lt;std::string&gt; out = reverse_out(vec);
//@E {"ll", "o", "he"}
//@X

template <typename T> std::vector<T> reverse_out(const std::vector<T> &x) {
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

//@T reverse_in
//@U template &lt;typename T&gt; std::vector&lt;T&gt; reverse_in(const std::vector&lt;T&gt; &x)
//@X
//@D Reverses a stl vector..
//@A x : is an stl vector
//@X
//@E std::vector&lt;std::string&gt; vec = {"he", "ll", "o"};
//@E reverse_out(vec);
//@E {"ll", "o", "he"}
//@X

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

#if 0
//@T reverse_out_standard
//@U template &lt;typename T&gt; std::vector&lt;T&gt; reverse_out(const std::vector&lt;T&gt; &x)
//@X
//@D Returns a reverse stl vector from an input stl vector. Uses another algorithm than <a href="#reverse_out">reverse_out</a>.
//@A x : is an stl vector
//@X
//@E std::vector&lt;std::string&gt; vec = {"he", "ll", "o"};
//@E std::vector&lt;std::string&gt; out = reverse_out(vec);
//@E {"ll", "o", "he"}
//@X
#endif

template <typename T> std::vector<T> reverse_out_standard(const std::vector<T> &x) {
  std::vector<T> rtn;
  const int n = x.size();
  rtn.resize(n);
  const int spv = n - 1;
  for (int i = 0; i < n; ++i) {
    rtn[i] = x[spv - i];
  };
  return rtn;
};

//@L3 Repetition of elements

//@T rep
//@U template &lt;typename T&gt; std::vector&lt;T&gt; rep(const std::vector&lt;T&gt; &x, const std::vector&lt;int&gt; &hmn)
//@X
//@D Returns a stl vector of elements repeted multiple times relatively to an int stl vector.
//@A x : is a stl vector containing all the elements that will be repeated
//@A hmn : is a stl int vector containing all the times each element will be repeated 
//@X 
//@E std::vector&lt;std::string&gt; vec;
//@E std::vector&lt;int&gt; hmn = {4, 2, 7};
//@E std::vector&lt;std::string&gt; elmnts = {"ok", "ko", "ok2"};
//@E vec = rep(elmnts, hmn);
//@E print_svec(vec);
//@E :0: ok  ok  ok  ok  ko  ko  ok2 ok2 ok2 ok2 ok2 ok2 ok2 
//@X

template <typename T> std::vector<T> rep(const std::vector<T> &x, const std::vector<int> &hmn) {
  std::vector<T> rtn;
  unsigned int cnt = 0;
  unsigned int i = 1;
  T val = x[0];
  bool no_stop = 1;
  while (no_stop) {
    if (i > hmn[cnt]) {
      if (cnt + 1 != hmn.size()) {
        cnt += 1;
        val = x[cnt];
        i = 1;
        rtn.push_back(val);
      } else {
        no_stop = 0;
      };
    } else {
      rtn.push_back(val);
    };
    i += 1;
  };
  return rtn;
};


//@T rep
//@U template &lt;typename T&gt; std::vector&lt;T&gt; rep(T val, int n) 
//@X
//@D Returns a vector of the input element repeated n times
//@A val : is your input value 
//@A n : is the n
//@X
//@E int val = 14;
//@E int n = 4;
//@E std::vector&lt;int&gt; = rep(val, n);
//@E {14, 14, 14, 14}
//@X

template <typename T> std::vector<T> rep(T val, int n) {
  std::vector<T> vec = {};
  for (int i = 0; i < n; i++) {
    vec.push_back(val);
  };
  return vec;
}

//@T repeat_untl
//@U template &lt;typename T&gt; void repeat_untl(std::vector&lt;T&gt; &vec, int n)
//@X
//@D Repeat the sequence of the input vector elements until it matches the target length
//@A vec : is your input vector
//@A n : is the target len
//@X
//@E std::vector&lt;int&gt; vec = {1, 2, 3};
//@E int n = 8;
//@E repeat_untl(vec, n);
//@E {1, 2, 3, 1, 2, 3, 1, 2}
//@X

template <typename T> void repeat_untl(std::vector<T> &vec, int n) {
  int ns = vec.size();
  if (n > ns) {
    for (int i = 0; i < (n - ns); i++) {
      vec.push_back(vec[i % ns]);
    };
  };
}

//@L3 Sequence/Range of elements

//@T seq 
//@U template &lt;typename T, typename T2, typename T3&gt; std::vector&lt;T&gt; seq(T from, T2 const &to, T3 const &by)
//@X
//@D Returns a stl range vector(int, float, double).
//@A from : is the starting value
//@A to : is the end value
//@A by : is the step value
//@X 
//@E float from = 1.25; 
//@E float to = 3;
//@E float by = 0.25;
//@E std::vector&lt;float&gt; = seq(from, to, by);
//@E {1.25, 1.5, 1.75, 2, 1.25, 2.5, 2.75, 3}
//@X

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

//@L3 Comparisons to booleans 

//@T comp2
//@U template &lt;typename T, typename T2&gt; std::vector&lt;bool&gt; comp2(const std::vector&lt;T&gt; &x, const std::vector&lt;T2&gt; &x2) 
//@X
//@D Returns a boolean vector of 2 stl vectors that will be compared elements by elements. The vectors should not necessarily be the same size. The output boolean vector will be the same size as the first stl vector argument. This is the prefered way when there are only 2 vectors to compare, compared to using Compv class.
//@A x : is an stl vector 
//@A x2 is an stl vector
//@X
//@E std::vector&lt;unsigned int&gt; vec = {1, 5, 2};
//@E std::vector&lt;unsigned int&gt; vecb = {1, 5, 22};
//@E std::vector&lt;bool&gt; out = comp2(vec, vecb);
//@E 1 1 0
//@E vec = {1, 5, 2, 1, 5, 2};
//@E out = comp2(vec, vecb);
//@E 1 1 0 1 1 0
//@X

template <typename T, typename T2> std::vector<bool> comp2(const std::vector<T> &x, const std::vector<T2> &x2) {
  std::vector<bool> rtn_v;
  rtn_v.resize(x.size(), 1);
  const unsigned int n2 = x2.size();
  const unsigned int n = x.size();
  for (int i = 0; i < n; ++i) {
    if (x[i] != x2[i % n2]) {
      rtn_v[i] = 0;
    };
  };
  return rtn_v;
};

//@L4 Variadic / Indefinite number of arguments - Compv Class

//@T Compv.to_comp()
//@U Compv comp1(std::vector&lt;Type&gt; vec1);
//@U comp1.to_comp(std::vector&lt;Type&gt; vec2, std::vector&lt;Type&gt; vec3);
//@U comp1.result();
//@U comp1.reinitiate(std::vector&lt;OtherType&gt; vec4);
//@U ...
//@X
//@D Returns a boolean vector of multiple stl vectors that will be compared elements by elements. The vectors do not have necessarily to be the same size. The output boolean vector will be the size of the initiation vector. 
//@A ... : undefinite number of stl vectors
//@X
//@E std::vector&lt;unsigned int&gt; vec = {1, 5, 2};
//@E std::vector&lt;unsigned int&gt; vecb = {1, 5, 2};
//@E std::vector&lt;unsigned int&gt; vecc = {1, 5, 22};
//@E std::vector&lt;unsigned int&gt; vec2 = {1, 5};
//@E std::vector&lt;unsigned int&gt; vec2b = {1, 5};
//@E std::vector&lt;unsigned int&gt; vec2c = {1, 5};
//@E Compv obj1(vec);
//@E obj1.to_comp(vecb, vecc);
//@E std::vector&lt;bool&gt; out = obj1.result();
//@E 1 1 0
//@E obj1.reinitiate(vec2);
//@E out = obj1.result();
//@E 1 1
//@E vec = {1, 5, 22, 1, 5, 2};
//@E obj1.reinitiate(vec);
//@E obj1.to_comp(vec, vecb, vecc);
//@E out = obj1.result();
//@E 1 1 0 1 1 0
//@X

template <typename TB> class Compv {
  private: 
    std::vector<TB> ref_vec;
    std::vector<bool> comp_v;
    unsigned int ref_lngth;
 
  public:
    void to_comp() {};
     
    template <typename T, typename... T2> void to_comp(std::vector<T>& var1, std::vector<T2>&... var2)
    {
      const unsigned int n = var1.size();
      for (int i = 0; i < ref_lngth; ++i) {
        if (var1[i % n] != ref_vec[i] & comp_v[i] != 0) {
          comp_v[i] = 0;
        };
      };
      to_comp(var2...);
    };

    void reinitiate_comp_v() {
      for (std::vector<bool>::iterator i = comp_v.begin(); i != comp_v.end(); ++i) {
        *i = 1;
      };
    };

    std::vector<bool> result() {
      return comp_v;
    };

    void reinitiate(std::vector<TB> &x) {
      const unsigned int n = x.size();
      if (ref_lngth == n) {
        for (int i =  0; i < n; ++i) {
          comp_v[i] = 1;
          ref_vec[i] = x[i];
        };
      } else if (ref_lngth > n) {
        comp_v.resize(n);
        comp_v.shrink_to_fit();
        ref_vec.resize(n);
        ref_vec.shrink_to_fit();
        for (int i =  0; i < n; ++i) {
          comp_v[i] = 1;
          ref_vec[i] = x[i];
        };
      } else {
          comp_v.resize(n);
          ref_vec.resize(n);
          for (int i =  0; i < n; ++i) {
            comp_v[i] = 1;
            ref_vec[i] = x[i];
          };
      };
      ref_lngth = n;
    };

    Compv(std::vector<TB> &x) {
      ref_lngth = x.size();
      comp_v.resize(ref_lngth, 1);
      ref_vec = x;
    };

    ~Compv() {}; 
};

//@L3 Bool and indices conversions

//@T bool_to_idx
//@U std::vector&lt;unsigned int&gt; bool_to_idx(std::vector&lt;bool&gt; &x)
//@X
//@D Converts a boolean vector to an indices vector.
//@A x : is the input boolean vector
//@X
//@E std::vector&lt;bool&gt; xbool = {0, 0, 1, 1, 0, 1, 0};
//@E std::vector&lt;unsigned int&gt; xidx = bool_to_idx(xbool);
//@E print_nvec(xidx);
//@E 2 3 5
//@X

std::vector<unsigned int> bool_to_idx(std::vector<bool> &x) {
  std::vector<unsigned int> rtn_v;
  for (unsigned int i = 0; i <  x.size(); ++i) {
    if (x[i] == 1) {
      rtn_v.push_back(i);
    };
  };
  return rtn_v;
};

//@T idx_to_bool
//@U std::vector&lt;bool&gt; idx_to_bool(std::vector&lt;unsigned int&gt; &x, int target_size = -1)
//@X
//@D Converts a indice vector to a boolean vector
//@A x : is the input indices vector
//@A target_size : is the size of the wanted output boolean vector
//@X
//@E std::vector&lt;unsigned int&gt; xidx = {2, 3, 5};
//@E std::vector&lt;bool&gt; xbool = idx_to_bool(xidx, 7);
//@E print_nvec(xbool);
//@E :0: 0 0 1 1 0 1 0
//@X

std::vector<bool> idx_to_bool(std::vector<unsigned int> &x, int target_size = -1) {
  if (target_size == -1) {
    target_size = x[x.size() - 1] + 1;
  };
  std::vector<bool> rtn_v;
  unsigned int i2 = 0;
  for (unsigned int i = 0; i < target_size; ++i) {
    if (i2 < x.size()) {
      if (i == x[i2]) {
        rtn_v.push_back(1);
        i2 += 1;
      } else {
        rtn_v.push_back(0);
      };
    } else {
      rtn_v.push_back(0);
    };
  };
  return rtn_v;
};


//@L3 Lower

//@T lowercomp2
//@U template &lt;typename T, typename T2&gt; std::vector&lt;bool&gt; lowercomp2(std::vector&lt;T&gt; &x, std::vector&lt;T2&gt; &x2)
//@X
//@D Returns a boolean vector, 1 if the corresponding values from the first vector is lower than  the corresponding values from the second vecotr. The output vector is the size of the first vector. 
//@A x : is the first vector
//@A x2 : is the second vector
//@X
//@E std::vector&lt;double&gt; vec = {1, 2.5, -6, 7.8, 2};
//@E std::vector&lt;double&gt; vec = {2, 2};
//@E lowercomp2(vec, vec2);
//@E 1 0 1 0 0
//@X

template <typename T, typename T2> std::vector<bool> lowercomp2(std::vector<T> x, T2 x2) {
  std::vector<bool> rtn_v;
  rtn_v.resize(x.size(), 0);
  const unsigned int n = x.size();
  const unsigned int n2 = x2.size();
  for (unsigned int i = 0; i < n; ++i) {
    if (x[i] < x2[i % n2]) {
      rtn_v[i] = 1;
    };
  };
  return rtn_v;
};

//@L3 Greater

//@T greatercomp2
//@U template &lt;typename T, typename T2&gt; std::vector&lt;bool&gt; greatercomp2(std::vector&lt;T&gt; x, T2 x2)
//@X
//@D Returns a boolean vector, 1 if the corresponding values from the first vector is greater than  the corresponding values from the second vecotr. The output vector is the size of the first vector.
//@A x : is the first vector
//@A x2 : is the second vector
//@X
//@E std::vector&lt;double&gt; vec = {1, 2.5, -6, 7.8, 2};
//@E std::vector&lt;double&gt; vec = {2, 2, 2, 2, 2};
//@E greatercomp2(vec, vec2);
//@E 0 1 0 1 0
//@X

template <typename T, typename T2> std::vector<bool> greatercomp2(std::vector<T> x, T2 x2) {
  std::vector<bool> rtn_v;
  rtn_v.resize(x.size(), 0);
  const unsigned int n = x.size();
  const unsigned int n2 = x2.size();
  for (unsigned int i = 0; i < n; ++i) {
    if (x[i] > x2[i % n2]) {
      rtn_v[i] = 1;
    };
  };
  return rtn_v;
};

//@L3 Any - All

//@T any
//@U bool any(const std::vector&lt;bool&gt; &x)
//@X
//@D Returns 1 if a boolean vector has at least 1 as value of one of its elements, 0 if not.
//@A x : is a stl boolean vector 
//@X
//@E std::vector&lt;bool&gt; vec = {0, 0, 1, 0};
//@E bool out = any(vec);
//@E 1
//@E std::vector&lt;bool&gt; vec = {0, 0, 0, 0};
//@E out = any(vec);
//@E 0
//@X

bool any(const std::vector<bool> &x) {
  for (std::vector<bool>::const_iterator i = x.begin(); i != x.end(); ++i) {
    if (*i == 1) {
      return 1;
    };
  };
  return 0;
};

//@T all
//@U all any(const std::vector&lt;bool&gt; &x)
//@X
//@D Returns 1 if all the elements of a stl boolean vector equals to 1, 0 if not.
//@A x : is a stl boolean vector 
//@X
//@E std::vector&lt;bool&gt; vec = {0, 0, 1, 0};
//@E bool out = all(vec);
//@E 0
//@E std::vector&lt;bool&gt; vec = {1, 1, 1, 1};
//@E out = all(vec);
//@E 1
//@X

bool all(const std::vector<bool> &x) {
  for (std::vector<bool>::const_iterator i = x.begin(); i != x.end(); ++i) {
    if (*i == 0) {
      return 0;
    };
  };
  return 1;
};

//@L3 Infamous Gnome Sorting Algorithm

//@T sort_desc
//@U template &lt;typename T&gt; void sort_desc(std::vector&lt;T&gt; &x) 
//@X
//@D Transforms a stl vector (int, float, double, bool) to a sorted decreasing stl vector.
//@A x : stl vector (int, float, double, bool) 
//@X
//@E std::vector&lt;int&gt; vec = {1, 5, 2, 1, 5, 22};
//@E sort_desc(vec);
//@E {22, 5, 5, 2, 1, 1}
//@X

template <typename T> void sort_desc(std::vector<T> &x) {
  const unsigned int n = x.size();
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

//@T sort_asc
//@U template &lt;typename T&gt; void sort_asc(std::vector&lt;T&gt; &x) 
//@X
//@D Transforms a stl vector (int, float, double, bool) to a sorted increasing stl vector.
//@A x : stl vector (int, float, double, bool) 
//@X
//@E std::vector&lt;int&gt; vec = {1, 5, 2, 1, 5, 22};
//@E sort_asc(vec);
//@E {1, 1, 2, 5, 5, 22}
//@X

template <typename T> void sort_asc(std::vector<T> &x) {
  const unsigned int n = x.size();
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

bool is_greater_str(std::string &x, std::string &x2, 
                std::vector<char> &order_v) {
  const unsigned int n = x.length();
  const unsigned int n2 = x2.length();
  unsigned int val1;
  unsigned int val2;
  if (n == n2) {
    for (unsigned int i = 0; i < n; ++i) {
      val1 = match(order_v, x[i]);
      val2 = match(order_v, x2[i]);
      if (val1 != val2) {
        if (val1 > val2) {
          return 1;
        } else {
          return 0;
        };
      };
    };
  } else if (n > n2) {
    return 1;
  } else {
    return 0;
  };
  return 1;
};

//@T str_sort_descend
//@U std::vector&lt;std::string&gt; str_sort_descend(std::vector&lt;std::string&gt; x, 
//@U std::vector<char> order_v = {
//@U  ' ', '!', '"', '#', '$', '%', '&', 
//@U  '\'', '(', ')', '*', '+', ',', '-', 
//@U  '.', '/', '0', '1', '2', '3', '4', '5',
//@U  '6', '7', '8', '9', ':', ';', '<', '=',
//@U  '>', '?', '@', 'A', 'B', 'C', 'D', 'E',
//@U  'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M',
//@U  'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U',
//@U  'V', 'W', 'X', 'Y', 'Z', '[', '\\', 
//@U  ']', '^', '_', '`', 'a', 'b', 'c', 'd', 'e',
//@U  'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm',
//@U  'n', 'o', 'p', 'q', 'r', 's', 't', 'u',
//@U  'v', 'w', 'x', 'y', 'z', '{', '|', '}',
//@U  '~'
//@U })
//@X
//@D Returns a descendly sorted vector of std::string (according to ascii table order by default)
//@A x : is the input vector
//@A order_v : is the order of each character (ascii table by default)
//@X
//@E std::vector&lt;std::string&gt; inv = {"b", "c", "a", "b", "a", "aa", "ab"};
//@E std::vector&lt;std::string&gt; outv = str_sort_descend(inv);
//@E print_svec(outv);
//@E :0: c  b  b  ab aa a  a
//@X

std::vector<std::string> str_sort_descend(std::vector<std::string> x, 
                std::vector<char> order_v = {
                         ' ', '!', '"', '#', '$', '%', '&', 
                        '\'', '(', ')', '*', '+', ',', '-', 
                        '.', '/', '0', '1', '2', '3', '4', '5',
                        '6', '7', '8', '9', ':', ';', '<', '=',
                        '>', '?', '@', 'A', 'B', 'C', 'D', 'E',
                        'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M',
                        'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U',
                        'V', 'W', 'X', 'Y', 'Z', '[', '\\', 
                        ']', '^', '_', '`', 'a', 'b', 'c', 'd', 'e',
                        'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm',
                        'n', 'o', 'p', 'q', 'r', 's', 't', 'u',
                        'v', 'w', 'x', 'y', 'z', '{', '|', '}',
                        '~'           
                }) {
  unsigned int i;
  unsigned int i2;
  const unsigned int n = x.size();
  std::vector<std::string> rtn_v = {};
  rtn_v.reserve(n);
  std::string cur_str;
  std::vector<std::string> x_ref = x;
  std::string min_str = " ";
  unsigned int max_len = 1;
  unsigned int cur_len;
  unsigned int idx_max;
  bool is_sup;
  for (i = 0; i < n; ++i) {
    cur_str = x[i];
    cur_len = cur_str.length();
    if (max_len < cur_len) {
      max_len = cur_len;
    };
  };
  for (i = 0; i < n; ++i) {
    cur_str = x[i];
    cur_len = cur_str.length();
    for (i2 = cur_len; i2 < max_len; ++i2) {
      cur_str.push_back(' ');
    };
    x[i] = cur_str;
  };
  for (i = 0; i < n; ++i) {
    cur_str = x[i];
    idx_max = i;
    for (i2 = 0; i2 < n; ++i2) {
      is_sup = is_greater_str(x[i2], cur_str, order_v);
      if (is_sup) {
        cur_str = x[i2];
        idx_max = i2;
      };
    };
    x[idx_max] = min_str;
    rtn_v.push_back(x_ref[idx_max]);
  };
  return rtn_v;
};

//@T str_sort_ascend
//@U std::vector&lt;std::string&gt; str_sort_ascend(std::vector&lt;std::string&gt; x, std::vector<char> order_v = {
//@U                         ' ', '!', '"', '#', '$', '%', '&', 
//@U                         '\'', '(', ')', '*', '+', ',', '-', 
//@U                         '.', '/', '0', '1', '2', '3', '4', '5',
//@U                         '6', '7', '8', '9', ':', ';', '<', '=',
//@U                         '>', '?', '@', 'A', 'B', 'C', 'D', 'E',
//@U                         'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M',
//@U                         'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U',
//@U                         'V', 'W', 'X', 'Y', 'Z', '[', '\\', 
//@U                         ']', '^', '_', '`', 'a', 'b', 'c', 'd', 'e',
//@U                         'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm',
//@U                         'n', 'o', 'p', 'q', 'r', 's', 't', 'u',
//@U                         'v', 'w', 'x', 'y', 'z', '{', '|', '}',
//@U                         '~'           
//@U 
//@U })
//@X
//@D Returns a ascendly sorted vector of std::string. (according to ascii table order by default)
//@A x : is the input vector
//@A order_v : is the order of each character (ascii table by default)
//@X
//@E std::vector&lt;std::string&gt; inv = {"b", "c", "a", "b", "a", "aa", "ab"};
//@E std::vector&lt;std::string&gt; outv = str_sort_ascend(inv);
//@E print_svec(outv);
//@E :0: a  a  aa ab b  b  c
//@X

std::vector<std::string> str_sort_ascend(std::vector<std::string> x,
                std::vector<char> order_v = {
                         ' ', '!', '"', '#', '$', '%', '&', 
                        '\'', '(', ')', '*', '+', ',', '-', 
                        '.', '/', '0', '1', '2', '3', '4', '5',
                        '6', '7', '8', '9', ':', ';', '<', '=',
                        '>', '?', '@', 'A', 'B', 'C', 'D', 'E',
                        'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M',
                        'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U',
                        'V', 'W', 'X', 'Y', 'Z', '[', '\\', 
                        ']', '^', '_', '`', 'a', 'b', 'c', 'd', 'e',
                        'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm',
                        'n', 'o', 'p', 'q', 'r', 's', 't', 'u',
                        'v', 'w', 'x', 'y', 'z', '{', '|', '}',
                        '~'           
                }) {
  unsigned int i;
  unsigned int i2;
  const unsigned int n = x.size();
  std::vector<std::string> rtn_v = {};
  rtn_v.reserve(n);
  std::string cur_str;
  std::vector<std::string> x_ref = x;
  std::string max_str = "~";
  unsigned int max_len = 1;
  unsigned int cur_len;
  unsigned int idx_min;
  bool is_sup;
  for (i = 0; i < n; ++i) {
    cur_str = x[i];
    cur_len = cur_str.length();
    if (max_len < cur_len) {
      max_len = cur_len;
    };
  };
  for (i = 1; i < max_len; ++i) {
    max_str.push_back('~');
  };
  for (i = 0; i < n; ++i) {
    cur_str = x[i];
    cur_len = cur_str.length();
    for (i2 = cur_len; i2 < max_len; ++i2) {
      cur_str.push_back(' ');
    };
    x[i] = cur_str;
  };
  for (i = 0; i < n; ++i) {
    cur_str = x[i];
    idx_min = i;
    for (i2 = 0; i2 < n; ++i2) {
      is_sup = is_greater_str(x[i2], cur_str, order_v);
      if (!is_sup) {
        cur_str = x[i2];
        idx_min = i2;
      };
    };
    x[idx_min] = max_str;
    rtn_v.push_back(x_ref[idx_min]);
  };
  return rtn_v;
};

//@L3 Remove range of elements

#if 0
//@T rm_ordered
//@U template &lt;typename T&gt; void rm_ordered(std::vector&lt;T&gt; &x, std::vector&lt;int&gt; ids)
//@X
//@D Remove elements from a stl vector. Keeps the vector sorted at a certain computational cost compared to <a href="#rm_unordered">rm_unordered</a>. The stl int vector provided for the indices of the element to be removed must be decreasingly sorted. The capacity of the vector is kept unchanged, so if you want to shrink it, consider doing <code>shrink_to_fit()</code> method.
//@A x : is an stl vector
//@A ids : is an stl int vector decreasingly sorted
//@X
//@E std::vector&lt;int&gt; vec = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
//@E std::vector&lt;int&gt; ids = {8, 5, 3, 2};
//@E rm_ordered(vec, ids); 
//@E print_nvec(vec);
//@E :0: 0 1 4 6 7 9
//@X
#endif

template <typename T> void rm_ordered(std::vector<T> &x, std::vector<int> ids) {
  const unsigned int n = ids.size();
  for (unsigned int i = 0; i < n; ++i) {
    x.erase(x.begin() + ids[i]);
  };
};

#if 0
//@T rm_unordered
//@U template &lt;typename T&gt; void rm_unordered(std::vector&lt;T&gt; &x, std::vector&lt;int&gt; ids) 
//@X
//@D Remove elements from a stl vector. Does not keep the vector sorted for computational speed compared to <a href="#rm_ordered">rm_ordered</a>. The stl int vector provided for the indices of the element to be removed must be decreasingly sorted. The capacity of the vector is kept unchanged, so if you want to shrink it, consider doing <code>shrink_to_fit()</code> method.
//@A x : is an stl vector
//@A ids : is an stl int vector decreasingly sorted
//@X
//@E std::vector&lt;int&gt; vec = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
//@E std::vector&lt;int&gt; ids = {8, 5, 3, 2};
//@E rm_unordered(vec, ids); 
//@E print_nvec(vec);
//@E :0: 0 1 6 7 4 9 
//@X
#endif

template <typename T> void rm_unordered(std::vector<T> &x, std::vector<int> ids) {
  const unsigned int n = ids.size();
  for (unsigned int i = 0; i < n; ++i) {
    std::swap(x[ids[i]], x.back());
    x.pop_back();
  };
};

//@L3 Sets (Union - Diff - Removing shared elements)

//@T union2
//@U template &lt;typename T&gt; std::vector&lt;T&gt; union2(std::vector&lt;T&gt; &x, std::vector&lt;T&gt; &x2)
//@X
//@D Returns the union of two stl vectors. Does not returns a stl vector with unique elements, so if you want it to return unique elements, make sure to enter unique stl vectors as input.
//@A x : is an stl vector
//@A x2 : is an stl vector
//@X
//@E std::vector&lt;int&gt; vec1 = {3, 4, 4, 5, 7, 8, 2, 4};
//@E std::vector&lt;int&gt; vec2 = {0, 1, 2, 3, 9, 11};
//@E std::vector&lt;int&gt; out = union2(vec1, vec2);
//@E print_nvec(out);
//@E :0: 3  4  4  5  7  8  2  4  0  1  2  3  9  11 
//@X

template <typename T> std::vector<T> union2(std::vector<T> &x, std::vector<T> &x2) {
  std::vector<T> rtn_v = x;
  const unsigned int n = x2.size();
  for (unsigned int i = 0; i < n; ++i) {
    rtn_v.push_back(x2[i]); 
  };
  return rtn_v;
};

//@L4 Variadic / Indefinite number of arguments - Unionv Class

//@T Unionv.to_union()
//@U Unionv union1(std::vector&lt;Type&gt; vec1);
//@U union1.to_union(std::vector&lt;Type&gt; vec2, std::vector&lt;Type&gt; vec3);
//@U union1.result();
//@U union1.reinitiate(std::vector&lt;Type2&gt; vec4);
//@U ...
//@X
//@A ... : undefinite number of stl vector of the same type
//@X
//@E std::vector&lt;int&gt; vec1 = {3, 4, 4, 5, 7, 8, 2, 4, 11};
//@E std::vector&lt;int&gt; vec2 = {0, 1, 2, 3, 9, 11, 4};
//@E std::vector&lt;int&gt; vec3 = {0, 1, 2, 3, 11, 9};
//@E Unionv union1(vec1);
//@E union1.to_union(vec2, vec3, vec3);
//@E std::vector&lt;int&gt; out = union1.result();
//@E print_nvec(out);
//@E :0: 3  4  4  5  7  8  2  4  11 0  1  2  3  9  11 4  0  1  2  3  11 9  0  1  
//@E :25: 2 3 11 9
//@E union1.reinitiate(vec2);
//@E union1.to_union(vec1);
//@E out = union1.result();
//@E print_nvec(out);
//@E :0: 0  1  2  3  9  11 4  3  4  4  5  7  8  2  4  11 
//@X

template <typename TB> class Unionv{
  private:
    std::vector<TB> rtn_v;

  public:
   
    void to_union() {};

    template <typename T, typename... T2> void to_union(std::vector<T> &var1, std::vector<T2>&... var2) {
      for (T i : var1) {
        rtn_v.push_back(i);
      };
      to_union(var2...);
    };

    std::vector<TB> result() {
      return rtn_v;
    };

    template <typename T> void reinitiate(std::vector<T> &x) {
      if (rtn_v.size() > x.size()) {
        rtn_v = x;
        rtn_v.shrink_to_fit();
      } else {
        rtn_v = x;
      };
    };

    Unionv (std::vector<TB> &x) {
      rtn_v = x;
    };

    ~Unionv() {};

};

//@J3

//@T intersect2
//@U template &lt;typename T&gt; std::vector&lt;T&gt; union2(std::vector&lt;T&gt; &x, std::vector&lt;T&gt; &x2)
//@X
//@D Returns the commun elements of two stl vectors of the same type. Does not returns a stl vector with unique elements, so if you want it to return unique elements, make sure to enter unique stl vectors as input.
//@A x : is an stl vector
//@A x2 : is an stl vector
//@X
//@E std::vector&lt;int&gt; vec1 = {3, 4, 4, 5, 7, 8, 2, 4};
//@E std::vector&lt;int&gt; vec2 = {0, 1, 2, 3, 9, 11};
//@E std::vector&lt;int&gt; out = intersect2(vec1, vec2);
//@E print_nvec(out);
//@E :0: 2 3 
//@X

template <typename T> std::vector<T> intersect2(std::vector<T> &x, std::vector<T> &x2) {
  std::vector<T> rtn_v;
  const unsigned int n = x.size();
  for (unsigned int i = 0; i < n; ++i) {
    for (T i2 : x2) {
      if (i2 == x[i]) {
        rtn_v.push_back(x[i]);
        break;
      };
    };
  };
  return rtn_v;
};

//@L4 Variadic / Indefinite number of arguments - Intersectv Class

#if 0
//@T Intersectv.to_intersect() 
//@U Intersectv intersect1(std::vector&lt;Type&gt; vec1);
//@U intersect1.to_intersect(std::vector&lt;Type&gt; vec2, std::vector&lt;Type&gt; vec3);
//@U intersect1.reinitiate(std::vector&lt;Type2&gt;);
//@U ...
//@X
//@D Returns the commun elements of undefinite number of stl vectors of the same type. The returned vector can have extra capacity non initiated, to get rid of that consider applying it the <code>shrink_to_fit()</code> method. The returned vector does not return unique elements, so if you want unique elements, consider enter unique stl vectors as input.
//@A ... : undefinite number of stl vectors
//@X
//@E std::vector&lt;int&gt; vec1 = {3, 4, 4, 5, 7, 8, 2, 4, 11};
//@E std::vector&lt;int&gt; vec2 = {0, 1, 2, 3, 9, 11, 4};
//@E std::vector&lt;int&gt; vec3 = {0, 1, 2, 3, 11, 9};
//@E Intersectv intersect1(vec1);
//@E intersect1.to_intersect(vec2, vec3);
//@E std::vector&lt;int&gt; out = intersect1.result();
//@E print_nvec(out);
//@E :0: 3  2  11 
//@E intersect1.reinitiate(vec1);
//@E intersect1.to_intersect(vec2);
//@E out = intersect1.result();
//@E print_nvec(out);
//@E :0: 3  4  4  2  4  11
//@X
#endif

template <typename TB> class Intersectv{
  private:
    std::vector<TB> rtn_v;
    std::vector<TB> cur_intersect;
    std::vector<TB> lst_intersect;
    unsigned int cur_n;

  public:

    void to_intersect() { };

    template <typename T, typename... T2> void to_intersect(std::vector<T> &var1, std::vector<T2>&... var2) {
      lst_intersect = cur_intersect;
      cur_n = lst_intersect.size();
      cur_intersect = {};
      rtn_v = {};
      unsigned int i;

      for (i = 0; i < cur_n; ++i) {
        for (T i2 : var1) {
          if (lst_intersect[i] == i2) {
            cur_intersect.push_back(i2);
            break;
          };
        };
      };

      cur_n = lst_intersect.size();

      for (i = 0; i < cur_n; ++i) {
        for (T i2 : cur_intersect) {
          if (lst_intersect[i] == i2) {
            rtn_v.push_back(i2);
            break;
          };
        };
      };

      to_intersect(var2...);

    };

    template <typename T> void reinitiate(std::vector<T> &x) {
      cur_intersect = x;
      if (cur_n < x.size()) {
        cur_n = x.size();
      } else {
        cur_intersect.shrink_to_fit();
        cur_n = x.size();
      };
    };

    std::vector<TB> result() {
      return rtn_v;
    };

    Intersectv(std::vector<TB> &x) {
      cur_intersect = x;
      cur_n = x.size();
    };

  ~Intersectv() {};
};

//@J3

//@T diff2
//@U template &lt;typename T&gt; std::vector&lt;T&gt; diff2(std::vector&lt;T&gt; &x, std::vector&lt;T&gt; &x2)
//@X
//@D Returns the elements that are in one of the stl vector but not in the intersection of all stl vectors. Does not returns a stl vector with unique elements, so if you want it to return unique elements, make sure to enter unique stl vectors as input.
//@A x : is an stl vector
//@A x2 : is an stl vector
//@X
//@E std::vector&lt;int&gt; vec1 = {3, 4, 4, 5, 7, 8, 2, 4};
//@E std::vector&lt;int&gt; vec2 = {0, 1, 2, 3, 9, 11};
//@E std::vector&lt;int&gt; out = diff2(vec1, vec2);
//@E print_nvec(out);
//@E :0: 9  4  4  5  7  8  11 4  0  1  
//@X

template <typename T> std::vector<T> diff2(std::vector<T> &x, std::vector<T> &x2) {
  std::vector<T> rtn_v = x;
  std::vector<T> intersect_v;
  unsigned int n = x2.size();
  int i;
  for (i = 0; i < n; ++i) {
    rtn_v.push_back(x2[i]);
  };
  n = x.size();
  for (i = 0; i < n; ++i) {
    for (T i2 : x2) {
      if (x[i] == i2) {
        intersect_v.push_back(x[i]);
        break;
      };
    }; 
  };
  n = rtn_v.size();
  for (i = n - 1; i > -1; --i) {
    for (T i2 : intersect_v) {
      if (rtn_v[i] == i2) {
        std::swap(rtn_v[i], rtn_v.back());
        rtn_v.pop_back();
        break;
      };
    };
  };
  return rtn_v;
};

//@L4 Variadic / Indefinite number of arguments - Diffv Class

#if 0
//@T Diffv.to_diff()
//@U Diffv diff1(std::vector&lt;Type&gt; vec1)
//@U diff1.to_diff(std::vector&lt;Type&gt; vec2, std::vector&lt;Type&gt; vec2);
//@U diff1.result();
//@U diff1.reinitiate(std::vector&lt;Type2&gt; vec4);
//@U ...
//@X
//@D Returs a stl vector of all the elements that are in one of the undefinite number of input stl vectors (of the same type) or more, but not in the intersection of all these stl vectors. Does not return a stl vector with unique elements, if you want it to return a stl vector with unique elements make sure that your input vectors contain unique elements. The returned vector can have more capacity than its size, to get rid of this unusable memory, you can apply the <code>shrink_to_fit()</code> method on it.
//@A ... : undefinite number of stl vectors of the same type
//@X
//@E std::vector&lt;int&gt; vec1 = {3, 4, 4, 5, 7, 8, 2, 4, 11};
//@E std::vector&lt;int&gt; vec2 = {0, 1, 2, 3, 9, 11, 4};
//@E std::vector&lt;int&gt; vec3 = {0, 1, 2, 3, 11, 9};
//@E Diffv diff1(vec1);
//@E diff1.to_diff(vec2, vec3);
//@E std::vector&lt;int&gt; out = diff1.result();
//@E print_nvec(out);
//@E :0: 9 4 4 5 7 8 9 4 4 0 1 0 1 
//@E diff1.reinitiate(vec3);
//@E diff1.to_diff(vec2, vec1);
//@E out = diff1.result();
//@E print_nvec(out);
//@E :0: 0 1 4 4 4 9 0 1 5 7 9 8 4 //same elements, different orders because the initializer vector is not the same 
//@X
#endif

template <typename TB> class Diffv{
  private:
    std::vector<TB> final_intersect;
    std::vector<TB> cur_intersect;
    std::vector<TB> lst_intersect;
    std::vector<TB> union_v;
    unsigned int cur_n;

  public:

    void to_diff() { 
      for (int i = union_v.size() - 1; i > -1; --i) {
        for (auto i2 : final_intersect) {
          if (i2 == union_v[i]) {
            std::swap(union_v[i], union_v.back());
            union_v.pop_back();
            break;
          };
        };
      };
    };

    template <typename T, typename... T2> void to_diff(std::vector<T> &var1, std::vector<T2>&... var2) {
      lst_intersect = cur_intersect;
      cur_n = lst_intersect.size();
      cur_intersect = {};
      final_intersect = {};
      unsigned int i;

      for (T i2 : var1) {
        union_v.push_back(i2);
      };

      for (i = 0; i < cur_n; ++i) {
        for (T i2 : var1) {
          if (lst_intersect[i] == i2) {
            cur_intersect.push_back(i2);
            break;
          };
        };
      };

      cur_n = lst_intersect.size();

      for (i = 0; i < cur_n; ++i) {
        for (T i2 : cur_intersect) {
          if (lst_intersect[i] == i2) {
            final_intersect.push_back(i2);
            break;
          };
        };
      };

      to_diff(var2...);

    };

    std::vector<TB> result() {
      return union_v;
    };

    template <typename T> void reinitiate(std::vector<T> &x) {
      cur_intersect = x;
      union_v = x;
      if (cur_n < x.size()) {
        cur_n = x.size();
      } else {
        cur_intersect.shrink_to_fit();
        union_v.shrink_to_fit();
        cur_n = x.size();
      };
    };

    Diffv(std::vector<TB> &x) {
      cur_intersect = x;
      union_v = x;
      cur_n = x.size();
    };

  ~Diffv() {};
};

//@J3

#if 0
//@T rm_shared_in
//@U template &lt;typename T&gt; void rm_shared_in(std::vector&lt;T&gt; &x, std::vector&lt;T&gt; &x2)
//@X
//@D Transforms the first stl vector input removing its commun elements with the second stl vector of the same type. The returned vector has its capacity unchanged, so consider applying the <code>shrink_to_fit()</code> method to it if you want to free some memory.
//@A x : is an stl vector
//@A x2 : is an stl vector
//@X
//@E std::vector&lt;int&gt; vec1 = {3, 4, 4, 5, 7, 8, 2, 4, 11};
//@E std::vector&lt;int&gt; vec2 = {0, 1, 2, 3, 9, 11, 4};
//@E rm_shared_in(vec1, vec2);
//@E print_nvec(vec1);
//@E :0: 5 7 8 
//@X
#endif

template <typename T> void rm_shared_in(std::vector<T> &x, std::vector<T> &x2) {
  for (int i = x.size() - 1; i > -1; --i) {
    for (T i2 : x2) {
      if (i2 == x[i]) {
        std::swap(x[i], x.back());
        x.pop_back();
        break;
      };
    };
  };
};

#if 0
//@T rm_shared_out
//@U template &lt;typename T&gt; std::vector&lt;T&gt; rm_shared_out(std::vector&lt;T&gt; &x, std::vector&lt;T&gt; &x2)
//@X
//@D Returns the first stl vector input minus the its commun elements with the second stl vector of the same type. The returned vector has its capacity unchanged, so consider applying the <code>shrink_to_fit()</code> method to it if you want to free some memory.
//@A x : is an stl vector
//@A x2 : is an stl vector
//@X
//@E std::vector&lt;int&gt; vec1 = {3, 4, 4, 5, 7, 8, 2, 4, 11};
//@E std::vector&lt;int&gt; vec2 = {0, 1, 2, 3, 9, 11, 4};
//@E std::vector&lt;int&gt; out = rm_shared_out(vec1, vec2);
//@E print_nvec(out);
//@E :0: 5 7 8 
//@X
#endif

template <typename T> std::vector<T> rm_shared_out(std::vector<T> &x, std::vector<T> &x2) {
  std::vector<T> rtn_v = x;
  for (int i = rtn_v.size() - 1; i > -1; --i) {
    for (T i2 : x2) {
      if (i2 == rtn_v[i]) {
        std::swap(rtn_v[i], rtn_v.back());
        rtn_v.pop_back();
        break;
      };
    };
  };
  return rtn_v;
};

//@L4 Variadic / Indefinite number of arguments - Rm_sharedv Class

//@T Rm_sharedv.to_rm()
//@U Rm_sharedv rm1(std::vector&lt;Type&gt; vec1);
//@U rm1.to_comp(std::vector&lt;Type&gt; vec2, std::vector&lt;Type&gt; vec3);
//@U rm1.result();
//@U rm1.reinitiate(std::vector&lt;OtherType&gt; vec4);
//@U ...
//@X
//@D Returns the initializer vector with the shared elements between this vector and an undefinite number of stl vectors, removed. This method is faster than finding commun elements between undefinite number of stl vectors and the initializer vector, and then removing the commun elements.
//@A ... : undefinite number of stl vectors
//@X
//@E std::vector&lt;int&gt; vec1 = {3, 4, 4, 5, 7, 8, 2, 4};
//@E std::vector&lt;int&gt; vec2 = {0, 1, 2, 3, 9, 11};
//@E std::vector&lt;int&gt; vec3 = {0, 1, 2, 3, 9, 11, 8};
//@E Rm_sharedv obj1(vec1);
//@E obj1.to_rm(vec2, vec3);
//@E std::vector&lt;int&gt; out = obj1.result();
//@E print_nvec(out);
//@E :0: 4 4 4 5 7 
//@E obj1.reinitiate(vec1);
//@E out = obj1.result();
//@E print_nvec(out);
//@E :0: 3 4 4 5 7 8 2 4 
//@X

template <typename TB> class Rm_sharedv {
  private: 
    std::vector<TB> rtn_v;
    int ref_lngth;

  public:
    void to_rm() { 
      rtn_v.shrink_to_fit();
    };
     
    template <typename T, typename... T2> void to_rm(std::vector<T>& var1, std::vector<T2>&... var2)
    {
      for (int i = ref_lngth; i > -1; --i) {
        for (T i2 : var1) {
          if (rtn_v[i] == i2) {
            std::swap(rtn_v[i], rtn_v.back());
            rtn_v.pop_back();
            ref_lngth -= 1;
            break;
          };
        };
      };
      to_union(var2...);
    };

    void reinitiate(std::vector<TB> &x) {
      const unsigned int n = x.size();
      rtn_v = x;
      if (n < ref_lngth) {
        rtn_v.shrink_to_fit();
      };
      ref_lngth = n - 1;
    };

    std::vector<TB> result() {
      return rtn_v;
    };

    Rm_sharedv(std::vector<TB> &x) {
      rtn_v = x;
      ref_lngth = x.size() - 1;
    };

    ~Rm_sharedv() {}; 
};

//@T sub
//@U template &lt;typename Iter&gt; std::vector&lt;typename std::iterator_traits&lt;Iter&gt;::value_type&gt; sub(Iter first, Iter last)
//@X
//@D Extract a contiguous subset from a vector.
//@A X : No args
//@X
//@E std::vector&lt;int&gt; vec = {1, 2, 3, 4, 5};
//@E sub(vec.begin() + 1, vec.begin() + 3);
//@E {2, 3}
//@X

template <typename Iter> 
std::vector<typename std::iterator_traits<Iter>::value_type>
sub(Iter first, Iter last) {
    return std::vector<typename std::iterator_traits<Iter>::value_type>(first, last);
}

//@L2 Finding closest elements in stl vector

//@T closest_idx
//@U template &lt;typename T&gt; unsigned int closest_idx(std::vector&lt;T&gt; &x, T &val)
//@X
//@D Returns the closest elements from a stl vector (int, float, double, bool) and a given value as the index of the closet element of the stl vector. This is equivalent to finding the index of the minimum difference between the value and the elements in the stl vector, but more efficiently since the function assumes the stl vector is already sorted ascendly or descendly as you see in examples.
//@A x : is an stl vector (int, float, double, bool), must be ascendly or descendly sorted
//@A val : is an int, float, double, bool
//@X
//@E std::vector&lt;double&gt; vec = {0.1, 0.89, 1.2, 1.66, 1.78, 2.25, 4.56};
//@E double val = 1.97;
//@E closest_idx(vec, val);
//@E 4
//@E val = 0.99;
//@E closest_idx(vec, val);
//@E 1
//@E std::vector&lt;double&gt; vec2 = sort_descout(vec);
//@E closest_idx(vec, val);
//@E 5
//@E val = 5.33;
//@E closest_val(vec2, val);
//@E 0
//@X

template <typename T, typename T2> unsigned int closest_idx(std::vector<T> &x, T2 &val) {
  const unsigned int n = x.size();
  unsigned int cnt = 1;
  double lst_diff = x[0] - val;
  if (lst_diff < 0) {
    lst_diff *= -1;
  };
  double cur_diff = x[1] - val;
  if (cur_diff < 0) {
    cur_diff *= -1;
  };
  while (cur_diff < lst_diff & cnt + 1 < n) {
    lst_diff = cur_diff;
    cnt += 1;
    cur_diff = x[cnt] - val;
    if (cur_diff < 0) {
      cur_diff *= -1;
    };
  };
  return cnt - 1;
};

//@L2 String and vectors conversions
//@L3 Collapse (vector to string)

//@T ncollapse
//@U template &lt;typename T, typename T2&gt; std::string ncollapse(const std::vector&lt;T&gt; &x, const T2 &sep)
//@X
//@D Collapses all elements from an stl vector (int, float, double, bool) to a string with a given separator.
//@A x : is an stl vector (int, float, double, bool)
//@A sep : is a char or string that will be the separator between the elements of x
//@X
//@E std::vector&lt;int&gt; vec = {5, 7, 22, 879};
//@E char sep = "-";
//@E std::string out = ncollapse(vec, sep);
//@E "5-7-22-879"
//@E
//@E std::string sep2 = "--";
//@E out = ncollapse(vec, sep2);
//@E "5--7--22--879"
//@X

template <typename T, typename T2> std::string ncollapse(const std::vector<T> &x, const T2 &sep) {
  std::string rtn;
  const typename std::vector<T>::const_iterator n = x.end() - 1;
  for (typename std::vector<T>::const_iterator i = x.begin(); i != n; ++i) {
    rtn += std::to_string(*i);
    rtn += sep;
  };
  rtn += std::to_string(*n);
  return rtn;
};

//@T scollapse
//@U template &lt;typename T&gt; std::string scollapse(const std::vector&lt;std::string&gt; &x, const T &sep)
//@X
//@D Collapses all elements from an stl string vector to a string with a given separator.
//@A x : is an stl vector (stl string)
//@A sep : is a char or string that will be the separator between the elements of x
//@X
//@E std::vector&lt;std::string&gt; vec = {"yess", "no", "maybe"};
//@E char sep = "-";
//@E std::string out = ncollapse(vec, sep);
//@E "yess-no-maybe"
//@E
//@E std::string sep2 = "--";
//@E out = ncollapse(vec, sep2);
//@E "yess--no--maybe"
//@X

template <typename T> std::string scollapse(const std::vector<std::string> &x, const T &sep) {
  std::string rtn;
  const typename std::vector<std::string>::const_iterator n = x.end() - 1;
  for (typename std::vector<std::string>::const_iterator i = x.begin(); i != n; ++i) {
    rtn += *i;
    rtn += sep;
  };
  rtn += *n;
  return rtn;
};

//@L3 Split (string to vector)

//@T split
//@U std::vector&lt;std::string&gt; split(const std::string &x, const char &sep)
//@X
//@D Returns a stl vector of stl strings that are part of the input stl string. The input string must have a separator to differenciate elements for the output stl vector.
//@A x : is a stl string
//@A sep : is a char
//@X
//@E std::string test = "y-e-ss";
//@E char sep = '-';
//@E std::vector&lt;std::string&gt; out = split(test, sep);
//@E {"y", "e", "ss"}
//@X

std::vector<std::string> split(const std::string &x, const char &sep) {
  std::vector<std::string> rtn;
  const unsigned int n = x.length();
  std::string cur;
  for (unsigned int i = 0; i < n; ++i) {
    if (!(x[i] == sep)) {
      cur += x[i];
    } else {
      rtn.push_back(cur);
      cur = "";
    };
  };
  rtn.push_back(cur);
  return rtn;
};

//@L3 Merge strings of 2 vectors

//@T merge_strv
//@U std::vector&lt;std::string&gt; merge_strv(std::vector&lt;std::string&gt; &x1, std::vector&lt;std::string&gt; &x2, std::string sep = "-")
//@X
//@D Returns a vector of merged strings of the input vectors
//@A x1 : is the first vector
//@A x2 : is the second vector
//@X
//@E 
//@E std::vector&lt;std::string&gt; vec = {"lm", "lm", "mm", "lm", "po", "rr", "rr", "po"};
//@E 
//@E std::vector&lt;std::string&gt; vec2 = {"lm", "lm", "O"};
//@E 
//@E std::vector&lt;std::string&gt; outv = merge_strv(vec, vec2);
//@E print_svec(outv);
//@E
//@E :0: lm-lm lm-lm mm-O  lm-lm po-lm rr-O  rr-lm po-lm
//@X

std::vector<std::string> merge_strv(std::vector<std::string> &x1, std::vector<std::string> &x2, std::string sep = "-") {
  std::vector<std::string> rtn_v;
  const unsigned int n = x1.size();
  const unsigned int n2 = x2.size();
  rtn_v.reserve(n);
  std::string cur_str;
  for (unsigned int i = 0; i < n; ++i) {
    cur_str = x1[i] + sep + x2[i % n2];
    rtn_v.push_back(cur_str);
  };
  return rtn_v;
};

//@L3 Occurence of elements in vectors

//@T occu
//@U template &lt;typename T&gt; std::map&lt;std::vector&lt;T&gt;, std::vector&lt;unsigned int&gt;&gt; occu(std::vector&lt;T&gt; &x)
//@X
//@D Returns a map containing: the input vector of elements with unique elements, and their associated occurence in another vector (second in map)
//@A x : is the input vector
//@X
//@E std::vector&lt;std::string&gt; vec = {"lm", "lm", "mm", "lm", "po", "rr", "rr", "po"};
//@E std::map&lt;std::vector&lt;std::string&gt;, std::vector&lt;unsigned int&gt;&gt; rtn_mp = occu(vec);
//@E std::map&lt;std::vector&lt;std::string&gt;, std::vector&lt;unsigned int&gt;&gt;::iterator rtn_it = rtn_mp.begin();
//@E int i;
//@E std::vector&lt;std::string&gt; uvec = rtn_it-&gt;first;
//@E std::vector&lt;unsigned int&gt; freqv = rtn_it-&gt;second;
//@E for (i = 0; i &lt; freqv.size(); ++i) {
//@E   std::cout &lt;&lt; uvec[i] &lt;&lt; " " &lt;&lt; freqv[i] &lt;&lt; "\n";
//@E };
//@E lm 3
//@E mm 1
//@E po 2
//@E rr 2
//@X

template <typename T> std::map<std::vector<T>, std::vector<unsigned int>> occu(std::vector<T> &x) {
  std::vector<T> uvec = unique(x);
  std::vector<unsigned int> freq_v;
  const unsigned int n2 = uvec.size();
  freq_v.reserve(n2);
  unsigned int n = x.size();
  unsigned int i2;
  unsigned int val_freq;
  for (T i : uvec) {
    val_freq = 0;
    for (i2 = 0; i2 < n; ++i2) {
      if (i == x[i2]) {
        val_freq += 1;
      };
    };
    freq_v.push_back(val_freq);
  };
  return {{uvec, freq_v}};
};

#if 0
//@T desc_occu
//@U template &lt;typename T&gt; std::map&lt;std::vector&lt;T&gt;, std::vector&lt;unsigned int&gt;&gt; desc_occu(std::vector&lt;T&gt; vec, std::vector&lt;unsigned int&gt; freqv)
//@X
//@D Returns a descendly sorted <code>occu()</code> output.
//@A vec : is the vector of unique elements
//@A freqv : is the associated occurence of the elements
//@X
//@E std::vector&lt;std::string&gt; vec = {"lm", "lm", "mm", "lm", "po", "rr", "rr", "po"};
//@E std::map&lt;std::vector&lt;std::string&gt;, std::vector&lt;unsigned int&gt;&gt; rtn_mp = occu(vec);
//@E std::map&lt;std::vector&lt;std::string&gt;, std::vector&lt;unsigned int&gt;&gt;::iterator rtn_it = rtn_mp.begin();
//@E int i;
//@E std::vector&lt;std::string&gt; uvec = rtn_it-&gt;first;
//@E std::vector&lt;unsigned int&gt; freqv = rtn_it-&gt;second;
//@E 
//@E std::cout &lt;&lt; "######\n";
//@E 
//@E rtn_mp = desc_occu(uvec, freqv);
//@E rtn_it = rtn_mp.begin();
//@E uvec = rtn_it-&gt;first;
//@E freqv = rtn_it-&gt;second;
//@E 
//@E for (i = 0; i &lt; freqv.size(); ++i) {
//@E   std::cout &lt;&lt; uvec[i] &lt;&lt; " " &lt;&lt; freqv[i] &lt;&lt; "\n";
//@E };
//@E lm 3
//@E po 2
//@E rr 2
//@E mm 1
//@X
#endif

template <typename T> std::map<std::vector<T>, std::vector<unsigned int>> desc_occu(std::vector<T> vec, std::vector<unsigned int> freqv) {
  int cur_max;
  unsigned int cur_idx;
  std::vector<unsigned int> rtn_freqv = {};
  std::vector<std::string> rtn_vec = {};
  const unsigned int n = vec.size();
  rtn_freqv.reserve(n);
  rtn_vec.reserve(n);
  for (unsigned int i = 0; i < n; ++i) {
    cur_max = max(freqv);
    cur_idx = match(freqv, cur_max);
    rtn_vec.push_back(vec[cur_idx]);
    rtn_freqv.push_back(freqv[cur_idx]);
    freqv[cur_idx] = 0;
  };
  return {{rtn_vec, rtn_freqv}};
};


#if 0
//@T asc_occu
//@U template &lt;typename T&gt; std::map&lt;std::vector&lt;T&gt;, std::vector&lt;unsigned int&gt;&gt; asc_occu(std::vector&lt;T&gt; vec, std::vector&lt;unsigned int&gt; freqv)
//@X
//@D Returns a ascendly sorted out put of the <code>occu()</code> output.
//@A vec : is the vector of unique elements
//@A freqv : is the associated occurence of the elements
//@X
//@E 
//@E std::vector&lt;std::string&gt; vec = {"lm", "lm", "mm", "lm", "po", "rr", "rr", "po"};
//@E std::map&lt;std::vector&lt;std::string&gt;, std::vector&lt;unsigned int&gt;&gt; rtn_mp = occu(vec);
//@E std::map&lt;std::vector&lt;std::string&gt;, std::vector&lt;unsigned int&gt;&gt;::iterator rtn_it = rtn_mp.begin();
//@E int i;
//@E std::vector&lt;std::string&gt; uvec = rtn_it-&gt;first;
//@E std::vector&lt;unsigned int&gt; freqv = rtn_it-&gt;second;
//@E for (i = 0; i &lt; freqv.size(); ++i) {
//@E   std::cout &lt;&lt; uvec[i] &lt;&lt; " " &lt;&lt; freqv[i] &lt;&lt; "\n";
//@E };
//@E 
//@E rtn_mp = asc_occu(uvec, freqv);
//@E rtn_it = rtn_mp.begin();
//@E uvec = rtn_it-&gt;first;
//@E freqv = rtn_it-&gt;second;
//@E 
//@E for (i = 0; i &lt; freqv.size(); ++i) {
//@E   std::cout &lt;&lt; uvec[i] &lt;&lt; " " &lt;&lt; freqv[i] &lt;&lt; "\n";
//@E };
//@E mm 1
//@E po 2
//@E rr 2
//@E lm 3
//@X
#endif

template <typename T> std::map<std::vector<T>, std::vector<unsigned int>> asc_occu(std::vector<T> vec, std::vector<unsigned int> freqv) {
  int cur_min;
  int ref_max = max(freqv) + 1;
  unsigned int cur_idx;
  std::vector<unsigned int> rtn_freqv = {};
  std::vector<std::string> rtn_vec = {};
  const unsigned int n = vec.size();
  rtn_freqv.reserve(n);
  rtn_vec.reserve(n);
  for (unsigned int i = 0; i < n; ++i) {
    cur_min = min(freqv);
    cur_idx = match(freqv, cur_min);
    rtn_vec.push_back(vec[cur_idx]);
    rtn_freqv.push_back(freqv[cur_idx]);
    freqv[cur_idx] = ref_max + 1;
  };
  return {{rtn_vec, rtn_freqv}};
};

//@L2 Others

//@T pct_to_idx
//@U unsigned int percentage_to_idx(double &val, unsigned int &sizen)
//@X
//@D Returns an idx of a stl vector from a percentage between 0 and 1.
//@A val : is the percentage value, between 0 and 1
//@A sizen : is the size of the vector you want to have the index.
//@X
//@E std::&lt;int&gt; vec = {1, 2, 3, 4};
//@E unsigned int sizen = vec.size();
//@E double pct = 0.6;
//@E unsigned int out = pct_to_idx(pct, sizen);
//@E 2
//@X

template <typename T> unsigned int pct_to_idx(T &val, unsigned int &sizen) {
  double bval = (sizen - 1) * val;
  int binc = bval; 
  if (bval - binc > 0.5) {
    binc += 1;
  };
  return binc;
};

//@T diff_mean
//@U template &lt;typename T&gt; double diff_mean(std::vector&lt;T&gt; &x)
//@X
//@D Returns the mean of all the differences in value between the contiguous elementsof a stl vector.
//@A x : is a stl vector (int, float, double, bool)
//@X
//@E std::vector&lt;double&gt; vec = {10, 10.5, 11, 11.5};
//@E diff_mean(vec);
//@E 0.5
//@X

template <typename T> double diff_mean(std::vector<T> &x) {
  const unsigned int n = x.size();
  double tsum = 0;
  double cur_val;
  for (unsigned int i = 1; i < n; ++i) {
    cur_val = x[i] - x[i - 1];
    if (cur_val < 0) {
      cur_val *= -1;
    };
    tsum += cur_val;
  };
  return tsum / (n - 1);
};

//@L1 The Dataframe Object

//@T Dataframe
//@U Dataframe my_dataframe
//@X
//@D Dataframe objects supporting writing / reading csv, storing columns in differents vectors type (automatically or not), specifying the rows and columns to copy or get by reference, perform all types of joins, groupby... See examples.
//@A See_below : See below
//@X
//@E See below
//@X

struct PairHash {
    using sv = std::string_view;
    std::size_t operator()(const std::pair<sv, sv>& p) const noexcept {
        std::size_t h1 = std::hash<sv>{}(p.first);
        std::size_t h2 = std::hash<sv>{}(p.second);
        return h1 ^ (h2 + 0x9e3779b97f4a7c15ULL + (h1 << 6) + (h1 >> 2));
    }
};

class Dataframe{
  private:
    
    unsigned int nrow = 0;
    unsigned int ncol = 0;
  
    std::vector<std::string> str_v = {};
    std::vector<char> chr_v = {};
    std::vector<bool> bool_v = {};
    std::vector<int> int_v = {};
    std::vector<unsigned int> uint_v = {};
    std::vector<double> dbl_v = {};
   
    std::vector<int> pre_str_v = {};
    std::vector<unsigned int> pre_chr_v = {};

    std::vector<std::vector<unsigned int>> matr_idx = {{}, {}, {}, {}, {}, {}};
    std::vector<std::string> name_v = {};
    std::vector<std::string> name_v_row = {};
    std::vector<unsigned int> longest_v = {};

    std::vector<char> type_refv = {};
    std::vector<std::vector<std::string>> tmp_val_refv = {};

    const std::vector<std::string>& get_str_vec() const {
      return str_v;
    };

    const std::vector<char>& get_chr_vec() const {
      return chr_v;
    };

    const std::vector<bool>& get_bool_vec() const {
      return bool_v;
    };

    const std::vector<int>& get_int_vec() const {
      return int_v;
    };

    const std::vector<unsigned int>& get_uint_vec() const {
      return uint_v;
    };

    const std::vector<double>& get_dbl_vec() const {
      return dbl_v;
    };

    const std::vector<std::vector<unsigned int>>& get_matr_idx() const {
      return matr_idx;
    };

    void longest_determine() {
      unsigned int i;
      unsigned int i2;
      if (name_v.size() > 0) {
        for (i = 0; i < ncol; ++i) {
          longest_v.push_back(name_v[i].length());
        };
      } else {
        longest_v.resize(ncol, 0);
      }; 
      for (i = 0; i < ncol; ++i) {
        for (i2 = 0; i2 < nrow; ++i2) {
          if (tmp_val_refv[i][i2].length() > longest_v[i]) {
            longest_v[i] = tmp_val_refv[i][i2].length();
          };
        };
      };
    };

  public:
    
    template <unsigned int strt_row = 0, unsigned int end_row = 0>
    void readf(std::string &file_name, char delim = ',', bool header_name = 1, char str_context_begin = '\'', char str_context_end = '\'') {
      std::string currow;
      std::string cur_str = "";
      std::fstream readfile(file_name);
      getline(readfile, currow);
      ncol = 1;
      std::vector<std::string> ex_vec = {};
      std::vector<unsigned int> matr_unknown_vec = {};
      unsigned int i = 0;
      unsigned int verif_ncol;
      unsigned int max_lngth;
      bool str_cxt = 0;
      if (header_name) {
        while (i < currow.length()) {
          if (currow[i] == delim && !str_cxt) {
            if (i == 0) {
              max_lngth = 2;
              name_v.push_back("NA");
            } else if (currow[i - 1] == delim) {
              max_lngth = 2;
              name_v.push_back("NA");
            } else {
              max_lngth = cur_str.length();
              name_v.push_back(cur_str);
            };
            tmp_val_refv.push_back(ex_vec);
            ncol += 1;
            cur_str = "";
            longest_v.push_back(max_lngth);
          } else if (currow[i] == str_context_begin) {
            str_cxt = 1; 
          } else if (currow[i] == str_context_end) {
            str_cxt = 0;
          } else {
            cur_str.push_back(currow[i]);
          };
          i += 1;
        };
        if (currow[i - 1] == delim) {
          max_lngth = 2;
          name_v.push_back("NA");
        } else {
          max_lngth = cur_str.length();
          name_v.push_back(cur_str);
        };
        tmp_val_refv.push_back(ex_vec);
        cur_str = "";
        longest_v.push_back(max_lngth);
      } else {
        while (i < currow.length()) {
          if (currow[i] == delim && !str_cxt) {
            if (i == 0) {
              max_lngth = 2;
            } else if (currow[i - 1] == delim) {
              max_lngth = 2;
            } else {
              max_lngth = cur_str.length();
              ex_vec.push_back(cur_str);
              tmp_val_refv.push_back(ex_vec);
              ex_vec = {};
            };
            ncol += 1;
            cur_str = "";
            longest_v.push_back(max_lngth);
          } else if (currow[i] == str_context_begin) {
            str_cxt = 1;
          } else if (currow[i] == str_context_end) {
            str_cxt = 0;
          } else {
            cur_str.push_back(currow[i]);
          };
          i += 1;
        };
        if (currow[i - 1] == delim) {
          max_lngth = 2;
        } else {
          max_lngth = cur_str.length();
          ex_vec.push_back(cur_str);
          tmp_val_refv.push_back(ex_vec);
          ex_vec = {};
        };
        cur_str = "";
        longest_v.push_back(max_lngth);
        nrow += 1;
      };
      type_refv.reserve(ncol);

      if constexpr (strt_row == 0 && end_row == 0) {

        while (getline(readfile, currow)) {
          verif_ncol = 1;
          str_cxt = 0;
          i = 0;
          while (i < currow.length()) {
            if (currow[i] == delim && !str_cxt) {
              if (i == 0) {
                if (longest_v[verif_ncol - 1] < 2) {
                  longest_v[verif_ncol - 1] = 2;
                };
                tmp_val_refv[0].push_back("NA");
              } else if (currow[i - 1] == delim) {
                if (longest_v[verif_ncol - 1] < 2) {
                  longest_v[verif_ncol - 1] = 2;
                };
                tmp_val_refv[verif_ncol - 1].push_back("NA");
              } else {
                if (longest_v[verif_ncol - 1] < cur_str.length()) {
                  longest_v[verif_ncol - 1] = cur_str.length();
                };
                tmp_val_refv[verif_ncol - 1].push_back(cur_str);
              };
              cur_str = "";
              verif_ncol += 1;
            } else if (currow[i] == str_context_begin) {
              str_cxt = 1;
            } else if (currow[i] == str_context_end) {
              str_cxt = 0;
            } else {
              cur_str.push_back(currow[i]);
            };
            i += 1;
          };
          if (currow[i - 1] == delim) {
            if (longest_v[verif_ncol - 1] < 2) {
              longest_v[verif_ncol - 1] = 2;
            };
            tmp_val_refv[verif_ncol - 1].push_back("0");
          } else {
            if (longest_v[verif_ncol - 1] < cur_str.length()) {
              longest_v[verif_ncol - 1] = cur_str.length();
            };
            tmp_val_refv[verif_ncol - 1].push_back(cur_str);
          };
          cur_str = "";
          if (verif_ncol != ncol) {
            std::cout << "column number problem at row: " << nrow << "\n";
            reinitiate();
            return;
          };
          nrow += 1;
        };

      } else if constexpr (strt_row != 0 && end_row != 0) {
      
        if (strt_row > end_row) {
          std::cerr << "strt_row must be lower or equal than end_row\n";
          return;
        };

        unsigned int row_check = 0;
        while (row_check < strt_row) {
          getline(readfile, currow);
          row_check += 1;
        };

        while (getline(readfile, currow)) {
          verif_ncol = 1;
          str_cxt = 0;
          i = 0;
          while (i < currow.length()) {
            if (currow[i] == delim && !str_cxt) {
              if (i == 0) {
                if (longest_v[verif_ncol - 1] < 2) {
                  longest_v[verif_ncol - 1] = 2;
                };
                tmp_val_refv[0].push_back("NA");
              } else if (currow[i - 1] == delim) {
                if (longest_v[verif_ncol - 1] < 2) {
                  longest_v[verif_ncol - 1] = 2;
                };
                tmp_val_refv[verif_ncol - 1].push_back("NA");
              } else {
                if (longest_v[verif_ncol - 1] < cur_str.length()) {
                  longest_v[verif_ncol - 1] = cur_str.length();
                };
                tmp_val_refv[verif_ncol - 1].push_back(cur_str);
              };
              cur_str = "";
              verif_ncol += 1;
            } else if (currow[i] == str_context_begin) {
              str_cxt = 1;
            } else if (currow[i] == str_context_end) {
              str_cxt = 0;
            } else {
              cur_str.push_back(currow[i]);
            };
            i += 1;
          };
          if (currow[i - 1] == delim) {
            if (longest_v[verif_ncol - 1] < 2) {
              longest_v[verif_ncol - 1] = 2;
            };
            tmp_val_refv[verif_ncol - 1].push_back("0");
          } else {
            if (longest_v[verif_ncol - 1] < cur_str.length()) {
              longest_v[verif_ncol - 1] = cur_str.length();
            };
            tmp_val_refv[verif_ncol - 1].push_back(cur_str);
          };
          cur_str = "";
          if (verif_ncol != ncol) {
            std::cout << "column number problem at row: " << nrow << "\n";
            reinitiate();
            return;
          };
          nrow += 1;
          row_check += 1;
          if (row_check > end_row) {
            break;
          };
        };

      } else if constexpr (strt_row != 0) {

        unsigned int row_check = 0;
        while (row_check < strt_row) {
          getline(readfile, currow);
          row_check += 1;
        };

        while (getline(readfile, currow)) {
          verif_ncol = 1;
          str_cxt = 0;
          i = 0;
          while (i < currow.length()) {
            if (currow[i] == delim && !str_cxt) {
              if (i == 0) {
                if (longest_v[verif_ncol - 1] < 2) {
                  longest_v[verif_ncol - 1] = 2;
                };
                tmp_val_refv[0].push_back("NA");
              } else if (currow[i - 1] == delim) {
                if (longest_v[verif_ncol - 1] < 2) {
                  longest_v[verif_ncol - 1] = 2;
                };
                tmp_val_refv[verif_ncol - 1].push_back("NA");
              } else {
                if (longest_v[verif_ncol - 1] < cur_str.length()) {
                  longest_v[verif_ncol - 1] = cur_str.length();
                };
                tmp_val_refv[verif_ncol - 1].push_back(cur_str);
              };
              cur_str = "";
              verif_ncol += 1;
            } else if (currow[i] == str_context_begin) {
              str_cxt = 1;
            } else if (currow[i] == str_context_end) {
              str_cxt = 0;
            } else {
              cur_str.push_back(currow[i]);
            };
            i += 1;
          };
          if (currow[i - 1] == delim) {
            if (longest_v[verif_ncol - 1] < 2) {
              longest_v[verif_ncol - 1] = 2;
            };
            tmp_val_refv[verif_ncol - 1].push_back("0");
          } else {
            if (longest_v[verif_ncol - 1] < cur_str.length()) {
              longest_v[verif_ncol - 1] = cur_str.length();
            };
            tmp_val_refv[verif_ncol - 1].push_back(cur_str);
          };
          cur_str = "";
          if (verif_ncol != ncol) {
            std::cout << "column number problem at row: " << nrow << "\n";
            reinitiate();
            return;
          };
          nrow += 1;
        };

      } else if constexpr (end_row != 0) {

        unsigned int row_check = 0;

        while (getline(readfile, currow)) {
          verif_ncol = 1;
          str_cxt = 0;
          i = 0;
          while (i < currow.length()) {
            if (currow[i] == delim && !str_cxt) {
              if (i == 0) {
                if (longest_v[verif_ncol - 1] < 2) {
                  longest_v[verif_ncol - 1] = 2;
                };
                tmp_val_refv[0].push_back("NA");
              } else if (currow[i - 1] == delim) {
                if (longest_v[verif_ncol - 1] < 2) {
                  longest_v[verif_ncol - 1] = 2;
                };
                tmp_val_refv[verif_ncol - 1].push_back("NA");
              } else {
                if (longest_v[verif_ncol - 1] < cur_str.length()) {
                  longest_v[verif_ncol - 1] = cur_str.length();
                };
                tmp_val_refv[verif_ncol - 1].push_back(cur_str);
              };
              cur_str = "";
              verif_ncol += 1;
            } else if (currow[i] == str_context_begin) {
              str_cxt = 1;
            } else if (currow[i] == str_context_end) {
              str_cxt = 0;
            } else {
              cur_str.push_back(currow[i]);
            };
            i += 1;
          };
          if (currow[i - 1] == delim) {
            if (longest_v[verif_ncol - 1] < 2) {
              longest_v[verif_ncol - 1] = 2;
            };
            tmp_val_refv[verif_ncol - 1].push_back("0");
          } else {
            if (longest_v[verif_ncol - 1] < cur_str.length()) {
              longest_v[verif_ncol - 1] = cur_str.length();
            };
            tmp_val_refv[verif_ncol - 1].push_back(cur_str);
          };
          cur_str = "";
          if (verif_ncol != ncol) {
            std::cout << "column number problem at row: " << nrow << "\n";
            reinitiate();
            return;
          };
          nrow += 1;
          row_check += 1;
          if (row_check > end_row) {
            break;
          };
        };

      };
      type_classification();
    };

    template <unsigned int strt_row = 0, unsigned int end_row = 0>
    void readf_trim(std::string &file_name, char delim = ',', bool header_name = 1, char str_context_begin = '\'', char str_context_end = '\'') {
      std::string currow;
      std::string cur_str = "";
      std::fstream readfile(file_name);
      getline(readfile, currow);
      ncol = 1;
      std::vector<std::string> ex_vec = {};
      std::vector<unsigned int> matr_unknown_vec = {};
      unsigned int i = 0;
      unsigned int verif_ncol;
      unsigned int max_lngth;
      bool str_cxt = 0;
      if (header_name) {
        while (i < currow.length()) {
          if (currow[i] == delim && !str_cxt) {
            if (i == 0) {
              max_lngth = 2;
              name_v.push_back("NA");
            } else if (currow[i - 1] == delim) {
              max_lngth = 2;
              name_v.push_back("NA");
            } else {
              max_lngth = cur_str.length();
              name_v.push_back(cur_str);
            };
            tmp_val_refv.push_back(ex_vec);
            ncol += 1;
            cur_str = "";
            longest_v.push_back(max_lngth);
          } else if (currow[i] == str_context_begin) {
            str_cxt = 1; 
          } else if (currow[i] == str_context_end) {
            str_cxt = 0;
          } else {
            cur_str.push_back(currow[i]);
          };
          i += 1;
        };
        if (currow[i - 1] == delim) {
          max_lngth = 2;
          name_v.push_back("NA");
        } else {
          max_lngth = cur_str.length();
          name_v.push_back(cur_str);
        };
        tmp_val_refv.push_back(ex_vec);
        cur_str = "";
        longest_v.push_back(max_lngth);
      } else {
        while (i < currow.length()) {
          if (currow[i] == delim && !str_cxt) {
            if (i == 0) {
              max_lngth = 2;
            } else if (currow[i - 1] == delim) {
              max_lngth = 2;
            } else {
              max_lngth = cur_str.length();
              ex_vec.push_back(cur_str);
              tmp_val_refv.push_back(ex_vec);
              ex_vec = {};
            };
            ncol += 1;
            cur_str = "";
            longest_v.push_back(max_lngth);
          } else if (currow[i] == str_context_begin) {
            str_cxt = 1;
          } else if (currow[i] == str_context_end) {
            str_cxt = 0;
          } else {
            cur_str.push_back(currow[i]);
          };
          i += 1;
        };
        if (currow[i - 1] == delim) {
          max_lngth = 2;
        } else {
          max_lngth = cur_str.length();
          ex_vec.push_back(cur_str);
          tmp_val_refv.push_back(ex_vec);
          ex_vec = {};
        };
        cur_str = "";
        longest_v.push_back(max_lngth);
        nrow += 1;
      };
      type_refv.reserve(ncol);
      if constexpr (strt_row == 0 && end_row == 0) {
        while (getline(readfile, currow)) {
          verif_ncol = 1;
          str_cxt = 0;
          i = 0;
          while (i < currow.length()) {
            if (currow[i] == delim && !str_cxt) {
              if (i == 0) {
                if (longest_v[verif_ncol - 1] < 2) {
                  longest_v[verif_ncol - 1] = 2;
                };
                tmp_val_refv[0].push_back("NA");
              } else if (currow[i - 1] == delim) {
                if (longest_v[verif_ncol - 1] < 2) {
                  longest_v[verif_ncol - 1] = 2;
                };
                tmp_val_refv[verif_ncol - 1].push_back("NA");
              } else {
                
                while (!(cur_str.empty()) && cur_str.back() == ' ') {
                  cur_str.pop_back();
                };

                size_t start = 0;

                while (!(cur_str.empty()) && cur_str[start] == ' ') {
                  start += 1;
                };

                cur_str.erase(0, start);

                if (longest_v[verif_ncol - 1] < cur_str.length()) {
                  longest_v[verif_ncol - 1] = cur_str.length();
                };

                tmp_val_refv[verif_ncol - 1].push_back(cur_str);
              };
              cur_str = "";
              verif_ncol += 1;
            } else if (currow[i] == str_context_begin) {
              str_cxt = 1;
            } else if (currow[i] == str_context_end) {
              str_cxt = 0;
            } else {
              cur_str.push_back(currow[i]);
            };
            i += 1;
          };
          if (currow[i - 1] == delim) {
            if (longest_v[verif_ncol - 1] < 2) {
              longest_v[verif_ncol - 1] = 2;
            };
            tmp_val_refv[verif_ncol - 1].push_back("NA");
          } else {
          
            while (!(cur_str.empty()) && cur_str.back() == ' ') {
              cur_str.pop_back();
            };

            size_t start = 0;

            while (!(cur_str.empty()) && cur_str[start] == ' ') {
              start += 1;
            };

            cur_str.erase(0, start);

            if (longest_v[verif_ncol - 1] < cur_str.length()) {
              longest_v[verif_ncol - 1] = cur_str.length();
            };

            tmp_val_refv[verif_ncol - 1].push_back(cur_str);

          };
          cur_str = "";
          if (verif_ncol != ncol) {
            std::cout << "column number problem at row: " << nrow << "\n";
            reinitiate();
            return;
          };
          nrow += 1;
        };
      } else if constexpr (strt_row != 0 && end_row != 0) {

        if (strt_row > end_row) {
          std::cerr << "strt_row must be lower or equal than end_row\n";
          return;
        };

        unsigned int row_check = 0;
        while (row_check < strt_row) {
          getline(readfile, currow);
          row_check += 1;
        };

        while (getline(readfile, currow)) {
          verif_ncol = 1;
          str_cxt = 0;
          i = 0;
          while (i < currow.length()) {
            if (currow[i] == delim && !str_cxt) {
              if (i == 0) {
                if (longest_v[verif_ncol - 1] < 2) {
                  longest_v[verif_ncol - 1] = 2;
                };
                tmp_val_refv[0].push_back("NA");
              } else if (currow[i - 1] == delim) {
                if (longest_v[verif_ncol - 1] < 2) {
                  longest_v[verif_ncol - 1] = 2;
                };
                tmp_val_refv[verif_ncol - 1].push_back("NA");
              } else {
                
                while (!(cur_str.empty()) && cur_str.back() == ' ') {
                  cur_str.pop_back();
                };

                size_t start = 0;

                while (!(cur_str.empty()) && cur_str[start] == ' ') {
                  start += 1;
                };

                cur_str.erase(0, start);

                if (longest_v[verif_ncol - 1] < cur_str.length()) {
                  longest_v[verif_ncol - 1] = cur_str.length();
                };

                tmp_val_refv[verif_ncol - 1].push_back(cur_str);
              };
              cur_str = "";
              verif_ncol += 1;
            } else if (currow[i] == str_context_begin) {
              str_cxt = 1;
            } else if (currow[i] == str_context_end) {
              str_cxt = 0;
            } else {
              cur_str.push_back(currow[i]);
            };
            i += 1;
          };
          if (currow[i - 1] == delim) {
            if (longest_v[verif_ncol - 1] < 2) {
              longest_v[verif_ncol - 1] = 2;
            };
            tmp_val_refv[verif_ncol - 1].push_back("NA");
          } else {
          
            while (!(cur_str.empty()) && cur_str.back() == ' ') {
              cur_str.pop_back();
            };

            size_t start = 0;

            while (!(cur_str.empty()) && cur_str[start] == ' ') {
              start += 1;
            };

            cur_str.erase(0, start);

            if (longest_v[verif_ncol - 1] < cur_str.length()) {
              longest_v[verif_ncol - 1] = cur_str.length();
            };

            tmp_val_refv[verif_ncol - 1].push_back(cur_str);

          };
          cur_str = "";
          if (verif_ncol != ncol) {
            std::cout << "column number problem at row: " << nrow << "\n";
            reinitiate();
            return;
          };
          row_check += 1;
          nrow += 1;
          if (row_check > end_row) {
            break;
          };
        };

      } else if constexpr (strt_row != 0) {

        unsigned int row_check = 0;
        while (row_check < strt_row) {
          getline(readfile, currow);
          row_check += 1;
        };

        while (getline(readfile, currow)) {
          verif_ncol = 1;
          str_cxt = 0;
          i = 0;
          while (i < currow.length()) {
            if (currow[i] == delim && !str_cxt) {
              if (i == 0) {
                if (longest_v[verif_ncol - 1] < 2) {
                  longest_v[verif_ncol - 1] = 2;
                };
                tmp_val_refv[0].push_back("NA");
              } else if (currow[i - 1] == delim) {
                if (longest_v[verif_ncol - 1] < 2) {
                  longest_v[verif_ncol - 1] = 2;
                };
                tmp_val_refv[verif_ncol - 1].push_back("NA");
              } else {
                
                while (!(cur_str.empty()) && cur_str.back() == ' ') {
                  cur_str.pop_back();
                };

                size_t start = 0;

                while (!(cur_str.empty()) && cur_str[start] == ' ') {
                  start += 1;
                };

                cur_str.erase(0, start);

                if (longest_v[verif_ncol - 1] < cur_str.length()) {
                  longest_v[verif_ncol - 1] = cur_str.length();
                };

                tmp_val_refv[verif_ncol - 1].push_back(cur_str);
              };
              cur_str = "";
              verif_ncol += 1;
            } else if (currow[i] == str_context_begin) {
              str_cxt = 1;
            } else if (currow[i] == str_context_end) {
              str_cxt = 0;
            } else {
              cur_str.push_back(currow[i]);
            };
            i += 1;
          };
          if (currow[i - 1] == delim) {
            if (longest_v[verif_ncol - 1] < 2) {
              longest_v[verif_ncol - 1] = 2;
            };
            tmp_val_refv[verif_ncol - 1].push_back("NA");
          } else {
          
            while (!(cur_str.empty()) && cur_str.back() == ' ') {
              cur_str.pop_back();
            };

            size_t start = 0;

            while (!(cur_str.empty()) && cur_str[start] == ' ') {
              start += 1;
            };

            cur_str.erase(0, start);

            if (longest_v[verif_ncol - 1] < cur_str.length()) {
              longest_v[verif_ncol - 1] = cur_str.length();
            };

            tmp_val_refv[verif_ncol - 1].push_back(cur_str);

          };
          cur_str = "";
          if (verif_ncol != ncol) {
            std::cout << "column number problem at row: " << nrow << "\n";
            reinitiate();
            return;
          };
          nrow += 1;
        };

      } else if constexpr (end_row != 0) {

        unsigned int row_check = 0;

        while (getline(readfile, currow)) {
          verif_ncol = 1;
          str_cxt = 0;
          i = 0;
          while (i < currow.length()) {
            if (currow[i] == delim && !str_cxt) {
              if (i == 0) {
                if (longest_v[verif_ncol - 1] < 2) {
                  longest_v[verif_ncol - 1] = 2;
                };
                tmp_val_refv[0].push_back("NA");
              } else if (currow[i - 1] == delim) {
                if (longest_v[verif_ncol - 1] < 2) {
                  longest_v[verif_ncol - 1] = 2;
                };
                tmp_val_refv[verif_ncol - 1].push_back("NA");
              } else {
                
                while (!(cur_str.empty()) && cur_str.back() == ' ') {
                  cur_str.pop_back();
                };

                size_t start = 0;

                while (!(cur_str.empty()) && cur_str[start] == ' ') {
                  start += 1;
                };

                cur_str.erase(0, start);

                if (longest_v[verif_ncol - 1] < cur_str.length()) {
                  longest_v[verif_ncol - 1] = cur_str.length();
                };

                tmp_val_refv[verif_ncol - 1].push_back(cur_str);
              };
              cur_str = "";
              verif_ncol += 1;
            } else if (currow[i] == str_context_begin) {
              str_cxt = 1;
            } else if (currow[i] == str_context_end) {
              str_cxt = 0;
            } else {
              cur_str.push_back(currow[i]);
            };
            i += 1;
          };
          if (currow[i - 1] == delim) {
            if (longest_v[verif_ncol - 1] < 2) {
              longest_v[verif_ncol - 1] = 2;
            };
            tmp_val_refv[verif_ncol - 1].push_back("NA");
          } else {
          
            while (!(cur_str.empty()) && cur_str.back() == ' ') {
              cur_str.pop_back();
            };

            size_t start = 0;

            while (!(cur_str.empty()) && cur_str[start] == ' ') {
              start += 1;
            };

            cur_str.erase(0, start);

            if (longest_v[verif_ncol - 1] < cur_str.length()) {
              longest_v[verif_ncol - 1] = cur_str.length();
            };

            tmp_val_refv[verif_ncol - 1].push_back(cur_str);

          };
          cur_str = "";
          if (verif_ncol != ncol) {
            std::cout << "column number problem at row: " << nrow << "\n";
            reinitiate();
            return;
          };
          nrow += 1;
          row_check += 1;
          if (row_check > end_row) {
            break;
          };
        };

      };
      type_classification();
    };

    template <unsigned int strt_row = 0, unsigned int end_row = 0>
    void readf_lambda(std::string &file_name, 
                    void (&f)(std::string&),
                    char delim = ',', 
                    bool header_name = 1, 
                    char str_context_begin = '\'', 
                    char str_context_end = '\'') {
      std::string currow;
      std::string cur_str = "";
      std::fstream readfile(file_name);
      getline(readfile, currow);
      ncol = 1;
      std::vector<std::string> ex_vec = {};
      std::vector<unsigned int> matr_unknown_vec = {};
      unsigned int i = 0;
      unsigned int verif_ncol;
      unsigned int max_lngth;
      bool str_cxt = 0;
      if (header_name) {
        while (i < currow.length()) {
          if (currow[i] == delim && !str_cxt) {
            if (i == 0) {
              max_lngth = 2;
              name_v.push_back("NA");
            } else if (currow[i - 1] == delim) {
              max_lngth = 2;
              name_v.push_back("NA");
            } else {
              max_lngth = cur_str.length();
              name_v.push_back(cur_str);
            };
            tmp_val_refv.push_back(ex_vec);
            ncol += 1;
            cur_str = "";
            longest_v.push_back(max_lngth);
          } else if (currow[i] == str_context_begin) {
            str_cxt = 1; 
          } else if (currow[i] == str_context_end) {
            str_cxt = 0;
          } else {
            cur_str.push_back(currow[i]);
          };
          i += 1;
        };
        if (currow[i - 1] == delim) {
          max_lngth = 2;
          name_v.push_back("NA");
        } else {
          max_lngth = cur_str.length();
          name_v.push_back(cur_str);
        };
        tmp_val_refv.push_back(ex_vec);
        cur_str = "";
        longest_v.push_back(max_lngth);
      } else {
        while (i < currow.length()) {
          if (currow[i] == delim && !str_cxt) {
            if (i == 0) {
              max_lngth = 2;
            } else if (currow[i - 1] == delim) {
              max_lngth = 2;
            } else {
              max_lngth = cur_str.length();
              ex_vec.push_back(cur_str);
              tmp_val_refv.push_back(ex_vec);
              ex_vec = {};
            };
            ncol += 1;
            cur_str = "";
            longest_v.push_back(max_lngth);
          } else if (currow[i] == str_context_begin) {
            str_cxt = 1;
          } else if (currow[i] == str_context_end) {
            str_cxt = 0;
          } else {
            cur_str.push_back(currow[i]);
          };
          i += 1;
        };
        if (currow[i - 1] == delim) {
          max_lngth = 2;
        } else {
          max_lngth = cur_str.length();
          ex_vec.push_back(cur_str);
          tmp_val_refv.push_back(ex_vec);
          ex_vec = {};
        };
        cur_str = "";
        longest_v.push_back(max_lngth);
        nrow += 1;
      };
      type_refv.reserve(ncol);
      if constexpr (strt_row == 0 && end_row == 0) {
        while (getline(readfile, currow)) {
          verif_ncol = 1;
          str_cxt = 0;
          i = 0;
          while (i < currow.length()) {
            if (currow[i] == delim && !str_cxt) {
              if (i == 0) {
                if (longest_v[verif_ncol - 1] < 2) {
                  longest_v[verif_ncol - 1] = 2;
                };
                tmp_val_refv[0].push_back("NA");
              } else if (currow[i - 1] == delim) {
                if (longest_v[verif_ncol - 1] < 2) {
                  longest_v[verif_ncol - 1] = 2;
                };
                tmp_val_refv[verif_ncol - 1].push_back("NA");
              } else {
                
                f(cur_str);

                if (longest_v[verif_ncol - 1] < cur_str.length()) {
                  longest_v[verif_ncol - 1] = cur_str.length();
                };

                tmp_val_refv[verif_ncol - 1].push_back(cur_str);
              };
              cur_str = "";
              verif_ncol += 1;
            } else if (currow[i] == str_context_begin) {
              str_cxt = 1;
            } else if (currow[i] == str_context_end) {
              str_cxt = 0;
            } else {
              cur_str.push_back(currow[i]);
            };
            i += 1;
          };
          if (currow[i - 1] == delim) {
            if (longest_v[verif_ncol - 1] < 2) {
              longest_v[verif_ncol - 1] = 2;
            };
            tmp_val_refv[verif_ncol - 1].push_back("NA");
          } else {
          
            f(cur_str);
            
            if (longest_v[verif_ncol - 1] < cur_str.length()) {
              longest_v[verif_ncol - 1] = cur_str.length();
            };

            tmp_val_refv[verif_ncol - 1].push_back(cur_str);

          };
          cur_str = "";
          if (verif_ncol != ncol) {
            std::cout << "column number problem at row: " << nrow << "\n";
            reinitiate();
            return;
          };
          nrow += 1;
        };
      } else if constexpr (strt_row != 0 && end_row != 0) {

        unsigned int row_check = 0;
        while (row_check < strt_row) {
          getline(readfile, currow);
          row_check += 1;
        };

        while (getline(readfile, currow)) {
          verif_ncol = 1;
          str_cxt = 0;
          i = 0;
          while (i < currow.length()) {
            if (currow[i] == delim && !str_cxt) {
              if (i == 0) {
                if (longest_v[verif_ncol - 1] < 2) {
                  longest_v[verif_ncol - 1] = 2;
                };
                tmp_val_refv[0].push_back("NA");
              } else if (currow[i - 1] == delim) {
                if (longest_v[verif_ncol - 1] < 2) {
                  longest_v[verif_ncol - 1] = 2;
                };
                tmp_val_refv[verif_ncol - 1].push_back("NA");
              } else {
                
                f(cur_str);

                if (longest_v[verif_ncol - 1] < cur_str.length()) {
                  longest_v[verif_ncol - 1] = cur_str.length();
                };

                tmp_val_refv[verif_ncol - 1].push_back(cur_str);
              };
              cur_str = "";
              verif_ncol += 1;
            } else if (currow[i] == str_context_begin) {
              str_cxt = 1;
            } else if (currow[i] == str_context_end) {
              str_cxt = 0;
            } else {
              cur_str.push_back(currow[i]);
            };
            i += 1;
          };
          if (currow[i - 1] == delim) {
            if (longest_v[verif_ncol - 1] < 2) {
              longest_v[verif_ncol - 1] = 2;
            };
            tmp_val_refv[verif_ncol - 1].push_back("NA");
          } else {
          
            f(cur_str);
            
            if (longest_v[verif_ncol - 1] < cur_str.length()) {
              longest_v[verif_ncol - 1] = cur_str.length();
            };

            tmp_val_refv[verif_ncol - 1].push_back(cur_str);

          };
          cur_str = "";
          if (verif_ncol != ncol) {
            std::cout << "column number problem at row: " << nrow << "\n";
            reinitiate();
            return;
          };
          nrow += 1;
          row_check += 1;
          if (row_check > end_row) {
            break;
          };
        };
      } else if constexpr (strt_row != 0) {

        unsigned int row_check = 0;
        while (row_check < strt_row) {
          getline(readfile, currow);
          row_check += 1;
        };

        while (getline(readfile, currow)) {
          verif_ncol = 1;
          str_cxt = 0;
          i = 0;
          while (i < currow.length()) {
            if (currow[i] == delim && !str_cxt) {
              if (i == 0) {
                if (longest_v[verif_ncol - 1] < 2) {
                  longest_v[verif_ncol - 1] = 2;
                };
                tmp_val_refv[0].push_back("NA");
              } else if (currow[i - 1] == delim) {
                if (longest_v[verif_ncol - 1] < 2) {
                  longest_v[verif_ncol - 1] = 2;
                };
                tmp_val_refv[verif_ncol - 1].push_back("NA");
              } else {
                
                f(cur_str);

                if (longest_v[verif_ncol - 1] < cur_str.length()) {
                  longest_v[verif_ncol - 1] = cur_str.length();
                };

                tmp_val_refv[verif_ncol - 1].push_back(cur_str);
              };
              cur_str = "";
              verif_ncol += 1;
            } else if (currow[i] == str_context_begin) {
              str_cxt = 1;
            } else if (currow[i] == str_context_end) {
              str_cxt = 0;
            } else {
              cur_str.push_back(currow[i]);
            };
            i += 1;
          };
          if (currow[i - 1] == delim) {
            if (longest_v[verif_ncol - 1] < 2) {
              longest_v[verif_ncol - 1] = 2;
            };
            tmp_val_refv[verif_ncol - 1].push_back("NA");
          } else {
          
            f(cur_str);
            
            if (longest_v[verif_ncol - 1] < cur_str.length()) {
              longest_v[verif_ncol - 1] = cur_str.length();
            };

            tmp_val_refv[verif_ncol - 1].push_back(cur_str);

          };
          cur_str = "";
          if (verif_ncol != ncol) {
            std::cout << "column number problem at row: " << nrow << "\n";
            reinitiate();
            return;
          };
          nrow += 1;
        };

      } else if (end_row != 0) {

        unsigned int row_check = 0;
        while (getline(readfile, currow)) {
          verif_ncol = 1;
          str_cxt = 0;
          i = 0;
          while (i < currow.length()) {
            if (currow[i] == delim && !str_cxt) {
              if (i == 0) {
                if (longest_v[verif_ncol - 1] < 2) {
                  longest_v[verif_ncol - 1] = 2;
                };
                tmp_val_refv[0].push_back("NA");
              } else if (currow[i - 1] == delim) {
                if (longest_v[verif_ncol - 1] < 2) {
                  longest_v[verif_ncol - 1] = 2;
                };
                tmp_val_refv[verif_ncol - 1].push_back("NA");
              } else {
                
                f(cur_str);

                if (longest_v[verif_ncol - 1] < cur_str.length()) {
                  longest_v[verif_ncol - 1] = cur_str.length();
                };

                tmp_val_refv[verif_ncol - 1].push_back(cur_str);
              };
              cur_str = "";
              verif_ncol += 1;
            } else if (currow[i] == str_context_begin) {
              str_cxt = 1;
            } else if (currow[i] == str_context_end) {
              str_cxt = 0;
            } else {
              cur_str.push_back(currow[i]);
            };
            i += 1;
          };
          if (currow[i - 1] == delim) {
            if (longest_v[verif_ncol - 1] < 2) {
              longest_v[verif_ncol - 1] = 2;
            };
            tmp_val_refv[verif_ncol - 1].push_back("NA");
          } else {
          
            f(cur_str);
            
            if (longest_v[verif_ncol - 1] < cur_str.length()) {
              longest_v[verif_ncol - 1] = cur_str.length();
            };

            tmp_val_refv[verif_ncol - 1].push_back(cur_str);

          };
          cur_str = "";
          if (verif_ncol != ncol) {
            std::cout << "column number problem at row: " << nrow << "\n";
            reinitiate();
            return;
          };
          nrow += 1;
          row_check += 1;
          if (row_check > end_row) {
            break;
          };
        };

      };
      type_classification();
    };

    template <unsigned int strt_row = 0, unsigned int end_row = 0>
    void readf_alrd(std::string &file_name, 
                    std::string& dtype,
                    char delim = ',', 
                    bool header_name = 1, 
                    char str_context_begin = '\'', 
                    char str_context_end = '\'') {
      std::string currow;
      std::string cur_str = "";
      std::fstream readfile(file_name);
      getline(readfile, currow);
      ncol = 1;
      std::vector<std::string> ex_vec = {};
      std::vector<unsigned int> matr_unknown_vec = {};
      unsigned int i;
      for (i = 0; i < dtype.size(); i += 1) {
        switch (dtype[i]) {
          case 's' : { matr_idx[0].push_back(i);
                       type_refv.push_back('s');
                       break;
                       };
          case 'c' : { matr_idx[1].push_back(i);
                       type_refv.push_back('c');
                       break;
                       };
          case 'b' : { matr_idx[2].push_back(i);
                       type_refv.push_back('b');
                       break;
                        };
          case 'i' : { matr_idx[3].push_back(i);
                       type_refv.push_back('i');
                       break;
                       };
          case 'u' : { matr_idx[4].push_back(i);
                       type_refv.push_back('u');
                       break;
                        };
          case 'd' : { matr_idx[5].push_back(i);
                       type_refv.push_back('d');
                       break;
                        };
        };
      };
      i = 0;
      unsigned int verif_ncol;
      unsigned int max_lngth;
      bool str_cxt = 0;
      if (header_name) {
        while (i < currow.length()) {
          if (currow[i] == delim && !str_cxt) {
            if (i == 0) {
              max_lngth = 2;
              name_v.push_back("NA");
            } else if (currow[i - 1] == delim) {
              max_lngth = 2;
              name_v.push_back("NA");
            } else {
              max_lngth = cur_str.length();
              name_v.push_back(cur_str);
            };
            tmp_val_refv.push_back(ex_vec);
            ncol += 1;
            cur_str = "";
            longest_v.push_back(max_lngth);
          } else if (currow[i] == str_context_begin) {
            str_cxt = 1; 
          } else if (currow[i] == str_context_end) {
            str_cxt = 0;
          } else {
            cur_str.push_back(currow[i]);
          };
          i += 1;
        };
        if (currow[i - 1] == delim) {
          max_lngth = 2;
          name_v.push_back("NA");
        } else {
          max_lngth = cur_str.length();
          name_v.push_back(cur_str);
        };
        tmp_val_refv.push_back(ex_vec);
        cur_str = "";
        longest_v.push_back(max_lngth);
      } else {
        while (i < currow.length()) {
          if (currow[i] == delim && !str_cxt) {
            if (i == 0) {
              max_lngth = 2;
            } else if (currow[i - 1] == delim) {
              max_lngth = 2;
            } else {
              max_lngth = cur_str.length();
              ex_vec.push_back(cur_str);
              tmp_val_refv.push_back(ex_vec);
              ex_vec = {};
            };
            ncol += 1;
            cur_str = "";
            longest_v.push_back(max_lngth);
          } else if (currow[i] == str_context_begin) {
            str_cxt = 1;
          } else if (currow[i] == str_context_end) {
            str_cxt = 0;
          } else {
            cur_str.push_back(currow[i]);
          };
          i += 1;
        };
        if (currow[i - 1] == delim) {
          max_lngth = 2;
        } else {
          max_lngth = cur_str.length();
          ex_vec.push_back(cur_str);
          tmp_val_refv.push_back(ex_vec);
          ex_vec = {};
        };
        cur_str = "";
        longest_v.push_back(max_lngth);
        nrow += 1;
      };
      type_refv.reserve(ncol);
      if constexpr (strt_row == 0 && end_row == 0) {
        while (getline(readfile, currow)) {
          verif_ncol = 1;
          str_cxt = 0;
          i = 0;
          while (i < currow.length()) {
            if (currow[i] == delim && !str_cxt) {
              if (i == 0) {
                if (longest_v[verif_ncol - 1] < 2) {
                  longest_v[verif_ncol - 1] = 2;
                };
                tmp_val_refv[0].push_back("NA");
              } else if (currow[i - 1] == delim) {
                if (longest_v[verif_ncol - 1] < 2) {
                  longest_v[verif_ncol - 1] = 2;
                };
                tmp_val_refv[verif_ncol - 1].push_back("NA");
              } else {
                
                if (longest_v[verif_ncol - 1] < cur_str.length()) {
                  longest_v[verif_ncol - 1] = cur_str.length();
                };

                tmp_val_refv[verif_ncol - 1].push_back(cur_str);

                switch (dtype[verif_ncol - 1]) {
                  case 's' : 
                          str_v.push_back(cur_str);
                          break;
                  case 'c' : 
                          chr_v.push_back(cur_str[0]);
                          break;
                  case 'b' : 
                          bool_v.push_back(std::stoi(cur_str));
                          break;
                  case 'i' : 
                          int_v.push_back(std::stoi(cur_str));
                          break;
                  case 'u' : 
                          uint_v.push_back(std::stoi(cur_str));
                          break;
                  case 'd' : 
                          dbl_v.push_back(std::stoi(cur_str));
                          break;
                  default:
                        std::cerr << "Unknown dtype: " << dtype[verif_ncol - 1] << "\n";
                        break;
                };

              };
              cur_str = "";
              verif_ncol += 1;
            } else if (currow[i] == str_context_begin) {
              str_cxt = 1;
            } else if (currow[i] == str_context_end) {
              str_cxt = 0;
            } else {
              cur_str.push_back(currow[i]);
            };
            i += 1;
          };
          if (currow[i - 1] == delim) {
            if (longest_v[verif_ncol - 1] < 2) {
              longest_v[verif_ncol - 1] = 2;
            };
            tmp_val_refv[verif_ncol - 1].push_back("NA");
          } else {
          
            if (longest_v[verif_ncol - 1] < cur_str.length()) {
              longest_v[verif_ncol - 1] = cur_str.length();
            };

            tmp_val_refv[verif_ncol - 1].push_back(cur_str);

            switch (dtype[verif_ncol - 1]) {
              case 's' : 
                      str_v.push_back(cur_str);
                      break;
              case 'c' : 
                      chr_v.push_back(cur_str[0]);
                      break;
              case 'b' : 
                      bool_v.push_back(std::stoi(cur_str));
                      break;
              case 'i' : 
                      int_v.push_back(std::stoi(cur_str));
                      break;
              case 'u' : 
                      uint_v.push_back(std::stoi(cur_str));
                      break;
              case 'd' : 
                      dbl_v.push_back(std::stoi(cur_str));
                      break;
              default:
                  std::cerr << "Unknown dtype: " << dtype[verif_ncol - 1] << "\n";
                  break;
            };

          };
          cur_str = "";
          if (verif_ncol != ncol) {
            std::cout << "column number problem at row: " << nrow << "\n";
            reinitiate();
            return;
          };
          nrow += 1;
        };
      } else if constexpr (strt_row != 0 && end_row != 0) {

        unsigned int row_check = 0;
        while (row_check < strt_row) {
          getline(readfile, currow);
          row_check += 1;
        };

        while (getline(readfile, currow)) {
          verif_ncol = 1;
          str_cxt = 0;
          i = 0;
          while (i < currow.length()) {
            if (currow[i] == delim && !str_cxt) {
              if (i == 0) {
                if (longest_v[verif_ncol - 1] < 2) {
                  longest_v[verif_ncol - 1] = 2;
                };
                tmp_val_refv[0].push_back("NA");
              } else if (currow[i - 1] == delim) {
                if (longest_v[verif_ncol - 1] < 2) {
                  longest_v[verif_ncol - 1] = 2;
                };
                tmp_val_refv[verif_ncol - 1].push_back("NA");
              } else {
                
                if (longest_v[verif_ncol - 1] < cur_str.length()) {
                  longest_v[verif_ncol - 1] = cur_str.length();
                };

                tmp_val_refv[verif_ncol - 1].push_back(cur_str);

                switch (dtype[verif_ncol - 1]) {
                  case 's' : 
                          str_v.push_back(cur_str);
                          break;
                  case 'c' : 
                          chr_v.push_back(cur_str[0]);
                          break;
                  case 'b' : 
                          bool_v.push_back(std::stoi(cur_str));
                          break;
                  case 'i' : 
                          int_v.push_back(std::stoi(cur_str));
                          break;
                  case 'u' : 
                          uint_v.push_back(std::stoi(cur_str));
                          break;
                  case 'd' : 
                          dbl_v.push_back(std::stoi(cur_str));
                          break;
                  default:
                        std::cerr << "Unknown dtype: " << dtype[verif_ncol - 1] << "\n";
                        break;
                };

              };
              cur_str = "";
              verif_ncol += 1;
            } else if (currow[i] == str_context_begin) {
              str_cxt = 1;
            } else if (currow[i] == str_context_end) {
              str_cxt = 0;
            } else {
              cur_str.push_back(currow[i]);
            };
            i += 1;
          };
          if (currow[i - 1] == delim) {
            if (longest_v[verif_ncol - 1] < 2) {
              longest_v[verif_ncol - 1] = 2;
            };
            tmp_val_refv[verif_ncol - 1].push_back("NA");
          } else {
          
            if (longest_v[verif_ncol - 1] < cur_str.length()) {
              longest_v[verif_ncol - 1] = cur_str.length();
            };

            tmp_val_refv[verif_ncol - 1].push_back(cur_str);

            switch (dtype[verif_ncol - 1]) {
              case 's' : 
                      str_v.push_back(cur_str);
                      break;
              case 'c' : 
                      chr_v.push_back(cur_str[0]);
                      break;
              case 'b' : 
                      bool_v.push_back(std::stoi(cur_str));
                      break;
              case 'i' : 
                      int_v.push_back(std::stoi(cur_str));
                      break;
              case 'u' : 
                      uint_v.push_back(std::stoi(cur_str));
                      break;
              case 'd' : 
                      dbl_v.push_back(std::stoi(cur_str));
                      break;
              default:
                  std::cerr << "Unknown dtype: " << dtype[verif_ncol - 1] << "\n";
                  break;
            };

          };
          cur_str = "";
          if (verif_ncol != ncol) {
            std::cout << "column number problem at row: " << nrow << "\n";
            reinitiate();
            return;
          };
          nrow += 1;
          row_check += 1;
          if (row_check > end_row) {
            break;
          };
        };

      } else if constexpr (strt_row != 0) {

        unsigned int row_check = 0;
        while (row_check < strt_row) {
          getline(readfile, currow);
          row_check += 1;
        };

        while (getline(readfile, currow)) {
          verif_ncol = 1;
          str_cxt = 0;
          i = 0;
          while (i < currow.length()) {
            if (currow[i] == delim && !str_cxt) {
              if (i == 0) {
                if (longest_v[verif_ncol - 1] < 2) {
                  longest_v[verif_ncol - 1] = 2;
                };
                tmp_val_refv[0].push_back("NA");
              } else if (currow[i - 1] == delim) {
                if (longest_v[verif_ncol - 1] < 2) {
                  longest_v[verif_ncol - 1] = 2;
                };
                tmp_val_refv[verif_ncol - 1].push_back("NA");
              } else {
                
                if (longest_v[verif_ncol - 1] < cur_str.length()) {
                  longest_v[verif_ncol - 1] = cur_str.length();
                };

                tmp_val_refv[verif_ncol - 1].push_back(cur_str);

                switch (dtype[verif_ncol - 1]) {
                  case 's' : 
                          str_v.push_back(cur_str);
                          break;
                  case 'c' : 
                          chr_v.push_back(cur_str[0]);
                          break;
                  case 'b' : 
                          bool_v.push_back(std::stoi(cur_str));
                          break;
                  case 'i' : 
                          int_v.push_back(std::stoi(cur_str));
                          break;
                  case 'u' : 
                          uint_v.push_back(std::stoi(cur_str));
                          break;
                  case 'd' : 
                          dbl_v.push_back(std::stoi(cur_str));
                          break;
                  default:
                        std::cerr << "Unknown dtype: " << dtype[verif_ncol - 1] << "\n";
                        break;
                };

              };
              cur_str = "";
              verif_ncol += 1;
            } else if (currow[i] == str_context_begin) {
              str_cxt = 1;
            } else if (currow[i] == str_context_end) {
              str_cxt = 0;
            } else {
              cur_str.push_back(currow[i]);
            };
            i += 1;
          };
          if (currow[i - 1] == delim) {
            if (longest_v[verif_ncol - 1] < 2) {
              longest_v[verif_ncol - 1] = 2;
            };
            tmp_val_refv[verif_ncol - 1].push_back("NA");
          } else {
          
            if (longest_v[verif_ncol - 1] < cur_str.length()) {
              longest_v[verif_ncol - 1] = cur_str.length();
            };

            tmp_val_refv[verif_ncol - 1].push_back(cur_str);

            switch (dtype[verif_ncol - 1]) {
              case 's' : 
                      str_v.push_back(cur_str);
                      break;
              case 'c' : 
                      chr_v.push_back(cur_str[0]);
                      break;
              case 'b' : 
                      bool_v.push_back(std::stoi(cur_str));
                      break;
              case 'i' : 
                      int_v.push_back(std::stoi(cur_str));
                      break;
              case 'u' : 
                      uint_v.push_back(std::stoi(cur_str));
                      break;
              case 'd' : 
                      dbl_v.push_back(std::stoi(cur_str));
                      break;
              default:
                  std::cerr << "Unknown dtype: " << dtype[verif_ncol - 1] << "\n";
                  break;
            };

          };
          cur_str = "";
          if (verif_ncol != ncol) {
            std::cout << "column number problem at row: " << nrow << "\n";
            reinitiate();
            return;
          };
          nrow += 1;
        };

      } else if constexpr (end_row != 0) {

        unsigned int row_check = 0;

        while (getline(readfile, currow)) {
          verif_ncol = 1;
          str_cxt = 0;
          i = 0;
          while (i < currow.length()) {
            if (currow[i] == delim && !str_cxt) {
              if (i == 0) {
                if (longest_v[verif_ncol - 1] < 2) {
                  longest_v[verif_ncol - 1] = 2;
                };
                tmp_val_refv[0].push_back("NA");
              } else if (currow[i - 1] == delim) {
                if (longest_v[verif_ncol - 1] < 2) {
                  longest_v[verif_ncol - 1] = 2;
                };
                tmp_val_refv[verif_ncol - 1].push_back("NA");
              } else {
                
                if (longest_v[verif_ncol - 1] < cur_str.length()) {
                  longest_v[verif_ncol - 1] = cur_str.length();
                };

                tmp_val_refv[verif_ncol - 1].push_back(cur_str);

                switch (dtype[verif_ncol - 1]) {
                  case 's' : 
                          str_v.push_back(cur_str);
                          break;
                  case 'c' : 
                          chr_v.push_back(cur_str[0]);
                          break;
                  case 'b' : 
                          bool_v.push_back(std::stoi(cur_str));
                          break;
                  case 'i' : 
                          int_v.push_back(std::stoi(cur_str));
                          break;
                  case 'u' : 
                          uint_v.push_back(std::stoi(cur_str));
                          break;
                  case 'd' : 
                          dbl_v.push_back(std::stoi(cur_str));
                          break;
                  default:
                        std::cerr << "Unknown dtype: " << dtype[verif_ncol - 1] << "\n";
                        break;
                };

              };
              cur_str = "";
              verif_ncol += 1;
            } else if (currow[i] == str_context_begin) {
              str_cxt = 1;
            } else if (currow[i] == str_context_end) {
              str_cxt = 0;
            } else {
              cur_str.push_back(currow[i]);
            };
            i += 1;
          };
          if (currow[i - 1] == delim) {
            if (longest_v[verif_ncol - 1] < 2) {
              longest_v[verif_ncol - 1] = 2;
            };
            tmp_val_refv[verif_ncol - 1].push_back("NA");
          } else {
          
            if (longest_v[verif_ncol - 1] < cur_str.length()) {
              longest_v[verif_ncol - 1] = cur_str.length();
            };

            tmp_val_refv[verif_ncol - 1].push_back(cur_str);

            switch (dtype[verif_ncol - 1]) {
              case 's' : 
                      str_v.push_back(cur_str);
                      break;
              case 'c' : 
                      chr_v.push_back(cur_str[0]);
                      break;
              case 'b' : 
                      bool_v.push_back(std::stoi(cur_str));
                      break;
              case 'i' : 
                      int_v.push_back(std::stoi(cur_str));
                      break;
              case 'u' : 
                      uint_v.push_back(std::stoi(cur_str));
                      break;
              case 'd' : 
                      dbl_v.push_back(std::stoi(cur_str));
                      break;
              default:
                  std::cerr << "Unknown dtype: " << dtype[verif_ncol - 1] << "\n";
                  break;
            };

          };
          cur_str = "";
          if (verif_ncol != ncol) {
            std::cout << "column number problem at row: " << nrow << "\n";
            reinitiate();
            return;
          };
          nrow += 1;
          row_check += 1;
          if (row_check > end_row) {
            break;
          };
        };

      };
    };

    void type_classification() {
      unsigned int i;
      unsigned int i2;
      bool is_nb;
      bool is_flt_dbl;
      bool is_unsigned = 1;
      bool is_bool = 1;
      std::string cur_str;
      std::string cur_str2;
      for (i = 0; i < ncol; ++i) {
        i2 = 0;
        while (i2 < nrow) {
          cur_str = tmp_val_refv[i][i2];
          cur_str2 = cur_str;
          if (cur_str[0] == '-' & cur_str.length() > 1) {
            cur_str2.erase(cur_str2.begin());
          };
          is_nb = can_be_nb(cur_str2);
          if (!is_nb) {
            if (cur_str.length() > 1) {
              type_refv.push_back('s');
              matr_idx[0].push_back(i);
              break;
            };
          } else {
            is_flt_dbl = can_be_flt_dbl(cur_str2);
            if (is_flt_dbl) {
              type_refv.push_back('d');
              matr_idx[5].push_back(i);
              break;
            };
            if (is_unsigned) {
              if (cur_str[0] == '-') {
                is_unsigned = 0;
              };
            };
            if (is_bool) {
              if (cur_str != "0" & cur_str != "1") {
                is_bool = 0;
              };
            };
          };
          i2 += 1;
        };
        if (i2 == nrow) {
          if (!is_nb) {
            type_refv.push_back('c');
            matr_idx[1].push_back(i);
          } else if (is_bool) {
            type_refv.push_back('b');
            matr_idx[2].push_back(i);
          } else if (!is_unsigned) {
            type_refv.push_back('i');
            matr_idx[3].push_back(i);
          } else {
            type_refv.push_back('u');
            matr_idx[4].push_back(i);
          };
        };
      };
      for (i = 0; i < ncol; ++i) {
        if (type_refv[i] == 's') {
          for (i2 = 0; i2 < nrow; ++i2) {
            cur_str = tmp_val_refv[i][i2];
            str_v.push_back(cur_str);
          };
        } else if (type_refv[i] == 'c') {
          for (i2 = 0; i2 < nrow; ++i2) {
            cur_str = tmp_val_refv[i][i2];
            chr_v.push_back(cur_str[0]);
          };
        } else if (type_refv[i] == 'b') {
          for (i2 = 0; i2 < nrow; ++i2) {
            cur_str = tmp_val_refv[i][i2];
            bool_v.push_back(std::stoi(cur_str));
          };
        } else if (type_refv[i] == 'i') {
          for (i2 = 0; i2 < nrow; ++i2) {
            cur_str = tmp_val_refv[i][i2];
            int_v.push_back(std::stoi(cur_str));
          };
        } else if (type_refv[i] == 'u') {
          for (i2 = 0; i2 < nrow; ++i2) {
            cur_str = tmp_val_refv[i][i2];
            uint_v.push_back(std::stoi(cur_str));
          };
        } else {
          for (i2 = 0; i2 < nrow; ++i2) {
            cur_str = tmp_val_refv[i][i2];
            dbl_v.push_back(std::stoi(cur_str));
          };
        };
      };
    };

    void display_filter(std::vector<bool> &x, std::vector<int> &colv) {
      unsigned int i2b;
      unsigned int i3;
      unsigned int i4;

      if (colv[0] == -1) {
        colv.resize(ncol);
        for (i2b = 0; i2b < ncol; i2b += 1) {
          colv[i2b] = i2b;
        };
      };

      unsigned int max_nblngth = 0;
      if (name_v_row.size() == 0) {
        max_nblngth = std::to_string(nrow).length();
      } else {
        for (auto& el : name_v_row) {
          if (el.size() > max_nblngth) {
            max_nblngth = el.size();
          };
        };
      };

      for (i2b = 0; i2b < max_nblngth + 2; ++i2b) {
        std::cout << " ";
      };
      std::string cur_str;
      for (auto& i2 : colv) {
        if (type_refv[i2] == 's') {
          cur_str = "<str>";
          if (longest_v[i2] < 5) {
            longest_v[i2] = 5;
          };
        } else if (type_refv[i2] == 'c') {
          cur_str = "<char>";
          if (longest_v[i2] < 6) {
            longest_v[i2] = 6;
          };
        } else if (type_refv[i2] == 'b') {
          cur_str = "<bool>";
          if (longest_v[i2] < 6) {
            longest_v[i2] = 6;
          };
        } else if (type_refv[i2] == 'i') {
          cur_str = "<int>";
          if (longest_v[i2] < 5) {
            longest_v[i2] = 5;
          };
        } else if (type_refv[i2] == 'u') {
          cur_str = "<uint>";
          if (longest_v[i2] < 6) {
            longest_v[i2] = 6;
          };
        } else if (type_refv[i2] == 'd') {
          cur_str = "<double>";
          if (longest_v[i2] < 8) {
            longest_v[i2] = 8;
          };
        };
        std::cout << cur_str << " ";  
        for (i4 = cur_str.length(); i4 < longest_v[i2]; ++i4) {
          std::cout << " ";
        };
      };

      std::cout << "\n";
      for (i2b = 0; i2b < max_nblngth + 2; ++i2b) {
        std::cout << " ";
      };
      if (name_v.size() > 0) {
        for (auto& i2 : colv) {
          cur_str = name_v[i2];
          std::cout << cur_str << " ";  
          for (i4 = cur_str.length(); i4 < longest_v[i2]; ++i4) {
            std::cout << " ";
          };
        };
      } else {
        for (auto& i2 : colv) {
          cur_str = "[" + std::to_string(i2) + "]";
          std::cout << cur_str << " ";
          for (i4 = cur_str.length(); i4 < longest_v[i2]; ++i4) {
            std::cout << " ";
          };
        };
      };
      std::cout << "\n";
      if (name_v_row.size() == 0) {
        for (unsigned int i = 0; i < nrow; ++i) {
          if (x[i]) {
            std::cout << ":" << i << ": ";
            for (i3 = std::to_string(i).length(); i3 < max_nblngth; ++i3) {
              std::cout << " ";
            };
            for (auto& i2 : colv) {
              cur_str = tmp_val_refv[i2][i];
              std::cout << cur_str << " ";
              for (i3 = cur_str.length(); i3 < longest_v[i2]; ++i3) {
                std::cout << " ";
              };
            };
            std::cout << "\n";
          };
        };
      } else {
        for (unsigned int i = 0; i < nrow; ++i) {
          if (x[i]) {
            std::cout << std::setw(max_nblngth) << name_v_row[i] << " : ";
            for (auto& i2 : colv) {
              cur_str = tmp_val_refv[i2][i];
              std::cout << cur_str << " ";
              for (i3 = cur_str.length(); i3 < longest_v[i2]; ++i3) {
                std::cout << " ";
              };
            };
            std::cout << "\n";
          };
        };
      };
    };

    void display_filter_idx(std::vector<int> &x, std::vector<int> &colv) {
      unsigned int i2b;
      unsigned int i3;
      unsigned int i4;

      if (colv[0] == -1) {
        colv.resize(ncol);
        for (i2b = 0; i2b < ncol; i2b += 1) {
          colv[i2b] = i2b;
        };
      };

      if (x[0] == -1) {
        x.resize(ncol);
        for (i2b = 0; i2b < nrow; i2b += 1) {
          x[i2b] = i2b;
        };
      };

      unsigned int max_nblngth = 0;
      if (name_v_row.size() == 0) {
        max_nblngth = std::to_string(nrow).length();
      } else {
        for (auto& el : name_v_row) {
          if (el.size() > max_nblngth) {
            max_nblngth = el.size();
          };
        };
      };

      for (i2b = 0; i2b < max_nblngth + 2; ++i2b) {
        std::cout << " ";
      };
      std::string cur_str;
      for (auto& i2 : colv) {
        if (type_refv[i2] == 's') {
          cur_str = "<str>";
          if (longest_v[i2] < 5) {
            longest_v[i2] = 5;
          };
        } else if (type_refv[i2] == 'c') {
          cur_str = "<char>";
          if (longest_v[i2] < 6) {
            longest_v[i2] = 6;
          };
        } else if (type_refv[i2] == 'b') {
          cur_str = "<bool>";
          if (longest_v[i2] < 6) {
            longest_v[i2] = 6;
          };
        } else if (type_refv[i2] == 'i') {
          cur_str = "<int>";
          if (longest_v[i2] < 5) {
            longest_v[i2] = 5;
          };
        } else if (type_refv[i2] == 'u') {
          cur_str = "<uint>";
          if (longest_v[i2] < 6) {
            longest_v[i2] = 6;
          };
        } else if (type_refv[i2] == 'd') {
          cur_str = "<double>";
          if (longest_v[i2] < 8) {
            longest_v[i2] = 8;
          };
        };
        std::cout << cur_str << " ";  
        for (i4 = cur_str.length(); i4 < longest_v[i2]; ++i4) {
          std::cout << " ";
        };
      };

      std::cout << "\n";
      for (i2b = 0; i2b < max_nblngth + 2; ++i2b) {
        std::cout << " ";
      };
      if (name_v.size() > 0) {
        for (auto& i2 : colv) {
          cur_str = name_v[i2];
          std::cout << cur_str << " ";  
          for (i4 = cur_str.length(); i4 < longest_v[i2]; ++i4) {
            std::cout << " ";
          };
        };
      } else {
        for (auto& i2 : colv) {
          cur_str = "[" + std::to_string(i2) + "]";
          std::cout << cur_str << " ";
          for (i4 = cur_str.length(); i4 < longest_v[i2]; ++i4) {
            std::cout << " ";
          };
        };
      };
      std::cout << "\n";
      if (name_v_row.size() == 0) {
        i4 = 0;
        for (const auto& el : x) {
          std::cout << ":" << i4 << ": ";
          for (i3 = std::to_string(i4).length(); i3 < max_nblngth; ++i3) {
            std::cout << " ";
          };
          for (auto& i2 : colv) {
            cur_str = tmp_val_refv[i2][el];
            std::cout << cur_str << " ";
            for (i3 = cur_str.length(); i3 < longest_v[i2]; ++i3) {
              std::cout << " ";
            };
          };
          std::cout << "\n";
          i4 += 1;
        };
      } else {
        for (const auto& el : x) {
          std::cout << std::setw(max_nblngth) << name_v_row[el] << " : ";
          for (auto& i2 : colv) {
            cur_str = tmp_val_refv[i2][el];
            std::cout << cur_str << " ";
            for (i3 = cur_str.length(); i3 < longest_v[i2]; ++i3) {
              std::cout << " ";
            };
          };
          std::cout << "\n";
        };
      };
    };

    void display() {
      unsigned int i2;
      unsigned int i3;
      unsigned int i4;
      unsigned int max_nblngth = 0;
      if (name_v_row.size() == 0) {
        max_nblngth = std::to_string(nrow).length();
      } else {
        for (auto& el : name_v_row) {
          if (el.size() > max_nblngth) {
            max_nblngth = el.size();
          };
        };
      };
      for (i2 = 0; i2 < max_nblngth + 2; ++i2) {
        std::cout << " ";
      };
      std::string cur_str;
      for (i2 = 0; i2 < ncol; ++i2) {
        if (type_refv[i2] == 's') {
          cur_str = "<str>";
          if (longest_v[i2] < 5) {
            longest_v[i2] = 5;
          };
        } else if (type_refv[i2] == 'c') {
          cur_str = "<char>";
          if (longest_v[i2] < 6) {
            longest_v[i2] = 6;
          };
        } else if (type_refv[i2] == 'b') {
          cur_str = "<bool>";
          if (longest_v[i2] < 6) {
            longest_v[i2] = 6;
          };
        } else if (type_refv[i2] == 'i') {
          cur_str = "<int>";
          if (longest_v[i2] < 5) {
            longest_v[i2] = 5;
          };
        } else if (type_refv[i2] == 'u') {
          cur_str = "<uint>";
          if (longest_v[i2] < 6) {
            longest_v[i2] = 6;
          };
        } else if (type_refv[i2] == 'd') {
          cur_str = "<double>";
          if (longest_v[i2] < 8) {
            longest_v[i2] = 8;
          };
        };
        std::cout << cur_str << " ";  
        for (i4 = cur_str.length(); i4 < longest_v[i2]; ++i4) {
          std::cout << " ";
        };
      };
      std::cout << "\n";
      for (i2 = 0; i2 < max_nblngth + 2; ++i2) {
        std::cout << " ";
      };
      if (name_v.size() > 0) {
        for (i2 = 0; i2 < ncol; ++i2) {
          cur_str = name_v[i2];
          std::cout << cur_str << " ";  
          for (i4 = cur_str.length(); i4 < longest_v[i2]; ++i4) {
            std::cout << " ";
          };
        };
      } else {
        for (i2 = 0; i2 < ncol; ++i2) {
          cur_str = "[" + std::to_string(i2) + "]";
          std::cout << cur_str << " ";
          for (i4 = cur_str.length(); i4 < longest_v[i2]; ++i4) {
            std::cout << " ";
          };
        };
      };
      std::cout << "\n";
      if (name_v_row.size() == 0) {
        for (unsigned int i = 0; i < nrow; ++i) {
          std::cout << ":" << i << ": ";
          for (i3 = std::to_string(i).length(); i3 < max_nblngth; ++i3) {
            std::cout << " ";
          };
          for (i2 = 0; i2 < ncol; ++i2) {
            cur_str = tmp_val_refv[i2][i];
            std::cout << cur_str << " ";
            for (i3 = cur_str.length(); i3 < longest_v[i2]; ++i3) {
              std::cout << " ";
            };
          };
          std::cout << "\n";
        };
      } else {
        for (unsigned int i = 0; i < nrow; ++i) {
          std::cout << std::setw(max_nblngth) << name_v_row[i] << " : ";
          for (i2 = 0; i2 < ncol; ++i2) {
            cur_str = tmp_val_refv[i2][i];
            std::cout << cur_str << " ";
            for (i3 = cur_str.length(); i3 < longest_v[i2]; ++i3) {
              std::cout << " ";
            };
          };
          std::cout << "\n";
        };
      };
    };

    void reinitiate() {
     
      nrow = 0;
      ncol = 0;
 
      str_v = {};
      chr_v = {};
      bool_v = {};
      int_v = {};
      uint_v = {};
      dbl_v = {};
   
      pre_str_v = {};
      pre_chr_v = {};

      matr_idx = {{}, {}, {}, {}, {}, {}};
      name_v = {};
      name_v_row = {};
      longest_v = {};

      type_refv = {};
      tmp_val_refv = {};

    };

    #if __cplusplus >= 202002L 

    template <typename T>
    void fapply(void (&f)(T&), unsigned int &n) {
      unsigned int i = 2;
      unsigned int i2;
      bool is_found = 0;

      while (!is_found) {
        i2 = 0;
        while (i2 < matr_idx[i].size()) {
          if (n == matr_idx[i][i2]) {
            is_found = 1;
            break;
          };
          i2 += 1;
        };
        i += 1;
      };
      
      i -= 1;
      i2 = nrow * i2;
    
      unsigned int i3 = 0;

      if constexpr (std::is_same_v<T, bool>) {

        for (i = i2; i < (i2 + nrow); i += 1) {
          f(bool_v[i]);
          tmp_val_refv[n][i] = std::to_string(bool_v[i]);
        };
      } else if constexpr (std::is_same_v<T, int>) {

        for (i = i2; i < (i2 + nrow); i += 1) {
          f(int_v[i]);
          tmp_val_refv[n][i] = std::to_string(int_v[i]);
        };
      } else if constexpr (std::is_same_v<T, unsigned int>) {

        for (i = i2; i < (i2 + nrow); i += 1) {
          f(uint_v[i]);
          tmp_val_refv[n][i3] = std::to_string(uint_v[i]);
          i3 += 1;
        };
      } else if constexpr (std::is_same_v<T, double>) {
        for (i = i2; i < (i2 + nrow); i += 1) {
          f(dbl_v[i]);
          tmp_val_refv[n][i] = std::to_string(bool_v[i]);
        };
      } else if constexpr (std::is_same_v<T, char>) {
        for (i = i2; i < (i2 + nrow); i += 1) {
          f(chr_v[i]);
          tmp_val_refv[n][i] = std::string(1, chr_v[i]);
        };
      } else if constexpr (std::is_same_v<T, std::string>) {
        for (i = i2; i < (i2 + nrow); i += 1) {
          f(str_v[i]);
          tmp_val_refv[n][i] = str_v[i];
        };
      };
    };

    using ColumnView = std::variant<
        std::span<const int>,
        std::span<const unsigned int>,
        std::span<const double>
    >;
    
    ColumnView view_colnb(unsigned int &x) const {
        unsigned int i2 = 0;
    
        for (unsigned int i = 3; i <= 5; ++i) {
            for (i2 = 0; i2 < matr_idx[i].size(); ++i2) {
                if (x == matr_idx[i][i2]) {
                    const size_t offset = static_cast<size_t>(nrow) * i2;
    
                    switch (i) {
                        case 3:
                            return std::span<const int>(int_v.data() + offset, nrow);
                        case 4:
                            return std::span<const unsigned int>(uint_v.data() + offset, nrow);
                        case 5:
                            return std::span<const double>(dbl_v.data() + offset, nrow);
                    }
                }
            }
        }
    
        throw std::out_of_range("view_colnb(): column not found");
    }

    std::span<const std::string> view_colstr(unsigned int &x) const {
      unsigned int i2 = 0;

      while (i2 < matr_idx[0].size()) {

        if (x == matr_idx[0][i2]) {
          break;
        };

        i2 += 1;
      };
      i2 = nrow * i2;
    
      return std::span<const std::string>(str_v.data() + i2, nrow);
 
    };

    std::span<const char> view_colchr(unsigned int &x) const {
      unsigned int i2 = 0;

      while (i2 < matr_idx[1].size()) {

        if (x == matr_idx[1][i2]) {
          break;
        };

        i2 += 1;
      };
      i2 = nrow * i2;
    
      return std::span<const char>(chr_v.data() + i2, nrow);
 
    };

    std::span<const int> view_colint(unsigned int &x) const {
      unsigned int i2 = 0;

      while (i2 < matr_idx[3].size()) {

        if (x == matr_idx[3][i2]) {
          break;
        };

        i2 += 1;
      };
      i2 = nrow * i2;
    
      return std::span<const int>(int_v.data() + i2, nrow);
 
    };

    std::span<const unsigned int> view_coluint(unsigned int &x) const {
      unsigned int i2 = 0;

      while (i2 < matr_idx[4].size()) {

        if (x == matr_idx[4][i2]) {
          break;
        };

        i2 += 1;
      };
      i2 = nrow * i2;
    
      return std::span<const unsigned int>(uint_v.data() + i2, nrow);
 
    };

    std::span<const double> view_coldbl(unsigned int &x) const {
      unsigned int i2 = 0;

      while (i2 < matr_idx[5].size()) {

        if (x == matr_idx[5][i2]) {
          break;
        };

        i2 += 1;
      };
      i2 = nrow * i2;
    
      return std::span<const double>(dbl_v.data() + i2, nrow);
 
    };

    #endif

    template <typename T>
    void get_col_filter(unsigned int &x, 
                    std::vector<T> &rtn_v,
                    std::vector<bool> &mask) {
      rtn_v.reserve(nrow);
      unsigned int i;
      unsigned int i2 = 0;

      if constexpr (std::is_same_v<T, bool>) {

        while (i2 < matr_idx[2].size()) {
          if (x == matr_idx[2][i2]) {
            break;
          };
          i2 += 1;
        };

        if (i2 == matr_idx[2].size()) {
          std::cerr << "Error in (get_col), no column found\n";
          return;
        };

        i2 = nrow * i2;

        for (i = 0; i < nrow; ++i) {
          if (mask[i]) {
            rtn_v.push_back(bool_v[i2 + i]);
          };
        };

      } else if constexpr (std::is_same_v<T, int>) {

        while (i2 < matr_idx[3].size()) {
          if (x == matr_idx[3][i2]) {
            break;
          };
          i2 += 1;
        };

        if (i2 == matr_idx[3].size()) {
          std::cerr << "Error in (get_col), no column found\n";
          return;
        };

        i2 = nrow * i2;

        for (i = 0; i < nrow; ++i) {
          if (mask[i]) {
            rtn_v.push_back(int_v[i2 + i]);
          };
        };

      } else if constexpr (std::is_same_v<T, unsigned int>) {

        while (i2 < matr_idx[4].size()) {
          if (x == matr_idx[4][i2]) {
            break;
          };
          i2 += 1;
        };

        if (i2 == matr_idx[4].size()) {
          std::cerr << "Error in (get_col), no column found\n";
          return;
        };

        i2 = nrow * i2;

        for (i = 0; i < nrow; ++i) {
          if (mask[i]) {
            rtn_v.push_back(uint_v[i2 + i]);
          };
        };

      } else if constexpr (std::is_same_v<T, double>) {

        while (i2 < matr_idx[5].size()) {
          if (x == matr_idx[5][i2]) {
            break;
          };
          i2 += 1;
        };

        if (i2 == matr_idx[5].size()) {
          std::cerr << "Error in (get_col), no column found\n";
          return;
        };

        i2 = nrow * i2;

        for (i = 0; i < nrow; ++i) {
          if (mask[i]) {
            rtn_v.push_back(dbl_v[i2 + i]);
          };
        };

      } else if constexpr (std::is_same_v<T, std::string>) {

        while (i2 < matr_idx[0].size()) {
          if (x == matr_idx[0][i2]) {
            break;
          };
          i2 += 1;
        };

        if (i2 == matr_idx[0].size()) {
          std::cerr << "Error in (get_col), no column found\n";
          return;
        };

        i2 = nrow * i2;

        for (i = 0; i < nrow; ++i) {
          if (mask[i]) {
            rtn_v.push_back(str_v[i2 + i]);
          };
        };

      } else if constexpr (std::is_same_v<T, char>) {

        while (i2 < matr_idx[1].size()) {
          if (x == matr_idx[1][i2]) {
            break;
          };
          i2 += 1;
        };

        if (i2 == matr_idx[1].size()) {
          std::cerr << "Error in (get_col), no column found\n";
          return;
        };

        i2 = nrow * i2;

        for (i = 0; i < nrow; ++i) {
          if (mask[i]) {
            rtn_v.push_back(chr_v[i2 + i]);
          };
        };

      } else {
        std::cerr << "Error in (get_col), unsupported type\n";
        return;
      };

    };


    template <typename T>
    void get_col(unsigned int &x, 
                    std::vector<T> &rtn_v) {
      rtn_v.reserve(nrow);
      unsigned int i;
      unsigned int i2 = 0;

      if constexpr (std::is_same_v<T, bool>) {

        while (i2 < matr_idx[2].size()) {
          if (x == matr_idx[2][i2]) {
            break;
          };
          i2 += 1;
        };

        if (i2 == matr_idx[2].size()) {
          std::cerr << "Error in (get_col), no column found\n";
          return;
        };

        i2 = nrow * i2;

        for (i = 0; i < nrow; ++i) {
          rtn_v.push_back(bool_v[i2 + i]);
        };

      } else if constexpr (std::is_same_v<T, int>) {

        while (i2 < matr_idx[3].size()) {
          if (x == matr_idx[3][i2]) {
            break;
          };
          i2 += 1;
        };

        if (i2 == matr_idx[3].size()) {
          std::cerr << "Error in (get_col), no column found\n";
          return;
        };

        i2 = nrow * i2;

        for (i = 0; i < nrow; ++i) {
          rtn_v.push_back(int_v[i2 + i]);
        };

      } else if constexpr (std::is_same_v<T, unsigned int>) {

        while (i2 < matr_idx[4].size()) {
          if (x == matr_idx[4][i2]) {
            break;
          };
          i2 += 1;
        };

        if (i2 == matr_idx[4].size()) {
          std::cerr << "Error in (get_col), no column found\n";
          return;
        };

        i2 = nrow * i2;

        for (i = 0; i < nrow; ++i) {
          rtn_v.push_back(uint_v[i2 + i]);
        };

      } else if constexpr (std::is_same_v<T, double>) {

        while (i2 < matr_idx[5].size()) {
          if (x == matr_idx[5][i2]) {
            break;
          };
          i2 += 1;
        };

        if (i2 == matr_idx[5].size()) {
          std::cerr << "Error in (get_col), no column found\n";
          return;
        };

        i2 = nrow * i2;

        for (i = 0; i < nrow; ++i) {
          rtn_v.push_back(dbl_v[i2 + i]);
        };

      } else if constexpr (std::is_same_v<T, std::string>) {

        while (i2 < matr_idx[0].size()) {
          if (x == matr_idx[0][i2]) {
            break;
          };
          i2 += 1;
        };

        if (i2 == matr_idx[0].size()) {
          std::cerr << "Error in (get_col), no column found\n";
          return;
        };

        i2 = nrow * i2;

        for (i = 0; i < nrow; ++i) {
          rtn_v.push_back(str_v[i2 + i]);
        };

      } else if constexpr (std::is_same_v<T, char>) {

        while (i2 < matr_idx[1].size()) {
          if (x == matr_idx[1][i2]) {
            break;
          };
          i2 += 1;
        };

        if (i2 == matr_idx[1].size()) {
          std::cerr << "Error in (get_col), no column found\n";
          return;
        };

        i2 = nrow * i2;

        for (i = 0; i < nrow; ++i) {
          rtn_v.push_back(chr_v[i2 + i]);
        };

      } else {
        std::cerr << "Error in (get_col), unsupported type\n";
        return;
      };

    };

    const std::vector<std::vector<std::string>>& get_tmp_val_refv() const {
      return tmp_val_refv;
    };

    const unsigned int& get_nrow() const {
      return nrow;
    };

    const unsigned int& get_ncol() const {
      return ncol;
    };

    void get_dataframe(std::vector<int> &cols, Dataframe &cur_obj) {
      unsigned int i2;
      nrow = cur_obj.get_nrow();
      const unsigned int& max_ncol = cur_obj.get_ncol();
      ncol = cols.size();
      const auto& cur_tmp = cur_obj.get_tmp_val_refv();
      std::vector<std::string> cur_v = {};
      if (cols[0] == -1) {
        cols.pop_back();
        cols.reserve(max_ncol);
        for (i2 = 0; i2 < max_ncol; ++i2) {
          cols.push_back(i2);
        };
        ncol = max_ncol;
      };
      for (int& i : cols) {
        cur_v = {};
        for (i2 = 0; i2 < nrow; ++i2) {
          cur_v.push_back(cur_tmp[i][i2]);  
        };
        tmp_val_refv.push_back(cur_v);
      };
      type_classification();
      name_v = cur_obj.get_colname();
      name_v_row = cur_obj.get_rowname(); 
      longest_determine();
    };

    void get_dataframe_filter(std::vector<int> &cols, 
                    Dataframe &cur_obj,
                    std::vector<bool> &mask) {
      unsigned int i2;
      const unsigned int& max_ncol = cur_obj.get_ncol();
      ncol = cols.size();
      const auto& cur_tmp = cur_obj.get_tmp_val_refv();
      if (cols[0] == -1) {
        cols.pop_back();
        cols.reserve(max_ncol);
        for (i2 = 0; i2 < max_ncol; ++i2) {
          cols.push_back(i2);
        };
        ncol = max_ncol;
      };
      nrow = count(mask.begin(), mask.end(), true);
      std::vector<std::string> cur_v(nrow);
      tmp_val_refv.resize(cols.size(), cur_v);
      unsigned int i3;
      for (int& i : cols) {
        i3 = 0;
        for (i2 = 0; i2 < mask.size(); ++i2) {
          if (mask[i2]) {
            tmp_val_refv[i][i3] = cur_tmp[i][i2];
            i3 += 1;
          };
        };
      };
      type_classification();
      name_v = cur_obj.get_colname();
      name_v_row = cur_obj.get_rowname(); 
      longest_determine();
    };

    void get_dataframe_filter_idx(std::vector<int> &cols, 
                    Dataframe &cur_obj,
                    std::vector<int> &mask) {
      unsigned int i2;
      const unsigned int& max_ncol = cur_obj.get_ncol();
      const unsigned int& max_nrow = cur_obj.get_nrow();
      ncol = cols.size();
      const auto& cur_tmp = cur_obj.get_tmp_val_refv();
      if (mask[0] == -1) {
        mask.pop_back();
        mask.reserve(max_nrow);
        for (i2 = 0; i2 < max_nrow; i2 += 1) {
          mask.push_back(i2);
        };
      };
      nrow = mask.size();
      std::vector<std::string> cur_v(mask.size());
      if (cols[0] == -1) {
        cols.pop_back();
        cols.reserve(max_ncol);
        for (i2 = 0; i2 < max_ncol; ++i2) {
          cols.push_back(i2);
        };
        ncol = max_ncol;
      };
      tmp_val_refv.resize(cols.size(), cur_v);
      for (int& i : cols) {
        i2 = 0;
        for (const auto& el : mask) {
          tmp_val_refv[i][i2] = cur_tmp[i][el];
          i2 += 1;
        };
      };
      type_classification();
      name_v = cur_obj.get_colname();
      name_v_row = cur_obj.get_rowname(); 
      longest_determine();
    };

    void writef(std::string &file_name, char delim = ',', bool header_name = 1, char str_context_bgn = '\'', char str_context_end = '\'') {
      unsigned int i2;
      unsigned int i3;
      std::fstream outfile(file_name, std::ios::out);
      std::string cur_str;
      if (header_name) {
        i2 = 0;
        while (i2 + 1 < ncol) {
          outfile << name_v[i2];
          outfile << delim;
          i2 += 1;
        };
        outfile << name_v[i2];
        outfile << "\n";
      };
      for (unsigned int i = 0; i < nrow; ++i) {
        i2 = 0;
        while (i2 + 1 < ncol) {
          cur_str = tmp_val_refv[i2][i];
          if (type_refv[i2] == 's') {
            for (i3 = 0; i3 < cur_str.length(); ++i3) {
              if (cur_str[i3] == delim) {
                cur_str.insert(0, 1, str_context_bgn);
                cur_str.push_back(str_context_end);
                break;
              };
            };
          } else if (cur_str[0] == delim) {
            cur_str.insert(0, 1, str_context_bgn);
            cur_str.push_back(str_context_end);
          };
          outfile << cur_str;
          i2 += 1;
          outfile << delim;
        };
        cur_str = tmp_val_refv[i2][i];
        if (type_refv[i2] == 's') {
          for (i3 = 0; i3 < cur_str.length(); ++i3) {
            if (cur_str[i3] == delim) {
              cur_str.insert(0, 1, str_context_bgn);
              cur_str.push_back(str_context_end);
              break;
            };
          };
        } else if (cur_str[0] == delim) {
          cur_str.insert(0, 1, str_context_bgn);
          cur_str.push_back(str_context_end);
        };
        outfile << cur_str;
        outfile << "\n";
      };
    };

    template <typename T> void replace_col(std::vector<T> &x, unsigned int &colnb) {

      if (x.size() != nrow) {
        std::cerr << "Error: vector length (" << x.size()
                  << ") does not match nrow (" << nrow << ")\n";
        return;
      }

      unsigned int i = 2;
      unsigned int i2 = 0;
      if constexpr (std::is_same_v<T, bool>) {

        while (i2 < matr_idx[2].size()) {
          if (colnb == matr_idx[2][i2]) {
            break;
          };
          i2 += 1;
        };

        if (i2 == matr_idx[2].size()) {
            std::cerr << "Error: column " << colnb << " not found for this type in (replace_col)\n";
            return;
        }

        i2 = nrow * i2;

        for (i = 0; i < nrow; ++i) {
          bool_v[i2 + i] = x[i];
          tmp_val_refv[colnb][i] = std::to_string(x[i]);
        };
      } else if constexpr (std::is_same_v<T, int>) {

        while (i2 < matr_idx[3].size()) {
          if (colnb == matr_idx[3][i2]) {
            break;
          };
          i2 += 1;
        };
        
        if (i2 == matr_idx[3].size()) {
            std::cerr << "Error: column " << colnb << " not found for this type in (replace_col)\n";
            return;
        }

        i2 = nrow * i2;

        for (i = 0; i < nrow; ++i) {
          int_v[i2 + i] = x[i];
          tmp_val_refv[colnb][i] = std::to_string(x[i]);
        };
      } else if constexpr (std::is_same_v<T, unsigned int>) {

        while (i2 < matr_idx[4].size()) {
          if (colnb == matr_idx[4][i2]) {
            break;
          };
          i2 += 1;
        };
        
        if (i2 == matr_idx[4].size()) {
            std::cerr << "Error: column " << colnb << " not found for this type in (replace_col)\n";
            return;
        }

        i2 = nrow * i2;

        for (i = 0; i < nrow; ++i) {
          uint_v[i2 + i] = x[i];
          tmp_val_refv[colnb][i] = std::to_string(x[i]);
        };
      } else if constexpr (std::is_same_v<T, double>) {

        while (i2 < matr_idx[5].size()) {
          if (colnb == matr_idx[5][i2]) {
            break;
          };
          i2 += 1;
        };
        
        if (i2 == matr_idx[5].size()) {
            std::cerr << "Error: column " << colnb << " not found for this type in (replace_col)\n";
            return;
        }

        i2 = nrow * i2;

        for (i = 0; i < nrow; ++i) {
          dbl_v[i2 + i] = x[i];
          tmp_val_refv[colnb][i] = std::to_string(x[i]);
        };
      } else if constexpr (std::is_same_v<T, std::string>) {

        while (i2 < matr_idx[0].size()) {
          if (colnb == matr_idx[0][i2]) {
            break;
          };
          i2 += 1;
        };
       
        if (i2 == matr_idx[0].size()) {
            std::cerr << "Error: column " << colnb << " not found for std::string in (replace_col)\n";
            return;
        }

        i2 = nrow * i2;

        for (i = 0; i < nrow; ++i) {
          str_v[i2 + i] = x[i];
          tmp_val_refv[colnb][i] = x[i];
        };

      } else if constexpr (std::is_same_v<T, char>) {

        while (i2 < matr_idx[1].size()) {
          if (colnb == matr_idx[1][i2]) {
            break;
          };
          i2 += 1;
        }; 

        if (i2 == matr_idx[1].size()) {
            std::cerr << "Error: column " << colnb << " not found for this type in (replace_col)\n";
            return;
        }

        i2 = nrow * i2;

        for (i = 0; i < nrow; ++i) {
          chr_v[i2 + i] = x[i];
          tmp_val_refv[colnb][i] = std::string(1, x[i]);
        };

      } else {
        std::cerr << "Error unsupported type in (replace_col)\n";
      };
    };

    template <typename T> void add_col(std::vector<T> &x, std::string name = "NA") {
      if (x.size() != nrow) {
        std::cerr << "Error: vector length (" << x.size()
                  << ") does not match nrow (" << nrow << ")\n";
        return;
      };
      name_v.push_back(name);
      std::vector<std::string> cur_v = {};
      cur_v.reserve(nrow);
      if constexpr (std::is_same_v<T, bool>) {
        matr_idx[2].push_back(ncol);
        type_refv.push_back('b');
        for (auto &i : x) {
          bool_v.push_back(i);
          cur_v.push_back(std::to_string(i));
        };
      } else if constexpr (std::is_same_v<T, int>) {
        matr_idx[3].push_back(ncol);
        type_refv.push_back('i');
        for (auto &i : x) {
          int_v.push_back(i);
          cur_v.push_back(std::to_string(i));
        };
      } else if constexpr (std::is_same_v<T, unsigned int>) {
        matr_idx[4].push_back(ncol);
        type_refv.push_back('u');
        for (auto &i : x) {
          uint_v.push_back(i);
          cur_v.push_back(std::to_string(i));
        };
      } else if constexpr (std::is_same_v<T, double>) {
        matr_idx[5].push_back(ncol);
        type_refv.push_back('d');
        for (auto &i : x) {
          dbl_v.push_back(i);
          cur_v.push_back(std::to_string(i));
        }; 
      } else if constexpr (std::is_same_v<T, char>) {
        matr_idx[1].push_back(ncol);
        type_refv.push_back('c');
        for (auto &i : x) {
          chr_v.push_back(i);
          cur_v.push_back(std::string(1, i));
        }; 
      } else if constexpr (std::is_same_v<T, std::string>) {
        matr_idx[0].push_back(ncol);
        type_refv.push_back('s');
        for (auto &i : x) {
          str_v.push_back(i);
          cur_v.push_back(i);
        }; 
      } else {
        std::cerr << "Error in (add_col) type not suported \n";
      };
      tmp_val_refv.push_back(cur_v);
      ncol += 1;
    };
    
    void rm_col(std::vector<unsigned int> &nbcolv) {
      unsigned int i;
      unsigned int i2;
      bool is_found;
      for (int nbcol : nbcolv) {
        if (nbcol >= ncol) {
          std::cout << "The column does not exist\n";
          return;
        };
        i = 0;
        is_found = 0;
        while (!is_found) {
          i2 = 0;
          while (i2 < matr_idx[i].size()) {
            if (nbcol == matr_idx[i][i2]) {
              is_found = 1;
              break;
            };
            i2 += 1;
          };
          i += 1;
        };
        i-= 1;
        name_v.erase(name_v.begin() + nbcol);
        matr_idx[i].erase(matr_idx[i].begin() + i2);
        tmp_val_refv.erase(tmp_val_refv.begin() + nbcol);
        type_refv.erase(type_refv.begin() + nbcol);
        i2 = nrow * i2;
        if (i == 0) {
          str_v.erase(str_v.begin() + i2, str_v.begin() + i2 + nrow);
        } else if (i == 1) {
          chr_v.erase(chr_v.begin() + i2, chr_v.begin() + i2 + nrow);
        } else if (i == 2) {
          bool_v.erase(bool_v.begin() + i2, bool_v.begin() + i2 + nrow);
        } else if (i == 3) {
          int_v.erase(int_v.begin() + i2, int_v.begin() + i2 + nrow);
        } else if (i == 4) {
          uint_v.erase(uint_v.begin() + i2, uint_v.begin() + i2 + nrow);
        } else if (i == 5) {
          dbl_v.erase(dbl_v.begin() + i2, dbl_v.begin() + i2 + nrow);
        };
        ncol -= 1;
      };
    };

    void rm_row(std::vector<unsigned int> &x) {
      unsigned int i;
      unsigned int cnt = 0;
      std::vector<unsigned int> alrd_v = {0, 0, 0, 0, 0, 0};
      for (unsigned int i2 = nrow - 1; i2 > 0; --i2) {
        if (i2 == x[cnt]) {
          for (i = 0; i < ncol; ++i) {
            tmp_val_refv[i].erase(tmp_val_refv[i].begin() + i2);
            if (type_refv[i] == 's') {
              str_v.erase(str_v.begin() + alrd_v[0] * nrow + i2);
              alrd_v[0] += 1;
            } else if (type_refv[i] == 'c') {
              chr_v.erase(chr_v.begin() + alrd_v[1] * nrow + i2);
              alrd_v[1] += 1;
            } else if (type_refv[i] == 'b') {
              bool_v.erase(bool_v.begin() + alrd_v[2] * nrow + i2);
              alrd_v[2] += 1;
            } else if (type_refv[i] == 'i') {
              int_v.erase(int_v.begin() + alrd_v[3] * nrow + i2);
              alrd_v[3] += 1;
            } else if (type_refv[i] == 'u') {
              uint_v.erase(uint_v.begin() + alrd_v[4] * nrow + i2);
              alrd_v[4] += 1;
            } else if (type_refv[i] == 'd') {
              dbl_v.erase(dbl_v.begin() + alrd_v[5] * nrow + i2);
              alrd_v[5] += 1;
            };
          };
          nrow -= 1;
          cnt += 1;
        };
      };
    };

    void transform_inner(Dataframe &cur_obj, unsigned int &in_col, unsigned int &ext_col) {
      unsigned int i2;
      const auto& cur_tmp = cur_obj.get_tmp_val_refv();
      const std::vector<std::string>& ext_colv = cur_tmp[ext_col];
      const std::vector<std::string>& in_colv = tmp_val_refv[in_col];
      std::string cur_val;
      unsigned int nrow2 = nrow;
      unsigned int pos_colv;
      nrow = 0;
      const unsigned int& ext_nrow = cur_obj.get_nrow();

      std::unordered_set<std::string> lookup;
      lookup.reserve(ext_nrow);
      for (unsigned int j = 0; j < ext_nrow; ++j)
        lookup.insert(ext_colv[j]);

      for (int i = 0; i < nrow2; ++i) {
        if (lookup.contains(in_colv[i])) {
          for (i2 = 0; i2 < matr_idx[0].size(); i2 += 1) {
            pos_colv = matr_idx[0][i2];
            str_v[nrow2 * i2 + nrow] = str_v[nrow2 * i2 + i];
            tmp_val_refv[pos_colv][nrow] = tmp_val_refv[pos_colv][i];
          };
          for (i2 = 0; i2 < matr_idx[1].size(); i2 += 1) {
            pos_colv = matr_idx[1][i2];
            chr_v[nrow2 * i2 + nrow] = chr_v[nrow2 * i2 + i];
            tmp_val_refv[pos_colv][nrow] = tmp_val_refv[pos_colv][i];
          };
          for (i2 = 0; i2 < matr_idx[2].size(); i2 += 1) {
            pos_colv = matr_idx[2][i2];
            bool_v[nrow2 * i2 + nrow] = bool_v[nrow2 * i2 + i];
            tmp_val_refv[pos_colv][nrow] = tmp_val_refv[pos_colv][i];
          };
          for (i2 = 0; i2 < matr_idx[3].size(); i2 += 1) {
            pos_colv = matr_idx[3][i2];
            int_v[nrow2 * i2 + nrow] = int_v[nrow2 * i2 + i];
            tmp_val_refv[pos_colv][nrow] = tmp_val_refv[pos_colv][i];
          };
          for (i2 = 0; i2 < matr_idx[4].size(); i2 += 1) {
            pos_colv = matr_idx[4][i2];
            uint_v[nrow2 * i2 + nrow] = uint_v[nrow2 * i2 + i];
            tmp_val_refv[pos_colv][nrow] = tmp_val_refv[pos_colv][i];
          };
          for (i2 = 0; i2 < matr_idx[5].size(); i2 += 1) {
            pos_colv = matr_idx[5][i2];
            dbl_v[nrow2 * i2 + nrow] = dbl_v[nrow2 * i2 + i];
            tmp_val_refv[pos_colv][nrow] = tmp_val_refv[pos_colv][i];
          };
          nrow += 1;
        };
      };
    };

    void transform_inner_clean(Dataframe &cur_obj, unsigned int &in_col, unsigned int &ext_col) {
      unsigned int i2;
      const auto& cur_tmp = cur_obj.get_tmp_val_refv();
      const std::vector<std::string>& ext_colv = cur_tmp[ext_col];
      const std::vector<std::string>& in_colv = tmp_val_refv[in_col];
      std::string cur_val;
      unsigned int nrow2 = nrow;
      unsigned int pos_colv;
      nrow = 0;
      const unsigned int& ext_nrow = cur_obj.get_nrow();

      std::unordered_set<std::string> lookup;
      lookup.reserve(ext_nrow);
      for (unsigned int j = 0; j < ext_nrow; ++j)
        lookup.insert(ext_colv[j]);

      for (int i = 0; i < nrow2; ++i) {
        if (lookup.contains(in_colv[i])) {
          for (i2 = 0; i2 < matr_idx[0].size(); i2 += 1) {
            pos_colv = matr_idx[0][i2];
            str_v[nrow2 * i2 + nrow] = str_v[nrow2 * i2 + i];
            tmp_val_refv[pos_colv][nrow] = tmp_val_refv[pos_colv][i];
          };
          for (i2 = 0; i2 < matr_idx[1].size(); i2 += 1) {
            pos_colv = matr_idx[1][i2];
            chr_v[nrow2 * i2 + nrow] = chr_v[nrow2 * i2 + i];
            tmp_val_refv[pos_colv][nrow] = tmp_val_refv[pos_colv][i];
          };
          for (i2 = 0; i2 < matr_idx[2].size(); i2 += 1) {
            pos_colv = matr_idx[2][i2];
            bool_v[nrow2 * i2 + nrow] = bool_v[nrow2 * i2 + i];
            tmp_val_refv[pos_colv][nrow] = tmp_val_refv[pos_colv][i];
          };
          for (i2 = 0; i2 < matr_idx[3].size(); i2 += 1) {
            pos_colv = matr_idx[3][i2];
            int_v[nrow2 * i2 + nrow] = int_v[nrow2 * i2 + i];
            tmp_val_refv[pos_colv][nrow] = tmp_val_refv[pos_colv][i];
          };
          for (i2 = 0; i2 < matr_idx[4].size(); i2 += 1) {
            pos_colv = matr_idx[4][i2];
            uint_v[nrow2 * i2 + nrow] = uint_v[nrow2 * i2 + i];
            tmp_val_refv[pos_colv][nrow] = tmp_val_refv[pos_colv][i];
          };
          for (i2 = 0; i2 < matr_idx[5].size(); i2 += 1) {
            pos_colv = matr_idx[5][i2];
            dbl_v[nrow2 * i2 + nrow] = dbl_v[nrow2 * i2 + i];
            tmp_val_refv[pos_colv][nrow] = tmp_val_refv[pos_colv][i];
          };
          nrow += 1;
        };
      };
      unsigned int delta_col = nrow2 - nrow;
      unsigned int pos_colv2;
      for (i2 = 0; i2 < matr_idx[0].size(); i2 += 1) {
        pos_colv = matr_idx[0][i2];
        pos_colv2 = (nrow + 1) * i2;
        str_v.erase(str_v.begin() + pos_colv2, 
                        str_v.begin() + pos_colv2 + delta_col);
        tmp_val_refv[pos_colv].erase(tmp_val_refv[pos_colv].begin() + nrow, 
                        tmp_val_refv[pos_colv].end());
        tmp_val_refv[pos_colv].shrink_to_fit();
      };
      str_v.shrink_to_fit();
      for (i2 = 0; i2 < matr_idx[1].size(); i2 += 1) {
        pos_colv = matr_idx[1][i2];
        pos_colv2 = (nrow + 1) * i2;
        chr_v.erase(chr_v.begin() + pos_colv2, 
                        chr_v.begin() + pos_colv2 + delta_col);
        tmp_val_refv[pos_colv].erase(tmp_val_refv[pos_colv].begin() + nrow, 
                        tmp_val_refv[pos_colv].end());
        tmp_val_refv[pos_colv].shrink_to_fit();
      };
      chr_v.shrink_to_fit();
      for (i2 = 0; i2 < matr_idx[2].size(); i2 += 1) {
        pos_colv = matr_idx[2][i2];
        pos_colv2 = (nrow + 1) * i2;
        bool_v.erase(bool_v.begin() + pos_colv2, 
                        bool_v.begin() + pos_colv2 + delta_col);
        tmp_val_refv[pos_colv].erase(tmp_val_refv[pos_colv].begin() + nrow, 
                        tmp_val_refv[pos_colv].end());
        tmp_val_refv[pos_colv].shrink_to_fit();
      };
      bool_v.shrink_to_fit();
      for (i2 = 0; i2 < matr_idx[3].size(); i2 += 1) {
        pos_colv = matr_idx[3][i2];
        pos_colv2 = (nrow + 1) * i2;
        int_v.erase(int_v.begin() + pos_colv2, 
                        int_v.begin() + pos_colv2 + delta_col);
        tmp_val_refv[pos_colv].erase(tmp_val_refv[pos_colv].begin() + nrow, 
                        tmp_val_refv[pos_colv].end());
        tmp_val_refv[pos_colv].shrink_to_fit();
      };
      int_v.shrink_to_fit();
      for (i2 = 0; i2 < matr_idx[4].size(); i2 += 1) {
        pos_colv = matr_idx[4][i2];
        pos_colv2 = (nrow + 1) * i2;
        uint_v.erase(uint_v.begin() + pos_colv2, 
                        uint_v.begin() + pos_colv2 + delta_col);
        tmp_val_refv[pos_colv].erase(tmp_val_refv[pos_colv].begin() + nrow, 
                        tmp_val_refv[pos_colv].end());
        tmp_val_refv[pos_colv].shrink_to_fit();
      };
      uint_v.shrink_to_fit();
      for (i2 = 0; i2 < matr_idx[5].size(); i2 += 1) {
        pos_colv = matr_idx[5][i2];
        pos_colv2 = (nrow + 1) * i2;
        dbl_v.erase(dbl_v.begin() + pos_colv2, 
                        dbl_v.begin() + pos_colv2 + delta_col);
        tmp_val_refv[pos_colv].erase(tmp_val_refv[pos_colv].begin() + nrow, 
                        tmp_val_refv[pos_colv].end());
        tmp_val_refv[pos_colv].shrink_to_fit();
      };
      dbl_v.shrink_to_fit();
    };

    void transform_excluding(Dataframe &cur_obj, unsigned int &in_col, unsigned int &ext_col) {
      unsigned int i2;
      unsigned int nrow2 = nrow;
      nrow = 0;
      std::vector<std::vector<std::string>> cur_tmp = cur_obj.get_tmp_val_refv();
      const std::vector<std::string>& ext_colv = cur_tmp[ext_col];
      const std::vector<std::string>& in_colv = tmp_val_refv[in_col];
      std::string cur_val;
      unsigned int pos_vl;
      const unsigned int& ext_nrow = cur_obj.get_nrow();

      std::unordered_set<std::string> lookup;
      lookup.reserve(ext_nrow);
      for (int j = 0; j < ext_nrow; j += 1) {
        lookup.insert(ext_colv[j]);
      };

      for (int i = 0; i < nrow2; i += 1) {
        if (!(lookup.contains(in_colv[i]))) {
          for (i2 = 0; i2 < matr_idx[0].size(); i2 += 1) {
            pos_vl = matr_idx[0][i2];
            str_v[i2 * nrow2 + nrow] = str_v[i2 * nrow2 + i];
            tmp_val_refv[pos_vl][nrow] = tmp_val_refv[pos_vl][i];
          };
          for (i2 = 0; i2 < matr_idx[1].size(); i2 += 1) {
            pos_vl = matr_idx[1][i2];
            chr_v[i2 * nrow2 + nrow] = chr_v[i2 * nrow2 + i];
            tmp_val_refv[pos_vl][nrow] = tmp_val_refv[pos_vl][i];
          };
          for (i2 = 0; i2 < matr_idx[2].size(); i2 += 1) {
            pos_vl = matr_idx[2][i2];
            bool_v[i2 * nrow2 + nrow] = bool_v[i2 * nrow2 + i];
            tmp_val_refv[pos_vl][nrow] = tmp_val_refv[pos_vl][i];
          };
          for (i2 = 0; i2 < matr_idx[3].size(); i2 += 1) {
            pos_vl = matr_idx[3][i2];
            int_v[i2 * nrow2 + nrow] = int_v[i2 * nrow2 + i];
            tmp_val_refv[pos_vl][nrow] = tmp_val_refv[pos_vl][i];
          };
          for (i2 = 0; i2 < matr_idx[4].size(); i2 += 1) {
            pos_vl = matr_idx[4][i2];
            uint_v[i2 * nrow2 + nrow] = uint_v[i2 * nrow2 + i];
            tmp_val_refv[pos_vl][nrow] = tmp_val_refv[pos_vl][i];
          };
          for (i2 = 0; i2 < matr_idx[5].size(); i2 += 1) {
            pos_vl = matr_idx[5][i2];
            dbl_v[i2 * nrow2 + nrow] = dbl_v[i2 * nrow2 + i];
            tmp_val_refv[pos_vl][nrow] = tmp_val_refv[pos_vl][i];
          };

          nrow += 1;
        };
      };
    };

    void transform_excluding_clean(Dataframe &cur_obj, unsigned int &in_col, unsigned int &ext_col) {
      unsigned int i2;
      unsigned int nrow2 = nrow;
      nrow = 0;
      std::vector<std::vector<std::string>> cur_tmp = cur_obj.get_tmp_val_refv();
      const std::vector<std::string>& ext_colv = cur_tmp[ext_col];
      const std::vector<std::string>& in_colv = tmp_val_refv[in_col];
      std::string cur_val;
      unsigned int pos_vl;
      const unsigned int& ext_nrow = cur_obj.get_nrow();

      std::unordered_set<std::string> lookup;
      lookup.reserve(ext_nrow);
      for (auto &j : ext_colv) {
        lookup.insert(j);
      };

      for (int i = 0; i < nrow2; i += 1) {
        if (!(lookup.contains(in_colv[i]))) {
          for (i2 = 0; i2 < matr_idx[0].size(); i2 += 1) {
            pos_vl = matr_idx[0][i2];
            str_v[i2 * nrow2 + nrow] = str_v[i2 * nrow2 + i];
            tmp_val_refv[pos_vl][nrow] = tmp_val_refv[pos_vl][i];
          };
          for (i2 = 0; i2 < matr_idx[1].size(); i2 += 1) {
            pos_vl = matr_idx[1][i2];
            chr_v[i2 * nrow2 + nrow] = chr_v[i2 * nrow2 + i];
            tmp_val_refv[pos_vl][nrow] = tmp_val_refv[pos_vl][i];
          };
          for (i2 = 0; i2 < matr_idx[2].size(); i2 += 1) {
            pos_vl = matr_idx[2][i2];
            bool_v[i2 * nrow2 + nrow] = bool_v[i2 * nrow2 + i];
            tmp_val_refv[pos_vl][nrow] = tmp_val_refv[pos_vl][i];
          };
          for (i2 = 0; i2 < matr_idx[3].size(); i2 += 1) {
            pos_vl = matr_idx[3][i2];
            int_v[i2 * nrow2 + nrow] = int_v[i2 * nrow2 + i];
            tmp_val_refv[pos_vl][nrow] = tmp_val_refv[pos_vl][i];
          };
          for (i2 = 0; i2 < matr_idx[4].size(); i2 += 1) {
            pos_vl = matr_idx[4][i2];
            uint_v[i2 * nrow2 + nrow] = uint_v[i2 * nrow2 + i];
            tmp_val_refv[pos_vl][nrow] = tmp_val_refv[pos_vl][i];
          };
          for (i2 = 0; i2 < matr_idx[5].size(); i2 += 1) {
            pos_vl = matr_idx[5][i2];
            dbl_v[i2 * nrow2 + nrow] = dbl_v[i2 * nrow2 + i];
            tmp_val_refv[pos_vl][nrow] = tmp_val_refv[pos_vl][i];
          };

          nrow += 1;
        };
      };

      unsigned delta_col = nrow2 - nrow;
      unsigned int pos_vl2;
      for (i2 = 0; i2 < matr_idx[0].size(); i2 += 1) {
        pos_vl = matr_idx[0][i2];
        pos_vl2 = (nrow + 1) * i2;
        str_v.erase(str_v.begin() + pos_vl2, 
                        str_v.begin() + pos_vl2 + delta_col);
        tmp_val_refv[pos_vl].erase(tmp_val_refv[pos_vl].begin() + nrow, 
                        tmp_val_refv[pos_vl].end());
        tmp_val_refv[pos_vl].shrink_to_fit();
      };
      str_v.shrink_to_fit();
      for (i2 = 0; i2 < matr_idx[1].size(); i2 += 1) {
        pos_vl = matr_idx[1][i2];
        pos_vl2 = (nrow + 1) * i2;
        chr_v.erase(chr_v.begin() + pos_vl2, 
                        chr_v.begin() + pos_vl2 + delta_col);
        tmp_val_refv[pos_vl].erase(tmp_val_refv[pos_vl].begin() + nrow, 
                        tmp_val_refv[pos_vl].end());
        tmp_val_refv[pos_vl].shrink_to_fit();
      };
      chr_v.shrink_to_fit();
      for (i2 = 0; i2 < matr_idx[2].size(); i2 += 1) {
        pos_vl = matr_idx[2][i2];
        pos_vl2 = (nrow + 1) * i2;
        bool_v.erase(bool_v.begin() + pos_vl2, 
                        bool_v.begin() + pos_vl2 + delta_col);
        tmp_val_refv[pos_vl].erase(tmp_val_refv[pos_vl].begin() + nrow, 
                        tmp_val_refv[pos_vl].end());
        tmp_val_refv[pos_vl].shrink_to_fit();
      };
      bool_v.shrink_to_fit();
      for (i2 = 0; i2 < matr_idx[3].size(); i2 += 1) {
        pos_vl = matr_idx[3][i2];
        pos_vl2 = (nrow + 1) * i2;
        int_v.erase(int_v.begin() + pos_vl2, 
                        int_v.begin() + pos_vl2 + delta_col);
        tmp_val_refv[pos_vl].erase(tmp_val_refv[pos_vl].begin() + nrow, 
                        tmp_val_refv[pos_vl].end());
        tmp_val_refv[pos_vl].shrink_to_fit();
      };
      int_v.shrink_to_fit();
      for (i2 = 0; i2 < matr_idx[4].size(); i2 += 1) {
        pos_vl = matr_idx[4][i2];
        pos_vl2 = (nrow + 1) * i2;
        uint_v.erase(uint_v.begin() + pos_vl2, 
                        uint_v.begin() + pos_vl2 + delta_col);
        tmp_val_refv[pos_vl].erase(tmp_val_refv[pos_vl].begin() + nrow, 
                        tmp_val_refv[pos_vl].end());
        tmp_val_refv[pos_vl].shrink_to_fit();
      };
      uint_v.shrink_to_fit();
      for (i2 = 0; i2 < matr_idx[5].size(); i2 += 1) {
        pos_vl = matr_idx[5][i2];
        pos_vl2 = (nrow + 1) * i2;
        dbl_v.erase(dbl_v.begin() + pos_vl2, 
                        dbl_v.begin() + pos_vl2 + delta_col);
        tmp_val_refv[pos_vl].erase(tmp_val_refv[pos_vl].begin() + nrow, 
                        tmp_val_refv[pos_vl].end());
        tmp_val_refv[pos_vl].shrink_to_fit();
      };
      dbl_v.shrink_to_fit();

    };

    void merge_inner(Dataframe &obj1, Dataframe &obj2, bool colname, unsigned int &key1, unsigned int &key2) {
      const unsigned int& ncol1 = obj1.get_ncol();
      const unsigned int& ncol2 = obj2.get_ncol();
      std::vector<std::string> cur_vstr;
      ncol = ncol1 + ncol2;
      unsigned int i;
      unsigned int i2;
      unsigned int i3;
      const std::vector<std::string>& name1 = obj1.get_colname();
      const std::vector<std::string>& name2 = obj2.get_colname();
      if (colname) {
        name_v.resize(ncol);
        if (name1.size() > 0) {
          for (i = 0; i < name1.size(); ++i) {
            name_v.push_back(name1[i]);
          };
        };
        if (name2.size() > 0) {
          for (i = 0; i < name2.size(); ++i) {
            name_v.push_back(name2[i]);
          };
        };
      };
      tmp_val_refv.reserve(ncol);
      for (i = 0; i < ncol; ++i) {
        tmp_val_refv.push_back(cur_vstr);
      };
      const std::vector<char>& type1 = obj1.get_typecol();
      const std::vector<char>& type2 = obj2.get_typecol();
      type_refv.reserve(ncol);
      for (i = 0; i < ncol1; ++i) {
        type_refv.push_back(type1[i]);
      };
      for (i = 0; i < ncol2; ++i) {
        type_refv.push_back(type2[i]);
      };
      const auto& tmp1 = obj1.get_tmp_val_refv();
      const auto& tmp2 = obj2.get_tmp_val_refv();
      const std::vector<std::string>& col1 = tmp1[key1];
      const std::vector<std::string>& col2 = tmp2[key2];
      std::unordered_multimap<std::string, size_t> b_index;
      for (size_t j = 0; j < col2.size(); ++j) {
        b_index.insert({col2[j], j});
      };
      for (size_t i = 0; i < col1.size(); ++i) {
        auto range = b_index.equal_range(col1[i]);
        for (auto it = range.first; it != range.second; ++it) {
          nrow += 1;
          size_t idx = it->second;
          for (i2 = 0; i2 < ncol1; i2 += 1) {
            tmp_val_refv[i2].push_back(tmp1[i2][i]);
          };
          for (i2 = 0; i2 < ncol2; i2 += 1) {
            tmp_val_refv[ncol1 + i2].push_back(tmp2[i2][idx]);
          };
        };
      };
      type_classification();
      longest_determine();
    };

    void transform_merge_inner2(Dataframe &obj, 
                    unsigned int &key1, 
                    unsigned int &key2) {
      const unsigned int& ncol2 = obj.get_ncol();
      std::vector<std::string> cur_vstr(nrow);
      unsigned int nrow2 = nrow;
      const unsigned int& nrowb = obj.get_nrow();
      nrow = 0;
      unsigned int i;
      unsigned int i2;
      unsigned int i3;
      const std::vector<std::string>& name2 = obj.get_colname();
      if (name_v.size() > 0) {
        name_v.insert(name_v.end(), name2.begin(), name2.end()); 
      };
      tmp_val_refv.reserve(ncol);
      for (i = 0; i < ncol2; ++i) {
        tmp_val_refv.push_back(cur_vstr);
      };
      const std::vector<std::vector<unsigned int>>& matr_idx2 = obj.get_matr_idx();
      const std::vector<char>& type2 = obj.get_typecol();
      type_refv.insert(type_refv.end(), type2.begin(), type2.end());
      const auto& tmp2 = obj.get_tmp_val_refv();
      const std::vector<std::string>& col1 = tmp_val_refv[key1];
      const std::vector<std::string>& col2 = tmp2[key2];
      
      std::unordered_multimap<std::string, size_t> b_index;
      for (size_t j = 0; j < col2.size(); ++j) {
        b_index.insert({col2[j], j});
      };

      std::vector<std::string> str_v2 = obj.get_str_vec();
      std::vector<char> chr_v2 = obj.get_chr_vec();
      std::vector<bool> bool_v2 = obj.get_bool_vec();
      std::vector<int> int_v2 = obj.get_int_vec();
      std::vector<unsigned int> uint_v2 = obj.get_uint_vec();
      std::vector<double> dbl_v2 = obj.get_dbl_vec();

      std::vector<std::string> tmp_str_v(nrow2);
      std::vector<char> tmp_chr_v(nrow2);
      std::vector<bool> tmp_bool_v(nrow2);
      std::vector<int> tmp_int_v(nrow2);
      std::vector<unsigned int> tmp_uint_v(nrow2);
      std::vector<double> tmp_dbl_v(nrow2);

      unsigned int pos_val;

      unsigned int pre_str_val = str_v.size() / nrow2;
      unsigned int pre_chr_val = chr_v.size() / nrow2;
      unsigned int pre_bool_val = bool_v.size() / nrow2;
      unsigned int pre_int_val = int_v.size() / nrow2;
      unsigned int pre_uint_val = uint_v.size() / nrow2;
      unsigned int pre_dbl_val = dbl_v.size() / nrow2;

      for (auto& el : matr_idx[0]) {
        str_v.insert(str_v.end(), tmp_str_v.begin(), tmp_str_v.end());
      };
      for (auto& el : matr_idx[1]) {
        chr_v.insert(chr_v.end(), tmp_chr_v.begin(), tmp_chr_v.end());
      };
      for (auto& el : matr_idx[2]) {
        bool_v.insert(bool_v.end(), tmp_bool_v.begin(), tmp_bool_v.end());
      };
      for (auto& el : matr_idx[3]) {
        int_v.insert(int_v.end(), tmp_int_v.begin(), tmp_int_v.end());
      };
      for (auto& el : matr_idx[4]) {
        uint_v.insert(uint_v.end(), tmp_uint_v.begin(), tmp_uint_v.end());
      };
      for (auto& el : matr_idx[5]) {
        dbl_v.insert(dbl_v.end(), tmp_dbl_v.begin(), tmp_dbl_v.end());
      };

      std::vector<std::vector<unsigned int>> matr_idx2b = matr_idx2;
      for (auto& el : matr_idx2b) {
        for (auto& el2 : el) {
          el2 += ncol;
        };
      };

      matr_idx[0].insert(matr_idx[0].end(), 
                         matr_idx2b[0].begin(), 
                         matr_idx2b[0].end());
      matr_idx[1].insert(matr_idx[1].end(), 
                         matr_idx2b[1].begin(), 
                         matr_idx2b[1].end());
      matr_idx[2].insert(matr_idx[2].end(), 
                         matr_idx2b[2].begin(), 
                         matr_idx2b[2].end());
      matr_idx[3].insert(matr_idx[3].end(), 
                         matr_idx2b[3].begin(), 
                         matr_idx2b[3].end());
      matr_idx[4].insert(matr_idx[4].end(), 
                         matr_idx2b[4].begin(), 
                         matr_idx2b[4].end());
      matr_idx[5].insert(matr_idx[5].end(), 
                         matr_idx2b[5].begin(), 
                         matr_idx2b[5].end());

      for (size_t i = 0; i < col1.size(); ++i) {
        auto it = b_index.find(col1[i]);
        if (it != b_index.end()) {
          size_t idx = it->second;
          for (i2 = 0; i2 < matr_idx[0].size(); i2 += 1) {
            str_v[nrow2 * i2 + nrow] = str_v[nrow2 * i2 + i];
            pos_val = matr_idx[0][i2];
            tmp_val_refv[pos_val][nrow] = tmp_val_refv[pos_val][i];
          };
          for (i2 = 0; i2 < matr_idx[1].size(); i2 += 1) {
            chr_v[nrow2 * i2 + nrow] = chr_v[nrow2 * i2 + i];
            pos_val = matr_idx[1][i2];
            tmp_val_refv[pos_val][nrow] = tmp_val_refv[pos_val][i];
          };
          for (i2 = 0; i2 < matr_idx[2].size(); i2 += 1) {
            bool_v[nrow2 * i2 + nrow] = bool_v[nrow2 * i2 + i];
            pos_val = matr_idx[2][i2];
            tmp_val_refv[pos_val][nrow] = tmp_val_refv[pos_val][i];
          };
          for (i2 = 0; i2 < matr_idx[3].size(); i2 += 1) {
            int_v[nrow2 * i2 + nrow] = int_v[nrow2 * i2 + i];
            pos_val = matr_idx[3][i2];
            tmp_val_refv[pos_val][nrow] = tmp_val_refv[pos_val][i];
          };
          for (i2 = 0; i2 < matr_idx[4].size(); i2 += 1) {
            uint_v[nrow2 * i2 + nrow] = uint_v[nrow2 * i2 + i];
            pos_val = matr_idx[4][i2];
            tmp_val_refv[pos_val][nrow] = tmp_val_refv[pos_val][i];
          };
          for (i2 = 0; i2 < matr_idx[5].size(); i2 += 1) {
            dbl_v[nrow2 * i2 + nrow] = dbl_v[nrow2 * i2 + i];
            pos_val = matr_idx[5][i2];
            tmp_val_refv[pos_val][nrow] = tmp_val_refv[pos_val][i];
          };
          for (i2 = 0; i2 < matr_idx2[0].size(); i2 += 1) {
            pos_val = pre_str_val + i2;
            str_v[nrow2 * pos_val + nrow] = str_v[nrow2 * pos_val + i];
            pos_val = ncol + matr_idx[0][i2];
            tmp_val_refv[pos_val][nrow] = tmp_val_refv[pos_val][i];
          };
          for (i2 = 0; i2 < matr_idx2[1].size(); i2 += 1) {
            pos_val = pre_chr_val + i2;
            chr_v[nrow2 * pos_val + nrow] = chr_v[nrow2 * pos_val + i];
            pos_val = ncol + matr_idx[1][i2];
            tmp_val_refv[pos_val][nrow] = tmp_val_refv[pos_val][i];
          };
          for (i2 = 0; i2 < matr_idx2[2].size(); i2 += 1) {
            pos_val = pre_bool_val + i2;
            bool_v[nrow2 * pos_val + nrow] = bool_v[nrow2 * pos_val + i];
            pos_val = ncol + matr_idx[2][i2];
            tmp_val_refv[pos_val][nrow] = tmp_val_refv[pos_val][i];
          };
          for (i2 = 0; i2 < matr_idx2[3].size(); i2 += 1) {
            pos_val = pre_int_val + i2;
            int_v[nrow2 * pos_val + nrow] = int_v[nrow2 * pos_val + i];
            pos_val = ncol + matr_idx[3][i2];
            tmp_val_refv[pos_val][nrow] = tmp_val_refv[pos_val][i];
          };
          for (i2 = 0; i2 < matr_idx2[4].size(); i2 += 1) {
            pos_val = pre_uint_val + i2;
            uint_v[nrow2 * pos_val + nrow] = uint_v[nrow2 * pos_val + i];
            pos_val = ncol + matr_idx[4][i2];
            tmp_val_refv[pos_val][nrow] = tmp_val_refv[pos_val][i];
          };
          for (i2 = 0; i2 < matr_idx2[5].size(); i2 += 1) {
            pos_val = pre_dbl_val + i2;
            dbl_v[nrow2 * pos_val + nrow] = dbl_v[nrow2 * pos_val + i];
            pos_val = ncol + matr_idx[5][i2];
            tmp_val_refv[pos_val][nrow] = tmp_val_refv[pos_val][i];
          };
          nrow += 1;
        };
      };
      ncol += ncol2;
      longest_determine();
    };

    void merge_inner2(Dataframe &obj1, Dataframe &obj2, bool colname, unsigned int &key1, unsigned int &key2) {
      const unsigned int& ncol1 = obj1.get_ncol();
      const unsigned int& ncol2 = obj2.get_ncol();
      std::vector<std::string> cur_vstr;
      ncol = ncol1 + ncol2;
      unsigned int i;
      unsigned int i2;
      unsigned int i3;
      const std::vector<std::string>& name1 = obj1.get_colname();
      const std::vector<std::string>& name2 = obj2.get_colname();
      if (colname) {
        name_v.resize(ncol);
        if (name1.size() > 0) {
          for (i = 0; i < name1.size(); ++i) {
            name_v.push_back(name1[i]);
          };
        };
        if (name2.size() > 0) {
          for (i = 0; i < name2.size(); ++i) {
            name_v.push_back(name2[i]);
          };
        };
      };
      tmp_val_refv.reserve(ncol);
      for (i = 0; i < ncol; ++i) {
        tmp_val_refv.push_back(cur_vstr);
      };
      const std::vector<char>& type1 = obj1.get_typecol();
      const std::vector<char>& type2 = obj2.get_typecol();
      const auto& tmp1 = obj1.get_tmp_val_refv();
      const auto& tmp2 = obj2.get_tmp_val_refv();
      const std::vector<std::string>& col1 = tmp1[key1];
      const std::vector<std::string>& col2 = tmp2[key2];
      std::unordered_multimap<std::string, size_t> b_index;
      for (size_t j = 0; j < col2.size(); ++j) {
        b_index.insert({col2[j], j});
      };
      for (size_t i = 0; i < col1.size(); ++i) {
        auto it = b_index.find(col1[i]);
        if (it != b_index.end()) {
          nrow += 1;
          size_t idx = it->second;
          for (i2 = 0; i2 < ncol1; i2 += 1) {
            tmp_val_refv[i2].push_back(tmp1[i2][i]);
          };
          for (i2 = 0; i2 < ncol2; i2 += 1) {
            tmp_val_refv[ncol1 + i2].push_back(tmp2[i2][idx]);
          };
        };
      };
      longest_determine();
      type_classification();
    };

    void merge_excluding(Dataframe &obj1, 
                         Dataframe &obj2, 
                         bool colname, 
                         unsigned int &key1, 
                         unsigned int &key2,
                         std::string default_str = "NA",
                         std::string default_chr = " ",
                         std::string default_bool = "0",
                         std::string default_int = "0",
                         std::string default_uint = "0",
                         std::string default_dbl = "0") {
      const unsigned int& ncol1 = obj1.get_ncol();
      const unsigned int& ncol2 = obj2.get_ncol();
      std::vector<std::string> cur_vstr;
      ncol = ncol1 + ncol2;
      unsigned int i;
      unsigned int i2;
      unsigned int i3;
      const std::vector<std::vector<unsigned int>>& matr_idx2 = obj2.get_matr_idx();
      const std::vector<std::string>& name1 = obj1.get_colname();
      const std::vector<std::string>& name2 = obj2.get_colname();
      if (colname) {
        name_v.resize(ncol);
        if (name1.size() > 0) {
          for (i = 0; i < name1.size(); ++i) {
            name_v.push_back(name1[i]);
          };
        };
        if (name2.size() > 0) {
          for (i = 0; i < name2.size(); ++i) {
            name_v.push_back(name2[i]);
          };
        };
      };
      tmp_val_refv.reserve(ncol);
      for (i = 0; i < ncol; ++i) {
        tmp_val_refv.push_back(cur_vstr);
      };
      const std::vector<char>& type1 = obj1.get_typecol();
      const std::vector<char>& type2 = obj2.get_typecol();
      const auto& tmp1 = obj1.get_tmp_val_refv();
      const auto& tmp2 = obj2.get_tmp_val_refv();
      const std::vector<std::string>& col1 = tmp1[key1];
      const std::vector<std::string>& col2 = tmp2[key2];
      std::unordered_multimap<std::string, size_t> b_index;
      for (size_t j = 0; j < col2.size(); ++j) {
        b_index.insert({col2[j], j});
      };
      for (size_t i = 0; i < col1.size(); ++i) {
        auto range = b_index.equal_range(col1[i]);
        if (range.first == range.second) {
          nrow += 1;
          for (i2 = 0; i2 < ncol1; i2 += 1) {
            tmp_val_refv[i2].push_back(tmp1[i2][i]);
          };
          for (auto& el : matr_idx2[0]) {
            tmp_val_refv[ncol1 + el].push_back(default_str);
          };
          for (auto& el : matr_idx2[1]) {
            tmp_val_refv[ncol1 + el].push_back(default_chr);
          };
          for (auto& el : matr_idx2[2]) {
            tmp_val_refv[ncol1 + el].push_back(default_bool);
          };
          for (auto& el : matr_idx2[3]) {
            tmp_val_refv[ncol1 + el].push_back(default_int);
          };
          for (auto& el : matr_idx2[4]) {
            tmp_val_refv[ncol1 + el].push_back(default_uint);
          };
          for (auto& el : matr_idx2[5]) {
            tmp_val_refv[ncol1 + el].push_back(default_dbl);
          };
        };
      };
      longest_determine();
      type_classification();
    };
    
    void merge_excluding_both(Dataframe &obj1, 
                              Dataframe &obj2, 
                              bool colname, 
                              unsigned int &key1, 
                              unsigned int &key2,
                              std::string default_str = "NA",
                              std::string default_chr = " ",
                              std::string default_bool = "0",
                              std::string default_int = "0",
                              std::string default_uint = "0",
                              std::string default_dbl = "0") {
      const unsigned int& ncol1 = obj1.get_ncol();
      const unsigned int& ncol2 = obj2.get_ncol();
      std::vector<std::string> cur_vstr;
      ncol = ncol1 + ncol2;
      unsigned int i;
      unsigned int i2;
      unsigned int i3;
      const std::vector<std::vector<unsigned int>>& matr_idx1 = obj1.get_matr_idx();
      const std::vector<std::vector<unsigned int>>& matr_idx2 = obj2.get_matr_idx();
      const std::vector<std::string>& name1 = obj1.get_colname();
      const std::vector<std::string>& name2 = obj2.get_colname();
      if (colname) {
        name_v.resize(ncol);
        if (name1.size() > 0) {
          for (i = 0; i < name1.size(); ++i) {
            name_v.push_back(name1[i]);
          };
        };
        if (name2.size() > 0) {
          for (i = 0; i < name2.size(); ++i) {
            name_v.push_back(name2[i]);
          };
        };
      };
      tmp_val_refv.reserve(ncol);
      for (i = 0; i < ncol; ++i) {
        tmp_val_refv.push_back(cur_vstr);
      };
      const std::vector<char>& type1 = obj1.get_typecol();
      const std::vector<char>& type2 = obj2.get_typecol();
      const auto& tmp1 = obj1.get_tmp_val_refv();
      const auto& tmp2 = obj2.get_tmp_val_refv();
      const std::vector<std::string>& col1 = tmp1[key1];
      const std::vector<std::string>& col2 = tmp2[key2];
      std::unordered_multimap<std::string, size_t> b_index;
      for (size_t j = 0; j < col2.size(); ++j) {
        b_index.insert({col2[j], j});
      };
      std::unordered_multimap<std::string, size_t> a_index;
      for (size_t j = 0; j < col1.size(); ++j) {
        a_index.insert({col1[j], j});
      };
      for (size_t i = 0; i < col1.size(); ++i) {
        auto range = b_index.equal_range(col1[i]);
        if (range.first == range.second) {
          nrow += 1;
          for (i2 = 0; i2 < ncol1; i2 += 1) {
            tmp_val_refv[i2].push_back(tmp1[i2][i]);
          };
          for (auto& el : matr_idx2[0]) {
            tmp_val_refv[ncol1 + el].push_back(default_str);
          };
          for (auto& el : matr_idx2[1]) {
            tmp_val_refv[ncol1 + el].push_back(default_chr);
          };
          for (auto& el : matr_idx2[2]) {
            tmp_val_refv[ncol1 + el].push_back(default_bool);
          };
          for (auto& el : matr_idx2[3]) {
            tmp_val_refv[ncol1 + el].push_back(default_int);
          };
          for (auto& el : matr_idx2[4]) {
            tmp_val_refv[ncol1 + el].push_back(default_uint);
          };
          for (auto& el : matr_idx2[5]) {
            tmp_val_refv[ncol1 + el].push_back(default_dbl);
          };
        };
      };
      for (size_t i = 0; i < col2.size(); ++i) {
        auto range = a_index.equal_range(col2[i]);
        if (range.first == range.second) {
          nrow += 1;
          for (auto& el : matr_idx1[0]) {
            tmp_val_refv[el].push_back(default_str);
          };
          for (auto& el : matr_idx1[1]) {
            tmp_val_refv[el].push_back(default_chr);
          };
          for (auto& el : matr_idx1[2]) {
            tmp_val_refv[el].push_back(default_bool);
          };
          for (auto& el : matr_idx1[3]) {
            tmp_val_refv[el].push_back(default_int);
          };
          for (auto& el : matr_idx1[4]) {
            tmp_val_refv[el].push_back(default_uint);
          };
          for (auto& el : matr_idx1[5]) {
            tmp_val_refv[el].push_back(default_dbl);
          };
          for (i2 = 0; i2 < ncol2; i2 += 1) {
            tmp_val_refv[ncol1 + i2].push_back(tmp2[i2][i]);
          };
        };
      };
      longest_determine();
      type_classification();
    };

    void merge_all(Dataframe &obj1, 
                    Dataframe &obj2, 
                    bool colname, 
                    unsigned int &key1, 
                    unsigned int &key2,
                    std::string default_str = "NA",
                    std::string default_chr = " ",
                    std::string default_bool = "0",
                    std::string default_int = "0",
                    std::string default_uint = "0",
                    std::string default_dbl = "0") {
      const unsigned int& ncol1 = obj1.get_ncol();
      const unsigned int& ncol2 = obj2.get_ncol();
      std::vector<std::string> cur_vstr;
      ncol = ncol1 + ncol2;
      unsigned int i;
      unsigned int i2;
      unsigned int i3;
      const std::vector<std::vector<unsigned int>>& matr_idx1 = obj1.get_matr_idx();
      const std::vector<std::vector<unsigned int>>& matr_idx2 = obj2.get_matr_idx();
      const std::vector<std::string>& name1 = obj1.get_colname();
      const std::vector<std::string>& name2 = obj2.get_colname();
      if (colname) {
        name_v.resize(ncol);
        if (name1.size() > 0) {
          for (i = 0; i < name1.size(); ++i) {
            name_v.push_back(name1[i]);
          };
        };
        if (name2.size() > 0) {
          for (i = 0; i < name2.size(); ++i) {
            name_v.push_back(name2[i]);
          };
        };
      };
      tmp_val_refv.reserve(ncol);
      for (i = 0; i < ncol; ++i) {
        tmp_val_refv.push_back(cur_vstr);
      };
      const std::vector<char>& type1 = obj1.get_typecol();
      const std::vector<char>& type2 = obj2.get_typecol();
      const auto& tmp1 = obj1.get_tmp_val_refv();
      const auto& tmp2 = obj2.get_tmp_val_refv();
      const std::vector<std::string>& col1 = tmp1[key1];
      const std::vector<std::string>& col2 = tmp2[key2];
      std::unordered_multimap<std::string, size_t> b_index;
      for (size_t j = 0; j < col2.size(); ++j) {
        b_index.insert({col2[j], j});
      };
      std::unordered_multimap<std::string, size_t> a_index;
      for (size_t j = 0; j < col1.size(); ++j) {
        a_index.insert({col1[j], j});
      };
      for (size_t i = 0; i < col1.size(); ++i) {
        auto range = b_index.equal_range(col1[i]);
        if (range.first == range.second) {
          nrow += 1;
          for (i2 = 0; i2 < ncol1; i2 += 1) {
            tmp_val_refv[i2].push_back(tmp1[i2][i]);
          };
          for (auto& el : matr_idx2[0]) {
            tmp_val_refv[ncol1 + el].push_back(default_str);
          };
          for (auto& el : matr_idx2[1]) {
            tmp_val_refv[ncol1 + el].push_back(default_chr);
          };
          for (auto& el : matr_idx2[2]) {
            tmp_val_refv[ncol1 + el].push_back(default_bool);
          };
          for (auto& el : matr_idx2[3]) {
            tmp_val_refv[ncol1 + el].push_back(default_int);
          };
          for (auto& el : matr_idx2[4]) {
            tmp_val_refv[ncol1 + el].push_back(default_uint);
          };
          for (auto& el : matr_idx2[5]) {
            tmp_val_refv[ncol1 + el].push_back(default_dbl);
          };
        } else {
          for (auto it = range.first; it != range.second; ++it) {
            nrow += 1;
            size_t idx = it->second;
            for (i2 = 0; i2 < ncol1; i2 += 1) {
              tmp_val_refv[i2].push_back(tmp1[i2][i]);
            };
            for (i2 = 0; i2 < ncol2; i2 += 1) {
              tmp_val_refv[ncol1 + i2].push_back(tmp2[i2][idx]);
            };
          };
        };
      };
      for (size_t i = 0; i < col2.size(); ++i) {
        auto range = a_index.equal_range(col2[i]);
        if (range.first == range.second) {
          nrow += 1;
          for (auto& el : matr_idx1[0]) {
            tmp_val_refv[el].push_back(default_str);
          };
          for (auto& el : matr_idx1[1]) {
            tmp_val_refv[el].push_back(default_chr);
          };
          for (auto& el : matr_idx1[2]) {
            tmp_val_refv[el].push_back(default_bool);
          };
          for (auto& el : matr_idx1[3]) {
            tmp_val_refv[el].push_back(default_int);
          };
          for (auto& el : matr_idx1[4]) {
            tmp_val_refv[el].push_back(default_uint);
          };
          for (auto& el : matr_idx1[5]) {
            tmp_val_refv[el].push_back(default_dbl);
          };
          for (i2 = 0; i2 < ncol2; i2 += 1) {
            tmp_val_refv[ncol1 + i2].push_back(tmp2[i2][i]);
          };
        };
      };
      longest_determine();
      type_classification();
    };

    void merge_all2(Dataframe &obj1, 
                    Dataframe &obj2, 
                    bool colname, 
                    unsigned int &key1, 
                    unsigned int &key2,
                    std::string default_str = "NA",
                    std::string default_chr = " ",
                    std::string default_bool = "0",
                    std::string default_int = "0",
                    std::string default_uint = "0",
                    std::string default_dbl = "0") {
      const unsigned int& ncol1 = obj1.get_ncol();
      const unsigned int& ncol2 = obj2.get_ncol();
      std::vector<std::string> cur_vstr;
      ncol = ncol1 + ncol2;
      unsigned int i;
      unsigned int i2;
      unsigned int i3;
      const std::vector<std::vector<unsigned int>>& matr_idx1 = obj1.get_matr_idx();
      const std::vector<std::vector<unsigned int>>& matr_idx2 = obj2.get_matr_idx();
      const std::vector<std::string>& name1 = obj1.get_colname();
      const std::vector<std::string>& name2 = obj2.get_colname();
      if (colname) {
        name_v.resize(ncol);
        if (name1.size() > 0) {
          for (i = 0; i < name1.size(); ++i) {
            name_v.push_back(name1[i]);
          };
        };
        if (name2.size() > 0) {
          for (i = 0; i < name2.size(); ++i) {
            name_v.push_back(name2[i]);
          };
        };
      };
      tmp_val_refv.reserve(ncol);
      for (i = 0; i < ncol; ++i) {
        tmp_val_refv.push_back(cur_vstr);
      };
      const std::vector<char>& type1 = obj1.get_typecol();
      const std::vector<char>& type2 = obj2.get_typecol();
      const auto& tmp1 = obj1.get_tmp_val_refv();
      const auto& tmp2 = obj2.get_tmp_val_refv();
      const std::vector<std::string>& col1 = tmp1[key1];
      const std::vector<std::string>& col2 = tmp2[key2];
      std::unordered_multimap<std::string, size_t> b_index;
      for (size_t j = 0; j < col2.size(); ++j) {
        b_index.insert({col2[j], j});
      };
      std::unordered_multimap<std::string, size_t> a_index;
      for (size_t j = 0; j < col1.size(); ++j) {
        a_index.insert({col1[j], j});
      };
      for (size_t i = 0; i < col1.size(); ++i) {
        auto it = b_index.find(col1[i]);
        if (it == b_index.end()) {
          nrow += 1;
          for (i2 = 0; i2 < ncol1; i2 += 1) {
            tmp_val_refv[i2].push_back(tmp1[i2][i]);
          };
          for (auto& el : matr_idx2[0]) {
            tmp_val_refv[ncol1 + el].push_back(default_str);
          };
          for (auto& el : matr_idx2[1]) {
            tmp_val_refv[ncol1 + el].push_back(default_chr);
          };
          for (auto& el : matr_idx2[2]) {
            tmp_val_refv[ncol1 + el].push_back(default_bool);
          };
          for (auto& el : matr_idx2[3]) {
            tmp_val_refv[ncol1 + el].push_back(default_int);
          };
          for (auto& el : matr_idx2[4]) {
            tmp_val_refv[ncol1 + el].push_back(default_uint);
          };
          for (auto& el : matr_idx2[5]) {
            tmp_val_refv[ncol1 + el].push_back(default_dbl);
          };
        } else {
          nrow += 1;
          size_t idx = it->second;
          for (i2 = 0; i2 < ncol1; i2 += 1) {
            tmp_val_refv[i2].push_back(tmp1[i2][i]);
          };
          for (i2 = 0; i2 < ncol2; i2 += 1) {
            tmp_val_refv[ncol1 + i2].push_back(tmp2[i2][idx]);
          };
        };
      };
      for (size_t i = 0; i < col2.size(); ++i) {
        auto it = a_index.find(col2[i]);
        if (it == a_index.end()) {
          nrow += 1;
          for (i2 = 0; i2 < ncol2; i2 += 1) {
            tmp_val_refv[ncol1 + i2].push_back(tmp2[i2][i]);
          };
          for (auto& el : matr_idx1[0]) {
            tmp_val_refv[el].push_back(default_str);
          };
          for (auto& el : matr_idx1[1]) {
            tmp_val_refv[el].push_back(default_chr);
          };
          for (auto& el : matr_idx1[2]) {
            tmp_val_refv[el].push_back(default_bool);
          };
          for (auto& el : matr_idx1[3]) {
            tmp_val_refv[el].push_back(default_int);
          };
          for (auto& el : matr_idx1[4]) {
            tmp_val_refv[el].push_back(default_uint);
          };
          for (auto& el : matr_idx1[5]) {
            tmp_val_refv[el].push_back(default_dbl);
          };
          for (i2 = 0; i2 < ncol2; i2 += 1) {
            tmp_val_refv[i2].push_back(tmp2[i2][i]);
          };
        };
      };
      longest_determine();
      type_classification();
    };

    void transform_left_join(Dataframe &obj, 
                    unsigned int &key1, 
                    unsigned int &key2,
                    std::string default_str = "NA",
                    char default_chr = ' ',
                    bool default_bool = 0,
                    int default_int = 0,
                    unsigned int default_uint = 0,
                    double default_dbl = 0) {
      const unsigned int& ncol2 = obj.get_ncol();
      const std::vector<std::vector<unsigned int>>& matr_idx2 = obj.get_matr_idx();

      const std::vector<std::string>& str_v2 = obj.get_str_vec();
      const std::vector<char>& chr_v2 = obj.get_chr_vec();
      const std::vector<bool>& bool_v2 = obj.get_bool_vec();
      const std::vector<int>& int_v2 = obj.get_int_vec();
      const std::vector<unsigned int>& uint_v2 = obj.get_uint_vec();
      const std::vector<double>& dbl_v2 = obj.get_dbl_vec();
      
      const unsigned int size_str = str_v.size() / nrow;
      const unsigned int size_chr = chr_v.size() / nrow;
      const unsigned int size_bool = bool_v.size() / nrow;
      const unsigned int size_int = int_v.size() / nrow;
      const unsigned int size_uint = uint_v.size() / nrow;
      const unsigned int size_dbl = dbl_v.size() / nrow;
      
      unsigned int i;
      unsigned int i2;
      
      std::vector<std::string> vec_str(nrow);

      for (i = 0; i < ncol2; i += 1) {
        tmp_val_refv.push_back(vec_str);
      };

      const std::vector<char>& vec_type = obj.get_typecol();
      const std::vector<std::string>& col1 = tmp_val_refv[key1];
      const std::vector<std::vector<std::string>>& tmp_val_refv2 = obj.get_tmp_val_refv();
      const std::vector<std::string>& col2 = tmp_val_refv2[key2];

      str_v.resize(str_v.size() + nrow * matr_idx2[0].size());
      chr_v.resize(chr_v.size() + nrow * matr_idx2[1].size());
      bool_v.resize(bool_v.size() + nrow * matr_idx2[2].size());
      int_v.resize(int_v.size() + nrow * matr_idx2[3].size());
      uint_v.resize(uint_v.size() + nrow * matr_idx2[4].size());
      dbl_v.resize(dbl_v.size() + nrow * matr_idx2[5].size());
     
      std::vector<std::vector<unsigned int>> matr_idx2b = matr_idx2;
      for (auto& el : matr_idx2b) {
        for (auto& el2 : el) {
          el2 += ncol;
        };
      };

      matr_idx[0].insert(matr_idx[0].end(), 
                         matr_idx2b[0].begin(), 
                         matr_idx2b[0].end());
      matr_idx[1].insert(matr_idx[1].end(), 
                         matr_idx2b[1].begin(), 
                         matr_idx2b[1].end());
      matr_idx[2].insert(matr_idx[2].end(), 
                         matr_idx2b[2].begin(), 
                         matr_idx2b[2].end());
      matr_idx[3].insert(matr_idx[3].end(), 
                         matr_idx2b[3].begin(), 
                         matr_idx2b[3].end());
      matr_idx[4].insert(matr_idx[4].end(), 
                         matr_idx2b[4].begin(), 
                         matr_idx2b[4].end());
      matr_idx[5].insert(matr_idx[5].end(), 
                         matr_idx2b[5].begin(), 
                         matr_idx2b[5].end());


      std::unordered_multimap<std::string, size_t> lookup;
      for (i = 0; i < col2.size(); i += 1) {
        lookup.insert({col2[i], i});
      };
 
      unsigned int idx;
      unsigned int pos_vl;
      const unsigned int& nrow2 = obj.get_nrow();
      for (i = 0; i < col1.size(); i += 1) {

        auto it = lookup.find(col1[i]);
        if (it == lookup.end()) {
          for (i2 = 0; i2 < matr_idx2[0].size(); i2 += 1) {
            tmp_val_refv[ncol + matr_idx2[0][i2]][i] = default_str;
            str_v[nrow * (size_str + i2) + i] = default_str;
          };
          for (i2 = 0; i2 < matr_idx2[1].size(); i2 += 1) {
            tmp_val_refv[ncol + matr_idx2[1][i2]][i] = std::string(1, default_chr);
            chr_v[nrow * (size_chr + i2) + i] = default_chr;
          };
          for (i2 = 0; i2 < matr_idx2[2].size(); i2 += 1) {
            tmp_val_refv[ncol + matr_idx2[2][i2]][i] = std::to_string(default_bool);
            bool_v[nrow * (size_bool + i2) + i] = default_bool;
          };
          for (i2 = 0; i2 < matr_idx2[3].size(); i2 += 1) {
            tmp_val_refv[ncol + matr_idx2[3][i2]][i] = std::to_string(default_int);
            int_v[nrow * (size_int + i2) + i] = default_int;
          };
          for (i2 = 0; i2 < matr_idx2[4].size(); i2 += 1) {
            tmp_val_refv[ncol + matr_idx2[4][i2]][i] = std::to_string(default_uint);
            uint_v[nrow * (size_uint + i2) + i] = default_uint;
          };
          for (i2 = 0; i2 < matr_idx2[5].size(); i2 += 1) {
            tmp_val_refv[ncol + matr_idx2[5][i2]][i] = std::to_string(default_dbl);
            dbl_v[nrow * (size_dbl + i2) + i] = default_dbl;
          };
        } else {
          idx = it->second;
          for (i2 = 0; i2 < matr_idx2[0].size(); i2 += 1) {
            str_v[nrow * (size_str + i2) + i] = str_v2[nrow2 * i2 + idx];
            pos_vl = matr_idx2[0][i2];
            tmp_val_refv[ncol + pos_vl][i] = tmp_val_refv2[pos_vl][idx];
          };
          for (i2 = 0; i2 < matr_idx2[1].size(); i2 += 1) {
            chr_v[nrow * (size_chr + i2) + i] = chr_v2[nrow2 * i2 + idx];
            pos_vl = matr_idx2[1][i2];
            tmp_val_refv[ncol + pos_vl][i] = tmp_val_refv2[pos_vl][idx];
          };
          for (i2 = 0; i2 < matr_idx2[2].size(); i2 += 1) {
            bool_v[nrow * (size_bool + i2) + i] = bool_v2[nrow2 * i2 + idx];
            pos_vl = matr_idx2[2][i2];
            tmp_val_refv[ncol + pos_vl][i] = tmp_val_refv2[pos_vl][idx];
          };
          for (i2 = 0; i2 < matr_idx2[3].size(); i2 += 1) {
            int_v[nrow * (size_int + i2) + i] = int_v2[nrow2 * i2 + idx];
            pos_vl = matr_idx2[3][i2];
            tmp_val_refv[ncol + pos_vl][i] = tmp_val_refv2[pos_vl][idx];
          };
          for (i2 = 0; i2 < matr_idx2[4].size(); i2 += 1) {
            uint_v[nrow * (size_uint + i2) + i] = uint_v2[nrow2 * i2 + idx];
            pos_vl = matr_idx2[4][i2];
            tmp_val_refv[ncol + pos_vl][i] = tmp_val_refv2[pos_vl][idx];
          };
          for (i2 = 0; i2 < matr_idx2[5].size(); i2 += 1) {
            dbl_v[nrow * (size_dbl + i2) + i] = dbl_v2[nrow2 * i2 + idx];
            pos_vl = matr_idx2[5][i2];
            tmp_val_refv[ncol + pos_vl][i] = tmp_val_refv2[pos_vl][idx];
          };
        };
      };
      type_refv.insert(type_refv.end(), vec_type.begin(), vec_type.end());
      ncol += ncol2;
      const std::vector<std::string>& colname2 = obj.get_colname();
      if (colname2.size() > 0) {
        name_v.insert(name_v.end(), colname2.begin(), colname2.end());
      } else {
        name_v.resize(ncol);
      };
      longest_determine();
    };

    void transform_filter(std::vector<bool>& mask) {
      unsigned int i2;
      unsigned int nrow2 = nrow;
      nrow = 0;
      unsigned int pos_vl;
      for (unsigned int i = 0; i < nrow2; i += 1) {
        if (mask[i]) {
          for (i2 = 0 ; i2 < matr_idx[0].size(); i2 += 1) {
            pos_vl = matr_idx[0][i2];
            tmp_val_refv[pos_vl][nrow] = tmp_val_refv[pos_vl][i];
            str_v[nrow2 * i2 + nrow] = str_v[nrow2 * i2 + i];
          };
          for (i2 = 0 ; i2 < matr_idx[1].size(); i2 += 1) {
            pos_vl = matr_idx[1][i2];
            tmp_val_refv[pos_vl][nrow] = tmp_val_refv[pos_vl][i];
            chr_v[nrow2 * i2 + nrow] = chr_v[nrow2 * i2 + i];
          };
          for (i2 = 0 ; i2 < matr_idx[2].size(); i2 += 1) {
            pos_vl = matr_idx[2][i2];
            tmp_val_refv[pos_vl][nrow] = tmp_val_refv[pos_vl][i];
            bool_v[nrow2 * i2 + nrow] = bool_v[nrow2 * i2 + i];
          };
          for (i2 = 0 ; i2 < matr_idx[3].size(); i2 += 1) {
            pos_vl = matr_idx[3][i2];
            tmp_val_refv[pos_vl][nrow] = tmp_val_refv[pos_vl][i];
            int_v[nrow2 * i2 + nrow] = int_v[nrow2 * i2 + i];
          };
          for (i2 = 0 ; i2 < matr_idx[4].size(); i2 += 1) {
            pos_vl = matr_idx[4][i2];
            tmp_val_refv[pos_vl][nrow] = tmp_val_refv[pos_vl][i];
            uint_v[nrow2 * i2 + nrow] = uint_v[nrow2 * i2 + i];
          };
          for (i2 = 0 ; i2 < matr_idx[5].size(); i2 += 1) {
            pos_vl = matr_idx[5][i2];
            tmp_val_refv[pos_vl][nrow] = tmp_val_refv[pos_vl][i];
            dbl_v[nrow2 * i2 + nrow] = dbl_v[nrow2 * i2 + i];
          };
          nrow += 1;
        };
      }
    };

    void transform_unique(unsigned int& n) {
      unsigned int nrow2 = nrow;
      unsigned int i;
      unsigned int i2;
      unsigned int pos_vl;
      nrow = 0;
      std::unordered_set<std::string> unic_v;
      for (i = 0; i < nrow2; i += 1) {
        if (!unic_v.contains(tmp_val_refv[n][i])) {
          unic_v.insert(tmp_val_refv[n][i]);
          for (i2 = 0; i2 < matr_idx[0].size(); i2 += 1) {
            pos_vl = matr_idx[0][i2];
            tmp_val_refv[pos_vl][nrow] = tmp_val_refv[pos_vl][i];
            str_v[nrow2 * i2 + nrow] = str_v[nrow2 * i2 + i];
          };
          for (i2 = 0; i2 < matr_idx[1].size(); i2 += 1) {
            pos_vl = matr_idx[1][i2];
            tmp_val_refv[pos_vl][nrow] = tmp_val_refv[pos_vl][i];
            chr_v[nrow2 * i2 + nrow] = chr_v[nrow2 * i2 + i];
          };
          for (i2 = 0; i2 < matr_idx[2].size(); i2 += 1) {
            pos_vl = matr_idx[2][i2];
            tmp_val_refv[pos_vl][nrow] = tmp_val_refv[pos_vl][i];
            bool_v[nrow2 * i2 + nrow] = bool_v[nrow2 * i2 + i];
          };
          for (i2 = 0; i2 < matr_idx[3].size(); i2 += 1) {
            pos_vl = matr_idx[3][i2];
            tmp_val_refv[pos_vl][nrow] = tmp_val_refv[pos_vl][i];
            int_v[nrow2 * i2 + nrow] = int_v[nrow2 * i2 + i];
          };
          for (i2 = 0; i2 < matr_idx[4].size(); i2 += 1) {
            pos_vl = matr_idx[4][i2];
            tmp_val_refv[pos_vl][nrow] = tmp_val_refv[pos_vl][i];
            uint_v[nrow2 * i2 + nrow] = uint_v[nrow2 * i2 + i];
          };
          for (i2 = 0; i2 < matr_idx[5].size(); i2 += 1) {
            pos_vl = matr_idx[5][i2];
            tmp_val_refv[pos_vl][nrow] = tmp_val_refv[pos_vl][i];
            dbl_v[nrow2 * i2 + nrow] = dbl_v[nrow2 * i2 + i];
          };
          nrow += 1;
        };
      };
    };

    void transform_unique_clean(unsigned int& n) {
      unsigned int nrow2 = nrow;
      unsigned int i;
      unsigned int i2;
      unsigned int pos_vl;
      nrow = 0;
      std::unordered_set<std::string> unic_v;
      for (i = 0; i < nrow2; i += 1) {
        if (!unic_v.contains(tmp_val_refv[n][i])) {
          unic_v.insert(tmp_val_refv[n][i]);
          for (i2 = 0; i2 < matr_idx[0].size(); i2 += 1) {
            pos_vl = matr_idx[0][i2];
            tmp_val_refv[pos_vl][nrow] = tmp_val_refv[pos_vl][i];
            str_v[nrow2 * i2 + nrow] = str_v[nrow2 * i2 + i];
          };
          for (i2 = 0; i2 < matr_idx[1].size(); i2 += 1) {
            pos_vl = matr_idx[1][i2];
            tmp_val_refv[pos_vl][nrow] = tmp_val_refv[pos_vl][i];
            chr_v[nrow2 * i2 + nrow] = chr_v[nrow2 * i2 + i];
          };
          for (i2 = 0; i2 < matr_idx[2].size(); i2 += 1) {
            pos_vl = matr_idx[2][i2];
            tmp_val_refv[pos_vl][nrow] = tmp_val_refv[pos_vl][i];
            bool_v[nrow2 * i2 + nrow] = bool_v[nrow2 * i2 + i];
          };
          for (i2 = 0; i2 < matr_idx[3].size(); i2 += 1) {
            pos_vl = matr_idx[3][i2];
            tmp_val_refv[pos_vl][nrow] = tmp_val_refv[pos_vl][i];
            int_v[nrow2 * i2 + nrow] = int_v[nrow2 * i2 + i];
          };
          for (i2 = 0; i2 < matr_idx[4].size(); i2 += 1) {
            pos_vl = matr_idx[4][i2];
            tmp_val_refv[pos_vl][nrow] = tmp_val_refv[pos_vl][i];
            uint_v[nrow2 * i2 + nrow] = uint_v[nrow2 * i2 + i];
          };
          for (i2 = 0; i2 < matr_idx[5].size(); i2 += 1) {
            pos_vl = matr_idx[5][i2];
            tmp_val_refv[pos_vl][nrow] = tmp_val_refv[pos_vl][i];
            dbl_v[nrow2 * i2 + nrow] = dbl_v[nrow2 * i2 + i];
          };
          nrow += 1;
        };
      };
     
      unsigned int pos_vl2;
      unsigned int delta_col = nrow2 - nrow;
      for (i2 = 0; i2 < matr_idx[0].size(); i2 += 1) {
        pos_vl = matr_idx[0][i2];
        pos_vl2 = (nrow + 1) * i2;
        str_v.erase(str_v.begin() + pos_vl2, 
                        str_v.begin() + pos_vl2 + delta_col);
        tmp_val_refv[pos_vl].erase(tmp_val_refv[pos_vl].begin() + nrow, 
                        tmp_val_refv[pos_vl].end());
        tmp_val_refv[pos_vl].shrink_to_fit();
      };
      str_v.shrink_to_fit();
      for (i2 = 0; i2 < matr_idx[1].size(); i2 += 1) {
        pos_vl = matr_idx[1][i2];
        pos_vl2 = (nrow + 1) * i2;
        chr_v.erase(chr_v.begin() + pos_vl2, 
                        chr_v.begin() + pos_vl2 + delta_col);
        tmp_val_refv[pos_vl].erase(tmp_val_refv[pos_vl].begin() + nrow, 
                        tmp_val_refv[pos_vl].end());
        tmp_val_refv[pos_vl].shrink_to_fit();
      };
      chr_v.shrink_to_fit();
      for (i2 = 0; i2 < matr_idx[2].size(); i2 += 1) {
        pos_vl = matr_idx[2][i2];
        pos_vl2 = (nrow + 1) * i2;
        bool_v.erase(bool_v.begin() + pos_vl2, 
                        bool_v.begin() + pos_vl2 + delta_col);
        tmp_val_refv[pos_vl].erase(tmp_val_refv[pos_vl].begin() + nrow, 
                        tmp_val_refv[pos_vl].end());
        tmp_val_refv[pos_vl].shrink_to_fit();
      };
      bool_v.shrink_to_fit();
      for (i2 = 0; i2 < matr_idx[3].size(); i2 += 1) {
        pos_vl = matr_idx[3][i2];
        pos_vl2 = (nrow + 1) * i2;
        int_v.erase(int_v.begin() + pos_vl2, 
                        int_v.begin() + pos_vl2 + delta_col);
        tmp_val_refv[pos_vl].erase(tmp_val_refv[pos_vl].begin() + nrow, 
                        tmp_val_refv[pos_vl].end());
        tmp_val_refv[pos_vl].shrink_to_fit();
      };
      int_v.shrink_to_fit();
      for (i2 = 0; i2 < matr_idx[4].size(); i2 += 1) {
        pos_vl = matr_idx[4][i2];
        pos_vl2 = (nrow + 1) * i2;
        uint_v.erase(uint_v.begin() + pos_vl2, 
                        uint_v.begin() + pos_vl2 + delta_col);
        tmp_val_refv[pos_vl].erase(tmp_val_refv[pos_vl].begin() + nrow, 
                        tmp_val_refv[pos_vl].end());
        tmp_val_refv[pos_vl].shrink_to_fit();
      };
      uint_v.shrink_to_fit();
      for (i2 = 0; i2 < matr_idx[5].size(); i2 += 1) {
        pos_vl = matr_idx[5][i2];
        pos_vl2 = (nrow + 1) * i2;
        dbl_v.erase(dbl_v.begin() + pos_vl2, 
                        dbl_v.begin() + pos_vl2 + delta_col);
        tmp_val_refv[pos_vl].erase(tmp_val_refv[pos_vl].begin() + nrow, 
                        tmp_val_refv[pos_vl].end());
        tmp_val_refv[pos_vl].shrink_to_fit();
      };
      dbl_v.shrink_to_fit();
    };

    void transform_group_by(std::vector<unsigned int> &x,
                            std::string sumcolname = "n") {
      std::unordered_map<std::string, unsigned int> lookup;
      std::vector<unsigned int> occ_v;
      std::vector<std::string> occ_v_str;
      occ_v_str.reserve(nrow);
      occ_v.reserve(nrow);
      std::string key;
      std::vector<std::string> key_vec(nrow);
      unsigned int i;
      unsigned int i2;
      for (i = 0; i < nrow; i += 1) {
        key = tmp_val_refv[x[0]][i];
        for (i2 = 1; i2 < x.size(); i2 += 1) {
          key += tmp_val_refv[x[i2]][i];
        };
        lookup[key] += 1;
        key_vec[i] = key;
      };
      unsigned int occ_val;
      for (auto& el : key_vec) {
        occ_val = lookup[el];
        occ_v.push_back(occ_val);
        occ_v_str.push_back(std::to_string(occ_val));
      };
      uint_v.insert(uint_v.end(), occ_v.begin(), occ_v.end());
      tmp_val_refv.push_back(occ_v_str);
      if (name_v.size() > 0) {
        name_v.push_back(sumcolname);
      };
      type_refv.push_back('u');
      ncol += 1;
      longest_determine();
    };

    void pivot_int(Dataframe &obj, unsigned int &n1, unsigned int& n2, unsigned int& n3) {
      const std::vector<std::vector<std::string>>& tmp = obj.get_tmp_val_refv();
      const std::vector<std::string>& col_vec = tmp[n1];
      const std::vector<std::string>& row_vec = tmp[n2];
      const unsigned int& nrow2 = obj.get_nrow();
      const std::vector<std::vector<unsigned int>>& matr_idx2 = obj.get_matr_idx();
      unsigned int i = 0;
      unsigned int pos_val;
      const std::vector<int>& cur_int_v = obj.get_int_vec();

      std::vector<int> tmp_int_v = {};

      std::unordered_map<std::pair<std::string_view, std::string_view>, int, PairHash> lookup;

      std::string key;
      for (auto& el : matr_idx2[3]) {
        if (n3 == el) {
          pos_val = nrow2 * i;
          tmp_int_v.insert(tmp_int_v.end(), 
                          cur_int_v.begin() + pos_val, 
                          cur_int_v.begin() + pos_val + nrow2);
        };
        i += 1;
      };
      std::unordered_map<std::string, int> idx_col;
      std::unordered_map<std::string, int> idx_row;

      for (i = 0; i < nrow2; i += 1) {
        key = col_vec[i];
        if (!idx_col.contains(key)) {
          idx_col[key] = idx_col.size();
        };
        key = row_vec[i];
        if (!idx_row.contains(key)) {
          idx_row[key] = idx_row.size();
        };
        lookup[{col_vec[i], row_vec[i]}] += tmp_int_v[i];
      };
      ncol = idx_row.size();
      nrow = idx_col.size();
      int_v.resize(ncol * nrow);

      std::vector<std::string> cur_vec_str(idx_row.size());
      tmp_val_refv.resize(ncol, cur_vec_str);
     
      int cur_int;      
      for (const auto& [key_v, value] : idx_col) {
        for (const auto& [key_v2, value2] : idx_row) {
          auto key_pair = std::pair<std::string_view, std::string_view> {key_v, key_v2};
          if (lookup.contains(key_pair)) {
            cur_int = lookup[key_pair];
            int_v[value * nrow + value2] = cur_int;
            tmp_val_refv[value][value2] = std::to_string(cur_int);
          };
        };
      };
      name_v.resize(idx_col.size());
      i = 0;
      matr_idx[3].resize(ncol);
      for (auto& [key_v, value] : idx_col) {
        type_refv.push_back('i');
        name_v[value] = key_v;
        matr_idx[3][i] = i;
        i += 1;
      };
      name_v_row.resize(idx_row.size());
      for (auto& [key_v, value] : idx_row) {
        name_v_row[value] = key_v;
      };
      longest_determine();
    };

    void pivot_uint(Dataframe &obj, unsigned int &n1, unsigned int& n2, unsigned int& n3) {
      const std::vector<std::vector<std::string>>& tmp = obj.get_tmp_val_refv();
      const std::vector<std::string>& col_vec = tmp[n1];
      const std::vector<std::string>& row_vec = tmp[n2];
      const unsigned int& nrow2 = obj.get_nrow();
      const std::vector<std::vector<unsigned int>>& matr_idx2 = obj.get_matr_idx();
      unsigned int i = 0;
      unsigned int pos_val;
      const std::vector<unsigned int>& cur_uint_v = obj.get_uint_vec();

      std::vector<unsigned int> tmp_uint_v = {};
      std::unordered_map<std::pair<std::string_view, std::string_view>, unsigned int, PairHash> lookup;
      std::string key;
      for (auto& el : matr_idx2[4]) {
        if (n3 == el) {
          pos_val = nrow2 * i;
          tmp_uint_v.insert(tmp_uint_v.end(), 
                          cur_uint_v.begin() + pos_val, 
                          cur_uint_v.begin() + pos_val + nrow2);
        };
        i += 1;
      };
      std::unordered_map<std::string, unsigned int> idx_col;
      std::unordered_map<std::string, unsigned int> idx_row;

      for (i = 0; i < nrow2; i += 1) {
        key = col_vec[i];
        if (!idx_col.contains(key)) {
          idx_col[key] = idx_col.size();
        };
        key = row_vec[i];
        if (!idx_row.contains(key)) {
          idx_row[key] = idx_row.size();
        };
        lookup[{ col_vec[i], row_vec[i] }] += tmp_uint_v[i];
      };
      ncol = idx_row.size();
      nrow = idx_col.size();
      uint_v.resize(ncol * nrow);

      std::vector<std::string> cur_vec_str(idx_row.size());
      tmp_val_refv.resize(ncol, cur_vec_str);
     
      unsigned int cur_uint;      
      for (const auto& [key_v, value] : idx_col) {
        for (const auto& [key_v2, value2] : idx_row) {
          auto key_pair = std::pair<std::string_view, std::string_view>{key_v, key_v2};
          if (lookup.contains(key_pair)) {
            cur_uint = lookup[key_pair];
            uint_v[value * nrow + value2] = cur_uint;
            tmp_val_refv[value][value2] = std::to_string(cur_uint);
          };
        };
      };
      name_v.resize(idx_col.size());
      i = 0;
      matr_idx[4].resize(ncol);
      for (auto& [key_v, value] : idx_col) {
        type_refv.push_back('u');
        name_v[value] = key_v;
        matr_idx[4][i] = i;
        i += 1;
      };
      name_v_row.resize(idx_row.size());
      for (auto& [key_v, value] : idx_row) {
        name_v_row[value] = key_v;
      };
      longest_determine();
    };

    void pivot_dbl(Dataframe &obj, unsigned int &n1, unsigned int& n2, unsigned int& n3) {
      const std::vector<std::vector<std::string>>& tmp = obj.get_tmp_val_refv();
      const std::vector<std::string>& col_vec = tmp[n1];
      const std::vector<std::string>& row_vec = tmp[n2];
      const unsigned int& nrow2 = obj.get_nrow();
      const std::vector<std::vector<unsigned int>>& matr_idx2 = obj.get_matr_idx();
      unsigned int i = 0;
      unsigned int pos_val;
      const std::vector<double>& cur_dbl_v = obj.get_dbl_vec();

      std::vector<double> tmp_dbl_v = {};

      std::unordered_map<std::pair<std::string_view, std::string_view>, double, PairHash> lookup;

      std::string key;
      for (auto& el : matr_idx2[4]) {
        if (n3 == el) {
          pos_val = nrow2 * i;
          tmp_dbl_v.insert(tmp_dbl_v.end(), 
                          cur_dbl_v.begin() + pos_val, 
                          cur_dbl_v.begin() + pos_val + nrow2);
        };
        i += 1;
      };
      std::unordered_map<std::string, unsigned int> idx_col;
      std::unordered_map<std::string, unsigned int> idx_row;

      for (i = 0; i < nrow2; i += 1) {
        key = col_vec[i];
        if (!idx_col.contains(key)) {
          idx_col[key] = idx_col.size();
        };
        key = row_vec[i];
        if (!idx_row.contains(key)) {
          idx_row[key] = idx_row.size();
        };
        lookup[{col_vec[i], row_vec[i]}] += tmp_dbl_v[i];
      };
      ncol = idx_row.size();
      nrow = idx_col.size();
      dbl_v.resize(ncol * nrow);

      std::vector<std::string> cur_vec_str(idx_row.size());
      tmp_val_refv.resize(ncol, cur_vec_str);
     
      double cur_dbl;
      for (const auto& [key_v, value] : idx_col) {
        for (const auto& [key_v2, value2] : idx_row) {
          auto key_pair = std::pair<std::string_view, std::string_view>{key_v, key_v2};
          if (lookup.contains(key_pair)) {
            cur_dbl = lookup[key_pair];
            dbl_v[value * nrow + value2] = cur_dbl;
            tmp_val_refv[value][value2] = std::to_string(cur_dbl);
          };
        };
      };
      name_v.resize(idx_col.size());
      i = 0;
      matr_idx[4].resize(ncol);
      for (auto& [key_v, value] : idx_col) {
        type_refv.push_back('d');
        name_v[value] = key_v;
        matr_idx[4][i] = i;
        i += 1;
      };
      name_v_row.resize(idx_row.size());
      for (auto& [key_v, value] : idx_row) {
        name_v_row[value] = key_v;
      };
      longest_determine();
    };

    void set_colname(std::vector<std::string> &x) {
      if (x.size() != ncol) {
        std::cout << "the number of columns of the dataframe does not correspond to the size of the input column name vector";
        return;
      } else {
        name_v = x;
      };
    };

    void set_rowname(std::vector<std::string> &x) {
      if (x.size() != nrow) {
        std::cout << "the number of columns of the dataframe does not correspond to the size of the input column name vector";
        return;
      } else {
        name_v_row = x;
      };
    };

    const std::vector<std::string>& get_colname() const {
      return name_v;
    };

    const std::vector<std::string>& get_rowname() const {
      return name_v_row;
    };

    const std::vector<char>& get_typecol() const {
      return type_refv;
    };

    Dataframe() {};

    ~Dataframe() {};

};

#if 0

//@T Dataframe.readf
//@U template<unsigned int strt_row = 0, unsigned int end_row = 0>
//@U void readf(std::string &file_name, char delim = ',', bool header_name = 1, char str_context_begin = '\'', char str_context_end = '\'')
//@X
//@D Import a csv as a Dataframe object.
//@A file_name : is the file_name of the csv to read
//@A delim : is the column delimiter
//@A header_name : is if the first row is in fact the column names
//@A str_context_begin : is the first symbol of a quote, (to not take in count a comma as a new column if it is in a quote for example)
//@A str_context_end : is the end symbol for a quote context
//@A strt_row : is the first row to read, defaults to 0
//@A end_row : is the last row to read, defaults to max (value of 0)
//@X
//@E Dataframe obj1;
//@E std::string file_name = "teste_dataframe.csv";
//@E obj1.readf<3, 8>(file_name); reads from the 3thrd to the 8nth row
//@X

//@T Dataframe.readf_trim
//@U template<unsigned int strt_row = 0, unsigned int end_row = 0>
//@U void readf_trim(std::string &file_name, char delim = ',', bool header_name = 1, char str_context_begin = '\'', char str_context_end = '\'')
//@X
//@D Import a csv as a Dataframe object. Automatically trim the value (removes extra spaces before and after)
//@A file_name : is the file_name of the csv to read
//@A delim : is the column delimiter
//@A header_name : is if the first row is in fact the column names
//@A str_context_begin : is the first symbol of a quote, (to not take in count a comma as a new column if it is in a quote for example)
//@A str_context_end : is the end symbol for a quote context
//@A strt_row : is the first row to read, defaults to 0
//@A end_row : is the last row to read, defaults to max (value of 0)
//@X
//@E Dataframe obj1;
//@E std::string file_name = "teste_dataframe2.csv";
//@E obj1.readf_trim<0, 8>(file_name); // reads until the 8nth row
//@X

//@T Dataframe.readf_lambda
//@U template<unsigned int strt_row = 0, unsigned int end_row = 0>
//@U void readf_lambda(std::string &file_name, void (&f)(std::string&), char delim = ',', bool header_name = 1, char str_context_begin = '\'', char str_context_end = '\'')
//@X
//@D Import a csv as a Dataframe object. Applies a custom function to all values from the csv before parsing it as appropriate data types.
//@A file_name : is the file_name of the csv to read
//@A f : is your custom function (void, must take a std:string as argument)
//@A delim : is the column delimiter
//@A header_name : is if the first row is in fact the column names
//@A str_context_begin : is the first symbol of a quote, (to not take in count a comma as a new column if it is in a quote for example)
//@A str_context_end : is the end symbol for a quote context
//@A strt_row : is the first row to read, defaults to 0
//@A end_row : is the last row to read, defaults to max (value of 0)
//@X
//@E void myfunc (std::string &x) {
//@E   x.push_back('L');
//@E };
//@E Dataframe obj1;
//@E std::string file_name = "teste_dataframe2.csv";
//@E obj1.readf_lambda<3, 0>(file_name, myfunc); // reads from the thirs row
//@X

//@T Dataframe.readf_alrd
//@U template<unsigned int strt_row = 0, unsigned int end_row = 0>
//@U void readf_alrd(std::string &file_name, std::vector&lt;string&gt;& dtype, char delim = ',', bool header_name = 1, char str_context_begin = '\'', char str_context_end = '\'')
//@X
//@D Import a csv as a Dataframe object. This function only makes sense if you know in advance the column data types (faster than semantical analysis). The column data types are contiguously described in <code>dtype</code> argument. The values are 's' (string), 'c' (char), 'b' (bool), 'i' (int), 'u' (unsigned int) and 'd' (double)
//@A file_name : is the file_name of the csv to read
//@A dtype : is the string vector containing all column data types
//@A f : is your custom function (void, must take a std:string as argument)
//@A delim : is the column delimiter
//@A header_name : is if the first row is in fact the column names
//@A str_context_begin : is the first symbol of a quote, (to not take in count a comma as a new column if it is in a quote for example)
//@A str_context_end : is the end symbol for a quote context
//@A strt_row : is the first row to read, defaults to 0
//@A end_row : is the last row to read, defaults to max (value of 0)
//@X
//@E std::string dvec = "dsusic";
//@E Dataframe obj1;
//@E std::string file_name = "teste_dataframe2.csv";
//@E obj1.readf_lambda(file_name, dvec); //reads the entire file
//@X

//@T Dataframe.writef
//@U void writef(std::string &file_name, char delim = ',', bool header_name = 1, char str_context_bgn = '\'', char str_context_end = '\'')
//@X
//@D Write a dataframe object into a csv file.
//@A file_name : is the file name to write data into
//@A delim : is the column delimiter
//@A header_name : 1 to write the column names, 0 else
//@A str_context_begin : is the first symbol of a quote, (to not take in count a comma as a new column if it is in a quote for example)
//@A str_context_end : is the end symbol for a quote context
//@X
//@E // after reading teste_dataframe.csv as obj1
//@E std::string out_file = "out.csv";
//@E obj1.writef(out_file);
//@X

//@T Dataframe.display
//@U void display();
//@X
//@D Print the current dataframe.
//@A no : no
//@X
//@E // after reading teste_dataframe.csv as obj1
//@E obj1.display();
//@E &lt;uint&gt; &lt;uint&gt; &lt;uint&gt; &lt;str&gt; &lt;int&gt; &lt;char&gt;
//@E col1 col2 col3 col4 col5 col6
//@E :0:  1    2    3    aa   5    z
//@E :1:  6    7    8    bb   10   e
//@E :2:  1    2    3    cc   5    h
//@E :3:  6    7    8    uu   10   a
//@E :4:  1    2    3    s4   -5   q
//@E :5:  6    7    8    s9   10   p
//@E :6:  1    2    3    a4   5    j
//@E :7:  6    7    8    m9   10   i
//@E :8:  6    7    8    s9   10   p
//@E :9:  1    2    3    a4   5    j
//@E :10: 6    7    8    m9   10   i
//@E :11: 6    7    8    m9   10   i
//@E :12: 6    7    8    s9   10   p
//@E :13: 1    2    3    a4   5    j
//@E :14: 6    7    8    m9   10   i
//@M img_dataframe.jpg
//@X

//@T Dataframe.display_filter
//@U void display_filter(std::vector&lt;bool&gt; &x, std::vector&lt;int&gt; &colv)
//@X
//@D Print the current dataframe. Works seemlessly with <code>Dataframe.view_colnb()</code> to efficiently create boolean vector to filter rows, see example.
//@A x : is the boolean vector filtering the rows to display
//@A colv : is the int vector representing the column index of the column to keep, <code>{-1}</code> to keep all columns
//@X
//@E // after reading teste_dataframe.csv as obj1
//@E
//@E unsigned int n = 1;
//@E
//@E std::vector&lt;int&gt; cols = {-1};
//@E
//@E auto col = obj1.view_colnb(n);
//@E
//@E std::vector&lt;bool&gt; mask; 
//@E
//@E std::visit([&mask](auto&& span) {
//@E     mask.resize(span.size());
//@E     for (size_t i = 0; i &lt; span.size(); ++i)
//@E         mask[i] = span[i] &gt; 3;
//@E }, col);
//@E 
//@E obj1.display_filter(mask, cols);
//@E
//@E     &lt;uint&gt; &lt;uint&gt; &lt;uint&gt; &lt;str&gt; &lt;int&gt; &lt;char&gt;
//@E     col1   col2   col3   col4  col5  col6
//@E :1:  6      7      8      bb    10    e
//@E :3:  6      7      8      uu    10    a
//@E :5:  6      7      8      s9    10    p
//@E :7:  6      7      8      m9    10    i
//@E :8:  6      7      8      s9    10    p
//@E :10: 6      7      8      m9    10    i
//@E :11: 6      7      8      m9    10    i
//@E :12: 6      7      8      s9    10    p
//@E :14: 6      7      8      m9    10    i
//@X

//@T Dataframe.display_filter_idx
//@U void display_filter_idx(std::vector&lt;int&gt; &x, std::vector&lt;int&gt; &colv)
//@X
//@D Print the current dataframe. Works seemlessly with <code>Dataframe.view_colnb()</code> to efficiently create an int vector to filter rows, see example.
//@A x : is the int vector filtering the rows to display, the vector length is not forced to match the dataframe row number. <code>{-1}</code> to keep all rows in default order
//@A colv : is the int vector representing the column index of the column to keep, <code>{-1}</code> to keep all columns
//@X
//@E
//@E  Dataframe obj1;
//@E  std::string fname = "csv_test/outb.csv";
//@E  obj1.readf&lt;3, 0&gt;(fname);
//@E  obj1.display();
//@E     &lt;str&gt; &lt;uint&gt; &lt;uint&gt; &lt;uint&gt; &lt;str&gt;
//@E     col1  col2   col3   col4   col5
//@E :0:  id4   6      7      8      uu
//@E :1:  id5   1      2      3      s4
//@E :2:  id6   6      7      8      s9
//@E :3:  id7   1      2      3      a4
//@E :4:  id8   6      7      8      m9
//@E :5:  id9   6      7      8      s9
//@E :6:  id10  1      2      3      a4
//@E :7:  id11  6      7      8      m9
//@E :8:  id12  6      7      8      m9
//@E :9:  id13  6      7      8      s9
//@E :10: id14  1      2      3      NA
//@E :11: id15  16     7      8      m9
//@E  std::vector&lt;int&gt; rvec = {3, 2, 5, 3, 6, 7, 6, 5, 8, 9, 11, 10};
//@E  std::vector&lt;int&gt; cvec = {-1};
//@E  obj1.display_filter_idx(rvec, cvec);
//@E
//@E     &lt;str&gt; &lt;uint&gt; &lt;uint&gt; &lt;uint&gt; &lt;str&gt;
//@E     col1  col2   col3   col4   col5
//@E :0:  id7   1      2      3      a4
//@E :1:  id6   6      7      8      s9
//@E :2:  id9   6      7      8      s9
//@E :3:  id7   1      2      3      a4
//@E :4:  id10  1      2      3      a4
//@E :5:  id11  6      7      8      m9
//@E :6:  id10  1      2      3      a4
//@E :7:  id9   6      7      8      s9
//@E :8:  id12  6      7      8      m9
//@E :9:  id13  6      7      8      s9
//@E :10: id15  16     7      8      m9
//@E :11: id14  1      2      3      NA
//@X

//@T Dataframe.get_dataframe
//@U void get_dataframe(std::vector&lt;int&gt; &cols, Dataframe &cur_obj)
//@X
//@D Allow to copy a dataframe choosing columns (by index) of the copied dataframe. 
//@A cols : is the vector of the index of the columns to copy (<code>{-1}</code>) for all
//@A cur_obj : is the dataframe that will contain all the rows and columns of the copied dataframe
//@X
//@E // after reading teste_dataframe.csv as obj1
//@E Dataframe obj2;
//@E std::vector&lt;int&gt; idx_cols2 = {1, 2, 3};
//@E obj2.get_dataframe(idx_cols2, obj1);
//@E 
//@E obj2.display();
//@E     col1 col2 col3
//@E :0:  2    3    aa
//@E :1:  7    8    bb
//@E :2:  2    3    cc
//@E :3:  7    8    uu
//@E :4:  2    3    s4
//@E :5:  7    8    s9
//@E :6:  2    3    a4
//@E :7:  7    8    m9
//@E :8:  7    8    s9
//@E :9:  2    3    a4
//@E :10: 7    8    m9
//@E :11: 7    8    m9
//@E :12: 7    8    s9
//@E :13: 2    3    a4
//@E :14: 7    8    m9
//@X

//@T Dataframe.get_dataframe_filter
//@U void get_dataframe_filter(std::vector&lt;int&gt; &cols, Dataframe &cur_obj, std::vector&lt;bool&gt; &mask)
//@X
//@D Allow to copy a dataframe choosing columns (by index) of the copied dataframe, while applying a mask on the desired rows. 
//@A cols : is the vector of the index of the columns to copy (<code>{-1}</code>) for all
//@A cur_obj : is the dataframe that will contain all the rows and columns of the copied dataframe
//@A mask : is the boolean mask vector
//@X
//@E // after reading teste_dataframe.csv as obj1
//@E unsigned int n = 3;
//@E auto vec = obj1.view_colnb(n);
//@E std::vector&lt;bool&gt; vmask = {};
//@E std::visit([&vmask](auto&& span) {
//@E     vmask.resize(span.size());
//@E     for (size_t i = 0; i &lt; span.size(); ++i)
//@E         vmask[i] = span[i] &gt; 4;
//@E }, vec);
//@E Dataframe obj2;
//@E std::vector&lt;int&gt; idx_cols2 = {1, 2, 3};
//@E obj2.get_dataframe_filter(idx_cols2, obj1, vmask);
//@E 
//@E obj2.display();
//@E     col1 col2 col3
//@E :1:  7    8    bb
//@E :3:  7    8    uu
//@E :5:  7    8    s9
//@E :7:  7    8    m9
//@E :8:  7    8    s9
//@E :10: 7    8    m9
//@E :11: 7    8    m9
//@E :12: 7    8    s9
//@E :14: 7    8    m9
//@X

//@T Dataframe.get_dataframe_filter_idx
//@U void get_dataframe_filter_idx(std::vector&lt;int&gt; &cols, Dataframe &cur_obj, std::vector&lt;int&gt; &mask)
//@X
//@D Allow to copy a dataframe choosing columns (by index) of the copied dataframe, while applying an index mask on the desired rows. 
//@A cols : is the vector of the index of the columns to copy (<code>{-1}</code>) for all
//@A cur_obj : is the dataframe that will contain all the rows and columns of the copied dataframe
//@A mask : is the index mask vector, <code>{-1}</code> to keep all rows
//@X
//@E 
//@E   Dataframe obj1, obj2, obj3;
//@E   std::string fname = "csv_test/outb.csv";
//@E   obj1.readf&lt;3, 0&gt;(fname);
//@E   obj1.display();
//@E
//@E     &lt;str&gt; &lt;uint&gt; &lt;uint&gt; &lt;uint&gt; &lt;str&gt;
//@E     col1  col2   col3   col4   col5
//@E :0:  id4   6      7      8      uu
//@E :1:  id5   1      2      3      s4
//@E :2:  id6   6      7      8      s9
//@E :3:  id7   1      2      3      a4
//@E :4:  id8   6      7      8      m9
//@E :5:  id9   6      7      8      s9
//@E :6:  id10  1      2      3      a4
//@E :7:  id11  6      7      8      m9
//@E :8:  id12  6      7      8      m9
//@E :9:  id13  6      7      8      s9
//@E :10: id14  1      2      3      NA
//@E :11: id15  16     7      8      m9
//@E
//@E   std::vector&lt;int&gt; rvec = {3, 2, 5, 3, 6, 7, 6, 5, 8, 9, 11, 10};
//@E   std::vector&lt;int&gt; cvec = {-1};
//@E   obj2.get_dataframe_filter_idx(cvec, obj1, rvec);
//@E   obj2.display();
//@E
//@E     &lt;str&gt; &lt;uint&gt; &lt;uint&gt; &lt;uint&gt; &lt;str&gt;
//@E     col1  col2   col3   col4   col5
//@E :0:  id7   1      2      3      a4
//@E :1:  id6   6      7      8      s9
//@E :2:  id9   6      7      8      s9
//@E :3:  id7   1      2      3      a4
//@E :4:  id10  1      2      3      a4
//@E :5:  id11  6      7      8      m9
//@E :6:  id10  1      2      3      a4
//@E :7:  id9   6      7      8      s9
//@E :8:  id12  6      7      8      m9
//@E :9:  id13  6      7      8      s9
//@E :10: id15  16     7      8      m9
//@E :11: id14  1      2      3      NA
//@E
//@X

//@T Dataframe.view_colnb
//@U using ColumnView = std::variant&lt;
//@U         std::span&lt;const int&gt;,
//@U         std::span&lt;const unsigned int&gt;,
//@U         std::span&lt;const double&gt;
//@U     &gt;;
//@U 
//@U     ColumnView view_colnb(unsigned int &x) const
//@X
//@D Allow to get the reference of a int, unsigned int or double column as a span&lt;T&gt;, by column index (>= C++ 20).
//@A rows : is a vector containing the row indices to copy (<code>{-1}</code>) for all. Intended to be used for creating boolean vecotr by your own functions, to maybe filter data later with <code>Dataframe.display_filter(), Dataframe.get_dataframe_filter(), Dataframe.get_col_filter, ...</code>
//@A x : is the index of the column to get the ref from
//@X
//@E // after reading teste_dataframe.csv as obj1
//@E unsigned int n = 1;
//@E 
//@E auto col = obj1.view_colnb(n);
//@X

//@T Dataframe.view_colstr
//@U std::span&lt;const std::string&gt; view_colstr(unsigned int &x) const 
//@X
//@D Allow to get the reference of a std::string column by column index.
//@A x : is the index of the column to get the ref from
//@X
//@E // after reading teste_dataframe.csv as obj1
//@E unsigned int n = 3;
//@E 
//@E auto col = obj1.view_colstr(n);
//@X

//@T Dataframe.view_colchr
//@U std::span&lt;const std::string&gt; view_colchr(unsigned int &x) const 
//@X
//@D Allow to get the reference of a char column by column index.
//@A x : is the index of the column to get the ref from
//@X
//@E // after reading teste_dataframe.csv as obj1
//@E unsigned int n = 5;
//@E 
//@E auto col = obj1.view_colchr(n);
//@X

//@T Dataframe.view_colint
//@U std::span&lt;const std::string&gt; view_colint(unsigned int &x) const 
//@X
//@D Allow to get the reference of an int column by column index.
//@A x : is the index of the column to get the ref from
//@X
//@E // after reading teste_dataframe.csv as obj1
//@E unsigned int n = 4;
//@E 
//@E auto col = obj1.view_colstr(n);
//@X

//@T Dataframe.view_coluint
//@U std::span&lt;const std::string&gt; view_coluint(unsigned int &x) const 
//@X
//@D Allow to get the reference of an uint column by column index.
//@A x : is the index of the column to get the ref from
//@X
//@E // after reading teste_dataframe.csv as obj1
//@E unsigned int n = 0;
//@E 
//@E auto col = obj1.view_colchr(n);
//@X

//@T Dataframe.view_coldbl
//@U std::span&lt;const std::string&gt; view_coldbl(unsigned int &x) const 
//@X
//@D Allow to get the reference of a double column by column index.
//@A x : is the index of the column to get the ref from
//@X
//@E // after reading teste_dataframe.csv as obj1
//@E unsigned int n = 1;
//@E 
//@E auto col = obj1.view_coldbl(n);
//@X

//@T Dataframe.get_col
//@U template &lt;typename T&gt;
//@U void get_col(unsigned int x, std::vector&lt;T&gt; &rtn_v)
//@X
//@D Allow to copy a column as a vector, by column index.
//@A x : is the index of the column to copy
//@A rtn_v : is the vector that will contain the column to copy
//@X
//@E // after reading teste_dataframe.csv as obj1
//@E std::vector&lt;std::string&gt; outv2 = {};
//@E obj1.get_col(3, outv2);
//@X

//@T Dataframe.get_col_filter
//@U template &lt;typename T&gt;
//@U void get_col_filter(unsigned int x, std::vector&lt;T&gt; &rtn_v, std::vector&lt;bool&gt; &mask)
//@X
//@D Allow to copy a column as a vector, by column index with a boolean vector mask to keep the desired lines.
//@A x : is the index of the column to copy
//@A rtn_v : is the vector that will contain the column to copy
//@X
//@E // after reading teste_dataframe.csv as obj1
//@E std::vector&lt;std::string&gt; outv2 = {};
//@E unsigned int n = 0;
//@E std::vector&lt;bool&gt; mask;
//@E unsigned int nrow = obj1.get_nrow();
//@E mask.reserve(nrow);
//@E auto vec = obj1.view_coluint(n);
//@E std::visit([&mask](auto&& span) {
//@E     mask.resize(span.size());
//@E     for (size_t i = 0; i &lt; span.size(); ++i)
//@E         mask[i] = span[i] &gt; 3;
//@E }, vec);
//@E obj1.get_col(3, outv2, mask);
//@X

//@T Dataframe.fapply
//@U template &lt;typename T&gt;
//@U void fapply(void (&f)(T&), unsigned int &n)
//@X
//@D Apply whatever function to all elements of a column. See example
//@A f : is the function to apply
//@A n : is the column index
//@X
//@E 
//@E   obj1.display();
//@E
//@E     &lt;str&gt; &lt;uint&gt;
//@E     col1  col2
//@E :0:  id1   1
//@E :1:  id2   6
//@E :2:  id4   6
//@E :3:  id5   1
//@E :4:  id6   6
//@E :5:  id7   1
//@E :6:  id8   6
//@E :7:  id9   6
//@E :8:  id11  6
//@E :9:  id12  6
//@E :10: id14  1
//@E :11: id15  16
//@E 
//@E   unsigned int n = 1;
//@E   obj1.fapply(mfunc, n);
//@E 
//@E   obj1.display();
//@E
//@E     &lt;str&gt; &lt;uint&gt;
//@E     col1  col2
//@E :0:  id1   2
//@E :1:  id2   7
//@E :2:  id4   7
//@E :3:  id5   2
//@E :4:  id6   7
//@E :5:  id7   2
//@E :6:  id8   7
//@E :7:  id9   7
//@E :8:  id11  7
//@E :9:  id12  7
//@E :10: id14  2
//@E :11: id15  17
//@E
//@X

//@T Dataframe.get_nrow
//@U unsigned int get_nrow();
//@X
//@D Returns the number of rows for the associated dataframe.
//@E // after reading teste_dataframe.csv as obj1
//@E unsigned int nrow = obj1.get_nrow();
//@E 15
//@X

//@T Dataframe.get_ncol
//@U unsigned int get_ncol();
//@X
//@D Returns the number of columns for the associated dataframe.
//@E // after reading teste_dataframe.csv as obj1
//@E unsigned int ncol = obj1.get_ncol();
//@E 6
//@X

//@T Dataframe.get_rowname
//@U std::vector&lt;std::string&gt; get_rowname();
//@X
//@D Returns the rowname of the associated dataframe.
//@E // after reading teste_dataframe.csv as obj1
//@E std::vector&lt;std::string&gt; row_names = obj1.get_rowname();
//@E nothing becuase obj1 has no rownames
//@X

//@T Dataframe.get_colname
//@U std::vector&lt;std::string&gt; get_colname();
//@X
//@D Returns the colname of the associated dataframe.
//@E // after reading teste_dataframe.csv as obj1
//@E std::vector&lt;std::string&gt; col_names = obj1.get_colname();
//@E col1 col2 col3 col4 col5 col6
//@X

//@T Dataframe.set_rowname
//@U void set_rowname(std::vector&lt;std::string&gt; &x);
//@X
//@D Set rowname to the associated dataframe.
//@E // after reading teste_dataframe.csv as obj1
//@E std::vector&lt;std::string&gt; row_names = {"n1", "n2", "n3"..."n15"};
//@E obj1.set_rowname(row_names);
//@X

//@T Dataframe.set_colname
//@U void set_colname(std::vector&lt;std::string&gt; &x);
//@X
//@D Set colname to the associated dataframe.
//@E // after reading teste_dataframe.csv as obj1
//@E std::vector&lt;std::string&gt; col_names = {"col1", "col2", "col3", "col4", 
//@E "col5", "col6"};
//@E obj1.set_colname();
//@X

//@T Dataframe.replace_col
//@U template &lt;typename T&gt; void replace_col(std::vector&lt;T&gt; &x, unsigned int &colnb)
//@X
//@D Replace a column of the associated dataframe.
//@A x : is the column (as vector) that will replace the dataframe column
//@A colnb : is the index of the column to replace
//@X
//@E // after reading teste_dataframe.csv as obj1
//@E 
//@E std::vector&lt;unsigned int&gt; rpl_col = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 
//@E                                       10, 11, 12, 13, 14};
//@E unsigned int col = 0;
//@E obj1.replace_col(rpl_col, col);
//@E obj1.display();
//@E      &lt;uint&gt; &lt;uint&gt; &lt;uint&gt; &lt;str&gt; &lt;int&gt; &lt;char&gt;
//@E      col1   col2   col3   col4  col5  col6
//@E  :0:  0      2      3      aa    5     z
//@E  :1:  1      7      8      bb    10    e
//@E  :2:  2      2      3      cc    5     h
//@E  :3:  3      7      8      uu    10    a
//@E  :4:  4      2      3      s4    -5    q
//@E  :5:  5      7      8      s9    10    p
//@E  :6:  6      2      3      a4    5     j
//@E  :7:  7      7      8      m9    10    i
//@E  :8:  8      7      8      s9    10    p
//@E  :9:  9      2      3      a4    5     j
//@E  :10: 10     7      8      m9    10    i
//@E  :11: 11     7      8      m9    10    i
//@E  :12: 12     7      8      s9    10    p
//@E  :13: 13     2      3      NA    5     j
//@E  :14: 14     7      8      m9    10    i
//@X

//@T Dataframe.add_col
//@U template &lt;typename T&gt; void add_col(std::vector&lt;T&gt; &x, std::string name = "NA")
//@X
//@D Add a column int, unsigned int, bool, double, char or string type to the associated dataframe
//@A x : is the column to add
//@A name : is the column to add name
//@X
//@E // after reading teste_dataframe.csv as obj1
//@E std::vector&lt;unsigned int&gt; rpl_col = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 
//@E                                       10, 11, 12, 13, 14};
//@E obj1.add_col(rpl_col);
//@E obj1.display();
//@E     &lt;uint&gt; &lt;uint&gt; &lt;uint&gt; &lt;str&gt; &lt;int&gt; &lt;char&gt; &lt;uint&gt;
//@E     col1   col2   col3   col4  col5  col6   NA
//@E :0:  1      2      3      aa    5     z      0
//@E :1:  6      7      8      bb    10    e      1
//@E :2:  1      2      3      cc    5     h      2
//@E :3:  6      7      8      uu    10    a      3
//@E :4:  1      2      3      s4    -5    q      4
//@E :5:  6      7      8      s9    10    p      5
//@E :6:  1      2      3      a4    5     j      6
//@E :7:  6      7      8      m9    10    i      7
//@E :8:  6      7      8      s9    10    p      8
//@E :9:  1      2      3      a4    5     j      9
//@E :10: 6      7      8      m9    10    i      10
//@E :11: 6      7      8      m9    10    i      11
//@E :12: 6      7      8      s9    10    p      12
//@E :13: 1      2      3      NA    5     j      13
//@E :14: 6      7      8      m9    10    i      14
//@X

//@T Dataframe.rm_col
//@U void rm_col(std::vector&lt;unsigned int&gt; &nbcolv)
//@X
//@D Removes columns from associated dataframe.
//@A nbcolv : is a vector containing all the indices of the columns to erase from the associated dataframe. The indices must be sorted descendly.
//@X
//@E // after reading teste_dataframe.csv as obj1
//@E std::vector&lt;unsigned int&gt; colv = {4, 1};
//@E obj1.rm_col(colv);
//@E obj1.display();
//@E     &lt;uint&gt; &lt;uint&gt; &lt;str&gt;  &lt;char&gt;
//@E     col1   col3   col4   col6
//@E :0:  1      3      aa     z
//@E :1:  6      8      bb     e
//@E :2:  1      3      cc     h
//@E :3:  6      8      uu     a
//@E :4:  1      3      s4     q
//@E :5:  6      8      s9     p
//@E :6:  1      3      a4     j
//@E :7:  6      8      m9     i
//@E :8:  6      8      s9     p
//@E :9:  1      3      a4     j
//@E :10: 6      8      m9     i
//@E :11: 6      8      m9     i
//@E :12: 6      8      s9     p
//@E :13: 1      3      NA     j
//@E :14: 6      8      m9     i
//@X

//@T Dataframe.rm_row
//@U void rm_col(std::vector&lt;unsigned int&gt; &nbcolv)
//@X
//@D Removes rows from associated dataframe.
//@A nbcolv : is a vector containing all the indices of the rows to erase from the associated dataframe. The indices must be sorted descendly.
//@X
//@E // after reading teste_dataframe.csv as obj1
//@E std::vector&lt;unsigned int&gt; rowv = {4, 1};
//@E obj1.rm_row(rowv);
//@E obj1.display();
//@E     &lt;uint&gt; &lt;uint&gt; &lt;uint&gt; &lt;str&gt; &lt;int&gt; &lt;char&gt;
//@E     col1   col2   col3   col4  col5  col6
//@E :0:  1      2      3      aa    5     z
//@E :1:  1      2      3      cc    5     h
//@E :2:  6      7      8      uu    10    a
//@E :3:  6      7      8      s9    10    p
//@E :4:  1      2      3      a4    5     j
//@E :5:  6      7      8      m9    10    i
//@E :6:  6      7      8      s9    10    p
//@E :7:  1      2      3      a4    5     j
//@E :8:  6      7      8      m9    10    i
//@E :9:  6      7      8      m9    10    i
//@E :10: 6      7      8      s9    10    p
//@E :11: 1      2      3      NA    5     j
//@E :12: 6      7      8      m9    10    i
//@X

//@T Dataframe.transform_inner
//@U void transform_inner(Dataframe &cur_obj, unsigned int &in_col, unsigned int &ext_col)
//@X
//@D Applies a inner join on the associated dataframe.
//@A cur_obj : is the other dataframe used for inner join
//@A in_col : is the index of the column representing the key (primary) of the associated dataframe
//@A ext_col : is the index of the column representing the key (foreign) of the other dataframe used for the inner join
//@X
//@E
//@E Dataframe obj1, obj2;
//@E std::string filename = "outb.csv";
//@E obj1.readf(filename);
//@E 
//@E std::vector&lt;unsigned int&gt; colv = {4, 3, 2};
//@E obj1.rm_col(colv);
//@E 
//@E std::string f2 = "outb2.csv";
//@E obj2.readf(f2);
//@E 
//@E unsigned int col1 = 0;
//@E unsigned int col2 = 0;
//@E 
//@E obj1.transform_inner(obj2, col1, col2);
//@E obj1.display();
//@E  &lt;str&gt; &lt;uint&gt;
//@E     col1  col2
//@E :0:  id1   1
//@E :1:  id2   6
//@E :2:  id4   6
//@E :3:  id5   1
//@E :4:  id6   6
//@E :5:  id7   1
//@E :6:  id8   6
//@E :7:  id9   6
//@E :8:  id11  6
//@E :9:  id12  6
//@E :10: id14  1
//@E :11: id15  6
//@X

//@T Dataframe.transform_inner_clean
//@U void transform_inner_clean(Dataframe &cur_obj, unsigned int &in_col, unsigned int &ext_col)
//@X
//@D Applies a inner join on the associated dataframe. Is basically the same as transform_inner but uses another algorithm that takes more time but frees memory after having kept the common elements.
//@A cur_obj : is the other dataframe used for inner join
//@A in_col : is the index of the column representing the key (primary) of the associated dataframe
//@A ext_col : is the index of the column representing the key (foreign) of the other dataframe used for the inner join
//@X
//@E
//@E Dataframe obj1, obj2;
//@E std::string filename = "outb.csv";
//@E obj1.readf(filename);
//@E 
//@E std::vector&lt;unsigned int&gt; colv = {4, 3, 2};
//@E obj1.rm_col(colv);
//@E 
//@E std::string f2 = "outb2.csv";
//@E obj2.readf(f2);
//@E 
//@E unsigned int col1 = 0;
//@E unsigned int col2 = 0;
//@E 
//@E obj1.transform_inner_clean(obj2, col1, col2);
//@E obj1.display();
//@E  &lt;str&gt; &lt;uint&gt;
//@E     col1  col2
//@E :0:  id1   1
//@E :1:  id2   6
//@E :2:  id4   6
//@E :3:  id5   1
//@E :4:  id6   6
//@E :5:  id7   1
//@E :6:  id8   6
//@E :7:  id9   6
//@E :8:  id11  6
//@E :9:  id12  6
//@E :10: id14  1
//@E :11: id15  6
//@X

//@T Dataframe.transform_excluding
//@U void transform_excluding(Dataframe &cur_obj, unsigned int &in_col, unsigned int &ext_col)
//@X
//@D Applies an excluding join on the associated dataframe.
//@A cur_obj : is the other dataframe used for inner join
//@A in_col : is the index of the column representing the key (primary) of the associated dataframe
//@A ext_col : is the index of the column representing the key (foreign) of the other dataframe used for the inner join
//@X
//@E
//@E Dataframe obj1, obj2;
//@E std::string filename = "outb.csv";
//@E obj1.readf(filename);
//@E 
//@E std::vector&lt;unsigned int&gt; colv = {4, 3, 2};
//@E obj1.rm_col(colv);
//@E 
//@E std::string f2 = "outb2.csv";
//@E obj2.readf(f2);
//@E 
//@E unsigned int col1 = 0;
//@E unsigned int col2 = 0;
//@E 
//@E obj1.transform_excluding(obj2, col1, col2);
//@E obj1.display();
//@E  &lt;str&gt; &lt;uint&gt;
//@E     col1  col2
//@E    col1  col2   col3   col4   col5
//@E :0: id3   1      2      3      cc
//@E :1: id10  1      2      3      a4
//@E :2: id13  6      7      8      s9
//@X

//@T Dataframe.transform_excluding_clean
//@U void transform_excluding_clean(Dataframe &cur_obj, unsigned int &in_col, unsigned int &ext_col)
//@X
//@D Applies an excluding join on the associated dataframe. Is basically the same as transform_excluding but uses another algorithm that takes more time but frees memory after having kept the common elements.
//@A cur_obj : is the other dataframe used for inner join
//@A in_col : is the index of the column representing the key (primary) of the associated dataframe
//@A ext_col : is the index of the column representing the key (foreign) of the other dataframe used for the inner join
//@X
//@E
//@E Dataframe obj1, obj2;
//@E std::string filename = "outb.csv";
//@E obj1.readf(filename);
//@E 
//@E std::vector&lt;unsigned int&gt; colv = {4, 3, 2};
//@E obj1.rm_col(colv);
//@E 
//@E std::string f2 = "outb2.csv";
//@E obj2.readf(f2);
//@E 
//@E unsigned int col1 = 0;
//@E unsigned int col2 = 0;
//@E 
//@E obj1.transform_excluding_clean(obj2, col1, col2);
//@E obj1.display();
//@E  &lt;str&gt; &lt;uint&gt;
//@E     col1  col2
//@E    col1  col2   col3   col4   col5
//@E :0: id3   1      2      3      cc
//@E :1: id10  1      2      3      a4
//@E :2: id13  6      7      8      s9
//@X

//@T Dataframe.merge_inner
//@U void merge_inner(Dataframe &obj1, Dataframe &obj2, bool colname, unsigned int &key1, unsigned int &key2)
//@X
//@D Performs a inner join on a newly created dataframe. May creates dupplicates if multiple occurences of the key is found in the second dataframes, use Dataframe.merge_inner2 if you do not want to create dupplicates.
//@A obj1 : is the first dataframe
//@A obj2 : is the second dataframe
//@A colname : 1 to give the column names to the newly created dataframe
//@A key1 : is the index of the first dataframe column as primary key
//@A key1 : is the index of the first dataframe column as foreign key
//@X
//@E 
//@E Dataframe obj1, obj2, obj3;
//@E std::string filename = "csv_test/outb.csv";
//@E obj1.readf(filename);
//@E 
//@E std::string f2 = "csv_test/outb2.csv";
//@E obj2.readf(f2);
//@E 
//@E unsigned int col1 = 0;
//@E unsigned int col2 = 0;
//@E 
//@E obj3.merge_inner(obj1, obj2, 1, col1, col2);
//@E obj3.display();
//@E     &lt;str&gt; &lt;uint&gt; &lt;uint&gt; &lt;uint&gt; &lt;str&gt; &lt;str&gt; &lt;uint&gt; &lt;uint&gt;
//@E     [0]   [1]    [2]    [3]    [4]   [5]   [6]    [7]
//@E :0:  id1   1      2      3      aa    id1   2      3
//@E :1:  id1   1      2      3      aa    id1   2      3
//@E :2:  id2   6      7      8      bb    id2   7      8
//@E :3:  id4   6      7      8      uu    id4   7      8
//@E :4:  id5   1      2      3      s4    id5   2      3
//@E :5:  id6   6      7      8      s9    id6   7      8
//@E :6:  id7   1      2      3      a4    id7   2      3
//@E :7:  id8   6      7      8      m9    id8   2      3
//@E :8:  id9   6      7      8      s9    id9   7      8
//@E :9:  id11  6      7      8      m9    id11  7      8
//@E :10: id11  6      7      8      m9    id11  7      8
//@E :11: id12  6      7      8      m9    id12  7      8
//@E :12: id14  1      2      3      NA    id14  7      8
//@E :13: id15  16     7      8      m9    id15  2      3
//@X

//@T Dataframe.merge_inner2
//@U void merge_inner2(Dataframe &obj1, Dataframe &obj2, bool colname, unsigned int &key1, unsigned int &key2)
//@X
//@D Performs a inner join on a newly created dataframe.
//@A obj1 : is the first dataframe
//@A obj2 : is the second dataframe
//@A colname : 1 to give the column names to the newly created dataframe
//@A key1 : is the index of the first dataframe column as primary key
//@A key1 : is the index of the first dataframe column as foreign key
//@X
//@E 
//@E Dataframe obj1, obj2, obj3;
//@E std::string filename = "csv_test/outb.csv";
//@E obj1.readf(filename);
//@E 
//@E std::string f2 = "csv_test/outb2.csv";
//@E obj2.readf(f2);
//@E 
//@E unsigned int col1 = 0;
//@E unsigned int col2 = 0;
//@E 
//@E obj3.merge_inner2(obj1, obj2, 1, col1, col2);
//@E obj3.display();
//@E     &lt;str&gt; &lt;uint&gt; &lt;uint&gt; &lt;uint&gt; &lt;str&gt; &lt;str&gt; &lt;uint&gt; &lt;uint&gt;
//@E     [0]   [1]    [2]    [3]    [4]   [5]   [6]    [7]
//@E :0:  id1   1      2      3      aa    id1   2      3
//@E :1:  id2   6      7      8      bb    id2   7      8
//@E :2:  id4   6      7      8      uu    id4   7      8
//@E :3:  id5   1      2      3      s4    id5   2      3
//@E :4:  id6   6      7      8      s9    id6   7      8
//@E :5:  id7   1      2      3      a4    id7   2      3
//@E :6:  id8   6      7      8      m9    id8   2      3
//@E :7:  id9   6      7      8      s9    id9   7      8
//@E :8:  id11  6      7      8      m9    id11  7      8
//@E :9:  id12  6      7      8      m9    id12  7      8
//@E :10: id14  1      2      3      NA    id14  7      8
//@E :11: id15  16     7      8      m9    id15  2      3
//@X

//@T Dataframe.merge_excluding
//@U void merge_excluding(Dataframe &obj1, 
//@U                          Dataframe &obj2, 
//@U                          bool colname, 
//@U                          unsigned int &key1, 
//@U                          unsigned int &key2,
//@U                          std::string default_str = "NA",
//@U                          std::string default_chr = " ",
//@U                          std::string default_bool = "0",
//@U                          std::string default_int = "0",
//@U                          std::string default_uint = "0",
//@U                          std::string default_dbl = "0")
//@X
//@D Performs a left excluding join to the associated dataframe (newly created). The first dataframe as argument is considered as the left one.
//@A obj1 : is the left dataframe
//@A obj2 : is the right dataframe
//@A colname : 1 to give the column names to the newly created dataframe
//@A key1 : is the index of the column of the left dataframe
//@A key2 : is the index of the column of the right dataframe
//@X
//@E Dataframe obj1, obj2, obj3;
//@E std::string filename = "csv_test/outb.csv";
//@E obj1.readf(filename);
//@E 
//@E std::string f2 = "csv_test/outb2.csv";
//@E obj2.readf(f2);
//@E 
//@E unsigned int col1 = 0;
//@E unsigned int col2 = 0;
//@E 
//@E obj3.merge_excluding(obj1, obj2, 1, col1, col2);
//@E obj3.display();
//@E    &lt;str&gt; &lt;uint&gt; &lt;uint&gt; &lt;uint&gt; &lt;str&gt; &lt;str&gt; &lt;uint&gt; &lt;uint&gt;
//@E    [0]   [1]    [2]    [3]    [4]   [5]   [6]    [7]
//@E :0: id3   1      2      3      cc    NA    0      0
//@E :1: id10  1      2      3      a4    NA    0      0
//@E :2: id13  6      7      8      s9    NA    0      0
//@X

//@T Dataframe.merge_excluding_both
//@U void merge_excluding_both(Dataframe &obj1, 
//@U                               Dataframe &obj2, 
//@U                               bool colname, 
//@U                               unsigned int &key1, 
//@U                               unsigned int &key2,
//@U                               std::string default_str = "NA",
//@U                               std::string default_chr = " ",
//@U                               std::string default_bool = "0",
//@U                               std::string default_int = "0",
//@U                               std::string default_uint = "0",
//@U                               std::string default_dbl = "0")
//@X
//@D Performs a full excluding join to the associated dataframe (newly created). The first dataframe as argument is considered as the left one.
//@A obj1 : is the left dataframe
//@A obj2 : is the right dataframe
//@A colname : 1 to give the column names to the newly created dataframe
//@A key1 : is the index of the column of the left dataframe
//@A key2 : is the index of the column of the right dataframe
//@X
//@E Dataframe obj1, obj2, obj3;
//@E std::string filename = "csv_test/outb.csv";
//@E obj1.readf(filename);
//@E 
//@E std::string f2 = "csv_test/outb2.csv";
//@E obj2.readf(f2);
//@E 
//@E unsigned int col1 = 0;
//@E unsigned int col2 = 0;
//@E 
//@E obj3.merge_excluding_both(obj1, obj2, 1, col1, col2);
//@E obj3.display();
//@E    &lt;str&gt; &lt;uint&gt; &lt;uint&gt; &lt;uint&gt; &lt;str&gt; &lt;str&gt; &lt;uint&gt; &lt;uint&gt;
//@E    [0]   [1]    [2]    [3]    [4]   [5]   [6]    [7]
//@E :0: id3   1      2      3      cc    NA    0      0
//@E :1: id10  1      2      3      a4    NA    0      0
//@E :2: id13  6      7      8      s9    NA    0      0
//@E :3: NA    0      0      0      NA    id119 7      8
//@X

//@T Dataframe.merge_all
//@U void merge_all(Dataframe &obj1, 
//@U                     Dataframe &obj2, 
//@U                     bool colname, 
//@U                     unsigned int &key1, 
//@U                     unsigned int &key2,
//@U                     std::string default_str = "NA",
//@U                     std::string default_chr = " ",
//@U                     std::string default_bool = "0",
//@U                     std::string default_int = "0",
//@U                     std::string default_uint = "0",
//@U                     std::string default_dbl = "0") 
//@X
//@D Performs a full join to the associated dataframe (newly created). The first dataframe as argument is considered as the left one. May producesdupplicates if several occurences of the same key appears in the second dataframe, use Dataframe.merge_all2 if you do not want to create dupplicates.
//@A obj1 : is the left dataframe
//@A obj2 : is the right dataframe
//@A colname : 1 to give the column names to the newly created dataframe
//@A key1 : is the index of the column of the left dataframe
//@A key2 : is the index of the column of the right dataframe
//@X
//@E Dataframe obj1, obj2, obj3;
//@E std::string filename = "csv_test/outb.csv";
//@E obj1.readf(filename);
//@E 
//@E std::string f2 = "csv_test/outb2.csv";
//@E obj2.readf(f2);
//@E 
//@E unsigned int col1 = 0;
//@E unsigned int col2 = 0;
//@E 
//@E obj3.merge_all(obj1, obj2, 1, col1, col2);
//@E obj3.display();
//@E     &lt;str&gt; &lt;uint&gt; &lt;uint&gt; &lt;uint&gt; &lt;str&gt; &lt;str&gt; &lt;uint&gt; &lt;uint&gt;
//@E     [0]   [1]    [2]    [3]    [4]   [5]   [6]    [7]
//@E :0:  id1   1      2      3      aa    id1   2      3
//@E :1:  id1   1      2      3      aa    id1   22     3
//@E :2:  id2   6      7      8      bb    id2   7      8
//@E :3:  id3   1      2      3      cc    NA    0      0
//@E :4:  id4   6      7      8      uu    id4   7      8
//@E :5:  id5   1      2      3      s4    id5   2      3
//@E :6:  id6   6      7      8      s9    id6   7      8
//@E :7:  id7   1      2      3      a4    id7   2      3
//@E :8:  id8   6      7      8      m9    id8   2      3
//@E :9:  id9   6      7      8      s9    id9   7      8
//@E :10: id10  1      2      3      a4    NA    0      0
//@E :11: id11  6      7      8      m9    id11  7      8
//@E :12: id11  6      7      8      m9    id11  17     8
//@E :13: id12  6      7      8      m9    id12  7      8
//@E :14: id13  6      7      8      s9    NA    0      0
//@E :15: id14  1      2      3      NA    id14  7      8
//@E :16: id15  6      7      8      m9    id15  2      3
//@E :17: NA    NA     NA     NA     NA    id119 7      8
//@X

//@T Dataframe.merge_all2
//@U void merge_all2(Dataframe &obj1, 
//@U                     Dataframe &obj2, 
//@U                     bool colname, 
//@U                     unsigned int &key1, 
//@U                     unsigned int &key2,
//@U                     std::string default_str = "NA",
//@U                     std::string default_chr = " ",
//@U                     std::string default_bool = "0",
//@U                     std::string default_int = "0",
//@U                     std::string default_uint = "0",
//@U                     std::string default_dbl = "0") 
//@X
//@D Performs a full join to the associated dataframe (newly created). The first dataframe as argument is considered as the left one.
//@A obj1 : is the left dataframe
//@A obj2 : is the right dataframe
//@A colname : 1 to give the column names to the newly created dataframe
//@A key1 : is the index of the column of the left dataframe
//@A key2 : is the index of the column of the right dataframe
//@X
//@E Dataframe obj1, obj2, obj3;
//@E std::string filename = "csv_test/outb.csv";
//@E obj1.readf(filename);
//@E 
//@E std::string f2 = "csv_test/outb2.csv";
//@E obj2.readf(f2);
//@E 
//@E unsigned int col1 = 0;
//@E unsigned int col2 = 0;
//@E 
//@E obj3.merge_all2(obj1, obj2, 1, col1, col2);
//@E obj3.display();
//@E     &lt;str&gt; &lt;uint&gt; &lt;uint&gt; &lt;uint&gt; &lt;str&gt; &lt;str&gt; &lt;uint&gt; &lt;uint&gt;
//@E     [0]   [1]    [2]    [3]    [4]   [5]   [6]    [7]
//@E :0:  id1   1      2      3      aa    id1   2      3
//@E :1:  id2   6      7      8      bb    id2   7      8
//@E :2:  id3   1      2      3      cc    NA    0      0
//@E :3:  id4   6      7      8      uu    id4   7      8
//@E :4:  id5   1      2      3      s4    id5   2      3
//@E :5:  id6   6      7      8      s9    id6   7      8
//@E :6:  id7   1      2      3      a4    id7   2      3
//@E :7:  id8   6      7      8      m9    id8   2      3
//@E :8:  id9   6      7      8      s9    id9   7      8
//@E :9:  id10  1      2      3      a4    NA    0      0
//@E :10: id11  6      7      8      m9    id11  7      8
//@E :11: id12  6      7      8      m9    id12  7      8
//@E :12: id13  6      7      8      s9    NA    0      0
//@E :13: id14  1      2      3      NA    id14  7      8
//@E :14: id15  16     7      8      m9    id15  2      3
//@E :15: NA    0      0      0      NA    id119 7      8
//@X

//@T Dataframe.transform_left_join
//@U void transform_left_join(Dataframe &obj, 
//@U                     unsigned int &key1, 
//@U                     unsigned int &key2,
//@U                     std::string default_str = "NA",
//@U                     char default_chr = ' ',
//@U                     bool default_bool = 0,
//@U                     int default_int = 0,
//@U                     unsigned int default_uint = 0,
//@U                     double default_dbl = 0) 
//@X
//@D Transforms the dataframe performing a left join.
//@A obj : is the second dataframe
//@A key1 : is the column index of the primary key
//@A key2 : is the foreign key
//@A default_str : is the default value for NA string values
//@A default_chr : is the default value for NA char values
//@A default_bool : is the default value for NA boolean values
//@A default_int : is the default value for NA int values
//@A default_uint : is the default value for NA unsigned int values
//@A default_dbl : is the default value for NA double values
//@X
//@E  Dataframe obj1, obj2;
//@E  std::string fname = "csv_test/outb.csv";
//@E  obj1.readf(fname);
//@E  fname = "csv_test/outb2.csv";
//@E  obj2.readf(fname);
//@E
//@E  unsigned int n = 0;
//@E  obj1.transform_left_join(obj2, n, n);
//@E
//@E  obj1.display();
//@E     &lt;str&gt; &lt;uint&gt; &lt;uint&gt; &lt;uint&gt; &lt;str&gt; &lt;str&gt; &lt;uint&gt; &lt;uint&gt;
//@E     col1  col2   col3   col4   col5  col1  col2   col3
//@E :0:  id1   1      2      3      aa    id1   2      3
//@E :1:  id2   6      7      8      bb    id2   7      8
//@E :2:  id3   1      2      3      cc    NA    0      0
//@E :3:  id4   6      7      8      uu    id4   7      8
//@E :4:  id5   1      2      3      s4    id5   2      3
//@E :5:  id6   6      7      8      s9    id6   7      8
//@E :6:  id7   1      2      3      a4    id7   2      3
//@E :7:  id8   6      7      8      m9    id8   2      3
//@E :8:  id9   6      7      8      s9    id9   7      8
//@E :9:  id10  1      2      3      a4    NA    0      0
//@E :10: id11  6      7      8      m9    id11  7      8
//@E :11: id12  6      7      8      m9    id12  7      8
//@E :12: id13  6      7      8      s9    NA    0      0
//@E :13: id14  1      2      3      NA    id14  7      8
//@E :14: id15  16     7      8      m9    id15  2      3
//@X

//@T Dataframe.transform_filter
//@U void transform_filter(std::vector&lt;bool&gt;& mask)
//@X
//@D Keeps the desired row from a boolean mask.
//@A mask : is the boolean mask
//@X
//@E Dataframe obj1, obj2;
//@E std::string fname = "csv_test/outb.csv";
//@E obj1.readf(fname);
//@E fname = "csv_test/outb2.csv";
//@E obj2.readf(fname);
//@E
//@E std::vector<bool> mask = {0, 1, 0, 1, 1, 1, 0, 1, 0, 1, 1, 1, 0, 1, 0, 1};
//@E
//@E obj1.transform_filter(mask);
//@E
//@E obj1.display();
//@E    &lt;str&gt; &lt;uint&gt; &lt;uint&gt; &lt;uint&gt; &lt;str&gt;
//@E    col1  col2   col3   col4   col5
//@E :0: id2   6      7      8      bb
//@E :1: id4   6      7      8      uu
//@E :2: id5   1      2      3      s4
//@E :3: id6   6      7      8      s9
//@E :4: id8   6      7      8      m9
//@E :5: id10  1      2      3      a4
//@E :6: id11  6      7      8      m9
//@E :7: id12  6      7      8      m9
//@E :8: id14  1      2      3      NA
//@X

//@T Dataframe.pivot_dbl
//@U void pivot_dbl(Dataframe &obj, unsigned int &n1, unsigned int& n2, unsigned int& n3)
//@X
//@D Performs a pivot to a newly created dataframe.
//@A obj : is the dataframe from which the pivot is performed
//@A n1 : is the column index of the columns created for the pivot
//@A n2 : is the column index of the rows created for the pivot
//@A n3 : is the column index of the column from which the pivot is performed
//@X
//@E
//@E  // after some random manipulation for obj1 dataframe
//@E  Dataframe obj3;
//@E  obj1.display();
//@E
//@E     &lt;str&gt; &lt;uint&gt; &lt;uint&gt; &lt;uint&gt; &lt;str&gt; &lt;str&gt; &lt;uint&gt; &lt;double&gt;
//@E     col1  col2   col3   col4   col5  col1  col2   col3
//@E :0:  id1   1      2      3      A     D     2      3
//@E :1:  id2   6      7      8      A     D     7      8
//@E :2:  id3   1      2      3      A     C     0      0
//@E :3:  id4   6      7      8      B     C     7      8
//@E :4:  id5   1      2      3      B     C     2      3
//@E :5:  id6   6      7      8      A     D     7      8
//@E :6:  id7   1      2      3      B     C     2      3
//@E :7:  id8   6      7      8      B     D     2      3
//@E :8:  id9   6      7      8      B     D     7      8
//@E :9:  id10  1      2      3      A     C     0      0
//@E :10: id11  6      7      8      A     D     7      8
//@E :11: id12  6      7      8      B     C     7      8
//@E :12: id13  6      7      8      B     D     0      0
//@E :13: id14  1      2      3      B     C     7      8
//@E :14: id15  16     7      8      B     D     2      3
//@E
//@E  unsigned int n1 = 4;
//@E  unsigned int n2 = 5;
//@E  unsigned int n3 = 7;
//@E
//@E  obj3.pivot_uint(obj1, n, n2, n3);
//@E
//@E  obj3.display();
//@E
//@E    &lt;double&gt; &lt;double&gt;
//@E    A        B
//@E D : 27       14
//@E C : 0        30
//@E
//@X

//@T Dataframe.pivot_int
//@U void pivot_int(Dataframe &obj, unsigned int &n1, unsigned int& n2, unsigned int& n3)
//@X
//@D Performs a pivot to a newly created dataframe.
//@A obj : is the dataframe from which the pivot is performed
//@A n1 : is the column index of the columns created for the pivot
//@A n2 : is the column index of the rows created for the pivot
//@A n3 : is the column index of the column from which the pivot is performed
//@X
//@E
//@E  // after some random manipulation for obj1 dataframe
//@E  Dataframe obj3;
//@E  obj1.display();
//@E
//@E     &lt;str&gt; &lt;uint&gt; &lt;uint&gt; &lt;uint&gt; &lt;str&gt; &lt;str&gt; &lt;uint&gt; &lt;int&gt;
//@E     col1  col2   col3   col4   col5  col1  col2   col3
//@E :0:  id1   1      2      3      A     D     2      3
//@E :1:  id2   6      7      8      A     D     7      8
//@E :2:  id3   1      2      3      A     C     0      0
//@E :3:  id4   6      7      8      B     C     7      8
//@E :4:  id5   1      2      3      B     C     2      3
//@E :5:  id6   6      7      8      A     D     7      8
//@E :6:  id7   1      2      3      B     C     2      3
//@E :7:  id8   6      7      8      B     D     2      3
//@E :8:  id9   6      7      8      B     D     7      8
//@E :9:  id10  1      2      3      A     C     0      0
//@E :10: id11  6      7      8      A     D     7      8
//@E :11: id12  6      7      8      B     C     7      8
//@E :12: id13  6      7      8      B     D     0      0
//@E :13: id14  1      2      3      B     C     7      8
//@E :14: id15  16     7      8      B     D     2      3
//@E
//@E  unsigned int n1 = 4;
//@E  unsigned int n2 = 5;
//@E  unsigned int n3 = 7;
//@E
//@E  obj3.pivot_uint(obj1, n, n2, n3);
//@E
//@E  obj3.display();
//@E
//@E    &lt;int&gt; &lt;int&gt;
//@E    A        B
//@E D : 27       14
//@E C : 0        30
//@E
//@X

//@T Dataframe.pivot_uint
//@U void pivot_uint(Dataframe &obj, unsigned int &n1, unsigned int& n2, unsigned int& n3)
//@X
//@D Performs a pivot to a newly created dataframe.
//@A obj : is the dataframe from which the pivot is performed
//@A n1 : is the column index of the columns created for the pivot
//@A n2 : is the column index of the rows created for the pivot
//@A n3 : is the column index of the column from which the pivot is performed
//@X
//@E
//@E  // after some random manipulation for obj1 dataframe
//@E  Dataframe obj3;
//@E  obj1.display();
//@E
//@E     &lt;str&gt; &lt;uint&gt; &lt;uint&gt; &lt;uint&gt; &lt;str&gt; &lt;str&gt; &lt;uint&gt; &lt;uint&gt;
//@E     col1  col2   col3   col4   col5  col1  col2   col3
//@E :0:  id1   1      2      3      A     D     2      3
//@E :1:  id2   6      7      8      A     D     7      8
//@E :2:  id3   1      2      3      A     C     0      0
//@E :3:  id4   6      7      8      B     C     7      8
//@E :4:  id5   1      2      3      B     C     2      3
//@E :5:  id6   6      7      8      A     D     7      8
//@E :6:  id7   1      2      3      B     C     2      3
//@E :7:  id8   6      7      8      B     D     2      3
//@E :8:  id9   6      7      8      B     D     7      8
//@E :9:  id10  1      2      3      A     C     0      0
//@E :10: id11  6      7      8      A     D     7      8
//@E :11: id12  6      7      8      B     C     7      8
//@E :12: id13  6      7      8      B     D     0      0
//@E :13: id14  1      2      3      B     C     7      8
//@E :14: id15  16     7      8      B     D     2      3
//@E
//@E  unsigned int n1 = 4;
//@E  unsigned int n2 = 5;
//@E  unsigned int n3 = 7;
//@E
//@E  obj3.pivot_uint(obj1, n, n2, n3);
//@E
//@E  obj3.display();
//@E
//@E    &lt;uint&gt; &lt;uint&gt;
//@E    A        B
//@E D : 27       14
//@E C : 0        30
//@E
//@X

//@T Dataframe.get_typecol
//@U const std::vector&lt;char&gt;& get_typecol() const
//@X
//@D Returns the column type of the dataframe, 'i' (int), 'u', (unsigned int), 'd', double, 's' (string), 'c' (char)
//@A X : NO ARGS
//@X
//@E const std::vector<char>& dtype = obj1.get_typecol();
//@E 'c' 'b' 'd' 'i' 
//@X

//@T Dataframe.transform_unique
//@U void transform_unique(unsigned int& n)
//@X
//@D Trnasforms your current dataframe to keep the unique values from a chosen column.
//@A n : is the column index
//@X
//@E   std::string fname = "csv_test/outb.csv";
//@E   obj1.readf&lt;3, 0&gt;(fname);
//@E   obj1.display();
//@E   
//@E     &lt;str&gt; &lt;uint&gt; &lt;uint&gt; &lt;uint&gt; &lt;str&gt;
//@E     col1  col2   col3   col4   col5
//@E :0:  id4   6      7      8      uu
//@E :1:  id5   1      2      3      s4
//@E :2:  id6   6      7      8      s9
//@E :3:  id7   1      2      3      a4
//@E :4:  id8   6      7      8      m9
//@E :5:  id9   6      7      8      s9
//@E :6:  id10  1      2      3      a4
//@E :7:  id11  6      7      8      m9
//@E :8:  id12  6      7      8      m9
//@E :9:  id13  6      7      8      s9
//@E :10: id14  1      2      3      NA
//@E :11: id15  16     7      8      m9
//@E
//@E   unsigned int n = 4;
//@E   obj1.transform_unique(n);
//@E   obj1.display();
//@E
//@E    &lt;str&gt; &lt;uint&gt; &lt;uint&gt; &lt;uint&gt; &lt;str&gt;
//@E    col1  col2   col3   col4   col5
//@E :0: id4   6      7      8      uu
//@E :1: id5   1      2      3      s4
//@E :2: id6   6      7      8      s9
//@E :3: id7   1      2      3      a4
//@E :4: id8   6      7      8      m9
//@E :5: id14  1      2      3      NA
//@E
//@X

//@T Dataframe.transform_unique_clean
//@U void transform_unique_clean(unsigned int& n)
//@X
//@D Trnasforms your current dataframe to keep the unique values from a chosen column. Basically the same as transfrm_unique, but frees memory, which can be slower.
//@A n : is the column index
//@X
//@E   std::string fname = "csv_test/outb.csv";
//@E   obj1.readf&lt;3, 0&gt;(fname);
//@E   obj1.display();
//@E   
//@E     &lt;str&gt; &lt;uint&gt; &lt;uint&gt; &lt;uint&gt; &lt;str&gt;
//@E     col1  col2   col3   col4   col5
//@E :0:  id4   6      7      8      uu
//@E :1:  id5   1      2      3      s4
//@E :2:  id6   6      7      8      s9
//@E :3:  id7   1      2      3      a4
//@E :4:  id8   6      7      8      m9
//@E :5:  id9   6      7      8      s9
//@E :6:  id10  1      2      3      a4
//@E :7:  id11  6      7      8      m9
//@E :8:  id12  6      7      8      m9
//@E :9:  id13  6      7      8      s9
//@E :10: id14  1      2      3      NA
//@E :11: id15  16     7      8      m9
//@E
//@E   unsigned int n = 4;
//@E   obj1.transform_unique_clean(n);
//@E   obj1.display();
//@E
//@E    &lt;str&gt; &lt;uint&gt; &lt;uint&gt; &lt;uint&gt; &lt;str&gt;
//@E    col1  col2   col3   col4   col5
//@E :0: id4   6      7      8      uu
//@E :1: id5   1      2      3      s4
//@E :2: id6   6      7      8      s9
//@E :3: id7   1      2      3      a4
//@E :4: id8   6      7      8      m9
//@E :5: id14  1      2      3      NA
//@E
//@X

//@L1 Apply any function on indefinite numbers of same type vectors

//@T Fapply object
//@U Fapply
//@X 
//@D Allows to perform any function on a set of same type vectors, simplified
//@A ... : all the vectors
//@X
//@E // declare a custom function
//@E 
//@E int add(std::vector&lt;int&gt; x) {
//@E   int rtn_v = x[0];
//@E   for (int i = 1; i &lt; x.size(); ++i) {
//@E     rtn_v += x[i];
//@E   };
//@E   return rtn_v;
//@E };
//@E
//@E std::vector&lt;int&gt; inpt_v1 = {1, 2, 3, 4, 5, 6, 7};
//@E std::vector&lt;int&gt; inpt_v2 = {7, 6, 5, 4, 3, 2, 1};
//@E 
//@E Fapply obj1(inpt_v1); //initialise object with a vector argument
//@E obj1.set_args(inpt_v1, inpt_v2, inpt_v2); //ingest args
//@E 
//@E //performs the chosen function
//@E std::vector&lt;int&gt; outv = obj1.fapply(add); 
//@E 
//@E print_nvec(outv);
//@E
//@E :0: 15 14 13 12 11 10 9
//@E
//@X

#endif

template <typename TB> class Fapply {

  private:

    std::vector<std::vector<TB>> args_matr = {};
    std::vector<TB> rtn_v = {};
    TB cur_val;
    unsigned int args_nb;

  public:

    void set_args() { };

    template <typename T, typename ...T2> 
    void set_args(std::vector<T> &x, std::vector<T2>&... x2) {

      for (unsigned int i = 0; i < args_nb; ++i) {
        args_matr[i].push_back(x[i]);
      };

      set_args(x2...);

    };

    std::vector<TB> fapply(TB (&f)(std::vector<TB>)) {
      for (unsigned int i = 0; i < args_nb; ++i) {
        cur_val = f(args_matr[i]);
        rtn_v.push_back(cur_val);
      };
      return rtn_v;
    };

    Fapply(std::vector<TB> &x) {
      cur_val = x[0];
      rtn_v.push_back(x[0]);
      rtn_v.pop_back();
      args_nb = x.size();
      rtn_v.reserve(args_nb);
      args_matr = {x};
      args_matr.pop_back();
      args_matr.resize(args_nb, {});
    };

    ~Fapply() {};

};

#if 0
//@T Fapply2d object
//@U Fapply(std::vector&lt;TB&gt; &x)
//@X
//@D Apllies any function onto a variadic numbers of vectors of any type
//@A x : is an empty vector of the type choosen for the operations between vectors
//@X
//@E std::vector&lt;int&gt; xint = {0, 1, 2};
//@E std::vector&lt;int&gt; xint2 = {0, 1, 2};
//@E 
//@E std::vector&lt;int&gt; iinv = {};
//@E 
//@E Fapply2d obj1(iinv);
//@X

//@T Fapply2d.set_args
//@U template &lt;typename T, typename ...T2&gt; void set_args(std::vector&lt;T&gt; &x, std::vector&lt;T2&gt;&... x2)
//@X
//@D Is a variadic function allowing to put in the class an indefinite number of vectors of the same type that will be used by your custom function later, see <code>Fapply2d.fapply2d()</code>
//@A ... : is some same types vectors
//@X
//@E 
//@E std::vector&lt;int&gt; xint = {0, 1, 2};
//@E std::vector&lt;int&gt; xint2 = {0, 1, 2};
//@E 
//@E obj1.set_args(xint, xint, xint2);
//@X

//@T Fapply2d.fapply2d
//@U template &lt;typename T&gt; std::vector&lt;T&gt; fapply2d(std::vector&lt;T&gt; (&f)(std::vector&lt;std::vector&lt;T&gt;&gt;))
//@X
//@D Performs your custom function on the <code>std::vector<std::vector<T>></code> created by <code>Fapply2d.set_args()</code>.
//@A f : is the reference to the custom function
//@X
//@E 
//@E std::vector&lt;int&gt; addv(std::vector&lt;std::vector&lt;int&gt;&gt; x) {
//@E   std::vector&lt;int&gt; rtn_v = {};
//@E   int cur_val;
//@E   unsigned int i2;
//@E   const unsigned int n  = x[0].size();
//@E   const unsigned int n2  = x.size();
//@E   for (int i = 0; i &lt; n; ++i) {
//@E     cur_val = 0;
//@E     for (i2 = 0; i2 &lt; n2; ++i2) {
//@E       cur_val += x[i2][i];
//@E     };
//@E     rtn_v.push_back(cur_val);
//@E   };
//@E   return rtn_v;
//@E };
//@E
//@E std::vector&lt;int&gt; xint = {0, 1, 2};
//@E std::vector&lt;int&gt; xint2 = {0, 1, 2};
//@E 
//@E std::vector&lt;int&gt; iinv = {};
//@E 
//@E Fapply2d obj1(iinv);
//@E obj1.set_args(xint, xint, xint2);
//@E iinv = obj1.fapply2d(addv);
//@E print_nvec(outv);
//@E :0: 0 3 6
//@X

//@T Fapply2d.reinitiate
//@U void reinitiate();
//@X
//@D Empties the 2d T internal vector. Necessary to reset args (vectors input of the internal 2d vector) of same type before applying the function (or another) to new vectors.
//@A no : no
//@X
//@E Fapply2d.reinitiate();
//@X
#endif

template <typename TB> class Fapply2d {

  private:

    std::vector<std::vector<TB>> matr_val = {};
    std::vector<TB> rtn_v;

  public:

    template <typename T> std::vector<T> fapply2d(std::vector<T> (&f)(std::vector<std::vector<T>>)) {
      return f(matr_val);
    };

    void set_args() { };
    
    template <typename T, typename ...T2> void set_args(std::vector<T> &x, std::vector<T2>&... x2) {
      matr_val.push_back(x);
      set_args(x2...);
    };

    void reinitiate() {
      rtn_v = {};
      matr_val = {};
    };

    Fapply2d(std::vector<TB> &x) {
      rtn_v = x;
      matr_val = {x};
      matr_val.pop_back();
    };

    ~Fapply2d() {};

};

//@L1 Geographical coordinates manipulation

//@T geo_min
//@U double geo_min(double &lat1, double &longit1, double &lat2, double &longit2, const double sphere_ray = 6378)
//@X
//@D Returns the shortest distance between 2 geographical points.
//@A lat1 : is the lattitude of the first point
//@A longit1 : is the longitude of the second point
//@A lat2 : is the lattitude of the second point
//@A longit2 : is the longitude of the second point
//@A sphere_ray : is the rayon of the sphere in km (defaults to Earth)
//@X
//@E double lat1 = 23;
//@E double longit1 = -45;
//@E 
//@E double lat2 = -23;
//@E double longit2 = 45;
//@E 
//@E double delta = geo_min(lat1, longit1, lat2, longit2);
//@E 
//@E std::cout &lt;&lt; delta &lt;&lt; "\n";
//@E 
//@E lat1 = 60;
//@E longit1 = 30;
//@E 
//@E lat2 = 60;
//@E longit2 = -150;
//@E 
//@E delta = geo_min(lat1, longit1, lat2, longit2);
//@E 
//@E std::cout &lt;&lt; delta &lt;&lt; "\n";
//@E 6679.1
//@X

double geo_min(double &lat1, double &longit1, double &lat2, double &longit2, const double sphere_ray = 6378) {
  double g_rad;
  double a_rad;
  double b_rad;
  double c_rad;
  double delta;
  const double pi = 3.141593;
  if (lat1 >= 0) {
    a_rad = 90 - lat1;
  } else {
    a_rad = 90 + lat1;
  };
  a_rad = pi * a_rad / 180;
  if (lat2 >= 0) {
    b_rad = 90 - lat2;
  } else {
    b_rad = 90 - lat2;
  };
  b_rad = pi * b_rad / 180;
  if (longit1 >= longit2) {
    g_rad = longit1 - longit2;
  } else {
    g_rad = longit2 - longit1;
  };
  g_rad = pi * g_rad / 180;
  c_rad = cos(a_rad) * cos(b_rad) + sin(a_rad) * sin(b_rad) * cos(g_rad);
  delta = acos(c_rad) * sphere_ray;
  return delta;
};

//@L1 Date manipulation (Gregorian)

//@L2 Format convertions

//@T fr_to_eng_datefmt
//@U std::string fr_to_eng_datefmt(std::string &x, char sep = '-')
//@X
//@D Converts a french date format to an english one.
//@A x : is the input date
//@A sep : is the date separator
//@X
//@E std::string fr_date = "02-07-2022";
//@E std::string eng_date = fr_to_eng_datefmt(fr_date);
//@E std::cout &lt;&lt; eng_date&lt;&lt; "\n";
//@E 07-02-2022
//@X

std::string fr_to_eng_datefmt(std::string &x, char sep = '-') {
  std::vector<std::string> vec = split(x, sep);
  std::string rtn_val = "";
  rtn_val += vec[1];
  rtn_val.push_back(sep);
  rtn_val += vec[0];
  rtn_val.push_back(sep);
  rtn_val += vec[2];
  return rtn_val;
};

//@T eng_to_fr_datefmt
//@U std::string eng_to_fr_datefmt(std::string &x, char sep = '-')
//@X
//@D Converts a english date format to an french one.
//@A x : is the input date
//@A sep : is the date separator
//@X
//@E std::string eng_date = "07-02-2022";
//@E std::string fr_date = eng_to_fr_datefmt(eng_date);
//@E std::cout << fr_date << "\n";
//@E 02-07-2022
//@X

std::string eng_to_fr_datefmt(std::string &x, char sep = '-') {
  std::vector<std::string> vec = split(x, sep);
  std::string rtn_val = "";
  rtn_val += vec[1];
  rtn_val.push_back(sep);
  rtn_val += vec[0];
  rtn_val.push_back(sep);
  rtn_val += vec[2];
  return rtn_val;
};

//@T fmt_converter_date
//@U std::string fmt_converter_date(std::string &x, std::string &in_fmt, std::string &out_fmt, char delim = '-')
//@X
//@D Cpnverts a date to another date format.
//@A x : is the input date
//@A in_fmt : is the input date format
//@A out_fmt : is the output date format
//@X
//@E std::string in_fmt = "dmy";
//@E std::string out_fmt = "mdy";
//@E std::string inpt_date = "02-07-2003";
//@E std::string outfmtdate = fmt_converter_date(inpt_date, in_fmt, out_fmt);
//@E std::cout << outfmtdate << "\n";
//@E 07-02-2003
//@X

std::string fmt_converter_date(std::string &x, std::string &in_fmt, std::string &out_fmt, char delim = '-') {
  unsigned int i2;
  unsigned int i;
  std::string rtn_val = "";
  std::vector<std::string> date_v = split(x, delim);
  const unsigned int n = in_fmt.length();
  if (n != out_fmt.length()) {
    throw std::invalid_argument("the 2 dates format are not the same length\n");
  };
  for (i = 0; i < n; ++i) {
    for (i2 = 0; i2 < n; ++i2) {
      if (in_fmt[i2] == out_fmt[i]) {
        rtn_val += date_v[i2];
        if (i + 1 < n) {
          rtn_val.push_back(delim);
        };
        break;
      };
    };
  };
  return rtn_val;
};

//@L2 Sort dates

//@T ascend_sort_date
//@U std::vector&lt;std::string&gt; ascend_sort_date(std::vector&lt;std::string&gt; &x, 
//@U                 std::string &fmt, char delim = '-')
//@X
//@D Returns a vector of date ascendly sorted. The format meaning is 'y' for year, 'm' for month, 'd' for day, 'h' for hour, 'n' for minute and 's' for second.
//@A x : is the input vector of dates
//@A fmt : is the date format
//@A delim : is the date delimiter
//@X
//@E std::vector&lt;std::string&gt; vec = {
//@E         "02-04-2026",
//@E         "02-11-2023",
//@E         "07-02-2026",
//@E         "22-04-2016",
//@E         "02-12-2006",
//@E         "17-9-2015",
//@E         "03-04-2017",
//@E         "02-05-2017",
//@E         "15-01-2026"
//@E }; 
//@E 
//@E std::string fmt = "dmy";
//@E 
//@E std::vector&lt;std::string&gt; outv = ascend_sort_date(vec, fmt);
//@E print_svec(outv);
//@E :0: 02-12-2006 17-9-2015  22-04-2016 03-04-2017 02-05-2017 02-11-2023 15-01-2026 07-02-2026
//@E :8: 02-04-2026
//@X

std::vector<std::string> ascend_sort_date(std::vector<std::string> &x, 
                std::string &fmt, char delim = '-') {
  const unsigned int n = x.size();
  std::vector<unsigned int> idx_fmt = {};
  idx_fmt.reserve(n);
  std::vector<std::string> rtn_v = {};
  rtn_v.reserve(n); 
  std::vector<char> unit_time_fmt = {'y', 'm', 'd', 'h', 'n', 's'};
  const unsigned int n_fmt = fmt.length();
  unsigned int cnt;
  unsigned int cnt2;
  char cur_time_unit;
  std::vector<int> val_fmt = {};
  val_fmt.resize(n, 0);
  std::vector<std::string> date_v;
  for (cnt = 0; cnt < 6; ++cnt) {
    cur_time_unit = unit_time_fmt[cnt];
    for (cnt2 = 0; cnt2 < n_fmt; ++cnt2) {
      if (cur_time_unit == fmt[cnt2]) {  
        idx_fmt.push_back(cnt2);
        break;
      };
    };
  };
  for (cnt = 0; cnt < n; ++cnt) {
    cnt2 = 0;
    date_v = split(x[cnt], delim);
    while (cnt2 + 1 < n_fmt) {
      val_fmt[cnt] += std::stoi(date_v[idx_fmt[cnt2]]);
      val_fmt[cnt] *= 100;
      cnt2 += 1;
    };
    val_fmt[cnt] += std::stoi(date_v[idx_fmt[cnt2]]);
  };
  std::vector<int> val_fmt2;
  sort_asc(val_fmt);
  unsigned int cur_idx;
  for (cnt = 0; cnt < n; ++cnt) {
    cur_idx = match(val_fmt, val_fmt2[cnt]);
    rtn_v.push_back(x[cur_idx]);
  };
  return rtn_v;
};

//@T descend_sort_date
//@U std::vector&lt;std::string&gt; descend_sort_date(std::vector&lt;std::string&gt; &x, 
//@U                 std::string &fmt, char delim = '-')
//@X
//@D Returns a vector of date descendly sorted. The format meaning is 'y' for year, 'm' for month, 'd' for day, 'h' for hour, 'n' for minute and 's' for second.
//@A x : is the input vector of dates
//@A fmt : is the date format
//@A delim : is the date delimiter
//@X
//@E std::vector&lt;std::string&gt; vec = {
//@E         "02-04-2026",
//@E         "02-11-2023",
//@E         "07-02-2026",
//@E         "22-04-2016",
//@E         "02-12-2006",
//@E         "17-9-2015",
//@E         "03-04-2017",
//@E         "02-05-2017",
//@E         "15-01-2026"
//@E }; 
//@E 
//@E std::string fmt = "dmy";
//@E 
//@E std::vector&lt;std::string&gt; outv = descend_sort_date(vec, fmt);
//@E print_svec(outv);
//@E :0: 02-04-2026 07-02-2026 15-01-2026 02-11-2023 02-05-2017 03-04-2017 22-04-2016 17-9-2015
//@E :8: 02-12-2006
//@X

std::vector<std::string> descend_sort_date(std::vector<std::string> &x, 
                std::string &fmt, char delim = '-') {
  const unsigned int n = x.size();
  std::vector<unsigned int> idx_fmt = {};
  idx_fmt.reserve(n);
  std::vector<std::string> rtn_v = {};
  rtn_v.reserve(n); 
  std::vector<char> unit_time_fmt = {'y', 'm', 'd', 'h', 'n', 's'};
  const unsigned int n_fmt = fmt.length();
  unsigned int cnt;
  unsigned int cnt2;
  char cur_time_unit;
  std::vector<int> val_fmt = {};
  val_fmt.resize(n, 0);
  std::vector<std::string> date_v;
  for (cnt = 0; cnt < 6; ++cnt) {
    cur_time_unit = unit_time_fmt[cnt];
    for (cnt2 = 0; cnt2 < n_fmt; ++cnt2) {
      if (cur_time_unit == fmt[cnt2]) {  
        idx_fmt.push_back(cnt2);
        break;
      };
    };
  };
  for (cnt = 0; cnt < n; ++cnt) {
    cnt2 = 0;
    date_v = split(x[cnt], delim);
    while (cnt2 + 1 < n_fmt) {
      val_fmt[cnt] += std::stoi(date_v[idx_fmt[cnt2]]);
      val_fmt[cnt] *= 100;
      cnt2 += 1;
    };
    val_fmt[cnt] += std::stoi(date_v[idx_fmt[cnt2]]);
  };
  std::vector<int> val_fmt2;
  sort_desc(val_fmt);
  unsigned int cur_idx;
  for (cnt = 0; cnt < n; ++cnt) {
    cur_idx = match(val_fmt, val_fmt2[cnt]);
    rtn_v.push_back(x[cur_idx]);
  };
  return rtn_v;
};

//@J1

//@T is_leap
//@U template &lt;typename T&gt; bool is_leap(unsigned T &x)
//@X
//@D Returns if the input year is leap.
//@A x : is the input year
//@X
//@E int year = 2024;
//@E bool bsx = is_leap(year);
//@E std::cout &lt;&lt; bsx &lt;&lt; "\n";
//@E 1
//@X

template <typename T> bool is_leap(T &x) {
  if (x == 0) {
    return 0;
  };
  if (x % 4 == 0) {
    if (x % 100 == 0) {
      if (x % 400 == 0) {
        return 1;
      } else {
        return 0;
      };
    } else {
      return 1;
    };
  } else {
    return 0;
  };
};

//@T delta_second
//@U double delta_second(std::string &bgn_date, std::string &end_date, int ref_year = 0, char delim = '-') 
//@X
//@D Returns the number of second elapsed between 2 dates.
//@A bgn_date : is the first date, must be lower than the second date
//@A end_date : is the second date
//@A ref_year : is a reference year from which the time elapsed wil be calculated. This value must be lower than the year of the first date
//@A delim : is the date delimiter
//@X
//@E std::string bgn_date = "2003-07-02-2-23-46";
//@E std::string end_date = "2025-04-01-12-13-26";
//@E double delta = delta_second(bgn_date, end_date);
//@E std::cout &lt;&lt; delta &lt;&lt; "\n";
//@E 6.86311e+08
//@X

double delta_second(std::string &bgn_date, std::string &end_date, int ref_year = 0, char delim = '-') {
  unsigned int i;
  std::vector<unsigned int> bgn_vec = {};
  bgn_vec.resize(6, 0);
  std::vector<std::string> date_v = split(bgn_date, delim);
  for (i = 0; i < 6; ++i) {
    bgn_vec[i] = std::stoi(date_v[i]);
  };
  std::vector<unsigned int> end_vec = {};
  end_vec.resize(6, 0);
  date_v = split(end_date, delim);
  for (i = 0; i < 6; ++i) {
    end_vec[i] = std::stoi(date_v[i]);
  };
  double rtn_val = 0;
  bool cur_leap;
  std::vector<unsigned int> leap_month_nbdays = {31, 29, 
                                                31, 30, 
                                                31, 30, 
                                                31, 31, 
                                                30, 31, 
                                                30, 31};

  std::vector<unsigned int> month_nbdays = {31, 28, 
                                            31, 30, 
                                            31, 30, 
                                            31, 31, 
                                            30, 31, 
                                            30, 31};
  double bgn_val = 0;
  double end_val = 0;
  for (i = ref_year; i <= bgn_vec[0]; ++i) {
    cur_leap = is_leap(i);
    if (!cur_leap) {
      bgn_val += (365 * 24 * 3600);
    } else {
      bgn_val += (366 * 24 * 3600);
    };
  };
  if (!cur_leap) {
    for (i = 0; i < bgn_vec[1]; ++i) {
      bgn_val += (month_nbdays[i] * 24 * 3600); 
    };
  } else {
    for (i = 0; i < bgn_vec[1]; ++i) {
      bgn_val += (leap_month_nbdays[i] * 24 * 3600); 
    };
  };
  bgn_val += (bgn_vec[2] * 24 * 3600);
  bgn_val += (bgn_vec[3] * 3600);
  bgn_val += (bgn_vec[4] * 60);
  bgn_val += bgn_vec[5];
  for (i = ref_year; i <= end_vec[0]; ++i) {
    cur_leap = is_leap(i);
    if (!cur_leap) {
      end_val += (365 * 24 * 3600);
    } else {
      end_val += (366 * 24 * 3600);
    };
  };
  if (!cur_leap) {
    for (i = 0; i < end_vec[1]; ++i) {
      end_val += (month_nbdays[i] * 24 * 3600); 
    };
  } else {
    for (i = 0; i < end_vec[1]; ++i) {
      end_val += (leap_month_nbdays[i] * 24 * 3600); 
    };
  };
  end_val += (end_vec[2] * 24 * 3600);
  end_val += (end_vec[3] * 3600);
  end_val += (end_vec[4] * 60);
  end_val += end_vec[5];
  rtn_val = end_val - bgn_val;
  return rtn_val;
};

//@T is_greater_date
//@U bool is_greater_date(std::string &x, std::string &x2, char delim = '-')
//@X
//@D Returns if the first date is greater than the second one. The dates must have the same format, which is the highest time unit at the beginning and so on.
//@A x : is the first date
//@A x2 : is the second date
//@A delim : is the date delimiter
//@X
//@E std::string bgn_date = "2003-07-02-2-23-46";
//@E std::string end_date = "2025-04-01-12-13-26";
//@E bool outbool = is_greater_date(end_date, bgn_date);
//@E std::cout &lt;&lt; outbool &lt;&lt; "\n";
//@E 1
//@X

bool is_greater_date(std::string &x, std::string &x2, char delim = '-') {
  std::vector<std::string> xv = split(x, delim);
  std::vector<std::string> x2v = split(x2, delim);
  int cur_valx = std::stoi(xv[0]);
  int cur_valx2 = std::stoi(x2v[0]);
  cur_valx *= 100;
  cur_valx2 *= 100;
  const unsigned int n = xv.size();
  if (x2v.size() != n) {
    std::cout << "the 2 dates does not have the same format\n";
    return 1;
  };
  for (unsigned int i = 0; i < n; ++i) {
    cur_valx = std::stoi(xv[0]);
    cur_valx2 = std::stoi(x2v[0]);
    cur_valx *= 100;
    cur_valx2 *= 100;
  };
  if (cur_valx > cur_valx2) {
    return 1;
  } else {
    return 0;
  };
};

//@L1 Fulgurance Tools

//@T Parser_tokenizer_full
//@U std::vector&lt;std::vector&lt;unsigned int&gt;&gt; Parser_tokenizer_full(std::string &x, char frst_chr = '(', char scd_chr = ')')
//@X
//@D Returns a 2d stl vectors. First vector is the pair of each parenthesis. Second stl vector is the index of each parenthesis. Takes a stl string as input. 
//@A x : is a stl string
//@X
//@E std::string teste = "(o((ldjf)de)po(m()()m)po)()()";
//@E std::vector&lt;std::vector&lt;unsigned int&gt;&gt; out = Parser_tokenizer_full(teste);
//@E {5 1 0 0 1 4 2 2 3 3 4 5 6 6 7 7}
//@E {0 2 3 8 11 14 16 17 18 19 21 24 25 26 27 28}
//@X

std::vector<std::vector<unsigned int>> Parser_tokenizer_full(std::string &x, char frst_chr = '(', char scd_chr = ')') {
  std::vector<unsigned int> num_par;
  std::vector<int> cur_val;
  std::vector<unsigned int> idx_vec;
  int i2;
  unsigned int cur_num = 0;
  const unsigned int n = x.length();
  bool alrd;
  for (int i = 0; i < n; ++i) {
    if (x[i] == frst_chr) {
      idx_vec.push_back(i);
      num_par.push_back(0);
      for (i2 = 0; i2 < cur_val.size(); ++i2) {
        cur_val[i2] += 1;
      };
      cur_val.push_back(1);
    } else if (x[i] == scd_chr) {
        idx_vec.push_back(i);
        i2 = cur_val.size() - 1;
        num_par.push_back(0);
        cur_val.push_back(1);
        alrd = 0;
        while (i2 > -1) {
          cur_val[i2] -= 1;
          if (cur_val[i2] == 0 & !alrd) {
            num_par[i2] = cur_num;
            num_par[num_par.size() - 1] = cur_num;
            cur_val[cur_val.size() - 1] = 0;
            cur_num += 1;
            alrd = 1;
          };
          i2 -= 1;
        };
    };
  };
  return {num_par, idx_vec};
};

#if 0
//@T is_intricated
//@U bool is_intricated (unsigned int &idx, std::vector&lt;unsigned int&gt; &tkn_v)
//@X
//@D Returns a boolean, 1 if the parenthesis refered is intricated in others parenthesis, 0 if not. See examples.
//@A tkn_v : is a std vector containing all the parenthesis pairs. The one outputed by <a href="#Parser_tokenizer_full">Parser_tokennizer_full</a> function.
//@A idx : is an unsigned int that indicates the parenthesis refered in tkn_v vector
//@X
//@E std::string inpt_str = "(ldkhf(f)ek(()))dkjf(gf())()()";
//@E std::vector&lt;std::vector&lt;unsigned int&gt;&gt; out_matr = Parser_tokenizer_full(inpt_str);
//@E std::vector&lt;unsigned int&gt; tkn_v = out_matr[0];
//@E std::vector&lt;unsigned int&gt; idx_v = out_matr[1];
//@E unsigned int i;
//@E for (i = 0; i &lt; tkn_v.size(); ++i) {
//@E   std::cout &lt;&lt; tkn_v[i] &lt;&lt; " ";
//@E };
//@E std::cout &lt;&lt; "\n";
//@E for (i = 0; i &lt; tkn_v.size(); ++i) {
//@E   std::cout &lt;&lt; idx_v[i] &lt;&lt; " ";
//@E };
//@E 3 0 0 2 1 1 2 3 5 4 4 5 6 6 7 7
//@E 0 6 8 11 12 13 14 15 20 23 24 25 26 27 28 29
//@E std::cout &lt;&lt; "\n";
//@E unsigned int cur_idx = 15;
//@E bool is_it = is_intricated(cur_idx, tkn_v);
//@E std::cout &lt;&lt; is_it &lt;&lt; "\n";
//@E 0
//@E cur_idx = 3;
//@E is_it = is_intricated(cur_idx, tkn_v);
//@E std::cout &lt;&lt; is_it &lt;&lt; "\n";
//@E 1
//@E cur_idx = 7;
//@E is_it = is_intricated(cur_idx, tkn_v);
//@E std::cout &lt;&lt; is_it &lt;&lt; "\n";
//@E 0
//@E cur_idx = 6;
//@E is_it = is_intricated(cur_idx, tkn_v);
//@E std::cout &lt;&lt; is_it &lt;&lt; "\n";
//@E 1
//@X
#endif

bool is_intricated (unsigned int &idx, std::vector<unsigned int> &tkn_v) {
  std::vector<int> alrd_tkn = {};
  unsigned int i;
  unsigned int i2;
  unsigned int cur_tkn;
  if (idx == 0) {
    return 0;
  };
  for (i = 0; i < idx + 1; ++i) {
    alrd_tkn.push_back(tkn_v[i]);
  };
  i = 0;
  const unsigned int n2 = alrd_tkn.size();
  while (i + 1 < n2) {
    if (alrd_tkn[i] != -1) {
      cur_tkn = alrd_tkn[i];
      i2 = i + 1;
      while (1) {
        if (i2 == n2) {
          return 1;
        } else if (cur_tkn == alrd_tkn[i2]) {
          alrd_tkn[i2] = -1;
          break;
        };
        i2 += 1;
      };
    };
    i += 1;
  };
  return 0;
};

//@T is_symetric
//@U template &lt;typename T&gt; bool is_symetric(std::vector&lt;T&gt; &x)
//@X
//@D Returns 1 if the vector is symetric, 0 if not. See examples.
//@A x : is the input vector of any type
//@X
//@E std::vector&lt;int&gt; vec = {0, 1, 2, 43, 2, 1, 0};
//@E bool out = is_symetric(vec);
//@E 1
//@E vec = {0, 1, 2, 2, 1, 0};
//@E out = is_symetric(vec);
//@E 1
//@E vec = {0, 1, 2, 2, 22, 0};
//@E out = is_symetric(vec);
//@E 0
//@X

template <typename T> bool is_symetric(std::vector<T> &x) {
  int cnt = x.size();
  int cnt2;
  if (cnt % 2  == 0) {
    cnt /= 2;
    cnt -= 1;
    cnt2 = cnt + 1;
    while (cnt > -1) {
      if (x[cnt] != x[cnt2]) {
        return 0;
      };
      cnt -= 1;
      cnt2 += 1;
    };
    return 1;
  } else {
    cnt /= 2;
    cnt -= 1;
    cnt2 = cnt + 2;
    while (cnt > -1) {
      if (x[cnt] != x[cnt2]) {
        return 0;
      };
      cnt -= 1;
      cnt2 += 1;
    };
    return 1;
  };
};

//@T all_comb
//@U std::vector&lt;std::vector&lt;bool&gt;&gt; all_comb(unsigned int &k, unsigned int &n)
//@X
//@D Returns all the combinations of k elements in a set of n elements.
//@A k : is the k value
//@A n : is the total number of the set
//@X
//@E unsigned int k = 5;
//@E unsigned int n = 9;
//@E std::vector&lt;std::vector&lt;bool&gt;&gt; outmatr = all_comb(k, n);
//@E int i2;
//@E for (int i = 0; i &lt; outmatr.size(); ++i) {
//@E   for (i2 = 0; i2 &lt; outmatr[0].size(); ++i2) {
//@E     std::cout &lt;&lt; outmatr[i][i2] &lt;&lt;< " ";
//@E   };
//@E   std::cout &lt;&lt; "\n";
//@E };
//@E 1 1 1 1 1 0 0 0 0
//@E 1 1 1 1 0 1 0 0 0
//@E 1 1 1 1 0 0 1 0 0
//@E 1 1 1 1 0 0 0 1 0
//@E 1 1 1 1 0 0 0 0 1
//@E 1 1 1 0 1 1 0 0 0
//@E 1 1 1 0 1 0 1 0 0
//@E 1 1 1 0 1 0 0 1 0
//@E 1 1 1 0 1 0 0 0 1
//@E 1 1 1 0 0 1 1 0 0
//@E 1 1 1 0 0 1 0 1 0
//@E 1 1 1 0 0 1 0 0 1
//@E 1 1 1 0 0 0 1 1 0
//@E 1 1 1 0 0 0 1 0 1
//@E 1 1 1 0 0 0 0 1 1
//@E 1 1 0 1 1 1 0 0 0
//@E 1 1 0 1 1 0 1 0 0
//@E 1 1 0 1 1 0 0 1 0
//@E 1 1 0 1 1 0 0 0 1
//@E 1 1 0 1 0 1 1 0 0
//@E 1 1 0 1 0 1 0 1 0
//@E 1 1 0 1 0 1 0 0 1
//@E 1 1 0 1 0 0 1 1 0
//@E 1 1 0 1 0 0 1 0 1
//@E 1 1 0 1 0 0 0 1 1
//@E 1 1 0 0 1 1 1 0 0
//@E 1 1 0 0 1 1 0 1 0
//@E 1 1 0 0 1 1 0 0 1
//@E 1 1 0 0 1 0 1 1 0
//@E 1 1 0 0 1 0 1 0 1
//@E 1 1 0 0 1 0 0 1 1
//@E 1 1 0 0 0 1 1 1 0
//@E 1 1 0 0 0 1 1 0 1
//@E 1 1 0 0 0 1 0 1 1
//@E 1 1 0 0 0 0 1 1 1
//@E 1 0 1 1 1 1 0 0 0
//@E 1 0 1 1 1 0 1 0 0
//@E 1 0 1 1 1 0 0 1 0
//@E 1 0 1 1 1 0 0 0 1
//@E 1 0 1 1 0 1 1 0 0
//@E 1 0 1 1 0 1 0 1 0
//@E 1 0 1 1 0 1 0 0 1
//@E 1 0 1 1 0 0 1 1 0
//@E 1 0 1 1 0 0 1 0 1
//@E 1 0 1 1 0 0 0 1 1
//@E 1 0 1 0 1 1 1 0 0
//@E 1 0 1 0 1 1 0 1 0
//@E 1 0 1 0 1 1 0 0 1
//@E 1 0 1 0 1 0 1 1 0
//@E 1 0 1 0 1 0 1 0 1
//@E 1 0 1 0 1 0 0 1 1
//@E 1 0 1 0 0 1 1 1 0
//@E 1 0 1 0 0 1 1 0 1
//@E 1 0 1 0 0 1 0 1 1
//@E 1 0 1 0 0 0 1 1 1
//@E 1 0 0 1 1 1 1 0 0
//@E 1 0 0 1 1 1 0 1 0
//@E 1 0 0 1 1 1 0 0 1
//@E 1 0 0 1 1 0 1 1 0
//@E 1 0 0 1 1 0 1 0 1
//@E 1 0 0 1 1 0 0 1 1
//@E 1 0 0 1 0 1 1 1 0
//@E 1 0 0 1 0 1 1 0 1
//@E 1 0 0 1 0 1 0 1 1
//@E 1 0 0 1 0 0 1 1 1
//@E 1 0 0 0 1 1 1 1 0
//@E 1 0 0 0 1 1 1 0 1
//@E 1 0 0 0 1 1 0 1 1
//@E 1 0 0 0 1 0 1 1 1
//@E 1 0 0 0 0 1 1 1 1
//@E 0 1 1 1 1 1 0 0 0
//@E 0 1 1 1 1 0 1 0 0
//@E 0 1 1 1 1 0 0 1 0
//@E 0 1 1 1 1 0 0 0 1
//@E 0 1 1 1 0 1 1 0 0
//@E 0 1 1 1 0 1 0 1 0
//@E 0 1 1 1 0 1 0 0 1
//@E 0 1 1 1 0 0 1 1 0
//@E 0 1 1 1 0 0 1 0 1
//@E 0 1 1 1 0 0 0 1 1
//@E 0 1 1 0 1 1 1 0 0
//@E 0 1 1 0 1 1 0 1 0
//@E 0 1 1 0 1 1 0 0 1
//@E 0 1 1 0 1 0 1 1 0
//@E 0 1 1 0 1 0 1 0 1
//@E 0 1 1 0 1 0 0 1 1
//@E 0 1 1 0 0 1 1 1 0
//@E 0 1 1 0 0 1 1 0 1
//@E 0 1 1 0 0 1 0 1 1
//@E 0 1 1 0 0 0 1 1 1
//@E 0 1 0 1 1 1 1 0 0
//@E 0 1 0 1 1 1 0 1 0
//@E 0 1 0 1 1 1 0 0 1
//@E 0 1 0 1 1 0 1 1 0
//@E 0 1 0 1 1 0 1 0 1
//@E 0 1 0 1 1 0 0 1 1
//@E 0 1 0 1 0 1 1 1 0
//@E 0 1 0 1 0 1 1 0 1
//@E 0 1 0 1 0 1 0 1 1
//@E 0 1 0 1 0 0 1 1 1
//@E 0 1 0 0 1 1 1 1 0
//@E 0 1 0 0 1 1 1 0 1
//@E 0 1 0 0 1 1 0 1 1
//@E 0 1 0 0 1 0 1 1 1
//@E 0 1 0 0 0 1 1 1 1
//@E 0 0 1 1 1 1 1 0 0
//@E 0 0 1 1 1 1 0 1 0
//@E 0 0 1 1 1 1 0 0 1
//@E 0 0 1 1 1 0 1 1 0
//@E 0 0 1 1 1 0 1 0 1
//@E 0 0 1 1 1 0 0 1 1
//@E 0 0 1 1 0 1 1 1 0
//@E 0 0 1 1 0 1 1 0 1
//@E 0 0 1 1 0 1 0 1 1
//@E 0 0 1 1 0 0 1 1 1
//@E 0 0 1 0 1 1 1 1 0
//@E 0 0 1 0 1 1 1 0 1
//@E 0 0 1 0 1 1 0 1 1
//@E 0 0 1 0 1 0 1 1 1
//@E 0 0 1 0 0 1 1 1 1
//@E 0 0 0 1 1 1 1 1 0
//@E 0 0 0 1 1 1 1 0 1
//@E 0 0 0 1 1 1 0 1 1
//@E 0 0 0 1 1 0 1 1 1
//@E 0 0 0 1 0 1 1 1 1
//@E 0 0 0 0 1 1 1 1 1
//@E std::cout &lt;&lt; outmatr.size() &lt;&lt; "\n";
//@E 126
//@X

std::vector<std::vector<bool>> all_comb(unsigned int &k, unsigned int &n) {
  std::vector<std::vector<bool>> matr = {};
  std::vector<unsigned int> cur_idx = {};
  std::vector<unsigned int> max_idx = {};
  std::vector<bool> cur_v = {};
  std::vector<bool> ref_v = {};
  unsigned int i = 0;
  const unsigned int ref_k = k - 1;
  int idx = ref_k;
  unsigned int idx_val;
  while (i < k) {
    max_idx.push_back(n - k + i);
    cur_idx.push_back(i);
    ref_v.push_back(0);
    i += 1;
  };
  while (i < n){
    ref_v.push_back(0);
    i += 1;
  };
  while (cur_idx[ref_k] < n) {
    while (cur_idx[ref_k] != n) {
      cur_v = ref_v;
      for (i = 0; i < k; ++i) {
        cur_v[cur_idx[i]] = 1;
      };
      matr.push_back(cur_v);
      cur_idx[ref_k] += 1;
    };
    idx = ref_k - 1;
    while (cur_idx[idx] == max_idx[idx] & idx > -1) {
      idx -= 1;
    };
    if (idx < 0) {
      idx = 0;
    };
    idx_val = cur_idx[idx] + 1;
    while (idx < k) {
      cur_idx[idx] = idx_val;
      idx += 1;
      idx_val += 1;
    };
  };
  return matr;
};

//@T all_comb_iter
//@U unsigned int all_comb_iter(std::vector&lt;bool&gt; &x)
//@X
//@D Returns the number of iterations to find the input boolean vector according to all_comb algorithm
//@A x : is the input boolean vector
//@X
//@E std::vector&lt;bool&gt; teste_dq = {1, 0, 1, 1, 1, 1, 0};
//@E unsigned int out = all_comb_iter(teste_dq);
//@E 11
//@X

unsigned int all_comb_iter(std::vector<bool> &x) {
  unsigned int n = x.size();
  unsigned int k = 0;
  unsigned int cnt = 0;
  std::vector<unsigned int> cur_idx = {};
  std::vector<unsigned int> max_idx = {};
  std::vector<bool> cur_v = {};
  std::vector<bool> ref_v = {};
  unsigned int i;
  for (i = 0; i < n; ++i) {
    if (x[i] == 1) {
      k += 1;
    };
  };
  const unsigned int ref_k = k - 1;
  int idx = ref_k;
  unsigned int idx_val;
  i = 0;
  while (i < k) {
    max_idx.push_back(n - k + i);
    cur_idx.push_back(i);
    ref_v.push_back(0);
    i += 1;
  };
  while (i < n){
    ref_v.push_back(0);
    i += 1;
  };
  while (cur_idx[ref_k] < n) {
    while (cur_idx[ref_k] != n) {
      cur_v = ref_v;
      for (i = 0; i < k; ++i) {
        cur_v[cur_idx[i]] = 1;
      };
      cnt += 1;
      if (cur_v == x) {
        return cnt;
      };
      cur_idx[ref_k] += 1;
    };
    idx = ref_k - 1;
    while (cur_idx[idx] == max_idx[idx] & idx > -1) {
      idx -= 1;
    };
    if (idx < 0) {
      idx = 0;
    };
    idx_val = cur_idx[idx] + 1;
    while (idx < k) {
      cur_idx[idx] = idx_val;
      idx += 1;
      idx_val += 1;
    };
  };
  return 0;
};

//@T all_comb_iterdq
//@U unsigned int all_comb_iterdq(std::deque&lt;bool&gt; &x)
//@X
//@D Returns the number of iterations to find the input boolean deque according to all_comb algorithm
//@A x : is the input boolean deque
//@X
//@E std::deque&lt;bool&gt; teste_dq = {1, 0, 1, 1, 1, 1, 0};
//@E unsigned int out = all_comb_iterdq(teste_dq);
//@E 11
//@X

unsigned int all_comb_iterdq(std::deque<bool> &x) {
  unsigned int n = x.size();
  unsigned int k = 0;
  unsigned int cnt = 0;
  std::deque<unsigned int> cur_idx = {};
  std::deque<unsigned int> max_idx = {};
  std::deque<bool> cur_v = {};
  std::deque<bool> ref_v = {};
  unsigned int i;
  for (i = 0; i < n; ++i) {
    if (x[i] == 1) {
      k += 1;
    };
  };
  const unsigned int ref_k = k - 1;
  int idx = ref_k;
  unsigned int idx_val;
  i = 0;
  while (i < k) {
    max_idx.push_back(n - k + i);
    cur_idx.push_back(i);
    ref_v.push_back(0);
    i += 1;
  };
  while (i < n){
    ref_v.push_back(0);
    i += 1;
  };
  while (cur_idx[ref_k] < n) {
    while (cur_idx[ref_k] != n) {
      cur_v = ref_v;
      for (i = 0; i < k; ++i) {
        cur_v[cur_idx[i]] = 1;
      };
      cnt += 1;
      if (cur_v == x) {
        return cnt;
      };
      cur_idx[ref_k] += 1;
    };
    idx = ref_k - 1;
    while (cur_idx[idx] == max_idx[idx] & idx > -1) {
      idx -= 1;
    };
    if (idx < 0) {
      idx = 0;
    };
    idx_val = cur_idx[idx] + 1;
    while (idx < k) {
      cur_idx[idx] = idx_val;
      idx += 1;
      idx_val += 1;
    };
  };
  return 0;
};

//@T bool_gen
//@U std::vector&lt;bool&gt; bool_gen(unsigned int &k, unsigned int &n, double seed = 0)
//@X
//@D Returns a boolean vector of size n, with k elements equal to 1
//@A k : is the number of elements that should equal to 1
//@A n : is the size of the vector
//@A seed : 0, if the vector should be randomly generated, strictly positive values either
//@X
//@E unsigned int k = 5;
//@E unsigned int n = 17;
//@E std::vector&lt;bool&gt; out = bool_gen(k, n, 0);
//@E print_nvec(out);
//@E :0: 0 1 1 0 1 0 0 1 0 0 0 0 0 0 0 0 1
//@X

//@L2 Binary conversions

//@T int_to_binarydq
//@U std::deque&lt;bool&gt; int_to_binarydq(unsigned int x)
//@X
//@D Converts an unsigned int to a binary format as a boolean deque
//@A x : is the input unsigned int
//@X
//@E std::deque&lt;bool&gt; rtn_dq  = int_to_binarydq(1286);
//@E 1 0 1 0 0 0 0 0 1 1 0
//@X

std::deque<bool> int_to_binarydq(unsigned int x) {
  std::deque<bool> rtn_dq = {};
  while (x > 0) {
    if (x % 2 == 0) {
      rtn_dq.push_front(0);
    } else {
      rtn_dq.push_front(1);
    };
    x /= 2;
  };
  return rtn_dq;
};

//@T binarydq_to_int
//@U unsigned int binarydq_to_int(std::deque&lt;bool&gt; &x)
//@X
//@D Converts a binary format as a boolean deque to an unsigned int
//@A x : is the input boolean std deque
//@X
//@E std::deque&lt;bool&gt; dq_input = {1, 0, 1, 0, 0, 0, 0, 0, 1, 1, 0};
//@E unsigned int out = binarydq_to_int(rtn_dq);
//@E 1286
//@X

unsigned int binarydq_to_int(std::deque<bool> &x) {
  unsigned int rtn_int = 0;
  std::deque<bool> ref_dq = {};
  const unsigned int ref_n = x.size() - 1;
  ref_dq.resize(ref_n + 1, 0);
  int i;
  while (ref_dq != x) {
    i = ref_n;
    while (ref_dq[i] == 1) {
      ref_dq[i] = 0;
      i -= 1;
    };
    ref_dq[i] = 1;
    rtn_int += 1;
  };
  return rtn_int;
};

//@L2 Unique string from int

#if 0
//@T letter_to_nb
//@U unsigned int letter_to_nb(std::string &x)
//@X
//@D Returns an int corresponding to the input letter.
//@D This algorithm can be used to get which unique id number it is, if we know that it has been generated with <a href="#nb_to_letter">nb_to_letter</a> function
//@A x : is the input string
//@X
//@E std::string inpt_str = "ecfy";
//@E unsigned int rtn_val = letter_to_nb(inpt_str);
//@E std::cout &lt;&lt; rtn_val &lt;&lt; "\n";
//@E 90089
//@E 
//@E inpt_str = "ajf";
//@E rtn_val = letter_to_nb(inpt_str);
//@E std::cout &lt;&lt; rtn_val &lt;&lt; "\n";
//@E 
//@E 942
//@X
#endif

unsigned int letter_to_nb(std::string &x) {
  std::string alphabet_v = "abcdefghijklmnopqrstuvwxyz";
  char cur_chr;
  unsigned int rtn_val = 0;
  unsigned int cnt2;
  const unsigned int n = x.length();
  for (int cnt = n - 1; cnt > -1; --cnt) {
    cur_chr = x[cnt];
    cnt2 = 0;
    while (alphabet_v[cnt2] != cur_chr) {
      cnt2 += 1;
    };
    cnt2 += 1;
    rtn_val += (cnt2 * std::pow(26, (n - 1 - cnt)));
  };
  return rtn_val;
};

//@T nb_to_letter
//@U std::string nb_to_letter(unsigned int &x)
//@X
//@D Returns a unique combination of letters based on an input number, see examples.
//@A x : is the input number
//@X
//@E unsigned int inpt_val = 702;
//@E std::string out_val = nb_to_letter(inpt_val);
//@E std::cout &lt;&lt; out_val &lt;&lt; "\n";
//@E
//@E "zz"
//@E
//@E unsigned int inpt_val = 104601;
//@E std::string out_val = nb_to_letter(inpt_val);
//@E std::cout &lt;&lt; out_val &lt;&lt; "\n";
//@E
//@E "exsc"
//@E
//@X

std::string nb_to_letter(unsigned int &x) {
  std::string alphabet_v = "abcdefghijklmnopqrstuvwxyz";
  std::string rtn_str = "";
  unsigned int cnt = 1;
  unsigned int rest_val2;
  unsigned int rest_val;
  unsigned int cur_val = 0;
  while (cur_val < x) {
    cur_val = std::pow(26, cnt);
    rest_val = x % cur_val;
    if (rest_val > 0) {
      rest_val2 = rest_val / std::pow(26, cnt - 1); 
      rtn_str.insert(0, 1, alphabet_v[rest_val2 - 1]);
    } else {
      rest_val = std::pow(26, cnt);
      rtn_str.insert(0, 1, 'z');
    };
    x -= rest_val;
    cnt += 1;
  };
  return rtn_str;
};

//@L1 JSON

//@T ValidateJSON
//@U bool ValidateJSON(std::string &x)
//@X
//@D Returns 1 if the JSon is valid, 0 if not.
//@A x : is the std::string representing the JSon 
//@X
//@E std::string x = "{\"name\" : \"JohnY Doe\",\"age\": 30,\"isStudent\": false,\"courses\": [\"Math\", {\"prefered1\"    :   \"Science\", \"prefered2\"  : \"Mathsss\", \"intricated_list\" : [1, \"2\", 2, {\"AAA\" : 22}, 34]}, \"History\"],\"address\": {\"street\": \"123 Main St\",\"city\": \"Poissy\",\"postalCode\": 78300},\"graduationYear\": null}";
//@E bool is_ok = ValidateJSON(x);
//@E std::cout &lt;&lt; "is_ok: " &lt;&lt; is_ok &lt;&lt; "\n";
//@E 1
//@E x = "{\"name\" : \"JohnY Doe\",\"age\": 30,\"isStudent\": false,\"courses\": [\"Math\", {\"prefered1\"    :   \"Science\", \"prefered2\"  : \"Mathsss\", \"intricated_list : [1, \"2\", 2, {\"AAA\" : 22}, 34]}, \"History\"],\"address\": {\"street\": \"123 Main St\",\"city\": \"Poissy\",\"postalCode\": 78300},\"graduationYear\": null}";
//@E is_ok = ValidateJSON(x);
//@E std::cout &lt;&lt; "is_ok: " &lt;&lt; is_ok &lt;&lt; "\n";
//@E 0
//@X

bool ValidateJSON(std::string &x) {
  const int n = x.size();
  bool is_nb;
  int cnt_bgn = 0;
  int cnt_end = 0;
  for (int i = 0; i < n; i++) {
    if (x[i] == '{') {
      cnt_bgn += 1;
    } else if (x[i] == '}') {
      cnt_end += 1;
    };
  };
  bool is_boolean;
  int untl;
  bool new_object;
  bool alrd_space = 0;
  std::string cur_str = "";
  if (cnt_bgn != cnt_end) {
    return 0;
  };
  bool alrd_dot;
  int i3;
  int i2 = 1;
  int depth_lists = 0;
  int depth_objs = 0;
  std::vector<int> depth_lists_vec = {0};
  std::vector<int> depth_objs_vec = {0};
  bool search_for_key = 1;
  std::vector<char> ref_nb = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9'};
  while (i2 < n) {
    if (search_for_key) {
      while (x[i2] != '"') {
        if (x[i2] != ' ') {
          return 0;
        };
        i2 += 1;
        if (i2 == n) {
          return 0;
        };
      };
      i2 += 1;
      if (i2 == n) {
        return 0;
      };
      while (x[i2] != '"') {
        i2 += 1;
        if (i2 == n) {
          return 0;
        };
      };
      i2 += 1;
      if (i2 == n) {
        return 0;
      };
      while (x[i2] != ':') {
        if (i2 == n) {
          return 0;
        };
        if (x[i2] != ' ') {
          return 0;
        };
        i2 += 1;
      };
      i2 += 1;
      if (i2 == n) {
        return 0;
      };
    };
    is_nb = 0;
    is_boolean = 0;
    new_object = 0;
    cur_str = "";
    while (x[i2] != '"' && x[i2] != '[') {
      if (x[i2] == '{') {
        depth_objs = depth_lists_vec[depth_lists_vec.size() - 1] + 1;
        depth_objs_vec.push_back(depth_objs);
        i2 += 1;
        new_object = 1;
        break;
      };
      if (x[i2] != ' ') {
        cur_str.push_back(x[i2]);
        if (cur_str == "t" || cur_str == "f" || cur_str == "n") {
          is_boolean = 1;
          i2 += 1;
          break;
        };
        for (i3 = 0; i3 < 10; i3++) {
          if (ref_nb[i3] == x[i2]) {
            is_nb = 1;
            break;
          };
        };
        if (!is_nb) {
          return 0;
        };
        break;
      };
      i2 += 1;
      if (i2 == n) {
        return 0;
      };
    };
    if (!new_object) {
      if (x[i2] == '[') {
        depth_lists = depth_objs_vec[depth_objs_vec.size() - 1] + 1;
        depth_lists_vec.push_back(depth_lists);
        i2 += 1;
        if (i2 == n) {
          return 0;
        };
        while (x[i2] == ' ') {
          i2 += 1;
          if (i2 == n) {
            return 0;
          };
        };
        if (x[i2] == '{') {
          depth_objs = depth_lists_vec[depth_lists_vec.size() - 1];
          depth_objs_vec.push_back(depth_objs);
          i2 += 1;
          new_object = 1;
        };
        if (!new_object) {
          while (x[i2] == '[') {
            depth_lists += 1;
            depth_lists_vec.push_back(depth_lists);
            i2 += 1;
            if (i2 == n) {
              return 0;
            };
            while (x[i2] == ' ') {
              i2 += 1;
              if (i2 == n) {
                return 0;
              };
            };
            if (x[i2] == '{') {
              depth_objs = depth_lists_vec[depth_lists_vec.size() - 1] + 1;
              depth_objs_vec.push_back(depth_objs);
              i2 += 1;
              new_object = 1;
              break;
            };
            if (x[i2] != ' ') {
              return 0;
            };
          };
          if (!new_object) {
            for (i3 = 0; i3 < 10; i3++) {
              if (x[i2] == ref_nb[i3]) {
                is_nb = 1;
                break;
              };
            };
            if (!is_nb) {
              cur_str = "";
              if (x[i2] == 't' || x[i2] == 'f' || x[i2] == 'n') {
                std::cout << "ici\n";
                cur_str.push_back(x[i2]);
                is_boolean = 1;
                i2 += 1;
              };
            };
          };
        };
      };
      if (x[i2] == '"' && !new_object) {
        i2 += 1;
        while (x[i2] != '"') {
          i2 += 1;
          if (i2 == n) {
            return 0;
          };
        };
        i2 += 1;
        if (i2 == n) {
          return 0;
        };
        if (x[i2] != ',') {
          if (x[i2] == ' ') {
            while (x[i2] == ' ') {
              i2 += 1;
              if (i2 == n) {
                return 0;
              };
            };
          };
          if (x[i2] != ']') {
            if (x[i2] != '}') {
              return 0;
            } else {
              depth_objs_vec.pop_back();
              i2 += 1;
              if (i2 == n) {
                return 1;
              };
              alrd_space = 0;
              while (x[i2] != ',') {
                alrd_space = 0;
                while (x[i2] == ' ') {
                  i2 += 1;
                  alrd_space = 1;
                  if (i2 == n) {
                    return 0;
                  };
                };
                while (x[i2] == '}') {
                  i2 += 1;
                  if (i2 == n) {
                    return 1;
                  };
                  depth_objs_vec.pop_back();
                  alrd_space = 0;
                  while (x[i2] == ' ') {
                    alrd_space = 1;
                    i2 += 1;
                    if (i2 == n) {
                      return 0;
                    };
                  };
                };
                if (x[i2] == ',') {
                  break;
                };
                if (x[i2] == ']') {
                  while (x[i2] == ']') {
                    depth_lists_vec.pop_back();
                    i2 += 1;
                    if (i2 == n) {
                      return 0;
                    };
                    alrd_space = 0;
                    while (x[i2] == ' ') {
                      alrd_space = 1;
                      i2 += 1;
                      if (i2 == n) {
                        return 0;
                      };
                    };
                  };
                } else {
                  break;
                };
                if (x[i2] != ',' && x[i2] != ']') {
                  return 0;
                };
              };
              if (alrd_space) {
                return 0;
              };
            };
          } else if (depth_lists_vec.size() > 1) {
            depth_lists_vec.pop_back();
            i2 += 1;
            alrd_space = 0;
            while (x[i2] != ',') {
              alrd_space = 0;
              while (x[i2] == ' ') {
                alrd_space = 1;
                i2 += 1;
                if (i2 == n) {
                  return 0;
                };
              };
              while (x[i2] == ']') {
                depth_lists_vec.pop_back();
                i2 += 1;
                if (i2 == n) {
                  return 0;
                };
                alrd_space = 0;
                while (x[i2] == ' ') {
                  alrd_space = 1;
                  i2 += 1;
                  if (i2 == n) {
                    return 0;
                  };
                };
              };
              if (x[i2] == ',') {
                break;
              };
              if (x[i2] == '}') {
                while (x[i2] == '}') {
                  i2 += 1;
                  if (i2 == n) {
                    return 1;
                  };
                  depth_objs_vec.pop_back();
                  alrd_space = 0;
                  while (x[i2] == ' ') {
                    alrd_space = 1;
                    i2 += 1;
                    if (i2 == n) {
                      return 0;
                    };
                  };
                };
              } else {
                break;
              };
              if (x[i2] != ',' && x[i2] != ']') {
                return 0;
              };
            };
            if (alrd_space) {
              return 0;
            };
          } else {
            return 0;
          };
        };
        i2 += 1;
        if (i2 == n) {
          return 0;
        };
      } else if (is_nb && !new_object) {
        alrd_dot = 0;
        while (x[i2] != ',') {
          is_nb = 0;
          for (i3 = 0; i3 < 10; i3++) {
            if (ref_nb[i3] == x[i2]) {
              is_nb = 1;
              break;
            };
          };
          if (!is_nb) {
            alrd_space = 0;
            if (x[i2] == ' ') {
              alrd_space = 1;
              while (x[i2] == ' ') {
                i2 += 1;
                if (i2 == n) {
                  return 0;
                };
              };
            };
            if (x[i2] == '.') {
              if (alrd_dot) {
                return 0;
              };
              if (alrd_space) {
                return 0;
              };
              alrd_dot = 1;
            } else if (x[i2] != ']') {
              if (x[i2] != '}') {
                return 0;
              } else {
                alrd_space = 0;
                i2 += 1;
                if (i2 == n) {
                  return 1;
                };
                depth_objs_vec.pop_back();
                while (x[i2] != ',') {
                  alrd_space = 0;
                  while (x[i2] == ' ') {
                    alrd_space = 1;
                    i2 += 1;
                    if (i2 == n) {
                      return 0;
                    }
                  };
                  while (x[i2] == '}') {
                    i2 += 1;
                    if (i2 == n) {
                      return 1;
                    };
                    depth_objs_vec.pop_back();
                    alrd_space = 0;
                    while (x[i2] == ' ') {
                      alrd_space = 1;
                      i2 += 1;
                      if (i2 == n) {
                        return  0;
                      };
                    };
                  };
                  if (x[i2] == ',') {
                    break;
                  };
                  if (x[i2] == ']') {
                    while (x[i2] == ']') {
                      depth_lists_vec.pop_back();
                      i2 += 1;
                      if (i2 == n) {
                        return 0;
                      };
                      alrd_space = 0;
                      while (x[i2] == ' ') {
                        alrd_space = 1;
                        i2 += 1;
                        if (i2 == n) {
                          return 0;
                        };
                      };
                    };
                  } else {
                    break;
                  };
                  if (x[i2] != ',' && x[i2] != ']') {
                    return 0;
                  };
                };
                if (alrd_space) {
                  return 0;
                };
                break;
              };
            } else if (depth_lists_vec.size() > 1) {
              alrd_space = 0;
              depth_lists_vec.pop_back();
              i2 += 1;
              while (x[i2] != ',') {
                alrd_space = 0;
                while (x[i2] == ' ') {
                  i2 += 1;
                  alrd_space = 1;
                  if (i2 == n) {
                    return 0;
                  };
                };
                while (x[i2] == ']') {
                  depth_lists_vec.pop_back();
                  i2 += 1;
                  if (i2 == n) {
                    return 0;
                  };
                  alrd_space = 0;
                  while (x[i2] == ' ') {
                    i2 += 1;
                    alrd_space = 1;
                    if (i2 == n) {
                      return 0;
                    };
                  };
                };
                if (x[i2] == ',') {
                  break;
                };
                if (x[i2] == '}') {
                  while (x[i2] == '}') {
                    i2 += 1;
                    if (i2 == n) {
                      return 1;
                    };
                    depth_objs_vec.pop_back();
                    alrd_space = 0;
                    while (x[i2] == ' ') {
                      alrd_space = 1;
                      i2 += 1;
                      if (i2 == n) {
                        return 0;
                      };
                    };
                  };
                } else {
                  break;
                };
                if (x[i2] != ',' && x[i2] != ']') {
                  return 0;
                };
              };
              if (alrd_space) {
                return 0;
              };
              break;
            } else {
              return 0;
            };
          };
          i2 += 1;
        };
        i2 += 1;
        if (i2 == n) {
          return 0;
        };
      } else if (is_boolean && !new_object) {
        if (cur_str == "f") {
          untl = i2 + 4;
          while (i2 < untl) {
            cur_str.push_back(x[i2]);
            i2 += 1;
            if (i2 == n) {
              return 0;
            };
          };
          if (cur_str != "false") {
            return 0;
          };
        } else if (cur_str == "t") {
          untl = i2 + 3;
          while (i2 < untl) {
            cur_str.push_back(x[i2]);
            i2 += 1;
            if (i2 == n) {
              return 0;
            };
          };
          if (cur_str != "true") {
            return 0;
          };
        } else {
          untl = i2 + 3;
          while (i2 < untl) {
            cur_str.push_back(x[i2]);
            i2 += 1;
            if (i2 == n) {
              return 0;
            };
          };
          if (cur_str != "null") {
            return 0;
          };
        };
        if (x[i2] != ',') {
          while (x[i2] == ' ') {
            i2 += 1;
            if (i2 == n) {
              return 0;
            };
          };
          alrd_space = 0;
          if (x[i2] != ']') {
            if (x[i2] != '}') {
              return 0;
            } else {
              i2 += 1;
              if (i2 == n) {
                return 1;
              };
              alrd_space = 0;
              depth_objs_vec.pop_back();
              while (x[i2] != ',') {
                alrd_space = 1;
                while (x[i2] == ' ') {
                  alrd_space = 1;
                  i2 += 1;
                  if (i2 == n) {
                    return 0;
                  };
                };
                while (x[i2] == '}') {
                  i2 += 1;
                  if (i2 == n) {
                    return 1;
                  };
                  depth_objs_vec.pop_back();
                  alrd_space = 0;
                  while (x[i2] == ' ') {
                    alrd_space = 1;
                    i2 += 1;
                    if (i2 == n) {
                      return 0;
                    };
                  };
                };
                if (x[i2] == ',') {
                  break;
                };
                if (x[i2] == ']') {
                  while (x[i2] == ']') {
                    depth_lists_vec.pop_back();
                    i2 += 1;
                    if (i2 == n) {
                      return 0;
                    };
                    alrd_space = 0;
                    while (x[i2] == ' ') {
                      alrd_space = 1;
                      i2 += 1;
                      if (i2 == n) {
                        return 0;
                      };
                    };
                  };
                } else {
                  break;
                };
                if (x[i2] != ',' && x[i2] != ']') {
                  return 0;
                };
              };
              if (alrd_space) {
                return 0;
              };
            };
          } else if (depth_lists_vec.size() > 1) {
            depth_lists_vec.pop_back();
            i2 += 1;
            alrd_space = 0;
            while (x[i2] != ',') {
              alrd_space = 0;
              while (x[i2] == ' ') {
                alrd_space = 1;
                i2 += 1;
                if (i2 == n) {
                  return 0;
                };
              };
              while (x[i2] == ']') {
                depth_lists_vec.pop_back();
                i2 += 1;
                if (i2 == n) {
                  return 0;
                };
                alrd_space = 0;
                while (x[i2] == ' ') {
                  alrd_space = 1;
                  i2 += 1;
                  if (i2 == n) {
                    return 0;
                  };
                };
              };
              if (x[i2] == ',') {
                break;
              };
              if (x[i2] == '}') {
                while (x[i2] == '}') {
                  i2 += 1;
                  if (i2 == n) {
                    return 1;
                  };
                  depth_objs_vec.pop_back();
                  alrd_space = 0;
                  while (x[i2] == ' ') {
                    alrd_space = 1;
                    i2 += 1;
                    if (i2 == n) {
                      return 0;
                    };
                  };
                };
              } else {
                break;
              };
              if (x[i2] != ',' && x[i2] != ']') {
                return 0;
              };
            };
            if (alrd_space) {
              return 0;
            };
          } else {
            return 0;
          };
        };
        i2 += 1;
        if (i2 == n) {
          return 0;
        };
      } else if (!new_object) {
        return 0;
      };
    };
    if (depth_lists_vec[depth_lists_vec.size() - 1] > depth_objs_vec[depth_objs_vec.size() - 1]) {
      search_for_key = 0;
    } else {
      search_for_key = 1;
    };
  };
  return 1;
};

//@T GetStringJSON
//@U std::string GetStringJSON(std::string &x, std::vector&lt;std::string&gt; keys_vec)
//@X
//@D Allows to get the string value from a JSON key.
//@A x : is the string representing the JSON data
//@A keys_vec : is a string vector containing all the keys in order
//@X
//@E std::string x = "{\"name\" : \"JohnY Doe\",\"age\": 30,\"isStudent\": false,\"courses\": [\"Math\",   {\"prefered1\"    :   \"Science\", \"prefered2\"  : \"Mathsss\",    \"intricated_list\" : [ \"oui\",  {\"AAA\" : \"22\", \"AA\" : [{\"BB\" : \"okok\"}, 1, 2.23] }, 34 ]} , \"History\"],\"address\": {\"street\": \"123 Main St\",\"city\": \"Poissy\",\"postalCode\": 78300}, \"graduationYear\": \"2021\", \"price\" : \"22\"}";
//@E std::vector&lt;std::string&gt; keys_vec = {"courses", "intricated_list", "AA", "BB"};
//@E std::string rslt = GetStringJSON(x, keys_vec);
//@E std::cout &lt;&lt; rslt &lt;&lt; "\n";
//@E okok
//@E keys_vec = {"address", "city"};
//@E rslt = GetStringJSON(x, keys_vec);
//@E std::cout &lt;&lt; rslt &lt;&lt; "\n";
//@E Poissy
//@E keys_vec = {"price"};
//@E rslt = GetStringJSON(x, keys_vec);
//@E std::cout &lt;&lt; rslt &lt;&lt; "\n";
//@E 22 
//@X

std::string GetStringJSON(std::string &x, std::vector<std::string> keys_vec) {
  int i = 0;
  int cur_i;
  const int n = keys_vec.size();
  char bgn_chr = '{';
  char end_chr = '}';
  std::vector<std::vector<unsigned int>> rtn_vec = Parser_tokenizer_full(x, bgn_chr, end_chr);
  std::vector<unsigned int> par_vec = rtn_vec[0];
  unsigned int cur_id;
  std::vector<unsigned int> idx_vec = rtn_vec[1];
  int val_crochet;
  std::string cur_key = "";
  std::string cmp_key = "";
  std::string rtn_val = "";
  for (int i2 = 0; i2 < n; i2++) {
    cur_key = keys_vec[i2];
    cur_i = idx_vec[i] + 1;
    while (cur_i < idx_vec[i + 1]) {
      while (x[cur_i] != '"') {
        if (x[cur_i] == '[') {
          val_crochet = 1;
          cur_i += 1;
          while (val_crochet > 0) {
            if (x[cur_i] == '{') {
              i += 1;
            } else if (x[cur_i] == '}') {
              i += 1;
            } else if (x[cur_i] == '[') {
              val_crochet += 1;
            } else if (x[cur_i] == ']') {
              val_crochet -= 1;
            };
            cur_i += 1;
          };
        };
        cur_i += 1;
      };
      cur_i += 1;
      cmp_key = "";
      while (x[cur_i] != '"') {
        cmp_key.push_back(x[cur_i]);
        cur_i += 1;
      };
      cur_i += 1;
      if (cmp_key == cur_key) {
        if (i2 + 1 == n) {
          while (x[cur_i] != '"') {
            cur_i += 1;
          };
          cur_i += 1;
          while (x[cur_i] != '"') {
            rtn_val.push_back(x[cur_i]);
            cur_i += 1;
          };
          return rtn_val;
        };
        while (idx_vec[i] < cur_i) {
          i += 1;
        };
        break;
      } else {
        while (x[cur_i] != ',' && x[cur_i] != '[') {
          if (x[cur_i] == '{') {
            val_crochet = 1;
            cur_i += 1;
            i += 1;
            while (val_crochet > 0) {
              if (x[cur_i] == '{') {
                i += 1;
                val_crochet += 1;
              } else if (x[cur_i] == '}') {
                i += 1;
                val_crochet -= 1;
              };
              cur_i += 1;
            };
            cur_i -= 1;
          };
          cur_i += 1;
        };
      };
      if (x[cur_i] != '[') {
        cur_i += 1;
      };
    };
    if (cur_i == idx_vec[i + 1]) {
      cur_id = par_vec[i - 1];
      i += 1;
      while (par_vec[i] != cur_id) {
        i += 1;
      };
      i += 1;
    };
  };
  return rtn_val;
};

//@T GetIntJSON
//@U int GetIntJSON(std::string &x, std::vector&lt;std::string&gt; keys_vec)
//@X
//@D Allow to get an int value from a JSON key.
//@A x : is the string representing the JSON data
//@A keys_vec : is the vector containing the keys in order
//@X
//@E  std::string x = "{\"name\" : \"JohnY Doe\",\"age\": 30,\"isStudent\": false,\"courses\": [\"Math\",   {\"prefered1\"    :   \"Science\", \"prefered2\"  : \"Mathsss\",    \"intricated_list\" : [ \"oui\",  {\"AAA\" : \"22\", \"AA\" : [{\"BB\" : \"okok\"}, 1, 2.23] }, 34 ]} , \"History\"],\"address\": {\"street\": \"123 Main St\",\"city\": \"Poissy\",\"postalCode\": 78300}, \"graduationYear\": \"2021\", \"price\" : 22}";
//@E  std::vector&lt;std::string&gt; keys_vec = {"price"};
//@E  int rslt = GetIntJSON(x, keys_vec);
//@E  std::cout &lt;&lt; rslt &lt;&lt; "\n";
//@E 22
//@X

int GetIntJSON(std::string &x, std::vector<std::string> keys_vec) {
  int i = 0;
  int cur_i;
  int rtn_int_val;
  const int n = keys_vec.size();
  std::vector<std::vector<unsigned int>> rtn_vec = Parser_tokenizer_full(x);
  std::vector<unsigned int> par_vec = rtn_vec[0];
  unsigned int cur_id;
  std::vector<unsigned int> idx_vec = rtn_vec[1];
  int val_crochet;
  std::string cur_key = "";
  std::string cmp_key = "";
  std::string rtn_val = "";
  for (int i2 = 0; i2 < n; i2++) {
    cur_key = keys_vec[i2];
    cur_i = idx_vec[i] + 1;
    while (cur_i < idx_vec[i + 1]) {
      while (x[cur_i] != '"') {
        if (x[cur_i] == '[') {
          val_crochet = 1;
          cur_i += 1;
          while (val_crochet > 0) {
            if (x[cur_i] == '{') {
              i += 1;
            } else if (x[cur_i] == '}') {
              i += 1;
            } else if (x[cur_i] == '[') {
              val_crochet += 1;
            } else if (x[cur_i] == ']') {
              val_crochet -= 1;
            };
            cur_i += 1;
          };
        };
        cur_i += 1;
      };
      cur_i += 1;
      cmp_key = "";
      while (x[cur_i] != '"') {
        cmp_key.push_back(x[cur_i]);
        cur_i += 1;
      };
      cur_i += 1;
      if (cmp_key == cur_key) {
        if (i2 + 1 == n) {
          while (x[cur_i] == ' ') {
            cur_i += 1;
          };
          cur_i += 1;
          while (x[cur_i] == ' ') {
            cur_i += 1;
          };
          while (x[cur_i] != ' ') {
            rtn_val.push_back(x[cur_i]);
            cur_i += 1;
            if (x[cur_i] == '}' || x[cur_i] == ']' || x[cur_i] == ',') {
              break;
            };
          };
          rtn_int_val = std::stoi(rtn_val);
          return rtn_int_val;
        };
        while (idx_vec[i] < cur_i) {
          i += 1;
        };
        break;
      } else {
        while (x[cur_i] != ',' && x[cur_i] != '[') {
          if (x[cur_i] == '{') {
            val_crochet = 1;
            cur_i += 1;
            i += 1;
            while (val_crochet > 0) {
              if (x[cur_i] == '{') {
                i += 1;
                val_crochet += 1;
              } else if (x[cur_i] == '}') {
                i += 1;
                val_crochet -= 1;
              };
              cur_i += 1;
            };
            cur_i -= 1;
          };
          cur_i += 1;
        };
      };
      if (x[cur_i] != '[') {
        cur_i += 1;
      };
    };
    if (cur_i == idx_vec[i + 1]) {
      cur_id = par_vec[i - 1];
      i += 1;
      while (par_vec[i] != cur_id) {
        i += 1;
      };
      i += 1;
    };
  };
  return rtn_int_val;
};

#if 0
//@L1 The Matrix Object

//@T Matrix
//@U Matrix matr(2d vector)
//@X
//@D Create a Matrix with variadic number of vectors, each vector represents a column. Supports, transposition, determinant computation, display...
//@A See_below : See below
//@X
//@E See below
//@X

//@T Matrix.create_matr
//@U template &lt;typename T, typename... T2&gt; void create_matr(std::vector&lt;T&gt; &var1, std::vector&lt;T2&gt;&... var2)
//@X
//@D After initializing a matrix with Matrix<int> matr(matr1), you can create it giving it a variadic number of colums, if a column missmatch the expected rownumber, a rep_untl function is applied to it to fit the matrix requirements, see example.
//@A ... : variadic number of columns
//@X
//@E std::vector&lt;int&gt; matr1 = {};
//@E int ncol = 0;
//@E int nrow = 0;
//@E Matrix&lt;int&gt; matr(matr1, nrow, ncol);
//@E 
//@E std::vector&lt;int&gt; col1 = {1, 2, 1, 2, 2, 1};
//@E std::vector&lt;int&gt; col2 = {55, 2, 11, 2, 1, 1};
//@E std::vector&lt;int&gt; col3 = {1, 12, 1, 2, 55, 55};
//@E std::vector&lt;int&gt; col4 = {1, 2, 1, 22, 6, 1};
//@E std::vector&lt;int&gt; col5 = {1, 2, 16, 22, 33, 1};
//@E std::vector&lt;int&gt; col6 = {45, 2, 11, 2, 71, 1};
//@E 
//@E matr.create_matr(col1, col2, col3, col4, col5);
//@E             1           55            1            1            1
//@E             2            2           12            2            2
//@E             1           11            1            1           16
//@E             2            2            2           22           22
//@E             2            1           55            6           33
//@E             1            1           55            1            1
//@X

//@T Matrix.get_matr_raw
//@U const std::vector&lt;TB&gt;& get_matr_raw()
//@X
//@D Returns the matrix as a 1D stl vector const reference.
//@A X : NO ARGS
//@X
//@E std::vector&lt;int&gt; matr1 = {};
//@E int ncol = 0;
//@E int nrow = 0;
//@E
//@E Matrix&lt;int&gt; matr(matr1, nrow, ncol);
//@E
//@E std::vector&lt;int&gt; col1 = {1, 2, 1, 2, 2, 1, 42};
//@E std::vector&lt;int&gt; col2 = {55, 2, 11, 2, 1, 1, 22};
//@E std::vector&lt;int&gt; col3 = {1, 12, 1, 2, 55, 55, 21};
//@E std::vector&lt;int&gt; col4 = {1, 2, 1, 22, 6, 1, 77};
//@E std::vector&lt;int&gt; col5 = {1, 2, 16, 22, 33, 1, 7};
//@E std::vector&lt;int&gt; col6 = {45, 2, 11, 2, 71, 1, 8};
//@E std::vector&lt;int&gt; col7 = {45, 2, 11, 42, 71, 1, 8};
//@E matr.create_matr(col1, col2, col3, col4, col5, col6, col7);
//@E matr1 = matr.get_matr_raw();
//@E print_nvec(matr1);
//@E  :0: 1  2  1  2  2  1  42 55 2  11
//@E :10: 2  1  1  22 1  12 1  2  55 55
//@E :20: 21 1  2  1  22 6  1  77 1  2
//@E :30: 16 22 33 1  7  45 2  11 2  71
//@E :40: 1  8  45 2  11 42 71 1  8
//@X

//@T Matrix.get_matr_raw2
//@U std::vector&lt;TB&gt; get_matr_raw2()
//@X
//@D Returns the matrix as a 1D stl vector.
//@A X : NO ARGS
//@X
//@E std::vector&lt;int&gt; matr1 = {};
//@E int ncol = 0;
//@E int nrow = 0;
//@E
//@E Matrix&lt;int&gt; matr(matr1, nrow, ncol);
//@E
//@E std::vector&lt;int&gt; col1 = {1, 2, 1, 2, 2, 1, 42};
//@E std::vector&lt;int&gt; col2 = {55, 2, 11, 2, 1, 1, 22};
//@E std::vector&lt;int&gt; col3 = {1, 12, 1, 2, 55, 55, 21};
//@E std::vector&lt;int&gt; col4 = {1, 2, 1, 22, 6, 1, 77};
//@E std::vector&lt;int&gt; col5 = {1, 2, 16, 22, 33, 1, 7};
//@E std::vector&lt;int&gt; col6 = {45, 2, 11, 2, 71, 1, 8};
//@E std::vector&lt;int&gt; col7 = {45, 2, 11, 42, 71, 1, 8};
//@E matr.create_matr(col1, col2, col3, col4, col5, col6, col7);
//@E matr1 = matr.get_matr_raw2();
//@E print_nvec(matr1);
//@E  :0: 1  2  1  2  2  1  42 55 2  11
//@E :10: 2  1  1  22 1  12 1  2  55 55
//@E :20: 21 1  2  1  22 6  1  77 1  2
//@E :30: 16 22 33 1  7  45 2  11 2  71
//@E :40: 1  8  45 2  11 42 71 1  8
//@X

//@T Matrix.get_matr
//@U Matrix&lt;TB&gt; get_matr()
//@X
//@D Returns the Matrix of the Matrix objects.
//@A X : NO ARGS
//@X
//@E std::vector&lt;int&gt; matr1 = {};
//@E int ncol = 0;
//@E int nrow = 0;
//@E
//@E Matrix&lt;int&gt; matr(matr1, nrow, ncol);
//@E
//@E std::vector&lt;int&gt; col1 = {1, 2, 1, 2, 2, 1, 42};
//@E std::vector&lt;int&gt; col2 = {55, 2, 11, 2, 1, 1, 22};
//@E std::vector&lt;int&gt; col3 = {1, 12, 1, 2, 55, 55, 21};
//@E std::vector&lt;int&gt; col4 = {1, 2, 1, 22, 6, 1, 77};
//@E std::vector&lt;int&gt; col5 = {1, 2, 16, 22, 33, 1, 7};
//@E std::vector&lt;int&gt; col6 = {45, 2, 11, 2, 71, 1, 8};
//@E std::vector&lt;int&gt; col7 = {45, 2, 11, 42, 71, 1, 8};
//@E
//@E matr.create_matr(col1, col2, col3, col4, col5);
//@E matr.show();
//@E            1           55            1            1            1
//@E            2            2           12            2            2
//@E            1           11            1            1           16
//@E            2            2            2           22           22
//@E            2            1           55            6           33
//@E            1            1           55            1            1
//@E           42           22           21           77            7
//@X

//@T Matrix.show
//@U void show()
//@X
//@D Display your matrix.
//@A X : NO ARGS
//@X
//@E matr.show();
//@E            1           55            1            1            1
//@E            2            2           12            2            2
//@E            1           11            1            1           16
//@E            2            2            2           22           22
//@E            2            1           55            6           33
//@E            1            1           55            1            1
//@X

//@T Matrix.transpose
//@U Matrix&lt;T&gt; transpose
//@X
//@D Returns the transpose of the matrix
//@A X : NO ARGS
//@X
//@E  std::vector&lt;std::vector&lt;int&gt;&gt; matr1 = {};
//@E  Matrix&lt;int&gt; matr(matr1);
//@E
//@E  std::vector&lt;int&gt; col1 = {1, 2, 1, 2, 2, 1};
//@E  std::vector&lt;int&gt; col2 = {55, 2, 11, 2, 1, 1};
//@E  std::vector&lt;int&gt; col3 = {1, 12, 1, 2, 55, 55};
//@E  std::vector&lt;int&gt; col4 = {1, 2, 1, 22, 6, 1};
//@E  std::vector&lt;int&gt; col5 = {1, 2, 16, 22, 33, 1};
//@E  std::vector&lt;int&gt; col6 = {45, 2, 11, 2, 71, 1};
//@E
//@E  matr.create_matr(col1, col2, col3, col4, col5);
//@E  Matrix&lt;int&gt; matr2 = matr.transpose();
//@E
//@E  matr.show();
//@E  std::cout &lt;&lt; "\n";
//@E  matr2.show();
//@E            1           55            1            1            1
//@E            2            2           12            2            2
//@E            1           11            1            1           16
//@E            2            2            2           22           22
//@E            2            1           55            6           33
//@E            1            1           55            1            1
//@E
//@E            1            2            1            2            2            1
//@E           55            2           11            2            1            1
//@E            1           12            1            2           55           55
//@E            1            2            1           22            6            1
//@E            1            2           16           22           33            1
//@X

//@T Matrix.det1
//@U double det1()
//@X
//@D Returns the determinant of the matrix. Important, it uses a custom algorithm for finding the determinant, a Laplace extension without recursivity. See det2 and det3 for standard Laplace expansion and det3 for the other method.
//@A X : NO ARGS
//@X
//@E  std::vector&lt;std::vector&lt;int&gt;&gt; matr1 = {};
//@E  std::vector&lt;int&gt; col1 = {1, 2, 1, 2, 2, 1};
//@E  std::vector&lt;int&gt; col2 = {55, 2, 11, 2, 1, 1};
//@E  std::vector&lt;int&gt; col3 = {1, 12, 1, 2, 55, 55};
//@E  std::vector&lt;int&gt; col4 = {1, 2, 1, 22, 6, 1};
//@E  std::vector&lt;int&gt; col5 = {1, 2, 16, 22, 33, 1};
//@E  std::vector&lt;int&gt; col6 = {45, 2, 11, 2, 71, 1};
//@E  Matrix&lt;int&gt; matr3(matr1);
//@E  matr3.create_matr(col1, col2, col3, col4, col5, col6);
//@E  double detval = matr3.det();
//@E  -1.05546e+08
//@X

//@T Matrix.det2
//@U double det2(const std::vector&lt;TB&gt;& M, int n) const
//@X
//@D Returns the determinant of the matrix with standard Laplace expansion method.
//@A M : is the matrix as a 1d stl vector
//@A n : is the number of rows or columns
//@X
//@E  std::vector&lt;std::vector&lt;int&gt;&gt; matr1 = {};
//@E  std::vector&lt;int&gt; col1 = {1, 2, 1, 2, 2, 1};
//@E  std::vector&lt;int&gt; col2 = {55, 2, 11, 2, 1, 1};
//@E  std::vector&lt;int&gt; col3 = {1, 12, 1, 2, 55, 55};
//@E  std::vector&lt;int&gt; col4 = {1, 2, 1, 22, 6, 1};
//@E  std::vector&lt;int&gt; col5 = {1, 2, 16, 22, 33, 1};
//@E  std::vector&lt;int&gt; col6 = {45, 2, 11, 2, 71, 1};
//@E  Matrix&lt;int&gt; matr3(matr1);
//@E  matr3.create_matr(col1, col2, col3, col4, col5, col6);
//@E  int nrow = 6;
//@E  matr1 = matr3.get_matr_raw();
//@E  double detval = matr3.det2(matr1, nrow);
//@E  -1.05546e+08
//@X

//@T Matrix.det3
//@U double det3()
//@X
//@D Returns the determinant of the matrix with EigenLU method. It is the most efficient method.
//@A X : NO ARGS
//@X
//@E  std::vector&lt;std::vector&lt;int&gt;&gt; matr1 = {};
//@E  std::vector&lt;int&gt; col1 = {1, 2, 1, 2, 2, 1};
//@E  std::vector&lt;int&gt; col2 = {55, 2, 11, 2, 1, 1};
//@E  std::vector&lt;int&gt; col3 = {1, 12, 1, 2, 55, 55};
//@E  std::vector&lt;int&gt; col4 = {1, 2, 1, 22, 6, 1};
//@E  std::vector&lt;int&gt; col5 = {1, 2, 16, 22, 33, 1};
//@E  std::vector&lt;int&gt; col6 = {45, 2, 11, 2, 71, 1};
//@E  Matrix&lt;int&gt; matr3(matr1);
//@E  matr3.create_matr(col1, col2, col3, col4, col5, col6);
//@E  double detval = matr3.det3();
//@E  -1.05546e+08
//@X

//@T Matrix.get_dim
//@U std::vector&lt;int&gt; get_dim()
//@X
//@D Returns the dimension of the matrix (nrow, ncol)
//@A X : NO ARGS
//@X
//@E  std::vector&lt;std::vector&lt;int&gt;&gt; matr1 = {};
//@E  std::vector&lt;int&gt; col1 = {1, 2, 1, 2, 2, 1};
//@E  std::vector&lt;int&gt; col2 = {55, 2, 11, 2, 1, 1};
//@E  std::vector&lt;int&gt; col3 = {1, 12, 1, 2, 55, 55};
//@E  std::vector&lt;int&gt; col4 = {1, 2, 1, 22, 6, 1};
//@E  std::vector&lt;int&gt; col5 = {1, 2, 16, 22, 33, 1};
//@E  std::vector&lt;int&gt; col6 = {45, 2, 11, 2, 71, 1};
//@E  Matrix&lt;int&gt; matr3(matr1);
//@E  matr3.create_matr(col1, col2, col3, col4, col5, col6);
//@E  std::vector&lt;int&gt; dim_vec = matr3.get_dim();
//@E  {6, 6}
//@X

//@T Matrix.mult_scalar
//@U template &lt;typename T&gt; void mult_scalar(const T &val)
//@X
//@D Multiplies each elements of the matrix by a given scalar.
//@A val : the scalar
//@X
//@E int vl = 2;
//@E std::vector&lt;int&gt; vec = {1, 2, 3, 4};
//@E Matrix&lt;int&gt; matr(vec, 2, 2);
//@E matr.mult_scalar(vl);
//@E matr.show();
//@E 2  4
//@E 6  8
//@X

//@T Matrix.div_scalar
//@U template &lt;typename T&gt; void div_scalar(const T &val)
//@X
//@D Divides each elements of the matrix by a given scalar.
//@A val : the scalar
//@X
//@E double vl = 2;
//@E std::vector&lt;double&gt; vec = {1, 2, 3, 4};
//@E Matrix&lt;int&gt; matr(vec, 2, 2);
//@E matr.div_scalar(vl);
//@E matr.show();
//@E 0.5  1
//@E 1.5  2
//@X

//@T Matrix.add_scalar
//@U template &lt;typename T&gt; void add_scalar(const T &val)
//@X
//@D Adds each elements of the matrix by a given scalar. Note, this operation is mathematically incorrect, but it is a substitution to adding the matrix to another matrix where all elements is equal to the scalar to add. (less memory usage)
//@A val : the scalar
//@X
//@E int vl = 2;
//@E std::vector&lt;int&gt; vec = {1, 2, 3, 4};
//@E Matrix&lt;int&gt; matr(vec, 2, 2);
//@E matr.add_scalar(vl);
//@E matr.show();
//@E 3  4
//@E 5  6
//@X

//@T Matrix.subs_scalar
//@U template &lt;typename T&gt; void subs_scalar(const T &val)
//@X
//@D Substract each elements of the matrix by a given scalar. Note, this operation is mathematically incorrect, but it is a substitution to substracting the matrix to another matrix where all elements is equal to the scalar to substract. (less memory usage)
//@A val : the scalar
//@X
//@E int vl = 2;
//@E std::vector&lt;int&gt; vec = {1, 2, 3, 4};
//@E Matrix&lt;int&gt; matr(vec, 2, 2);
//@E matr.subs_scalar(vl);
//@E matr.show();
//@E -1  0
//@E  1  2
//@X

//@T Matrix.lambda_scalar
//@U template &lt;typename Func&gt; void lambda_scalar(Func f)
//@X
//@D Apply a function to each elements of the matrix.
//@A f : the function, takes 1 arg, the i-jnth element of the matrix
//@X
//@E int myfunc (int &x) {
//@E   return x * 3 + 5;
//@E };
//@E std::vector&lt;int&gt; vec = {1, 2, 3, 4};
//@E Matrix&lt;int&gt; matr(vec, 2, 2);
//@E matr.lambda_scalar(myfunc);
//@E matr.show();
//@E  8  11
//@E 14  17
//@X

//@T Matrix.add_matr
//@U template &lt;typename TB2&gt; void add_matr(const Matrix&lt;TB2&gt; &matr)
//@X
//@D Performs a Matrix addition.
//@A matr : is the B matrix of A + B
//@X
//@E std::vector&lt;int&gt; vec = {1, 2, 3, 4};
//@E Matrix&lt;int&gt; matr(vec, 2, 2);
//@E Matrix&lt;int&gt; matr2(vec, 2, 2);
//@E matr.add_matr(matr2);
//@E matr.show();
//@E  2  4
//@E  6  8
//@X

//@T Matrix.subs_matr
//@U template &lt;typename TB2&gt; void subs_matr(const Matrix&lt;TB2&gt; &matr)
//@X
//@D Performs a Matrix substraction.
//@A matr : is the B matrix of A - B
//@X
//@E std::vector&lt;int&gt; vec = {1, 2, 3, 4};
//@E Matrix&lt;int&gt; matr(vec, 2, 2);
//@E Matrix&lt;int&gt; matr2(vec, 2, 2);
//@E matr.subs_matr(matr2);
//@E matr.show();
//@E  0  0
//@E  0  0
//@X

//@T Matrix.mult_matr
//@U template &lt;typename TB2&gt; void mult_matr(const Matrix&lt;TB2&gt; &matr)
//@X
//@D Performs a Matrix multiplication (i-jnth element to i-jnth element).
//@A matr : is the B matrix of A * B (as i-jnth element to i-jnth element)
//@X
//@E std::vector&lt;int&gt; vec = {1, 2, 3, 4};
//@E Matrix&lt;int&gt; matr(vec, 2, 2);
//@E Matrix&lt;int&gt; matr2(vec, 2, 2);
//@E matr.mult_matr(matr2);
//@E matr.show();
//@E  1   4
//@E  9  16
//@X

//@T Matrix.div_matr
//@U template &lt;typename TB2&gt; void div_matr(const Matrix&lt;TB2&gt; &matr)
//@X
//@D Performs a Matrix division (i-jnth element to i-jnth element).
//@A matr : is the B matrix of A / B (as i-jnth element to i-jnth element)
//@X
//@E std::vector&lt;int&gt; vec = {1, 2, 3, 4};
//@E Matrix&lt;int&gt; matr(vec, 2, 2);
//@E Matrix&lt;int&gt; matr2(vec, 2, 2);
//@E matr.div_matr(matr2);
//@E matr.show();
//@E  1   1
//@E  1   1
//@X

//@T Matrix.lambda_matr
//@U template &lt;typename TB2, typename Func&gt; void lambda_matr(const Matrix&lt;TB2&gt; &matr, Func f)
//@X
//@D a generalized elementwise operator.
//@D It allows you to define arbitrary mathematical operations between two matrices, not just addition or multiplication.
//@A matr : is the B matrix of A / B (as i-jnth element to i-jnth element)
//@A f : is the function, takes 2 args, the first one is the i-jnth element from the Matrix object from which the function is applied, the second is the i-jnth element from the input Matrix
//@X
//@E int myfunc (int &vl1, int &vl2) {
//@E   return vl1 / vl2 + 1;
//@E }
//@E std::vector&lt;int&gt; vec = {1, 2, 3, 4};
//@E Matrix&lt;int&gt; matr(vec, 2, 2);
//@E Matrix&lt;int&gt; matr2(vec, 2, 2);
//@E matr.lambda_matr(matr2, myfunc);
//@E matr.show();
//@E  2   2
//@E  2   2
//@X

//@T Matrix.mult_scalar_out
//@U template &lt;typename T&gt; Matrix&lt;std::common_type_t&lt;TB, T&gt;&gt; mult_scalar_out(const T &val)
//@X
//@D This function performs an element-wise multiplication between a matrix and a
//@D   scalar. Unlike `mult_scalar()`, which modifies the current
//@D   matrix in-place and preserves its data type, `mult_scalar_out()` creates a
//@D   new matrix whose element type is automatically promoted to the most
//@D   expressive type of the operands (using `std::common_type_t`).
//@D  
//@D   This allows safe arithmetic between matrices of different numeric types
//@D   without precision loss.
//@A val : the scalar
//@X
//@E int vl = 2.5;
//@E std::vector&lt;int&gt; vec = {1, 2, 3, 4};
//@E Matrix&lt;int&gt; matr(vec, 2, 2);
//@E auto matr2 = matr.mult_scalar_out(vl);
//@E matr2.show();
//@E 2.5  5.0
//@E 7.5  10.0
//@X

//@T Matrix.div_scalar_out
//@U template &lt;typename T&gt; Matrix&lt;std::common_type_t&lt;TB, T&gt;&gt; div_scalar_out(const T &val)
//@X
//@D This function performs an element-wise division between a matrix and a
//@D   scalar. Unlike `div_scalar()`, which modifies the current
//@D   matrix in-place and preserves its data type, `div_scalar_out()` creates a
//@D   new matrix whose element type is automatically promoted to the most
//@D   expressive type of the operands (using `std::common_type_t`).
//@D  
//@D   This allows safe arithmetic between matrices of different numeric types
//@D   without precision loss.
//@A val : the scalar
//@X
//@E double vl = 2;
//@E std::vector&lt;double&gt; vec = {1, 2, 3, 4};
//@E Matrix&lt;int&gt; matr(vec, 2, 2);
//@E auto matr2 = matr.div_scalar_out(vl);
//@E matr2.show();
//@E 0.5  1
//@E 1.5  2
//@X

//@T Matrix.add_scalar_out
//@U template &lt;typename T&gt; Matrix&lt;std::common_type_t&lt;TB, T&gt;&gt; add_scalar_out(const T &val)
//@X
//@D This function performs an element-wise addition between a matrix and
//@D   a scalar. Unlike `add_scalar()`, which modifies the current
//@D   matrix in-place and preserves its data type, `add_scalar_out()` creates a
//@D   new matrix whose element type is automatically promoted to the most
//@D   expressive type of the operands (using `std::common_type_t`).
//@D  
//@D   This allows safe arithmetic between matrices of different numeric types
//@D   without precision loss. 
//@D   Strictly mathematically speaking, wa can not add a scalar and a matrix, but for memory performance, imagine the scalar as a matrix of nm dimensions filled with the scalar value.
//@A val : the scalar
//@X
//@E int vl = 2;
//@E std::vector&lt;int&gt; vec = {1, 2, 3, 4};
//@E Matrix&lt;int&gt; matr(vec, 2, 2);
//@E auto matr2 = matr.add_scalar_out(vl);
//@E matr2.show();
//@E 3  4
//@E 5  6
//@X

//@T Matrix.subs_scalar_out
//@U template &lt;typename T&gt; Matrix&lt;std::common_type_t&lt;TB, T&gt;&gt; subs_scalar_out(const T &val)
//@X
//@D This function performs an element-wise substraction between a matrix and
//@D   a scalar. Unlike `subs_scalar()`, which modifies the current
//@D   matrix in-place and preserves its data type, `subs_scalar_out()` creates a
//@D   new matrix whose element type is automatically promoted to the most
//@D   expressive type of the operands (using `std::common_type_t`).
//@D  
//@D   This allows safe arithmetic between matrices of different numeric types
//@D   without precision loss. 
//@D   Strictly mathematically speaking, wa can not substract a scalar and a matrix, but for memory performance, imagine the scalar as a matrix of nm dimensions filled with the scalar value.
//@A val : the scalar
//@X
//@E int vl = 2;
//@E std::vector&lt;int&gt; vec = {1, 2, 3, 4};
//@E Matrix&lt;int&gt; matr(vec, 2, 2);
//@E auto matr2 = matr.subs_scalar_out(vl);
//@E matr2.show();
//@E -1  0
//@E  1  2
//@X

//@T Matrix.lambda_scalar_out
//@U template &lt;typename Func&gt; auto lambda_scalar_out(Func f)
//@X
//@D Apply a function to each elements of the matrix. Returns a new matrix to keep precision of the most expressive type used.
//@A f : the function, takes 1 arg, the i-jnth element of the matrix
//@X
//@E int myfunc (int &x) {
//@E   return x * 3 + 5;
//@E };
//@E std::vector&lt;int&gt; vec = {1, 2, 3, 4};
//@E Matrix&lt;int&gt; matr(vec, 2, 2);
//@E auto matr2 = matr.lambda_scalar_out(myfunc);
//@E matr2.show();
//@E  8  11
//@E 14  17
//@X

//@T Matrix.add_matr_out
//@U template &lt;typename TB2&gt; Matrix&lt;std::common_type_t&lt;TB, TB2&gt;&gt; add_matr_out(const Matrix&lt;TB2&gt; &matr)
//@X
//@D Performs a Matrix addition. Returns a new matrix to keep precision of the most expressive type used.
//@A matr : is the B matrix of A + B
//@X
//@E std::vector&lt;int&gt; vec = {1, 2, 3, 4};
//@E Matrix&lt;int&gt; matr(vec, 2, 2);
//@E Matrix&lt;int&gt; matr2(vec, 2, 2);
//@E auto matr3 = matr.add_matr_out(matr2);
//@E matr3.show();
//@E  2  4
//@E  6  8
//@X

//@T Matrix.subs_matr_out
//@U template &lt;typename TB2&gt; Matrix&lt;std::common_type_t&lt;TB, TB2&gt;&gt; subs_matr_out(const Matrix&lt;TB2&gt; &matr)
//@X
//@D Performs a Matrix substraction. Returns a matrix to keep the precision of the most expressive type used.
//@A matr : is the B matrix of A - B
//@X
//@E std::vector&lt;int&gt; vec = {1, 2, 3, 4};
//@E Matrix&lt;int&gt; matr(vec, 2, 2);
//@E Matrix&lt;int&gt; matr2(vec, 2, 2);
//@E auto matr3 = matr.subs_matr_out(matr2);
//@E matr3.show();
//@E  0  0
//@E  0  0
//@X

//@T Matrix.mult_matr_out
//@U template &lt;typename TB2&gt; Matrix&lt;std::common_type_t&lt;TB, TB2&gt;&gt; mult_matr_out(const Matrix&lt;TB2&gt; &matr)
//@X
//@D Performs a Matrix multiplication (i-jnth element to i-jnth element). Returns a matrix to keep precision of the most expressive type used.
//@A matr : is the B matrix of A * B (as i-jnth element to i-jnth element)
//@X
//@E std::vector&lt;int&gt; vec = {1, 2, 3, 4};
//@E Matrix&lt;int&gt; matr(vec, 2, 2);
//@E Matrix&lt;int&gt; matr2(vec, 2, 2);
//@E auto matr3 = matr.mult_matr_out(matr2);
//@E matr3.show();
//@E  1   4
//@E  9  16
//@X

//@T Matrix.div_matr_out
//@U template &lt;typename TB2&gt; Matrix&lt;std::common_type_t&lt;TB, TB2&gt;&gt; div_matr_out(const Matrix&lt;TB2&gt; &matr)
//@X
//@D Performs a Matrix division (i-jnth element to i-jnth element). Returns a new matrix to keep precision of the most expressive type used.
//@A matr : is the B matrix of A / B (as i-jnth element to i-jnth element)
//@X
//@E std::vector&lt;int&gt; vec = {1, 2, 3, 4};
//@E Matrix&lt;int&gt; matr(vec, 2, 2);
//@E Matrix&lt;int&gt; matr2(vec, 2, 2);
//@E auto matr3 = matr.div_matr_out(matr2);
//@E matr3.show();
//@E  1   1
//@E  1   1
//@X

//@T Matrix.lambda_matr_out
//@U template &lt;typename TB2, typename Func&gt; auto lambda_matr_out(const Matrix&lt;TB2&gt; &matr, Func f)
//@X
//@D A generalized elementwise operator.
//@D It allows you to define arbitrary mathematical operations between two matrices, not just addition or multiplication. Returns a new matrix to keep precision of the most expressive type used.
//@A matr : is the B matrix of A / B (as i-jnth element to i-jnth element)
//@A f : is the function, takes 2 args, the first one is the i-jnth element from the Matrix object from which the function is applied, the second is the i-jnth element from the input Matrix
//@X
//@E int myfunc (int &vl1, int &vl2) {
//@E   return vl1 / vl2 + 1;
//@E }
//@E std::vector&lt;int&gt; vec = {1, 2, 3, 4};
//@E Matrix&lt;int&gt; matr(vec, 2, 2);
//@E Matrix&lt;int&gt; matr2(vec, 2, 2);
//@E auto matr3 = matr.lambda_matr_out(matr2, myfunc);
//@E matr3.show();
//@E  2   2
//@E  2   2
//@X

//@T Matrix.mult1
//@U template &lt;typename TB2&gt; Matrix&lt;std::common_type_t&lt;TB, TB2&gt;&gt; mult1(const Matrix&lt;TB2&gt; &matr)
//@X
//@D Performs a matrix multiplication as A * B, with A as the Matrix from which the function is called, see example.
//@A matr : is the B matrix
//@X
//@E std::vector&lt;int&gt; vec = {1, 2, 3, 4, 5, 6};
//@E Matrix&lt;int&gt; matr(vec, 3, 2);
//@E //@E std::vector&lt;int&gt; vec = {5, 6, 7, 8};
//@E Matrix&lt;int&gt; matr2(vec, 2, 2);
//@E Matrix&lt;int&gt; matr3 = matr.mult1(matr2);
//@E matr3.show();
//@E 29 39
//@E 40 54
//@E 51 69
//@X

//@T Matrix.mult2
//@U template &lt;typename TB2&gt; Matrix&lt;std::common_type_t&lt;TB, TB2&gt;&gt; mult2(const Matrix&lt;TB2&gt; &matr)
//@X
//@D Performs a matrix multiplication as A * B, with B as the Matrix from which the function is called, see example.
//@A matr : is the A matrix
//@X
//@E std::vector&lt;int&gt; vec = {1, 2, 3, 4, 5, 6};
//@E Matrix&lt;int&gt; matr(vec, 2, 2);
//@E //@E std::vector&lt;int&gt; vec = {5, 6, 7, 8};
//@E Matrix&lt;int&gt; matr2(vec, 2, 2);
//@E Matrix&lt;int&gt; matr3 = matr2.mult2(matr);
//@E matr3.show();
//@E 29 39
//@E 40 54
//@E 51 69
//@X

//@T Matrix.mult1_opt_raw
//@U template &lt;typename TB2&gt; Matrix&lt;std::common_type_t&lt;TB, TB2&gt;&gt; mult1_opt_raw(const Matrix&lt;TB2&gt; &matr)
//@X
//@D Performs an optimized matrix multiplication as A * B, with A as the Matrix from which the function is called, see example. The result is the transpose of the actual result, it is usefull if you want to chain matrix multiplications in an optimized way. So for the end result, don't forget to transpose the output.
//@A matr : is the B matrix
//@X
//@E std::vector&lt;int&gt; vec = {1, 2, 3, 4, 5, 6};
//@E Matrix&lt;int&gt; matr(vec, 3, 2);
//@E //@E std::vector&lt;int&gt; vec = {5, 6, 7, 8};
//@E Matrix&lt;int&gt; matr2(vec, 2, 2);
//@E Matrix&lt;int&gt; matr3 = matr.mult1_opt_raw(matr2);
//@E matr3.show();
//@E           29           40           51
//@E           39           54           69
//@X

//@T Matrix.mult2_opt_raw
//@U template &lt;typename TB2&gt; Matrix&lt;std::common_type_t&lt;TB, TB2&gt;&gt; mult2_opt_raw(const Matrix&lt;TB2&gt; &matr)
//@X
//@D Performs a matrix multiplication as A * B, with B as the Matrix from which the function is called, see example.
//@A matr : is the A matrix
//@X
//@E std::vector&lt;int&gt; vec = {1, 2, 3, 4, 5, 6};
//@E Matrix&lt;int&gt; matr(vec, 2, 2);
//@E //@E std::vector&lt;int&gt; vec = {5, 6, 7, 8};
//@E Matrix&lt;int&gt; matr2(vec, 2, 2);
//@E Matrix&lt;int&gt; matr3 = matr2.mult2_opt_raw(matr);
//@E matr3.show();
//@E           29           40           51
//@E           39           54           69
//@X

//@T Matrix.mult1_opt
//@U template &lt;typename TB2&gt; Matrix&lt;std::common_type_t&lt;TB, TB2&gt;&gt; mult1_opt(const Matrix&lt;TB2&gt; &matr)
//@X
//@D Performs a matrix multiplication as A * B, with A as the Matrix from which the function is called, see example.
//@A matr : is the B matrix
//@X
//@E std::vector&lt;int&gt; vec = {1, 2, 3, 4, 5, 6};
//@E Matrix&lt;int&gt; matr(vec, 3, 2);
//@E //@E std::vector&lt;int&gt; vec = {5, 6, 7, 8};
//@E Matrix&lt;int&gt; matr2(vec, 2, 2);
//@E Matrix&lt;int&gt; matr3 = matr.mult1_opt(matr2);
//@E matr3.show();
//@E 29 39
//@E 40 54
//@E 51 69
//@X

//@T Matrix.mult2_opt
//@U template &lt;typename TB2&gt; Matrix&lt;std::common_type_t&lt;TB, TB2&gt;&gt; mult2_opt(const Matrix&lt;TB2&gt; &matr)
//@X
//@D Performs a matrix multiplication as A * B, with B as the Matrix from which the function is called, see example.
//@A matr : is the A matrix
//@X
//@E std::vector&lt;int&gt; vec = {1, 2, 3, 4};
//@E Matrix&lt;int&gt; matr(vec, 2, 2);
//@E //@E std::vector&lt;int&gt; vec = {5, 6, 7, 8};
//@E Matrix&lt;int&gt; matr2(vec, 2, 2);
//@E Matrix&lt;int&gt; matr3 = matr2.mult2_opt(matr);
//@E matr3.show();
//@E           29           39
//@E           40           54
//@E           51           69
//@X

//@T Matrix.mult1_GPU
//@U template &lt;typename TB2&gt; Matrix&lt;std::common_type_t&lt;TB, TB2&gt;&gt; mult1(const Matrix&lt;TB2&gt; &matr)
//@X
//@D Performs a matrix multiplication as A * B, with A as the Matrix from which the function is called, see example. This functions uses cuBLAS (nvidia graphics card), see how to set the GPU context for accelerated computing.
//@A matr : is the B matrix
//@X
//@E CUBLASContext::init();
//@E std::vector&lt;float&gt; a = {1,2,3,4, 5, 6};
//@E std::vector&lt;float&gt; b = {5,6,7,8,9,10};
//@E Matrix&lt;float&gt; A(a, 3, 2), B(b, 2, 3);
//@E auto C = A.mult1_GPU(B);
//@E C.show();
//@E CUBLASContext::destroy();
//@E Initialized GPU context
//@E            29           39           49
//@E            40           54           68
//@E            51           69           87
//@E Destroyed GPU context
//@X

//@T Matrix.mult2_GPU
//@U template &lt;typename TB2&gt; Matrix&lt;std::common_type_t&lt;TB, TB2&gt;&gt; mult2(const Matrix&lt;TB2&gt; &matr)
//@X
//@D Performs a matrix multiplication as A * B, with B as the Matrix from which the function is called, see example. This functions uses cuBLAS (nvidia graphics card), see how to set the GPU context for accelerated computing.
//@A matr : is the A matrix
//@X
//@E CUBLASContext::init();
//@E std::vector&lt;float&gt; a = {1,2,3,4, 5, 6};
//@E std::vector&lt;float&gt; b = {5,6,7,8,9,10};
//@E Matrix&lt;float&gt; A(a, 3, 2), B(b, 2, 3);
//@E auto C = B.mult2_GPU(A);
//@E C.show();
//@E CUBLASContext::destroy();
//@E Initialized GPU context
//@E            29           39           49
//@E            40           54           68
//@E            51           69           87
//@E Destroyed GPU context
//@X

#endif

#ifdef __CUDACC__

#define CUDA_CHECK(x) do { \
    cudaError_t err = (x); \
    if (err != cudaSuccess) \
        throw std::runtime_error(cudaGetErrorString(err)); \
} while(0)

#define CUBLAS_CHECK(x) do { \
    cublasStatus_t stat = (x); \
    if (stat != CUBLAS_STATUS_SUCCESS) \
        throw std::runtime_error("cuBLAS error"); \
} while(0)

struct CUBLASContext {
    inline static cublasHandle_t handle = nullptr;

    static void init() {
        if (!handle) {
            CUBLAS_CHECK(cublasCreate(&handle));

            cudaDeviceProp prop{};
            cudaGetDeviceProperties(&prop, 0);

            if (prop.major >= 8) {
                cublasSetMathMode(handle, CUBLAS_TF32_TENSOR_OP_MATH);
            } else if (prop.major >= 7) {
                cublasSetMathMode(handle, CUBLAS_TENSOR_OP_MATH);
            } else {
                cublasSetMathMode(handle, CUBLAS_DEFAULT_MATH);
            };

            std::cout << "Initialized GPU context\n";
        }
    }

    static void destroy() {
        if (handle) {
            cublasDestroy(handle);
            handle = nullptr;
            std::cout << "Destroyed GPU context\n";
        }
    }

    static cublasHandle_t get() {
        return handle;
    }
};
#endif

template <typename TB> class Matrix{
  private:
    std::vector<TB> rtn_matr;
    int nrow = 0;
    int ncol = 0;
    bool alrd = 0;

    #ifdef __CUDACC__
    static inline cublasHandle_t cublas_handle = nullptr;
    static inline bool is_initiated = 0;
    #endif

    int permutation_parity(const std::vector<int>& vec, const std::vector<int>& pos_vec) {
        std::vector<int> perm = vec;
        perm.insert(perm.end(), pos_vec.begin(), pos_vec.end());
        int inversions = 0;
        for (size_t i = 0; i < perm.size(); ++i) {
            for (size_t j = i + 1; j < perm.size(); ++j) {
                if (perm[i] > perm[j]) inversions++;
            }
        }
        return inversions % 2; 
    }

  public:
  
    Matrix(std::vector<TB> &x, int nrowv, int ncolv)
        : rtn_matr(x), nrow(nrowv), ncol(ncolv) {}
    
    void create_matr() {};

    template <typename T, typename... T2> void create_matr(std::vector<T> &var1, std::vector<T2>&... var2) {
      if (!alrd) {
        nrow = var1.size();
        ncol = 0;
        alrd = 1;
      } else if (nrow < var1.size()) {
        var1.erase(var1.end() - (var1.size() - nrow), var1.end());
      } else if (nrow > var1.size()) {
        repeat_untl(var1, nrow);
      };
      ncol += 1;
      rtn_matr.insert(rtn_matr.end(), var1.begin(), var1.end());
      create_matr(var2...);
    };

    Matrix<TB> get_matr() {
      return Matrix<TB>(rtn_matr, nrow, ncol);
    };

    const std::vector<TB>& get_matr_raw() const {
      return rtn_matr;
    };

    std::vector<TB> get_matr_raw2() {
      return rtn_matr;
    };

    template <typename T> void reinitiate() {
      alrd = 0;
      ncol = 0;
      nrow = 0;
      rtn_matr = {};  
    };

    void show() {

      std::ios old_state(nullptr);
      old_state.copyfmt(std::cout);

      std::setprecision(6);

      int j;
      for (int i = 0; i < nrow; i +=1) {
        for (j = 0; j < ncol; j += 1) {
          std::cout << std::setw(13) << rtn_matr[i + nrow * j];
        };
        std::cout << "\n";
      }
      std::cout.copyfmt(old_state);
    };

    void transpose() {
      int i;
      std::vector<TB> pre_matr = {};
      for (int j = 0; j < nrow; j += 1) {
        for (i = 0; i < ncol; i += 1) {
          pre_matr.push_back(rtn_matr[j + i * nrow]);
        };
      };
      rtn_matr = pre_matr;
      i = nrow;
      nrow = ncol;
      ncol = i;
    };

    const std::vector<int> get_dim() const {
      return {nrow, ncol};
    };

    double det1() {
      if (nrow != ncol) {
        std::cout << "No det can be calculated for a non square Matrix\n";
      } else if (nrow == 2) {
        return rtn_matr[0] * rtn_matr[3] - rtn_matr[2] * rtn_matr[1];
      };
      const int N = nrow;
      std::vector<int> vec = {};
      std::vector<int> mooves_vec = {};
      mooves_vec.resize(N - 2, 0);
      std::vector<int> pos_vec = {};
      vec.resize(N - 2, 0);
      int i;
      int cur_pos;
      std::vector<int> sub_pos = {};
      double detval = 0;
      double detval2;
      int parity;
      double sign;
      std::vector<int> set_pos = {};
      for (i = 0; i < N; i += 1) {
        set_pos.push_back(i);
      };
      for (i = 0; i < vec.size(); i += 1) {
        vec[i] = i;
      };
      while (mooves_vec[0] < N) {
        
        detval2 = 1.0;
        for (i = 0; i < (int)vec.size(); ++i) {
          detval2 *= rtn_matr[vec[i] * N + i];
        }

        pos_vec = diff2(set_pos, vec);
        sort_asc(pos_vec);
        
       detval2 *= ((rtn_matr[pos_vec[1] * N + N - 1] * rtn_matr[pos_vec[0] * N + N - 2] - rtn_matr[pos_vec[0] * N + N - 1] * rtn_matr[pos_vec[1] * N + N - 2])); 


        int sign_parity = permutation_parity(vec, pos_vec);
        sign = (sign_parity ? -1.0 : 1.0);
        detval2 *= sign;
        detval += detval2;
        i = vec.size() - 1;
        if (i > 0) {
          while (mooves_vec[i] == N - i - 1) {
            i -= 1;
            if (i == 0) {
              if (mooves_vec[0] == N - i - 1) {
                return detval;
              } else {
                break;
              };
            };
          };
        };
        sub_pos = sub(vec.begin(), vec.begin() + i + 1);
        pos_vec = diff2(set_pos, sub_pos);
        sort_desc(pos_vec);
        cur_pos = pos_vec[pos_vec.size() - 1];

        int min_pos = cur_pos;

        while (cur_pos < vec[i]) {
          pos_vec.pop_back();
          if (pos_vec.size() == 0) { break; };
          cur_pos = pos_vec[pos_vec.size() - 1];
        };
        if (pos_vec.size() > 0) {
          vec[i] = cur_pos;
        } else {
          vec[i] = min_pos;
        };
        mooves_vec[i] += 1;
        i += 1;
        while (i < vec.size()) {
          sub_pos = sub(vec.begin(), vec.begin() + i + 1);
          pos_vec = diff2(set_pos, sub_pos);
          cur_pos = min(pos_vec);
          vec[i] = cur_pos;
          mooves_vec[i] = 0;
          i += 1;
        };
      };
      return detval;
    };


    double det2(const std::vector<TB>& M, int n) const {
      if (n == 1) return M[0];
      if (n == 2) return M[0] * M[3] - M[1] * M[2]; 

      double det = 0.0;
      int j;
      int i;

      for (int col = 0; col < n; ++col) {
          std::vector<TB> subM;
          subM.reserve((n - 1) * (n - 1));

          for (j = 0; j < n; ++j) {
              if (j == col) continue;
              for (i = 1; i < n; ++i) {
                  subM.push_back(M[i + j * n]);
              };
          };

          double sign = ((col % 2) ? -1.0 : 1.0);
          det += sign * M[0 + col * n] * det2(subM, n - 1);
      };

      return det;
    }

    double det3() {
      double det_sign = 1.0;

      std::vector<TB> tmp_matr = rtn_matr;

      for (int k = 0; k < nrow; ++k) {
          // Pivot selection
          int pivot = k;
          double max_val = std::abs(tmp_matr[k * nrow + k]);
          for (int i = k + 1; i < nrow; ++i) {
              double val = std::abs(tmp_matr[i * nrow + k]);
              if (val > max_val) {
                  max_val = val;
                  pivot = i;
              };
          };

          // Singular matrix, check to avoid dividing 
          // by zero (at index k * n + k)
          if (max_val < 1e-15)
              return 0.0;

          // Row swap if needed (if the current 
          // row max at k nth col not the max of the entire k nth column)
          if (pivot != k) {
              for (int j = 0; j < nrow; ++j)
                  std::swap(tmp_matr[pivot * nrow + j], tmp_matr[k * nrow + j]);
              det_sign *= -1.0;
          };

          // Eliminate below pivot, to fast forward 
          // create a upper triangular matrix
          for (int i = k + 1; i < nrow; ++i) {
              double factor = tmp_matr[i * nrow + k] / tmp_matr[k * nrow + k];
              for (int j = k; j < nrow; ++j)
                  tmp_matr[i * nrow + j] -= factor * tmp_matr[k * nrow + j];
          };
      }

      // Product of diagonal entries
      double det = det_sign;
      for (int i = 0; i < nrow; ++i)
          det *= tmp_matr[i * nrow + i];

      return det;
    }

    std::vector<TB> get_col(unsigned int n) {
      if (n > ncol) {
        std::cout << "Exceeds the maximum column number\n";
        return {};
      };
      return sub(rtn_matr.begin() + nrow * (n), 
                      rtn_matr.begin() + nrow * (n + 1));
    };

    std::vector<TB> get_row(unsigned int n) {
      if (n > nrow) {
        std::cout << "Exceeds the maximum row number\n";
        return {};
      };
      std::vector<TB> rtn_vec = {};
      rtn_vec.reserve(ncol);
      for (int i = 0; i < ncol; i++) {
        rtn_vec.push_back(rtn_matr[nrow * i + n]);
      };
      return rtn_vec;
    };

    TB get_cell(int n1, int n2) {
      if (n1 > nrow) {
        std::cout << "Exceeds the maximum row number\n";
        return 0;
      } else if (n2 > ncol) {
        std::cout << "Exceeds the maximum column number\n";
        return 0;
      };
      return rtn_matr[nrow * n2 + n1];
    };

    Matrix<TB> get_sub(int n1, int n1b, int n2, int n2b) {
      std::vector<TB> empty=  {};
      if (n1 > nrow) {
        std::cout << "Exceeds the maximum row number\n";
        return Matrix<TB>(empty, 0, 0);
      } else if (n2 > ncol) {
        std::cout << "Exceeds the maximum column number\n";
        return Matrix<TB>(empty, 0, 0);
      } else if (n1b > nrow) {
        std::cout << "Exceeds the maximum row number\n";
        return Matrix<TB>(empty, 0, 0);
      } else if (n2b > ncol) {
        std::cout << "Exceeds the maximum column number\n";
        return Matrix<TB>(empty, 0, 0);
      };

      if (n2 >= n2b) {
        std::cout << "First column must be lower than second\n";
        return Matrix<TB>(empty, 0, 0);
      } else if (n1 >= n1b) {
        std::cout << "First row must be lower than second\n";
        return Matrix<TB>(empty, 0, 0);
      };

      std::vector<TB> rtn_vec = {};
      rtn_vec.reserve((n2b - n2) * (n1b - n1));
      int i;
      for (int j = n2; j <= n2b; j += 1) {
        for (i = n1; i <= n1b; i += 1) {
          rtn_vec.push_back(rtn_matr[nrow * j + i]);
        };
      };
      return Matrix<TB>(rtn_vec, (n1b - n1 + 1), (n2b - n2 + 1));
    };

    template <typename T> void mult_scalar(const T &val) {
      for (size_t i = 0; i < nrow * ncol; i += 1) {
        rtn_matr[i] *= val;
      };
    };

    template <typename T> void div_scalar(T &val) {
      for (size_t i = 0; i < nrow * ncol; i += 1) {
        rtn_matr[i] /= val;
      };
    };

    template <typename T> void add_scalar(T &val) {
      for (size_t i = 0; i < nrow * ncol; i += 1) {
        rtn_matr[i] += val;
      };
    };

    template <typename T> void subs_scalar(T &val) {
      for (size_t i = 0; i < nrow * ncol; i += 1) {
        rtn_matr[i] -= val;
      };
    };

    template <typename Func> void lambda_scalar(Func f) {
      for (size_t i = 0; i < nrow * ncol; i += 1) {
        rtn_matr[i] = f(rtn_matr[i]);
      };
    };

    template <typename TB2> void add_matr(const Matrix<TB2> &matr) {

      if (matr.get_dim() != std::vector<int>{nrow, ncol}) {
          std::cerr << "❌ Matrix size mismatch in add_matr\n";
          return;
      }

      const std::vector<TB2>& rtn_matr2 = matr.get_matr_raw();
      for (size_t i = 0; i < nrow * ncol; i += 1) {
        rtn_matr[i] += rtn_matr2[i];
      };
    };

    template <typename TB2> void sub_matr(const Matrix<TB2> &matr) {

      if (matr.get_dim() != std::vector<int>{nrow, ncol}) {
          std::cerr << "❌ Matrix size mismatch in sub_matr\n";
          return;
      }

      const std::vector<TB2>& rtn_matr2 = matr.get_matr_raw();
      for (size_t i = 0; i < nrow * ncol; i += 1) {
        rtn_matr[i] -= rtn_matr2[i];
      };
    };

    template <typename TB2> void mult_matr(const Matrix<TB2> &matr) {

      if (matr.get_dim() != std::vector<int>{nrow, ncol}) {
          std::cerr << "❌ Matrix size mismatch in mult_matr\n";
          return;
      }

      const std::vector<TB2>& rtn_matr2 = matr.get_matr_raw();
      for (size_t i = 0; i < nrow * ncol; i += 1) {
        rtn_matr[i] *= rtn_matr2[i];
      };
    };

    template <typename TB2> void div_matr(const Matrix<TB2> &matr) {

      if (matr.get_dim() != std::vector<int>{nrow, ncol}) {
          std::cerr << "❌ Matrix size mismatch in div_matr\n";
          return;
      }

      const std::vector<TB2>& rtn_matr2 = matr.get_matr_raw();
      for (size_t i = 0; i < nrow * ncol; i += 1) {
        rtn_matr[i] /= rtn_matr2[i];
      };
    };

    template <typename TB2, typename Func> 
    void lambda_matr(const Matrix<TB2> &matr, 
                     Func f) {

      if (matr.get_dim() != std::vector<int>{nrow, ncol}) {
          std::cerr << "❌ Matrix size mismatch in lambda_matr\n";
          return;
      }

      const std::vector<TB2>& rtn_matr2 = matr.get_matr_raw();
      for (size_t i = 0; i < nrow * ncol; i += 1) {
        rtn_matr[i] = f(rtn_matr[i], rtn_matr2[i]);
      };
    };

    template <typename T> 
    Matrix<std::common_type_t<TB, T>>
    mult_scalar_out(const T &val) const {
      
      using TC = std::common_type_t<TB, T>;
      std::vector<TC> rtn_matr2(rtn_matr.size());

      for (size_t i = 0; i < rtn_matr.size(); i += 1) {
        rtn_matr2[i] = rtn_matr[i] * val;
      };

      return Matrix<TC>(rtn_matr2, nrow, ncol);

    };

    template <typename T>
    Matrix<std::common_type_t<TB, T>>
    div_scalar_out(T &val) const {

      using TC = std::common_type_t<TB, T>;
      std::vector<TC> rtn_matr2(rtn_matr.size());

      for (size_t i = 0; i < rtn_matr.size(); i += 1) {
        rtn_matr2[i] = rtn_matr[i] / val;
      };

      return Matrix<TC>(rtn_matr2, nrow, ncol);

    };

    template <typename T>
    Matrix<std::common_type_t<TB, T>>
    add_scalar_out(T &val) const {

      using TC = std::common_type_t<TB, T>;
      std::vector<TC> rtn_matr2(rtn_matr.size());

      for (size_t i = 0; i < rtn_matr.size(); i += 1) {
        rtn_matr2[i] = rtn_matr[i] + val;
      };

      return Matrix<TC>(rtn_matr2, nrow, ncol);

    };

    template <typename T> 
    Matrix<std::common_type_t<TB, T>> 
    subs_scalar_out(T &val) const {

      using TC = std::common_type_t<TB, T>;
      std::vector<TC> rtn_matr2(rtn_matr.size());

      for (size_t i = 0; i < rtn_matr.size(); ++i) {
        rtn_matr2[i] = rtn_matr[i] - val;
      };

      return Matrix<TC>(rtn_matr2, nrow, ncol);

    };

    template <typename Func>
    auto lambda_scalar_out(Func f) const {
      using TC = decltype(f(std::declval<TB>()));
    
      std::vector<TC> rtn_matr2(rtn_matr.size());
    
      for (size_t i = 0 ; i < rtn_matr.size(); i += 1) {
          rtn_matr2[i] = f(rtn_matr[i]);
      };
    
      return Matrix<TC>(rtn_matr2, nrow, ncol);
    };

    template <typename TB2> 
    Matrix<std::common_type_t<TB, TB2>>
    add_matr_out(const Matrix<TB2> &matr) const {

      using TC = std::common_type_t<TB, TB2>;
      std::vector<TC> empty = {};

      if (matr.get_dim() != std::vector<int>{nrow, ncol}) {
          std::cerr << "❌ Matrix size mismatch in add_matr_out\n";
          return Matrix<TC>(empty, 0, 0);
      }

      std::vector<TC> rtn_matr3(rtn_matr.size());

      const std::vector<TB2>& rtn_matr2 = matr.get_matr_raw();
      for (size_t i = 0; i < rtn_matr.size(); i += 1) {
        rtn_matr3[i] = rtn_matr[i] + rtn_matr2[i];
      };

      return Matrix<TC>(rtn_matr3, nrow, ncol);
    };

    template <typename TB2> 
    Matrix<std::common_type_t<TB, TB2>>
    sub_matr_out(const Matrix<TB2> &matr) {

      using TC = std::common_type_t<TB, TB2>;
      std::vector<TC> empty = {};

      if (matr.get_dim() != std::vector<int>{nrow, ncol}) {
          std::cerr << "❌ Matrix size mismatch in sub_matr_out\n";
          return Matrix<TC>(empty, 0, 0);
      }

      std::vector<TC> rtn_matr3(rtn_matr.size());
      const std::vector<TB2>& rtn_matr2 = matr.get_matr_raw();
      for (size_t i = 0; i < rtn_matr.size(); i += 1) {
        rtn_matr3[i] = rtn_matr[i] - rtn_matr2[i];
      };

      return Matrix<TC>(rtn_matr3, nrow, ncol);
    };

    template <typename TB2>
    Matrix<std::common_type_t<TB, TB2>>
    mult_matr_out(const Matrix<TB2> &matr) {

      using TC = std::common_type_t<TB, TB2>;
      std::vector<TC> empty = {};

      if (matr.get_dim() != std::vector<int>{nrow, ncol}) {
          std::cerr << "❌ Matrix size mismatch in mult_matr_out\n";
          return Matrix<TC>(empty, 0, 0);
      }

      std::vector<TC> rtn_matr3(rtn_matr.size());
      const std::vector<TB2>& rtn_matr2 = matr.get_matr_raw();
      for (size_t i = 0; i < rtn_matr.size(); i += 1) {
        rtn_matr3[i] = rtn_matr[i] * rtn_matr2[i];
      };

      return Matrix<TC>(rtn_matr3, nrow, ncol);
    };

    template <typename TB2> 
    Matrix<std::common_type_t<TB, TB2>>
    div_matr_out(const Matrix<TB2> &matr) {

      using TC = std::common_type_t<TB, TB2>;
      std::vector<TC> empty = {};

      if (matr.get_dim() != std::vector<int>{nrow, ncol}) {
          std::cerr << "❌ Matrix size mismatch in div_matr_out\n";
          return Matrix<TC>(empty, 0, 0);
      }

      std::vector<TC> rtn_matr3(rtn_matr.size());
      const std::vector<TB2>& rtn_matr2 = matr.get_matr_raw();
      for (size_t i = 0; i < rtn_matr.size(); i += 1) {
        rtn_matr3[i] = rtn_matr[i] / rtn_matr2[i];
      };

      return Matrix<TC>(rtn_matr3, nrow, ncol);
    };

    template <typename TB2, typename Func> 
    auto
    lambda_matr_out(const Matrix<TB2> &matr, 
                     Func f) {

      using TC = decltype(f(std::vector<TB>()));
      std::vector<TC> empty = {};

      if (matr.get_dim() != std::vector<int>{nrow, ncol}) {
          std::cerr << "❌ Matrix size mismatch in lambda_matr_out\n";
          return Matrix<TC>(empty, 0, 0);
      }

      std::vector<TC> rtn_matr3(rtn_matr.size());
      const std::vector<TB2>& rtn_matr2 = matr.get_matr_raw();
      for (size_t i = 0; i < nrow * ncol; i += 1) {
        rtn_matr3[i] = f(rtn_matr[i], rtn_matr2[i]);
      };

      return Matrix<TC>(rtn_matr3, nrow, ncol);
    };

    template <typename TB2> Matrix<std::common_type_t<TB, TB2>> 
    mult1(const Matrix<TB2> &matr) {

      using TC = std::common_type_t<TB, TB2>;

      const std::vector<int>& dim_vec = matr.get_dim();
      std::vector<TC> empty = {};

      if (ncol != dim_vec[0]) {
          std::cerr << "❌ Matrix size mismatch in mult1\n";
          return Matrix<TC>(empty, 0, 0);
      };

      const std::vector<TB2>& rtn_matr2 = matr.get_matr_raw();

      std::vector<TC> rtn_matr3(nrow * dim_vec[1]);

      int j;
      int j2;
      TC val;
      for (int i = 0; i < nrow; i += 1) {
        for (j2 = 0; j2 < dim_vec[1]; j2 += 1) {
          val = 0;
          for (j = 0; j < ncol; j += 1) {
            val += rtn_matr[j * nrow + i] * rtn_matr2[j2 * dim_vec[0] + j];
          };
          rtn_matr3[j2 * nrow + i] = val; 
        };
      };

      return Matrix<TC>(rtn_matr3, nrow, dim_vec[1]);
    };

   template <typename TB2> Matrix<std::common_type_t<TB, TB2>> 
   mult2(const Matrix<TB2> &matr) {
      
      using TC = std::common_type_t<TB, TB2>;

      const std::vector<int>& dim_vec = matr.get_dim();
      std::vector<TC> empty = {};

      if (nrow != dim_vec[1]) {
          std::cerr << "❌ Matrix size mismatch in mult2\n";
          return Matrix<TC>(empty, 0, 0);
      };

      const std::vector<TB2>& rtn_matr2 = matr.get_matr_raw();

      std::vector<TC> rtn_matr3(ncol * dim_vec[0]);

      int j;
      int j2;
      TC val;
      for (int i = 0; i < dim_vec[0]; i += 1) {
        for (j2 = 0; j2 < ncol; j2 += 1) {
          val = 0;
          for (j = 0; j < dim_vec[1]; j += 1) {
            val += rtn_matr[j2 * nrow + j] * rtn_matr2[j * dim_vec[0] + i];
          };
          rtn_matr3[j2 * dim_vec[0] + i] = val; 
        };
      };

      return Matrix<TC>(rtn_matr3, dim_vec[0], ncol);
    };

    template <typename TB2> Matrix<std::common_type_t<TB, TB2>> 
    mult1_opt_raw(const Matrix<TB2> &matr) {
      
      using TC = std::common_type_t<TB, TB2>;

      const std::vector<int>& dim_vec = matr.get_dim();
      std::vector<TC> empty = {};

      if (ncol != dim_vec[0]) {
          std::cerr << "❌ Matrix size mismatch in mult1\n";
          return Matrix<TC>(empty, 0, 0);
      };

      const std::vector<TB2>& rtn_matr2 = matr.get_matr_raw();

      std::vector<TC> rtn_matr3 = {};
      rtn_matr3.reserve(nrow * dim_vec[1]);

      int j;
      int j2;
      TC val;
      for (int i = 0; i < nrow; i += 1) {
        for (j2 = 0; j2 < dim_vec[1]; j2 += 1) {
          val = 0;
          for (j = 0; j < ncol; j += 1) {
            val += rtn_matr[j * nrow + i] * rtn_matr2[j2 * dim_vec[0] + j];
          };
          rtn_matr3.push_back(val);
        };
      };

      return Matrix<TC>(rtn_matr3, dim_vec[1], nrow);
    };

   template <typename TB2> Matrix<std::common_type_t<TB, TB2>> 
   mult2_opt_raw(const Matrix<TB2> &matr) {
      
      const std::vector<int>& dim_vec = matr.get_dim();

      using TC = std::common_type_t<TB, TB2>;

      std::vector<TC> empty = {};

      if (nrow != dim_vec[1]) {
          std::cerr << "❌ Matrix size mismatch in mult2\n";
          return Matrix<TC>(empty, 0, 0);
      };

      const std::vector<TB2>& rtn_matr2 = matr.get_matr_raw();

      std::vector<TC> rtn_matr3 = {};
      rtn_matr3.reserve(ncol * dim_vec[0]);

      int j;
      int j2;
      TC val;
      for (int i = 0; i < dim_vec[0]; i += 1) {
        for (j2 = 0; j2 < ncol; j2 += 1) {
          val = 0;
          for (j = 0; j < dim_vec[1]; j += 1) {
            val += rtn_matr[j2 * nrow + j] * rtn_matr2[j * dim_vec[0] + i];
          };
          rtn_matr3.push_back(val);
        };
      };

      return Matrix<TC>(rtn_matr3, ncol, dim_vec[0]);
    };

    template <typename TB2> Matrix<std::common_type_t<TB, TB2>> 
    mult1_opt(const Matrix<TB2> &matr) {

      using TC = std::common_type_t<TB, TB2>;

      const std::vector<int>& dim_vec = matr.get_dim();
      std::vector<TC> empty = {};

      if (ncol != dim_vec[0]) {
          std::cerr << "❌ Matrix size mismatch in mult1\n";
          return Matrix<TC>(empty, 0, 0);
      };

      const std::vector<TB2>& rtn_matr2 = matr.get_matr_raw();

      std::vector<TC> rtn_matr3 = {};
      rtn_matr3.reserve(nrow * dim_vec[1]);

      int j;
      int j2;
      TC val;
      for (int i = 0; i < nrow; i += 1) {
        for (j2 = 0; j2 < dim_vec[1]; j2 += 1) {
          val = 0;
          for (j = 0; j < ncol; j += 1) {
            val += rtn_matr[j * nrow + i] * rtn_matr2[j2 * dim_vec[0] + j];
          };
          rtn_matr3.push_back(val);
        };
      };

      Matrix<TC> end_matr(rtn_matr3, dim_vec[1], nrow);
      end_matr.transpose();
      return end_matr;
    };

   template <typename TB2> Matrix<std::common_type_t<TB, TB2>> 
   mult2_opt(const Matrix<TB2> &matr) {

      using TC = std::common_type_t<TB, TB2>;  
      
      const std::vector<int>& dim_vec = matr.get_dim();
      std::vector<TC> empty = {};

      if (nrow != dim_vec[1]) {
          std::cerr << "❌ Matrix size mismatch in mult2\n";
          return Matrix<TC>(empty, 0, 0);
      };

      const std::vector<TB2>& rtn_matr2 = matr.get_matr_raw();

      std::vector<TC> rtn_matr3 = {};
      rtn_matr3.reserve(ncol * dim_vec[0]);

      int j;
      int j2;
      TC val;
      for (int i = 0; i < dim_vec[0]; i += 1) {
        for (j2 = 0; j2 < ncol; j2 += 1) {
          val = 0;
          for (j = 0; j < dim_vec[1]; j += 1) {
            val += rtn_matr[j2 * nrow + j] * rtn_matr2[j * dim_vec[0] + i];
          };
          rtn_matr3.push_back(val);
        };
      };

      Matrix<TC> end_matr(rtn_matr3, ncol, dim_vec[0]);
      end_matr.transpose();
      return end_matr;
    };

    void identity_in() {
      std::vector<TB> empty = {};
      if (nrow != ncol || nrow == 0 || ncol == 0) {
        std::cout << "No identity matrix for non square matrix\n";
        return;
      };

      std::fill(rtn_matr.begin(), rtn_matr.end(), 0);

      for (int i = 0; i < nrow; i += 1) {
        rtn_matr[nrow * i + i] = 1;
      };

    };

    Matrix<TB> identity_out() {
      std::vector<TB> empty = {};
      if (nrow != ncol || nrow == 0 || ncol == 0) {
        std::cout << "No identity matrix for non square matrix\n";
        return Matrix<TB>(empty, 0, 0);
      };


      std::vector<TB> out_v(nrow * nrow);

      for (int i = 0; i < nrow; i += 1) {
        out_v[nrow * i + i] = 1;
      };

      return Matrix<TB>(out_v, nrow, nrow);
    };

    #ifdef __CUDACC__
    
    template <typename TB2>
    __host__ Matrix<std::common_type_t<TB, TB2>>
    mult1_GPU(const Matrix<TB2>& matr) const;
    
    template <typename TB2>
    __host__ Matrix<std::common_type_t<TB, TB2>>
    mult2_GPU(const Matrix<TB2>& matr) const;

    __host__ Matrix<TB>
    power_GPU_out2(const unsigned int& nvl) const;

    __host__ Matrix<TB>
    power_GPU_out1(const unsigned int& nvl) const;

    #endif

    ~Matrix() {};
};

#ifdef __CUDACC__

template <typename TB>
template <typename TB2>
__host__ inline Matrix<std::common_type_t<TB, TB2>>
Matrix<TB>::mult1_GPU(const Matrix<TB2>& matr) const {
    using TC = std::common_type_t<TB, TB2>;

    const std::vector<int>& dim_vec = matr.get_dim();
    std::vector<TC> empty = {};
    if (ncol != dim_vec[0]) {
        std::cerr << "❌ Matrix size mismatch in multGPU\n";
        return Matrix<TC>(empty, 0, 0);
    }

    int m = nrow, k = ncol, n = dim_vec[1];
    std::vector<TC> C(m * n);

    // GPU memory allocation
    TC *d_A, *d_B, *d_C;
    CUDA_CHECK(cudaMalloc(&d_A, m * k * sizeof(TC)));
    CUDA_CHECK(cudaMalloc(&d_B, k * n * sizeof(TC)));
    CUDA_CHECK(cudaMalloc(&d_C, m * n * sizeof(TC)));

    // Type conversion and copy
    std::vector<TC> A_conv(rtn_matr.begin(), 
                           rtn_matr.end());
    std::vector<TC> B_conv(matr.get_matr_raw().begin(), 
                           matr.get_matr_raw().end());
    
    CUDA_CHECK(cudaMemcpy(d_A, A_conv.data(), m * k * sizeof(TC), 
                            cudaMemcpyHostToDevice));
    CUDA_CHECK(cudaMemcpy(d_B, B_conv.data(), k * n * sizeof(TC), 
                            cudaMemcpyHostToDevice));


    cublasHandle_t handle = CUBLASContext::get();
    if constexpr (std::is_same_v<TC, float>) {
        const float alpha = 1.0f, beta = 0.0f;
        CUBLAS_CHECK(cublasSgemm_v2(
            handle,
            CUBLAS_OP_N, CUBLAS_OP_N,
            n, m, k,
            &alpha,
            d_A, n,
            d_B, k,
            &beta,
            d_C, n
        ));
    }
    else if constexpr (std::is_same_v<TC, double>) {
        const double alpha = 1.0, beta = 0.0;
        CUBLAS_CHECK(cublasDgemm_v2(
            handle,
            CUBLAS_OP_N, CUBLAS_OP_N,
            n, m, k,
            &alpha,
            d_A, n,
            d_B, k,
            &beta,
            d_C, n
        ));
    }
    else {
        static_assert(std::is_floating_point_v<TC>, "cuBLAS only supports float or double");
    }

    // Copy result back
    CUDA_CHECK(cudaMemcpy(C.data(), d_C, 
                            m * n * sizeof(TC), 
                            cudaMemcpyDeviceToHost));

    cudaFree(d_A); cudaFree(d_B); cudaFree(d_C);

    return Matrix<TC>(C, m, n);
};

template <typename TB>
template <typename TB2>
__host__ inline Matrix<std::common_type_t<TB, TB2>>
Matrix<TB>::mult2_GPU(const Matrix<TB2>& matr) const {
    using TC = std::common_type_t<TB, TB2>;

    const std::vector<int>& dim_vec = matr.get_dim();
    std::vector<TC> empty = {};
    if (ncol != dim_vec[0]) {
        std::cerr << "❌ Matrix size mismatch in multGPU\n";
        return Matrix<TC>(empty, 0, 0);
    }

    int m = dim_vec[0], k = nrow, n = ncol;
    
    std::vector<TC> C(m * n);

    // GPU memory allocation
    TC *d_A, *d_B, *d_C;
    CUDA_CHECK(cudaMalloc(&d_A, m * k * sizeof(TC)));
    CUDA_CHECK(cudaMalloc(&d_B, k * n * sizeof(TC)));
    CUDA_CHECK(cudaMalloc(&d_C, m * n * sizeof(TC)));

    // Type conversion and copy
    std::vector<TC> B_conv(rtn_matr.begin(), 
                           rtn_matr.end());
    std::vector<TC> A_conv(matr.get_matr_raw().begin(), 
                           matr.get_matr_raw().end());
    
    CUDA_CHECK(cudaMemcpy(d_A, A_conv.data(), m * k * sizeof(TC), 
                            cudaMemcpyHostToDevice));
    CUDA_CHECK(cudaMemcpy(d_B, B_conv.data(), k * n * sizeof(TC), 
                            cudaMemcpyHostToDevice));


    cublasHandle_t handle = CUBLASContext::get();
    if constexpr (std::is_same_v<TC, float>) {
        const float alpha = 1.0f, beta = 0.0f;
        CUBLAS_CHECK(cublasSgemm_v2(
            handle,
            CUBLAS_OP_N, CUBLAS_OP_N,
            n, m, k,
            &alpha,
            d_A, n,
            d_B, k,
            &beta,
            d_C, m
        ));
    } else if constexpr (std::is_same_v<TC, double>) {
        const double alpha = 1.0, beta = 0.0;
        CUBLAS_CHECK(cublasDgemm_v2(
            handle,
            CUBLAS_OP_N, CUBLAS_OP_N,
            n, m, k,
            &alpha,
            d_A, n,
            d_B, k,
            &beta,
            d_C, m
        ));
    } else {
        static_assert(std::is_floating_point_v<TC>, "cuBLAS only supports float or double");
    }

    // Copy result back
    CUDA_CHECK(cudaMemcpy(C.data(), d_C, 
                            m * n * sizeof(TC), 
                            cudaMemcpyDeviceToHost));

    cudaFree(d_A); cudaFree(d_B); cudaFree(d_C);

    return Matrix<TC>(C, m, n);
};

template <typename TB>
__host__ inline Matrix<TB>
Matrix<TB>::power_GPU_out2(const unsigned int &nvl) const {

    const int n = nrow;

    std::vector<TB> empty = {};
    if (ncol != nrow) {
        std::cerr << "❌ Matrix size mismatch in multGPU\n";
        return Matrix<TB>(empty, 0, 0);
    } else if (nvl == 0) {
      empty.resize(nrow * nrow);
      for (int i = 0; i < nrow; i += 1) {
        empty[i * nrow + i] = 1;
      };
      return Matrix<TB>(empty, nrow, nrow);
    } else if (nvl == 1) {
      return *this;
    };

    std::vector<TB> C(n * n);

    // GPU memory allocation
    TB *d_A, *d_B, *d_C;
    CUDA_CHECK(cudaMalloc(&d_A, n * n * sizeof(TB)));
    CUDA_CHECK(cudaMalloc(&d_B, n * n * sizeof(TB)));
    CUDA_CHECK(cudaMalloc(&d_C, n * n * sizeof(TB)));

    // Type conversion and copy
    std::vector<TB> A_conv(rtn_matr.begin(), 
                           rtn_matr.end());
    
    CUDA_CHECK(cudaMemcpy(d_A, A_conv.data(), n * n * sizeof(TB), 
                            cudaMemcpyHostToDevice));
    // better because both lives on the GPU
    CUDA_CHECK(cudaMemcpy(d_B, d_A, n * n * sizeof(TB), 
                        cudaMemcpyDeviceToDevice));


    cublasHandle_t handle = CUBLASContext::get();
    unsigned int i = 0;
    unsigned int i2 = 2;

    if constexpr (std::is_same_v<TB, float>) {
        const float alpha = 1.0f, beta = 0.0f;
       
        while (i2 < nvl) {
         
          CUBLAS_CHECK(cublasSgemm_v2(
                handle,
                CUBLAS_OP_N, CUBLAS_OP_N,
                n, n, n,
                &alpha,
                d_A, n,
                d_A, n,
                &beta,
                d_A, n
          ));

          i2 *= 2;
        };

        i = i2 / 2;

        if (i % 2 != 0) {
          CUBLAS_CHECK(cublasSgemm_v2(
                handle,
                CUBLAS_OP_N, CUBLAS_OP_N,
                n, n, n,
                &alpha,
                d_A, n,
                d_B, n,
                &beta,
                d_C, n
          ));
          i += 1;
        };

        while (i < nvl) {
          if (i % 2 == 0) {
            CUBLAS_CHECK(cublasSgemm_v2(
                handle,
                CUBLAS_OP_N, CUBLAS_OP_N,
                n, n, n,
                &alpha,
                d_A, n,
                d_B, n,
                &beta,
                d_C, n
            ));
          } else {
            CUBLAS_CHECK(cublasSgemm_v2(
                handle,
                CUBLAS_OP_N, CUBLAS_OP_N,
                n, n, n,
                &alpha,
                d_C, n,
                d_B, n,
                &beta,
                d_A, n
            ));
          };
          i += 1;
        };

    } else if constexpr (std::is_same_v<TB, double>) {
        const double alpha = 1.0, beta = 0.0;
       
        while (i2 < nvl) {
         
          CUBLAS_CHECK(cublasDgemm_v2(
                handle,
                CUBLAS_OP_N, CUBLAS_OP_N,
                n, n, n,
                &alpha,
                d_A, n,
                d_A, n,
                &beta,
                d_A, n
          ));

          i2 *= 2;
        };

        i = i2 / 2;

        if (i % 2 != 0) {
          CUBLAS_CHECK(cublasDgemm_v2(
                handle,
                CUBLAS_OP_N, CUBLAS_OP_N,
                n, n, n,
                &alpha,
                d_A, n,
                d_B, n,
                &beta,
                d_C, n
          ));
          i += 1;
        };

        while (i < nvl) {

          if (i % 2 == 0) {
            CUBLAS_CHECK(cublasDgemm_v2(
                handle,
                CUBLAS_OP_N, CUBLAS_OP_N,
                n, n, n,
                &alpha,
                d_A, n,
                d_B, n,
                &beta,
                d_C, n
            ));
          } else {
            CUBLAS_CHECK(cublasDgemm_v2(
                handle,
                CUBLAS_OP_N, CUBLAS_OP_N,
                n, n, n,
                &alpha,
                d_C, n,
                d_B, n,
                &beta,
                d_A, n
            ));
          };
          i += 1;
        };

    } else {
        static_assert(std::is_floating_point_v<TB>, "cuBLAS only supports float or double");
    }

    if (i % 2 == 1) {
        CUDA_CHECK(cudaMemcpy(C.data(), d_C, 
                            n * n * sizeof(TB), 
                            cudaMemcpyDeviceToHost));
    } else {
        CUDA_CHECK(cudaMemcpy(C.data(), d_A, 
                            n * n * sizeof(TB), 
                            cudaMemcpyDeviceToHost));
    };

    cudaFree(d_A); cudaFree(d_B); cudaFree(d_C);

    return Matrix<TB>(C, n, n);
};

template <typename TB>
__host__ inline Matrix<TB>
Matrix<TB>::power_GPU_out1(const unsigned int &nvl) const {

    const int n = nrow;

    // Base checks
    std::vector<TB> empty;
    if (ncol != nrow) {
        std::cerr << "❌ Matrix size mismatch in power_GPU_out\n";
        return Matrix<TB>(empty, 0, 0);
    } else if (nvl == 0) {
        empty.resize(nrow * nrow);
        for (int i = 0; i < nrow; i += 1) {
          empty[i * nrow + i] = 1;
        };
        return Matrix<TB>(empty, nrow, nrow);
    } else if (nvl == 1) {
        return *this;
    }

    std::vector<TB> C(n * n);

    // GPU memory allocation
    TB *d_A, *d_B, *d_C;
    CUDA_CHECK(cudaMalloc(&d_A, n * n * sizeof(TB)));
    CUDA_CHECK(cudaMalloc(&d_B, n * n * sizeof(TB)));
    CUDA_CHECK(cudaMalloc(&d_C, n * n * sizeof(TB)));

    // Copy A to GPU
    std::vector<TB> A_conv(rtn_matr.begin(), rtn_matr.end());
    CUDA_CHECK(cudaMemcpy(d_A, A_conv.data(), n * n * sizeof(TB), cudaMemcpyHostToDevice));

    // Initialize d_B as identity matrix (result accumulator)
    std::vector<TB> host_identity(n * n, 0);
    for (int i = 0; i < n; ++i) host_identity[i * n + i] = TB(1);
    CUDA_CHECK(cudaMemcpy(d_B, host_identity.data(), n * n * sizeof(TB), cudaMemcpyHostToDevice));

    // cuBLAS setup
    cublasHandle_t handle = CUBLASContext::get();
    const TB alpha = TB(1);
    const TB beta  = TB(0);

    int exp = nvl;

    // Lambda for GEMM (auto-selects precision)
    auto gemm = [&](TB* X, TB* Y, TB* Out) {
        if constexpr (std::is_same_v<TB, float>) {
            CUBLAS_CHECK(cublasSgemm_v2(
                handle, CUBLAS_OP_N, CUBLAS_OP_N,
                n, n, n, &alpha,
                X, n, Y, n, &beta, Out, n
            ));
        } else if constexpr (std::is_same_v<TB, double>) {
            CUBLAS_CHECK(cublasDgemm_v2(
                handle, CUBLAS_OP_N, CUBLAS_OP_N,
                n, n, n, &alpha,
                X, n, Y, n, &beta, Out, n
            ));
        } else {
            static_assert(std::is_floating_point_v<TB>,
                "cuBLAS only supports float or double");
        }
    };

    // --- Exponentiation by squaring ---
    while (exp > 0) {
        if (exp & 1) {
            // d_B = d_B * d_A
            gemm(d_B, d_A, d_C);
            std::swap(d_B, d_C);
        }
        // d_A = d_A * d_A
        gemm(d_A, d_A, d_C);
        std::swap(d_A, d_C);

        exp >>= 1; // divide exponent by 2
    }

    // Copy result back
    CUDA_CHECK(cudaMemcpy(C.data(), d_B, n * n * sizeof(TB), cudaMemcpyDeviceToHost));

    cudaFree(d_A);
    cudaFree(d_B);
    cudaFree(d_C);

    return Matrix<TB>(C, n, n);
};

#endif












