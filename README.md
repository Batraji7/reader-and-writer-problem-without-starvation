##### reader-and-writer-problem-without-starvation
 Introduction:-
Suppose we have a database on file which is shared by multiple processes(threads) and some of processes want to access it ,that is read the database but some of the processes at same time (concurrently) want to change some values in that data base ie they want to write onto that files.

Starvation is caused by when the reader after reader make read on database and writer did'nt get a chance to write on database

variable defined--


