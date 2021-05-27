#include <cstdio>
#include <cstring>
#include <iostream>
#include <sstream>
#include <vector>
#include <map>
#include <iomanip>
#include <assert.h>

#include "lieonn.hh"
typedef myfloat num_t;
#include <cmath>
using std::sqrt;
#include "decompose.hh"
#include "catg.hh"

int main(int argc, const char* argv[]) {
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

