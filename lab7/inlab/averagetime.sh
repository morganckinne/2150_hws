#!/bin/bash

size=5
runtotal=0
read input;
if [$input == 'quit']
then
    exit
fi
for ((i=1; i<=$size; i++)) #for loop
do
    echo "Running iteration ${i}: "
    t=`./a.out ${input} | tail -1` #store runtime
    runtotal=$((runtotal+t)) #sum runtime
    echo "time taken: $t ms" #print runtime
done
runavg=$((runtotal/5)) #avg runtime
echo "5 iterations took $runtotal ms"
echo "Average time was $runavg ms"
#echo $runavg print avg runtime
