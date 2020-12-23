# bitsofcotton/catg
Categorize series of inputs into svd unitary matrices.

# Contexts
There exists support vector machine and so on to categorize vector series.  
So this is another categorizer on vector series to make them into operator.  
(I didn't searched well, so might be preceding results exist.)

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
    // Catg<double> has catg.Left, catg.lambda

# How to use (commandline)
    ./catg <range> < data.txt

# Description
From #{a_k subset R^n} == m, with below, this catg learns {a_1, ..., a_m} habit on e_k's importance manner.

If there exists pre-categorized groups, this learns their habit and (Left^t v) is stable for their importance
if original {a_k} has a habit.

Otherwise, we should solve max_(n)min_k|A^t\*n\*(1+n_0)|\_k / ||n|| multiple times to crack category.

# Known bug
If input is sparse enough on rank, it describes better to get vectors on this, but result will be NaN because of rough QR and lambda == 0.
This don't happen if no context option is supposed (recur option).

# Tips
If we want some clusters larger than t items, it costs at most O(t\*m\*n^2+t\*n^3) because we eliminate one by one.  
Without this, if the items we have isn't clean data enough, the vector we taken is meaning-less.

# Tips
This only depends input dimension order and block, or, if same dimension, block condition.
If we don't have separated input, sorting can make one of the result that we suppose structure that we can't easily find in raw.
