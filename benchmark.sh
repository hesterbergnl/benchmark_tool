gcc -Wall -std=c99 benchmarkRec.c -o benchmarkRec && time ./benchmarkRec
gcc -Wall -std=c99 -o2 benchmarkRecO2.c -o benchmarkRecO2 && time ./benchmarkRecO2
gcc -Wall -std=c99 benchmarkLoop.c -o benchmarkLoop && time ./benchmarkLoop
gcc -Wall -std=c99 benchmarkLoopO2.c -o benchmarkLoopO2 && time ./benchmarkLoopO2
