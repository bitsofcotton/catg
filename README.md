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
    const auto cg(crushNoContext<double>(in, /* some size */, /* cut intensity */));
    // cg[/* index */].first[/* index */].first.first  : learned vector itself.
    // cg[/* index */].first[/* index */].first.second : dimension shift number.
    // cg[/* index */].first[/* index */].second : in[/* here */].
    // cg[/* index */].second : Catg<double> learned manner.
    //
    const auto g(crush<double>(in, /* some size */, /* cut intensity */));
    // g[/* index */].first[/* index */].first  : learned vector itself.
    // g[/* index */].first[/* index */].second : in[/* here */].
    // g[/* index */].second : Catg<double> learned manner.
    //
    // Catg<double> has catg.R
    // if cut intensity < 0, it's adjusted to first crush result ratio with abs(cut intensity).

# How to use (commandline)
    ./catg <status dimension> <vector block size> < data.txt

# Description
From #{a_k subset R^n} == m, with below, this catg learns {a_1, ..., a_m} habit on e_k's importance manner.

If there exists pre-categorized groups, this learns their habit and (R^{-1} v) is stable for their importance
if original {a_k} has a habit.

Otherwise, we should solve max_(n) exists n_0 min_k|A^t\*n+1\*n_0|\_k / ||n|| multiple times to crack category.
(once |A^t\*n+1\*n_0|\_k into Linner solves vector, from somehow, n_0 can be scaled as the same vector n.)

# Known bug
If input is sparse enough on rank, it describes better to get vectors on this, but result will be NaN because of rough QR and det(R) == 0.
This shouldn't happen if no context option is supposed (recur option).

If the items we have isn't clean data enough, the vector we take has mis-separated vectors.

# Tips
This catg only depends input dimension order and block condition. We can't avoid block condition without some other algorithms nor hypothesis.

# Another Download Sites
* https://drive.google.com/drive/folders/1B71X1BMttL6yyi76REeOTNRrpopO8EAR?usp=sharing
* https://1drv.ms/u/s!AnqkwcwMjB_PaDIfXya_M3-aLXw?e=qzfKcU
* https://ja.osdn.net/users/bitsofcotton/

# Archive
This repository is archived, so without bugreport, will no change.
