##### reader-and-writer-problem-without-starvation
 Introduction:-
Suppose we have a database on file which is shared by multiple processes(threads) and some of processes want to access it ,that is read the database but some of the processes at same time (concurrently) want to change some values in that data base ie they want to write onto that files.

---js

int rc = 0; // reader count
 boolean writing=false; // weather the process is busy with writing
 int waitingWriters = 0; // number of processes which are waiting for write 
 boolean readersTurn = false;
Semaphore s=0;// binary semaphore for readers
Semaphore w=0;// binary semaphore for writers

---
