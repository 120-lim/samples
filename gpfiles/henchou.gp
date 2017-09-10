A = 0.99948
set xlabel "energy[eV]"
set ylabel "{/Symbol D}R/R"
B = 1.51701
p "henchou.dat" u (1239.8/(A*$1+B)):5 title "" w l
C= 0.0083429642
D = 7000.0331709455
E = 1.5146312285 




set term postscript eps color
set out "henchou.eps"
rep


