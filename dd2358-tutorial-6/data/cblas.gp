set terminal dumb enhanced ansi256
set term dumb 94 44
#set terminal png 
#set autoscale
#set output "cblas.png" 
set xlabel "N"
set ylabel "Gflop/s"
set border 3 lw 1
set title "Intel Core i5-7360U, icc 2021.1.2"
set tics nomirror
set key inside right
plot "naive_perf.dat" using 1:($3/1e9) with linespoints title "Naive",\
     "cblas_perf.dat" using 1:($3/1e9) with linespoints title "Ref CBLAS"