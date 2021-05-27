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
    const auto cg(crush<double>(in,
      /* some size (<0 for pairwise left part) */,
      /* is no align */, /* count of blocks? */));
    // cg[/* index */].first  : separated vector itself.
    // cg[/* index */].second : vector pair (align, index).
    const auto cc(crushWithOrder<double>(std::vector<double>(...),
      /* some size (<0 for pairwise left part) */,
      /* count of blocks? (<0 for each sorted) */));
    // cc[/* index */].first  : divided vector itself.
    // cc[/* index */].second : divided vector indices.

# How to use (commandline)
    ./catg <status dimension> <count> < data.txt
    # status dimension < 0 for pairwise divide left part.
    # count <  - 1 for each sorted divide.
    # count == - 1 for each sorted divide, divide to last one.
    # count == 0 for divide to last one.

# Description
We solve max_(n,t) min_k|A^t\*n+1\*t|\_k / ||\[n t\]|| multiple times on invariant of makeProgramInvariant.

# Another Download Sites
* https://drive.google.com/drive/folders/1B71X1BMttL6yyi76REeOTNRrpopO8EAR?usp=sharing
* https://1drv.ms/u/s!AnqkwcwMjB_PaDIfXya_M3-aLXw?e=qzfKcU
* https://ja.osdn.net/users/bitsofcotton/
