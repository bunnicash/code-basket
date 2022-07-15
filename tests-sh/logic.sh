#!/bin/bash

read -r -p "(Use 1, 0) A B: " A B

i="1"  #compare-against
s_="1" #success/true
f_="0" #failure/false

if [ $A == $i ] && [ $B == $i ]; then
 echo "$s_ : AND"
else echo " "
fi

if [ $A == $i ] && [ $B == $i ]; then
 echo "$f_ : NAND"
else echo " "
fi

if [ $A == $i ] || [ $B == $i ]; then
 echo "$s_ : OR"
else echo " "
fi

if [ $A == $i ] && [ $B == $i ]; then
 echo "$f_ : XOR"
else echo " "
fi

if [ $A != $i ] && [ $B != $i ]; then
 echo "$s_ : NOR"
else echo " "
fi
