# bitsofcotton/catg
Categorize series of inputs into rough QR unitary matrices.

# Contexts
There exists support vector machine and so on to categorize vector series.  
So this is another categorizer on vector series. (I didn't searched well, so might be preceding results exist.)

# How to use
    const auto cg(crush<double>(std::vector<SimpleVector<double> >(...),
     or we can do:crushWithOrder<double>(std::vector<double>(...),
      /* some status size (see below) */,
      /* count of blocks? (see below) */));
    // cg[/* index */].first  : divided vector itself.
    // cg[/* index */].second : divided vector indices.

# How to use (commandline)
    ./catg <status dimension> <count> < data.txt
    # status dimension < 0 for pairwise divide left part.
    # count <  - 1 for each sorted divide.
    # count == - 1 for each sorted divide, divide to last one.
    # count == 0 for divide to last one.

# Description
We solve max_(n,t) min_k|A^t\*n+1\*t|\_k / ||\[n t\]|| multiple times on invariant of makeProgramInvariant.

# Tips (XXX)
If there's a unnecessary mini block on crushed parts, we can try them with vanishing to 0 each mini block and concat some block and test them if causes large block can validated. This isn't implemented to this.

# Another Download Sites
* https://drive.google.com/drive/folders/1B71X1BMttL6yyi76REeOTNRrpopO8EAR?usp=sharing
* https://1drv.ms/u/s!AnqkwcwMjB_PaDIfXya_M3-aLXw?e=qzfKcU
* https://ja.osdn.net/users/bitsofcotton/

