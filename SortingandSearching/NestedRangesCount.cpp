// https://cses.fi/paste/21abe15379bd71c58c9e3f/
input/code.cpp: In function 'int32_t main()':
input/code.cpp:34:9: warning: this 'for' clause does not guard... [-Wmisleading-indentation]
   34 |         for (auto x : a1) cout << x << ' '; cout << '\n';
      |         ^~~
input/code.cpp:34:45: note: ...this statement, but the latter is misleadingly indented as if it were guarded by the 'for'
   34 |         for (auto x : a1) cout << x << ' '; cout << '\n';
      |                                             ^~~~
input/code.cpp:35:9: warning: this 'for' clause does not guard... [-Wmisleading-indentation]
   35 |         for (auto x : a2) cout << x << ' '; cout << '\n';
      |         ^~~
input/code.cpp:35:45: note: ...this statement, but the latter is misleadingly indented as if it were guarded by the 'for'
   35 |         for (auto x : a2) cout << x << ' '; cout << '\n';
      |                                             ^~~~