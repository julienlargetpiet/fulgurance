#include "abstraction.h"

std::map<std::vector<unsigned int>, std::map<bool, std::string>> regex_findrlow(std::string &searched, std::string &x) {
  std::map<std::vector<std::vector<unsigned int>>, std::vector<std::vector<std::string>>> out_mp = regex_findr_bgn_low(searched, x);
  std::map<std::vector<std::vector<unsigned int>>, std::vector<std::vector<std::string>>>::iterator out_it = out_mp.begin();
  std::vector<std::vector<unsigned int>> idx_hmn = out_it->first;
  std::vector<std::vector<std::string>> str_hmn = out_it->second;
  const unsigned int n_hmn = str_hmn.size();
  unsigned int n_hmn2;
  if (str_hmn.size() == 0) {
    return {{{0, 0}, {{0, ""}}}};
  };
  std::map<std::vector<unsigned int>, std::map<bool, std::string>> cur_mp;
  std::map<std::vector<unsigned int>, std::map<bool, std::string>>::iterator cur_it;
  std::map<bool, std::string>::iterator rslt_mp;
  std::string cur_searched = "";
  unsigned int rtn_pre_cnt;
  unsigned int rtn_lst_cnt;
  const unsigned int n = searched.length();
  const unsigned int n2 = x.length();
  unsigned int cnt  = regex_findr_first_condition_idx(searched);
  unsigned int cnt2;
  unsigned int cnt3;
  bool cur_found;
  std::string rtn_str;
  std::string cur_str;
  std::string cur_x;
  std::vector<unsigned int> idx_v;
  while (cnt < n) {
    cur_searched.push_back(searched[cnt]);
    cnt += 1;
  };
  if (cur_searched.length() > 0) {
    cnt = 0;
    while (cnt < n_hmn) {
      cnt2 = 0;
      n_hmn2 = idx_hmn[cnt].size();
      while (cnt2 < n_hmn2) {
        cur_x = "";
        rtn_lst_cnt = idx_hmn[cnt][cnt2];
        if (rtn_lst_cnt + 1 < n2) {
          rtn_str = str_hmn[cnt][cnt2];
          for (cnt3 = rtn_lst_cnt + 1; cnt3 < n2; ++cnt3) {
            cur_x.push_back(x[cnt3]);
          };
          cur_mp = regex_findr2sub(cur_searched, cur_x);
          cur_it = cur_mp.begin();
          rslt_mp = cur_it->second.begin();
          if (rslt_mp->first) {
            idx_v = cur_it->first;
            rtn_pre_cnt = rtn_lst_cnt - rtn_str.length() + 1;
            rtn_lst_cnt += idx_v[1];
            rtn_lst_cnt += 1;
            cur_str = rslt_mp->second;
            rtn_str += cur_str;
            return {{{rtn_pre_cnt, rtn_lst_cnt}, {{1, rtn_str}}}};
          };
          cnt2 += 1;
        } else {
          break;
        };
      };
      cnt += 1;
    };
    return {{{0, 0}, {{0, ""}}}};
  } else {
    rtn_lst_cnt = idx_hmn[0][0];
    rtn_str = str_hmn[0][0];
    rtn_pre_cnt = rtn_lst_cnt - rtn_str.length() + 1;
    return {{{rtn_pre_cnt, rtn_lst_cnt}, {{1, rtn_str}}}};
  };
};

std::map<std::vector<unsigned int>, std::vector<std::string>> regex_findrlow_all(std::string &searched, std::string &x) {
  std::map<std::vector<std::vector<unsigned int>>, std::vector<std::vector<std::string>>> out_mp = regex_findr_bgn_low(searched, x);
  std::map<std::vector<std::vector<unsigned int>>, std::vector<std::vector<std::string>>>::iterator out_it = out_mp.begin();
  std::vector<std::vector<unsigned int>> idx_hmn = out_it->first;
  std::vector<std::vector<std::string>> str_hmn = out_it->second;
  const unsigned int n_hmn = str_hmn.size();
  unsigned int n_hmn2;
  if (str_hmn.size() == 0) {
    return {{{0, 0}, {{0, ""}}}};
  };
  std::map<std::vector<unsigned int>, std::map<bool, std::string>> cur_mp;
  std::map<std::vector<unsigned int>, std::map<bool, std::string>>::iterator cur_it;
  std::map<bool, std::string>::iterator rslt_mp;
  std::string cur_searched = "";
  unsigned int rtn_lst_cnt;
  const unsigned int n = searched.length();
  const unsigned int n2 = x.length();
  unsigned int cnt  = regex_findr_first_condition_idx(searched);
  unsigned int cnt2;
  unsigned int cnt3;
  bool cur_found;
  std::string rtn_str;
  std::string cur_str;
  std::string cur_x;
  std::vector<unsigned int> idx_v;
  std::vector<unsigned int> rtn_idxv = {};
  std::vector<std::string> rtn_strv = {};
  while (cnt < n) {
    cur_searched.push_back(searched[cnt]);
    cnt += 1;
  };
  if (cur_searched.length() > 0) {
    cnt = 0;
    while (cnt < n_hmn) {
      cnt2 = 0;
      n_hmn2 = idx_hmn[cnt].size();
      while (cnt2 < n_hmn2) {
        cur_x = "";
        rtn_lst_cnt = idx_hmn[cnt][cnt2];
        if (rtn_lst_cnt + 1 < n2) {
          rtn_str = str_hmn[cnt][cnt2];
          for (cnt3 = rtn_lst_cnt + 1; cnt3 < n2; ++cnt3) {
            cur_x.push_back(x[cnt3]);
          };
          cur_mp = regex_findr2sub(cur_searched, cur_x);
          cur_it = cur_mp.begin();
          rslt_mp = cur_it->second.begin();
          if (rslt_mp->first) {
            idx_v = cur_it->first;
            rtn_lst_cnt += idx_v[1];
            rtn_lst_cnt += 1;
            cur_str = rslt_mp->second;
            rtn_str += cur_str;
            rtn_idxv.push_back(rtn_lst_cnt);
            rtn_strv.push_back(rtn_str);
          };
          cnt2 += 1;
        } else {
          break;
        };
      };
      cnt += 1;
    };
  } else {
    cnt = 0;
    while (cnt < n_hmn) {
      cnt2 = 0;
      n_hmn2 = idx_hmn[cnt].size();
      while (cnt2 < n_hmn2) {
        rtn_idxv.push_back(idx_hmn[cnt][cnt2]);
        rtn_strv.push_back(str_hmn[cnt][cnt2]);
        cnt2 += 1;
      };
      cnt += 1;
    };
  };
  return {{rtn_idxv, rtn_strv}};
};

