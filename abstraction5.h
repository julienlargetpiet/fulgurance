#include "abstraction4.h"

std::string regex_subout(std::string &searched, std::string &replacer, std::string x) {
  std::map<std::vector<int>, std::map<bool, std::string>> out_mp = regex_match(searched, x);
  std::map<std::vector<int>, std::map<bool, std::string>>::iterator out_it = out_mp.begin();
  std::map<bool, std::string>::iterator rslt_it = out_it->second.begin();
  std::vector<int> idx_v;
  unsigned int pre_cnt;
  unsigned int post_cnt;
  if (rslt_it->first) {
    idx_v = out_it->first;
    pre_cnt = idx_v[0];
    post_cnt = idx_v[1];
    x.erase(x.begin() + pre_cnt, x.begin() + post_cnt + 1);
    for (unsigned int i = 0; i < replacer.length(); ++i) {
      x.insert(pre_cnt + i, 1, replacer[i]);
    };
  };
  return x;
};

std::string regex_subout_all(std::string &searched, std::string &replacer, std::string x) {
  std::map<std::vector<int>, std::map<bool, std::string>> out_mp;
  std::map<std::vector<int>, std::map<bool, std::string>>::iterator out_it;
  std::map<bool, std::string>::iterator rslt_it;
  std::vector<int> idx_v;
  unsigned int pre_cnt = 0;
  unsigned int post_cnt = 0;
  unsigned int cur_post_cnt;
  int cur_delta;
  const int n = replacer.length();
  std::string cur_x = x;
  std::string cur_str;
  while (1) {
    out_mp = regex_match(searched, cur_x);
    out_it = out_mp.begin();
    rslt_it = out_it->second.begin();
    if (rslt_it->first) {
      cur_str = rslt_it->second;
      idx_v = out_it->first;
      pre_cnt += idx_v[0];
      cur_post_cnt = idx_v[1];
      post_cnt += cur_post_cnt;
      x.erase(x.begin() + pre_cnt, x.begin() + post_cnt + 1);
      for (unsigned int i = 0; i < replacer.length(); ++i) {
        x.insert(pre_cnt + i, 1, replacer[i]);
      };
      cur_x.erase(cur_x.begin(), cur_x.begin() + cur_post_cnt + 1);
      if (cur_x.length() == 0) {
        break;
      };
      cur_delta = n - cur_str.length();
      post_cnt += (cur_delta + 1);
      pre_cnt = post_cnt;
    } else {
      break;
    };
  };
  return x;
};


void regex_subin(std::string &searched, std::string &replacer, std::string &x) {
  std::map<std::vector<int>, std::map<bool, std::string>> out_mp = regex_match(searched, x);
  std::map<std::vector<int>, std::map<bool, std::string>>::iterator out_it = out_mp.begin();
  std::map<bool, std::string>::iterator rslt_it = out_it->second.begin();
  std::vector<int> idx_v;
  unsigned int pre_cnt;
  unsigned int post_cnt;
  if (rslt_it->first) {
    idx_v = out_it->first;
    pre_cnt = idx_v[0];
    post_cnt = idx_v[1];
    x.erase(x.begin() + pre_cnt, x.begin() + post_cnt + 1);
    for (unsigned int i = 0; i < replacer.length(); ++i) {
      x.insert(pre_cnt + i, 1, replacer[i]);
    };
  };
};

void regex_subin_all(std::string &searched, std::string &replacer, std::string &x) {
  std::map<std::vector<int>, std::map<bool, std::string>> out_mp;
  std::map<std::vector<int>, std::map<bool, std::string>>::iterator out_it;
  std::map<bool, std::string>::iterator rslt_it;
  std::vector<int> idx_v;
  unsigned int pre_cnt = 0;
  unsigned int post_cnt = 0;
  unsigned int cur_post_cnt;
  int cur_delta;
  const int n = replacer.length();
  std::string cur_x = x;
  std::string cur_str;
  while (1) {
    out_mp = regex_match(searched, cur_x);
    out_it = out_mp.begin();
    rslt_it = out_it->second.begin();
    if (rslt_it->first) {
      cur_str = rslt_it->second;
      idx_v = out_it->first;
      pre_cnt += idx_v[0];
      cur_post_cnt = idx_v[1];
      post_cnt += cur_post_cnt;
      x.erase(x.begin() + pre_cnt, x.begin() + post_cnt + 1);
      for (unsigned int i = 0; i < replacer.length(); ++i) {
        x.insert(pre_cnt + i, 1, replacer[i]);
      };
      cur_x.erase(cur_x.begin(), cur_x.begin() + cur_post_cnt + 1);
      if (cur_x.length() == 0) {
        break;
      };
      cur_delta = n - cur_str.length();
      post_cnt += (cur_delta + 1);
      pre_cnt = post_cnt;
    } else {
      break;
    };
  };
};
