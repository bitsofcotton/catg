#include <cstdio>
#include <cstring>
#include <iostream>
#include <sstream>
#include <vector>
#include <map>
#include <iomanip>
#include <assert.h>

#include "ifloat.hh"
typedef myfloat num_t;
#include "simplelin.hh"
#include "decompose.hh"
#include "catg.hh"

int main(int argc, const char* argv[]) {
  std::cout << std::setprecision(30);
  std::string s;
  int  slen(8);
  auto intensity(- num_t(1) / num_t(2));
  if(1 < argc)
    slen = std::atoi(argv[1]);
  if(2 < argc)
    // XXX atof:
    intensity = std::atof(argv[2]);
  SimpleVector<num_t> v(slen);
  std::vector<SimpleVector<num_t> > va;
  int t(0);
  while(std::getline(std::cin, s, '\n')) {
    std::stringstream ins(s);
    ins >> v[t % slen];
    if(! ((t ++) % slen) && 1 < t)
      va.emplace_back(v);
  }
  const auto cg(crush<num_t>(va, slen, ! true, intensity, - 1, 8));
  for(int t = 0; t < cg.size(); t ++) {
    std::cout << "Pair(" << cg[t].first.first.size() << ")" << ", R: " << std::endl;
    for(int i = 0; i < cg[t].second.rows(); i ++) {
      for(int j = 0; j < cg[t].second.cols(); j ++)
        std::cout << cg[t].second(i, j) << "\t";
      std::cout << std::endl;
    }
    std::cout << std::endl;
  }
  return 0;
}

