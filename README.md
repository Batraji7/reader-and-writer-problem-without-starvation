##### reader-and-writer-problem-without-starvation
 Introduction:-
Suppose we have a database on file which is shared by multiple processes(threads) and some of processes want to access it ,that is read the database but some of the processes at same time (concurrently) want to change some values in that data base ie they want to write onto that files.

Starvation is caused by when the reader after reader make read on database and writer did'nt get a chance to write on database.

case 1 reader and writer
when reader execute the startRead function the rc (readcount) gets incremented and it reach to the database(critical section).
As reader is in the critical section ie in the database so when the other processes wants to write onto data base it cannot as rc==1 making that writer in waiting list.
 
 ```js
 if(rc(true as one writer is in CS;rc=1) > 0 || writing(false as no writer in CS)){
++waitingWriters; 
wait(w);
 }
```

case 2 witer and writer
when one writer is in the database and the writing value will get equal to true(writing=true) So when the other writer enters startWrite() it will get blocked.
 
 ```js
 if(rc(false as no reader in CS) > 0 || writing(true as one writer is in CS)){
++waitingWriters; 
wait(w);
 }
```
