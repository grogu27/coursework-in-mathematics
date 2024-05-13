set terminal png size 1200,800
set output "results_Dead.png"

set title "Dead Results"
set xlabel "Time"
set ylabel "Population"

plot "../bin/simulation results" using 1:6 with lines title "D"