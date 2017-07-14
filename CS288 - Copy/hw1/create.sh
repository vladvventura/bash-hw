#!/bin/bash
#create.sh
#Vladimir Ventura
#Homework 1
#CS-288
#note: creating depth and breadth of 5 goes beyond the limit of cmd window.
#In other words, I can't screenshot the top part. Apologies

function main()
{
    create $1 $2 $3
}

function create()
{
    local d=$1 b=$2 s=$3
    open=($s)
    
    for((j=1;j<=d;j++)); do
	temp_open=( )
	for x in ${open[@]}; do
	   temp=( )
	   for((i=1;i<=b;i++)); do #the deepest part of the nested loop is done
	       #first; i.e. breadth is done first at the first depth.
	       temp=(${temp[@]} $x/$i)
	       #echo "This is the deepest part" ${temp[@]}#testing purposes
	   done;
	temp_open=(${temp_open[@]} ${temp[@]})

	done;
    open=(${temp_open[@]})
    l=`expr $j - 1`
    echo "Depth #$l:"
    for k in ${open[@]}; do
	echo $k
        done;
    done;
    #the following was used to show the directory was created:
    #for x in ${open[@]}; do
    #	echo $x
    #	done;
}

main $1 $2 $3

