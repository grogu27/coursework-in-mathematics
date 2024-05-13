set terminal png size 1200,800
set output "results_plot.png"

set title "SEIR-D Model Results"
set xlabel "Time"
set ylabel "Population"

plot "../bin/simulation results" using 1:2 with lines title "S", \
     "../bin/simulation results" using 1:3 with lines title "E", \
     "../bin/simulation results" using 1:4 with lines title "I", \
     "../bin/simulation results" using 1:5 with lines title "R", \
     "../bin/simulation results" using 1:6 with lines title "D"