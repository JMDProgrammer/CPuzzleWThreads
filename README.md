# CPuzzleWThreads
An automatic puzzle generator with an automatic puzzle solver written in C (programming language), using a dictionary file called dict.txt

Project hosted on:

https://replit.com/@monkeythrowup/Project6#wordpuzzle.c

In the terminal enter these commands:

#---------------------------------------------------------------------------

#1. enter make. NOTE: if "make -s" pops up in replit.com, just retype make and it will work

make


#---------------------------------------------------------------------------

#---------------------------------------------------------------------------

#using 1000 as an example to generate puzzle

./randomgen 1000 

#is the command

#will create a random puzzle like:

zmebhhozaicuclamnidjvxflpbjtosbqfirophprpsltdnfswietfjgwnprbivrpdldsuvlmpxfumnmkxqdfckdpbvsjqmatzgnvbyjqxrkkewubpagrkkilfaxxoxqnffjgduwdlinphjtwjbptnxhuzgrofjdloorujqxuymmhvhdfiuawrhstpkhvtmgibzekrbgqnszibfpmzqktzcmpmvkghsqktuulxbdkvcuzhklhcvcbxqqkncswwkhqedbdgencgjdqvozxjbzgrrsgwkcswjicnjftpuxyeaozonzzqagjtapplrijbqmqcrjtmjrqjfrauszkshtmiibvclefcqvgigzuprmbyfbtycfskzgsjinnvrszknfsuholacoyjptjuzceakylunzqgrpqhxkdeaogedeouaxqbbudmuqghpwojogslrvrrlxyqdmndldgnajbuajeriscwyuhrryldvjtyvgeikkxkwygykkpseuofoxwgxhlssesnlyyxlvjhwpfgawygqmlhjipirackeuzrvxogtzpppwvrsvxlhlsstjamjcwpyyjvvzdqzshoqehjzgwirqcmzezkivzjvkerkijjctztxgezoahgsksrqrdzpeikpmdzwpibijuhragfcqnucgnszqrquzdloikmxunhdjpulxcnnpjpvwixobpldswrdhfcbtkhebbqaffovpfslprarhnubjneqshuntbuuemukrkhgqzufrwyyjszshejanfpgglamxwypjfvzfrgynfwwzxphdajqfawnmybjxcyghwhonnmdukzukqbnskgzkeowfqicsikbgrsuggxbryvdpyqhkyjudxtindmhlwlspdovjnycntfetyodwxabuvlkaxrltefihvgrkevyabctzqzxnbzkwkuwinjdsrozmusxaovarzwsqvpfwqrublslzbqtsgshcneddbfuabmsydawursxfkiema

#---------------------------------------------------------------------------

#---------------------------------------------------------------------------

#initialize the files with a gcc command 

gcc randomgen.c -o randomgen -w

#---------------------------------------------------------------------------

#---------------------------------------------------------------------------

#solve: 

Note: if you change the buffersize that comes after ./randomgen, it should also be changed in the code at ./wordpuzzle.c (line 33) if there are any problems

./randomgen 10000 | ./wordpuzzle -nthreads 10000 -time -verbose

#will give:

Note: Thread #1: started!

Error: can't read the input stream!Note: Thread #4: started!

Note: Thread #2: started!

Note: Thread #0: started!

Note: Thread #3: started!

Note: Thread #2: at

Note: Thread #3: f

Note: Thread #2: t

Note: Thread #0: u

Note: Thread #4: o

Note: Thread #4: o

Note: Thread #3: f

Note: Thread #2: at

Note: Thread #2: t

Note: Thread #0: u

Note: Thread 0 joined!

Note: Thread 1 joined!

Note: Thread 2 joined!

Note: Thread 3 joined!

Note: Thread 4 joined!

Note: Total time: 73660645 nanoseconds using 5 threads!

This is a test: 11826415 nanoseconds using threads!

--> it mostly works and I am proud of it.

#---------------------------------------------------------------------------
