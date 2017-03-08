/* InformativeAssert.hpp
 *
 * Author: Mattias Tiger, 2017 
 * * * * * * * * * * * * * * * */

#include <iostream>
#include <stdlib.h>

#ifndef NDEBUG
  #define AssertM(Expr, Msg) \
    if (!(Expr)) {\
      std::cerr << "Assert failed:\t" << Msg << "\n"\
                << "Expected:\t" << #Expr << "\n"\
                << "Source:\t\t" << __FILE__\
                << ", line " << __LINE__ << "\n";\
      abort();\
    }
#else
  #define AssertM(Expr, Msg) ;
#endif

