##### reader-and-writer-problem-without-starvation
 Introduction:-
Suppose we have a database on file which is shared by multiple processes(threads) and some of processes want to access it ,that is read the database but some of the processes at same time (concurrently) want to change some values in that data base ie they want to write onto that files.

Starvation is caused by when the reader after reader make read on database and writer did'nt get a chance to write on database.

case 1:- reader and then writer=
when reader execute the startRead function the rc (readcount) gets incremented and it reach to the database(critical section).
As reader is in the critical section ie in the database so when the other processes wants to write onto data base it cannot as rc==1 making that writer in waiting list.
 
 ```js
 if(rc(true as one writer is in CS;rc=1) > 0 || writing(false as no writer in CS)){
++waitingWriters; 
wait(w);
 }
```

case 2:- writer1 and then writer2=
when writer1 is in the database and the writing value will get equal to true(writing=true) So when the writer2 enters startWrite() it will get blocked.
 
 ```js
 if(rc(false as no reader in CS) > 0 || writing(true as one writer is in CS)){
++waitingWriters; 
wait(w);
 }
```
case 3:- writer and then reader= writing value becomes true when writer goes into the critical section and reader will get into block list.
 ```js
--waitingWriters;
 writing = true;

// DATA BASE ie. CRITICAL SECTION
```
```js
public void startRead(){ 

if(writing(==true) || waitingWriters > 0 && !readersTurn){
    wait(s);
}
```
case 4:- reader1 and then reader2 (STARVATION PREVENTION)=
after the execution of read function by the reader1, the reader2 cannot enter the critical section until the writer is in the waiting section ie, waitingWriters>0 and readersTurn is equal to false. 
```js
if(writing || waitingWriters > 0(true) && !readersTurn(!false)){
    wait(s);
}
```
