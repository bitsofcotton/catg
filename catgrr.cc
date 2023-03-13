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
  int  slen(8);
  int  count(0);
  if(argc < 2)
    std::cerr << "catgr <status dimension>? <divide count>? <block shown>?" << std::endl;
  else {
    if(1 < argc) slen  = std::atoi(argv[1]);
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
  CatG<num_t> catg;
  t = std::atoi(argv[3]);
  for(int i = 0; i < cg[t].first.size(); i ++) {
    for(int j = 0; j < cg[t].first[i].size(); j ++)
      std::cout << cg[t].first[i][j] << ", ";
    std::cout << std::endl;
  }
  return 0;
}

