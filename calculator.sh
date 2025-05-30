#!/bin/bash

read -p "Enter a Integer: " a
read -p "Enter another Integer: " b

echo "1. Addition"
echo "2. Subraction"
echo "3. Multiplication"
echo "4. Division"
echo "5. Modulus"
read -p "Enter your choice: " ch

case $ch in
1)
	res=$(( a+b ))
	echo "A + B = $res";;
2)
	res=$(( a-b ))
	echo "A - B = $res";;
3)
	res=$(( a*b ))
	echo "A * B = $res";;
4)
	res=$(( a/b ))
	echo "A / B = $res";;
5)
	res=$(( a%b ))
	echo "A % B = $res";;
esac
