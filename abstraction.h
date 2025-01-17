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
  std::vector<double> out;
  std::vector<unsigned int> rtn_v;
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
  std::vector<double> out;
  std::vector<unsigned int> rtn_v;
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
  std::vector<double> out;
  std::vector<double> rtn_v;
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
  std::vector<double> sum_col;
  std::vector<double> sum_row;
  double n = 0;
  const unsigned int n_col = matr.size();
  const unsigned int n_row = matr[0].size();
  sum_col.resize(n_col, 0);
  sum_row.reserve(n_row);
  unsigned int i = 0;
  unsigned int i2 = 0;
  double cur_sum;
  double cur_val;
  std::vector<double> ref_probv;
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
  std::vector<double> out;
  std::vector<unsigned int> rtn_v;
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







