# Data-Processing
given a "garbage" text file containing a piece of data on each line. t is possible that each of these lines could
be interpreted as several different data types, so we will need to establish a precedence for the types. Each
line will be given the following priority with regards to types: int > char > double > bool > string,
where int has the highest priority and string has the lowest priority. To organize these various pieces of trash, we will place them into a big garbage pile and then sort our way through it. This will involve reading the data, determining the type, and then placing it into our pile. The
pile will be represented here as a series of doubly linked nodes, with each node containing a single piece of
garbage. After throwing everything into the pile, we will sort all of the garbage first by its type, and then
by the standard sorting implementation for that type. 
