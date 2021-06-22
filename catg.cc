#include <cstdio>
#include <cstring>
#include <iostream>
#include <sstream>
#include <vector>
#include <map>
#include <iomanip>
#include <assert.h>

#if defined(_FLOAT_BITS_)
#define int int64_t
#endif
#include "lieonn.hh"
typedef myfloat num_t;
#include "decompose.hh"
#include "catg.hh"

#if defined(_FLOAT_BITS_)
#undef int
#endif
int main(int argc, const char* argv[]) {
#if defined(_FLOAT_BITS_)
#define int int64_t
#endif
  std::cout << std::setprecision(30);
  std::string s;
  int  slen(8);
  int  count(0);
  if(argc < 2)
    std::cerr << "catg <status dimension>? <divide count>?" << std::endl;
  else {
    if(1 < argc) slen  = std::atoi(argv[1]);
    if(2 < argc) count = std::atoi(argv[2]);
  }
  std::cerr << "continue with catg " << slen << " " << count << std::endl;
  std::vector<num_t> v;
  int t(0);
  while(std::getline(std::cin, s, '\n')) {
    std::stringstream ins(s);
    v.emplace_back(num_t(0));
    ins >> v[v.size() - 1];
  }
  auto cg(crushWithOrder<num_t>(v, slen, count));
  std::cout << cg.size() << "pairs." << std::endl;
  CatG<num_t> catg;
  for(int t = 0; t < cg.size(); t ++) {
    std::sort(cg[t].second.begin(), cg[t].second.end());
    cg[t].second.erase(std::unique(cg[t].second.begin(), cg[t].second.end()), cg[t].second.end());
    std::cout << cg[t].first.size() << " : " << std::endl;
    if(cg[t].first.size()) {
      auto avg(catg.tayl(abs(slen), cg[t].first[0].size()) * cg[t].first[0]);
      for(int j = 1; j < cg[t].first.size(); j ++)
        avg += catg.tayl(abs(slen), cg[t].first[j].size()) * cg[t].first[j];
      std::cout << (avg / num_t(cg[t].first.size()));
    }
    for(int j = 0; j < cg[t].second.size(); j ++)
      std::cout << cg[t].second[j] << " ";
    std::cout << std::endl << std::endl;
  }
  return 0;
}

