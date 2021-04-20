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
  std::vector<num_t> vv;
  int t(0);
  while(std::getline(std::cin, s, '\n')) {
    std::stringstream ins(s);
    vv.emplace_back(num_t(0));
    ins >> vv[vv.size() - 1];
  }
  auto cg(crushWithOrder<num_t>(vv, slen, intensity, - 1, 8));
  std::cout << cg.size() << "pairs." << std::endl;
  for(int t = 0; t < cg.size(); t ++) {
    std::sort(cg[t].second.begin(), cg[t].second.end());
    cg[t].second.erase(std::unique(cg[t].second.begin(), cg[t].second.end()), cg[t].second.end());
    std::cout << cg[t].first.size() << " : " << std::endl;
    for(int j = 0; j < cg[t].second.size(); j ++)
      std::cout << cg[t].second[j] << " ";
    std::cout << std::endl;
  }
  return 0;
}

