#include <iostream>
#include <vector>
#include <deque>
#include <math.h>
#include <chrono>
#include <thread>
#include <map>
#include <fstream>
#include <typeinfo>

//@I Stylished documentation is available <a href="https://julienlargetpiet.tech/static/files/fulgurance.html">here</a>
//@I In current development.
//@I This framework provides functions for statistical analysis, machine learning, parsing and data manipulation with its own implementation of matrices and dataframes. Other tools can be found at fulgurance_tools part.
//@I The framework is developped with C++ 14 but should work properly with 11 and 17 and furthers.
//@I The main branch provides algorithms developped on the top of stl vector, but a deque version is coming.
//@G2 Philosophy
//@I Dataframes implementation is a class. All functions that will transform 'voidly' (internaly) the relative data are built in the class. All functions that copy and transform the relative data are extern to classes.
//@I Matrices are stl 2D vectors.
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

//@L3 RegEx

//@T regex_match
//@U std::map&lt;std::vector&lt;unsigned int&gt;, std::map&lt;bool, std::string&gt;&gt; regex_match(std::string &searched, std::string &x)
//@X
//@D Performs a match with the regex flavor.
//@D This library provides an entirely new RegEx flavor. 
//@D Read documentation in README_RegEx.md file for details about synthax.
//@A searched : is the regular expression
//@A x : is the text to search into
//@X
//@E std::string inpt_str = "Le radiateur fonctionne bien.";
//@E std::string searched = "[A-Z a-z][A-Z{+1}a-z{+1} {+1}]{?bien}[A-Z{0}]{+1}";
//@E 
//@E std::map&lt;std::vector&lt;int&gt;, std::map&lt;bool, std::string&gt;&gt; out_mp = regex_match(searched, inpt_str);
//@E std::map&lt;std::vector&lt;int&gt;, std::map&lt;bool, std::string&gt;&gt;::iterator out_it = out_mp.begin();
//@E std::vector&lt;int&gt; idx_v = out_it-&gt;first;
//@E std::map&lt;bool, std::string&gt;::iterator rslt_mp = out_it-&gt;second.begin();
//@E std::string rtn_str = rslt_mp-&gt;second;
//@E bool is_found = rslt_mp-&gt;first;
//@E if (is_found) {
//@E   std::cout &lt;&lt; idx_v[0] &lt;&lt; "\n";
//@E   std::cout &lt;&lt; idx_v[1] &lt;&lt; "\n";
//@E   std::cout &lt;&lt; is_found &lt;&lt; "\n";
//@E   std::cout &lt;&lt; rtn_str &lt;&lt; "\n";
//@E } else {
//@E   std::cout &lt;&lt; "not found\n";
//@E };
//@E 
//@E 0
//@E 28
//@E 1
//@E Le radiateur fonctionne bien.
//@X

//@T regex_grep
//@U std::map&lt;std::vector&lt;int&gt;, std::vector&lt;std::string&gt;&gt; regex_grep(std::string &searched, std::string &x)
//@X
//@D Performs a grep with the regex flavor.
//@D This library provides an entirely new RegEx flavor. 
//@D Read documentation in README_RegEx.md file for details about synthax.
//@A searched : is the input regular expression
//@A x : is the text to search into
//@X
//@E std::string inpt_str = "MMMLe radiateur fonctionne bien.";
//@E std::string searched = "[A-Z a-z][A-Z{+1}a-z{+1} {+1}]{?bien}[A-Z{0}]{+1}";
//@E 
//@E std::map&lt;std::vector&lt;int&gt;, std::vector&lt;std::string&gt;&gt; out_mp2 = regex_search_all(searched, inpt_str);
//@E std::map&lt;std::vector&lt;int&gt;, std::vector&lt;std::string&gt;&gt;::iterator out_it2 = out_mp2.begin();
//@E std::vector&lt;int&gt; idx_v2 = out_it2-&gt;first;
//@E std::vector&lt;std::string&gt; str_v2 = out_it2-&gt;second;
//@E for (int i = 0; i &lt; str_v2.size(); ++i) {
//@E   std::cout &lt;&lt; "idx: " &lt;&lt; idx_v2[i] &lt;&lt; " str: " &lt;&lt; str_v2[i] &lt;&lt; "\n";
//@E };
//@E idx: 31 str: Le radiateur fonctionne bien.
//@E idx: 31 str:  radiateur fonctionne bien.
//@E idx: 31 str:  fonctionne bien.
//@E idx: 31 str: e radiateur fonctionne bien.
//@E idx: 31 str: r fonctionne bien.
//@E idx: 31 str: e bien.
//@X

//@T regex_subout
//@U std::string regex_subout(std::string &searched, std::string &replacer, std::string x)
//@X
//@D Substituates the first pattern matched by the regular expression, to a replacement pattern.
//@A searched : is the regular expression
//@A replacer : is the replacement pattern
//@A x : is the input string to replace searched by replacer into
//@X
//@E std::string inpt_str = "MMMLe radiateur fonctionne bien.... C'est un bon radiateur.";
//@E std::string rplcd = " moteur ";
//@E std::string searched = " a-z{9}[ .]";
//@E std::string out_txt = regex_subout(searched, rplcd, inpt_str);
//@E std::cout &lt;&lt; out_txt &lt;&lt; "\n";
//@E MMMLe moteur fonctionne bien.... C'est un bon radiateur.
//@X

//@T regex_subout_all
//@U std::string regex_subout_all(std::string &searched, std::string &replacer, std::string x)
//@X
//@D Substituates all patterns matched by the regular expression, to a replacement pattern.
//@A searched : is the regular expression
//@A replacer : is the replacement pattern
//@A x : is the input string to replace searched by replacer into
//@X
//@E std::string inpt_str = "MMMLe radiateur fonctionne bien.... C'est un bon radiateur.";
//@E std::string rplcd = " moteur ";
//@E std::string searched = " a-z{9}[ .]";
//@E std::string out_txt = regex_subout_all(searched, rplcd, inpt_str);
//@E std::cout &lt;&lt; out_txt &lt;&lt; "\n";
//@E MMMLe moteur fonctionne bien.... C'est un bon moteur.
//@X

//@T regex_subin
//@U void regex_subin(std::string &searched, std::string &replacer, std::string &x)
//@X
//@D Substituates the first pattern matched by the regular expression, to a replacement pattern.
//@A searched : is the regular expression
//@A replacer : is the replacement pattern
//@A x : is the input string to replace searched by replacer into
//@X
//@E std::string inpt_str = "MMMLe radiateur fonctionne bien.... C'est un bon radiateur.";
//@E std::string rplcd = " moteur ";
//@E std::string searched = " a-z{9}[ .]";
//@E regex_subin(searched, rplcd, inpt_str);
//@E std::cout &lt;&lt; inpt_str &lt;&lt; "\n";
//@E MMMLe moteur fonctionne bien.... C'est un bon radiateur.
//@X

//@T regex_subin_all
//@U void regex_subin_all(std::string &searched, std::string &replacer, std::string &x)
//@X
//@D Substituates all patterns matched by the regular expression, to a replacement pattern.
//@A searched : is the regular expression
//@A replacer : is the replacement pattern
//@A x : is the input string to replace searched by replacer into
//@X
//@E std::string inpt_str = "MMMLe radiateur fonctionne bien.... C'est un bon radiateur.";
//@E std::string rplcd = " moteur ";
//@E std::string searched = " a-z{9}[ .]";
//@E regex_subin_all(searched, rplcd, inpt_str);
//@E std::cout &lt;&lt; inpt_str &lt;&lt; "\n";
//@E MMMLe moteur fonctionne bien.... C'est un bon moteur.
//@X

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

template <typename T> double sum(const std::vector<T> &x) {
  double rtn = 0;
  for (typename std::vector<T>::const_iterator it = x.begin(); it != x.end(); ++it) {
    rtn += *it;
  };
  return rtn;
};

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

template <typename T> T Mean(const std::vector<T> &x) {
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
//@E 1.224745
//@X

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

std::vector<double> qunif(std::vector<double> &x, double &min, double &max) {
  double coeff = 1 / (max - min);
  std::vector<double> rtn_v;
  for (double i : x) {
    rtn_v.push_back(i / coeff + min);
  };
  return rtn_v;
};

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

template <typename T> std::vector<double> dnorm(std::vector<T> &x, double &mean, double &sd, double step = 1) {
  std::vector<double> rtn_v = {};
  const double divider = (sd * pow(2 * M_PI, 0.5));
  for (typename std::vector<T>::iterator i = x.begin(); i != x.end(); ++i) {
    rtn_v.push_back((exp(-0.5 * pow(((mean - *i) / sd), 2))) / divider * step);
  };
  return rtn_v;
};

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
  double divided;
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
  double divided;
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
  double divided;
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
  if (n_trials > n_tot) {
    return {0};
  };
  double n_ones_left;
  double cur_prob;
  const int ref_n_tot = n_ones + n_others;
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
  if (n_trials > n_tot) {
    return {0};
  };
  double n_ones_left;
  double cur_prob;
  double rtn_prob = 0;
  unsigned int cnt = 0;
  const int ref_n_tot = n_ones + n_others;
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
  if (n_trials > n_tot) {
    return {0};
  };
  double n_ones_left;
  double cur_prob;
  double rtn_prob = 0;
  double lst_rtn_prob = 0;
  const int ref_n_tot = n_ones + n_others;
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

//@L3 Parts 

//@T getpart
//@U template &lt;typename T&gt; std::vector&lt;T&gt; getpart(std::vector&lt;T&gt; &x, std::string prt)
//@X
//@D Retursn part of stl vector with R like synthax.
//@A x : is an stl vector
//@A prt : is a std::string that describe the parts of the stl vector to get (R like synthax)
//@X
//@E std::vector&lt;int&gt; vec;
//@E std::vector&lt;int&gt; vec2 = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
//@E vec = getpart(vec2, "1,3,5:9,0:9");
//@E print_nvec(vec);
//@E :0: 2  4  6  7  8  9  10 1  2  3  4  5  6  7  8  9  10 
//@X

template <typename T> std::vector<T> getpart(std::vector<T> &x, std::string prt) {
  const unsigned int n = prt.length();
  std::vector<T> rtn_v;
  unsigned int i = 0;
  unsigned int cur_idx;
  unsigned int untl_idx;
  while (i < n) {
    cur_idx = int(prt[i]) - 48;
    rtn_v.push_back(x[cur_idx]);
    if (prt[i + 1] == ':') {
      i += 2;
      untl_idx = int(prt[i]) - 48;
      while (cur_idx < untl_idx) {
        cur_idx += 1;
        rtn_v.push_back(x[cur_idx]);
      };
    };
    i += 2;
  };
  return rtn_v;
};

//@L4 Add parts to existing stl vector

//@T partout
//@U template &lt;typename T&gt; std::vector&lt;T&gt; partout(std::vector&lt;T&gt; &inpt, std::vector&lt;T&gt; &x, std::string prt)
//@X
//@D Returns the input stl vector with elements added from another stl vector of the same type. The elements added are described with a std::string following the R synthax.
//@A inpt : is the stl vector to which elements from the second stl vector will be added
//@A x : is the stle vecotr from which elements will be added
//@A prt : is a std::string that describes the elements from the second stl vector to be aded to the first stl vector
//@X
//@E std::vector&lt;int&gt; out;
//@E std::vector&lt;int&gt; vec = {52, 88};
//@E std::vector&lt;int&gt; vec2 = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
//@E out = partout(vec, vec2, "1,3,5:9,0:9");
//@E print_nvec(out);
//@E:0: 52 88 2  4  6  7  8  9  10 1  2  3  4  5  6  7  8  9  10 
//@X

template <typename T> std::vector<T> partout(std::vector<T> &inpt, std::vector<T> &x, std::string prt) {
  const unsigned int n = prt.length();
  std::vector<T> rtn_v = inpt;
  unsigned int i = 0;
  unsigned int cur_idx;
  unsigned int untl_idx;
  while (i < n) {
    cur_idx = int(prt[i]) - 48;
    rtn_v.push_back(x[cur_idx]);
    if (prt[i + 1] == ':') {
      i += 2;
      untl_idx = int(prt[i]) - 48;
      while (cur_idx < untl_idx) {
        cur_idx += 1;
        rtn_v.push_back(x[cur_idx]);
      };
    };
    i += 2;
  };
  return rtn_v;
};

//@T partin
//@U template &lt;typename T&gt; std::vector&lt;T&gt; partin(std::vector&lt;T&gt; &inpt, std::vector&lt;T&gt; &x, std::string prt)
//@X
//@D Transforms the input stl vector adding elements from another stl vector of the same type. The elements added are described with a std::string following the R synthax.
//@A inpt : is the stl vector to which elements from the second stl vector will be added
//@A x : is the stle vecotr from which elements will be added
//@A prt : is a std::string that describes the elements from the second stl vector to be aded to the first stl vector
//@X
//@E std::vector&lt;int&gt; vec = {52, 88};
//@E std::vector&lt;int&gt; vec2 = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
//@E partin(vec, vec2, "1,3,5:9,0:9");
//@E print_nvec(vec);
//@E:0: 52 88 2  4  6  7  8  9  10 1  2  3  4  5  6  7  8  9  10 
//@X

template <typename T> void partin(std::vector<T> &inpt, std::vector<T> &x, std::string prt) {
  const unsigned int n = prt.length();
  unsigned int i = 0;
  unsigned int cur_idx;
  unsigned int untl_idx;
  while (i < n) {
    cur_idx = int(prt[i]) - 48;
    inpt.push_back(x[cur_idx]);
    if (prt[i + 1] == ':') {
      i += 2;
      untl_idx = int(prt[i]) - 48;
      while (cur_idx < untl_idx) {
        cur_idx += 1;
        inpt.push_back(x[cur_idx]);
      };
    };
    i += 2;
  };
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

//@L3 Bool and indices conversions

//@T bool_to_idx
//@U std::vector&lt;unsigned int&gt; bool_to_idx(std::vector&lt;bool&gt; &x)
//@X
//@D Converts a boolean vector to an indices vector.
//@A x : is the input boolean vector
//@X
//@E std::vector&lt;bool&gt; xbool = {0, 0, 1, 1, 0, 1, 0};
//@E std::vector<unsigned int> xidx = bool_to_idx(xbool);
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
//@D Dataframe objects supporting reading csv, with custom separator, storing columns in differents type vectors, creating a new Dataframe object on top of an already existing one specifying the rows and columns to copy, the same goes for a matrix (as <code>std::vector&lt;std::vector&lt;T&gt;&gt;</code>) and <code>std::vector&lt;T&gt;</code>. See examples.
//@A See_below : See below
//@X
//@E See below
//@X

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

    std::vector<const char*> type_refv = {};
    std::vector<std::vector<std::string>> tmp_val_refv = {};

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
          if (currow[i] == delim & !str_cxt) {
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
          if (currow[i] == delim & !str_cxt) {
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
      while (getline(readfile, currow)) {
        verif_ncol = 1;
        str_cxt = 0;
        i = 0;
        while (i < currow.length()) {
          if (currow[i] == delim & !str_cxt) {
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
      type_classification();
    };

    void type_classification() {
      unsigned int i;
      unsigned int i2;
      unsigned int n;
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
              type_refv.push_back(typeid(std::string).name());
              matr_idx[0].push_back(i);
              break;
            };
          } else {
            is_flt_dbl = can_be_flt_dbl(cur_str2);
            if (is_flt_dbl) {
              type_refv.push_back(typeid(double).name());
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
            type_refv.push_back(typeid(char).name());
            matr_idx[1].push_back(i);
          } else if (is_bool) {
            type_refv.push_back(typeid(bool).name());
            matr_idx[2].push_back(i);
          } else if (!is_unsigned) {
            type_refv.push_back(typeid(int).name());
            matr_idx[3].push_back(i);
          } else {
            type_refv.push_back(typeid(unsigned int).name());
            matr_idx[4].push_back(i);
          };
        };
      };
      for (i = 0; i < ncol; ++i) {
        if (type_refv[i] == typeid(std::string).name()) {
          for (i2 = 0; i2 < nrow; ++i2) {
            cur_str = tmp_val_refv[i][i2];
            str_v.push_back(cur_str);
          };
        } else if (type_refv[i] == typeid(char).name()) {
          for (i2 = 0; i2 < nrow; ++i2) {
            cur_str = tmp_val_refv[i][i2];
            chr_v.push_back(cur_str[0]);
          };
        } else if (type_refv[i] == typeid(bool).name()) {
          for (i2 = 0; i2 < nrow; ++i2) {
            cur_str = tmp_val_refv[i][i2];
            bool_v.push_back(std::stoi(cur_str));
          };
        } else if (type_refv[i] == typeid(int).name()) {
          for (i2 = 0; i2 < nrow; ++i2) {
            cur_str = tmp_val_refv[i][i2];
            int_v.push_back(std::stoi(cur_str));
          };
        } else if (type_refv[i] == typeid(unsigned int).name()) {
          for (i2 = 0; i2 < nrow; ++i2) {
            cur_str = tmp_val_refv[i][i2];
            uint_v.push_back(std::stoi(cur_str));
          };
        };
      };
    };
 
    void display() {
      unsigned int i2;
      unsigned int i3;
      unsigned int i4;
      unsigned int max_nblngth = std::to_string(nrow).length();
      for (i2 = 0; i2 < max_nblngth + 2; ++i2) {
        std::cout << " ";
      };
      std::string cur_str;
      bool is_found;
      for (i2 = 0; i2 < ncol; ++i2) {
        if (type_refv[i2] == typeid(std::string).name()) {
          cur_str = "<str>";
          if (longest_v[i2] < 5) {
            longest_v[i2] = 5;
          };
        } else if (type_refv[i2] == typeid(char).name()) {
          cur_str = "<char>";
          if (longest_v[i2] < 6) {
            longest_v[i2] = 6;
          };
        } else if (type_refv[i2] == typeid(bool).name()) {
          cur_str = "<bool>";
          if (longest_v[i2] < 6) {
            longest_v[i2] = 6;
          };
        } else if (type_refv[i2] == typeid(int).name()) {
          cur_str = "<int>";
          if (longest_v[i2] < 5) {
            longest_v[i2] = 5;
          };
        } else if (type_refv[i2] == typeid(unsigned int).name()) {
          cur_str = "<uint>";
          if (longest_v[i2] < 6) {
            longest_v[i2] = 6;
          };
        } else if (type_refv[i2] == typeid(double).name()) {
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

    template <typename T> void name_colint(std::vector<int> rows, std::string colname, std::vector<T> &rtn_v) {
      if (name_v.size() == 0) {
        std::cout << "no column names\n";
        reinitiate();
        return;
      };
      unsigned int x = 0;
      while (colname != name_v[x]) {
        x += 1;
      };
      rtn_v.reserve(nrow);
      unsigned int i = 2;
      unsigned int i2;
      if (rows[0] == -1) {
        rows.pop_back();
        for (i2 = 0; i2 < nrow; ++i2) {
          rows.push_back(i2);
        };
      };
      i2 = 0;
      bool is_found = 0;
      while (!is_found) {
        while (i2 < matr_idx[i].size()) {
          if (x == matr_idx[i][i2]) {
            is_found = 1;
            break;
          };
          i2 += 1;
        };
        i += 1;
      };
      i -= 1;
      i2 = nrow * i2;
      if (i == 2) {
        for (i = 0; i < rows.size(); ++i) {
          rtn_v.push_back(bool_v[i2 + rows[i]]);
        };
      } else if (i == 3) {
        for (i = 0; i < rows.size(); ++i) {
          rtn_v.push_back(int_v[i2 + rows[i]]);
        };
      } else if (i == 4) {
        for (i = 0; i < rows.size(); ++i) {
          rtn_v.push_back(uint_v[i2 + rows[i]]);
        };
      } else if (i == 5) {
        for (i = 0; i < rows.size(); ++i) {
          rtn_v.push_back(dbl_v[i2 + rows[i]]);
        };
      };
    };

    template <typename T> void idx_colint(std::vector<int> rows, unsigned int x, std::vector<T> &rtn_v) {
      rtn_v.reserve(nrow);
      unsigned int i = 2;
      unsigned int i2;
      if (rows[0] == -1) {
        rows.pop_back();
        for (i2 = 0; i2 < nrow; ++i2) {
          rows.push_back(i2);
        };
      };
      i2 = 0;
      bool is_found = 0;
      while (!is_found) {
        while (i2 < matr_idx[i].size()) {
          if (x == matr_idx[i][i2]) {
            is_found = 1;
            break;
          };
          i2 += 1;
        };
        i += 1;
      };
      i -= 1;
      i2 = nrow * i2;
      if (i == 2) {
        for (i = 0; i < rows.size(); ++i) {
          rtn_v.push_back(bool_v[i2 + rows[i]]);
        };
      } else if (i == 3) {
        for (i = 0; i < rows.size(); ++i) {
          rtn_v.push_back(int_v[i2 + rows[i]]);
        };
      } else if (i == 4) {
        for (i = 0; i < rows.size(); ++i) {
          rtn_v.push_back(uint_v[i2 + rows[i]]);
        };
      } else if (i == 5) {
        for (i = 0; i < rows.size(); ++i) {
          rtn_v.push_back(dbl_v[i2 + rows[i]]);
        };
      };
    };

    void name_colstr(std::vector<int> rows, std::string colname, std::vector<std::string> &rtn_v) {
      if (name_v.size() == 0) {
        std::cout << "no column names\n";
        reinitiate();
        return;
      };
      unsigned int x = 0;
      while (colname != name_v[x]) {
        x += 1;
      };
      rtn_v.reserve(nrow);
      unsigned int i;
      unsigned int i2;
      if (rows[0] == -1) {
        rows.pop_back();
        for (i2 = 0; i2 < nrow; ++i2) {
          rows.push_back(i2);
        };
      };
      i2 = 0;
      while (i2 < matr_idx[0].size()) {
        if (x == matr_idx[0][i2]) {
          break;
        };
        i2 += 1;
      };
      i2 = nrow * i2;
      for (i = 0; i < rows.size(); ++i) {
        rtn_v.push_back(str_v[i2 + rows[i]]);
      };
    };

    void idx_colstr(std::vector<int> rows, unsigned int x, std::vector<std::string> &rtn_v) {
      rtn_v.reserve(nrow);
      unsigned int i;
      unsigned int i2;
      if (rows[0] == -1) {
        rows.pop_back();
        for (i2 = 0; i2 < nrow; ++i2) {
          rows.push_back(i2);
        };
      };
      i2 = 0;
      while (i2 < matr_idx[0].size()) {
        if (x == matr_idx[0][i2]) {
          break;
        };
        i2 += 1;
      };
      i2 = nrow * i2;
      for (i = 0; i < rows.size(); ++i) {
        rtn_v.push_back(str_v[i2 + rows[i]]);
      };
    };

    void name_colchr(std::vector<int> rows, std::string colname, std::vector<char> &rtn_v) {
      if (name_v.size() == 0) {
        std::cout << "no column names\n";
        reinitiate();
        return;
      };
      unsigned int x = 0;
      while (colname != name_v[x]) {
        x += 1;
      };
      rtn_v.reserve(nrow);
      unsigned int i;
      unsigned int i2;
      if (rows[0] == -1) {
        rows.pop_back();
        for (i2 = 0; i2 < nrow; ++i2) {
          rows.push_back(i2);
        };
      };
      i2 = 0;
      while (i2 < matr_idx[1].size()) {
        if (x == matr_idx[1][i2]) {
          break;
        };
        i2 += 1;
      };
      i2 = nrow * i2;
      for (i = 0; i < rows.size(); ++i) {
        rtn_v.push_back(chr_v[i2 + rows[i]]);
      };
    };

    void idx_colchr(std::vector<int> rows, unsigned int x, std::vector<char> &rtn_v) {
      rtn_v.reserve(nrow);
      unsigned int i;
      unsigned int i2;
      if (rows[0] == -1) {
        rows.pop_back();
        for (i2 = 0; i2 < nrow; ++i2) {
          rows.push_back(i2);
        };
      };
      i2 = 0;
      while (i2 < matr_idx[1].size()) {
        if (x == matr_idx[1][i2]) {
          break;
        };
        i2 += 1;
      };
      i2 = nrow * i2;
      for (i = 0; i < rows.size(); ++i) {
        rtn_v.push_back(chr_v[i2 + rows[i]]);
      };
    };

    template <typename T> void name_matrint(std::vector<int> rows, std::vector<std::string> x_v, std::vector<std::vector<T>> &rtn_matr) {
      std::vector<T> rtn_v;
      unsigned int i;
      unsigned int i2;
      if (rows[0] == -1) {
        rows.pop_back();
        for (i2 = 0; i2 < nrow; ++i2) {
          rows.push_back(i2);
        };
      };
      bool is_found;
      unsigned int x;
      if (name_v.size() == 0) {
        std::cout << "There are no column names\n";
        reinitiate();
        return;
      };
      for (std::string cur_name : x_v) {
        x = 0;
        while (cur_name != name_v[x]) {
          x += 1;
        };
        rtn_v = {};
        rtn_v.reserve(nrow);
        i = 2;
        i2 = 0;
        is_found = 0;
        while (!is_found) {
          while (i2 < matr_idx[i].size()) {
            if (x == matr_idx[i][i2]) {
              is_found = 1;
              break;
            };
            i2 += 1;
          };
          i += 1;
        };
        i -= 1;
        i2 = nrow * i2;
        if (i == 2) {
          for (i = 0; i < rows.size(); ++i) {
            rtn_v.push_back(bool_v[i2 + rows[i]]);
          };
        } else if (i == 3) {
          for (i = 0; i < rows.size(); ++i) {
            rtn_v.push_back(int_v[i2 + rows[i]]);
          };
        } else if (i == 4) {
          for (i = 0; i < rows.size(); ++i) {
            rtn_v.push_back(uint_v[i2 + rows[i]]);
          };
        } else if (i == 5) {
          for (i = 0; i < rows.size(); ++i) {
            rtn_v.push_back(dbl_v[i2 + rows[i]]);
          };
        };
        rtn_matr.push_back(rtn_v);
      };
    };

    template <typename T> void idx_matrint(std::vector<int> rows, std::vector<unsigned int> x_v, std::vector<std::vector<T>> &rtn_matr) {
      std::vector<T> rtn_v;
      unsigned int i;
      unsigned int i2;
      if (rows[0] == -1) {
        rows.pop_back();
        for (i2 = 0; i2 < nrow; ++i2) {
          rows.push_back(i2);
        };
      };
      bool is_found;
      for (unsigned int x : x_v) {
        rtn_v = {};
        rtn_v.reserve(nrow);
        i = 2;
        i2 = 0;
        is_found = 0;
        while (!is_found) {
          while (i2 < matr_idx[i].size()) {
            if (x == matr_idx[i][i2]) {
              is_found = 1;
              break;
            };
            i2 += 1;
          };
          i += 1;
        };
        i -= 1;
        i2 = nrow * i2;
        if (i == 2) {
          for (i = 0; i < rows.size(); ++i) {
            rtn_v.push_back(bool_v[i2 + rows[i]]);
          };
        } else if (i == 3) {
          for (i = 0; i < rows.size(); ++i) {
            rtn_v.push_back(int_v[i2 + rows[i]]);
          };
        } else if (i == 4) {
          for (i = 0; i < rows.size(); ++i) {
            rtn_v.push_back(uint_v[i2 + rows[i]]);
          };
        } else if (i == 5) {
          for (i = 0; i < rows.size(); ++i) {
            rtn_v.push_back(dbl_v[i2 + rows[i]]);
          };
        };
        rtn_matr.push_back(rtn_v);
      };
    };

    void name_matrstr(std::vector<int> rows, std::vector<std::string> x_v, std::vector<std::vector<std::string>> &rtn_matr) {
      std::vector<std::string> rtn_v;
      unsigned int i;
      unsigned int i2;
      if (rows[0] == -1) {
        rows.pop_back();
        for (i2 = 0; i2 < nrow; ++i2) {
          rows.push_back(i2);
        };
      };
      unsigned int x;
      if (name_v.size() == 0) {
        std::cout << "There are no column names\n";
        reinitiate();
        return;
      };
      for (std::string cur_name : x_v) {
        x = 0;
        while (cur_name != name_v[x]) {
          x += 1;
        };
        rtn_v = {};
        rtn_v.reserve(nrow);
        i2 = 0;
        while (i2 < matr_idx[0].size()) {
          if (x == matr_idx[0][i2]) {
            break;
          };
          i2 += 1;
        };
        i2 = nrow * i2;
        for (i = 0; i < rows.size(); ++i) {
          rtn_v.push_back(str_v[i2 + rows[i]]);
        }; 
        rtn_matr.push_back(rtn_v);
      };
    };

    void idx_matrstr(std::vector<int> rows, std::vector<unsigned int> x_v, std::vector<std::vector<std::string>> &rtn_matr) {
      std::vector<std::string> rtn_v;
      unsigned int i;
      unsigned int i2;
      if (rows[0] == -1) {
        rows.pop_back();
        for (i2 = 0; i2 < nrow; ++i2) {
          rows.push_back(i2);
        };
      };
      for (unsigned int x : x_v) {
        rtn_v = {};
        rtn_v.reserve(nrow);
        i = 2;
        i2 = 0;
        while (i2 < matr_idx[0].size()) {
          if (x == matr_idx[0][i2]) {
            break;
          };
          i2 += 1;
        };
        i2 = nrow * i2;
        for (i = 0; i < rows.size(); ++i) {
          rtn_v.push_back(str_v[i2 + rows[i]]);
        };
        rtn_matr.push_back(rtn_v);
      };
    };

    void name_matrchr(std::vector<int> rows, std::vector<std::string> x_v, std::vector<std::vector<char>> &rtn_matr) {
      std::vector<char> rtn_v;
      unsigned int i;
      unsigned int i2;
      if (rows[0] == -1) {
        rows.pop_back();
        for (i2 = 0; i2 < nrow; ++i2) {
          rows.push_back(i2);
        };
      };
      unsigned int x;
      if (name_v.size() == 0) {
        std::cout << "There are no column names\n";
        reinitiate();
        return;
      };
      for (std::string cur_name : x_v) {
        x = 0;
        while (cur_name != name_v[x]) {
          x += 1;
        };
        rtn_v = {};
        rtn_v.reserve(nrow);
        i2 = 0;
        while (i2 < matr_idx[1].size()) {
          if (x == matr_idx[1][i2]) {
            break;
          };
          i2 += 1;
        };
        i2 = nrow * i2;
        for (i = 0; i < rows.size(); ++i) {
          rtn_v.push_back(chr_v[i2 + rows[i]]);
        }; 
        rtn_matr.push_back(rtn_v);
      };
    };

    void idx_matrchr(std::vector<int> rows, std::vector<unsigned int> x_v, std::vector<std::vector<char>> &rtn_matr) {
      std::vector<char> rtn_v;
      unsigned int i;
      unsigned int i2;
      if (rows[0] == -1) {
        rows.pop_back();
        for (i2 = 0; i2 < nrow; ++i2) {
          rows.push_back(i2);
        };
      };
      for (unsigned int x : x_v) {
        rtn_v = {};
        rtn_v.reserve(nrow);
        i = 2;
        i2 = 0;
        while (i2 < matr_idx[1].size()) {
          if (x == matr_idx[1][i2]) {
            break;
          };
          i2 += 1;
        };
        i2 = nrow * i2;
        for (i = 0; i < rows.size(); ++i) {
          rtn_v.push_back(chr_v[i2 + rows[i]]);
        };
        rtn_matr.push_back(rtn_v);
      };
    };

    std::vector<std::vector<std::string>> get_tmp_val_refv() {
      return tmp_val_refv;
    };

    unsigned int get_nrow() {
      return nrow;
    };

    unsigned int get_ncol() {
      return ncol;
    };

    void name_dataframe(std::vector<int> &rows, std::vector<std::string> &name_cols, Dataframe &cur_obj) {
      unsigned int i2;
      unsigned int max_nrow = cur_obj.get_nrow();
      unsigned int max_ncol = cur_obj.get_ncol();
      std::vector<std::string> objcname = cur_obj.get_colname();
      nrow = rows.size();
      ncol = name_cols.size();
      if (objcname.size() == 0) {
        std::cout << "The dataframe has no column name\n";
        reinitiate();
        return;
      };
      std::vector<int> cols = {};
      for (std::string valstr : objcname) {
        for (i2 = 0; i2 < ncol; ++i2) {
          if (valstr == objcname[i2]) {
            cols.push_back(i2);
            break;
          };
        };
      };
      std::vector<std::vector<std::string>> cur_tmp = cur_obj.get_tmp_val_refv();
      std::vector<std::string> cur_v = {};
      if (rows[0] == -1) {
        rows.pop_back();
        for (i2 = 0; i2 < max_nrow; ++i2) {
          rows.push_back(i2);
        };
        nrow = max_nrow;
      };
      if (cols[0] == -1) {
        cols.pop_back();
        for (i2 = 0; i2 < max_ncol; ++i2) {
          cols.push_back(i2);
        };
        ncol = max_ncol;
      };
      for (unsigned int i : cols) {
        cur_v = {};
        for (i2 = 0; i2 < nrow; ++i2) {
          cur_v.push_back(cur_tmp[i][rows[i2]]);  
        };
        tmp_val_refv.push_back(cur_v);
      };
      type_classification();
      name_v = cur_obj.get_colname();
      name_v_row = cur_obj.get_rowname(); 
      longest_determine();
    };

    void idx_dataframe(std::vector<int> &rows, std::vector<int> &cols, Dataframe &cur_obj) {
      unsigned int i2;
      unsigned int max_nrow = cur_obj.get_nrow();
      unsigned int max_ncol = cur_obj.get_ncol();
      nrow = rows.size();
      ncol = cols.size();
      std::vector<std::vector<std::string>> cur_tmp = cur_obj.get_tmp_val_refv();
      std::vector<std::string> cur_v = {};
      if (rows[0] == -1) {
        rows.pop_back();
        for (i2 = 0; i2 < max_nrow; ++i2) {
          rows.push_back(i2);
        };
        nrow = max_nrow;
      };
      if (cols[0] == -1) {
        cols.pop_back();
        for (i2 = 0; i2 < max_ncol; ++i2) {
          cols.push_back(i2);
        };
        ncol = max_ncol;
      };
      for (unsigned int i : cols) {
        cur_v = {};
        for (i2 = 0; i2 < nrow; ++i2) {
          cur_v.push_back(cur_tmp[i][rows[i2]]);  
        };
        tmp_val_refv.push_back(cur_v);
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
          if (type_refv[i2] == typeid(std::string).name()) {
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
        if (type_refv[i2] == typeid(std::string).name()) {
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

    template <typename T> void replace_colint(std::vector<T> &x, unsigned int &colnb) {
      unsigned int i = 2;
      unsigned int i2;
      bool is_found = 0;
      while (!is_found) {
        i2 = 0;
        while (i2 < matr_idx[i].size()) {
          if (colnb == matr_idx[i][i2]) {
            is_found = 1;
            break;
          };
          i2 += 1;
        };
        i += 1;
      };
      i -= 1;
      i2 = nrow * i2;
      if (i == 2) {
        for (i = 0; i < nrow; ++i) {
          bool_v[i2 + i] = x[i];
          tmp_val_refv[colnb][i] = std::to_string(x[i]);
        };
      } else if (i == 3) {
        for (i = 0; i < nrow; ++i) {
          int_v[i2 + i] = x[i];
          tmp_val_refv[colnb][i] = std::to_string(x[i]);
        };
      } else if (i == 4) {
        for (i = 0; i < nrow; ++i) {
          uint_v[i2 + i] = x[i];
          tmp_val_refv[colnb][i] = std::to_string(x[i]);
        };
      } else if (i == 5) {
        for (i = 0; i < nrow; ++i) {
          dbl_v[i2 + i] = x[i];
          tmp_val_refv[colnb][i] = std::to_string(x[i]);
        };
      };
    };

    void replace_colstr(std::vector<std::string> &x, unsigned int &colnb) {
      unsigned int i;
      unsigned int i2 = 0;
      while (1) {
        if (colnb == matr_idx[0][i2]) {
          break;
        };
        i2 += 1;
      };
      i2 = nrow * i2;
      for (i = 0; i < nrow; ++i) {
        str_v[i2 + i] = x[i];
        tmp_val_refv[colnb][i] = x[i];
      };
    };

    void replace_colchr(std::vector<char> &x, unsigned int &colnb) {
      unsigned int i;
      unsigned int i2 = 0;
      std::string cur_str;
      while (1) {
        if (colnb == matr_idx[1][i2]) {
          break;
        };
        i2 += 1;
      };
      i2 = nrow * i2;
      for (i = 0; i < nrow; ++i) {
        chr_v[i2 + i] = x[i];
        cur_str = "";
        cur_str.push_back(x[i]);
        tmp_val_refv[colnb][i] = cur_str;
      };
    };

    template <typename T> void add_colint(std::vector<T> &x, std::string name = "NA") {
      name_v.push_back(name);
      unsigned int i;
      std::vector<std::string> cur_v = {};
      if (typeid(T).name() == typeid(bool).name()) {
        matr_idx[2].push_back(ncol);
        type_refv.push_back(typeid(bool).name());
        for (i = 0; i < nrow; ++i) {
          bool_v.push_back(x[i]);
          cur_v.push_back(std::to_string(x[i]));
        };
      } else if (typeid(T).name() == typeid(int).name()) {
        matr_idx[3].push_back(ncol);
        type_refv.push_back(typeid(int).name());
        for (i = 0; i < nrow; ++i) {
          int_v.push_back(x[i]);
          cur_v.push_back(std::to_string(x[i]));
        };
      } else if (typeid(T).name() == typeid(unsigned int).name()) {
        matr_idx[4].push_back(ncol);
        type_refv.push_back(typeid(unsigned int).name());
        for (i = 0; i < nrow; ++i) {
          uint_v.push_back(x[i]);
          cur_v.push_back(std::to_string(x[i]));
        };
      } else if (typeid(T).name() == typeid(double).name()) {
        matr_idx[5].push_back(ncol);
        type_refv.push_back(typeid(double).name());
        for (i = 0; i < nrow; ++i) {
          dbl_v.push_back(x[i]);
          cur_v.push_back(std::to_string(x[i]));
        }; 
      };
      tmp_val_refv.push_back(cur_v);
      ncol += 1;
    };

    void add_colstr(std::vector<std::string> &x, std::string name = "NA") {
      name_v.push_back(name);
      unsigned int i;
      std::vector<std::string> cur_v = {};
      matr_idx[0].push_back(ncol);
      type_refv.push_back(typeid(std::string).name());
      for (i = 0; i < nrow; ++i) {
        str_v.push_back(x[i]);
        cur_v.push_back(x[i]);
      };
      tmp_val_refv.push_back(cur_v);
      ncol += 1;
    };

    void add_colchr(std::vector<char> &x, std::string name = "NA") {
      name_v.push_back(name);
      unsigned int i;
      std::vector<std::string> cur_v = {};
      matr_idx[1].push_back(ncol);
      type_refv.push_back(typeid(char).name());
      std::string cur_str;
      for (i = 0; i < nrow; ++i) {
        chr_v.push_back(x[i]);
        cur_str = "";
        cur_str.push_back(x[i]);
        cur_v.push_back(cur_str);
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
        i2;
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
            if (type_refv[i] == typeid(std::string).name()) {
              str_v.erase(str_v.begin() + alrd_v[0] * nrow + i2);
              alrd_v[0] += 1;
            } else if (type_refv[i] == typeid(char).name()) {
              chr_v.erase(chr_v.begin() + alrd_v[1] * nrow + i2);
              alrd_v[1] += 1;
            } else if (type_refv[i] == typeid(bool).name()) {
              bool_v.erase(bool_v.begin() + alrd_v[2] * nrow + i2);
              alrd_v[2] += 1;
            } else if (type_refv[i] == typeid(int).name()) {
              int_v.erase(int_v.begin() + alrd_v[3] * nrow + i2);
              alrd_v[3] += 1;
            } else if (type_refv[i] == typeid(unsigned int).name()) {
              uint_v.erase(uint_v.begin() + alrd_v[4] * nrow + i2);
              alrd_v[4] += 1;
            } else if (type_refv[i] == typeid(double).name()) {
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
      std::vector<std::vector<std::string>> cur_tmp = cur_obj.get_tmp_val_refv();
      std::vector<std::string> ext_colv = cur_tmp[ext_col];
      std::vector<std::string> in_colv = tmp_val_refv[in_col];
      std::string cur_val;
      const unsigned int ext_nrow = cur_obj.get_nrow();
      for (int i = nrow - 1; i >= 0; --i) {
        i2 = 0;
        cur_val = in_colv[i];
        while (i2 < ext_nrow) {
          if (cur_val == ext_colv[i2]) {
            break;
          };
          i2 += 1;
        };
        if (i2 == ext_nrow) {
          nrow -= 1;
          for (i2 = 0; i2 < ncol; ++i2) {
            tmp_val_refv[i2].erase(tmp_val_refv[i2].begin() + i);
            if (type_refv[i2] == typeid(std::string).name()) {
              str_v.erase(str_v.begin() + nrow * i2 + i);
            } else if (type_refv[i2] == typeid(char).name()) {
              chr_v.erase(chr_v.begin() + nrow * i2 + i);
            } else if (type_refv[i2] == typeid(bool).name()) {
              bool_v.erase(bool_v.begin() + nrow * i2 + i);
            } else if (type_refv[i2] == typeid(int).name()) {
              int_v.erase(int_v.begin() + nrow * i2 + i);
            } else if (type_refv[i2] == typeid(unsigned int).name()) {
              uint_v.erase(uint_v.begin() + nrow * i2 + i);
            } else if (type_refv[i2] == typeid(double).name()) {
              dbl_v.erase(dbl_v.begin() + nrow * i2 + i);
            };
          };
        };
      };
    };

    void transform_excluding(Dataframe &cur_obj, unsigned int &in_col, unsigned int &ext_col) {
      unsigned int i2;
      unsigned int i3;
      std::vector<std::vector<std::string>> cur_tmp = cur_obj.get_tmp_val_refv();
      std::vector<std::string> ext_colv = cur_tmp[ext_col];
      std::vector<std::string> in_colv = tmp_val_refv[in_col];
      std::string cur_val;
      const unsigned int ext_nrow = cur_obj.get_nrow();
      for (int i = nrow - 1; i >= 0; --i) {
        cur_val = in_colv[i];
        for (i2 = 0; i2 < ext_nrow; ++i2) {
          if (cur_val == ext_colv[i2]) {
            nrow -= 1;
            for (i3 = 0; i3 < ncol; ++i3) {
              tmp_val_refv[i3].erase(tmp_val_refv[i3].begin() + i);
              if (type_refv[i3] == typeid(std::string).name()) {
                str_v.erase(str_v.begin() + nrow * i3 + i);
              } else if (type_refv[i3] == typeid(char).name()) {
                chr_v.erase(chr_v.begin() + nrow * i3 + i);
              } else if (type_refv[i3] == typeid(bool).name()) {
                bool_v.erase(bool_v.begin() + nrow * i3 + i);
              } else if (type_refv[i3] == typeid(int).name()) {
                int_v.erase(int_v.begin() + nrow * i3 + i);
              } else if (type_refv[i3] == typeid(unsigned int).name()) {
                uint_v.erase(uint_v.begin() + nrow * i3 + i);
              } else if (type_refv[i3] == typeid(double).name()) {
                dbl_v.erase(dbl_v.begin() + nrow * i3 + i);
              };
            };
            break;
          };
        };
      };
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

    std::vector<std::string> get_colname() {
      return name_v;
    };

    std::vector<std::string> get_rowname() {
      return name_v_row;
    };

    Dataframe() {};

    ~Dataframe() {};

};

//@T Dataframe.readf
//@U void readf(std::string &file_name, char delim = ',', bool header_name = 1, char str_context_begin = '\'', char str_context_end = '\'')
//@X
//@D Import a csv as a Dataframe object.
//@A file_name : is the file_name of the csv to read
//@A delim : is the column delimiter
//@A header_name : is if the first row is in fact the column names
//@A str_context_begin : is the first symbol of a quote, (to not take in count a comma as a new column if it is in a quote for example)
//@A str_context_end : is the end symbol for a quote context
//@X
//@E Dataframe obj1;
//@E std::string file_name = "teste_dataframe.csv";
//@E obj1.readf(file_name);
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

//@T Dataframe.idx_dataframe
//@U void idx_dataframe(std::vector&lt;int&gt; &rows, std::vector&lt;int&gt; &cols, Dataframe &cur_obj)
//@X
//@D Allow to copy a dataframe choosing rows and columns (by index) of the copied dataframe. 
//@A rows : is the vector containing all the rows to copy (<code>{-1}</code>) for all
//@A cols : is the vector of the index of the columns to copy
//@A cur_obj : is the dataframe that will contain all the rows and columns of the copied dataframe
//@X
//@E // after reading teste_dataframe.csv as obj1
//@E Dataframe obj2;
//@E std::vector&lt;int&gt; idx_rows = {-1};
//@E std::vector&lt;int&gt; idx_cols2 = {1, 2, 3};
//@E obj2.idx_dataframe(idx_rows, idx_cols2, obj1);
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

//@T Dataframe.name_dataframe
//@U void name_dataframe(std::vector&lt;int&gt; &rows, std::vector&lt;int&gt; &name_cols, Dataframe &cur_obj)
//@X
//@D Allow to copy a dataframe choosing rows and columns (by name) of the copied dataframe. 
//@A rows : is the vector containing all the rows to copy (<code>{-1}</code>) for all
//@A cols : is the vector of the name of the columns to copy
//@A cur_obj : is the dataframe that will contain all the rows and columns of the copied dataframe
//@X
//@E // after reading teste_dataframe.csv as obj1
//@E Dataframe obj2;
//@E std::vector&lt;int&gt; idx_rows = {-1};
//@E std::vector&lt;std::string&gt; idx_cols2 = {"col2", "col3", "col3"};
//@E obj2.name_dataframe(idx_rows, idx_cols2, obj1);
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

//@T Dataframe.idx_colint
//@U template &lt;typename T&gt; void idx_colint(std::vector&lt;int&gt; rows, unsigned int x, std::vector&lt;T&gt; &rtn_v)
//@X
//@D Allow to copy a int, unsigned int , bool or double column as a vector&lt;T&gt;, by column index.
//@A rows : is a vector containing the row indices to copy (<code>{-1}</code>) for all
//@A x : is the index of the column to copy
//@A rtn_v : is the vector that will contain the column to copy
//@X
//@E // after reading teste_dataframe.csv as obj1
//@E std::vector&lt;int&gt; currows = {1, 0, 1};
//@E std::vector&lt;unsigned int&gt; outv = {};
//@E obj1.idx_colint(currows, 2, outv);
//@E print_nvec(outv);
//@E :0: 8 3 8
//@X

//@T Dataframe.name_colint
//@U template &lt;typename T&gt; void name_colint(std::vector&lt;int&gt; rows, std::string colname, std::vector&lt;T&gt; &rtn_v)
//@X
//@D Allow to copy a int, unsigned int , bool or double column as a vector&lt;T&gt;, by column name.
//@A rows : is a vector containing the row indices to copy (<code>{-1}</code>) for all
//@A x : is the name of the column to copy
//@A rtn_v : is the vector that will contain the column to copy
//@X
//@E // after reading teste_dataframe.csv as obj1
//@E std::vector&lt;int&gt; currows = {1, 0, 1};
//@E std::vector&lt;unsigned int&gt; outv = {};
//@E obj1.idx_colint(currows, "col2", outv);
//@E print_nvec(outv);
//@E :0: 8 3 8
//@X

//@T Dataframe.idx_colstr
//@U void idx_colstr(std::vector&lt;int&gt; rows, unsigned int x, std::vector&lt;std::string&gt; &rtn_v)
//@X
//@D Allow to copy a std::string column as a vector&lt;std::string&gt;, by column index.
//@A rows : is a vector containing the row indices to copy (<code>{-1}</code>) for all
//@A x : is the index of the column to copy
//@A rtn_v : is the vector that will contain the column to copy
//@X
//@E // after reading teste_dataframe.csv as obj1
//@E std::vector&lt;std::string&gt; outv2 = {};
//@E obj1.idx_colstr(currows, 3, outv2);
//@E print_svec(outv2);
//@E :0: bb aa bb
//@X

//@T Dataframe.name_colstr
//@U template &lt;typename T&gt; void name_colint(std::vector&lt;int&gt; rows, std::string colname, std::vector&lt;T&gt; &rtn_v)
//@X
//@D Allow to copy a int, unsigned int , bool or double column as a vector&lt;std::string&gt;, by column name.
//@A rows : is a vector containing the row indices to copy (<code>{-1}</code>) for all
//@A x : is the name of the column to copy
//@A rtn_v : is the vector that will contain the column to copy
//@X
//@E // after reading teste_dataframe.csv as obj1
//@E std::vector&lt;std::string&gt; outv2 = {};
//@E obj1.name_colstr(currows, "col4", outv2);
//@E print_svec(outv2);
//@E :0: bb aa bb
//@X

//@T Dataframe.idx_colchr
//@U void idx_colchr(std::vector&lt;int&gt; rows, unsigned int x, std::vector&lt;char&gt; &rtn_v)
//@X
//@D Allow to copy a char column as a vector&lt;char&gt;, by column index.
//@A rows : is a vector containing the row indices to copy (<code>{-1}</code>) for all
//@A x : is the index of the column to copy
//@A rtn_v : is the vector that will contain the column to copy
//@X
//@E // after reading teste_dataframe.csv as obj1
//@E std::vector&lt;char&gt; outv3 = {};
//@E obj1.idx_colchr(currows, 5, outv3);
//@E for (char i : outv3) {
//@E   std::cout &lt;&lt; i &lt;&lt; " ";
//@E };
//@E std::cout &lt;&lt; "\n";
//@E e z e
//@X

//@T Dataframe.name_colchr
//@U void name_colchr(std::vector&lt;int&gt; rows, std::string colname, std::vector&lt;char&gt; &rtn_v)
//@X
//@D Allow to copy a char column as a vector&lt;char&gt;, by column name.
//@A rows : is a vector containing the row indices to copy (<code>{-1}</code>) for all
//@A x : is the name of the column to copy
//@A rtn_v : is the vector that will contain the column to copy
//@X
//@E // after reading teste_dataframe.csv as obj1
//@E std::vector&lt;char&gt; outv3 = {};
//@E obj1.name_colchr(currows, "col6", outv3);
//@E for (char i : outv3) {
//@E   std::cout &lt;&lt; i &lt;&lt; " ";
//@E };
//@E std::cout &lt;&lt; "\n";
//@E e z e
//@X

//@T Dataframe.idx_matrint
//@U template &lt;typename T&gt; void idx_matrint(std::vector&lt;int&gt; rows, std::vector&lt;unsigned int&gt; x_v, std::vector&lt;std::vector&lt;T&gt;&gt; &rtn_matr)
//@X
//@D Allow to copy a set of columns that are same type (int, unsigned int, bool or double) as a <code> std::vector&lt;std::vector&lt;T&gt;&gt; </code>, by column index.
//@A rows : is a vector containing the row indices to copy (<code> {-1} </code>) for all
//@A x_v : is the vector containing the indices of the column to copy
//@A rtn_matr : is the matrix that will contain all the columns copyed
//@X
//@E // after reading teste_dataframe.csv as obj1
//@E std::vector&lt;std::vector&lt;unsigned int&gt;&gt; out_matr = {};
//@E std::vector&lt;unsigned int&gt; idx_cols = {1, 0, 2, 2};
//@E obj1.idx_matrint(currows, idx_cols, out_matr);
//@E print_nmatr(out_matr);
//@E                   [0]               [1]               [2]               [3]
//@E :0:                 7                 6                 8                 8
//@E :1:                 2                 1                 3                 3
//@E :2:                 7                 6                 8                 8
//@X

//@T Dataframe.name_matrint
//@U template &lt;typename T&gt; void name_matrint(std::vector&lt;int&gt; rows, std::vector&lt;std::string&gt; x_v, std::vector&lt;std::vector&lt;T&gt;&gt; &rtn_matr)
//@X
//@D Allow to copy a set of columns that are same type (int, unsigned int, bool or double) as a <code>std::vector&lt;std::vector&lt;T&gt;&gt;</code>, by column name.
//@A rows : is a vector containing the row indices to copy (<code>{-1}</code>) for all
//@A x_v : is the vector containing the names of the column to copy
//@A rtn_matr : is the matrix that will contain all the columns copyed
//@X
//@E // after reading teste_dataframe.csv as obj1
//@E std::vector&lt;std::vector&lt;unsigned int&gt;&gt; out_matr = {};
//@E std::vector&lt;std::string&gt; idx_vec2 = {"col1", "col2", "col3"};
//@E obj1.name_matrint(currows, idx_vec2, out_matr);
//@E print_nmatr(out_matr);
//@E                   [0]               [1]               [2]
//@E :0:                 6                 7                 8
//@E :1:                 1                 2                 3
//@E :2:                 6                 7                 8
//@X

//@T Dataframe.idx_matrstr
//@U void idx_matrstr(std::vector&lt;int&gt; rows, std::vector&lt;unsigned int&gt; x_v, std::vector&lt;std::vector&lt;std::string&gt;&gt; &rtn_matr)
//@X
//@D Allow to copy a set of columns that are <code>std::string</code> type as a <code>std::vector&lt;std::vector&lt;std::string&gt;&gt;</code>, by column index.
//@A rows : is a vector containing the row indices to copy (<code>{-1}</code>) for all
//@A x_v : is the vector containing the indices of the column to copy
//@A rtn_matr : is the matrix that will contain all the columns copyed
//@X
//@E // after reading teste_dataframe.csv as obj1
//@E std::vector&lt;std::vector&lt;std::string&gt;&gt; out_matr2 = {};
//@E std::vector&lt;unsigned int&gt; idx_cols = {3};
//@E obj1.idx_matrstr(currows, idx_cols, out_matr2);
//@E print_smatr(out_matr2);
//@E                     [0]
//@E :0:                   bb
//@E :1:                   aa
//@E :2:                   bb
//@X

//@T Dataframe.name_matrstr
//@U void name_matrstr(std::vector&lt;int&gt; rows, std::vector&lt;std::string&gt; x_v, std::vector&lt;std::vector&lt;std::string&gt;&gt; &rtn_matr)
//@X
//@D Allow to copy a set of columns that are <code>std::string</code> type as a <code>std::vector&lt;std::vector&lt;std::string&gt;&gt;</code>, by column name.
//@A rows : is a vector containing the row indices to copy (<code>{-1}</code>) for all
//@A x_v : is the vector containing the names of the column to copy
//@A rtn_matr : is the matrix that will contain all the columns copyed
//@X
//@E // after reading teste_dataframe.csv as obj1
//@E std::vector&lt;std::vector&lt;std::string&gt;&gt; out_matr2 = {};
//@E std::vector&lt;std::string&gt; idx_vec2 = {"col4"};
//@E obj1.name_matrstr(currows, idx_vec2, out_matr2);
//@E print_smatr(out_matr2);
//@E                     [0]
//@E :0:                   bb
//@E :1:                   aa
//@E :2:                   bb
//@X

//@T Dataframe.idx_matrchr
//@U void idx_matrchr(std::vector&lt;int&gt; rows, std::vector&lt;unsigned int&gt; x_v, std::vector&lt;std::vector&lt;char&gt;&gt; &rtn_matr)
//@X
//@D Allow to copy a set of columns that are <code>char</code> type as a <code>std::vector&lt;std::vector&lt;char&gt;&gt;</code>, by column index.
//@A rows : is a vector containing the row indices to copy (<code>{-1}</code>) for all
//@A x_v : is the vector containing the indices of the column to copy
//@A rtn_matr : is the matrix that will contain all the columns copyed
//@X
//@E // after reading teste_dataframe.csv as obj1
//@E std::vector&lt;std::vector&lt;char&gt;&gt; out_matr3 = {};
//@E std::vector&lt;unsigned int&gt; idx_cols = {5};
//@E obj1.idx_matrchr(currows, idx_cols, out_matr3);
//@E print_smatr(out_matr3);
//@E                     [0]
//@E :0:                    e
//@E :1:                    z
//@E :2:                    e
//@X

//@T Dataframe.name_matrchr
//@U void name_matrchr(std::vector&lt;int&gt; rows, std::vector&lt;std::string&gt; x_v, std::vector&lt;std::vector&lt;char&gt;&gt; &rtn_matr)
//@X
//@D Allow to copy a set of columns that are <code>char</code> type as a <code>std::vector&lt;std::vector&lt;char&gt;&gt;</code>, by column name.
//@A rows : is a vector containing the row indices to copy (<code>{-1}</code>) for all
//@A x_v : is the vector containing the names of the column to copy
//@A rtn_matr : is the matrix that will contain all the columns copyed
//@X
//@E // after reading teste_dataframe.csv as obj1
//@E std::vector&lt;char&gt; out_matr3 = {};
//@E std::vector&lt;std::string&gt; idx_vec2 = {"col6"};
//@E obj1.name_matrchr(currows, idx_vec2, out_matr3);
//@E print_smatr(out_matr3);
//@E                     [0]
//@E :0:                    e
//@E :1:                    z
//@E :2:                    e
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

//@T Dataframe.replace_colint
//@U template &lt;typename T&gt; void replace_colint(std::vector&lt;T&gt; &x, unsigned int &colnb)
//@X
//@D Replace a int, unsigned int, bool or double column of the associated dataframe.
//@A x : is the column (as vector) that will replace the dataframe column
//@A colnb : is the index of the column to replace
//@X
//@E // after reading teste_dataframe.csv as obj1
//@E 
//@E std::vector&lt;unsigned int&gt; rpl_col = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 
//@E                                       10, 11, 12, 13, 14};
//@E unsigned int col = 0;
//@E obj1.replace_colint(rpl_col, col);
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

//@T Dataframe.replace_colstr
//@U void replace_colstr(std::vector&lt;std::string&gt; &x, unsigned int &colnb)
//@X
//@D Replace a string column of the associated dataframe.
//@A x : is the column (as vector) that will replace the dataframe column
//@A colnb : is the index of the column to replace
//@X
//@E // after reading teste_dataframe.csv as obj1
//@E
//@E std::vector&lt;std::string&gt; rpl_col = {"0", "1", "2", "3", "4", "5", "6", 
//@E                                         "7", "8", "9", 
//@E                                         "10", "11", "12", "13", "14"};
//@E unsigned int col = 3;
//@E obj1.replace_colstr(rpl_col, col);
//@E obj1.display();
//@E     &lt;uint&gt; &lt;uint&gt; &lt;uint&gt; &lt;str&gt; &lt;int&gt; &lt;char&gt;
//@E     col1   col2   col3   col4  col5  col6
//@E :0:  1      2      3      0     5     z
//@E :1:  6      7      8      1     10    e
//@E :2:  1      2      3      2     5     h
//@E :3:  6      7      8      3     10    a
//@E :4:  1      2      3      4     -5    q
//@E :5:  6      7      8      5     10    p
//@E :6:  1      2      3      6     5     j
//@E :7:  6      7      8      7     10    i
//@E :8:  6      7      8      8     10    p
//@E :9:  1      2      3      9     5     j
//@E :10: 6      7      8      10    10    i
//@E :11: 6      7      8      11    10    i
//@E :12: 6      7      8      12    10    p
//@E :13: 1      2      3      13    5     j
//@E :14: 6      7      8      14    10    i
//@X

//@T Dataframe.replace_colchr
//@U void replace_colchr(std::vector&lt;char&gt; &x, unsigned int &colnb)
//@X
//@D Replace a string column of the associated dataframe.
//@A x : is the column (as vector) that will replace the dataframe column
//@A colnb : is the index of the column to replace
//@X
//@E // after reading teste_dataframe.csv as obj1
//@E
//@E std::vector&lt;char&gt; rpl_col = {'c', 'c', 'c', 'c', 'c', 'c', 'c', 
//@E                                       'c', 'c', 'c', 
//@E                                       'b', 'b', 'v', 'v', 'v'};
//@E unsigned int col = 5;
//@E obj1.replace_colchr(rpl_col, col);
//@E obj1.display();
//@E     &lt;uint&gt; &lt;uint&gt; &lt;uint&gt; &lt;str&gt; &lt;int&gt; &lt;char&gt;
//@E     col1   col2   col3   col4  col5  col6
//@E :0:  1      2      3      aa    5     c
//@E :1:  6      7      8      bb    10    c
//@E :2:  1      2      3      cc    5     c
//@E :3:  6      7      8      uu    10    c
//@E :4:  1      2      3      s4    -5    c
//@E :5:  6      7      8      s9    10    c
//@E :6:  1      2      3      a4    5     c
//@E :7:  6      7      8      m9    10    c
//@E :8:  6      7      8      s9    10    c
//@E :9:  1      2      3      a4    5     c
//@E :10: 6      7      8      m9    10    b
//@E :11: 6      7      8      m9    10    b
//@E :12: 6      7      8      s9    10    v
//@E :13: 1      2      3      NA    5     v
//@E :14: 6      7      8      m9    10    v
//@X

//@T Dataframe.add_colint
//@U template &lt;typename T&gt; void add_colint(std::vector&lt;T&gt; &x, std::string name = "NA")
//@X
//@D Add a column int, unsigned int, bool or double type to the associated dataframe
//@A x : is the column to add
//@A name : is the column to add name
//@X
//@E // after reading teste_dataframe.csv as obj1
//@E std::vector&lt;unsigned int&gt; rpl_col = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 
//@E                                       10, 11, 12, 13, 14};
//@E obj1.add_colint(rpl_col);
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

//@T Dataframe.add_colstr
//@U void add_colstr(std::vector&lt;std::string&gt; &x, std::string name = "NA")
//@X
//@D Add a column string type to the associated dataframe.
//@A x : is the column to add
//@A name : is the column to add name
//@X
//@E // after reading teste_dataframe.csv as obj1
//@E 
//@E std::vector&lt;std::string&gt; rpl_col = {"0", "1", "2", "3", "4", "5", "6", "7", "8", "9", 
//@E                                       "10", "11", "12", "13", "14"};
//@E obj1.add_colstr(rpl_col);
//@E obj1.display();
//@E     &lt;uint&gt; &lt;uint&gt; &lt;uint&gt; &lt;str&gt; &lt;int&gt; &lt;char&gt; &lt;str&gt;
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

//@T Dataframe.add_colchr
//@U add_colchr(std::vector&lt;char&gt; &x, std::string name = "NA")
//@X
//@D Add a column char type to the associated dataframe.
//@A x : is the column to add
//@A name : is the column to add name
//@X
//@E // after reading teste_dataframe.csv as obj1
//@E std::vector&lt;char&gt; rpl_col = {'c', 'c', 'c', 'c', 'c', 'c', 'c', 
//@E                                       'c', 'c', 'c', 
//@E                                       'b', 'b', 'v', 'v', 'v'};
//@E obj1.add_colchr(rpl_col);
//@E obj1.display();
//@E     &lt;uint&gt; &lt;uint&gt; &lt;uint&gt; &lt;str&gt; &lt;int&gt; &lt;char&gt; &lt;char&gt;
//@E     col1   col2   col3   col4  col5  col6   NA
//@E :0:  1      2      3      aa    5     z      c
//@E :1:  6      7      8      bb    10    e      c
//@E :2:  1      2      3      cc    5     h      c
//@E :3:  6      7      8      uu    10    a      c
//@E :4:  1      2      3      s4    -5    q      c
//@E :5:  6      7      8      s9    10    p      c
//@E :6:  1      2      3      a4    5     j      c
//@E :7:  6      7      8      m9    10    i      c
//@E :8:  6      7      8      s9    10    p      c
//@E :9:  1      2      3      a4    5     j      c
//@E :10: 6      7      8      m9    10    i      b
//@E :11: 6      7      8      m9    10    i      b
//@E :12: 6      7      8      s9    10    p      v
//@E :13: 1      2      3      NA    5     j      v
//@E :14: 6      7      8      m9    10    i      v
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

//@T Dataframe.transform_excluding
//@U void transform_excluding(Dataframe &cur_obj, unsigned int &in_col, unsigned int &ext_col)
//@X
//@D Applies a excluding join on the associated dataframe.
//@A cur_obj : is the other dataframe used for the excluding join
//@A in_col : is the index of the column representing the key (primary) of the associated dataframe
//@A ext_col : is the index of the column representing the key (foreign) of the other dataframe used for the excluding join
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
//@E    &lt;str&gt; &lt;uint&gt;
//@E    col1  col2
//@E :0: id3   1
//@E :1: id10  1
//@E :2: id13  6
//@X

//@L1 Operations on matrices like 2d vectors std::vector&lt;std::vector&lt;Type&gt;&gt;

//@L2 Read matrix from file

//@T read_matr
//@U template &lt;typename T&gt; void read_matr(std::string &file_name, std::vector&lt;std::vector&lt;T&gt;&gt; &out_matr, char delim = ',')
//@X
//@D Returns a matrix stored in a file. 
//@A file_name : is the name of the file
//@A out_matr : is a declared matrix
//@A delim : is the column delimiter
//@X
//@E  std::string teste_file = "teste.csv";
//@E  std::vector&lt;std::vector&lt;double&gt;&gt; out_matr;
//@E  read_matr(teste_file, out_matr);
//@E  print_matr(out_matr);
//@E
//@E  [0] [1] [2] [3] [4]
//@E  :0:  1  2  3  4  5
//@E  :1:  6  7  8  9 10
//@E  :2:  1  2  3  4  5
//@E  :3:  6  7  8  9 10
//@E  :4:  1  2  3  4  5
//@E  :5:  6  7  8  9 10
//@E  :6:  1  2  3  4  5
//@E  :7:  6  7  8  9 10
//@E
//@X

template <typename T> void read_matr(std::string &file_name, std::vector<std::vector<T>> &out_matr, char delim = ',') {
  std::fstream read_file(file_name);
  std::vector<T> cur_col = {};
  std::string currow;
  std::string cur_cell = "";
  unsigned int cnt;
  unsigned int cnt2;
  int cur_val;
  getline(read_file, currow);
  if (typeid(T).name() == typeid(int).name() || typeid(T).name() == typeid(unsigned int).name()) {
    for (cnt = 0; cnt < currow.length(); ++cnt) {
      if (currow[cnt] == delim) {
        cur_val = std::stoi(cur_cell);
        cur_col.push_back(cur_val);
        out_matr.push_back(cur_col);
        cur_col = {};
        cur_cell = "";
      } else if (currow[cnt] != ' ') {
        cur_cell.push_back(currow[cnt]);
      };
    };
    cur_val = std::stoi(cur_cell);
    cur_col.push_back(cur_val);
    out_matr.push_back(cur_col);
    cur_cell = "";
    while (getline(read_file, currow)) {
      cnt2 = 0;
      for (cnt = 0; cnt < currow.length(); ++cnt) {
        if (currow[cnt] == delim) {
          cur_val = std::stoi(cur_cell);
          out_matr[cnt2].push_back(cur_val);
          cur_cell = "";
          cnt2 += 1;
        } else if (currow[cnt] != ' ') {
          cur_cell.push_back(currow[cnt]);
        };
      };
      cur_val = std::stoi(cur_cell);
      out_matr[cnt2].push_back(cur_val);
    };
  } else if (typeid(T).name() == typeid(float).name()) {
    for (cnt = 0; cnt < currow.length(); ++cnt) {
      if (currow[cnt] == delim) {
        cur_val = std::stof(cur_cell);
        cur_col.push_back(cur_val);
        out_matr.push_back(cur_col);
        cur_col = {};
        cur_cell = "";
      } else if (currow[cnt] != ' ') {
        cur_cell.push_back(currow[cnt]);
      };
    };
    cur_val = std::stof(cur_cell);
    cur_col.push_back(cur_val);
    out_matr.push_back(cur_col);
    cur_cell = "";
    while (getline(read_file, currow)) {
      cnt2 = 0;
      for (cnt = 0; cnt < currow.length(); ++cnt) {
        if (currow[cnt] == delim) {
          cur_val = std::stof(cur_cell);
          out_matr[cnt2].push_back(cur_val);
          cur_cell = "";
          cnt2 += 1;
        } else if (currow[cnt] != ' ') {
          cur_cell.push_back(currow[cnt]);
        };
      };
      cur_val = std::stof(cur_cell);
      out_matr[cnt2].push_back(cur_val);
    };
  } else if (typeid(T).name() == typeid(double).name()) {
    for (cnt = 0; cnt < currow.length(); ++cnt) {
      if (currow[cnt] == delim) {
        cur_val = std::stod(cur_cell);
        cur_col.push_back(cur_val);
        out_matr.push_back(cur_col);
        cur_col = {};
        cur_cell = "";
      } else if (currow[cnt] != ' ') {
        cur_cell.push_back(currow[cnt]);
      };
    };
    cur_val = std::stod(cur_cell);
    cur_col.push_back(cur_val);
    out_matr.push_back(cur_col);
    cur_cell = "";
    while (getline(read_file, currow)) {
      cnt2 = 0;
      for (cnt = 0; cnt < currow.length(); ++cnt) {
        if (currow[cnt] == delim) {
          cur_val = std::stod(cur_cell);
          out_matr[cnt2].push_back(cur_val);
          cur_cell = "";
          cnt2 += 1;
        } else if (currow[cnt] != ' ') {
          cur_cell.push_back(currow[cnt]);
        };
      };
      cur_val = std::stod(cur_cell);
      out_matr[cnt2].push_back(cur_val);
      cur_cell = "";
    };
  } else if (typeid(T).name() == typeid(long double).name()) {
    for (cnt = 0; cnt < currow.length(); ++cnt) {
      if (currow[cnt] == delim) {
        cur_val = std::stold(cur_cell);
        cur_col.push_back(cur_val);
        out_matr.push_back(cur_col);
        cur_col = {};
        cur_cell = "";
      } else if (currow[cnt] != ' ') {
        cur_cell.push_back(currow[cnt]);
      };
    };
    cur_val = std::stold(cur_cell);
    cur_col.push_back(cur_val);
    out_matr.push_back(cur_col);
    cur_cell = "";
    while (getline(read_file, currow)) {
      cnt2 = 0;
      for (cnt = 0; cnt < currow.length(); ++cnt) {
        if (currow[cnt] == delim) {
          cur_val = std::stold(cur_cell);
          out_matr[cnt2].push_back(cur_val);
          cur_cell = "";
          cnt2 += 1;
        } else if (currow[cnt] != ' ') {
          cur_cell.push_back(currow[cnt]);
        };
      };
      cur_val = std::stold(cur_cell);
      out_matr[cnt2].push_back(cur_val);
      cur_cell = "";
    };
  } else if (typeid(T).name() == typeid(long int).name() || typeid(T).name() == typeid(long unsigned int).name()) {
    for (cnt = 0; cnt < currow.length(); ++cnt) {
      if (currow[cnt] == delim) {
        cur_val = std::stol(cur_cell);
        cur_col.push_back(cur_val);
        out_matr.push_back(cur_col);
        cur_col = {};
        cur_cell = "";
      } else if (currow[cnt] != ' ') {
        cur_cell.push_back(currow[cnt]);
      };
    };
    cur_val = std::stol(cur_cell);
    cur_col.push_back(cur_val);
    out_matr.push_back(cur_col);
    cur_cell = "";
    while (getline(read_file, currow)) {
      cnt2 = 0;
      for (cnt = 0; cnt < currow.length(); ++cnt) {
        if (currow[cnt] == delim) {
          cur_val = std::stol(cur_cell);
          out_matr[cnt2].push_back(cur_val);
          cur_cell = "";
          cnt2 += 1;
        } else if (currow[cnt] != ' ') {
          cur_cell.push_back(currow[cnt]);
        };
      };
      cur_val = std::stol(cur_cell);
      out_matr[cnt2].push_back(cur_val);
      cur_cell = "";
    };
  } else if (typeid(T).name() == typeid(long long int).name() || typeid(T).name() == typeid(long long unsigned int).name()) {
    for (cnt = 0; cnt < currow.length(); ++cnt) {
      if (currow[cnt] == delim) {
        cur_val = std::stoll(cur_cell);
        cur_col.push_back(cur_val);
        out_matr.push_back(cur_col);
        cur_col = {};
        cur_cell = "";
      } else if (currow[cnt] != ' ') {
        cur_cell.push_back(currow[cnt]);
      };
    };
    cur_val = std::stoll(cur_cell);
    cur_col.push_back(cur_val);
    out_matr.push_back(cur_col);
    cur_cell = "";
    while (getline(read_file, currow)) {
      cnt2 = 0;
      for (cnt = 0; cnt < currow.length(); ++cnt) {
        if (currow[cnt] == delim) {
          cur_val = std::stoll(cur_cell);
          out_matr[cnt2].push_back(cur_val);
          cur_cell = "";
          cnt2 += 1;
        } else if (currow[cnt] != ' ') {
          cur_cell.push_back(currow[cnt]);
        };
      };
      cur_val = std::stoll(cur_cell);
      out_matr[cnt2].push_back(cur_val);
      cur_cell = "";
    };
  };
};

//@T write_matr
//@U template &lt;typename T&gt; void write_matr(std::string &file_name, std::vector&lt;std::vector&lt;T&gt;&gt; &in_matr, char delim = ',')
//@X
//@D Writes a matrix into a file.
//@A file_name : is the name of the file
//@A in_matr : is the input matrix
//@A delim : is the chosen column delimiter
//@X
//@E
//@E  std::string teste_file = "teste2.csv";
//@E  std::vector&lt;std::vector&lt;int&gt;&gt; in_matr = {
//@E          {1, 2, 3, 4},
//@E          {1, 2, 3, 4},
//@E          {1, 2, 3, 4},
//@E          {1, 2, 3, 4},
//@E          {1, 2, 3, 4},
//@E          {1, 2, 3, 4}
//@E  };
//@E
//@E  write_matr(teste_file, in_matr);
//@E
//@X

template <typename T> void write_matr(std::string &file_name, std::vector<std::vector<T>> &in_matr, char delim = ',') {
  std::string currow;
  std::fstream outfile(file_name, std::ios::out);
  T cur_val;
  std::string cur_str;
  unsigned int i = 0;
  unsigned int i2;
  const unsigned int n = in_matr.size();
  const unsigned int n2 = in_matr[0].size();
  std::vector<T> cur_v = {};
  cur_v.reserve(n2);
  while (i < n) {
    i2 = 0;
    currow = "";
    cur_v = in_matr[i];
    while (i2 < n2 - 1) {
      cur_val = cur_v[i2];
      cur_str = std::to_string(cur_val);
      currow += cur_str;
      currow.push_back(delim);
      i2 += 1;
    };
    cur_val = cur_v[i2];
    cur_str = std::to_string(cur_val);
    currow += cur_str;
    outfile << currow + "\n";
    i += 1;
  };
};

//@L2 Sum elements for each rows and columns

//@T sum_nxp
//@U template &lt;typename T&gt; std::vector&lt;std::vector&lt;T&gt;&gt; sum_nxp(std::vector&lt;std::vector&lt;T&gt;&gt; &matr)
//@X
//@D Returns as the first vector the sum of elements in each row, and in the second vector the sum of each elements in each column
//@A matr : is the input matrice 
//@X
//@E std::vector&lt;std::vector&lt;double&gt;&gt; matr = {{1, 2}, {3, 4}, {5, 6}};
//@E print_matr(matr);
//@E std::vector&lt;std::vector&lt;double&gt;&gt; outmatr = sum_xnx(matr);
//@E for (double i : outmatr[0]) {
//@E   std::cout &lt;&lt; i &lt;&lt; " ";
//@E };
//@E std::cout &lt;&lt; "\n";
//@E for (double i : outmatr[1]) {
//@E   std::cout &lt;&lt; i &lt;&lt; " ";
//@E };
//@E std::cout &lt;&lt; "\n";
//@E 9 12
//@E 3 7 11
//@X

template <typename T> std::vector<std::vector<T>> sum_nxp(std::vector<std::vector<T>> &matr) {
  std::vector<T> sum_row;
  std::vector<T> sum_col;
  const unsigned int n_col = matr.size();
  const unsigned int n_row = matr[0].size();
  sum_col.resize(n_col, 0);
  sum_row.reserve(n_row);
  unsigned int i = 0;
  unsigned int i2 = 0;
  T cur_sum;
  T cur_val;
  for (i = 0; i < n_row; ++i) {
    cur_sum = 0;
    for (i2 = 0; i2 < n_col; ++i2) {
      cur_val = matr[i2][i];
      sum_col[i2] += cur_val;
      cur_sum += cur_val;
    };
    sum_row.push_back(cur_sum);
  };
  std::vector<std::vector<T>> rtn_sums = {sum_row, sum_col};
  return rtn_sums;
};

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

//@T print_nmatr
//@U template &lt;typename T&gt; void print_nmatr(const std::vector&lt;std::vector&lt;T&gt;&gt; &x) 
//@X
//@D Print a matrix (float, int, double...) as 2D stl vector.
//@A x : is a 2D stl vector (float, int, double...)
//@X
//@E
//@E std::vector&lt;std::vector&lt;int&gt;&gt; out_matr = {
//@E     {1, 2, 3, 4},
//@E     {1, 2, 3, 4},
//@E     {1, 2, 333, 4},
//@E     {1, 2, 3, 4},
//@E     {1, 2, 3, 4}
//@E   };
//@E print_nmatr(out_matr);
//@E
//@E           [0]       [1]       [2]       [3]       [4]
//@E :0:         1         1         1         1         1
//@E :1:         2         2         2         2         2
//@E :2:         3         3       333         3         3
//@E :3:         4         4         4         4         4
//@E
//@M print_nmatr1.jpg
//@E
//@E std::vector&lt;std::vector&lt;double&gt;&gt; out_matr2 = {
//@E   {1, 2, 3, 4},
//@E   {1, 2, 3, 4},
//@E   {1, 2, 333.23, 4},
//@E   {1, 2, 3, 4},
//@E   {1, 2, 3, 4}
//@E };
//@E print_nmatr(out_matr2);
//@E
//@E           [0]       [1]       [2]       [3]       [4]
//@E :0:         1         1         1         1         1
//@E :1:         2         2         2         2         2
//@E :2:         3         3    333.23         3         3
//@E :3:         4         4         4         4         4
//@E
//@M print_nmatr2.jpg
//@X

template <typename T> void print_nmatr(const std::vector<std::vector<T>> &x) {
  unsigned int i;
  unsigned int i2;
  int i3;
  int lngth;
  unsigned int cnt;
  const unsigned int n = x.size();
  const unsigned int n2 = x[0].size();
  std::string cur_val;
  std::cout << "   ";
  for (i = 0; i < n; ++i) {
    lngth = std::to_string(i).length();
    for (i3 = 0; i3 < 16 - lngth; ++i3) {
      std::cout << " ";
    };
    std::cout << "[" << i << "]";
  };
  std::cout << "\n";
  if (typeid(T).name() == typeid(float).name() || typeid(T).name() == typeid(double).name() || typeid(T).name() == typeid(long double).name()) {
    for (int i2 = 0; i2 < n2; ++i2) {
      std::cout << ":" << i2 << ":";
      for (i = 0; i < n; ++i) {
        if (i != 0) {
          for (i3 = 0; i3 < std::to_string(i2).length() - 1; ++i3) {
            std::cout << " "; 
          };
        };
        cur_val = std::to_string(x[i][i2]);
        cnt = cur_val.length() - 1;
        while (cur_val[cnt] == '0') {
          cur_val.pop_back();
          cnt -= 1;
        };
        if (cur_val[cnt] == '.') {
          cur_val.pop_back();
        };
        lngth = cur_val.length() + std::to_string(i2).length() - 1;
        for (i3 = 0; i3 < 18 - lngth; ++i3) {
          std::cout << " ";
        };
        std::cout << cur_val;
      };
      std::cout << "\n";
    };
  } else {
    for (int i2 = 0; i2 < n2; ++i2) {
      std::cout << ":" << i2 << ":";
      for (i = 0; i < n; ++i) {
        if (i != 0) {
          for (i3 = 0; i3 < std::to_string(i2).length() - 1; ++i3) {
            std::cout << " "; 
          };
        };
        cur_val = std::to_string(x[i][i2]);
        lngth = cur_val.length() + std::to_string(i2).length() - 1;
        for (i3 = 0; i3 < 18 - lngth; ++i3) {
          std::cout << " ";
        };
        std::cout << x[i][i2];
      };
      std::cout << "\n";
    };
  };
};

//@T print_smatr
//@U template &lt;typename T&gt; void print_smatr(const std::vector&lt;std::vector&lt;T&gt;&gt; &x) 
//@X
//@D Print a matrix (std::string, char) as 2D stl vector.
//@A x : is a 2D stl vector (std::string, char)
//@X
//@E std::vector&lt;std::vector&lt;std::string&gt;&gt; out_matr3 = {
//@E    {"1", "2", "3", "4"},
//@E    {"1", "2", "3", "4"},
//@E    {"1", "2", "333", "44224441111111"},
//@E    {"1", "2", "3", "4"},
//@E    {"1", "2", "3", "4"}
//@E  };
//@E print_smatr(out_matr3);
//@E
//@E                     [0]                 [1]                 [2]                 [3]                 [4]
//@E :0:                    1                    1                    1                    1                    1
//@E :1:                    2                    2                    2                    2                    2
//@E :2:                    3                    3                  333                    3                    3
//@E :3:                    4                    4       44224441111111                    4                    4
//@E
//@M print_smatr1.jpg
//@E
//@E std::vector&lt;std::vector&lt;char&gt;&gt; out_matr4 = {
//@E    {'1', '2', '3', '4'},
//@E    {'1', '2', '3', '4'},
//@E    {'1', '2', '3', '4'},
//@E    {'1', '2', '3', '4'},
//@E    {'1', '2', '3', '4'}
//@E };
//@E
//@E print_smatr(out_matr4);
//@E
//@E                     [0]                 [1]                 [2]                 [3]                 [4]
//@E :0:                    1                    1                    1                    1                    1
//@E :1:                    2                    2                    2                    2                    2
//@E :2:                    3                    3                    3                    3                    3
//@E :3:                    4                    4                    4                    4                    4
//@E
//@M print_smatr2.jpg
//@X

template <typename T> void print_smatr(const std::vector<std::vector<T>> &x) {
  unsigned int i;
  unsigned int i2;
  int i3;
  int lngth;
  const unsigned int n = x.size();
  const unsigned int n2 = x[0].size();
  std::string cur_val;
  std::cout << "   ";
  for (i = 0; i < n; ++i) {
    lngth = std::to_string(i).length();
    for (i3 = 0; i3 < 18 - lngth; ++i3) {
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
      cur_val = x[i][i2];
      lngth = cur_val.length() + std::to_string(i2).length() - 1;
      for (i3 = 0; i3 < 21 - lngth; ++i3) {
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

//@T det_small
//@U template &lt;typename T&gt; double det_small(std::vector&lt;std::vector&lt;T&gt;&gt; &inpt_matr)
//@X
//@D Calculates matrix determinant up to 5x5.
//@A impt_matr : is the input matrix
//@X
//@E 
//@E std::vector&lt;std::vector&lt;int&gt;&gt; inpt_matr = {
//@E                                               {81, 55, 1, 81, 40},
//@E                                               {42, 48, 41, 37, 5},
//@E                                               {84, 1, 61, 612, 6},
//@E                                               {52, 59, 23, 50, 22},
//@E                                               {39, 6, 95, 69, 23},
//@E                                             };
//@E int out_val = det_small(inpt_matr);
//@E std::cout &lt;&lt; out_val &lt;&lt; "\n";
//@E 1473982232
//@E
//@X

template <typename T> double det_small(std::vector<std::vector<T>> &inpt_matr){
  if (inpt_matr.size() == 2) {
    return inpt_matr[0][0] * inpt_matr[1][1] - inpt_matr[0][1] * inpt_matr[1][0];
  };
  double rtn_val = 0;
  const unsigned int n = inpt_matr.size();
  const unsigned int n2 = n - 2;
  std::vector<unsigned int> moov_v = {};
  moov_v.resize(n2, 1);
  std::vector<unsigned int> pos_v = {};
  pos_v.reserve(n2);
  unsigned int cnt;
  unsigned int cnt2;
  unsigned int cur_col1 = n2;
  unsigned int cur_col2 = n2 + 1;
  unsigned int cur_n;
  unsigned int bf_idx;
  double cur_val;
  double cur_prod_val;
  bool alrd_in;
  for (cnt = 0; cnt < n2; ++cnt) {
    pos_v.push_back(cnt);
  };
  while (1) {
    cur_prod_val = 1;
    for (cnt = 0; cnt < n2; ++cnt) {
      cur_prod_val *= inpt_matr[pos_v[cnt]][cnt];
      if (moov_v[cnt] % 2 == 0) {
        cur_prod_val *= -1;
      };
    };
    cur_val = inpt_matr[cur_col1][n2] * inpt_matr[cur_col2][n2 + 1] - inpt_matr[cur_col1][n2 + 1] * inpt_matr[cur_col2][n2];
    rtn_val += (cur_val * cur_prod_val);
    cnt = 3;
    cur_n = n2 - 1;
    if (moov_v[cur_n] == n - (n - cnt)) {
      while (moov_v[cur_n] == n - (n - cnt)) {
        if (cur_n == 0) {
          return rtn_val;
        };
        moov_v[cur_n] = 1;
        cur_n -= 1;
        cnt += 1;
      };
      moov_v[cur_n] += 1;
      if (cur_n == 0) {
        pos_v[0] += 1;
      } else {
        cnt = pos_v[cur_n] + 1;
        while (1) {
          alrd_in = 0;
          cnt2 = 0;
          while (cnt2 < cur_n) {
            if (cnt == pos_v[cnt2]) {
              alrd_in = 1;
              break;
            };
            cnt2 += 1;
          };
          if (!alrd_in) {
            pos_v[cur_n] = cnt;
            break;
          };
          cnt += 1;
        };
      };
      cur_n += 1;
      while (cur_n < n2) {
        cnt = 0;
        while (1) {
          alrd_in = 0;
          cnt2 = 0;
          while (cnt2 < cur_n) {
            if (cnt == pos_v[cnt2]) {
              alrd_in = 1;
              break;
            };
            cnt2 += 1;
          };
          if (!alrd_in) {
            pos_v[cur_n] = cnt;
            break;
          };
          cnt += 1;
        };
        cur_n += 1;
      };
    } else {
      moov_v[cur_n] += 1;
      if (cur_n > 0) {
        cnt = pos_v[cur_n] + 1;
        while (1) {
          alrd_in = 0;
          cnt2 = 0;
          while (cnt2 < cur_n) {
            if (cnt == pos_v[cnt2]) {
              alrd_in = 1;
              break;
            };
            cnt2 += 1;
          };
          if (!alrd_in) {
            pos_v[cur_n] = cnt;
            break;
          };
          cnt += 1;
        };
      } else {
        pos_v[0] += 1;
      };
    };
    cnt = 0;
    while (1) {
      alrd_in = 0;
      cnt2 = 0;
      while (cnt2 < n2) {
        if (cnt == pos_v[cnt2]) {
          alrd_in = 1;
          break;
        };
        cnt2 += 1;
      };
      if (!alrd_in) {
        cur_col1 = cnt;
        break;
      };
      cnt += 1;
    };
    cnt = cur_col1 + 1;
    while (1) {
      alrd_in = 0;
      cnt2 = 0;
      while (cnt2 < n2) {
        if (cnt == pos_v[cnt2]) {
          alrd_in = 1;
          break;
        };
        cnt2 += 1;
      };
      if (!alrd_in) {
        cur_col2 = cnt;
        break;
      };
      cnt += 1;
    };
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
//@U unsigned int all_comb_iter(std::deque&lt;bool&gt; &x)
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

//@T letter_to_nb
//@U unsigned int letter_to_nb(std::string &x)
//@X
//@D Returns an int corresponding to the input letter.
//@D This algorithm can be used to get which unique id number it is, if we know that it has been generated with <a href="#nb_to_letter">nb_to_letter</a> function
//@A x : is the input string
//@X
//@E std::string inpt_str = "ecfy";
//@E unsigned int rtn_val = letter_to_nb(inpt_str);
//@E std::cout << rtn_val << "\n";
//@E 90089
//@E 
//@E inpt_str = "ajf";
//@E rtn_val = letter_to_nb(inpt_str);
//@E std::cout << rtn_val << "\n";
//@E 
//@E 942
//@X

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


std::map<std::vector<unsigned int>, std::map<bool, std::string>> regex_findr2sub(std::string &searched, std::string &x) {
  char cur_chr;
  unsigned int i = 0;
  unsigned int cnt = 0;
  unsigned int ref_cnt;
  const unsigned int n = searched.length();
  const unsigned int n2 = x.length();
  bool agn;
  bool agn2;
  bool or_state = 0;
  unsigned int ref_int1;
  unsigned int ref_int2;
  bool range_state;
  bool cur_found;
  unsigned int rep_val;
  unsigned int rep_val_cnt;
  unsigned int ref_rep_val = 1;
  unsigned int jump_i;
  unsigned int jump_i2;
  unsigned int cur_lmt;
  unsigned int ref_cur_lmt;
  unsigned int bf_rep_val;
  bool greedy_state1 = 0;
  bool greedy_state2 = 0;
  std::string cur_matched_str = "";
  std::string matched_str = "";
  std::string rtn_str;
  unsigned int lst_cnt;
  unsigned int pre_cnt;
  unsigned int cur_ref_cnt;
  unsigned int cur_ref_i;
  unsigned int temp_i;
  bool is_repetition = 0;
  bool alrd_zero = 0;
  bool or_found_alrd;
  unsigned int cur_idx;
  unsigned int bf_cnt_zero = 0;
  unsigned int bgn_i;
  while (i < n & cnt < n2) {
    greedy_state2 = 0;
    if (searched[i] == '\\') {
      i += 1;
    } else {
      if (searched[i] == '[') {
        or_found_alrd = 0;
        ref_cnt = cnt;
        or_state = 1;
        i += 1;
        bgn_i = i;
        jump_i = i;
        while (searched[jump_i] != ']' & searched[jump_i - 1] != '\\') {
          jump_i += 1;
        };
        jump_i2 = jump_i;
        if (jump_i + 2 < n) {
          if (searched[jump_i + 1] == '{') {
            is_repetition = 1;
            jump_i += 2;
            if (jump_i + 1 < n) {
              if (searched[jump_i] == '+') {
                  greedy_state1 = 1;
                  jump_i += 1;
              };
            } else {
              return {{{0, 0}, {{0, ""}}}};
            };
            if (searched[jump_i] != '}') {
              ref_rep_val = (int(searched[jump_i]) - 48);
              jump_i += 1;
              while (searched[jump_i] != '}') {
                ref_rep_val *= 10;
                ref_rep_val += (int(searched[jump_i]) - 48);
                jump_i += 1;
              };
            } else {
              return {{{0, 0}, {{0, ""}}}};
            };
          };
        };
      };
    };
    rep_val = 1;
    cur_found = 0;
    range_state = 0;
    ref_int1 = int(searched[i]);
    if (i + 1 < n) {
      if (searched[i + 1] == '-') {
        i += 2;
        if (!(i < n)) {
          return {{{0, 0}, {{0, ""}}}};
        };
        range_state = 1;
        ref_int2 = int(searched[i]);
        if (int(x[cnt]) >= ref_int1 & int(x[cnt]) <= ref_int2) {
          cur_found = 1;
        };
      } else if (ref_int1 == int(x[cnt])) {
        cur_found = 1;
      };
    } else if (ref_int1 == int(x[cnt])) {
      cur_found = 1;
    };
    cur_matched_str = x[cnt];
    i += 1;
    cnt += 1;
    if (cur_found & i < n) {
      if (searched[i] != '\\') {
        if (searched[i] == '{') {
          is_repetition = 1;
          i += 1;
          if (searched[i] == '+') {
            greedy_state2 = 1;
            i += 1;
          };
          if (searched[i] != '}') {
            rep_val = int(searched[i]) - 48;
            i += 1;
            while (searched[i] != '}') {
              rep_val *= 10;
              rep_val += (int(searched[i]) - 48);
              i += 1;
            };
          } else {
            return {{{0, 0}, {{0, ""}}}};
          };
          i += 1;
        };
      } else {
        i += 1;
      };
      if (greedy_state2 & rep_val == 0) {
        rep_val = 1;
        if (ref_rep_val == 0) {
          ref_rep_val = 1;
        };
      };
      if (greedy_state1 & ref_rep_val == 0) {
        ref_rep_val = 1;
        if (rep_val == 0) {
          rep_val = 1;
        };
      };
      bf_rep_val = rep_val;
      if (range_state & is_repetition & rep_val != 0 & ref_rep_val != 0) {
        agn = 1;
        rep_val *= ref_rep_val;
        rep_val -= 1;
        rep_val_cnt = 0;
        while (rep_val_cnt < rep_val) {
          agn2 = int(x[cnt]) >= ref_int1 & int(x[cnt]) <= ref_int2;
          if (agn2) {
            cur_matched_str.push_back(x[cnt]);
            if (!(cnt + 1 < n2) & rep_val - rep_val_cnt > 1) {
              agn = 0;
              break;
            } else {
              cnt += 1;
            };
            rep_val_cnt += 1;
          } else {
            agn = 0;
            break;
          };
        };
        if (!agn) {
          cur_found = 0;
        } else if (greedy_state1 || greedy_state2) {
          if (greedy_state1 & greedy_state2) {
            cur_lmt = bf_rep_val * ref_rep_val;
          } else if (greedy_state1) {
            cur_lmt = bf_rep_val;
          } else if (greedy_state2) {
            cur_lmt = ref_rep_val;
          };
          while (agn) {
            rep_val_cnt = 0;
            while (rep_val_cnt < cur_lmt) {
              agn2 = int(x[cnt]) >= ref_int1 & int(x[cnt]) <= ref_int2;
              if (agn2) {
                cur_matched_str.push_back(x[cnt]);
                if (!(cnt + 1 < n2) & cur_lmt - rep_val_cnt > 1) {
                  agn = 0;
                  break;
                } else {
                  cnt += 1;
                };
                rep_val_cnt += 1;
              } else {
                agn = 0;
                break;
              };
            };
          };
        };
        rep_val = 1;
      } else if (is_repetition & rep_val != 0 & ref_rep_val != 0) {
        agn = 1;
        rep_val *= ref_rep_val;
        rep_val -= 1;
        rep_val_cnt = 0;
        while (rep_val_cnt < rep_val) {
          agn2 = int(x[cnt]) == ref_int1;
          if (agn2) {
            cur_matched_str.push_back(x[cnt]);
            if (!(cnt + 1 < n2) & rep_val - rep_val_cnt > 1) {
              agn = 0;
              break;
            } else {
              cnt += 1;
            };
            rep_val_cnt += 1;
          } else {
            agn = 0;
            break;
          };
        };
        if (!agn) {
          cur_found = 0;
        } else if (greedy_state1 || greedy_state2) {
          if (greedy_state1 & greedy_state2) {
            cur_lmt = bf_rep_val * ref_rep_val;
          } else if (greedy_state1) {
            cur_lmt = bf_rep_val;
          } else if (greedy_state2) {
            cur_lmt = ref_rep_val;
          };
          while (agn) {
            rep_val_cnt = 0;
            while (rep_val_cnt < cur_lmt) {
              agn2 = int(x[cnt]) == ref_int1;
              if (agn2) {
                cur_matched_str.push_back(x[cnt]);
                if (!(cnt + 1 < n2) & cur_lmt - rep_val_cnt > 1) {
                  agn = 0;
                  break;
                } else {
                  cnt += 1;
                };
                rep_val_cnt += 1;
              } else {
                agn = 0;
                break;
              };
            };
          };
        };
        rep_val = 1;
      };
      if (rep_val == 0 || ref_rep_val == 0) {
        cur_found = 0;
      };
    } else {
      if (ref_rep_val == 0) {
        if (cur_found) {
          cur_found = 0;
        } else {
          cur_found = 1;
        };
        if (i + 3 < n) {
          if (searched[i] == '{' & searched[i + 1] == '0' & searched[i + 2] == '}') {
            i += 3;
          } else if (searched[i] == '{' & searched[i + 1] == '+' & searched[i + 2] == '0' & searched[i + 3] == '}') {
            i += 4;
          };
        } else if (i + 3 == n) {
          if (searched[i] == '{' & searched[i + 1] == '0' & searched[i + 2] == '}') {
            i += 3;
          };
        };
      } else if (i + 3 < n) {
        if (searched[i] == '{' & searched[i + 1] == '0' & searched[i + 2] == '}') {
          i += 3;
          rep_val = 0;
          if (cur_found) {
            cur_found = 0;
          } else {
            cur_found = 1;
          };
        } else if (searched[i] == '{' & searched[i + 1] == '+' & searched[i + 2] == '0' & searched[i + 3] == '}') {
          i += 4;
          rep_val = 0;
          if (cur_found) {
            cur_found = 0;
          } else {
            cur_found = 1;
          };
        };
      } else if (i + 3 == n) {
          if (searched[i] == '{' & searched[i + 1] == '0' & searched[i + 2] == '}') {
          i += 3;
          rep_val = 0;
          if (cur_found) {
            cur_found = 0;
          } else {
            cur_found = 1;
          };
        };
      };
    };
    if (or_state) {
      rep_val = 1;
      if (cur_found) {
        ref_cnt = cnt;
        or_found_alrd = 1;
        matched_str += cur_matched_str;
        i = bgn_i;
        if (cur_matched_str != "") {
          lst_cnt = cnt - 1;
        } else {
          lst_cnt = cnt;
        };
      } else {
        if (i == jump_i2) {
          if (!or_found_alrd) {
            return {{{0, 0}, {{0, ""}}}};
          } else {
            cur_found = 1;
            i = jump_i + 1;
            or_state = 0;
            greedy_state1 = 0;
            is_repetition = 0;
            ref_rep_val = 1;
          };
        } else {
          cnt = ref_cnt;
        };
      };
    } else if (!cur_found) {
      return {{{0, 0}, {{0, ""}}}};
    } else {
      matched_str += cur_matched_str;
      if (cur_matched_str != "") {
        lst_cnt = cnt - 1;
      } else {
        lst_cnt = cnt;
      };
      is_repetition = 0;
      rep_val = 1;
    };
  };
  rtn_str = matched_str;
  pre_cnt = lst_cnt - matched_str.length() + 1;
  return {{{pre_cnt, lst_cnt}, 
          {{cur_found, rtn_str}}}}; 
};

std::map<std::vector<unsigned int>, std::map<bool, std::string>> regex_findr1sub(std::string searched, std::string x) {
  char cur_chr;
  unsigned int i = 0;
  unsigned int cnt = 0;
  unsigned int ref_cnt;
  unsigned int bf_cnt2;
  unsigned int n = searched.length();
  const unsigned int n2 = x.length();
  bool agn;
  bool agn2;
  unsigned int ref_int1;
  unsigned int ref_int2;
  bool range_state;
  bool cur_found;
  unsigned int rep_val;
  unsigned int rep_val_cnt;
  unsigned int ref_rep_val = 1;
  unsigned int jump_i;
  unsigned int idx_cnt = 0;
  unsigned int cur_lmt;
  unsigned int ref_cur_lmt;
  unsigned int bf_rep_val;
  bool greedy_state1 = 0;
  bool greedy_state2 = 0;
  std::string cur_matched_str = "";
  unsigned int lst_cnt = -1;
  unsigned int pre_cnt;
  unsigned int cur_ref_cnt;
  unsigned int temp_i;
  bool is_repetition = 0;
  unsigned int cur_idx;
  unsigned int bf_cnt_zero = 0;
  if (searched[0] == '[') {
    cnt = 1;
    while (1) {
      if (searched[cnt] == ']' & searched[cnt - 1] != '\\') {
        break;
      };
      cnt += 1;
    };
    idx_cnt = cnt;
    cnt += 1;
    if (cnt < n) {
      if (searched[cnt] == '{') {
        is_repetition = 1;
        cnt += 1;
        if (searched[cnt] != '?') { 
          if (searched[cnt] == '+') {
            greedy_state1 = 1;
            cnt += 1;
          };
          ref_rep_val = int(searched[cnt]) - 48;
          cnt += 1;
          while (searched[cnt] != '}') {
            ref_rep_val *= 10;
            ref_rep_val += (int(searched[cnt]) - 48);
            cnt += 1;
          };
        };
        while (searched[idx_cnt] != '}') {
          searched.erase(searched.begin() + idx_cnt);
          n -= 1;
        };
      };
    };
    searched.erase(searched.begin() + idx_cnt);
    searched.erase(searched.begin());
    n -= 2;
  };
  cnt = 0;
  while (cnt < n2) {
    greedy_state2 = 0;
    if (searched[i] == '\\') {
      i += 1;
    };
    rep_val = 1;
    cur_found = 0;
    range_state = 0;
    ref_int1 = int(searched[i]);
    if (i + 1 < n) {
      if (searched[i + 1] == '-') {
        i += 2;
        if (!(i < n)) {
          return {{{0, 0}, {{0, ""}}}};
        };
        range_state = 1;
        ref_int2 = int(searched[i]);
        while (!cur_found & cnt < n2) {
          cur_found = (int(x[cnt]) >= ref_int1 & int(x[cnt]) <= ref_int2);
          cnt += 1;
        };
      } else {
        while (!cur_found & cnt < n2) {
          cur_found = (ref_int1 == int(x[cnt])); 
          cnt += 1;
        };
      };
    } else {
      while (!cur_found & cnt < n2) {
        cur_found = (ref_int1 == int(x[cnt])); 
        cnt += 1;
      };
    };
    bf_cnt2 = cnt;
    cur_matched_str = x[cnt - 1];
    i += 1;
    if (cur_found & i < n) {
      if (searched[i] != '\\') {
        if (searched[i] == '{') {
          is_repetition = 1;
          i += 1;
          if (searched[i] == '+') {
            greedy_state2 = 1;
            i += 1;
          };
          if (searched[i] != '}') {
            rep_val = int(searched[i]) - 48;
            i += 1;
            while (searched[i] != '}') {
              rep_val *= 10;
              rep_val += (int(searched[i]) - 48);
              i += 1;
            };
          } else {
            return {{{0, 0}, {{0, ""}}}};
          };
          i += 1;
        };
      } else {
        i += 1;
      };
      if (greedy_state2 & rep_val == 0) {
        rep_val = 1;
        if (ref_rep_val == 0) {
          ref_rep_val = 1;
        };
      };
      if (greedy_state1 & ref_rep_val == 0) {
        ref_rep_val = 1;
        if (rep_val == 0) {
          rep_val = 1;
        };
      };
      bf_rep_val = rep_val;
      if (range_state & is_repetition & rep_val != 0 & ref_rep_val != 0) {
        agn = 1;
        bf_rep_val = rep_val;
        rep_val *= ref_rep_val;
        rep_val -= 1;
        rep_val_cnt = 0;
        while (rep_val_cnt < rep_val) {
          agn2 = int(x[cnt]) >= ref_int1 & int(x[cnt]) <= ref_int2;
          if (agn2) {
            cur_matched_str.push_back(x[cnt]);
            if (!(cnt + 1 < n2) & rep_val - rep_val_cnt > 1) {
              agn = 0;
              break;
            } else {
              cnt += 1;
            };
            rep_val_cnt += 1;
          } else {
            agn = 0;
            break;
          };
        };
        if (!agn) {
          cur_found = 0;
        } else if (greedy_state1 || greedy_state2) {
          if (greedy_state1 & greedy_state2) {
            cur_lmt = bf_rep_val * ref_rep_val;
          } else if (greedy_state1) {
            cur_lmt = bf_rep_val;
          } else if (greedy_state2) {
            cur_lmt = ref_rep_val;
          };
          while (agn) {
            rep_val_cnt = 0;
            cur_ref_cnt = cnt;
            while (rep_val_cnt < cur_lmt) {
              agn2 = int(x[cnt]) >= ref_int1 & int(x[cnt]) <= ref_int2;
              if (agn2) {
                cur_matched_str.push_back(x[cnt]);
                if (!(cnt + 1 < n2) & cur_lmt - rep_val_cnt > 1) {
                  agn = 0;
                  break;
                } else {
                  cnt += 1;
                };
                rep_val_cnt += 1;
              } else {
                agn = 0;
                break;
              };
            };
          };
          cnt = cur_ref_cnt;
        };
        rep_val = 1;
      } else if (is_repetition & rep_val != 0 & ref_rep_val != 0) {
        agn = 1;
        bf_rep_val = rep_val;
        rep_val *= ref_rep_val;
        rep_val -= 1;
        rep_val_cnt = 0;
        while (rep_val_cnt < rep_val) {
          agn2 = int(x[cnt]) == ref_int1;
          if (agn2) {
            cur_matched_str.push_back(x[cnt]);
            if (!(cnt + 1 < n2) & rep_val - rep_val_cnt > 1) {
              agn = 0;
              break;
            } else {
              cnt += 1;
            };
            rep_val_cnt += 1;
          } else {
            agn = 0;
            break;
          };
        };
        if (!agn) {
          cur_found = 0;
        } else if (greedy_state1 || greedy_state2) {
          if (greedy_state1 & greedy_state2) {
            cur_lmt = bf_rep_val * ref_rep_val;
          } else if (greedy_state1) {
            cur_lmt = bf_rep_val;
          } else if (greedy_state2) {
            cur_lmt = ref_rep_val;
          };
          while (agn) {
            rep_val_cnt = 0;
            cur_ref_cnt = cnt;
            while (rep_val_cnt < cur_lmt) {
              agn2 = int(x[cnt]) == ref_int1;
              if (agn2) {
                cur_matched_str.push_back(x[cnt]);
                if (!(cnt + 1 < n2) & cur_lmt - rep_val_cnt > 1) {
                  agn = 0;
                  break;
                } else {
                  cnt += 1;
                };
                rep_val_cnt += 1;
              } else {
                agn = 0;
                break;
              };
            };
          };
          cnt = cur_ref_cnt;
        };
        rep_val = 1;
      };
    } else {
      if (ref_rep_val == 0) {
        if (cur_found) {
          cur_found = 0;
        } else {
          cur_found = 1;
        };
        if (i + 3 < n) {
          if (searched[i] == '{' & searched[i + 1] == '0' & searched[i + 2] == '}') {
            i += 3;
          } else if (searched[i] == '{' & searched[i + 1] == '+' & searched[i + 2] == '0' & searched[i + 3] == '}') {
            i += 4;
          };
        } else if (i + 3 == n) {
          if (searched[i] == '{' & searched[i + 1] == '0' & searched[i + 2] == '}') {
            i += 3;
          };
        };
      } else if (i + 3 < n) {
        if (searched[i] == '{' & searched[i + 1] == '0' & searched[i + 2] == '}') {
          rep_val = 0;
          if (cur_found) {
            cur_found = 0;
          } else {
            cur_found = 1;
          };
          i += 3;
        } else if (searched[i] == '{' & searched[i + 1] == '+' & searched[i + 2] == '0' & searched[i + 3] == '}') {
          if (cur_found) {
            cur_found = 0;
          } else {
            cur_found = 1;
          };
          i += 4;
        };
      } else if (i + 3 == n) {
        if (searched[i] == '{' & searched[i + 1] == '0' & searched[i + 2] == '}') {
          rep_val = 0;
          if (cur_found) {
            cur_found = 0;
          } else {
            cur_found = 1;
          };
          i += 3;
        };
      } else {
        if (cur_found) {
          idx_cnt = 1;
          if (!range_state) {
            while (cur_found & cnt < n2 & idx_cnt < ref_rep_val) {
              cur_found = (ref_int1 == int(x[cnt]));
              cur_matched_str.push_back(x[cnt]);
              cnt += 1;
              if (cur_found) {
                idx_cnt += 1;
              };
            };
            if (idx_cnt == ref_rep_val) {
              cur_found = 1;
            } else {
              cur_found = 0;
            };
            if (greedy_state1 & cur_found) {
              while (cnt < n2) {
                if (ref_int1 == int(x[cnt])) {
                  cur_matched_str.push_back(x[cnt]);
                } else {
                  break;
                };
                cnt += 1;
              };
            };
          } else {
            while (cur_found & cnt < n2 & idx_cnt < ref_rep_val) {
              cur_found = (int(x[cnt]) >= ref_int1 & int(x[cnt]) <= ref_int2);
              cur_matched_str.push_back(x[cnt]);
              cnt += 1;
              if (cur_found) {
                idx_cnt += 1;
              };
            };
            if (idx_cnt == ref_rep_val) {
              cur_found = 1;
            } else {
              cur_found = 0;
            };
            if (greedy_state1 & cur_found) {
              while (cnt < n2) {
                if (int(x[cnt]) >= ref_int1 & int(x[cnt]) <= ref_int2) {
                  cur_matched_str.push_back(x[cnt]);
                } else {
                  break;
                };
                cnt += 1;
              };
            };
          };
        };
      };
    };
    if (cnt < n2 & cur_found) {
      if (range_state) {
        agn2 = int(x[cnt]) >= ref_int1 & int(x[cnt]) <= ref_int2;
        if (agn2) {
          for (temp_i = 0; temp_i + 1 < cur_matched_str.length(); ++temp_i) {
            cur_matched_str[temp_i] = cur_matched_str[temp_i + 1];   
          };
          cur_matched_str[cur_matched_str.length() - 1] = x[cnt];
          cnt += 1;
          while (agn2 & cnt < n2) {
            agn2 = int(x[cnt]) >= ref_int1 & int(x[cnt]) <= ref_int2;
            if (agn2) {
              for (temp_i = 0; temp_i + 1 < cur_matched_str.length(); ++temp_i) {
                cur_matched_str[temp_i] = cur_matched_str[temp_i + 1];   
              };
              cur_matched_str[cur_matched_str.length() - 1] = x[cnt];
              cnt += 1;
            };
          };
        };
      } else {
        agn2 = int(x[cnt]) == ref_int1;
        if (agn2) {
          cnt += 1;
          while (agn2 & cnt < n2) {
            agn2 = int(x[cnt]) == ref_int1;
            if (agn2) {
              cnt += 1;
            };
          };
        };
      };
    };
    if (rep_val == 0 || ref_rep_val == 0) {
      if (bf_cnt_zero + 1 < bf_cnt2) {
        if (bf_cnt2 > 1) {
          if (bf_cnt2 < n2) {
            lst_cnt = bf_cnt2 - 2;
          } else {
            lst_cnt = bf_cnt2 - 1;
          };
          cur_matched_str = x[lst_cnt];
          pre_cnt = lst_cnt;
          cur_found = 1;
          break;
        };
      };
      bf_cnt_zero = cnt;
    };
    if (cur_found & rep_val != 0 & ref_rep_val != 0) {
      lst_cnt = cnt - 1;
      pre_cnt = cnt - cur_matched_str.length();
      break;
    };
    i = 0;
  };
  if (lst_cnt == -1) {
    return {{{0, 0}, {{0, ""}}}};
  };
  return {{{pre_cnt, lst_cnt}, 
          {{cur_found, cur_matched_str}}}}; 
};

int regex_findr_first_condition_idx(std::string searched) {
  const unsigned int n = searched.length();
  unsigned int cnt = 0;
  unsigned int cur_par;
  if (searched[cnt] == '[') {
    while (searched[cnt] != ']') {
      cnt += 1;
    };
    cnt += 1;
  } else {
    cnt += 1;
    if (cnt < n) {
      if (searched[cnt] == '-') {
        cnt += 2;
      };
    } else {
      return cnt;
    };
  };
  if (!(cnt < n)) {
    return cnt;
  } else if (searched[cnt] == '{') {
    cnt += 1;
    if (searched[cnt] == '?') {
      cnt += 1;
      cur_par = 1;
      while (1) {
        if (searched[cnt] == '}' & searched[cnt - 1] != '\\') {
          cur_par -= 1;
          if (cur_par == 0) {
            break;
          };
        } else if (searched[cnt] == '{' & searched[cnt - 1] != '\\') {
          cur_par += 1;
        };
        cnt += 1;
      };
    } else {
      while (searched[cnt] != '}') {
        cnt += 1;
      };
    };
    cnt += 1;
    return cnt;
  } else {
    return cnt;
  };
};
