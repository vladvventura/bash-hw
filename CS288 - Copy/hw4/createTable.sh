#!/bin/bash
#createTable.sh
#Vladimir Ventura
#Homework 4
#CS-288
#This is to create a CSV of views, users, time, and title.
#The output of this bash file goes into the corresponding C file.
#I used the information from HW2 to do global replacement of , -> MY_COMMA

function main()
{
    User="User" Views="Views" Time="Time" Title="Title"
    grep data-context-item index.html | while read x; do
	tempViews=`expr "$x" : ".*data-context-item-views=\"\([0-9,]*\)"`
	tempViews=${tempViews//,/}	#take out the commas, dont bother with MY_COMMA
	#I'm sorting based on Views and turning it into ints anyway, so no need to bother.

	tempU=`expr "$x" : ".*data-context-item-user=\"\(.*\)\" data-context-item-type"`
	tempU=${tempU//,/MY_COMMA}
	
	tempT=`expr "$x" : ".*data-context-item-time=\"\(.*\)\" data-context-item-views"`
	tempT=${tempT//,/MY_COMMA}
	
	tempTitle=`expr "$x" : ".*data-context-item-title=\"\(.*\)\" data-context-item-time"`
	tempTitle=${tempTitle//,/MY_COMMA}

	echo $tempViews","$tempU","$tempT","$tempTitle >> table.txt;
    done

}

main
