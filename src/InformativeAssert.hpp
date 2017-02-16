#include <iostream>

/* Source: Stack Overflow */

#ifndef NDEBUG
#   define AssertM(Expr, Msg) \
    __AssertM(#Expr, Expr, __FILE__, __LINE__, Msg)
#else
#   define M_Assert(Expr, Msg) ;
#endif

void __AssertM(char* expr_str, bool expr,  char* file, int line, char* msg)
{
    if (!expr)
    {
        std::cerr << "Assert failed:\t" << msg << "\n"
            << "Expected:\t" << expr_str << "\n"
            << "Source:\t\t" << file << ", line " << line << "\n";
        abort();
    }
}

