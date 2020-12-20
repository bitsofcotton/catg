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
    catg.compute(); // we get : catg.cut, catg.origin, catg.distance, catg.cat.
                    //   catg.cat : catg.cat.Left, catg.cat.lambda.

# How to use (commandline)
    ./catg <range> < data.txt

# Description
From #{a_k subset R^n} == m, with below, this catg learns {a_1, ..., a_m} habit on e_k's importance manner.
If there exists pre-categorized groups, this learns their habit and (Left^t v) is stable for their importance
if original {a_k} has a habit. This is done by O(mn + n^3)

Otherwise, we should solve max_(n)min_k|A^t\*n\*(1+n_0)|\_k multiple times to crack category.
This is done by O(mn^2 + n^3) with SVD and configured Linner.

This returns both specific value vector and GAN trained vector if categorize is better.

# Known bug
If input is sparse enough on rank, it describes better to get vectors on this, but result will be NaN because of rough QR and lambda == 0.

# Tips
If we want some clusters larger than t items, it costs at most O(t\*m\*n^2+t\*n^3) because we eliminate one by one.

# General Tips
If the items we have isn't clean data enough, the vector we take is meaning-less.

# General Tips 2
The context we input into catg is important enough because of sparsity of the problem depends and dimension we need depends data stream size itself.
