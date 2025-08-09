 # Algorithm Learning

 学一些日常算法，万一哪天用上呢

 ## 构建方式

 ### （不推荐）原生 Xcode
 直接打开：
 algorithm.xcodeproj
 选择目标并运行即可。 不过得自己配置gtest啥的 很麻烦
 
 ---

 ### VSCode (推荐) CMake + Ninja + GCC 15
 ```shell
 cmake -S . -B build -G Ninja \
  -DCMAKE_BUILD_TYPE=Debug \
  -DCMAKE_C_COMPILER=$(brew --prefix)/bin/gcc-15 \
  -DCMAKE_CXX_COMPILER=$(brew --prefix)/bin/g++-15
 cmake --build build
 ```

 ---

 ### （Mac OS）CMake + Xcode
  ```shell
 cmake -S . -B build -G Xcode \
   -DCMAKE_C_COMPILER=clang \
   -DCMAKE_CXX_COMPILER=clang++
 open build/algorithm.xcodeproj
  ```

 ---

 ## 依赖？
 - C++20+
 - CMake 3.16+
 - Ninja（可选）
 - GCC 15（方式二）

 ## License
 MIT
  
