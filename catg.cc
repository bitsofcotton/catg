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
  int slen(8);
  int range(20);
  if(1 < argc)
    slen = std::atoi(argv[1]);
  if(2 < argc)
    range = std::atoi(argv[1]);
  SimpleVector<num_t> v(range * 2);
  Decompose<num_t>    dec(v.size());
  std::vector<SimpleVector<num_t> > va;
  int t(0);
  while(std::getline(std::cin, s, '\n')) {
    std::stringstream ins(s);
    ins >> v[t % range];
    if(! ((t ++) % range) && t) {
      for(int i = range; i < v.size(); i ++)
        v[i] = v[v.size() - i - 1];
      va.emplace_back(dec.next(v));
    }
  }
  const auto cg(crushNoContext<num_t>(va, slen));
  for(int t = 0; t < cg.size(); t ++) {
    std::cout << "Pair(" << cg[t].first.size() << ")" << std::endl;
    std::cout << "Output" << std::endl;
    for(int i = 0; i < cg[t].second.Left.rows(); i ++) {
      for(int j = 0; j < cg[t].second.Left.cols(); j ++)
        std::cout << cg[t].second.Left(i, j) << "\t";
      std::cout << std::endl;
    }
    std::cout << std::endl << "Intensity" << std::endl;
    for(int i = 0; i < cg[t].second.lambda.size(); i ++)
      std::cout << cg[t].second.lambda[i] << "\t";
    std::cout << std::endl;
  }
  return 0;
}

