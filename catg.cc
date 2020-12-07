#include <cstdio>
#include <cstring>
#include <iostream>
#include <sstream>
#include <vector>
#include <iomanip>
#include <assert.h>

#if !defined(_FLOAT_BITS_)
  #include <complex>
  #include <cmath>
  using namespace std;
  typedef long double num_t;
#else
  #include "ifloat.hh"
  template <typename T> using complex = Complex<T>;
# if _FLOAT_BITS_ == 8
    typedef uint8_t myuint;
    typedef int8_t  myint;
    typedef SimpleFloat<myuint, uint16_t, 8, int64_t> num_t;
    #define mybits 8
# elif _FLOAT_BITS_ == 16
    typedef uint16_t myuint;
    typedef int16_t  myint;
    typedef SimpleFloat<myuint, uint32_t, 16, int64_t> num_t;
    #define mybits 16
# elif _FLOAT_BITS_ == 32
    typedef uint32_t myuint;
    typedef int32_t  myint;
    typedef SimpleFloat<myuint, uint64_t, 32, int64_t> num_t;
    #define mybits 32
# elif _FLOAT_BITS_ == 64
    typedef uint64_t myuint;
    typedef int64_t  myint;
    typedef SimpleFloat<myuint, DUInt<myuint, 64>, 64, int64_t> num_t;
    #define mybits 64
# elif _FLOAT_BITS_ == 128
    typedef DUInt<uint64_t, 64> uint128_t;
    typedef Signed<uint128_t, 128> int128_t;
    typedef uint128_t myuint;
    typedef int128_t  myint;
    typedef SimpleFloat<myuint, DUInt<myuint, 128>, 128, int64_t> num_t;
    #define mybits 128
# elif _FLOAT_BITS_ == 256
    typedef DUInt<uint64_t, 64> uint128_t;
    typedef DUInt<uint128_t, 128> uint256_t;
    typedef Signed<uint256_t, 128> int256_t;
    typedef uint256_t myuint;
    typedef int256_t  myint;
    typedef SimpleFloat<myuint, DUInt<myuint, 256>, 256, int64_t> num_t;
    #define mybits 256
# else
#   error cannot handle float
# endif
#endif

#include "simplelin.hh"
#include "p0.hh"
#include "decompose.hh"
#include "catg.hh"

int main(int argc, const char* argv[]) {
  std::cout << std::setprecision(30);
  std::string s;
  int range(20);
  if(1 < argc)
    range = std::atoi(argv[1]);
  SimpleVector<num_t> v(range);
  Decompose<num_t>    dec(v.size());
  Catg<num_t>         cat(v.size());
  int t(0);
  while(std::getline(std::cin, s, '\n')) {
    std::stringstream ins(s);
    ins >> v[t % v.size()];
    if(! ((t ++) % v.size()) && t)
      cat.inq(dec.next(v));
  }
  cat.compute();
  std::cout << "Output(" << cat.Left.rows() << ", " << cat.Left.cols() << "): " << std::endl;
  for(int i = 0; i < cat.Left.rows(); i ++) {
    for(int j = 0; j < cat.Left.cols(); j ++)
      std::cout << cat.Left(i, j) << "\t";
    std::cout << std::endl;
  }
  std::cout << "Intensity(" << cat.lambda.size() << "): " << std::endl;
  for(int i = 0; i < cat.lambda.size(); i ++)
    std::cout << cat.lambda[i] << "\t";
  return 0;
}

