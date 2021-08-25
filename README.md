# Fast-exact-string-matching-algorithms
A very fast new family of string matching algorithms based on hashing q-grams.

# Abstract
String matching is the problem of finding all the occurrences of a pattern in a text. We propose a very fast new family of string
matching algorithms based on hashing q-grams. The new algorithms are the fastest on many cases, in particular, on small size
alphabets.

# The new algorithm
In this project the researcher has presented an adaptation of the Wu
and Manber multiple string matching algorithm to sin-
gle string matching algorithm. He has proposed then very
efficient implementations of this algorithm that in many
cases are much faster than the previous known fastest
string matching algorithms.


# Preprocessing Phase

The idea of the new algorithm is to consider sub-
strings of length q. Substrings B of such a length are
hashed using a function h into integer values within 0
and 255.

# Searching Phase

The searching phase of the algorithm consists in
reading substrings B of length q. If shift[h(B)] > 0
then a shift of length shift[h(B)] is applied. Otherwise,
when shift[h(B)] = 0 the pattern x is naively checked
in the text. In this case a shift of length sh is applied where sh = m − 1 − i with i = max{0 <= j <= m − q |
h(x[j..j + q − 1]) = h(x[m − q + 1..m − 1]}.

# Experimental results
The new algorithms are very
fast for short patterns on small size alphabets compar-
ing to the well known fast algorithms using bitwise
techniques. The new algorithms are also fast on long
patterns (length 32 to 256) comparing to algorithms us-
ing an indexing structure for the reverse pattern (namely
the Backward Oracle Matching algorithm). This new
type of algorithm can serve as filters for finding seeds
when computing approximate string matching.

## Screenshots of experimental results

