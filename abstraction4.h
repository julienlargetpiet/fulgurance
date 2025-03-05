#include "abstraction3.h"


std::map<std::vector<int>, std::map<bool, std::string>> regex_search(std::string &searched, std::string &x) {
  std::string cur_searched = "";
  std::string cur_x = x;
  std::string cur_x_ref;
  std::string rtn_str;
  std::string cur_str;
  std::string cur_break_ptrn = "";
  std::string cur_rslt;
  bool ok_next;
  bool is_mult;
  bool is_greedy1;
  bool alrd_or_found;
  bool cur_found;
  unsigned int idx_condition;
  unsigned int cnt = 0;
  unsigned int temp_cnt;
  unsigned int bf_or_cnt;
  unsigned int jump_cnt;
  unsigned int ref_mult;
  int rtn_lst_cnt = -1;
  unsigned int rtn_pre_cnt;
  bool agn = 1;
  unsigned int cur_hmn = 0;
  unsigned int cur_hmn_idx = 0;
  bool or_context = 0;
  bool alrd_or_cxt;
  std::map<std::vector<unsigned int>, std::map<bool, std::string>> cur_mp;
  std::map<std::vector<unsigned int>, std::map<bool, std::string>>::iterator cur_it;
  std::map<bool, std::string>::iterator rslt_mp;
  std::vector<unsigned int> idx_v;
  const unsigned int n = searched.length();
  unsigned int n2 = x.length();
  const unsigned int n2_ref = n2;
  unsigned int n_hmn;
  unsigned int cur_par;
  unsigned int ref_cnt;
  unsigned int conditions_idx;
  std::vector<unsigned int> conditions_idxv2;
  if (searched[0] == '[') {
    cnt = 1;
    while (searched[cnt] != ']') {
      cnt += 1;
    };
  } else if (cnt + 1 < n) {
    if (searched[cnt + 1] == '-') {
      cnt += 2;
    };
  };
  if (cnt + 1 < n) {
    cnt += 1;
    if (searched[cnt] == '{') {
      cnt += 1;
      if (searched[cnt] == '?') {
        cur_break_ptrn = "";
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
          cur_break_ptrn.push_back(searched[cnt]);
          cnt += 1;
        };
        cur_mp = regex_findrlow(cur_break_ptrn, cur_x);
        cur_it = cur_mp.begin();
        rslt_mp = cur_it->second.begin();
        if (rslt_mp->first) {
          idx_v = cur_it->first;
          rtn_lst_cnt = idx_v[1];
          for (temp_cnt = 0; temp_cnt < n2 - rtn_lst_cnt - 1; ++temp_cnt) {
            cur_x.pop_back();
          };
        };
      };
    };
  };
  std::map<std::vector<std::vector<unsigned int>>, std::vector<std::vector<std::string>>> bgn_mp = regex_findr_bgn_mid(searched, cur_x);
  std::map<std::vector<std::vector<unsigned int>>, std::vector<std::vector<std::string>>>::iterator bgn_it = bgn_mp.begin();
  std::vector<std::vector<std::string>> hmn_str_idxv = bgn_it->second;
  std::vector<std::vector<unsigned int>> hmn_idxv = bgn_it->first;
  rtn_str = hmn_str_idxv[0][0];
  cnt = regex_findr_first_condition_idx(searched);
  ref_cnt = cnt;
  rtn_lst_cnt = hmn_idxv[0][0];
  n_hmn = hmn_idxv.size();
  cur_x = "";
  while (1) {
    if (searched[cnt] == '{' & searched[cnt - 1] != '\\') {
      cnt += 1;
      if (searched[cnt] == '?') {
        ok_next = 1;
        cnt += 1;
        cur_break_ptrn = "";
        cur_x = "";
        cur_par = 1;
        while (1) {
          if (searched[cnt] == '{' & searched[cnt] != '\\') {
            cur_par += 1;
          } else if (searched[cnt] == '}' & searched[cnt] != '\\') {
            cur_par -= 1;
            if (cur_par == 0) {
              break;
            };
          };
          cur_break_ptrn.push_back(searched[cnt]);
          cnt += 1;
        };
        cnt += 1;
        for (temp_cnt = rtn_lst_cnt + 1; temp_cnt < n2; ++temp_cnt) {
          cur_x.push_back(x[temp_cnt]);
        };
        cur_mp = regex_findrlow(cur_break_ptrn, cur_x);
        cur_it = cur_mp.begin();
        rslt_mp = cur_it->second.begin();
        if (rslt_mp->first) {
          idx_v = cur_it->first;
          rtn_pre_cnt = idx_v[0];
          cur_x_ref = cur_x;
          cur_x = "";
          for (temp_cnt = 0; temp_cnt < rtn_pre_cnt; ++temp_cnt) {
            cur_x.push_back(cur_x_ref[temp_cnt]);
          };
        };
        cur_mp = regex_findr2sub(cur_searched, cur_x);
        cur_it = cur_mp.begin();
        rslt_mp = cur_it->second.begin();
        if (rslt_mp->first) {
          cur_str = rslt_mp->second;
          rtn_lst_cnt += cur_str.length(); 
          rtn_str += cur_str;
          if (or_context) {
            cnt = jump_cnt;
            or_context = 0;
            is_mult = 0;
            n2 = n2_ref;
          };
        } else {
          if (or_context) {
            if (cnt < conditions_idx) {
              ok_next = 0;
            } else {
              or_context = 0;
            };
          };
          if (ok_next) {
            cur_hmn_idx += 1;
            cnt = ref_cnt;
            if (cur_hmn_idx == hmn_idxv[cur_hmn].size()) {
              cur_hmn_idx = 0;
              cur_hmn += 1;
              if (cur_hmn < n_hmn) {
                cur_searched = "";
                rtn_str = hmn_str_idxv[cur_hmn][cur_hmn_idx];
                rtn_lst_cnt = hmn_idxv[cur_hmn][cur_hmn_idx];
              } else {
                return {{{0, 0}, {{0, ""}}}};
              };
            } else {
              cur_searched = "";
              rtn_lst_cnt = hmn_idxv[cur_hmn][cur_hmn_idx];
              rtn_str = hmn_str_idxv[cur_hmn][cur_hmn_idx];
            };
          };
        };
        cur_searched = "";
      } else {
        cur_searched.push_back('{');
      };
    } else if (or_context) {
      if (conditions_idxv2.size() > 0) {
        if (cnt - 1 == conditions_idxv2[idx_condition]) {
          cur_searched.insert(0, 1, '[');
          cur_searched.push_back(']');
          cur_searched.push_back('{');
          if (is_greedy1) {
            cur_searched.push_back('+'); 
          };
          cur_searched += std::to_string(ref_mult);
          cur_searched.push_back('}');
          cur_x = "";
          for (temp_cnt = rtn_lst_cnt + 1; temp_cnt < n2; ++temp_cnt) {
            cur_x.push_back(x[temp_cnt]);
          };
          if (cur_x.length() > 0) {
            cur_mp = regex_findr2sub(cur_searched, cur_x);
            cur_it = cur_mp.begin();
            rslt_mp = cur_it->second.begin();
            cur_found = rslt_mp->first;
          } else {
            cur_found = 0;
          };
          idx_condition += 1;
          if (cur_found) {
            alrd_or_found = 1;
            cur_str = rslt_mp->second;
            rtn_str += cur_str;
            rtn_lst_cnt += cur_str.length();
            cur_x = "";
            for (temp_cnt = rtn_lst_cnt + 1; temp_cnt < n2; ++temp_cnt) {
              cur_x.push_back(x[temp_cnt]);
            };
            if (searched[cnt] == ']') {
              cnt = bf_or_cnt;
              idx_condition = 0;
            };
          } else {
            if (cnt == conditions_idx) {
              if (!alrd_or_found) {
                or_context = 0;
                cur_hmn_idx += 1;
                cnt = ref_cnt;
                if (cur_hmn_idx == hmn_idxv[cur_hmn].size()) {
                  cur_hmn_idx = 0;
                  cur_hmn += 1;
                  if (cur_hmn < n_hmn) {
                    cur_searched = "";
                    rtn_str = hmn_str_idxv[cur_hmn][cur_hmn_idx];
                    rtn_lst_cnt = hmn_idxv[cur_hmn][cur_hmn_idx];
                  } else {
                    return {{{0, 0}, {{0, ""}}}};
                  };
                } else {
                  cur_searched = "";
                  rtn_lst_cnt = hmn_idxv[cur_hmn][cur_hmn_idx];
                  rtn_str = hmn_str_idxv[cur_hmn][cur_hmn_idx];
                };
              } else {
                cnt = jump_cnt;
                or_context = 0;
                is_mult = 0;
                n2 = n2_ref;
              };
            };
          };
          cur_searched = "";
        };
      };
    } else if (searched[cnt] == '[' & searched[cnt - 1] != '\\') {
      cur_x = "";
      for (temp_cnt = rtn_lst_cnt + 1; temp_cnt < n2; ++temp_cnt) {
        cur_x.push_back(x[temp_cnt]);
      };
      idx_condition = 0;
      alrd_or_found = 0;
      is_mult = 0;
      conditions_idxv2 = {};
      temp_cnt = cnt + 1;
      bf_or_cnt = temp_cnt;
      or_context = 1;
      ref_mult = 1;
      while (1) {
        if (searched[temp_cnt] == ']' & searched[temp_cnt - 1] != '\\') {
          break;
        } else if (searched[temp_cnt + 1] == '{' & searched[temp_cnt] != '\\') {
           temp_cnt += 1;
           if (searched[temp_cnt + 1] != '?') {
             temp_cnt += 1;
             while (searched[temp_cnt] != '}') {
               temp_cnt += 1;
             };
             conditions_idxv2.push_back(temp_cnt);
           } else {
             temp_cnt += 1;
             cur_par = 1;
             while (1) {
               if (searched[temp_cnt] == '}' & searched[temp_cnt - 1] != '\\') {
                 cur_par -= 1;
                 if (cur_par == 0) {
                   break;
                 };
               } else if (searched[temp_cnt] == '{' & searched[temp_cnt - 1] != '\\') {
                 cur_par += 1;
               };
               temp_cnt += 1;
             };
           };
        } else {
          if (searched[temp_cnt + 1] == '-') {
            temp_cnt += 1;
          } else {
            conditions_idxv2.push_back(temp_cnt);
          };
        };
        temp_cnt += 1;
      };
      conditions_idx = temp_cnt;
      temp_cnt += 1;
      if (temp_cnt < n) {
        if (searched[temp_cnt] == '{') {
          temp_cnt += 1;
          if (searched[temp_cnt] == '?') {
            cur_break_ptrn = "";
            temp_cnt += 1;
            cur_par = 1;
            while (1) {
              if (searched[temp_cnt] == '}' & searched[temp_cnt - 1] != '\\') {
                cur_par -= 1;
                if (cur_par == 0) {
                  break;
                };
              } else if (searched[temp_cnt] == '{' & searched[temp_cnt - 1] != '\\') {
                cur_par += 1;
              };
              cur_break_ptrn.push_back(searched[temp_cnt]);
              temp_cnt += 1;
            };
            cur_mp = regex_findrlow(cur_break_ptrn, cur_x);
            cur_it = cur_mp.begin();
            rslt_mp = cur_it->second.begin();
            if (rslt_mp->first) {
              idx_v = cur_it->first;
              n2 = rtn_lst_cnt + idx_v[0] + 1;
            };
            temp_cnt += 1;
          } else {
            is_mult = 1;
            if (searched[temp_cnt] == '+') {
              temp_cnt += 1;
              is_greedy1 = 1;
            } else {
              is_greedy1 = 0;
            };
            ref_mult = int(searched[temp_cnt]) - 48;
            temp_cnt += 1;
            while (searched[temp_cnt] != '}') {
              ref_mult *= 10;
              ref_mult += (int(searched[temp_cnt]) - 48);
              temp_cnt += 1;
            };
            temp_cnt += 1;
          };
        };
      };
      cnt += 1;
      jump_cnt = temp_cnt;
    };
    if (cnt < n) {
      if (searched[cnt] != '[') {
        cur_searched.push_back(searched[cnt]);
        cnt += 1;
        alrd_or_cxt = 0;
      } else {
        alrd_or_cxt = 1;
      };
      if (!alrd_or_cxt) {
        if (!or_context) {
          if (cnt < n) {
            if (searched[cnt] == '-') {
              cnt += 1;
              cur_searched.push_back('-');
              cur_searched.push_back(searched[cnt]);
              cnt += 1;
            };
            if (searched[cnt] == '{') {
              while (searched[cnt] != '}') {
                cur_searched.push_back(searched[cnt]);
                cnt += 1;
              };
              cur_searched.push_back('}');
              cnt += 1;
            };
          };
          cur_x = "";
          for (temp_cnt = rtn_lst_cnt + 1; temp_cnt < n2; ++temp_cnt) {
            cur_x.push_back(x[temp_cnt]);
          };
          cur_mp = regex_findr2sub(cur_searched, cur_x);
          cur_it = cur_mp.begin();
          rslt_mp = cur_it->second.begin();
          if (rslt_mp->first) {
            cur_str = rslt_mp->second;
            rtn_str += cur_str;
            rtn_lst_cnt += cur_str.length();
            cur_searched = "";
          } else {
            cur_hmn_idx += 1;
            cnt = ref_cnt;
            if (cur_hmn_idx == hmn_idxv[cur_hmn].size()) {
              cur_hmn_idx = 0;
              cur_hmn += 1;
              if (cur_hmn < n_hmn) {
                cur_searched = "";
                rtn_str = hmn_str_idxv[cur_hmn][cur_hmn_idx];
                rtn_lst_cnt = hmn_idxv[cur_hmn][cur_hmn_idx];
              } else {
                return {{{0, 0}, {{0, ""}}}};
              };
            } else {
              cur_searched = "";
              rtn_lst_cnt = hmn_idxv[cur_hmn][cur_hmn_idx];
              rtn_str = hmn_str_idxv[cur_hmn][cur_hmn_idx];
            };
          };
        };
      };
    } else {
      break;
    };
  };
  rtn_pre_cnt = rtn_lst_cnt - rtn_str.length() + 1;
  return {{{(int)rtn_pre_cnt, rtn_lst_cnt}, {{1, rtn_str}}}};
};

std::map<std::vector<int>, std::vector<std::string>> regex_search_all(std::string &searched, std::string &x) {
  std::string cur_searched = "";
  std::string cur_x = x;
  std::string cur_x_ref;
  std::string rtn_str;
  std::string cur_str;
  std::string cur_break_ptrn = "";
  std::string cur_rslt;
  bool ok_next;
  bool is_mult;
  bool is_greedy1;
  bool cur_found;
  bool alrd_or_found;
  unsigned int idx_condition;
  unsigned int cnt = 0;
  unsigned int bf_or_cnt;
  unsigned int temp_cnt;
  unsigned int jump_cnt;
  unsigned int ref_mult;
  int rtn_lst_cnt = -1;
  unsigned int rtn_pre_cnt;
  bool agn = 1;
  unsigned int cur_hmn = 0;
  unsigned int cur_hmn_idx = 0;
  bool or_context = 0;
  bool alrd_or_cxt;
  std::map<std::vector<unsigned int>, std::map<bool, std::string>> cur_mp;
  std::map<std::vector<unsigned int>, std::map<bool, std::string>>::iterator cur_it;
  std::map<bool, std::string>::iterator rslt_mp;
  std::vector<unsigned int> idx_v;
  const unsigned int n = searched.length();
  unsigned int n2 = x.length();
  const unsigned int n2_ref = n2;
  unsigned int n_hmn;
  unsigned int cur_par;
  unsigned int ref_cnt;
  unsigned int conditions_idx;
  std::vector<unsigned int> conditions_idxv2;
  if (searched[0] == '[') {
    cnt = 1;
    while (searched[cnt] != ']') {
      cnt += 1;
    };
  } else if (cnt + 1 < n) {
    if (searched[cnt + 1] == '-') {
      cnt += 2;
    };
  };
  if (cnt + 1 < n) {
    cnt += 1;
    if (searched[cnt] == '{') {
      cnt += 1;
      if (searched[cnt] == '?') {
        cur_break_ptrn = "";
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
          cur_break_ptrn.push_back(searched[cnt]);
          cnt += 1;
        };
        cur_mp = regex_findrlow(cur_break_ptrn, cur_x);
        cur_it = cur_mp.begin();
        rslt_mp = cur_it->second.begin();
        if (rslt_mp->first) {
          idx_v = cur_it->first;
          rtn_lst_cnt = idx_v[1];
          for (temp_cnt = 0; temp_cnt < n2 - rtn_lst_cnt - 1; ++temp_cnt) {
            cur_x.pop_back();
          };
        };
      };
    };
  };
  std::map<std::vector<std::vector<unsigned int>>, std::vector<std::vector<std::string>>> bgn_mp = regex_findr_bgn_mid(searched, cur_x);
  std::map<std::vector<std::vector<unsigned int>>, std::vector<std::vector<std::string>>>::iterator bgn_it = bgn_mp.begin();
  std::vector<std::vector<std::string>> hmn_str_idxv = bgn_it->second;
  std::vector<std::vector<unsigned int>> hmn_idxv = bgn_it->first;
  rtn_str = hmn_str_idxv[0][0];
  cnt = regex_findr_first_condition_idx(searched);
  ref_cnt = cnt;
  rtn_lst_cnt = hmn_idxv[0][0];
  n_hmn = hmn_idxv.size();
  std::vector<int> rtn_idxv = {};
  std::vector<std::string> rtn_strv = {};
  bool lst_found;
  cur_x = "";
  while (1) {
    lst_found = 1;
    while (1) {
      if (searched[cnt] == '{' & searched[cnt - 1] != '\\') {
        cnt += 1;
        if (searched[cnt] == '?') {
          ok_next = 1;
          cnt += 1;
          cur_break_ptrn = "";
          cur_x = "";
          cur_par = 1;
          while (1) {
            if (searched[cnt] == '{' & searched[cnt] != '\\') {
              cur_par += 1;
            } else if (searched[cnt] == '}' & searched[cnt] != '\\') {
              cur_par -= 1;
              if (cur_par == 0) {
                break;
              };
            };
            cur_break_ptrn.push_back(searched[cnt]);
            cnt += 1;
          };
          cnt += 1;
          for (temp_cnt = rtn_lst_cnt + 1; temp_cnt < n2; ++temp_cnt) {
            cur_x.push_back(x[temp_cnt]);
          };
          cur_mp = regex_findrlow(cur_break_ptrn, cur_x);
          cur_it = cur_mp.begin();
          rslt_mp = cur_it->second.begin();
          if (rslt_mp->first) {
            idx_v = cur_it->first;
            rtn_pre_cnt = idx_v[0];
            cur_x_ref = cur_x;
            cur_x = "";
            for (temp_cnt = 0; temp_cnt < rtn_pre_cnt; ++temp_cnt) {
              cur_x.push_back(cur_x_ref[temp_cnt]);
            };
          };
          cur_mp = regex_findr2sub(cur_searched, cur_x);
          cur_it = cur_mp.begin();
          rslt_mp = cur_it->second.begin();
          if (rslt_mp->first) {
            cur_str = rslt_mp->second;
            rtn_lst_cnt += cur_str.length(); 
            rtn_str += cur_str;
            if (or_context) {
              cnt = jump_cnt;
              or_context = 0;
              is_mult = 0;
              n2 = n2_ref;
            };
          } else {
            if (or_context) {
              if (cnt < conditions_idx) {
                ok_next = 0;
              } else {
                or_context = 0;
              };
            };
            if (ok_next) {
              cur_hmn_idx += 1;
              cnt = ref_cnt;
              if (cur_hmn_idx == hmn_idxv[cur_hmn].size()) {
                cur_hmn_idx = 0;
                cur_hmn += 1;
                if (cur_hmn < n_hmn) {
                  cur_searched = "";
                  rtn_str = hmn_str_idxv[cur_hmn][cur_hmn_idx];
                  rtn_lst_cnt = hmn_idxv[cur_hmn][cur_hmn_idx];
                } else {
                  lst_found = 0;
                  break;
                };
              } else {
                cur_searched = "";
                rtn_lst_cnt = hmn_idxv[cur_hmn][cur_hmn_idx];
                rtn_str = hmn_str_idxv[cur_hmn][cur_hmn_idx];
              };
            };
          };
          cur_searched = "";
        } else {
          cur_searched.push_back('{');
        };
      } else if (or_context) {
        if (conditions_idxv2.size() > 0) {
          if (cnt - 1 == conditions_idxv2[idx_condition]) {
            cur_searched.insert(0, 1, '[');
            cur_searched.push_back(']');
            cur_searched.push_back('{');
            if (is_greedy1) {
              cur_searched.push_back('+'); 
            };
            cur_searched += std::to_string(ref_mult);
            cur_searched.push_back('}');
            cur_x = "";
            for (temp_cnt = rtn_lst_cnt + 1; temp_cnt < n2; ++temp_cnt) {
              cur_x.push_back(x[temp_cnt]);
            };
            if (cur_x.length() > 0) {
              cur_mp = regex_findr2sub(cur_searched, cur_x);
              cur_it = cur_mp.begin();
              rslt_mp = cur_it->second.begin();
              cur_found = rslt_mp->first;
            } else {
              cur_found = 0;
            };
            idx_condition += 1;
            if (cur_found) {
              alrd_or_found = 1;
              cur_str = rslt_mp->second;
              rtn_str += cur_str;
              rtn_lst_cnt += cur_str.length();
              cur_x = "";
              for (temp_cnt = rtn_lst_cnt + 1; temp_cnt < n2; ++temp_cnt) {
                cur_x.push_back(x[temp_cnt]);
              };
              if (searched[cnt] == ']') {
                cnt = bf_or_cnt;
                idx_condition = 0;
              };
            } else {
              if (cnt == conditions_idx) {
                if (!alrd_or_found) {
                  or_context = 0;
                  cur_hmn_idx += 1;
                  cnt = ref_cnt;
                  if (cur_hmn_idx == hmn_idxv[cur_hmn].size()) {
                    cur_hmn_idx = 0;
                    cur_hmn += 1;
                    if (cur_hmn < n_hmn) {
                      cur_searched = "";
                      rtn_str = hmn_str_idxv[cur_hmn][cur_hmn_idx];
                      rtn_lst_cnt = hmn_idxv[cur_hmn][cur_hmn_idx];
                    } else {
                      lst_found = 0;
                      break;
                    };
                  } else {
                    cur_searched = "";
                    rtn_lst_cnt = hmn_idxv[cur_hmn][cur_hmn_idx];
                    rtn_str = hmn_str_idxv[cur_hmn][cur_hmn_idx];
                  };
                } else {
                  cnt = jump_cnt;
                  or_context = 0;
                  is_mult = 0;
                  n2 = n2_ref;
                };
              };
            };
            cur_searched = "";
          };
        };
      } else if (searched[cnt] == '[' & searched[cnt - 1] != '\\') {
        cur_x = "";
        for (temp_cnt = rtn_lst_cnt + 1; temp_cnt < n2; ++temp_cnt) {
          cur_x.push_back(x[temp_cnt]);
        };
        idx_condition = 0;
        alrd_or_found = 0;
        is_mult = 0;
        conditions_idxv2 = {};
        temp_cnt = cnt + 1;
        bf_or_cnt = temp_cnt;
        or_context = 1;
        ref_mult = 1;
        while (1) {
          if (searched[temp_cnt] == ']' & searched[temp_cnt - 1] != '\\') {
            break;
          } else if (searched[temp_cnt + 1] == '{' & searched[temp_cnt] != '\\') {
             temp_cnt += 1;
             if (searched[temp_cnt + 1] != '?') {
               temp_cnt += 1;
               while (searched[temp_cnt] != '}') {
                 temp_cnt += 1;
               };
               conditions_idxv2.push_back(temp_cnt);
             } else {
               temp_cnt += 1;
               cur_par = 1;
               while (1) {
                 if (searched[temp_cnt] == '}' & searched[temp_cnt - 1] != '\\') {
                   cur_par -= 1;
                   if (cur_par == 0) {
                     break;
                   };
                 } else if (searched[temp_cnt] == '{' & searched[temp_cnt - 1] != '\\') {
                   cur_par += 1;
                 };
                 temp_cnt += 1;
               };
             };
          } else {
            if (searched[temp_cnt + 1] == '-') {
              temp_cnt += 1;
            } else {
              conditions_idxv2.push_back(temp_cnt);
            };
          };
          temp_cnt += 1;
        };
        conditions_idx = temp_cnt;
        temp_cnt += 1;
        if (temp_cnt < n) {
          if (searched[temp_cnt] == '{') {
            temp_cnt += 1;
            if (searched[temp_cnt] == '?') {
              cur_break_ptrn = "";
              temp_cnt += 1;
              cur_par = 1;
              while (1) {
                if (searched[temp_cnt] == '}' & searched[temp_cnt - 1] != '\\') {
                  cur_par -= 1;
                  if (cur_par == 0) {
                    break;
                  };
                } else if (searched[temp_cnt] == '{' & searched[temp_cnt - 1] != '\\') {
                  cur_par += 1;
                };
                cur_break_ptrn.push_back(searched[temp_cnt]);
                temp_cnt += 1;
              };
              cur_mp = regex_findrlow(cur_break_ptrn, cur_x);
              cur_it = cur_mp.begin();
              rslt_mp = cur_it->second.begin();
              if (rslt_mp->first) {
                idx_v = cur_it->first;
                n2 = rtn_lst_cnt + idx_v[0] + 1;
              };
              temp_cnt += 1;
            } else {
              is_mult = 1;
              if (searched[temp_cnt] == '+') {
                temp_cnt += 1;
                is_greedy1 = 1;
              } else {
                is_greedy1 = 0;
              };
              ref_mult = int(searched[temp_cnt]) - 48;
              temp_cnt += 1;
              while (searched[temp_cnt] != '}') {
                ref_mult *= 10;
                ref_mult += (int(searched[temp_cnt]) - 48);
                temp_cnt += 1;
              };
              temp_cnt += 1;
            };
          };
        };
        cnt += 1;
        jump_cnt = temp_cnt;
      };
      if (cnt < n) {
        if (searched[cnt] != '[') {
          cur_searched.push_back(searched[cnt]);
          cnt += 1;
          alrd_or_cxt = 0;
        } else {
          alrd_or_cxt = 1;
        };
        if (!alrd_or_cxt) {
          if (!or_context) {
            if (cnt < n) {
              if (searched[cnt] == '-') {
                cnt += 1;
                cur_searched.push_back('-');
                cur_searched.push_back(searched[cnt]);
                cnt += 1;
              };
              if (searched[cnt] == '{') {
                while (searched[cnt] != '}') {
                  cur_searched.push_back(searched[cnt]);
                  cnt += 1;
                };
                cur_searched.push_back('}');
                cnt += 1;
              };
            };
            cur_x = "";
            for (temp_cnt = rtn_lst_cnt + 1; temp_cnt < n2; ++temp_cnt) {
              cur_x.push_back(x[temp_cnt]);
            };
            cur_mp = regex_findr2sub(cur_searched, cur_x);
            cur_it = cur_mp.begin();
            rslt_mp = cur_it->second.begin();
            if (rslt_mp->first) {
              cur_str = rslt_mp->second;
              rtn_str += cur_str;
              rtn_lst_cnt += cur_str.length();
              cur_searched = "";
            } else {
              cur_hmn_idx += 1;
              cnt = ref_cnt;
              if (cur_hmn_idx == hmn_idxv[cur_hmn].size()) {
                cur_hmn_idx = 0;
                cur_hmn += 1;
                if (cur_hmn < n_hmn) {
                  cur_searched = "";
                  rtn_str = hmn_str_idxv[cur_hmn][cur_hmn_idx];
                  rtn_lst_cnt = hmn_idxv[cur_hmn][cur_hmn_idx];
                } else {
                  lst_found = 0;
                  break;
                };
              } else {
                cur_searched = "";
                rtn_lst_cnt = hmn_idxv[cur_hmn][cur_hmn_idx];
                rtn_str = hmn_str_idxv[cur_hmn][cur_hmn_idx];
              };
            };
          };
        };
      } else {
        break;
      };
    };
    if (lst_found) {
      rtn_idxv.push_back(rtn_lst_cnt);
      rtn_strv.push_back(rtn_str);
      cur_hmn_idx += 1;
      cnt = ref_cnt;
      if (cur_hmn_idx == hmn_idxv[cur_hmn].size()) {
        cur_hmn_idx = 0;
        cur_hmn += 1;
        if (cur_hmn < n_hmn) {
          cur_searched = "";
          cnt = ref_cnt;
          rtn_str = hmn_str_idxv[cur_hmn][cur_hmn_idx];
          rtn_lst_cnt = hmn_idxv[cur_hmn][cur_hmn_idx];
        } else {
          break;
        };
      } else {
        cur_searched = "";
        cnt = ref_cnt;
        rtn_lst_cnt = hmn_idxv[cur_hmn][cur_hmn_idx];
        rtn_str = hmn_str_idxv[cur_hmn][cur_hmn_idx];
      };
    } else {
      break;    
    };
  };
  return {{rtn_idxv, rtn_strv}};
};

std::map<std::vector<int>, std::map<bool, std::string>> regex_findrmid2sub(std::string &searched, std::string &x) {
  std::string cur_searched = "";
  std::string cur_x = x;
  std::string cur_x_ref;
  std::string rtn_str;
  std::string cur_str;
  std::string cur_break_ptrn = "";
  std::string cur_rslt;
  bool ok_next;
  bool is_mult;
  bool is_greedy1;
  bool cur_found;
  bool alrd_or_found;
  unsigned int idx_condition;
  unsigned int cnt = 0;
  unsigned int bf_or_cnt;
  unsigned int temp_cnt;
  unsigned int jump_cnt;
  unsigned int ref_mult;
  int rtn_lst_cnt = -1;
  unsigned int rtn_pre_cnt;
  bool agn = 1;
  bool or_context = 0;
  bool alrd_or_cxt;
  bool is_ok;
  std::map<std::vector<unsigned int>, std::map<bool, std::string>> cur_mp;
  std::map<std::vector<unsigned int>, std::map<bool, std::string>>::iterator cur_it;
  std::map<bool, std::string>::iterator rslt_mp;
  std::vector<unsigned int> idx_v;
  const unsigned int n = searched.length();
  unsigned int n2 = x.length();
  const unsigned int n2_ref = n2;
  unsigned int n_hmn;
  unsigned int cur_par;
  unsigned int conditions_idx;
  std::vector<unsigned int> conditions_idxv2;
  rtn_str = "";
  rtn_lst_cnt = -1;
  while (1) {
    is_ok = 1;
    if (searched[cnt] == '{') {
      if (cnt > 0) {
        if (searched[cnt - 1] == '\\') {
          is_ok = 0;
        };
      };
      if (is_ok) {
        cnt += 1;
        if (searched[cnt] == '?') {
          ok_next = 1;
          cnt += 1;
          cur_break_ptrn = "";
          cur_x = "";
          cur_par = 1;
          while (1) {
            if (searched[cnt] == '{' & searched[cnt] != '\\') {
              cur_par += 1;
            } else if (searched[cnt] == '}' & searched[cnt] != '\\') {
              cur_par -= 1;
              if (cur_par == 0) {
                break;
              };
            };
            cur_break_ptrn.push_back(searched[cnt]);
            cnt += 1;
          };
          cnt += 1;
          for (temp_cnt = rtn_lst_cnt + 1; temp_cnt < n2; ++temp_cnt) {
            cur_x.push_back(x[temp_cnt]);
          };
          cur_mp = regex_findrlow(cur_break_ptrn, cur_x);
          cur_it = cur_mp.begin();
          rslt_mp = cur_it->second.begin();
          if (rslt_mp->first) {
            idx_v = cur_it->first;
            rtn_pre_cnt = idx_v[0];
            cur_x_ref = cur_x;
            cur_x = "";
            for (temp_cnt = 0; temp_cnt < rtn_pre_cnt; ++temp_cnt) {
              cur_x.push_back(cur_x_ref[temp_cnt]);
            };
          };
          cur_mp = regex_findr2sub(cur_searched, cur_x);
          cur_it = cur_mp.begin();
          rslt_mp = cur_it->second.begin();
          if (rslt_mp->first) {
            cur_str = rslt_mp->second;
            rtn_lst_cnt += cur_str.length(); 
            rtn_str += cur_str;
            if (or_context) {
              cnt = jump_cnt;
              or_context = 0;
              is_mult = 0;
              n2 = n2_ref;
            };
          } else {
            if (or_context) {
              if (cnt < conditions_idx) {
                ok_next = 0;
              } else {
                or_context = 0;
              };
            };
            if (ok_next) {
              return {{{}, {{0, ""}}}};
            };
          };
          cur_searched = "";
        } else {
          cur_searched.push_back('{');
        };
      };
    } else if (or_context) {
      if (conditions_idxv2.size() > 0) {
        if (cnt - 1 == conditions_idxv2[idx_condition]) {
          cur_searched.insert(0, 1, '[');
          cur_searched.push_back(']');
          cur_searched.push_back('{');
          if (is_greedy1) {
            cur_searched.push_back('+'); 
          };
          cur_searched += std::to_string(ref_mult);
          cur_searched.push_back('}');
          cur_x = "";
          for (temp_cnt = rtn_lst_cnt + 1; temp_cnt < n2; ++temp_cnt) {
            cur_x.push_back(x[temp_cnt]);
          };
          if (cur_x.length() > 0) {
            cur_mp = regex_findr2sub(cur_searched, cur_x);
            cur_it = cur_mp.begin();
            rslt_mp = cur_it->second.begin();
            cur_found = rslt_mp->first;
          } else {
            cur_found = 0;
          };
          idx_condition += 1;
          if (cur_found) {
            alrd_or_found = 1;
            cur_str = rslt_mp->second;
            rtn_str += cur_str;
            rtn_lst_cnt += cur_str.length();
            cur_x = "";
            for (temp_cnt = rtn_lst_cnt + 1; temp_cnt < n2; ++temp_cnt) {
              cur_x.push_back(x[temp_cnt]);
            };
            if (searched[cnt] == ']') {
              cnt = bf_or_cnt;
              idx_condition = 0;
            };
          } else {
            if (cnt == conditions_idx) {
              if (!alrd_or_found) {
                return {{{}, {{0, ""}}}};
              } else {
                cnt = jump_cnt;
                or_context = 0;
                is_mult = 0;
                n2 = n2_ref;
              };
            };
          };
          cur_searched = "";
        };
      };
    } else if (searched[cnt] == '[') {
      if (cnt > 0) {
        if (searched[cnt - 1] == '\\') {
          is_ok = 0;
        };
      };
      if (is_ok) {
        cur_x = "";
        for (temp_cnt = rtn_lst_cnt + 1; temp_cnt < n2; ++temp_cnt) {
          cur_x.push_back(x[temp_cnt]);
        };
        idx_condition = 0;
        alrd_or_found = 0;
        is_mult = 0;
        conditions_idxv2 = {};
        temp_cnt = cnt + 1;
        bf_or_cnt = temp_cnt;
        or_context = 1;
        ref_mult = 1;
        while (1) {
          if (searched[temp_cnt] == ']' & searched[temp_cnt - 1] != '\\') {
            break;
          } else if (searched[temp_cnt + 1] == '{' & searched[temp_cnt] != '\\') {
             temp_cnt += 1;
             if (searched[temp_cnt + 1] != '?') {
               temp_cnt += 1;
               while (searched[temp_cnt] != '}') {
                 temp_cnt += 1;
               };
               conditions_idxv2.push_back(temp_cnt);
             } else {
               temp_cnt += 1;
               cur_par = 1;
               while (1) {
                 if (searched[temp_cnt] == '}' & searched[temp_cnt - 1] != '\\') {
                   cur_par -= 1;
                   if (cur_par == 0) {
                     break;
                   };
                 } else if (searched[temp_cnt] == '{' & searched[temp_cnt - 1] != '\\') {
                   cur_par += 1;
                 };
                 temp_cnt += 1;
               };
             };
          } else {
            if (searched[temp_cnt + 1] == '-') {
              temp_cnt += 1;
            } else {
              conditions_idxv2.push_back(temp_cnt);
            };
          };
          temp_cnt += 1;
        };
        conditions_idx = temp_cnt;
        temp_cnt += 1;
        if (temp_cnt < n) {
          if (searched[temp_cnt] == '{') {
            temp_cnt += 1;
            if (searched[temp_cnt] == '?') {
              cur_break_ptrn = "";
              temp_cnt += 1;
              cur_par = 1;
              while (1) {
                if (searched[temp_cnt] == '}' & searched[temp_cnt - 1] != '\\') {
                  cur_par -= 1;
                  if (cur_par == 0) {
                    break;
                  };
                } else if (searched[temp_cnt] == '{' & searched[temp_cnt - 1] != '\\') {
                  cur_par += 1;
                };
                cur_break_ptrn.push_back(searched[temp_cnt]);
                temp_cnt += 1;
              };
              cur_mp = regex_findrlow(cur_break_ptrn, cur_x);
              cur_it = cur_mp.begin();
              rslt_mp = cur_it->second.begin();
              if (rslt_mp->first) {
                idx_v = cur_it->first;
                n2 = rtn_lst_cnt + idx_v[0] + 1;
              };
              temp_cnt += 1;
            } else {
              is_mult = 1;
              if (searched[temp_cnt] == '+') {
                temp_cnt += 1;
                is_greedy1 = 1;
              } else {
                is_greedy1 = 0;
              };
              ref_mult = int(searched[temp_cnt]) - 48;
              temp_cnt += 1;
              while (searched[temp_cnt] != '}') {
                ref_mult *= 10;
                ref_mult += (int(searched[temp_cnt]) - 48);
                temp_cnt += 1;
              };
              temp_cnt += 1;
            };
          };
        };
        cnt += 1;
        jump_cnt = temp_cnt;
      };
    };
    if (cnt < n) {
      if (searched[cnt] != '[') {
        cur_searched.push_back(searched[cnt]);
        cnt += 1;
        alrd_or_cxt = 0;
      } else {
        alrd_or_cxt = 1;
      };
      if (!alrd_or_cxt) {
        if (!or_context) {
          if (cnt < n) {
            if (searched[cnt] == '-') {
              cnt += 1;
              cur_searched.push_back('-');
              cur_searched.push_back(searched[cnt]);
              cnt += 1;
            };
            if (searched[cnt] == '{') {
              while (searched[cnt] != '}') {
                cur_searched.push_back(searched[cnt]);
                cnt += 1;
              };
              cur_searched.push_back('}');
              cnt += 1;
            };
          };
          cur_x = "";
          for (temp_cnt = rtn_lst_cnt + 1; temp_cnt < n2; ++temp_cnt) {
            cur_x.push_back(x[temp_cnt]);
          };
          cur_mp = regex_findr2sub(cur_searched, cur_x);
          cur_it = cur_mp.begin();
          rslt_mp = cur_it->second.begin();
          if (rslt_mp->first) {
            cur_str = rslt_mp->second;
            rtn_str += cur_str;
            rtn_lst_cnt += cur_str.length();
            cur_searched = "";
          } else {
            return {{{}, {{0, ""}}}}; 
          };
        };
      };
    } else {
      break;
    };
  };
  rtn_pre_cnt = rtn_lst_cnt - rtn_str.length() + 1;
  return {{{(int)rtn_pre_cnt, rtn_lst_cnt}, {{1, rtn_str}}}};
};
