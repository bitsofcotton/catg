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
    # count == - 1 for each sorted divide, divide to sqrt(num).
    # count == 0 for divide to sqrt(num).
    # count >= 1 for divide at most count parts.

# Description
We solve max_(n,t) min_k|A^t\*n+1\*t|\_k / ||\[n t\]|| multiple times on invariant of makeProgramInvariant.

# Tips on XXX
We categorize by multiple of the meaning on input stream or by complexity of input calculation. So if input stream can be described by f(x) g(x) == 0, it's not separatable by this catg program. In such case, we need to separate by multiple of p1 copy structure then, we need simple NAND gate program factorization.

# Tips on XXX (2)
We treat all input dimension as meaningful.
So if it's not so, the no bias causes orthogonal to categorize.

# Another Download Sites
* https://drive.google.com/drive/folders/1B71X1BMttL6yyi76REeOTNRrpopO8EAR?usp=sharing
* https://1drv.ms/u/s!AnqkwcwMjB_PaDIfXya_M3-aLXw?e=qzfKcU
* https://ja.osdn.net/users/bitsofcotton/

# Real close
2023/03/13 try to real close.
2023/03/24 code clean.
2023/03/31 merge prand.
2023/04/02 fix CatG::CatG score calculation.
2023/04/03 merge.
2023/04/05 fix makeProgramInvariant scale accuracy stability.
2023/04/21 shapeup around make/revert ProgramInvariant, algorthm changed.
2023/08/02 crush to the last.
2023/10/30 copy structure reliably with randtools meaning.
2023/11/15 update readme. close.
2024/09/28 merge latest lieonn.
2025/07/04 merge latest lieonn causes categorize strategy change.
2025/07/06 merge latest lieonn.

