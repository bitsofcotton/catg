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
  CatG<num_t>         cat(v.size());
  int t(0);
  while(std::getline(std::cin, s, '\n')) {
    std::stringstream ins(s);
    ins >> v[t % v.size()];
    if(! ((t ++) % v.size()) && t)
      cat.inq(dec.next(v));
  }
  cat.compute();
  std::cout << "Distance: " << cat.distance << std::endl;
  std::cout << "Cut: " << std::endl;
  for(int i = 0; i < cat.cut.size(); i ++)
    std::cout << cat.cut[i] << "\t";
  std::cout << std::endl;
  Catg<num_t> c0(v.size());
  int  t0(0);
  auto c1(c0);
  auto t1(t0);
  for(int i = 0; i < cat.cache.size(); i ++) {
    if(cat.cache[i].dot(cat.cut) < num_t(0)) {
      c0.inq(cat.cache[i]);
      t0 ++;
    } else {
      c1.inq(cat.cache[i]);
      t1 ++;
    }
  }
  std::cout << "Pair: (" << t0 << ", " << t1 << ")" << std::endl;
  c0.compute();
  std::cout << "Output0 (" << c0.Left.rows() << ", " << c0.Left.cols() << "): " << std::endl;
  for(int i = 0; i < c0.Left.rows(); i ++) {
    for(int j = 0; j < c0.Left.cols(); j ++)
      std::cout << c0.Left(i, j) << "\t";
    std::cout << std::endl;
  }
  std::cout << "Intensity0 (" << c0.lambda.size() << "): " << std::endl;
  for(int i = 0; i < c0.lambda.size(); i ++)
    std::cout << c0.lambda[i] << "\t";
  c1.compute();
  std::cout << "Output1 (" << c1.Left.rows() << ", " << c1.Left.cols() << "): " << std::endl;
  for(int i = 0; i < c1.Left.rows(); i ++) {
    for(int j = 0; j < c1.Left.cols(); j ++)
      std::cout << c1.Left(i, j) << "\t";
    std::cout << std::endl;
  }
  std::cout << "Intensity1 (" << c1.lambda.size() << "): " << std::endl;
  for(int i = 0; i < c1.lambda.size(); i ++)
    std::cout << c1.lambda[i] << "\t";
  return 0;
}

