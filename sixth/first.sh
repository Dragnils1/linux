#!/bin/bash

cat <<EOF > conditional_compilation.cpp
#ifdef USE_GPU
  #ifdef USE_FLOAT
    std::cout << "Your code for USE_GPU and USE_FLOAT" << std::endl;
  #else
    std::cout << "Your code for USE_GPU" << std::endl;
  #endif
#else
  #ifdef USE_FLOAT
    std::cout << "Your code for USE_FLOAT" << std::endl;
  #else
    std::cout << "Your code without macros" << std::endl;
  #endif
#endif
EOF

# cat <<EOF > conditional_compilation.cpp
# #ifdef USE_GPU
#   #ifdef USE_FLOAT
#     #define VERSION_CODE "GPU with float"
#   #else
#     #define VERSION_CODE "GPU without float"
#   #endif
# #else
#   #ifdef USE_FLOAT
#     #define VERSION_CODE "CPU with float"
#   #else
#     #define VERSION_CODE "CPU without float"
#   #endif
# #endif

# int main() {
#     std::cout << "Version: " << VERSION_CODE << std::endl;
#     return 0;
# }
# EOF
#include <iostream>



# Компиляция и вывод препроцессированного кода
# g++ -E conditional_compilation.cpp
# g++ -E -DUSE_GPU -DUSE_FLOAT your_file.cpp
