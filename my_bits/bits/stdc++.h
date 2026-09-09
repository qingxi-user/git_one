// my_bits/bits/stdc++.h
//
// Mac (Apple Clang) 学习用万能头
// ─────────────────────────────────────────────────────────────
// GCC 自带 <bits/stdc++.h>（一个文件 include 所有 C++ 标准头），
// 但 Apple Clang 用的是 libc++，没有这个头。直接 #include<bits/stdc++.h>
// 会报 'file not found'。
//
// 用法：在 code_one 工作区下，tasks.json 已加 -I my_bits，
//       所以这一行可以直接编：
//           #include <bits/stdc++.h>
//
// 维护说明：本文件只 include 学习/竞赛常用的头，不是 GCC 那 100+ 个
// 的完全版。如需补全，按下面风格加新行即可。

#pragma once

// ── 输入输出 ──
#include <iostream>
#include <iomanip>
#include <sstream>
#include <fstream>
#include <ios>
#include <istream>
#include <ostream>
#include <streambuf>
#include <iosfwd>

// ── 字符串与字符 ──
#include <string>
#include <string_view>
#include <cctype>
#include <cstdio>
#include <cstdlib>
#include <cstring>

// ── 容器 ──
#include <vector>
#include <list>
#include <deque>
#include <queue>
#include <stack>
#include <array>
#include <tuple>
#include <utility>
#include <initializer_list>

// ── 关联容器 ──
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <bitset>

// ── 算法与迭代器 ──
#include <algorithm>
#include <functional>
#include <iterator>
#include <numeric>
#include <random>

// ── 数学与数值 ──
#include <cmath>
#include <complex>
#include <valarray>
#include <limits>
#include <cfloat>
#include <climits>

// ── 时间与并发 ──
#include <chrono>
#include <thread>
#include <mutex>
#include <condition_variable>
#include <future>
#include <atomic>

// ── 错误处理与类型 ──
#include <exception>
#include <stdexcept>
#include <type_traits>
#include <typeinfo>
#include <memory>

// ── 正则与杂项 ──
#include <regex>
#include <optional>
#include <variant>