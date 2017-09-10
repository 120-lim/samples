#!/bin/sh
ff="'"
fin="\mode:=ljfour;input "
rm *pk
platex ex.tex
a=$(ls *.mf)
for file in $a;do
   com="mf $ff$fin$file$ff"
   eval ${com}
done
