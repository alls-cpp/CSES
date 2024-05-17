// https://cses.fi/paste/49eca9ffc09706468c8865/
input/code.cpp: In function 'int32_t main()':
input/code.cpp:37:9: warning: this 'for' clause does not guard... [-Wmisleading-indentation]
   37 |         for (auto x : a1) cout << x << ' '; cout << '\n';
      |         ^~~
input/code.cpp:37:45: note: ...this statement, but the latter is misleadingly indented as if it were guarded by the 'for'
   37 |         for (auto x : a1) cout << x << ' '; cout << '\n';
      |                                             ^~~~
input/code.cpp:38:9: warning: this 'for' clause does not guard... [-Wmisleading-indentation]
   38 |         for (auto x : a2) cout << x << ' '; cout << '\n';
      |         ^~~
input/code.cpp:38:45: note: ...this statement, but the latter is misleadingly indented as if it were guarded by the 'for'
   38 |         for (auto x : a2) cout << x << ' '; cout << '\n';
      |                                             ^~~~