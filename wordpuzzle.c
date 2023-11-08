#include<stdlib.h>
#include<stdio.h>
#include<string.h>
#include <pthread.h>
#include <time.h>
#include <unistd.h>

#define SBUFFER 10000000L //define the buffer size
#define FALSE 0
#define TRUE 1

//#define LEN 7
int LEN;
//int checkFlag
int flagForLength;
int flagForTime;
int flagForVerbose; 
long startBinaryTime;
long totalBinarySearchTime;

//currentIndexOfAllFoundWords;

pthread_mutex_t mutex;

int tokenizeArray[10000] = {8,9};//default string if option not used

//define THREADS 20;
int THREADS;

int dictionary_size;
char* dict[100000];
int countLength;
char* buffer[1000];

//do the binary search over the alphabetically sorted list of all english words
int binsearch(char* dictionaryWords[],int listSize,char* keyword){
  //printf("inside of the binsearch");
	int mid, low = 0, high = listSize - 1;
	while (high >= low) {
    //middle average of high and low
		mid = (high + low) / 2;
		if (strcmp(dictionaryWords[mid],keyword) < 0)
			low = mid + 1;
		else if (strcmp(dictionaryWords[mid],keyword)>0)
			high = mid - 1;
		else
			return mid;
	}
  //if -1 is returned then an error has occured 
	return -1; //not found
}

//get the nanos function
//this is for units in counting the seconds
//call this whenever i want to get the time
static long get_nanos(void) {
  //printf("inside of the get_nanos");
    struct timespec ts;
    timespec_get(&ts, TIME_UTC);
    //convert seconds to nano seconds, number 1 billion
	return (long)ts.tv_sec * 100000000L + ts.tv_nsec;
}

//piece everything together here
void* word_puzzle_solver(void* id){
  //printf("inside of the puzzle_solver");
  char c = 0;
  int i,j;
	char* buf = buffer[(int)id];
  if(flagForVerbose >0)
	fprintf(stderr, "Note: Thread #%d: %s\n", (int) id, "started!");//check
if(flagForLength==0){
  countLength = 2;
}
//n becomes buffer/threads -count length
//which is the number of characters
int n = SBUFFER/THREADS-countLength;
                                    
for(j=0;j<countLength;j++){
  LEN = tokenizeArray[j]; //the whole tokenized array is the length
  //keep going till i is greater than the number of words - length of words
  //so if the length is 8 and the array number of words is 8, unpause
	for(i = 0; i < n-LEN;i++){
		if(c)
			buf[i + LEN - 1] = c;
		c = buf[i + LEN];
		buf[i + LEN] = '\0';
    if(flagForTime){//lock
      pthread_mutex_lock(&mutex);
      startBinaryTime = get_nanos();//convert time to nanoseconds
      //printf("inside of flag for time");
		if(binsearch(dict, dictionary_size, buf + i) + 1){//if successful!
			printf("Note: Thread #%d: %s\n",(int)id, buf + i);
      //printf("inside of binsearch succesfull");
	}
  //binary start time becomes nanos - the start time
  startBinaryTime = get_nanos()-startBinaryTime; 
  totalBinarySearchTime += startBinaryTime; //total binary time
  //printf("inside of the of word_puzzle_solver");
        pthread_mutex_unlock(&mutex);//unlock the thread for the next user
    }
    else{
      //printf("inside of the else statement of word_puzzle_solver");
      		if(binsearch(dict, dictionary_size, buf + i) + 1){//if search is successful!
			printf("Thread #%d: %s\n",(int)id, buf + i);
	}
    }
    }
}
}//this is correct

void main(int argc, char** argv){//void is correct here
  long startTime = get_nanos(); //start the count
  THREADS = 1; //default thread count, okay all clear
  flagForLength = 0;
  flagForVerbose = FALSE;
  flagForTime = FALSE;
  //int amountOfThreads = 0;
  //THREADS = 3;
  char* token1Length; //pointer for token1
  char* token2Length; //pointer for token2 

   for (int counter = 1; counter < argc; counter++) {
     //printf("checking for loop %d\n",counter);
     char* argument = argv[counter];
     //-length
    if(strcmp(argument,"-len")==0){
      //printf("checking in len %s",argument);
      flagForLength++;
      countLength = 0;
      token2Length = argv[++counter];
      token1Length = strtok(token2Length,",");
      int otherCounter = 0;
      //printf("checking in len %s",argument);
      while(token1Length != NULL){
        //printf("checking while loop %d\n",counter);
            tokenizeArray[otherCounter] = atoi(token1Length);
            otherCounter++;
            countLength++;
            token1Length = strtok(NULL,",");
        //printf("testing inside of main %d", otherCounter);
      }
      //if -nthreads
    }else if(strcmp(argument,"-nthreads")==0){
          int amountOfThreads = atoi(argv[++counter]);
          THREADS = amountOfThreads;
      //if verbose
    }else if(strcmp(argument,"-verbose")==0){
      flagForVerbose = TRUE;
     //if -time
    }else if(strcmp(argument,"-time")==0){
      flagForTime = TRUE;
    }
   }
	int thread_number, j, size = SBUFFER/THREADS;
	char temp[100];
	pthread_t threadID[THREADS];
	char line[1000];
	char * pointer;
	FILE* f = fopen("dict.txt", "r");//retrieve from txt file
	dictionary_size = 0;
	while(fgets(line, 1000, f)){
    //reads formated 
		sscanf(line, "%s\n", temp);
		if(strlen(temp) == 0)
			continue;//one last go
		dict[dictionary_size] = (char*) malloc(sizeof(temp)+1);
		strcpy(dict[dictionary_size++], temp);
	}fclose(f);
  pthread_mutex_init(&mutex,NULL);
  //printf("mutex check%p",&mutex);
	for(thread_number = 0; thread_number < THREADS;thread_number++){
    //printf("checking inside of main for loop%d",thread_number);
		buffer[thread_number] = (char*) malloc(size + 1);
		if(!fgets(buffer[thread_number], size + 1, stdin)){
			fprintf(stderr, "Error: can't read the input stream!");
			break;
		}
		if(pthread_create(threadID + thread_number, NULL, word_puzzle_solver, (void *)thread_number)){
			fprintf(stderr, "Error: Too many threads are created!\n");
			break;
		}
	}
	for(j = 0; j < thread_number;j++){
		pthread_join(threadID[j], NULL);
    //character count matters in fprintf
    if(flagForVerbose)
		fprintf(stderr, "Note: Thread %d joined!\n", j);
	}
  pthread_mutex_destroy(&mutex);
  if(flagForVerbose)
	fprintf(stderr, "Note: Total time: %ld nanoseconds using %d threads!\n", 
		get_nanos()-startTime, thread_number);
    if(flagForTime)
    printf("This is a test: %ld nanoseconds using threads!\n",totalBinarySearchTime);//46 characters
    //printf("Testing: %ld nanoseconds using threads!\n",totalBinarySearchTime);//40 characters
}