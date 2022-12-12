#!/bin/bash

#echo 'Dictionary Filename?'
read dict; #should read in dictionary file
#echo 'Grid Filename?'
read grid; #read in grid file

run1=`./a.out dict grid | tail -1` #store first runtime (last line of output, stored in milliseconds)
run2=`./a.out dict grid | tail -1` #store second runtime
run3=`./a.out dict grid | tail -1` #store third runtime 
run4=`./a.out dict grid | tail -1` #store fourth runtime
run5=`./a.out dict grid | tail -1` #store fifth runtime

runtotal=$((run1+run2+run3+run4+run5)) #should add up the int values from the output of the method
runavg=$((runtotal/5)) #should find average of run time

echo ${runavg}
