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
