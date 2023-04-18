# Data-Processing
given a "garbage" text file containing a piece of data on each line. It is possible that each of these lines could
be interpreted as several different data types, so we will need to establish a precedence for the types. Each
line will be given the following priority with regards to types: int > char > double > bool > string,
where int has the highest priority and string has the lowest priority. To organize these various pieces of data, we will place them into a big collection of data and then sort our way through it. This will involve reading the data, determining the type, and then placing it into proper order. The
collection will be represented here as a series of doubly linked nodes, with each node containing a single piece of
data. After throwing everything into the collection pile, we will sort all of the data first by its type, and then
by the standard sorting implementation for that type. 
