#!/bin/sh

#THREADS=1
TRIALS=10

threadcount=(32 16 8 4 1)

for tcount in "${threadcount[@]}"
do
	echo "Running Trials, $tcount threads."

	for ((t=1; t<=$TRIALS; t++))
	do
		echo "Running Trial $t"
		./task2_4_both $tcount > out/1cpu/both_50x50_${tcount}th_trial$t
	done

	echo "Done Running Trials for $tcount threads."
done
