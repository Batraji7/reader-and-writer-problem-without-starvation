 Database {

 int rc = 0; // reader count
 boolean writing=false; // weather the process is busy with writing
 int waitingWriters = 0; // number of processes which are waiting for write 
 boolean readersTurn = false;
Semaphore s=0;// binary semaphore for readers
Semaphore w=0;// binary semaphore for writers

// entry section for readers

startRead(){ 

if(writing || waitingWriters > 0 && !readersTurn){
    wait(s);
    wait(s);
}
else{
    ++rc;
}

// DATA BASE ie. CRITICAL SECTION

 readOver(){ //exit section for readers

--rc;
 readersTurn = false;
  if(rc == 0){
    
    signal(s);
    wait(s);
      } 
   }
}

//entry section for writers

 startWrite(){
    if(rc > 0 || writing){
++waitingWriters; 
wait(w);
wait(w);
 }

 // DATA BASE ie. CRITICAL SECTION

--waitingWriters;
 writing = true;

 writeOver(){ //exit section for writers

writing = false;
 readersTurn = true;
 
  signal(w);
    wait(w);
      
      }
   }
}
