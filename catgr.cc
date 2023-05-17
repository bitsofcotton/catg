#include <cstdio>
#include <cstring>
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <map>
#include <iomanip>
#include <algorithm>
#include <assert.h>

#if defined(_FLOAT_BITS_)
#define int int64_t
#endif
#include "lieonn.hh"
typedef myfloat num_t;

#if defined(_FLOAT_BITS_)
#undef int
#endif
int main(int argc, const char* argv[]) {
#if defined(_FLOAT_BITS_)
#define int int64_t
#endif
  std::cout << std::setprecision(30);
  std::string s;
  int  slen(6);
  int  count(0);
  if(argc < 2)
    std::cerr << "catgr <status dimension>? <divide count>?" << std::endl;
  else {
    if(1 < argc) slen  = std::atoi(argv[1]);
    slen = slen < 0 ? - min(int(6), - slen) : min(int(6), slen);
    if(2 < argc) count = std::atoi(argv[2]);
  }
  std::cerr << "continue with catgr " << slen << " " << count << std::endl;
  std::vector<SimpleVector<num_t> > v;
  SimpleVector<num_t> buf(abs(slen));
  int t(0);
  while(std::getline(std::cin, s, '\n')) {
    std::stringstream ins(s);
    ins >> buf[(t ++) % buf.size()];
    if(! (t % buf.size()) )
      v.emplace_back(SimpleVector<num_t>(buf));
  }
  auto cg(crush<num_t>(v, slen, count));
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
      // std::cout << (avg / num_t(cg[t].first.size()));
      std::cout << (avg / sqrt(avg.dot(avg)));
    }
    for(int j = 0; j < cg[t].second.size(); j ++)
      std::cout << cg[t].second[j] << " ";
    std::cout << std::endl << std::endl;
  }
  return 0;
}

