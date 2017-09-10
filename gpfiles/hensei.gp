N = 0.717942
R = 0.217726
U = 0.087043 
set xlabel "wavelength[nm]"
set ylabel "strength"
plot "natural.txt" u 1:($2*N) title "natural"
rep "Unfold.txt" u 1:($2*U) title "Un-fold"
rep "Refold.txt" u 1:($2*R) title "Re-fold"
set term postscript eps color
set out "hensei.eps"
rep
