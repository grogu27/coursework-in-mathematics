set terminal png size 1200,800
set output "results_Recovered.png"

set title "Recovered Results"
set xlabel "Time"
set ylabel "Population"

plot "../bin/simulation results" using 1:5 with lines title "R", \
