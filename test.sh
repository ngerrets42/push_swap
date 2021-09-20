#!/bin/sh

for i in {1..10000};
do ./push_swap $(python3 args.py 100) | grep "7"
done;
