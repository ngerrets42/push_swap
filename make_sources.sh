#!/bin/bash
echo -n "SOURCES :=" > sources_pushswap.mk ;
find src_pushswap -type f -name *.c | awk '{print "	" $0 " \\"}' >> sources_pushswap.mk ;
find src -type f -name *.c | awk '{print "	" $0 " \\"}' >> sources_pushswap.mk ;
echo -n "SOURCES_CHECKER :=" > sources_checker.mk ;
find src_checker -type f -name *.c | awk '{print "	" $0 " \\"}' >> sources_checker.mk ;
find src -type f -name *.c | awk '{print "	" $0 " \\"}' >> sources_checker.mk ;