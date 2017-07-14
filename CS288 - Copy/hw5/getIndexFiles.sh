#!/bin/bash
#createTable.sh
#Vladimir Ventura
#Homework 5
#CS-288
#This is to download 60 index.html files from YouTube.
#The output of this bash file goes into another bash file, which will be
#converted into text files.

function main()
{

	
    for((i=0;i<60;i++)); do
	wget -O index-`date +"%Y-%m-%d-%H-%M"`.html www.youtube.com;
	sleep 60;
    done;

}

main
