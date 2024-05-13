#!/bin/bash

# Цикл для создания пяти графиков
for i in {1..5}; do
    gnuplot graph$i.gp
done

gnuplot graph.gp