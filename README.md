# algorithm

学一些有的没的小算法 万一哪天用上了呢。


## 功能特性
- 功能 1
- 功能 2

## 安装
```bash
git clone https://github.com/xxx/your-project.git
cd your-project
```

- cmake Ninja, gcc-15 (for #include <bits/stdc++.h>)
```bash
cmake -S . -B build -G Ninja \
  -DCMAKE_C_COMPILER=$(brew --prefix)/bin/gcc-15 \
  -DCMAKE_CXX_COMPILER=$(brew --prefix)/bin/g++-15
  
cmake --build build  
```

- cmake Xcode
```bash
cmake -S . -B build -G Xcode \
  -DCMAKE_C_COMPILER=clang \
  -DCMAKE_CXX_COMPILER=clang++
```
  
