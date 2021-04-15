# bitsofcotton/catg
Categorize series of inputs into rough QR unitary matrices.

# Contexts
There exists support vector machine and so on to categorize vector series.  
So this is another categorizer on vector series. (I didn't searched well, so might be preceding results exist.)

# How to use
    std::vector<SimpleVector<double> > in;
    ...
      // multiple loop of ins operations.
      in.emplace_back(SimpleVector<double>(/* some size */));
      // in[in.size() - 1] operations.
    const auto cg(crush<double>(in, /* some size */,
      /* is no align */,
      /* cut intensity (<0 for adjust ratio first result) */,
      /* maximum count on result */,
      /* complexity */);
    // cg[/* index */].first.first  : learned vector itself.
    // cg[/* index */].first.second : vector pair (align, index).
    // cg[/* index */].second : learned manner.
    
# How to use (commandline)
    ./catg <status dimension> <cut intensity> < data.txt

# Description
From #{a_k subset R^n} == m, with below, this catg learns {a_1, ..., a_m} habit on e_k's importance manner.

If there exists pre-categorized groups, this learns their habit and (R^{-1} v) is stable for their importance
if original {a_k} has a habit.

Otherwise, we should solve max_(n,t) min_k|A^t\*n+1\*t|\_k / ||\[n t\]|| multiple times to crack category.

# Tips
This catg only depends input dimension order and block condition.
We can avoid block condition with sliding bits, but we can't avoid non same block
size condition without some other algorithms nor hypothesis.

# Another Download Sites
* https://drive.google.com/drive/folders/1B71X1BMttL6yyi76REeOTNRrpopO8EAR?usp=sharing
* https://1drv.ms/u/s!AnqkwcwMjB_PaDIfXya_M3-aLXw?e=qzfKcU
* https://ja.osdn.net/users/bitsofcotton/

# Archive
This repository is archived, so without bugreport, will no change.

