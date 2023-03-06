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
    wait(s); // blockes the read process
}
else{
    ++rc;
}

// DATA BASE ie. CRITICAL SECTION

 readOver(){ //exit section for readers

--rc;
 readersTurn = false;
  if(rc == 0){
    
wakeup();  // wake up blocked processes
      } 
   }
}

//entry section for writers

 startWrite(){
    if(rc > 0 || writing){
++waitingWriters; 
wait(w); // blockes the write process

 }

--waitingWriters;
 writing = true;
 
  // DATA BASE ie. CRITICAL SECTION
 
  writeOver(){ //exit section for writers

writing = false;
 readersTurn = true;
 
  wakeup(); // wake up blocked processes
   
      }
   }
}
