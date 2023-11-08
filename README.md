# CPuzzleWThreads
An automatic puzzle generator with an automatic puzzle solver written in C (programming language), using a dictionary file called dict.txt

Project hosted on:

https://replit.com/@monkeythrowup/Project6#wordpuzzle.c

In the terminal enter these commands:

#---------------------------------------------------------------------------

#1. enter make. NOTE: if make -s pops up in replit.com, just retype make and it will work

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

#last the randomgen number should be chosen to be the same as buffer number on line 33 with the wordpuzzle.c file

./randomgen 10000 | ./wordpuzzle -nthreads 20 -nthreads 200000 time -verbose

#will give:

Note: Thread #0: started!

Note: Thread #1: started!

Note: Thread #8: started!

Error: can't read the input stream!Note: Thread 0 joined!

Note: Thread 1 joined!

Note: Thread #3: started!

Note: Thread #5: started!

Note: Thread #6: started!

Note: Thread #7: started!

Thread #6: p

Note: Thread #9: started!

Note: Thread #10: started!

Note: Thread #11: started!

Note: Thread #12: started!

Note: Thread #13: started!

Note: Thread #4: started!

Note: Thread #14: started!

Note: Thread #15: started!

Note: Thread #16: started!

Note: Thread #2: started!

Thread #7: mc

Thread #7: c

Thread #7: mc

Thread #7: c

Thread #6: p

Note: Thread #17: started!

Note: Thread #18: started!

Note: Thread #19: started!

Note: Thread #20: started!

Note: Thread #21: started!

Thread #17: yr

Thread #17: r

Note: Thread #22: started!

Note: Thread #23: started!

Thread #22: z

Note: Thread #24: started!

Note: Thread #25: started!

Thread #21: br

Thread #21: r

Thread #21: up

Thread #21: p

Thread #22: post

Thread #22: st

Thread #22: t

Note: Thread #31: started!

Note: Thread #34: started!

Thread #22: kon

Thread #22: on

Thread #22: n

Thread #22: z

Thread #22: post

Thread #22: st

Thread #22: t

Thread #22: kon

Thread #22: on

Thread #22: n

Note: Thread #69: started!

Note: Thread #27: started!

Note: Thread #28: started!

Note: Thread #29: started!

Thread #29: n

Note: Thread #30: started!

Note: Thread #32: started!

Thread #31: cor

Thread #31: or

Thread #31: r

Thread #31: c

Thread #31: cor

Thread #31: or

Thread #31: r

Thread #31: c

Thread #32: ta

Thread #32: a

Thread #29: sb

Thread #29: b

Thread #29: x

Thread #29: n

Thread #29: sb

Thread #29: b

Thread #29: x

Thread #32: ta

Thread #32: a

Note: Thread #53: started!

Note: Thread #54: started!

Note: Thread #33: started!

Thread #53: ldl

Thread #53: dl

Thread #53: l

Note: Thread #55: started!

Note: Thread #45: started!

Thread #54: hex

Thread #54: ex

Thread #54: x

Note: Thread #56: started!

Note: Total time: 194557090 nanoseconds using 10 threads!

--> it mostly works and I am proud of it

#---------------------------------------------------------------------------
