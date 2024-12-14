#include "fulgurance.h"
#include <string>
//#include <iomanip>

//template <typename T, typename T2> unsigned int closest_vidx(std::vector<T> &x, std::vector<T2> &val) {
//  unsigned int cnt = 0;
//  const unsigned int n = x.size();
//  for (auto I : val) {
//    double lst_diff = x[cnt] - I;
//    if (lst_diff < 0) {
//      lst_diff *= -1;
//    };
//    double cur_diff = x[1] - I;
//    if (cur_diff < 0) {
//      cur_diff *= -1;
//    };
//    while (cur_diff < lst_diff & cnt + 1 < n) {
//      lst_diff = cur_diff;
//      cnt += 1;
//      cur_diff = x[cnt] - I;
//      if (cur_diff < 0) {
//        cur_diff *= -1;
//      };
//    };
//  };
//  return cnt - 1;
//};


//template <typename T> std::vector<unsigned int> qbinom(std::vector<T> &val, unsigned int &n, double &p, double offset_prob = 0.001) {
//  std::vector<unsigned int> rtn_v;
//  rtn_v.reserve(val.size());
//  double mean = n * p;
//  double sd = n * p * (1 - p);
//  unsigned int cnt = mean;
//  if (mean - cnt > 0.5) {
//    cnt += 1;
//  };
//  unsigned int cnt2;
//  double cur_prob;
//  double divider = (sd * pow(2 * M_PI, 0.5));
//  for (auto i : val) {
//    cnt2 = cnt;
//    cur_prob = 0.5;
//    std::cout << "here\n";
//    if (i > 0.5) {
//      while (cur_prob <= i) {
//        cur_prob += (exp(-0.5 * (cnt2 / sd) * (cnt2 / sd))) / divider;
//        cnt2 += 1;
//        //std::cout << cur_prob << " Acnt2: " << cnt2 << "\n";
//      };
//      rtn_v.push_back(cnt2 - 1);
//    } else {
//      while (cur_prob >= i) {
//        cur_prob -= (exp(-0.5 * (cnt2 / sd) * (cnt2 / sd))) / divider;
//        cnt2 -= 1;
//        std::cout << cur_prob << " Bcnt2: " << cnt2 << "\n";
//      };
//      rtn_v.push_back(cnt2 + 1);
//    };
//  };
//  return rtn_v;
//};

//std::string itos(int x) {
//  double x2 = x;
//  int x3 = x2;
//  unsigned int cnt = 0;
//  std::string rtn_str = "";
//  while (x3 != 0) {
//    cnt += 1;
//    x2 /= 10;
//    x3 = x2;
//  };
//  for (unsigned int i = 0; i < cnt; ++i) {
//    x2 *= 10;
//    std::cout << x2 << "\n";
//    x3 = x2;
//    std::cout << "x3: " << x3 << "\n";
//    rtn_str += char(x3 + 48);
//    x2 -= x3;
//  };
//  return rtn_str;
//};

int main() {
  //std::vector<double> vec = {0.1, 0.2, 0.35, 0.5, 0.6, 0.9};
  //unsigned int n = 20;
  //double prob = 0.5;
  //std::vector<unsigned int> out2 = qbinom(vec, n, prob, 0.0001);
  //print_nvec(out2);
  int x = 458782; 
  std::string out;
  out = std::to_string(x);
  std::cout << out + "\n";
  out = itos(x);
  std::cout << out + "\n";
  for (int i = 0; i < 10000000; ++i) {
    //out = itos(x);
    out = std::to_string(x);
  };
  //std::cout << 44 % 10 << "\n";
  return 0;
}



