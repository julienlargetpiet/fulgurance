#include "fulgurance.h"

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
//@E std::vector<unsigned int> out = rbinom(n, size, p);
//@E print_nvec(out);
 //@E :0: 58 42 42 42 59 59 41 41 61 61 39 39 67 67 
 //@E 35 35 50 50 50 50 50 50 50 50
//@E :25: 50 50 50 50 50 50 50 50 50 50 50 50 50 50 
//@E 50 50 50 50 50 50 50 50 50 50
//@E :50: 50 50 50 50 50 50 50 50 50 50
//@E std::cout << Mean(out) << "\n";
//@E 49
//@E std::cout << Sd(out) << "\n";
//@E 5.90141
//@E std::cout << std::sqrt(size * p * (1 - p)) << "\n";
//@E 5
//@X

std::vector<unsigned int> rbinom(unsigned int &n, unsigned int size, double p) {
  std::vector<double> out = {};
  std::vector<unsigned int> rtn_v = {};
  unsigned int n_norm = 400;
  double mean = size * p;
  double sd = std::sqrt(size * p * (1 - p));
  double r_val;
  unsigned int r_idx;
  auto now = std::chrono::system_clock::now();
  auto duration = now.time_since_epoch();
  for (unsigned int i = 0; i < n; ++i) {
    out = rnorm(n_norm, mean, sd);
    now = std::chrono::system_clock::now();
    duration = now.time_since_epoch();
    r_idx = std::chrono::duration_cast<std::chrono::microseconds>(duration).count() % 400;
    if (r_idx % 9 == 0) {
      std::this_thread::sleep_for(std::chrono::microseconds(9));
    } else if (r_idx % 8 == 0) {
      std::this_thread::sleep_for(std::chrono::microseconds(8));
    } else if (r_idx % 6 == 0) {
      std::this_thread::sleep_for(std::chrono::microseconds(6));
    } else if (r_idx % 5 == 0) {
      std::this_thread::sleep_for(std::chrono::microseconds(5));
    } else if (r_idx % 3 == 0) {
      std::this_thread::sleep_for(std::chrono::microseconds(3));
    } else if (r_idx % 2 == 0) {
      std::this_thread::sleep_for(std::chrono::microseconds(2));
    } else {
      std::this_thread::sleep_for(std::chrono::microseconds(1));
    };
    r_val = out[r_idx];
    if (r_val < 0) {
      r_val *= -1;
    };
    r_val = round(r_val);
    rtn_v.push_back(r_val);
  };
  return rtn_v;
};

//@T rpois
//@U std::vector&lt;unsigned int&gt; rpois(unsigned int &n, unsigned int lambda)
//@D
//@A n : is the number of observations
//@A lambda : is the mean
//@X
//@E unsigned int lambda = 100;
//@E unsigned int n = 60;
//@E std::vector<unsigned int> out = rpois(n, lambda);
//@E print_nvec(out);
//@E  :0: 114 86  86  86  115 115 85  
//@E 85  85  116 116 84  84  119 119 
//@E 83  83  120 120 79  79  133 133 67
//@E :25: 100 100 100 100 100 100 100 
//@E 100 100 100 100 100 100 100 100 100 
//@E 100 100 100 100 100 100 100 100
//@E :50: 101 101 101 101 101 101 101 101 
//@E 101 101
//@E std::cout << Mean(out) << "\n";
//@E 99
//@E std::cout << Sd(out) << "\n";
//@E 13.0799
//@E std::cout << std::sqrt(lambda) << "\n";
//@E 10
//@X

std::vector<unsigned int> rpois(unsigned int &n, unsigned int lambda) {
  std::vector<double> out = {};
  std::vector<unsigned int> rtn_v = {};
  unsigned int n_norm = 400;
  double sd = std::sqrt(lambda);
  double r_val;
  unsigned int r_idx;
  auto now = std::chrono::system_clock::now();
  auto duration = now.time_since_epoch();
  double mean = lambda;
  for (unsigned int i = 0; i < n; ++i) {
    out = rnorm(n_norm, mean, sd);
    now = std::chrono::system_clock::now();
    duration = now.time_since_epoch();
    r_idx = std::chrono::duration_cast<std::chrono::microseconds>(duration).count() % 400;
    if (r_idx % 9 == 0) {
      std::this_thread::sleep_for(std::chrono::microseconds(9));
    } else if (r_idx % 8 == 0) {
      std::this_thread::sleep_for(std::chrono::microseconds(8));
    } else if (r_idx % 6 == 0) {
      std::this_thread::sleep_for(std::chrono::microseconds(6));
    } else if (r_idx % 5 == 0) {
      std::this_thread::sleep_for(std::chrono::microseconds(5));
    } else if (r_idx % 3 == 0) {
      std::this_thread::sleep_for(std::chrono::microseconds(3));
    } else if (r_idx % 2 == 0) {
      std::this_thread::sleep_for(std::chrono::microseconds(2));
    } else {
      std::this_thread::sleep_for(std::chrono::microseconds(1));
    };
    r_val = out[r_idx];
    if (r_val < 0) {
      r_val *= -1;
    };
    r_val = round(r_val);
    rtn_v.push_back(r_val);
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
//@E std::vector<double> out = rexp(n, rate);
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
//@E std::cout << Mean(out) << "\n";
//@E 5.94307
//@E std::cout << Sd(out) << "\n";
//@E 4.29426
//@X

std::vector<double> rexp(unsigned int &n, double rate) {
  std::vector<double> out = {};
  std::vector<double> rtn_v = {};
  unsigned int n_norm = 400;
  double mean = 1 / rate;
  double sd = std::sqrt(1 / std::pow(rate, 2));
  double r_val;
  unsigned int r_idx;
  auto now = std::chrono::system_clock::now();
  auto duration = now.time_since_epoch();
  for (unsigned int i = 0; i < n; ++i) {
    out = rnorm(n_norm, mean, sd);
    now = std::chrono::system_clock::now();
    duration = now.time_since_epoch();
    r_idx = std::chrono::duration_cast<std::chrono::microseconds>(duration).count() % 400;
    if (r_idx % 9 == 0) {
      std::this_thread::sleep_for(std::chrono::microseconds(9));
    } else if (r_idx % 8 == 0) {
      std::this_thread::sleep_for(std::chrono::microseconds(8));
    } else if (r_idx % 6 == 0) {
      std::this_thread::sleep_for(std::chrono::microseconds(6));
    } else if (r_idx % 5 == 0) {
      std::this_thread::sleep_for(std::chrono::microseconds(5));
    } else if (r_idx % 3 == 0) {
      std::this_thread::sleep_for(std::chrono::microseconds(3));
    } else if (r_idx % 2 == 0) {
      std::this_thread::sleep_for(std::chrono::microseconds(2));
    } else {
      std::this_thread::sleep_for(std::chrono::microseconds(1));
    };
    r_val = out[r_idx];
    if (r_val < 0) {
      r_val *= -1;
    };
    rtn_v.push_back(r_val);
  };
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

bool test_chisq_fit(std::vector<double> theoretical, std::vector<double> observed, double a_value = 0.05, double step = 0.05) {
  double degf = observed.size() - 1;
  double delta = 0;
  std::vector<double> cur_proba = {1 - a_value};
  std::vector<double> ref_v = qchisq(cur_proba, degf, step);
  double ref_val = ref_v[0];
  for (unsigned int i = 0; i < degf + 1; ++i) {
    delta += pow((theoretical[i] - observed[i]), 2) / theoretical[i];
  };
  if (delta < ref_val) {
    return 1;
  } else {
    return 0;
  };
};

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

bool test_chisq_independance(std::vector<std::vector<double>> &matr, double a_value = 0.05, double step = 0.05) {
  std::vector<double> sum_col = {};
  std::vector<double> sum_row = {};
  double n = 0;
  const unsigned int n_col = matr.size();
  const unsigned int n_row = matr[0].size();
  sum_col.resize(n_col, 0);
  sum_row.reserve(n_row);
  unsigned int i = 0;
  unsigned int i2 = 0;
  double cur_sum;
  double cur_val;
  std::vector<double> ref_probv = {};
  double ref_prob;
  double degf = (n_row - 1) * (n_col - 1);
  std::vector<double> delta = {0, 0};
  for (i = 0; i < n_row; ++i) {
    cur_sum = 0;
    for (i2 = 0; i2 < n_col; ++i2) {
      cur_val = matr[i2][i];
      sum_col[i2] += cur_val;
      cur_sum += cur_val;
    };
    n += cur_sum;
    sum_row.push_back(cur_sum);
  };
  for (i = 0; i < n_row; ++i) {
    for (i2 = 0; i2 < n_col; ++i2) {
      cur_val = sum_row[i] * sum_col[i2] / n;
      delta[1] += std::pow(matr[i2][i] - cur_val, 2) / cur_val;
    };
  };
  ref_probv = pchisq(delta, degf);
  ref_prob = 1 - ref_probv[1];
  if (ref_prob < a_value) {
    return 1;
  } else {
    return 0;
  };
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

std::vector<unsigned int> rgeom(unsigned int &n, double &p) {
  std::vector<double> out = {};
  std::vector<unsigned int> rtn_v = {};
  unsigned int n_norm = 400;
  double mean = 1 / p;
  double sd = std::sqrt(1 / std::pow(p, 2));
  double r_val;
  unsigned int r_idx;
  auto now = std::chrono::system_clock::now();
  auto duration = now.time_since_epoch();
  for (unsigned int i = 0; i < n; ++i) {
    out = rnorm(n_norm, mean, sd);
    now = std::chrono::system_clock::now();
    duration = now.time_since_epoch();
    r_idx = std::chrono::duration_cast<std::chrono::microseconds>(duration).count() % 400;
    if (r_idx % 9 == 0) {
      std::this_thread::sleep_for(std::chrono::microseconds(9));
    } else if (r_idx % 8 == 0) {
      std::this_thread::sleep_for(std::chrono::microseconds(8));
    } else if (r_idx % 6 == 0) {
      std::this_thread::sleep_for(std::chrono::microseconds(6));
    } else if (r_idx % 5 == 0) {
      std::this_thread::sleep_for(std::chrono::microseconds(5));
    } else if (r_idx % 3 == 0) {
      std::this_thread::sleep_for(std::chrono::microseconds(3));
    } else if (r_idx % 2 == 0) {
      std::this_thread::sleep_for(std::chrono::microseconds(2));
    } else {
      std::this_thread::sleep_for(std::chrono::microseconds(1));
    };
    r_val = out[r_idx];
    if (r_val < 0) {
      r_val *= -1;
    };
    rtn_v.push_back(std::round(r_val));
  };
  return rtn_v;
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

std::vector<bool> bool_gen(unsigned int &k, unsigned int &n, double seed = 0) {
  std::vector<unsigned int> cur_idx = {};
  std::vector<unsigned int> max_idx = {};
  std::vector<bool> cur_v = {};
  std::vector<bool> ref_v = {};
  unsigned int i = 0;
  const unsigned int ref_k = k - 1;
  int idx = ref_k;
  unsigned int idx_val;
  double cnt = 0;
  auto now = std::chrono::system_clock::now();
  auto duration = now.time_since_epoch();
  double ref_comb_val = Comb(k, n);
  if (seed == 0) {
    seed = std::chrono::duration_cast<std::chrono::microseconds>(duration).count() % (int)ref_comb_val;
    seed += 1;
  } else {
    seed = (int)seed % (int)ref_comb_val;
  };
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
  while (1) {
    while (cur_idx[ref_k] != n) {
      cur_v = ref_v;
      for (i = 0; i < k; ++i) {
        cur_v[cur_idx[i]] = 1;
      };
      cnt += 1;
      if (cnt >= seed) {
        return cur_v;
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
};

//@T regex_findr
//@U std::map&lt;std::vector&lt;unsigned int&gt;, std::map&lt;bool, std::string&gt;&gt; regex_findr(std::string &searched, std::string &x)
//@X
//@D A minimalist RegEx flavor.
//@D - <strong>or context</strong> which is the set of elements that are inside <code>[]</code>, evaluates the expression from left to right 
//@D - <strong>range elements</strong> matches every elements that are between <code>x-y</code> acording to the ASCII table
//@D - <strong>repetition</strong> is the number of times a set of elements have to be matched, this is declared inside <code>{n}</code> after the set of elements
//@D - <strong>greedyness</strong> allows to match a given number of times a set of elements or more, this is declared by <code>{+n}</code> after the set of elements
//@D - <code>\\</code> is used to escape special characters, apart when it is in a range context, so <code>\\-x</code> or <code>x-\\</code> are valid
//@A searched : is the RegEx expression
//@A x : is the input std::string
//@X
//@E
//@E std::string inpt_str = "uouuupeieeeppppiimi";
//@E std::string searched = "[u{1}p{2}]{2}ii[a-em]";
//@E std::map<std::vector<unsigned int>, std::map<bool, std::string>> outmp = regex_findr(searched, inpt_str);
//@E std::map<std::vector<unsigned int>, std::map<bool, std::string>>::iterator it = outmp.begin();
//@E std::vector<unsigned int> vec1 = it->first;
//@E std::map<bool, std::string>::iterator it2b = it->second.begin();
//@E std::cout << vec1[0] << "\n";
//@E std::cout << vec1[1] << "\n";
//@E std::cout << it2b->first << "\n";
//@E std::cout << it2b->second << "\n";
//@E 
//@E 11
//@E 17
//@E 1
//@E ppppiim
//@E 
//@E std::string inpt_str = "uouuupeieeeppppiimi";
//@E std::string searched = "[u{1}p{2}]{+1}ii[a-em]";
//@E std::map<std::vector<unsigned int>, std::map<bool, std::string>> outmp = regex_findr(searched, inpt_str);
//@E std::map<std::vector<unsigned int>, std::map<bool, std::string>>::iterator it = outmp.begin();
//@E std::vector<unsigned int> vec1 = it->first;
//@E std::map<bool, std::string>::iterator it2b = it->second.begin();
//@E std::cout << vec1[0] << "\n";
//@E std::cout << vec1[1] << "\n";
//@E std::cout << it2b->first << "\n";
//@E std::cout << it2b->second << "\n";
//@E 
//@E 11
//@E 17
//@E 1
//@E ppppiim
//@E 
//@E std::string inpt_str = "uouuupeieeeppppiimi";
//@E std::string searched = "e{+1}p{2}";
//@E std::map<std::vector<unsigned int>, std::map<bool, std::string>> outmp = regex_findr(searched, inpt_str);
//@E std::map<std::vector<unsigned int>, std::map<bool, std::string>>::iterator it = outmp.begin();
//@E std::vector<unsigned int> vec1 = it->first;
//@E std::map<bool, std::string>::iterator it2b = it->second.begin();
//@E std::cout << vec1[0] << "\n";
//@E std::cout << vec1[1] << "\n";
//@E std::cout << it2b->first << "\n";
//@E std::cout << it2b->second << "\n";
//@E 
//@E 8
//@E 12
//@E 1
//@E eeepp
//@E 
//@E std::string inpt_str = "uouuupeieeeppppiimi";
//@E std::string searched = "[a-ia-z]{+1}";
//@E std::map<std::vector<unsigned int>, std::map<bool, std::string>> outmp = regex_findr(searched, inpt_str);
//@E std::map<std::vector<unsigned int>, std::map<bool, std::string>>::iterator it = outmp.begin();
//@E std::vector<unsigned int> vec1 = it->first;
//@E std::map<bool, std::string>::iterator it2b = it->second.begin();
//@E std::cout << vec1[0] << "\n";
//@E std::cout << vec1[1] << "\n";
//@E std::cout << it2b->first << "\n";
//@E std::cout << it2b->second << "\n";
//@E 
//@E 6
//@E 10
//@E 1
//@E eieee
//@E
//@X

std::map<std::vector<unsigned int>, std::map<bool, std::string>> regex_findr(std::string &searched, std::string &x) {
  char cur_chr;
  unsigned int i = 0;
  unsigned int cnt = 0;
  unsigned int pre_cnt2;
  unsigned int ref_cnt;
  unsigned int ref_i;
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
  unsigned int jump_i3;
  unsigned int idx_cnt = 0;
  unsigned int cur_lmt;
  unsigned int ref_cur_lmt;
  unsigned int bf_rep_val;
  bool greedy_state1 = 0;
  bool greedy_state2 = 0;
  std::vector<unsigned int> multiple_cnt = {};
  std::vector<unsigned int> ref_multiple_cnt = {};
  std::string cur_matched_str = "";
  std::vector<std::string> matched_str;
  std::vector<std::string> pre_matched_str;
  std::string rtn_str;
  unsigned int lst_cnt;
  unsigned int pre_cnt;
  unsigned int cur_ref_cnt;
  unsigned int cur_ref_i;
  unsigned int temp_i;
  bool is_repetition = 0;
  std::vector<unsigned int> sorted_v;
  unsigned int cur_idx;
  unsigned int bf_cnt_zero = 0;
  while (cnt < n2) {
    greedy_state2 = 0;
    if (searched[i] == '\\') {
      i += 1;
    } else {
      if (searched[i] == '[') {
        or_state = 1;
        i += 1;
        jump_i = i;
        while (searched[jump_i] != ']' & searched[jump_i - 1] != '\\') {
          jump_i += 1;
        };
        jump_i2 = jump_i;
        if (jump_i + 2 < n) {
          if (searched[jump_i + 1] == '{') {
            is_repetition = 1;
            rep_val = 1;
            jump_i += 2;
            if (jump_i + 1 < n) {
              if (searched[jump_i] == '+') {
                greedy_state1 = 1;
                jump_i += 1;
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
            } else {
              return {{{0, 0}, {{0, ""}}}};
            };
          };
        };
      };
    };
    rep_val = 1;
    cur_ref_i = i;
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
      };
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
            cur_lmt = bf_rep_val + ref_rep_val;
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
            cur_lmt = bf_rep_val + ref_rep_val;
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
      pre_cnt2 = cnt;
    } else {
      if (ref_rep_val == 0) {
        if (cur_found) {
          cur_found = 0;
        } else {
          cur_found = 1;
          pre_cnt2 = cnt;
          cur_matched_str = ""; 
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
            cur_matched_str = ""; 
            pre_cnt2 = cnt;
          };
          i += 3;
        } else if (searched[i] == '{' & searched[i + 1] == '+' & searched[i + 2] == '0' & searched[i + 3] == '}') {
          rep_val = 0;
          if (cur_found) {
            cur_found = 0;
          } else {
            cur_found = 1;
            pre_cnt2 = cnt;
            cur_matched_str = ""; 
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
            pre_cnt2 = cnt;
            cur_matched_str = ""; 
          };
          i += 3;
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
      if (bf_cnt_zero + 1 < pre_cnt2) {
        cur_found = 1;
        ref_i = i;
        while (bf_cnt_zero + 1 < pre_cnt2) {
          matched_str.push_back("");
          multiple_cnt.push_back(bf_cnt_zero);
          bf_cnt_zero += 1;
        };
        if (pre_cnt2 == n2 & x[n2 - 1] != ref_int1) {
          matched_str.push_back("");
          multiple_cnt.push_back(bf_cnt_zero);
        };
        if (or_state) {
          ref_i = jump_i + 1;
        };
      };
      bf_cnt_zero = cnt;
    };
    if (or_state) {
      rep_val = 1;
      if (cur_found & rep_val != 0 & ref_rep_val != 0) {
        multiple_cnt.push_back(cnt);
        matched_str.push_back(cur_matched_str);
        ref_i = jump_i + 1;
      };
      if (cnt == n2) {
        if (i < jump_i2) {
          cnt = 0;
          bf_cnt_zero = 0;
        } else {
          or_state = 0;
          greedy_state1 = 0;
          break;
        };
      } else {
        i = cur_ref_i; 
      };
    } else if (cur_found & rep_val != 0 & ref_rep_val != 0) {
      multiple_cnt.push_back(cnt);
      matched_str.push_back(cur_matched_str);
      ref_i = i;
      is_repetition = 0;
      rep_val = 1;
      i = 0;
    } else {
      i = 0;
    };
  };
  cur_matched_str = "";
  const unsigned int n_cnt = multiple_cnt.size();
  if (n_cnt == 0) {
    return {{{0, 0}, {{0, ""}}}};
  };
  i = ref_i;
  sorted_v = sort_ascout(multiple_cnt);
  for (temp_i = 0; temp_i < n_cnt; ++temp_i) {
    cur_idx = match(multiple_cnt, sorted_v[temp_i]);
    pre_matched_str.push_back(matched_str[cur_idx]);
  };
  multiple_cnt = sorted_v;
  cnt = multiple_cnt[0];
  if (cnt == n2) {
    temp_i = ref_i;
    while (temp_i < n) {
      if (searched[temp_i] != '\\') {
        temp_i += 1;
        if (searched[temp_i] == '{') {
          temp_i += 1;
          if (searched[temp_i] != '0') {
            return {{{{0, 0}}, {{0, ""}}}};
          };
        } else if (searched[temp_i] == '^') {
          temp_i += 1;
          if (temp_i + 2 < n) {
            if (searched[temp_i + 1] == '-') {
              temp_i += 2;
              if (searched[temp_i] != '~' & searched[temp_i - 2] != ' ') {
                return {{{{0, 0}}, {{0, ""}}}};
              } else if (searched[temp_i] != ' ' & searched[temp_i - 2] != '~') {
                return {{{{0, 0}}, {{0, ""}}}};
              };
            } else {
              return {{{{0, 0}}, {{0, ""}}}};
            };
          } else {
            return {{{{0, 0}}, {{0, ""}}}};
          };
        } else {
          return {{{{0, 0}}, {{0, ""}}}};
        };
      };
      temp_i += 1;
    };
    pre_cnt = cnt - matched_str[0].length();
    lst_cnt = cnt - 1;
    return {{{{pre_cnt, lst_cnt}}, {{1, matched_str[0]}}}};
  };
  if (pre_matched_str[0] != "") {
    lst_cnt = multiple_cnt[0] - 1;
  } else {
    lst_cnt = multiple_cnt[0];
  };
  matched_str = pre_matched_str;
  ref_rep_val = 1;
  is_repetition = 0;
  greedy_state1 = 0;
  while (i < n & cnt < n2) {
    greedy_state2 = 0;
    if (searched[i] == '\\') {
      i += 1;
    } else {
      if (searched[i] == '[') {
        ref_cnt = cnt;
        or_state = 1;
        i += 1;
        jump_i = i;
        while (searched[jump_i] != ']' & searched[jump_i - 1] != '\\') {
          jump_i += 1;
        };
        jump_i2 = jump_i;
        if (jump_i + 2 < n) {
          if (searched[jump_i + 1] == '{') {
            is_repetition = 1;
            rep_val = 1;
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
      };
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
            cur_lmt = bf_rep_val + ref_rep_val;
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
            cur_lmt = bf_rep_val + ref_rep_val;
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
        cur_matched_str = "";
      };
    } else {
      if (ref_rep_val == 0) {
        if (cur_found) {
          cur_found = 0;
        } else {
          cur_found = 1;
          cur_matched_str = "";
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
            cur_matched_str = "";
          };
        } else if (searched[i] == '{' & searched[i + 1] == '+' & searched[i + 2] == '0' & searched[i + 3] == '}') {
          i += 4;
          rep_val = 0;
          if (cur_found) {
            cur_found = 0;
          } else {
            cur_found = 1;
            cur_matched_str = "";
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
            cur_matched_str = "";
          };
        };
      };
    };
    if (rep_val == 0 || ref_rep_val == 0) {
      cnt -= 1;
    };
    if (or_state) {
      rep_val = 1;
      if (cur_found) {
        matched_str[idx_cnt] += cur_matched_str;
        i = jump_i + 1;
        lst_cnt = cnt - 1;
        or_state = 0;
        greedy_state1 = 0;
        is_repetition = 0;
        ref_rep_val = 1;
      } else {
        if (i == jump_i2) {
          if (idx_cnt + 1 < n_cnt) {
            idx_cnt += 1;
            cnt = multiple_cnt[idx_cnt];
            i = ref_i;
            or_state = 0;
            greedy_state1 = 0;
            ref_rep_val = 1;
            is_repetition = 0;
          } else {
            return {{{0, 0}, {{0, ""}}}};
          };
        } else {
          cnt = ref_cnt;
        };
      };
    } else if (!cur_found) {
      if (idx_cnt + 1 < n_cnt) {
        idx_cnt += 1;
        is_repetition = 0;
        greedy_state1 = 0;
        ref_rep_val = 1;
        cnt = multiple_cnt[idx_cnt];
        i = ref_i;
      } else {
        return {{{0, 0}, {{0, ""}}}};
      };
    } else {
      matched_str[idx_cnt] += cur_matched_str;
      lst_cnt = cnt - 1;
      is_repetition = 0;
      rep_val = 1;
    };
  };
  rtn_str = matched_str[idx_cnt];
  pre_cnt = multiple_cnt[idx_cnt] - pre_matched_str[idx_cnt].length();
  return {{{pre_cnt, lst_cnt}, 
          {{cur_found, rtn_str}}}}; 
};




std::map<std::vector<std::vector<unsigned int>>, std::vector<std::vector<std::string>>> regex_findr_bgn_low(std::string &searched, std::string &x) {
  std::vector<unsigned int> conditions_idxv = {};
  const unsigned int n = searched.length();
  const unsigned int n2 = x.length();
  unsigned int cnt = 0;
  unsigned int cnt2 = 0;
  unsigned int rtn_lst_cnt;
  unsigned int ref_rep_val;
  bool is_ref = 0;
  bool is_greedy1 = 0;
  std::string cur_searched = "";
  std::string cur_str;
  std::string cur_x = x;
  std::vector<std::vector<unsigned int>> idx_hmn;
  std::vector<std::vector<std::string>> str_hmn;
  std::map<std::vector<unsigned int>, std::map<bool, std::string>> cur_mp;
  std::map<std::vector<unsigned int>, std::map<bool, std::string>>::iterator cur_it;
  std::map<bool, std::string>::iterator rslt_mp;
  std::vector<unsigned int> idx_v;
  std::vector<unsigned int> cur_idx_hmn;
  std::vector<std::string> cur_str_hmn;
  if (searched[0] == '[') {
    cnt = 1;
    while (1) {
      conditions_idxv.push_back(cnt);
      if (searched[cnt] == ']' & searched[cnt - 1] != '\\') {
        break;
      };
      if (searched[cnt + 1] == '-' & searched[cnt] != '\\') {
        cnt += 2;
      };
      if (searched[cnt + 1] == '{') {
        cnt += 1;
        while (searched[cnt] != '}') {
          cnt += 1;
        };
      };
      cnt += 1;
    };
    if (cnt + 1 < n) {
      cnt += 1;
      if (searched[cnt] == '{') {
        is_ref = 1;
        cnt += 1;
        if (searched[cnt] == '+') {
          cnt += 1;
          is_greedy1 = 1;
        };
        ref_rep_val = int(searched[cnt]) - 48;
        cnt += 1;
        while (searched[cnt] != '}') {
          ref_rep_val *= 10;
          ref_rep_val += (int(searched[cnt]) - 48);
          cnt += 1;
        };
      };
    };
    for (cnt = 0; cnt < conditions_idxv.size() - 1; ++cnt) {
      cur_searched = "";
      cur_x = x;
      for (cnt2 = conditions_idxv[cnt]; cnt2 < conditions_idxv[cnt + 1]; ++cnt2) {
        cur_searched.push_back(searched[cnt2]);
      };
      if (is_ref) {
        cur_searched.insert(0, 1, '[');
        cur_searched.push_back(']');
        cur_searched.push_back('{');
        if (is_greedy1) {
          cur_searched.push_back('+');
        };
        cur_searched += std::to_string(ref_rep_val);
        cur_searched.push_back('}');
      };
      cur_mp = regex_findr1sub(cur_searched, cur_x);
      cur_it = cur_mp.begin();
      rslt_mp = cur_it->second.begin();
      cur_idx_hmn = {};
      cur_str_hmn = {};
      if (rslt_mp->first) {
        idx_v = cur_it->first;
        rtn_lst_cnt = idx_v[1];
        cur_str = rslt_mp->second;
        cur_str_hmn.push_back(cur_str);
        cur_idx_hmn.push_back(rtn_lst_cnt);
        cur_x = "";
        for (cnt2 = rtn_lst_cnt + 1; cnt2 < n2; ++cnt2) {
          cur_x.push_back(x[cnt2]);
        };
        while (1) {
          cur_mp = regex_findr1sub(cur_searched, cur_x);
          cur_it = cur_mp.begin();
          rslt_mp = cur_it->second.begin();
          if (rslt_mp->first) {
            idx_v = cur_it->first;
            rtn_lst_cnt += idx_v[1];
            cur_str = rslt_mp->second;
            cur_str_hmn.push_back(cur_str);
            rtn_lst_cnt += 1;
            cur_idx_hmn.push_back(rtn_lst_cnt);
            cur_x = "";
            for (cnt2 = rtn_lst_cnt + 1; cnt2 < n2; ++cnt2) {
              cur_x.push_back(x[cnt2]);
            };
          } else {
            break;
          };
        };
      idx_hmn.push_back(cur_idx_hmn);
      str_hmn.push_back(cur_str_hmn);
      };
    };
  } else {
    cur_searched.push_back(searched[0]);
    if (n > 2) {
      cnt += 1;
      if (searched[cnt] == '-') {
        cur_searched.push_back(searched[1]);
        cur_searched.push_back(searched[2]);
        cnt += 2;
      };
      if (searched[cnt] == '{') {
        cur_searched.push_back('{');
        cnt += 1;
        while (searched[cnt] != '}') {
          cur_searched.push_back(searched[cnt]);
          cnt += 1;
        };
        cur_searched.push_back('}');
      };
    };
    cur_mp = regex_findr1sub(cur_searched, cur_x);
    cur_it = cur_mp.begin();
    rslt_mp = cur_it->second.begin();
    cur_idx_hmn = {};
    cur_str_hmn = {};
    if (rslt_mp->first) {
      idx_v = cur_it->first;
      rtn_lst_cnt = idx_v[1];
      cur_str = rslt_mp->second;
      cur_str_hmn.push_back(cur_str);
      cur_idx_hmn.push_back(rtn_lst_cnt);
      cur_x = "";
      for (cnt2 = rtn_lst_cnt + 1; cnt2 < n2; ++cnt2) {
        cur_x.push_back(x[cnt2]);
      };
      while (1) {
        cur_mp = regex_findr1sub(cur_searched, cur_x);
        cur_it = cur_mp.begin();
        rslt_mp = cur_it->second.begin();
        if (rslt_mp->first) {
          idx_v = cur_it->first;
          rtn_lst_cnt += idx_v[1];
          rtn_lst_cnt += 1;
          cur_str = rslt_mp->second;
          cur_str_hmn.push_back(cur_str);
          cur_idx_hmn.push_back(rtn_lst_cnt);
          cur_x = "";
          for (cnt2 = rtn_lst_cnt + 1; cnt2 < n2; ++cnt2) {
            cur_x.push_back(x[cnt2]);
          };
        } else {
          break;
        };
      };
      idx_hmn.push_back(cur_idx_hmn);
      str_hmn.push_back(cur_str_hmn);
    };
  };  
  return {{idx_hmn, str_hmn}};
};
