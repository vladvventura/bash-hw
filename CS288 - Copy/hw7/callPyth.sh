#!/bin/bash
#createTable.sh
#Vladimir Ventura
#Homework 5
#CS-288
#This is to read through the 60 files, as I wanted to have the files before finishing the code (not even sure if I might be able to finish, I know jack of python). This will go through all the files and send each to python for conversion, and uploading them into sql server.

function main()
{

    hr="09"
    min=33
    for((i=0;i<60;i++)); do
       if [ min<60 ]
         then
	   python hw7.py index-2013-05-03-`echo $hr`-`echo $min`.html
       elif [ min>=60 ] #once it reaches sixty, you're at the hr
           min=0;
           hr="10";
           python hw7.py echo index-2013-05-03-`echo $hr`-`echo $min`.html
       fi;
       let min++
    done;

}

main
