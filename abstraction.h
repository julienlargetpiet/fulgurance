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
  unsigned int n_norm = 60;
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
    r_idx = std::chrono::duration_cast<std::chrono::milliseconds>(duration).count() % 60;
    if (r_idx % 2 == 0) {
      usleep(r_idx * 10);
    } else {
      usleep(r_idx * 5);
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
  unsigned int n_norm = 60;
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
    r_idx = std::chrono::duration_cast<std::chrono::milliseconds>(duration).count() % 60;
    if (r_idx % 2 == 0) {
      usleep(r_idx * 10);
    } else {
      usleep(r_idx * 5);
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
    r_idx = std::chrono::duration_cast<std::chrono::milliseconds>(duration).count() % 400;
    if (r_idx % 9 == 0) {
      usleep(9);
    } else if (r_idx % 8 == 0) {
      usleep(8);
    } else if (r_idx % 6 == 0) {
      usleep(6);
    } else if (r_idx % 5 == 0) {
      usleep(5);
    } else if (r_idx % 3 == 0) {
      usleep(3);
    } else if (r_idx % 2 == 0) {
      usleep(2);
    } else {
      usleep(1);
    };
    r_val = out[r_idx];
    if (r_val < 0) {
      r_val *= -1;
    };
    rtn_v.push_back(r_val);
  };
  return rtn_v;
};





















