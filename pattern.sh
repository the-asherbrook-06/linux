#!/bin/bash

echo "Welcome to Pattern Generator"
echo "****************************"
echo
read -p "Enter number of lines: " n
echo
echo "1. Simple Triangle"
echo "2. Simple Number Triangle"
echo "3. Right Triangle"
echo "4. Triangle"
echo "5. Diamond"
read -p "Enter your choice: " ch
echo
echo

case $ch in
1)
	for((i=0; i<n; i++)) do
		for((j=0; j<i; j++)) do
			echo -n "* "
		done
		echo
	done;;
2)
	for((i=0; i<n; i++)) do
		for((j=0; j<i; j++)) do
			echo -n "$j "
		done
		echo
	done;;
3)
	for((i=0; i<n; i++)) do
		for((j=n-i; j>0; j--)) do
			echo -n "  "
		done
		for((j=0; j<i; j++)) do
			echo -n "* "
		done
		echo
	done;;
4)
	for((i=0; i<n; i++)) do
		for((j=n-i; j>0; j--)) do
			echo -n "  "
		done
		for((j=0; j<i; j++)) do
			echo -n "* "
		done
		for((j=0; j<i-1; j++)) do
			echo -n "* "
		done
		echo
	done;;
5)
	for((i=0; i<n; i++)) do
		for((j=n-i; j>0; j--)) do
			echo -n "  "
		done
		for((j=0; j<i; j++)) do
			echo -n "* "
		done
		for((j=0; j<i-1; j++)) do
			echo -n "* "
		done		
		echo
	done
	for((i=n-2; i>0; i--)) do
		for((j=n-i; j>0; j--)) do
			echo -n "  "
		done
		for((j=0; j<i; j++)) do
			echo -n "* "
		done
		for((j=0; j<i-1; j++)) do
			echo -n "* "
		done
		echo
	done;;
esac
