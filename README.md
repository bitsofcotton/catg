# bitsofcotton/catg
Categorize series of inputs into svd unitary matrices.

# Contexts
There exists support vector machine and so on to categorize vector series.  
So this is another categorizer on vector series to make them into operator.  
(I didn't searched well, so might be preceding results exist.)

# How to use
    SimpleVector<double> ins(/* some size */);
    CatG<double> catg(ins.size());
    ...
      // multiple loop of ins operations.
      catg.inq(ins);
      // or we can use: catg.inqRecur(ins);
    catg.compute(); // we get : catg.cut, catg.origin, catg.distance, catg.cat.
                    //   catg.cat : catg.cat.Left, catg.cat.lambda.
                    // we can use: catg.lmrRecur(ins);

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
