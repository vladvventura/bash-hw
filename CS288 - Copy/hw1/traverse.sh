#!/bin/bash
#traverse.sh
#Vladimir Ventura
#Homework 1
#CS-288
function main()
{
    traverse $1 $1
}

function traverse()
{
    local b=$2
    cd $1
    for x in `ls`; do
	if [ -d "$x"  ]; then #the directory exists
	    b=("$b""/$x")
	    echo $b
	    (traverse "$x" "$b")
	    #echo $1/$x
	    #(traverse "$x")
	fi #if the directory doesnt exist, do nothing!
	done;

}


main $1 #directory