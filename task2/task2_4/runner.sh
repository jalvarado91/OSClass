#!/bin/sh

##########################################################
## COP4610 – Principles of Operating Systems – Summer C 2017
## Prof. Jose F. Osorio
## Student: Juan Alvarado – 3367805
##
## Assignment #: 3
## Specs: Task 2.4, OpenMP Program
## Due Date: 06/09/2017 by 11:55pm
##
## Module Name: tunner
##
## I Certify that this program code has been written by me
## and no part of it has been taken from any sources.
##########################################################


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
