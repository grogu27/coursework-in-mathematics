set terminal png size 1200,800
set output "results_Susceptible.png"

set title "Susceptible Results"
set xlabel "Time"
set ylabel "Population"

plot "../bin/simulation results" using 1:2 with lines title "S"
