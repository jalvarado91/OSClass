##########################################################
## COP4610 – Principles of Operating Systems – Summer C 2017
## Prof. Jose F. Osorio
## Student: Juan Alvarado – 3367805
##
## Assignment #: 3
## Specs: Task 2.4, OpenMP Program
## Due Date: 06/09/2017 by 11:55pm
##
## Module Name: consolidate_2cpu
##
## I Certify that this program code has been written by me
## and no part of it has been taken from any sources.
##########################################################

echo "Starting"

echo "orig"
cat 2cpu/orig_50x50_1th_trial* > 2cpu_final/orig_50x50_1th
cat 2cpu/orig_50x50_4th_trial* > 2cpu_final/orig_50x50_4th
cat 2cpu/orig_50x50_8th_trial* > 2cpu_final/orig_50x50_8th 
cat 2cpu/orig_50x50_16th_trial* > 2cpu_final/orig_50x50_16th
cat 2cpu/orig_50x50_32th_trial* > 2cpu_final/orig_50x50_32th

cat 2cpu/orig_500x500_1th_trial* > 2cpu_final/orig_500x500_1th
cat 2cpu/orig_500x500_4th_trial* > 2cpu_final/orig_500x500_4th
cat 2cpu/orig_500x500_8th_trial* > 2cpu_final/orig_500x500_8th 
cat 2cpu/orig_500x500_16th_trial* > 2cpu_final/orig_500x500_16th
cat 2cpu/orig_500x500_32th_trial* > 2cpu_final/orig_500x500_32th

echo "out"
cat 2cpu/out_50x50_1th_trial* > 2cpu_final/out_50x50_1th
cat 2cpu/out_50x50_4th_trial* > 2cpu_final/out_50x50_4th
cat 2cpu/out_50x50_8th_trial* > 2cpu_final/out_50x50_8th 
cat 2cpu/out_50x50_16th_trial* > 2cpu_final/out_50x50_16th
cat 2cpu/out_50x50_32th_trial* > 2cpu_final/out_50x50_32th

cat 2cpu/out_500x500_1th_trial* > 2cpu_final/out_500x500_1th
cat 2cpu/out_500x500_4th_trial* > 2cpu_final/out_500x500_4th
cat 2cpu/out_500x500_8th_trial* > 2cpu_final/out_500x500_8th 
cat 2cpu/out_500x500_16th_trial* > 2cpu_final/out_500x500_16th
cat 2cpu/out_500x500_32th_trial* > 2cpu_final/out_500x500_32th

echo "middle"
cat 2cpu/middle_50x50_1th_trial* > 2cpu_final/middle_50x50_1th
cat 2cpu/middle_50x50_4th_trial* > 2cpu_final/middle_50x50_4th
cat 2cpu/middle_50x50_8th_trial* > 2cpu_final/middle_50x50_8th 
cat 2cpu/middle_50x50_16th_trial* > 2cpu_final/middle_50x50_16th
cat 2cpu/middle_50x50_32th_trial* > 2cpu_final/middle_50x50_32th

cat 2cpu/middle_500x500_1th_trial* > 2cpu_final/middle_500x500_1th
cat 2cpu/middle_500x500_4th_trial* > 2cpu_final/middle_500x500_4th
cat 2cpu/middle_500x500_8th_trial* > 2cpu_final/middle_500x500_8th 
cat 2cpu/middle_500x500_16th_trial* > 2cpu_final/middle_500x500_16th
cat 2cpu/middle_500x500_32th_trial* > 2cpu_final/middle_500x500_32th

echo "both"
cat 2cpu/both_50x50_1th_trial* > 2cpu_final/both_50x50_1th
cat 2cpu/both_50x50_4th_trial* > 2cpu_final/both_50x50_4th
cat 2cpu/both_50x50_8th_trial* > 2cpu_final/both_50x50_8th 
cat 2cpu/both_50x50_16th_trial* > 2cpu_final/both_50x50_16th
cat 2cpu/both_50x50_32th_trial* > 2cpu_final/both_50x50_32th

cat 2cpu/both_500x500_1th_trial* > 2cpu_final/both_500x500_1th
cat 2cpu/both_500x500_4th_trial* > 2cpu_final/both_500x500_4th
cat 2cpu/both_500x500_8th_trial* > 2cpu_final/both_500x500_8th 
cat 2cpu/both_500x500_16th_trial* > 2cpu_final/both_500x500_16th
cat 2cpu/both_500x500_32th_trial* > 2cpu_final/both_500x500_32th

echo "Finished"
