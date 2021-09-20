# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    tester.sh                                          :+:    :+:             #
#                                                      +:+                     #
#    By: ngerrets <ngerrets@student.codam.nl>         +#+                      #
#                                                    +#+                       #
#    Created: 2021/09/20 15:51:42 by ngerrets      #+#    #+#                  #
#    Updated: 2021/09/20 17:24:44 by ngerrets      ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

#
#	Credits for the "args.py" script goes to student mraasvel
#

#!/bin/sh

# For default tests
f() {
	INSTRUCTIONS=$(./push_swap $1);
	if [ -z "$INSTRUCTIONS" ]
	then
		echo "$INSTRUCTIONS\c" | ./checker_Mac $1 | tr -d '\n';
	else
		echo "$INSTRUCTIONS" | ./checker_Mac $1 | tr -d '\n';
	fi
	echo "	" | tr -d '\n';
	echo "$INSTRUCTIONS" | ./checker $1 | tr -d '\n';
	echo "$INSTRUCTIONS" | wc -l | tr -d '\n';
	echo "	" $1;
}

# For testing errors
f_error() {
	echo "	input: " "\""$1"\"";
	echo "	push_swap: " | tr -d '\n';
	./push_swap $1 | tr -d '\n';
	echo "";
	echo "	checker: " | tr -d '\n';
	./checker $1 | tr -d '\n';
	echo ""
	echo "	checker_Mac: " | tr -d '\n';
	./checker_Mac $1 | tr -d '\n';
	echo "\n";
}

# tests but don't print the input stack
f_noprint() {
	INSTRUCTIONS=$(./push_swap $1);
	if [ -z "$INSTRUCTIONS" ]
	then
		echo "$INSTRUCTIONS\c" | ./checker_Mac $1 | tr -d '\n';
	else
		echo "$INSTRUCTIONS" | ./checker_Mac $1 | tr -d '\n';
	fi
	echo "	" | tr -d '\n';
	echo "$INSTRUCTIONS" | ./checker $1 | tr -d '\n';
	echo "$INSTRUCTIONS" | wc -l | tr -d '\n';
	echo "	  NOT PRINTED";
}

echo "42:	checker: count:	permutation:"
echo "\nTwo"
f "0 1"
f "1 0"
echo "\nThree:"
f "0 1 2"
f "2 1 0"
f "1 2 0"
for i in {1..7}; do f "$(python3 args.py 3)"; done;
echo "\nFour:"
for i in {1..3}; do f "$(python3 args.py 4)"; done;
echo "\nFive:"
for i in {1..10}; do f "$(python3 args.py 5)"; done;
echo "\nSix:"
for i in {1..3}; do f "$(python3 args.py 6)"; done;
echo "\nSeven:"
for i in {1..3}; do f "$(python3 args.py 7)"; done;
echo "\nEight:"
for i in {1..3}; do f "$(python3 args.py 8)"; done;
echo "\nNine:"
for i in {1..3}; do f "$(python3 args.py 9)"; done;
echo "\nTen:"
for i in {1..3}; do f "$(python3 args.py 10)"; done;
echo "\nTwenty:"
for i in {1..3}; do f "$(python3 args.py 20)"; done;
echo "\nFivety:"
for i in {1..3}; do f_noprint "$(python3 args.py 50)"; done;
echo "\nHundred:"
for i in {1..10}; do f_noprint "$(python3 args.py 100)"; done;
echo "\nFive hundred:"
for i in {1..10}; do f_noprint "$(python3 args.py 500)"; done;

echo "\nERROR CHECK:\n"
f_error "-835770774378 9 0"
f_error "7885802848"
f_error "732323733777547573578903747875737403147078026"
f_error ""
f_error "9 8 7 6 5 4 3 2 1 9 10 11"
f_error "a b c d e f g"

echo "\nExtra Tests:"
echo "Thousand:"
for i in {1..3}; do f_noprint "$(python3 args.py 1000)"; done;
echo "\nTwo Thousand Five Hundred:"
f_noprint "$(python3 args.py 2500)";
echo "\nFive Thousand"
f_noprint "$(python3 args.py 5000)";
