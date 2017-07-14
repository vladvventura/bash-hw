#!/bin/bash
#createTable.sh
#Vladimir Ventura
#Homework 5
#CS-288
#This is to download 60 index.html files from usatoday.
#The output of this bash file goes into another bash file, which will call python

function main()
{

	
    for((i=0;i<60;i++)); do
	wget -O index-`date +"%Y-%m-%d-%H-%M"`.html http://markets.usatoday.com/custom/usatoday-com/html-mktscreener.asp;
	sleep 60;
    done;

}

main
