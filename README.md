# bitsofcotton/catg
Categorize series of inputs into svd unitary matrices.

# How to use
    SimpleVector<double> ins(/* some size */);
    Catg<double> cat(ins.size());
    ...
      // multiple loop of ins operations.
      cat.inq(ins);
    cat.compute();
    // we get : cat.Left, cat.lambda, cat.Right.

# How to use (commandline)
    ./catg <range> < data.txt

# Description
If there's a series of the vector {a_1,...,a_n}, SVD can decompose them into left and right unitary matrix.
So we can use right unitary matrix to categorize input, also left and singular values to categorize output.

# Known bug
If input is sparse enough on rank, result will be NaN because of rough QR and lambda == 0.

# Tips
This program needs huge amounts of data.
If we complement data series with few amounts, we might use p0 and their limit.
