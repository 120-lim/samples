set xlabel "1/concentration of ATP[mM]"
set ylabel "1/velosity"
p [0:11] "ATP-velosity.txt" u (1/$1):(1/$2):((1/$2)-(1/($2+$3))) w error title "velosity under ATP"
set term postscript eps color
set out "Vmax.eps"
rep

