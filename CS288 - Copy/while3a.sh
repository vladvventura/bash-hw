#!/bin/sh
while read f
do
    case $f in
	hello)      echo English ;;
	howdy)      echo American ;;
	gday)       echo Australian ;;
	bonjour)    echo French ;;
	"guten tag") echo German ;;
	*)           echo Unkown Language: $f
    
    esac
done <myfile
