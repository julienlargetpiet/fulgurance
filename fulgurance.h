#include <iostream>
#include <vector>
#include <typeinfo>
#include <fstream>
#include <math.h>
#include <chrono>

//@I Stylished documentation is available <a href="https://julienlargetpiet.tech/static/files/fulgurance.html">here</a>
//@I In current development.
//@I This framework provides functions for statistical analysis, machine learning, parsing and data manipulation with its own implementation of matrices and dataframes. Other tools can be found at fulgurance_tools part.
//@I The framework is developped with C++ 14 but should work properly with 11 and 17 and furthers.
//@I The main branch provides algorithms developped on the top of stl vector, but a deque version is coming.
//@G2 Philosophy
//@I Matrices and dataframes implementation are classes. All functions that will transform 'voidly' (internaly) the relative data are built in the classes. All functions that copy and transform the relative data are extern to classes.
//@I Also, all the functions relative to matrices classes exist for more standard type of matrices that is stl 2D vectors.
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

template <typename T> double mod(T &dividend, T &divider) {
  int x = dividend / divider;
  return dividend - x * divider;
};

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

int int_lngth(const int &x) {
  float x2 = x;
  int i = 0;
  while (x2 >= 1) {
    x2 /= 10;
    i +=1;
  };
  return i;
}

//@T roundout
//@U template &lt;typename T&gt; T roundout(T &x, int &n)
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

template <typename T> T roundout(T &x, int &n) {
  unsigned int mlt = 1;
  if (n > -1) {
    for (unsigned int i = 0; i < n; ++i) {
      mlt *= 10;
    };
    return round(x * mlt) / mlt;
  } else {
    n *= -1;
    for (unsigned int i = 0; i < n; ++i) {
      mlt *= 10;
    };
    return round(x / mlt) * mlt;
  };
};

//@T roundin
//@U template &lt;typename T&gt; void roundin(T &x, int &n)
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

template <typename T> void roundin(T &x, int &n) {
  unsigned int mlt = 1;
  if (n > -1) {
    for (unsigned int i = 0; i < n; ++i) {
      mlt *= 10;
    };
    x = round(x * mlt) / mlt;
  } else {
    n *= -1;
    for (unsigned int i = 0; i < n; ++i) {
      mlt *= 10;
    };
    x = round(x / mlt) * mlt;
  };
};

//@T randint
//@U int randint(const int &min, const int max, int seed = -1)
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
//@X

int randint(const int &min, const int max, int seed = -1) {
  unsigned int cnt = 0;
  unsigned long int mlc;
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
  if (seed == -1) {
    auto now = std::chrono::system_clock::now();
    auto duration = now.time_since_epoch();
    rtn = std::chrono::duration_cast<std::chrono::milliseconds>(duration).count();
    rtn /= 10;
    mlc = rtn;
    rtn -= mlc;
    rtn *= 10;
    rtn = round(rtn);
  } else {
    rtn = seed;
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
    rtn *= 10;
    rtn = round(rtn);
    rtn += cur_val;
    cnt2 += 1;
  };
  cur_valint = rtn;
  return (cur_valint % delta) + min;
};

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

template <typename T, typename T2> double logn(T &val, T2 &base) {
  return log(val) / log(base);
};

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

int si(const std::string &x) {
  int rtn = int(x[0]) - 48;
  const int n = x.size();
  for (int i = 1; i < n; ++i) {
    rtn *= 10;
    rtn += (int(x[i]) - 48);
  };
  return rtn;
}

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

//@T sd
//@U double sd(const std::string &x)
//@X
//@D Returns a converted std::string, that can be converted to a double, to a double.
//@A x : is a stl string
//@X 
//@E std::string a = "4566.132214";
//@E double out = sd(a);
//@E 4566.132214
//@X

double sd(const std::string &x) {
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

template <typename T> T sum(const std::vector<T> &x) {
  T rtn = 0;
  for (typename std::vector<T>::const_iterator it = x.begin(); it != x.end(); ++it) {
    rtn += *it;
  }
  return rtn;
};

//@T mean
//@U template &lt;typename T&gt; T mean(const std::vector&lt;T&gt; &x) 
//@X
//@D Returns the mean of all elements in a vector (int, float, double, bool).
//@A x : is a stl vector (int, float, double, bool)
//@X
//@E std::vector&lt;int&gt; vec = {1, 4, 2};
//@E double out = mean(vec);
//@E 2.333333
//@X

template <typename T> T mean(const std::vector<T> &x) {
  float rtn = 0;
  for (typename std::vector<T>::const_iterator it = x.begin(); it != x.end(); ++it) {
    rtn += *it;
  }
  return rtn / x.size();
};

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

template <typename T, typename T2> double quantile(std::vector<T> &x, T2 &prob, double precision = 0.001) {
  double n = x.size();
  unsigned int idx = round((n - 1) * prob);
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

//@T quantile_theoretical
//@U template &lt;typename T, typename T2&gt; double quantile_theoretical(T &mean, T2 &sd, double &val, double offset_prob = 0.05)
//@X
//@D Returns the quantile value for a given theoretical noral distribution. There is an offset probability input that tells the most offset probability the function has to takein count in order to return the quantile value.
//@A mean : is the mean of the normal distribution
//@A sd : is the standard deviation of the normal distribution
//@A val : is the quantile percentage (between 0 and 1)
//@A offset_prob : is the probability from which is no longer not taken in count by the function in order to return a coherent value
//@X
//@E 
//@E double val = 0.65;
//@E double offset_prob = 0.05;
//@E int mean = 144;
//@E int sd = 2;
//@E double out = quantile_theoretical(mean, sd, val, offset_prob);
//@E 144.998
//@X

template <typename T, typename T2> double quantile_theoretical(T &mean, T2 &sd, double &val, double offset_prob = 0.05) {
  double offset = pow(-2 * log(offset_prob * sd * pow((2 * M_PI), 0.5)), 0.5) * sd;
  double rtn = offset * 2 * val + (mean - offset);
  return rtn;
};

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
  std::cout << std::to_string(d1) << "\n";
  double rtn = d1 / sqrt(s1 * s2);
  return rtn;
};

//@T Sd
//@U template &lt;typename T&gt; double Sd(std::vector&lt;T&gt; &x)
//@X
//@D Returns the standard deviation of a stl vector (int, float, double, bool).
//@A x : is an stl vector (int, float, double, bool)
//@X
//@E std::vector&lt;int&gt; vec = {1, 2, 2, 3, 3, 3, 4, 4, 5};
//@E double out = Sd(vec);
//@E 1.33333
//@X

template <typename T> double Sd(std::vector<T> &x) {
  unsigned int i;
  const double n = x.size();
  double mean = x[0];
  for (i = 1; i < n; ++i) {
    mean += x[i];
  };
  mean /= n;
  std::cout << mean << "\n";
  double delta_sq = 0;
  for (i = 0; i < n; ++i) {
    delta_sq += pow(x[i] - mean, 2);
  };
  std::cout << delta_sq << "\n";
  return delta_sq / n;
};

//@L3 Min - Max

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

template <typename T> T min(const std::vector<T> &x) {
  T rtn = x[0];
  for (typename std::vector<T>::const_iterator it = x.begin() + 1; it != x.end(); ++it) {
    if (rtn > *it) {
      rtn = *it;
    };
  };
  return rtn;
};

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
  unsigned int valint = addr;
  unsigned int addr2;
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
  addr = round(addr);
  unsigned long int v;
  long double n = x.size();
  const unsigned int n2 = n;
  n += 0.5 * n;
  T switchr;
  double mlt = 1;
  unsigned int i;
  while (mlt < n2) {
    mlt *= 10;
  };
  for (unsigned int i = 0; i < n2; ++i) {
    switchr = x[i];
    v = sin((((i + 1) * mlt) / n)) * n2 + addr + addr2;
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
  unsigned int valint = addr;
  unsigned int addr2;
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
  addr = round(addr);
  unsigned long int v;
  long double n = x.size();
  const unsigned int n2 = n;
  n += 0.5 * n;
  T switchr;
  double mlt = 1;
  unsigned int i;
  while (mlt < n2) {
    mlt *= 10;
  };
  for (unsigned int i = 0; i < n2; ++i) {
    switchr = x[i];
    v = sin((((i + 1) * mlt) / n)) * n2 + addr + addr2;
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
  unsigned long int v;
  long double n = x.size();
  const unsigned int n2 = n;
  n += 0.5 * n;
  T switchr;
  double mlt = 1;
  unsigned int i;
  while (mlt < n2) {
    mlt *= 10;
  };
  for (unsigned int i = 0; i < n2; ++i) {
    switchr = x[i];
    v = sin((((i + 1) * mlt) / n)) * n2;
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
  unsigned long int v;
  long double n = x.size();
  const unsigned int n2 = n;
  n += 0.5 * n;
  T switchr;
  double mlt = 1;
  unsigned int i;
  while (mlt < n2) {
    mlt *= 10;
  };
  for (unsigned int i = 0; i < n2; ++i) {
    switchr = x[i];
    v = sin((((i + 1) * mlt) / n)) * n2;
    v = v % n2;
    x[i] = x[v];
    x[v] = switchr;
  };
};

//@L3 Print

//@T print_nvec
//@U template &lt;typename T&gt; void print_nvec(const std::vector&lt;T&gt; &x) 
//@X
//@D Print a stl vector (int, float, double, bool)
//@A x : stl vector (int, float, double, bool)
//@X
//@E std::vector&lt;int&gt; vec = {12, 2, 4534, 7, -78, 12122};
//@E for (int i = 0; i &lt; 20; ++i) { vec.push_back(7); }
//@E print_nvec(vec);
//@E :0: 12    2     4534  7     -78   12122 23323 12    6     2     8     45    7     7     7     7     7     7     7     7     7     7     7     7     
//@E :25: 7     7     7     7     7     7     7     
//@X

template <typename T> void print_nvec(const std::vector<T> &x) {
  const int n = x.size();
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

//@T print_svec
//@U template &lt;typename T&gt; void print_nvec(const std::vector&lt;T&gt; &x) 
//@X
//@D Print a stl vector (int, float, double, bool)
//@A x : stl vector (int, float, double, bool)
//@X
//@E std::vector&lt;std::string&gt; vec = {"peugeot", "wolkswagen", "honda", "renault", "stellantis"};
//@E for (int i = 0; i &lt; 20; ++i) { vec.push_back("yesss"); }
//@E print_svec(vec);
//@E :0: peugeot    wolkswagen honda      renault    stellantis yesss      yesss      yesss      yesss      yesss      yesss      yesss      yesss      yesss      yesss      yesss      yesss      
//@E :18: yesss      yesss      yesss      yesss      yesss      yesss      yesss       
//@X

void print_svec(const std::vector<std::string> &x) {
  const int n = x.size();
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
  const int ref_delta = std::to_string(n).length();
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

template <typename T, typename T2> unsigned int match(const std::vector<T> &source, const T2 &ptrn) {
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
    rtn = {-1};
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

//@L3 Sorting algorithms 

//@T sort_descin
//@U template &lt;typename T&gt; void sort_descin(std::vector&lt;T&gt; &x) 
//@X
//@D Transforms a stl vector (int, float, double, bool) to a sorted decreasing stl vector.
//@A x : stl vector (int, float, double, bool) 
//@X
//@E std::vector&lt;int&gt; vec = {1, 5, 2, 1, 5, 22};
//@E sort_descin(vec);
//@E {22, 5, 5, 2, 1, 1}
//@X

template <typename T> void sort_descin(std::vector<T> &x) {
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

//@T sort_ascin
//@U template &lt;typename T&gt; void sort_ascin(std::vector&lt;T&gt; &x) 
//@X
//@D Transforms a stl vector (int, float, double, bool) to a sorted increasing stl vector.
//@A x : stl vector (int, float, double, bool) 
//@X
//@E std::vector&lt;int&gt; vec = {1, 5, 2, 1, 5, 22};
//@E sort_ascin(vec);
//@E {1, 1, 2, 5, 5, 22}
//@X

template <typename T> void sort_ascin(std::vector<T> &x) {
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

//@T sort_descout
//@U template &lt;typename T&gt; void sort_descout(std::vector&lt;T&gt; &x) 
//@X
//@D Returns a stl sorted decreasingly vector from a  stl vector (int, float, double, bool).
//@A x : stl vector (int, float, double, bool) 
//@X
//@E std::vector&lt;int&gt; vec = {1, 5, 2, 1, 5, 22};
//@E std::&lt;int&gt; out = sort_descout(vec);
//@E {22, 5, 5, 2, 1, 1}
//@X

template <typename T> std::vector<T> sort_descout(const std::vector<T> &x) {
  std::vector<T> rtn = x;
  const unsigned int n = x.size();
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

//@T sort_ascout
//@U template &lt;typename T&gt; void sort_ascout(std::vector&lt;T&gt; &x) 
//@X
//@D Returns a stl sorted increasingly vector from a  stl vector (int, float, double, bool).
//@A x : stl vector (int, float, double, bool) 
//@X
//@E std::vector&lt;int&gt; vec = {1, 5, 2, 1, 5, 22};
//@E std::&lt;int&gt; out = sort_ascout(vec);
//@E {1, 1, 2, 5, 5, 22}
//@X

template <typename T> std::vector<T> sort_ascout(const std::vector<T> &x) {
  std::vector<T> rtn = x;
  const unsigned int n = x.size();
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

//@L3 Remove range of elements

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

template <typename T> void rm_ordered(std::vector<T> &x, std::vector<int> ids) {
  const unsigned int n = ids.size();
  for (unsigned int i = 0; i < n; ++i) {
    x.erase(x.begin() + ids[i]);
  };
};

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

//@L3 Others

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

unsigned int pct_to_idx(double &val, unsigned int &sizen) {
  return round((sizen - 1) * val);
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

//@L1 Operations on matrices like 2d vectors std::vector&lt;std::vector&lt;Type&gt;&gt;
//@L2 Transposition

//@T t
//@U template &lt;typename T&gt; std::vector&lt;std::vector&lt;T&gt;&gt; t(const std::vector&lt;std::vector&lt;T&gt;&gt; &x)
//@X
//@D Retursn the transpose of a matrix as 2D stl vector (int, float, double, bool).
//@A x : is a 2D stl vector (int, float, double, bool)
//@X
//@E std::vector&lt;std::vector&lt;int&gt;&gt; matr = {{1, 2, 3}, {4, 5, 6}};
//@E print_matr(matr); // another function from this library to print matrix as 2D stl vector
//@E           [0]       [1]
//@E :0:         1         4
//@E :1:         2         5
//@E :2:         3         6
//@E std::vector&lt;std::vector&lt;int&gt;&gt; out = t(matr);
//@E print_matr(out);
//@E           [0]       [1]       [2]
//@E :0:         1         2         3
//@E :1:         4         5         6
//@X

template <typename T> std::vector<std::vector<T>> t(const std::vector<std::vector<T>> &x) {
  const unsigned int nrow = x.size();
  const unsigned int ncol = x[0].size();
  std::vector<std::vector<T>> matr;
  matr.resize(ncol);
  unsigned int i2;
  for (unsigned int i = 0; i < ncol; ++i) {
    matr[i].resize(nrow);
    for (i2 = 0; i2 < nrow; ++i2) {
      matr[i][i2] = x[i2][i];
    };
  };
  return matr; 
};

//@T t_in_square
//@U template &lt;typename T&gt; void t_in_square(std::vector&lt;std::vector&lt;T&gt;&gt; &x)
//@X
//@D Transforms the input <b>square</b> matrix as 2D stl vector (int, float, double, bool) to its transpose.
//@A x : is a 2D stl vector (int, float, double, bool)
//@X
//@E std::vector&lt;std::vector&lt;int&gt;&gt; matr = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
//@E print_matr(matr); // another function from this library to print matrix as 2D stl vector
//@E 
//@E           [0]       [1]       [2]
//@E :0:         1         4         7
//@E :1:         2         5         8
//@E :2:         3         6         9
//@E
//@E t_in_square(matr);
//@E
//@E print_matr(matr);
//@E
//@E           [0]       [1]       [2]
//@E :0:         1         2         3
//@E :1:         4         5         6
//@E :2:         7         8         9
//@X

template <typename T> void t_in_square(std::vector<std::vector<T>> &x) {
  T ref;
  const unsigned int n  = x.size();
  unsigned int i2;
  for (unsigned int i = 0; i < n; ++i) {
    for (i2 = i + i; i2 < n; ++i2) {
      ref = x[i][i2];
      x[i][i2] = x[i2][i];
      x[i2][i] = ref;
    };
  };
};

//@T t_in
//@U template &lt;typename T&gt; void t_in(std::vector&lt;std::vector&lt;T&gt;&gt; &x)
//@X 
//@D Transforms a matrix as 2D stl vector to its transpose
//@A x : is a matrix as a 2D stl vector
//@X
//@E std::vector&lt;std::vector&lt;int&gt;&gt; matr = {{1, 2, 3, 88, 90}, {4, -5, 6, 78, -7}, {-7, 8, -9, 12, 478}};
//@E print_matr(matr);
//@E           [0]       [1]       [2]
//@E :0:         1         4        -7
//@E :1:         2        -5         8
//@E :2:         3         6        -9
//@E :3:        88        78        12
//@E :4:        90        -7       478
//@E t_in(matr);
//@E print_matr(matr);
//@E           [0]       [1]       [2]       [3]       [4]
//@E :0:         1         2         3        88        90
//@E :1:         4        -5         6        78        -7
//@E :2:        -7         8        -9        12       478
//@E t_in(matr);
//@E print_matr(matr);
//@E           [0]       [1]       [2]
//@E :0:         1         4        -7
//@E :1:         2        -5         8
//@E :2:         3         6        -9
//@E :3:        88        78        12
//@E :4:        90        -7       478
//@X

template <typename T> void t_in(std::vector<std::vector<T>> &x) {
  const unsigned int ncol = x.size();
  const unsigned int nrow = x[0].size();
  unsigned int i2;
  unsigned int i3;
  std::vector<T> cur_vec;
  T switchr;
  if (nrow >= ncol) {
    x.reserve(nrow);
    cur_vec.reserve(nrow);
    for (int i = 0; i < ncol; ++i) {
      cur_vec = x[i];
      i3 = i + 1;
      for (i2 = i3; i2 < nrow; ++i2) {
        if (i3 < ncol) {
          switchr = x[i2][i];
          x[i2][i] = cur_vec[i2];
          x[i][i2] = switchr;
        } else {
          x[i2].push_back(cur_vec[i2]);
        };
        i3 += 1;
      };
      x[i].resize(ncol);
      x[i].shrink_to_fit();
    };
  } else {
    cur_vec.reserve(ncol);
    for (int i = 0; i < nrow; ++i) {
      x[i].reserve(5);
      cur_vec = {};
      for (i3 = 0; i3 < ncol; ++i3) {
        cur_vec.push_back(x[i3][i]);
      };
      i3 = i + 1;
      for (i2 = i3; i2 < ncol; ++i2) {
        if (i3 < nrow) {
          switchr = x[i][i2];
          x[i][i2] = cur_vec[i2];
          x[i2][i] = switchr;
        } else {
          x[i].push_back(cur_vec[i2]);
        };
        i3 += 1;
      };
    };
    x.resize(nrow);
    x.shrink_to_fit();
  };
};

//@L2 Print

//@T print_matr
//@U template &lt;typename T&gt; void print_matr(const std::vector&lt;std::vector&lt;T&gt;&gt; &x) 
//@X
//@D Print a matrix as 2D stl vector.
//@A x : is a 2D stl vector
//@X
//@E std::vector&lt;std::vector&lt;int&gt;&gt; matr = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
//@E print_matr(matr);
//@E           [0]       [1]       [2]
//@E :0:         1         4         7
//@E :1:         2         5         8
//@E :2:         3         6         9
//@X

template <typename T> void print_matr(const std::vector<std::vector<T>> &x) {
  unsigned int i;
  unsigned int i2;
  unsigned int i3;
  unsigned int lngth;
  const unsigned int n = x.size();
  const unsigned int n2 = x[0].size();
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

//@L2 Absolute values

//@T abs_matrin
//@U template &lt;typename T&gt; void abs_matrin(std::vector&lt;std::vector&lt;T&gt;&gt; &x) 
//@X
//@D Transforms all the values of the cells from a matrix as 2D stl vector (int, float, double, bool) to absolute values.
//@A x : is a matrix as 2D stl vector (int, float, double, bool)
//@X
//@E std::vector&lt;std::vector&lt;int&gt;&gt; matr = {{1, 2, 3}, {4, -5, 6}, {-7, 8, -9}};
//@E print_matr(matr); // another function from this library to print matrix as 2D stl vector
//@E           [0]       [1]       [2]
//@E :0:         1         4        -7
//@E :1:         2        -5         8
//@E :2:         3         6        -9
//@E abs_matrin(matr);
//@E print_matr(matr);
//@E           [0]       [1]       [2]
//@E :0:         1         4         7
//@E :1:         2         5         8
//@E :2:         3         6         9
//@X

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

//@T abs_matrout
//@U template &lt;typename T&gt; void abs_matrout(std::vector&lt;std::vector&lt;T&gt;&gt; &x) 
//@X
//@D Returns a marix as 2D stl vector (int, float, double, bool) with only absolute values from a matrix as 2D stl vector (int, float, double, bool). 
//@A x : is a matrix as 2D stl vector (int, float, double, bool)
//@X
//@E std::vector&lt;std::vector&lt;int&gt;&gt; matr = {{1, 2, 3}, {4, -5, 6}, {-7, 8, -9}};
//@E print_matr(matr); // another function from this library to print matrix as 2D stl vector
//@E           [0]       [1]       [2]
//@E :0:         1         4        -7
//@E :1:         2        -5         8
//@E :2:         3         6        -9
//@E std::vector&lt;std::vector&lt;int&gt;&gt; out = abs_matrout(matr);
//@E print_matr(out);
//@E           [0]       [1]       [2]
//@E :0:         1         4         7
//@E :1:         2         5         8
//@E :2:         3         6         9
//@X

template <typename T> std::vector<std::vector<T>> abs_matrout(const std::vector<std::vector<T>> &x) {
  std::vector<std::vector<T>> rtn = x;
  int unsigned i2 = 0;
  const unsigned int n = x.size();
  const unsigned int n2 = x[0].size();
  for (int i = 0; i < n; ++i) {
    for (i2 = 0; i2 < n2; ++i2) {
      if (x[i][i2] < 0) {
        rtn[i][i2] = -1 * x[i][i2];
      };
    };
  };
  return rtn;
};

//@L2 Statistical distributions

//@L3 Normal distribution
//@L4 Getting probability from values

//@T normal_ppoint
//@U template &lt;typename T, typename T2, typename T3&gt; double normal_ppoint(T &mean, T2 &sd, T3 &val)
//@X
//@D Returns the probability of a value in a normal distribution with given parameters.
//@A mean : is the mean of the normal distribution 
//@A sd : is the standard deviation of the normal distribution
//@A val : is the value you want to get its probability
//@X
//@E double mean = 4;
//@E double sdt = 2;
//@E double val = 0.65;
//@E normal_ppoint(mean, sdt, val);
//@E 0.176033
//@X

template <typename T, typename T2, typename T3> double normal_ppoint(T &mean, T2 &sd, T3 &val) {
  return (1 / (sd * pow(M_PI * 2, 0.5))) * exp(-0.5 * pow((val - mean)/sd, 2));
};

//@T normal_prange
//@U template &lt;typename T, typename T2, typename T3, typename T4, typename T5&gt; double normal_prange(T &mean, T2 &sd, T3 &from, T4 &to, T5 &by)
//@X
//@D Returns the probability of a range of value in a normal distribution with given parameters.
//@A mean : is the mean of the normal distribution
//@A sd : is the standard deviation of the normal distribution
//@A from is the first value of the range of values
//@A to : is the last value of the range of values
//@A by : is the accuracy step of the range of values, the lower it is, higher the result will be accurate
//@X
//@E double mean = 3;
//@E double sd = 1.23;
//@E double from = 2;
//@E double to = 4;
//@E double by = 0.1;
//@E double out = normal_prange(mean, sd, from, to, by);
//@E 0.795199
//@X

template <typename T, typename T2, typename T3, typename T4, typename T5> double normal_prange(T &mean, T2 &sd, T3 &from, T4 &to, T5 &by) {
  double delta = 0;
  for (double i = 0; i <= to; i += by) {
    delta += (1 / (sd * pow(M_PI * 2, 0.5))) * exp(-0.5 * pow((from - mean)/sd, 2)) * by;
    from += by;
  };
  return delta;
};

//@L4 Getting values from probability

//@T normal_offval
//@U template &lt;typename T, typename T2&gt; double normal_offval(T &sd, T2 prob)
//@X
//@D Returns the offset value for a given normal distribution with given probability, see example. 
//@A sd : is the standard deviation of the normal distribution
//@A offset_prob : is the offset probability of the wanted value(s)
//@X
//@E double sdt = 2.33;
//@E double offset_prob = 0.001;
//@E double out = normal_offval(sdt, prob);
//@E mean - out
//@E mean - 7.47269 
//@E mean + out
//@E mean + 7.47269
//@X

template <typename T, typename T2> double normal_offval(T &sd, T2 prob) {
  return pow(-2 * log(prob * sd * pow((2 * M_PI), 0.5)), 0.5) * sd;
};

//@L1 Fulgurance Tools

//@T Parser_tokenizer_full
//@U std::vector&lt;std::vector&lt;unsigned int&gt;&gt; Parser_tokenizer_full(std::string &x)
//@X
//@D Returns a 2d stl vectors. First vector is the pair of each parenthesis. Second stl vector is the index of each parenthesis. Takes a stl string as input. 
//@A x : is a stl string
//@X
//@E std::string teste = "(o((ldjf)de)po(m()()m)po)()()";
//@E std::vector&lt;std::vector&lt;unsigned int&gt;&gt; out = Parser_tokenizer_full(teste);
//@E {5 1 0 0 1 4 2 2 3 3 4 5 6 6 7 7}
//@E {0 2 3 8 11 14 16 17 18 19 21 24 25 26 27 28}
//@X

std::vector<std::vector<unsigned int>> Parser_tokenizer_full(std::string &x) {
  std::vector<unsigned int> num_par;
  std::vector<int> cur_val;
  std::vector<unsigned int> idx_vec;
  int i2;
  unsigned int cur_num = 0;
  const unsigned int n = x.length();
  bool alrd;
  for (int i = 0; i < n; ++i) {
    if (x[i] == '(') {
      idx_vec.push_back(i);
      num_par.push_back(0);
      for (i2 = 0; i2 < cur_val.size(); ++i2) {
        cur_val[i2] += 1;
      };
      cur_val.push_back(1);
    } else if (x[i] == ')') {
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

