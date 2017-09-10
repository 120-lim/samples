A = 0.99948
B = 1.51701
set xlabel "wavelength[nm]"
set ylabel "voltage[V]"
p "< paste 19.txt 20.txt" u ($1*A + B):($2+$4)/2 w l
rep "19.txt" u ($1*A + B):2 w l

