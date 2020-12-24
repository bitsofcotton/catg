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
    const auto cg(crushNoContext<double>(in, /* some size */));
    // cg[/* index */].first[/* index */].first.first  : learned vector itself.
    // cg[/* index */].first[/* index */].first.second : dimension shift number.
    // cg[/* index */].first[/* index */].second : in[/* here */].
    // cg[/* index */].second : Catg<double> learned manner.
    // Catg<double> has catg.Left, catg.R

# How to use (commandline)
    ./catg <range> < data.txt

# Description
From #{a_k subset R^n} == m, with below, this catg learns {a_1, ..., a_m} habit on e_k's importance manner.

If there exists pre-categorized groups, this learns their habit and (Left^t v) is stable for their importance
if original {a_k} has a habit.

Otherwise, we should solve max_(n) exists n_0 min_k|A^t\*n+1\*n_0|\_k / ||n|| multiple times to crack category.
(once |A^t\*n+1\*n_0|\_k into Linner solves vector, from somehow, n_0 can be scaled as the same vector n.)

# Known bug
If input is sparse enough on rank, it describes better to get vectors on this, but result will be NaN because of rough QR and det(R) == 0.
This shouldn't happen if no context option is supposed (recur option).

If the items we have isn't clean data enough, the vector we take has mis-separated vectors.

# Tips
This catg only depends input dimension order and block, or, if the same dimension we have all, block condition.

If we don't have separated input (no block condition), sorting can make one of the result that we suppose structure that we can't easily find in raw.

Otherwise, converting stream into randtools format with a\_{k+1}=A\_k\*2^(a\_k) on each dimensions and if we are lucky, A is block diagonal,
we can separate conditions, but, their condition is too huge to solve over 16 bit width on modern PCs.
