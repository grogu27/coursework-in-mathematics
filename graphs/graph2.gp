set terminal png size 1200,800
set output "results_Exposed.png"

set title "Exposed Results"
set xlabel "Time"
set ylabel "Population"

plot "../bin/simulation results" using 1:3 with lines title "E"
