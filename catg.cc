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
  std::vector<std::vector<SimpleVector<num_t> > > va;
  va.resize(1, std::vector<SimpleVector<num_t> >());
  int t(0);
  while(std::getline(std::cin, s, '\n')) {
    std::stringstream ins(s);
    ins >> v[t % v.size()];
    if(! ((t ++) % v.size()) && t)
      va[0].emplace_back(dec.next(v));
  }
  t = 0;
  num_t Mdist(0);
  while(t < va.size()) {
    CatG<num_t> cat(v.size());
    for(int i = 0; i < va[t].size(); i ++)
      cat.inq(va[t][i]);
    std::cerr << "." << std::flush;
    cat.compute();
    if(! t && Mdist == num_t(0)) {
      Mdist = cat.distance;
      std::cout << "Distance: " << Mdist << std::endl;
    }
    if(Mdist <= cat.distance) {
      std::cout << "Cut (" << t << ", " << cat.distance << ")" << std::endl;
      for(int i = 0; i < cat.cut.size(); i ++)
        std::cout << cat.cut[i] << "\t";
      std::cout << std::endl;
      std::vector<SimpleVector<num_t> > left;
      std::vector<SimpleVector<num_t> > right;
      for(int i = 0; i < va[t].size(); i ++)
        if(va[t][i].dot(cat.cut) < cat.origin)
          left.emplace_back(va[t][i]);
        else
          right.emplace_back(va[t][i]);
      if(left.size() && right.size()) {
        va[t] = left;
        va.emplace_back(right);
      } else
        t ++;
    } else
      t ++;
  }
  for(int i = 0; i < va.size(); i ++) {
    Catg<num_t> c(v.size());
    std::cout << "Pair(" << va[i].size() << ")" << std::endl;
    for(int j = 0; j < va[i].size(); j ++)
      c.inq(va[i][j]);
    c.compute();
    std::cout << "Output" << std::endl;
    for(int i = 0; i < c.Left.rows(); i ++) {
      for(int j = 0; j < c.Left.cols(); j ++)
        std::cout << c.Left(i, j) << "\t";
    }
    std::cout << std::endl << "Intensity" << std::endl;
    for(int i = 0; i < c.lambda.size(); i ++)
      std::cout << c.lambda[i] << "\t";
     std::cout << std::endl;
  }
  return 0;
}

