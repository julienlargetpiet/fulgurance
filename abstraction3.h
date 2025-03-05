#include "abstraction2.h"

std::map<std::vector<std::vector<unsigned int>>, std::vector<std::vector<std::string>>> regex_findr_bgn_mid(std::string searched, std::string x) {
  std::map<std::vector<unsigned int>, std::map<bool, std::string>> cur_mp;
  std::map<std::vector<unsigned int>, std::map<bool, std::string>>::iterator cur_it;
  std::map<bool, std::string>::iterator rslt_mp;
  std::vector<unsigned int> idx_v;
  std::vector<unsigned int> conditions_idx_v = {};
  std::vector<std::vector<std::string>> hmn_str_idxv = {};
  std::vector<unsigned int> cur_hmn_idxv = {};
  std::vector<std::string> cur_hmn_strv = {};
  std::vector<std::vector<unsigned int>> hmn_idxv = {};
  unsigned int ncx = searched.length();
  unsigned int temp_cnt;
  unsigned int temp_cnt2;
  unsigned int cur_lmt;
  unsigned int rtn_pre_cnt;
  unsigned int rtn_lst_cnt = 0;
  unsigned int ref_mult;
  unsigned int ref_mult2;
  unsigned int ref_temp_cnt2;
  unsigned int cur_par = 0;
  bool bgn_par = 0;
  bool greedy_state;
  bool par_content;
  bool is_found;
  std::string cur_str;
  std::string cur_x;
  std::string ref_cur_x;
  std::string break_ptrn = "";
  std::string cur_break_ptrn;
  std::string cur_searched;
  if (searched[0] == '[') {
    temp_cnt = 1;
    while (searched[temp_cnt] != ']' & searched[temp_cnt - 1] != '\\') {
      if (searched[temp_cnt] == '{' & searched[temp_cnt - 1] != '\\') {
        bgn_par = 1;
      } else if (searched[temp_cnt] == '}' & searched[temp_cnt - 1] != '\\') {
        bgn_par = 0;
      } else if (!bgn_par) {
        conditions_idx_v.push_back(temp_cnt);
        if (temp_cnt + 1 < ncx) {
          if (searched[temp_cnt + 1] == '-') {
            temp_cnt += 2;
          };
        };
      };
      temp_cnt += 1;
    };
    conditions_idx_v.push_back(temp_cnt);
    if (temp_cnt + 4 < ncx) {
      temp_cnt += 1;
      if (searched[temp_cnt] == '{' & searched[temp_cnt + 1] == '?') {
        cur_x = x;
        temp_cnt += 2;
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
          break_ptrn.push_back(searched[temp_cnt]);
          temp_cnt += 1;
          if (temp_cnt == ncx) {
            break;
          };
        };
        cur_mp = regex_findrlow(break_ptrn, x);
        cur_it = cur_mp.begin();
        rslt_mp = cur_it->second.begin();
        if (rslt_mp->first) {
          idx_v = cur_it->first;
          rtn_pre_cnt = idx_v[0];
          cur_x = "";
          for (temp_cnt = 0; temp_cnt < rtn_pre_cnt; ++temp_cnt) {
            cur_x.push_back(x[temp_cnt]);
          };
        };
        ref_cur_x = cur_x;
        for (temp_cnt = 0; temp_cnt + 1 < conditions_idx_v.size(); ++temp_cnt) {
          cur_x = ref_cur_x;
          rtn_lst_cnt = 0;
          par_content = 0;
          cur_searched = "";
          temp_cnt2 = conditions_idx_v[temp_cnt];
          cur_lmt = conditions_idx_v[temp_cnt + 1];
          while (temp_cnt2 < cur_lmt) {
            if (searched[temp_cnt2] == '{' & searched[temp_cnt2] != '\\') {
              par_content = 1;
              break;
            };
            cur_searched.push_back(searched[temp_cnt2]);
            temp_cnt2 += 1;
          };
          cur_break_ptrn = "";
          if (par_content) {
            temp_cnt2 += 1;
            cur_par = 1;
            if (searched[temp_cnt2] == '?') {
              temp_cnt2 += 1;
              while (1) {
                if (searched[temp_cnt2] == '}' & searched[temp_cnt2 - 1] != '\\') {
                  cur_par -= 1;
                  if (cur_par == 0) {
                    break;
                  };
                } else if (searched[temp_cnt2] == '{' & searched[temp_cnt2 - 1] != '\\') {
                  cur_par += 1;
                };
                cur_break_ptrn.push_back(searched[temp_cnt2]);
                temp_cnt2 += 1;
              };
              cur_mp = regex_findrlow(cur_break_ptrn, cur_x);
              cur_it = cur_mp.begin();
              rslt_mp = cur_it->second.begin();
              if (rslt_mp->first) {
                idx_v = cur_it->first;
                rtn_pre_cnt = idx_v[0];
                cur_x = "";
                for (temp_cnt2 = 0; temp_cnt2 < rtn_pre_cnt; ++temp_cnt2) {
                  cur_x.push_back(x[temp_cnt2]);
                };
              };
            } else {
              cur_searched.push_back('{');
              while (1) {
                if (searched[temp_cnt2] == '}' & searched[temp_cnt2] != '\\') {
                  cur_par -= 1;
                  if (cur_par == 0) {
                    break;
                  };
                } else if (searched[temp_cnt2] == '{' & searched[temp_cnt2] != '\\') {
                  cur_par += 1;
                };
                cur_searched.push_back(searched[temp_cnt2]);
                temp_cnt2 += 1;
              };
              cur_searched.push_back('}');
            };
          };
          cur_hmn_idxv = {};
          cur_hmn_strv = {};
          ncx = cur_x.length();
          is_found = 0;
          while (1) {
            cur_mp = regex_findr1sub(cur_searched, cur_x);
            cur_it = cur_mp.begin();
            rslt_mp = cur_it->second.begin();
            if (rslt_mp->first) {
              is_found = 1;
              cur_str = rslt_mp->second;
              cur_hmn_strv.push_back(cur_str);
              idx_v = cur_it->first;
              rtn_lst_cnt += idx_v[1];
              cur_hmn_idxv.push_back(rtn_lst_cnt);
            } else {
              break;
            };
            if (rtn_lst_cnt + 1 < ncx) {
              cur_x = "";
              for (temp_cnt2 = rtn_lst_cnt + 1; temp_cnt2 < ncx; ++temp_cnt2) {
                cur_x.push_back(x[temp_cnt2]);
              };
              rtn_lst_cnt += 1;
            } else {
              break;
            };
          };
          if (is_found) {
            hmn_idxv.push_back(cur_hmn_idxv);
            hmn_str_idxv.push_back(cur_hmn_strv);
          };
        };
      } else if (searched[temp_cnt] == '{') {
        ncx = x.length();
        temp_cnt += 1;
        if (searched[temp_cnt] == '+')  {
          temp_cnt += 1;
        };
        ref_mult = int(searched[temp_cnt]) - 48;
        temp_cnt += 1;
        while (searched[temp_cnt] != '}') {
          temp_cnt *= 10;
          ref_mult += (int(searched[temp_cnt]) - 48);
          temp_cnt += 1;
        };
        for (temp_cnt = 0; temp_cnt + 1 < conditions_idx_v.size(); ++temp_cnt) {
          rtn_lst_cnt = 0;
          par_content = 0;
          cur_lmt = conditions_idx_v[temp_cnt + 1];
          cur_searched = "";
          temp_cnt2 = conditions_idx_v[temp_cnt];
          while (temp_cnt2 < cur_lmt) {
            cur_searched.push_back(searched[temp_cnt2]);
            temp_cnt2 += 1;
          };
          cur_searched.insert(0, 1, '[');
          cur_searched.push_back(']');
          cur_searched.push_back('{');
          cur_searched += std::to_string(ref_mult);
          cur_searched.push_back('}');
          cur_x = x;
          cur_hmn_idxv = {};
          cur_hmn_strv = {};
          is_found = 0;
          while (1) {
            cur_mp = regex_findr1sub(cur_searched, cur_x);
            cur_it = cur_mp.begin();
            rslt_mp = cur_it->second.begin();
            if (rslt_mp->first) {
              is_found = 1;
              idx_v = cur_it->first;
              rtn_lst_cnt += idx_v[1];
              cur_str = rslt_mp->second;
              cur_hmn_strv.push_back(cur_str);
              cur_hmn_idxv.push_back(rtn_lst_cnt);
            } else {
              break;
            };
            if (rtn_lst_cnt + 1 < ncx) {
              cur_x = "";
              for (temp_cnt2 = rtn_lst_cnt + 1; temp_cnt2 < ncx; ++temp_cnt2) {
                cur_x.push_back(x[temp_cnt2]);
              };
              rtn_lst_cnt += 1;
            } else {
              break;
            };
          };
          if (is_found) {
            hmn_idxv.push_back(cur_hmn_idxv);
            hmn_str_idxv.push_back(cur_hmn_strv);
          };
        };
      } else {
        ncx = x.length();
        for (temp_cnt = 0; temp_cnt + 1 < conditions_idx_v.size(); ++temp_cnt) {
          rtn_lst_cnt = 0;
          cur_searched = "";
          cur_lmt = conditions_idx_v[temp_cnt + 1];
          for (temp_cnt2 = conditions_idx_v[temp_cnt]; temp_cnt2 < cur_lmt; ++temp_cnt2) {
            cur_searched.push_back(searched[temp_cnt2]);
          };
          cur_x = x;
          cur_hmn_idxv = {};
          cur_hmn_strv = {};
          is_found = 0;
          while (1) {
            cur_mp = regex_findr1sub(cur_searched, cur_x);
            cur_it = cur_mp.begin();
            rslt_mp = cur_it->second.begin();
            if (rslt_mp->first) {
              is_found = 1;
              idx_v = cur_it->first;
              rtn_lst_cnt += idx_v[1];
              cur_hmn_idxv.push_back(rtn_lst_cnt);
              cur_str = rslt_mp->second;
              cur_hmn_strv.push_back(cur_str);
            } else {
              break;
            };
            if (rtn_lst_cnt + 1 < ncx) {
              cur_x = "";
              for (temp_cnt2 = rtn_lst_cnt + 1; temp_cnt2 < ncx; ++temp_cnt2) {
                cur_x.push_back(x[temp_cnt2]);
              };
              rtn_lst_cnt += 1;
            } else {
              break;
            };
          };
          if (is_found) {
            hmn_idxv.push_back(cur_hmn_idxv);
            hmn_str_idxv.push_back(cur_hmn_strv);
          };
        };
      };
    } else if (temp_cnt + 1 < ncx) { 
      if (searched[temp_cnt + 1] == '{') {
        ncx = x.length();
        temp_cnt += 2;
        ref_mult = int(searched[temp_cnt]) - 48;
        temp_cnt += 1;
        while (searched[temp_cnt] != '}') {
          temp_cnt *= 10;
          ref_mult += (int(searched[temp_cnt]) - 48);
          temp_cnt += 1;
        };
        for (temp_cnt = 0; temp_cnt + 1 < conditions_idx_v.size(); ++temp_cnt) {
          rtn_lst_cnt = 0;
          par_content = 0;
          cur_lmt = conditions_idx_v[temp_cnt + 1];
          cur_searched = "";
          temp_cnt2 = conditions_idx_v[temp_cnt];
          while (temp_cnt2 < cur_lmt) {
            cur_searched.push_back(searched[temp_cnt2]);
            temp_cnt2 += 1;
          };
          cur_searched.insert(0, 1, '[');
          cur_searched.push_back(']');
          cur_searched.push_back('{');
          cur_searched += std::to_string(ref_mult);
          cur_searched.push_back('}');
          cur_x = x;
          cur_hmn_idxv = {};
          cur_hmn_strv = {};
          is_found = 0;
          while (1) {
            cur_mp = regex_findr1sub(cur_searched, cur_x);
            cur_it = cur_mp.begin();
            rslt_mp = cur_it->second.begin();
            if (rslt_mp->first) {
              is_found = 1;
              idx_v = cur_it->first;
              rtn_lst_cnt += idx_v[1];
              cur_str = rslt_mp->second;
              cur_hmn_strv.push_back(cur_str);
              cur_hmn_idxv.push_back(rtn_lst_cnt);
            } else {
              break;
            };
            if (rtn_lst_cnt + 1 < ncx) {
              cur_x = "";
              for (temp_cnt2 = rtn_lst_cnt + 1; temp_cnt2 < ncx; ++temp_cnt2) {
                cur_x.push_back(x[temp_cnt2]);
              };
              rtn_lst_cnt += 1;
            } else {
              break;
            };
          };
          if (is_found) {
            hmn_idxv.push_back(cur_hmn_idxv);
            hmn_str_idxv.push_back(cur_hmn_strv);
          };
        };
      } else {
        ncx = x.length();
        for (temp_cnt = 0; temp_cnt + 1 < conditions_idx_v.size(); ++temp_cnt) {
          rtn_lst_cnt = 0;
          cur_searched = "";
          cur_lmt = conditions_idx_v[temp_cnt + 1];
          for (temp_cnt2 = conditions_idx_v[temp_cnt]; temp_cnt2 < cur_lmt; ++temp_cnt2) {
            cur_searched.push_back(searched[temp_cnt2]);
          };
          cur_x = x;
          cur_hmn_idxv = {};
          cur_hmn_strv = {};
          is_found = 0;
          while (1) {
            cur_mp = regex_findr1sub(cur_searched, cur_x);
            cur_it = cur_mp.begin();
            rslt_mp = cur_it->second.begin();
            if (rslt_mp->first) {
              is_found = 1;
              idx_v = cur_it->first;
              rtn_lst_cnt += idx_v[1];
              cur_hmn_idxv.push_back(rtn_lst_cnt);
              cur_str = rslt_mp->second;
              cur_hmn_strv.push_back(cur_str);
            } else {
              break;
            };
            if (rtn_lst_cnt + 1 < ncx) {
              cur_x = "";
              for (temp_cnt2 = rtn_lst_cnt + 1; temp_cnt2 < ncx; ++temp_cnt2) {
                cur_x.push_back(x[temp_cnt2]);
              };
              rtn_lst_cnt += 1;
            } else {
              break;
            };
          };
          if (is_found) {
            hmn_idxv.push_back(cur_hmn_idxv);
            hmn_str_idxv.push_back(cur_hmn_strv);
          };
        };
      };
    } else {
      ncx = x.length();
      for (temp_cnt = 0; temp_cnt + 1 < conditions_idx_v.size(); ++temp_cnt) {
        rtn_lst_cnt = 0;
        cur_searched = "";
        cur_lmt = conditions_idx_v[temp_cnt + 1];
        for (temp_cnt2 = conditions_idx_v[temp_cnt]; temp_cnt2 < cur_lmt; ++temp_cnt2) {
          cur_searched.push_back(searched[temp_cnt2]);
        };
        cur_x = x;
        cur_hmn_idxv = {};
        cur_hmn_strv = {};
        is_found = 0;
        while (1) {
          cur_mp = regex_findr1sub(cur_searched, cur_x);
          cur_it = cur_mp.begin();
          rslt_mp = cur_it->second.begin();
          if (rslt_mp->first) {
            is_found = 1;
            idx_v = cur_it->first;
            rtn_lst_cnt += idx_v[1];
            cur_hmn_idxv.push_back(rtn_lst_cnt);
            cur_str = rslt_mp->second;
            cur_hmn_strv.push_back(cur_str);
          } else {
            break;
          };
          if (rtn_lst_cnt + 1 < ncx) {
            cur_x = "";
            for (temp_cnt2 = rtn_lst_cnt + 1; temp_cnt2 < ncx; ++temp_cnt2) {
              cur_x.push_back(x[temp_cnt2]);
            };
            rtn_lst_cnt += 1;
          } else {
            break;
          };
        };
        if (is_found) {
          hmn_idxv.push_back(cur_hmn_idxv);
          hmn_str_idxv.push_back(cur_hmn_strv);
        };
      };
    };
  } else {
    cur_x = x;
    cur_searched = searched[0];
    temp_cnt2 = 1;
    if (ncx > 1) {
      if (searched[1] == '-') {
        cur_searched.push_back('-');
        cur_searched.push_back(searched[2]);
        temp_cnt2 = 3;
      };
    };
    if (temp_cnt2 < ncx) {
      if (searched[temp_cnt2] == '{') {
        if (searched[temp_cnt2 + 1] != '?') {
          while (1) {
            cur_searched.push_back(searched[temp_cnt2]);
            temp_cnt2 += 1;
            if (temp_cnt2 == ncx) {
              break;
            };
            if (searched[temp_cnt2] == '}' & searched[temp_cnt2 - 1] != '\\') {
              cur_searched.push_back('}');
              break;
            };
          };
        } else {
          cur_par = 1;
          cur_break_ptrn = "";
          temp_cnt2 += 2;
          while (1) {
            if (searched[temp_cnt2] == '}' & searched[temp_cnt2 - 1] != '\\') {
              cur_par -= 1;
              if (cur_par == 0) {
                break;
              };
            } else if (searched[temp_cnt2] == '{' & searched[temp_cnt2 - 1] != '\\') {
              cur_par += 1;
            };
            cur_break_ptrn.push_back(searched[temp_cnt2]);
            temp_cnt2 += 1;
            if (temp_cnt2 == ncx) {
              break;
            };
          };
          cur_mp = regex_findrlow(cur_break_ptrn, cur_x);
          cur_it = cur_mp.begin();
          rslt_mp = cur_it->second.begin();
          if (rslt_mp->first) {
            idx_v = cur_it->first;
            rtn_pre_cnt = idx_v[0];
            cur_x = "";
            for (temp_cnt2 = 0; temp_cnt2 < rtn_pre_cnt; ++temp_cnt2) {
              cur_x.push_back(x[temp_cnt2]);
            };
          };
        };
      };
    };
    ncx = cur_x.length();
    cur_hmn_idxv = {};
    cur_hmn_strv = {};
    is_found = 0;
    while (1) {
      cur_mp = regex_findr1sub(cur_searched, cur_x);
      cur_it = cur_mp.begin();
      rslt_mp = cur_it->second.begin();
      if (rslt_mp->first) {
        is_found = 1;
        idx_v = cur_it->first;
        rtn_lst_cnt += idx_v[1];
        cur_hmn_idxv.push_back(rtn_lst_cnt);
        cur_str = rslt_mp->second;
        cur_hmn_strv.push_back(cur_str);
      } else {
        break;
      };
      if (rtn_lst_cnt + 1 < ncx) {
        cur_x = "";
        for (temp_cnt2 = rtn_lst_cnt + 1; temp_cnt2 < ncx; ++temp_cnt2) {
          cur_x.push_back(x[temp_cnt2]);
        };
        rtn_lst_cnt += 1;
      } else {
        break;
      };
    };
    if (is_found) {
      hmn_idxv.push_back(cur_hmn_idxv);
      hmn_str_idxv.push_back(cur_hmn_strv);
    };
  };
  return {{hmn_idxv, hmn_str_idxv}};
};
