#!/bin/sh
wget http://tug.ctan.org/macros/latex/contrib/feynmf.zip
unzip feynmf.zip
cd feynmf
platex feynmf.ins
mkdir -p /usr/share/texlive/texmf-dist/tex/latex/feynmf
mkdir -p /usr/share/texlive/texmf-dist/metafont/feynmf
mkdir -p /usr/share/texlive/texmf-dist/metapost/feynmf
cp feynmf.sty /usr/share/texlive/texmf-dist/tex/latex/feynmf
cp feynmp.sty /usr/share/texlive/texmf-dist/tex/latex/feynmf
cp feynmf.mf /usr/share/texlive/texmf-dist/metafont/feynmf 
cp feynmp.mp /usr/share/texlive/texmf-dist/metapost/feynmf
mktexlsr
