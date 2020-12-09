# bitsofcotton/catg
Categorize series of inputs into svd unitary matrices.

# Contexts
There exists support vector machine and so on to categorize vector series.  
So this is another categorizer on vector series to make them into operator.
(I didn't searched well, so might be preceding results exists.)

# How to use
    SimpleVector<double> ins(/* some size */);
    Catg<double> cat(ins.size());
    ...
      // multiple loop of ins operations.
      cat.inq(ins);
    cat.compute();
    // we get : cat.Left, cat.lambda.

# How to use (commandline)
    ./catg <range> < data.txt

# Description
If there's a series of the vector {a_1,...,a_n}, SVD can decompose them into left and right unitary matrix.
Right is unitary means each dimension's importance is depends on abs(&lambda;\_k).
Each Left unitary matrix column vector means each important vector in linear space.

# General Description
With below, this catg learns {a_1, ..., a_n} habit on e_k's importance manner.
If there exists pre-categorized groups, this learns their habit and (Left^t v) is stable for their importance
if original {a_k} has a habit.
Otherwise, (Left^t v) means whole {a_k} habits on their e_k, so we should categorize them with the patterns on their axises.
To do so, re calculate {a_k} with Left matrix, categorize on the distribution on axises, so this depends on {a_k'} categorizer.
(If we categorize them only in each axises, the result can be huge enough. But in linear categorize (no nonlinear factors),
 we only need to place hyperplanes on {a_k'} to make max distance on the groups.)

# Known bug
If input is sparse enough on rank, result will be NaN because of rough QR and lambda == 0.
