set terminal png size 1200,800
set output "results_Infectious.png"

set title "Infectious Results"
set xlabel "Time"
set ylabel "Population"

plot "../bin/simulation results" using 1:4 with lines title "I", \
