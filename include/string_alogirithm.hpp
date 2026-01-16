//
//  string_alogirithm.hpp
//  algorithm
//
//  Created by Tianqi Zhu on 1/15/26.
//

#pragma once
#include <bits/stdc++.h>

// kmp
inline vector<int> prefix_function(string s) {
    int n = (int)s.length();
    vector<int> pi(n);
    
    for (int i = 1; i < n; i++) {
        int j = pi[i - 1];
        while (j > 0 && s[j] != s[i]) {
            j = pi[j-1];
        }
        if (s[j] == s[i])
            j++;
        pi[i] = j;
    }
    return pi;
}

#ifdef UNIT_TEST
static bool test_kmp = [] {
    vector<int> v = {0, 0, 0, 1, 2, 3, 0};
    assert(v == prefix_function("abcabcd"));
    return true;
}();
#endif

// z
inline vector<int> z_function(string s) {
    int n = (int)s.length();
    vector<int> z(n);
    int l = 0, r = 0;
    for (int i = 1; i < n; i++) {
        if (i < r) {
            z[i] = min(z[i - l], r - i);
        }
        while (i + z[i] < n && s[i + z[i]] == s[z[i]]) {
            z[i]++;
        }
        if (i + z[i] > r) {
            l = i;
            r = z[i] + i;
        }
    }
    return z;
}

#ifdef UNIT_TEST
static bool test_z = [] {
    vector<int> v = {0, 0, 1, 0, 3, 0, 1};
    assert(v == z_function("abacaba"));
    return true;
}();
#endif


