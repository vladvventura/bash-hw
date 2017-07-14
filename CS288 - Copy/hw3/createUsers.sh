#!/bin/bash
#Vladimir Ventura
#2/27/2013
#Homework 3

function main()
{
    User="Users"
    echo $User >> users.txt
    grep data-context-item index.html | while read x; do
	tempU=`expr "$x" : ".*data-context-item-user=\"\(.*\)\" data-context-item-type"`
	echo $tempU >> users.txt;
	done;
}

main