# CPuzzleWThreads
An automatic puzzle generator with an automatic puzzle solver written in C (programming language), using a dictionary file called dict.txt


In the terminal enter these commands:

#---------------------------------------------------------------------------

#1. enter make

make

#will give: 

#gcc -I. -g -pthread -w   -c -o wordpuzzle.o wordpuzzle.c

#gcc -o wordpuzzle wordpuzzle.o -I. -g -pthread -w

#---------------------------------------------------------------------------

#---------------------------------------------------------------------------

#using 100 as an example to generate puzzle

./randomgen 100 #is the command


#---------------------------------------------------------------------------

#---------------------------------------------------------------------------

#initialize the files with a gcc command 

gcc randomgen.c -o randomgen -w

#---------------------------------------------------------------------------

#---------------------------------------------------------------------------

#last the randomgen number should be chosen to be the same as buffer number on line 33 with the wordpuzzle.c file

./randomgen 1000 | ./wordpuzzle -nthreads 20 -nthreads 200000 time -verbose

#will give:

Note: Thread #2: started!

Note: Thread #9: started!

Note: Thread #8: started!

Thread #2: ex

Thread #2: x

Thread #2: ex

Thread #2: x

Note: Thread #7: started!

Thread #8: pb

Thread #8: b

Thread #8: us

Thread #8: s

Note: Thread #5: started!

Note: Thread #4: started!

Note: Thread #3: started!

Note: Thread #1: started!

Note: Thread #0: started!

Note: Thread #6: started!

Thread #0: rim

Thread #0: m

Thread #6: px

Thread #6: x

Thread #6: px

Thread #6: x

Thread #0: rim

Thread #0: m

Note: Thread 0 joined!

Note: Thread 1 joined!

Note: Thread 2 joined!

Note: Thread 3 joined!

Note: Thread 4 joined!

Note: Thread 5 joined!

Note: Thread 6 joined!

Note: Thread 7 joined!

Note: Thread 8 joined!

Note: Thread 9 joined!

Note: Total time: 74957809 nanoseconds using 10 threads!

#---------------------------------------------------------------------------
