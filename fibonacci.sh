	#!/bin/bash
	
	read -p "Enter an Integer: " n
	
	a=0
	b=1
	echo -n "Fibonacci Series: "
	for((i=0; i<n; i++)) do
		echo -n "$a "
		c=$((a+b))
		a=$b
		b=$c
	done
	
