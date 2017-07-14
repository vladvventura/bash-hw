#!/bin/bash
#createTable.sh
#Vladimir Ventura
#Homework 5
#CS-288
#This is to create 60 CSV files from 60 YouTube index.html files.
#The output of this bash file goes into text files.
#I used the information from HW2 to do global replacement of , -> MY_COMMA
#I used the information from HW4 to help with doing this overall.

#So, youtube has organized the views, user, title and time
#differently for EVERY site update. In other words, one grep won't work for
#all sites. Because of this, I need to make several greps. Great.
function main()
{
    
   
    User="User" Views="Views" Time="Time" Title="Title"
    hr="01"
    min="13"

#here I will list which tables contain what order:
#User, Time, ID, Title, Type, Views 1:34 2:11
#User, Time, Views, ID, Title, Type 2:07
#User, Time, ID, Views, Title, Type 2:12
#User, Type, ID, Time, Views, Title 1:35
#User, Type, Time, ID, Title, Views 1:54 2:08
#User, ID, Time, Title, Type, Views 1:45
#User, Title, Views, Time
#User, Title, Type, Time, ID, Views 1:47
#User, Title, type, id, Time, Views 1:43
#User, ID, Views, Time, Title, Type 1:41
#User, Views, type, Title, id, Time 1:16
#ID, User, Views, Title, type, Time 1:14
#ID, Type, Time, Title, User, Views 1:24
#ID, type, Time, Views, User, Title 1:37
#ID, Type, Title, User, Time, Views 1:58
#ID, Time, Title, Views, User, Type 1:46 1:57
#ID, Time, User, Views, Type, Title 1:32 1:40
#ID, Time, Type, Views, Title, User 2:05
#ID, Time, Type, Title, Views, User 2:10
#ID, title, time, views, user, type 1:25 1:30 1:42
#ID, Title, Time, type, User, Views 1:20 1:50
#ID, Title, User, Time, Views, type 1:17
#ID, Views, User, Title, Type, Time 1:44
#ID, Views, User, Title, Time, Type 2:03
#ID, Views, Time, Title, type, User 1:13
#Time, Views, ID, Type, Title, User 1:31
#Time, Type, Views, Title, ID, User 1:53
#Time, ID, Type, Title, User, Views 1:56
#Time, User, Views, Title, ID, Type 2:13
#Type, ID, Time, User, Title, Views 1:33
#Type, Title, Time, Views, id, User 1:15
#Type, Title, Time, User, Views, ID 2:04
#Type, Time, Title, User, Views, ID 1:19
#Type, Views, Title, ID, Time, User 2:01
#Title, User, Time, ID, Views, Type 1:52
#Title, ID, User, type, Views, Time 1:18
#Title, ID, Views, User, Type, Time 1:48 1:51
#Title, Type, Time, User, Views, ID 2:09
#Title, User, Views, Time, ID, Type 1:21 1:22
#Title, User, Views, ID, Type, Time 1:38 2:00
#Title, Views, Time, User, ID, Type 1:26 1:59
#Views, ID, Title, User, Time, Type 1:36 2:06
#Views, ID, Time, Type, Title, User 1:23
#Views, Title, Time, ID, Type, User 2:02
#Views, User, ID, Time, Type, Title 1:27
#Views, User, Time, ID, Title, Type 1:49
#Views, Time, User, Type, ID, Title 1:29
#Views, Time, Type, ID, Title, User 1:28
#Views, Time, ID, Title, Type, User 1:55
#
#
# As you can see, there is no pattern to the way this works....
#    


##User, Time, ID, Title, Type, Views 1:34 2:11
    hr="01";
    min="34";
    grep data-context-item index-2013-04-08-`echo $hr`-`echo $min`.html | while read x; do
	tempViews=`expr "$x" : ".*data-context-item-views=\"\([0-9,]*\)"`
	tempViews=${tempViews//,/}	#take out the commas, dont bother with MY_COMMA
	#I'm sorting based on Views and turning it into ints anyway, so no need to bother.

	tempU=`expr "$x" : ".*data-context-item-user=\"\(.*\)\" data-context-item-time="`
	tempU=${tempU//,/MY_COMMA}
	
	tempT=`expr "$x" : ".*data-context-item-time=\"\(.*\)\" data-context-item-id"`
	tempT=${tempT//,/MY_COMMA}
	
	tempTitle=`expr "$x" : ".*data-context-item-title=\"\(.*\)\" data-context-item-type"`
	tempTitle=${tempTitle//,/MY_COMMA}

	echo $tempViews","$tempU","$tempT","$tempTitle >> index-2013-04-08-`echo $hr`-`echo $min`-table.txt;
    done

    hr="02";
    min="11";

    grep data-context-item index-2013-04-08-`echo $hr`-`echo $min`.html | while read x; do
	tempViews=`expr "$x" : ".*data-context-item-views=\"\([0-9,]*\)"`
	tempViews=${tempViews//,/}	#take out the commas, dont bother with MY_COMMA
	#I'm sorting based on Views and turning it into ints anyway, so no need to bother.

	tempU=`expr "$x" : ".*data-context-item-user=\"\(.*\)\" data-context-item-time="`
	tempU=${tempU//,/MY_COMMA}
	
	tempT=`expr "$x" : ".*data-context-item-time=\"\(.*\)\" data-context-item-id"`
	tempT=${tempT//,/MY_COMMA}
	
	tempTitle=`expr "$x" : ".*data-context-item-title=\"\(.*\)\" data-context-item-type"`
	tempTitle=${tempTitle//,/MY_COMMA}

	echo $tempViews","$tempU","$tempT","$tempTitle >> index-2013-04-08-`echo $hr`-`echo $min`-table.txt;
    done


#User, Time, Views, ID, Title, Type 2:07

    hr="02"
    min="07"
    grep data-context-item index-2013-04-08-`echo $hr`-`echo $min`.html | while read x; do
	tempViews=`expr "$x" : ".*data-context-item-views=\"\([0-9,]*\)"`
	tempViews=${tempViews//,/}	#take out the commas, dont bother with MY_COMMA
	#I'm sorting based on Views and turning it into ints anyway, so no need to bother.

	tempU=`expr "$x" : ".*data-context-item-user=\"\(.*\)\" data-context-item-time="`
	tempU=${tempU//,/MY_COMMA}
	
	tempT=`expr "$x" : ".*data-context-item-time=\"\(.*\)\" data-context-item-views"`
	tempT=${tempT//,/MY_COMMA}
	
	tempTitle=`expr "$x" : ".*data-context-item-title=\"\(.*\)\" data-context-item-type"`
	tempTitle=${tempTitle//,/MY_COMMA}

	echo $tempViews","$tempU","$tempT","$tempTitle >> index-2013-04-08-`echo $hr`-`echo $min`-table.txt;
    done


#User, Time, ID, Views, Title, Type 2:12
    hr="02"
    min="12"
    grep data-context-item index-2013-04-08-`echo $hr`-`echo $min`.html | while read x; do
	tempViews=`expr "$x" : ".*data-context-item-views=\"\([0-9,]*\)"`
	tempViews=${tempViews//,/}	#take out the commas, dont bother with MY_COMMA
	#I'm sorting based on Views and turning it into ints anyway, so no need to bother.

	tempU=`expr "$x" : ".*data-context-item-user=\"\(.*\)\" data-context-item-time="`
	tempU=${tempU//,/MY_COMMA}
	
	tempT=`expr "$x" : ".*data-context-item-time=\"\(.*\)\" data-context-item-id"`
	tempT=${tempT//,/MY_COMMA}
	
	tempTitle=`expr "$x" : ".*data-context-item-title=\"\(.*\)\" data-context-item-type"`
	tempTitle=${tempTitle//,/MY_COMMA}

	echo $tempViews","$tempU","$tempT","$tempTitle >> index-2013-04-08-`echo $hr`-`echo $min`-table.txt;
    done


#User, Type, ID, Time, Views, Title 1:35
    hr="01"
    min="35"
    grep data-context-item index-2013-04-08-`echo $hr`-`echo $min`.html | while read x; do
	tempViews=`expr "$x" : ".*data-context-item-views=\"\([0-9,]*\)"`
	tempViews=${tempViews//,/}	#take out the commas, dont bother with MY_COMMA
	#I'm sorting based on Views and turning it into ints anyway, so no need to bother.

	tempU=`expr "$x" : ".*data-context-item-user=\"\(.*\)\" data-context-item-type="`
	tempU=${tempU//,/MY_COMMA}
	
	tempT=`expr "$x" : ".*data-context-item-time=\"\(.*\)\" data-context-item-views"`
	tempT=${tempT//,/MY_COMMA}
	
	tempTitle=`expr "$x" : ".*data-context-item-title=\"\(.*\)\">"`
	tempTitle=${tempTitle//,/MY_COMMA}

	echo $tempViews","$tempU","$tempT","$tempTitle >> index-2013-04-08-`echo $hr`-`echo $min`-table.txt;
    done
#User, Type, Time, ID, Title, Views 1:54 2:08
    hr="01"
    min="54"
    grep data-context-item index-2013-04-08-`echo $hr`-`echo $min`.html | while read x; do
	tempViews=`expr "$x" : ".*data-context-item-views=\"\([0-9,]*\)"`
	tempViews=${tempViews//,/}	#take out the commas, dont bother with MY_COMMA
	#I'm sorting based on Views and turning it into ints anyway, so no need to bother.

	tempU=`expr "$x" : ".*data-context-item-user=\"\(.*\)\" data-context-item-type="`
	tempU=${tempU//,/MY_COMMA}
	
	tempT=`expr "$x" : ".*data-context-item-time=\"\(.*\)\" data-context-item-id"`
	tempT=${tempT//,/MY_COMMA}
	
	tempTitle=`expr "$x" : ".*data-context-item-title=\"\(.*\)\" data-context-item-views"`
	tempTitle=${tempTitle//,/MY_COMMA}

	echo $tempViews","$tempU","$tempT","$tempTitle >> index-2013-04-08-`echo $hr`-`echo $min`-table.txt;
    done

    hr="02"
    min="08"
    grep data-context-item index-2013-04-08-`echo $hr`-`echo $min`.html | while read x; do
	tempViews=`expr "$x" : ".*data-context-item-views=\"\([0-9,]*\)"`
	tempViews=${tempViews//,/}	#take out the commas, dont bother with MY_COMMA
	#I'm sorting based on Views and turning it into ints anyway, so no need to bother.

	tempU=`expr "$x" : ".*data-context-item-user=\"\(.*\)\" data-context-item-type="`
	tempU=${tempU//,/MY_COMMA}
	
	tempT=`expr "$x" : ".*data-context-item-time=\"\(.*\)\" data-context-item-id"`
	tempT=${tempT//,/MY_COMMA}
	
	tempTitle=`expr "$x" : ".*data-context-item-title=\"\(.*\)\" data-context-item-views"`
	tempTitle=${tempTitle//,/MY_COMMA}

	echo $tempViews","$tempU","$tempT","$tempTitle >> index-2013-04-08-`echo $hr`-`echo $min`-table.txt;
    done

#User, ID, Time, Title, Type, Views 1:45

    hr="01"
    min="45"
    grep data-context-item index-2013-04-08-`echo $hr`-`echo $min`.html | while read x; do
	tempViews=`expr "$x" : ".*data-context-item-views=\"\([0-9,]*\)"`
	tempViews=${tempViews//,/}	#take out the commas, dont bother with MY_COMMA
	#I'm sorting based on Views and turning it into ints anyway, so no need to bother.

	tempU=`expr "$x" : ".*data-context-item-user=\"\(.*\)\" data-context-item-id="`
	tempU=${tempU//,/MY_COMMA}
	
	tempT=`expr "$x" : ".*data-context-item-time=\"\(.*\)\" data-context-item-title"`
	tempT=${tempT//,/MY_COMMA}
	
	tempTitle=`expr "$x" : ".*data-context-item-title=\"\(.*\)\" data-context-item-type"`
	tempTitle=${tempTitle//,/MY_COMMA}

	echo $tempViews","$tempU","$tempT","$tempTitle >> index-2013-04-08-`echo $hr`-`echo $min`-table.txt;
    done
#User, Title, Type, Time, ID, Views 1:47

    hr="01"
    min="47"
    grep data-context-item index-2013-04-08-`echo $hr`-`echo $min`.html | while read x; do
	tempViews=`expr "$x" : ".*data-context-item-views=\"\([0-9,]*\)"`
	tempViews=${tempViews//,/}	#take out the commas, dont bother with MY_COMMA
	#I'm sorting based on Views and turning it into ints anyway, so no need to bother.

	tempU=`expr "$x" : ".*data-context-item-user=\"\(.*\)\" data-context-item-title="`
	tempU=${tempU//,/MY_COMMA}
	
	tempT=`expr "$x" : ".*data-context-item-time=\"\(.*\)\" data-context-item-id"`
	tempT=${tempT//,/MY_COMMA}
	
	tempTitle=`expr "$x" : ".*data-context-item-title=\"\(.*\)\" data-context-item-type"`
	tempTitle=${tempTitle//,/MY_COMMA}

	echo $tempViews","$tempU","$tempT","$tempTitle >> index-2013-04-08-`echo $hr`-`echo $min`-table.txt;
    done
#User, Title, type, id, Time, Views 1:43
    hr="01"
    min="43"
    grep data-context-item index-2013-04-08-`echo $hr`-`echo $min`.html | while read x; do
	tempViews=`expr "$x" : ".*data-context-item-views=\"\([0-9,]*\)"`
	tempViews=${tempViews//,/}	#take out the commas, dont bother with MY_COMMA
	#I'm sorting based on Views and turning it into ints anyway, so no need to bother.

	tempU=`expr "$x" : ".*data-context-item-user=\"\(.*\)\" data-context-item-title="`
	tempU=${tempU//,/MY_COMMA}
	
	tempT=`expr "$x" : ".*data-context-item-time=\"\(.*\)\" data-context-item-views"`
	tempT=${tempT//,/MY_COMMA}
	
	tempTitle=`expr "$x" : ".*data-context-item-title=\"\(.*\)\" data-context-item-type"`
	tempTitle=${tempTitle//,/MY_COMMA}

	echo $tempViews","$tempU","$tempT","$tempTitle >> index-2013-04-08-`echo $hr`-`echo $min`-table.txt;
    done
#User, ID, Views, Time, Title, Type 1:41
    hr="01"
    min="41"
    grep data-context-item index-2013-04-08-`echo $hr`-`echo $min`.html | while read x; do
	tempViews=`expr "$x" : ".*data-context-item-views=\"\([0-9,]*\)"`
	tempViews=${tempViews//,/}	#take out the commas, dont bother with MY_COMMA
	#I'm sorting based on Views and turning it into ints anyway, so no need to bother.

	tempU=`expr "$x" : ".*data-context-item-user=\"\(.*\)\" data-context-item-id="`
	tempU=${tempU//,/MY_COMMA}
	
	tempT=`expr "$x" : ".*data-context-item-time=\"\(.*\)\" data-context-item-title"`
	tempT=${tempT//,/MY_COMMA}
	
	tempTitle=`expr "$x" : ".*data-context-item-title=\"\(.*\)\" data-context-item-type"`
	tempTitle=${tempTitle//,/MY_COMMA}

	echo $tempViews","$tempU","$tempT","$tempTitle >> index-2013-04-08-`echo $hr`-`echo $min`-table.txt;
    done
#User, Views, type, Title, id, Time 1:16
    hr="01"
    min="16"
    grep data-context-item index-2013-04-08-`echo $hr`-`echo $min`.html | while read x; do
	tempViews=`expr "$x" : ".*data-context-item-views=\"\([0-9,]*\)"`
	tempViews=${tempViews//,/}	#take out the commas, dont bother with MY_COMMA
	#I'm sorting based on Views and turning it into ints anyway, so no need to bother.

	tempU=`expr "$x" : ".*data-context-item-user=\"\(.*\)\" data-context-item-views="`
	tempU=${tempU//,/MY_COMMA}
	
	tempT=`expr "$x" : ".*data-context-item-time=\"\(.*\)\">"`
	tempT=${tempT//,/MY_COMMA}
	
	tempTitle=`expr "$x" : ".*data-context-item-title=\"\(.*\)\" data-context-item-id"`
	tempTitle=${tempTitle//,/MY_COMMA}

	echo $tempViews","$tempU","$tempT","$tempTitle >> index-2013-04-08-`echo $hr`-`echo $min`-table.txt;
    done
#ID, User, Views, Title, type, Time 1:14
    hr="01"
    min="14"
    grep data-context-item index-2013-04-08-`echo $hr`-`echo $min`.html | while read x; do
	tempViews=`expr "$x" : ".*data-context-item-views=\"\([0-9,]*\)"`
	tempViews=${tempViews//,/}	#take out the commas, dont bother with MY_COMMA
	#I'm sorting based on Views and turning it into ints anyway, so no need to bother.

	tempU=`expr "$x" : ".*data-context-item-user=\"\(.*\)\" data-context-item-views="`
	tempU=${tempU//,/MY_COMMA}
	
	tempT=`expr "$x" : ".*data-context-item-time=\"\(.*\)\">"`
	tempT=${tempT//,/MY_COMMA}
	
	tempTitle=`expr "$x" : ".*data-context-item-title=\"\(.*\)\" data-context-item-type"`
	tempTitle=${tempTitle//,/MY_COMMA}

	echo $tempViews","$tempU","$tempT","$tempTitle >> index-2013-04-08-`echo $hr`-`echo $min`-table.txt;
    done
#ID, Type, Time, Title, User, Views 1:24
    hr="01"
    min="24"
    grep data-context-item index-2013-04-08-`echo $hr`-`echo $min`.html | while read x; do
	tempViews=`expr "$x" : ".*data-context-item-views=\"\([0-9,]*\)"`
	tempViews=${tempViews//,/}	#take out the commas, dont bother with MY_COMMA
	#I'm sorting based on Views and turning it into ints anyway, so no need to bother.

	tempU=`expr "$x" : ".*data-context-item-user=\"\(.*\)\" data-context-item-views="`
	tempU=${tempU//,/MY_COMMA}
	
	tempT=`expr "$x" : ".*data-context-item-time=\"\(.*\)\" data-context-item-title"`
	tempT=${tempT//,/MY_COMMA}
	
	tempTitle=`expr "$x" : ".*data-context-item-title=\"\(.*\)\" data-context-item-user"`
	tempTitle=${tempTitle//,/MY_COMMA}

	echo $tempViews","$tempU","$tempT","$tempTitle >> index-2013-04-08-`echo $hr`-`echo $min`-table.txt;
    done
#ID, type, Time, Views, User, Title 1:37
    hr="01"
    min="37"
    grep data-context-item index-2013-04-08-`echo $hr`-`echo $min`.html | while read x; do
	tempViews=`expr "$x" : ".*data-context-item-views=\"\([0-9,]*\)"`
	tempViews=${tempViews//,/}	#take out the commas, dont bother with MY_COMMA
	#I'm sorting based on Views and turning it into ints anyway, so no need to bother.

	tempU=`expr "$x" : ".*data-context-item-user=\"\(.*\)\" data-context-item-title="`
	tempU=${tempU//,/MY_COMMA}
	
	tempT=`expr "$x" : ".*data-context-item-time=\"\(.*\)\" data-context-item-views"`
	tempT=${tempT//,/MY_COMMA}
	
	tempTitle=`expr "$x" : ".*data-context-item-title=\"\(.*\)\">"`
	tempTitle=${tempTitle//,/MY_COMMA}

	echo $tempViews","$tempU","$tempT","$tempTitle >> index-2013-04-08-`echo $hr`-`echo $min`-table.txt;
    done
#ID, Type, Title, User, Time, Views 1:58
    hr="01"
    min="58"
    grep data-context-item index-2013-04-08-`echo $hr`-`echo $min`.html | while read x; do
	tempViews=`expr "$x" : ".*data-context-item-views=\"\([0-9,]*\)"`
	tempViews=${tempViews//,/}	#take out the commas, dont bother with MY_COMMA
	#I'm sorting based on Views and turning it into ints anyway, so no need to bother.

	tempU=`expr "$x" : ".*data-context-item-user=\"\(.*\)\" data-context-item-time="`
	tempU=${tempU//,/MY_COMMA}
	
	tempT=`expr "$x" : ".*data-context-item-time=\"\(.*\)\" data-context-item-views"`
	tempT=${tempT//,/MY_COMMA}
	
	tempTitle=`expr "$x" : ".*data-context-item-title=\"\(.*\)\" data-context-item-user"`
	tempTitle=${tempTitle//,/MY_COMMA}

	echo $tempViews","$tempU","$tempT","$tempTitle >> index-2013-04-08-`echo $hr`-`echo $min`-table.txt;
    done
#ID, Time, Title, Views, User, Type 1:46 1:57
    hr="01"
    min="46"
    grep data-context-item index-2013-04-08-`echo $hr`-`echo $min`.html | while read x; do
	tempViews=`expr "$x" : ".*data-context-item-views=\"\([0-9,]*\)"`
	tempViews=${tempViews//,/}	#take out the commas, dont bother with MY_COMMA
	#I'm sorting based on Views and turning it into ints anyway, so no need to bother.

	tempU=`expr "$x" : ".*data-context-item-user=\"\(.*\)\" data-context-item-type="`
	tempU=${tempU//,/MY_COMMA}
	
	tempT=`expr "$x" : ".*data-context-item-time=\"\(.*\)\" data-context-item-title"`
	tempT=${tempT//,/MY_COMMA}
	
	tempTitle=`expr "$x" : ".*data-context-item-title=\"\(.*\)\" data-context-item-views"`
	tempTitle=${tempTitle//,/MY_COMMA}

	echo $tempViews","$tempU","$tempT","$tempTitle >> index-2013-04-08-`echo $hr`-`echo $min`-table.txt;
    done
    hr="01"
    min="57"
    grep data-context-item index-2013-04-08-`echo $hr`-`echo $min`.html | while read x; do
	tempViews=`expr "$x" : ".*data-context-item-views=\"\([0-9,]*\)"`
	tempViews=${tempViews//,/}	#take out the commas, dont bother with MY_COMMA
	#I'm sorting based on Views and turning it into ints anyway, so no need to bother.

	tempU=`expr "$x" : ".*data-context-item-user=\"\(.*\)\" data-context-item-type="`
	tempU=${tempU//,/MY_COMMA}
	
	tempT=`expr "$x" : ".*data-context-item-time=\"\(.*\)\" data-context-item-title"`
	tempT=${tempT//,/MY_COMMA}
	
	tempTitle=`expr "$x" : ".*data-context-item-title=\"\(.*\)\" data-context-item-views"`
	tempTitle=${tempTitle//,/MY_COMMA}

	echo $tempViews","$tempU","$tempT","$tempTitle >> index-2013-04-08-`echo $hr`-`echo $min`-table.txt;
    done
#ID, Time, User, Views, Type, Title 1:32 1:40
    hr="01"
    min="32"
    grep data-context-item index-2013-04-08-`echo $hr`-`echo $min`.html | while read x; do
	tempViews=`expr "$x" : ".*data-context-item-views=\"\([0-9,]*\)"`
	tempViews=${tempViews//,/}	#take out the commas, dont bother with MY_COMMA
	#I'm sorting based on Views and turning it into ints anyway, so no need to bother.

	tempU=`expr "$x" : ".*data-context-item-user=\"\(.*\)\" data-context-item-views="`
	tempU=${tempU//,/MY_COMMA}
	
	tempT=`expr "$x" : ".*data-context-item-time=\"\(.*\)\" data-context-item-user"`
	tempT=${tempT//,/MY_COMMA}
	
	tempTitle=`expr "$x" : ".*data-context-item-title=\"\(.*\)\">"`
	tempTitle=${tempTitle//,/MY_COMMA}

	echo $tempViews","$tempU","$tempT","$tempTitle >> index-2013-04-08-`echo $hr`-`echo $min`-table.txt;
    done
    hr="01"
    min="40"
    grep data-context-item index-2013-04-08-`echo $hr`-`echo $min`.html | while read x; do
	tempViews=`expr "$x" : ".*data-context-item-views=\"\([0-9,]*\)"`
	tempViews=${tempViews//,/}	#take out the commas, dont bother with MY_COMMA
	#I'm sorting based on Views and turning it into ints anyway, so no need to bother.

	tempU=`expr "$x" : ".*data-context-item-user=\"\(.*\)\" data-context-item-views="`
	tempU=${tempU//,/MY_COMMA}
	
	tempT=`expr "$x" : ".*data-context-item-time=\"\(.*\)\" data-context-item-user"`
	tempT=${tempT//,/MY_COMMA}
	
	tempTitle=`expr "$x" : ".*data-context-item-title=\"\(.*\)\">"`
	tempTitle=${tempTitle//,/MY_COMMA}

	echo $tempViews","$tempU","$tempT","$tempTitle >> index-2013-04-08-`echo $hr`-`echo $min`-table.txt;
    done
#ID, Time, Type, Views, Title, User 2:05
    hr="02"
    min="05"
    grep data-context-item index-2013-04-08-`echo $hr`-`echo $min`.html | while read x; do
	tempViews=`expr "$x" : ".*data-context-item-views=\"\([0-9,]*\)"`
	tempViews=${tempViews//,/}	#take out the commas, dont bother with MY_COMMA
	#I'm sorting based on Views and turning it into ints anyway, so no need to bother.

	tempU=`expr "$x" : ".*data-context-item-user=\"\(.*\)\">"`
	tempU=${tempU//,/MY_COMMA}
	
	tempT=`expr "$x" : ".*data-context-item-time=\"\(.*\)\" data-context-item-type"`
	tempT=${tempT//,/MY_COMMA}
	
	tempTitle=`expr "$x" : ".*data-context-item-title=\"\(.*\)\" data-context-item-user"`
	tempTitle=${tempTitle//,/MY_COMMA}

	echo $tempViews","$tempU","$tempT","$tempTitle >> index-2013-04-08-`echo $hr`-`echo $min`-table.txt;
    done
#ID, Time, Type, Title, Views, User 2:10
    hr="02"
    min="10"
    grep data-context-item index-2013-04-08-`echo $hr`-`echo $min`.html | while read x; do
	tempViews=`expr "$x" : ".*data-context-item-views=\"\([0-9,]*\)"`
	tempViews=${tempViews//,/}	#take out the commas, dont bother with MY_COMMA
	#I'm sorting based on Views and turning it into ints anyway, so no need to bother.

	tempU=`expr "$x" : ".*data-context-item-user=\"\(.*\)\">"`
	tempU=${tempU//,/MY_COMMA}
	
	tempT=`expr "$x" : ".*data-context-item-time=\"\(.*\)\" data-context-item-type"`
	tempT=${tempT//,/MY_COMMA}
	
	tempTitle=`expr "$x" : ".*data-context-item-title=\"\(.*\)\" data-context-item-views"`
	tempTitle=${tempTitle//,/MY_COMMA}

	echo $tempViews","$tempU","$tempT","$tempTitle >> index-2013-04-08-`echo $hr`-`echo $min`-table.txt;
    done
#ID, title, time, views, user, type 1:25 1:30 1:42
    hr="01"
    min="25"
    grep data-context-item index-2013-04-08-`echo $hr`-`echo $min`.html | while read x; do
	tempViews=`expr "$x" : ".*data-context-item-views=\"\([0-9,]*\)"`
	tempViews=${tempViews//,/}	#take out the commas, dont bother with MY_COMMA
	#I'm sorting based on Views and turning it into ints anyway, so no need to bother.

	tempU=`expr "$x" : ".*data-context-item-user=\"\(.*\)\" data-context-item-type="`
	tempU=${tempU//,/MY_COMMA}
	
	tempT=`expr "$x" : ".*data-context-item-time=\"\(.*\)\" data-context-item-views"`
	tempT=${tempT//,/MY_COMMA}
	
	tempTitle=`expr "$x" : ".*data-context-item-title=\"\(.*\)\" data-context-item-time"`
	tempTitle=${tempTitle//,/MY_COMMA}

	echo $tempViews","$tempU","$tempT","$tempTitle >> index-2013-04-08-`echo $hr`-`echo $min`-table.txt;
    done
    hr="01"
    min="30"
    grep data-context-item index-2013-04-08-`echo $hr`-`echo $min`.html | while read x; do
	tempViews=`expr "$x" : ".*data-context-item-views=\"\([0-9,]*\)"`
	tempViews=${tempViews//,/}	#take out the commas, dont bother with MY_COMMA
	#I'm sorting based on Views and turning it into ints anyway, so no need to bother.

	tempU=`expr "$x" : ".*data-context-item-user=\"\(.*\)\" data-context-item-type="`
	tempU=${tempU//,/MY_COMMA}
	
	tempT=`expr "$x" : ".*data-context-item-time=\"\(.*\)\" data-context-item-views"`
	tempT=${tempT//,/MY_COMMA}
	
	tempTitle=`expr "$x" : ".*data-context-item-title=\"\(.*\)\" data-context-item-time"`
	tempTitle=${tempTitle//,/MY_COMMA}

	echo $tempViews","$tempU","$tempT","$tempTitle >> index-2013-04-08-`echo $hr`-`echo $min`-table.txt;
    done
    hr="01"
    min="42"
    grep data-context-item index-2013-04-08-`echo $hr`-`echo $min`.html | while read x; do
	tempViews=`expr "$x" : ".*data-context-item-views=\"\([0-9,]*\)"`
	tempViews=${tempViews//,/}	#take out the commas, dont bother with MY_COMMA
	#I'm sorting based on Views and turning it into ints anyway, so no need to bother.

	tempU=`expr "$x" : ".*data-context-item-user=\"\(.*\)\" data-context-item-type="`
	tempU=${tempU//,/MY_COMMA}
	
	tempT=`expr "$x" : ".*data-context-item-time=\"\(.*\)\" data-context-item-views"`
	tempT=${tempT//,/MY_COMMA}
	
	tempTitle=`expr "$x" : ".*data-context-item-title=\"\(.*\)\" data-context-item-time"`
	tempTitle=${tempTitle//,/MY_COMMA}

	echo $tempViews","$tempU","$tempT","$tempTitle >> index-2013-04-08-`echo $hr`-`echo $min`-table.txt;
    done

#ID, Title, Time, type, User, Views 1:20 1:50
    hr="01"
    min="20"
    grep data-context-item index-2013-04-08-`echo $hr`-`echo $min`.html | while read x; do
	tempViews=`expr "$x" : ".*data-context-item-views=\"\([0-9,]*\)"`
	tempViews=${tempViews//,/}	#take out the commas, dont bother with MY_COMMA
	#I'm sorting based on Views and turning it into ints anyway, so no need to bother.

	tempU=`expr "$x" : ".*data-context-item-user=\"\(.*\)\" data-context-item-views="`
	tempU=${tempU//,/MY_COMMA}
	
	tempT=`expr "$x" : ".*data-context-item-time=\"\(.*\)\" data-context-item-type"`
	tempT=${tempT//,/MY_COMMA}
	
	tempTitle=`expr "$x" : ".*data-context-item-title=\"\(.*\)\" data-context-item-time"`
	tempTitle=${tempTitle//,/MY_COMMA}

	echo $tempViews","$tempU","$tempT","$tempTitle >> index-2013-04-08-`echo $hr`-`echo $min`-table.txt;
    done
    hr="01"
    min="50"
    grep data-context-item index-2013-04-08-`echo $hr`-`echo $min`.html | while read x; do
	tempViews=`expr "$x" : ".*data-context-item-views=\"\([0-9,]*\)"`
	tempViews=${tempViews//,/}	#take out the commas, dont bother with MY_COMMA
	#I'm sorting based on Views and turning it into ints anyway, so no need to bother.

	tempU=`expr "$x" : ".*data-context-item-user=\"\(.*\)\" data-context-item-views="`
	tempU=${tempU//,/MY_COMMA}
	
	tempT=`expr "$x" : ".*data-context-item-time=\"\(.*\)\" data-context-item-type"`
	tempT=${tempT//,/MY_COMMA}
	
	tempTitle=`expr "$x" : ".*data-context-item-title=\"\(.*\)\" data-context-item-time"`
	tempTitle=${tempTitle//,/MY_COMMA}

	echo $tempViews","$tempU","$tempT","$tempTitle >> index-2013-04-08-`echo $hr`-`echo $min`-table.txt;
    done
#ID, Title, User, Time, Views, type 1:17
    hr="01"
    min="17"
    grep data-context-item index-2013-04-08-`echo $hr`-`echo $min`.html | while read x; do
	tempViews=`expr "$x" : ".*data-context-item-views=\"\([0-9,]*\)"`
	tempViews=${tempViews//,/}	#take out the commas, dont bother with MY_COMMA
	#I'm sorting based on Views and turning it into ints anyway, so no need to bother.

	tempU=`expr "$x" : ".*data-context-item-user=\"\(.*\)\" data-context-item-time="`
	tempU=${tempU//,/MY_COMMA}
	
	tempT=`expr "$x" : ".*data-context-item-time=\"\(.*\)\" data-context-item-views"`
	tempT=${tempT//,/MY_COMMA}
	
	tempTitle=`expr "$x" : ".*data-context-item-title=\"\(.*\)\" data-context-item-user"`
	tempTitle=${tempTitle//,/MY_COMMA}

	echo $tempViews","$tempU","$tempT","$tempTitle >> index-2013-04-08-`echo $hr`-`echo $min`-table.txt;
    done
#ID, Views, User, Title, Type, Time 1:44
    hr="01"
    min="44"
    grep data-context-item index-2013-04-08-`echo $hr`-`echo $min`.html | while read x; do
	tempViews=`expr "$x" : ".*data-context-item-views=\"\([0-9,]*\)"`
	tempViews=${tempViews//,/}	#take out the commas, dont bother with MY_COMMA
	#I'm sorting based on Views and turning it into ints anyway, so no need to bother.

	tempU=`expr "$x" : ".*data-context-item-user=\"\(.*\)\" data-context-item-title="`
	tempU=${tempU//,/MY_COMMA}
	
	tempT=`expr "$x" : ".*data-context-item-time=\"\(.*\)\">"`
	tempT=${tempT//,/MY_COMMA}
	
	tempTitle=`expr "$x" : ".*data-context-item-title=\"\(.*\)\" data-context-item-type"`
	tempTitle=${tempTitle//,/MY_COMMA}

	echo $tempViews","$tempU","$tempT","$tempTitle >> index-2013-04-08-`echo $hr`-`echo $min`-table.txt;
    done
#ID, Views, User, Title, Time, Type 2:03
    hr="02"
    min="03"
    grep data-context-item index-2013-04-08-`echo $hr`-`echo $min`.html | while read x; do
	tempViews=`expr "$x" : ".*data-context-item-views=\"\([0-9,]*\)"`
	tempViews=${tempViews//,/}	#take out the commas, dont bother with MY_COMMA
	#I'm sorting based on Views and turning it into ints anyway, so no need to bother.

	tempU=`expr "$x" : ".*data-context-item-user=\"\(.*\)\" data-context-item-title="`
	tempU=${tempU//,/MY_COMMA}
	
	tempT=`expr "$x" : ".*data-context-item-time=\"\(.*\)\" data-context-item-type"`
	tempT=${tempT//,/MY_COMMA}
	
	tempTitle=`expr "$x" : ".*data-context-item-title=\"\(.*\)\" data-context-item-time"`
	tempTitle=${tempTitle//,/MY_COMMA}

	echo $tempViews","$tempU","$tempT","$tempTitle >> index-2013-04-08-`echo $hr`-`echo $min`-table.txt;
    done
#ID, Views, Time, Title, type, User 1:13
    hr="01"
    min="13"
    grep data-context-item index-2013-04-08-`echo $hr`-`echo $min`.html | while read x; do
	tempViews=`expr "$x" : ".*data-context-item-views=\"\([0-9,]*\)"`
	tempViews=${tempViews//,/}	#take out the commas, dont bother with MY_COMMA
	#I'm sorting based on Views and turning it into ints anyway, so no need to bother.

	tempU=`expr "$x" : ".*data-context-item-user=\"\(.*\)\">"`
	tempU=${tempU//,/MY_COMMA}
	
	tempT=`expr "$x" : ".*data-context-item-time=\"\(.*\)\" data-context-item-title"`
	tempT=${tempT//,/MY_COMMA}
	
	tempTitle=`expr "$x" : ".*data-context-item-title=\"\(.*\)\" data-context-item-type"`
	tempTitle=${tempTitle//,/MY_COMMA}

	echo $tempViews","$tempU","$tempT","$tempTitle >> index-2013-04-08-`echo $hr`-`echo $min`-table.txt;
    done
#Time, Views, ID, Type, Title, User 1:31
    hr="01"
    min="31"
    grep data-context-item index-2013-04-08-`echo $hr`-`echo $min`.html | while read x; do
	tempViews=`expr "$x" : ".*data-context-item-views=\"\([0-9,]*\)"`
	tempViews=${tempViews//,/}	#take out the commas, dont bother with MY_COMMA
	#I'm sorting based on Views and turning it into ints anyway, so no need to bother.

	tempU=`expr "$x" : ".*data-context-item-user=\"\(.*\)\">"`
	tempU=${tempU//,/MY_COMMA}
	
	tempT=`expr "$x" : ".*data-context-item-time=\"\(.*\)\" data-context-item-view"`
	tempT=${tempT//,/MY_COMMA}
	
	tempTitle=`expr "$x" : ".*data-context-item-title=\"\(.*\)\" data-context-item-user"`
	tempTitle=${tempTitle//,/MY_COMMA}

	echo $tempViews","$tempU","$tempT","$tempTitle >> index-2013-04-08-`echo $hr`-`echo $min`-table.txt;
    done
#Time, Type, Views, Title, ID, User 1:53
    hr="01"
    min="53"
    grep data-context-item index-2013-04-08-`echo $hr`-`echo $min`.html | while read x; do
	tempViews=`expr "$x" : ".*data-context-item-views=\"\([0-9,]*\)"`
	tempViews=${tempViews//,/}	#take out the commas, dont bother with MY_COMMA
	#I'm sorting based on Views and turning it into ints anyway, so no need to bother.

	tempU=`expr "$x" : ".*data-context-item-user=\"\(.*\)\">"`
	tempU=${tempU//,/MY_COMMA}
	
	tempT=`expr "$x" : ".*data-context-item-time=\"\(.*\)\" data-context-item-type"`
	tempT=${tempT//,/MY_COMMA}
	
	tempTitle=`expr "$x" : ".*data-context-item-title=\"\(.*\)\" data-context-item-id"`
	tempTitle=${tempTitle//,/MY_COMMA}

	echo $tempViews","$tempU","$tempT","$tempTitle >> index-2013-04-08-`echo $hr`-`echo $min`-table.txt;
    done
#Time, ID, Type, Title, User, Views 1:56
    hr="01"
    min="56"
    grep data-context-item index-2013-04-08-`echo $hr`-`echo $min`.html | while read x; do
	tempViews=`expr "$x" : ".*data-context-item-views=\"\([0-9,]*\)"`
	tempViews=${tempViews//,/}	#take out the commas, dont bother with MY_COMMA
	#I'm sorting based on Views and turning it into ints anyway, so no need to bother.

	tempU=`expr "$x" : ".*data-context-item-user=\"\(.*\)\" data-context-item-views="`
	tempU=${tempU//,/MY_COMMA}
	
	tempT=`expr "$x" : ".*data-context-item-time=\"\(.*\)\" data-context-item-id"`
	tempT=${tempT//,/MY_COMMA}
	
	tempTitle=`expr "$x" : ".*data-context-item-title=\"\(.*\)\" data-context-item-user"`
	tempTitle=${tempTitle//,/MY_COMMA}

	echo $tempViews","$tempU","$tempT","$tempTitle >> index-2013-04-08-`echo $hr`-`echo $min`-table.txt;
    done
#Time, User, Views, Title, ID, Type 2:13
    hr="02"
    min="13"
    grep data-context-item index-2013-04-08-`echo $hr`-`echo $min`.html | while read x; do
	tempViews=`expr "$x" : ".*data-context-item-views=\"\([0-9,]*\)"`
	tempViews=${tempViews//,/}	#take out the commas, dont bother with MY_COMMA
	#I'm sorting based on Views and turning it into ints anyway, so no need to bother.

	tempU=`expr "$x" : ".*data-context-item-user=\"\(.*\)\" data-context-item-views="`
	tempU=${tempU//,/MY_COMMA}
	
	tempT=`expr "$x" : ".*data-context-item-time=\"\(.*\)\" data-context-item-user"`
	tempT=${tempT//,/MY_COMMA}
	
	tempTitle=`expr "$x" : ".*data-context-item-title=\"\(.*\)\" data-context-item-id"`
	tempTitle=${tempTitle//,/MY_COMMA}

	echo $tempViews","$tempU","$tempT","$tempTitle >> index-2013-04-08-`echo $hr`-`echo $min`-table.txt;
    done
#Type, ID, Time, User, Title, Views 1:33
    hr="01"
    min="33"
    grep data-context-item index-2013-04-08-`echo $hr`-`echo $min`.html | while read x; do
	tempViews=`expr "$x" : ".*data-context-item-views=\"\([0-9,]*\)"`
	tempViews=${tempViews//,/}	#take out the commas, dont bother with MY_COMMA
	#I'm sorting based on Views and turning it into ints anyway, so no need to bother.

	tempU=`expr "$x" : ".*data-context-item-user=\"\(.*\)\" data-context-item-title="`
	tempU=${tempU//,/MY_COMMA}
	
	tempT=`expr "$x" : ".*data-context-item-time=\"\(.*\)\" data-context-item-user"`
	tempT=${tempT//,/MY_COMMA}
	
	tempTitle=`expr "$x" : ".*data-context-item-title=\"\(.*\)\" data-context-item-views"`
	tempTitle=${tempTitle//,/MY_COMMA}

	echo $tempViews","$tempU","$tempT","$tempTitle >> index-2013-04-08-`echo $hr`-`echo $min`-table.txt;
    done
#Type, Title, Time, Views, id, User 1:15
    hr="01"
    min="15"
    grep data-context-item index-2013-04-08-`echo $hr`-`echo $min`.html | while read x; do
	tempViews=`expr "$x" : ".*data-context-item-views=\"\([0-9,]*\)"`
	tempViews=${tempViews//,/}	#take out the commas, dont bother with MY_COMMA
	#I'm sorting based on Views and turning it into ints anyway, so no need to bother.

	tempU=`expr "$x" : ".*data-context-item-user=\"\(.*\)\">"`
	tempU=${tempU//,/MY_COMMA}
	
	tempT=`expr "$x" : ".*data-context-item-time=\"\(.*\)\" data-context-item-views"`
	tempT=${tempT//,/MY_COMMA}
	
	tempTitle=`expr "$x" : ".*data-context-item-title=\"\(.*\)\" data-context-item-time"`
	tempTitle=${tempTitle//,/MY_COMMA}

	echo $tempViews","$tempU","$tempT","$tempTitle >> index-2013-04-08-`echo $hr`-`echo $min`-table.txt;
    done
#Type, Title, Time, User, Views, ID 2:04
    hr="02"
    min="04"
    grep data-context-item index-2013-04-08-`echo $hr`-`echo $min`.html | while read x; do
	tempViews=`expr "$x" : ".*data-context-item-views=\"\([0-9,]*\)"`
	tempViews=${tempViews//,/}	#take out the commas, dont bother with MY_COMMA
	#I'm sorting based on Views and turning it into ints anyway, so no need to bother.

	tempU=`expr "$x" : ".*data-context-item-user=\"\(.*\)\" data-context-item-views="`
	tempU=${tempU//,/MY_COMMA}
	
	tempT=`expr "$x" : ".*data-context-item-time=\"\(.*\)\" data-context-item-user"`
	tempT=${tempT//,/MY_COMMA}
	
	tempTitle=`expr "$x" : ".*data-context-item-title=\"\(.*\)\" data-context-item-time"`
	tempTitle=${tempTitle//,/MY_COMMA}

	echo $tempViews","$tempU","$tempT","$tempTitle >> index-2013-04-08-`echo $hr`-`echo $min`-table.txt;
    done
#Type, Time, Title, User, Views, ID 1:19
    hr="01"
    min="19"
    grep data-context-item index-2013-04-08-`echo $hr`-`echo $min`.html | while read x; do
	tempViews=`expr "$x" : ".*data-context-item-views=\"\([0-9,]*\)"`
	tempViews=${tempViews//,/}	#take out the commas, dont bother with MY_COMMA
	#I'm sorting based on Views and turning it into ints anyway, so no need to bother.

	tempU=`expr "$x" : ".*data-context-item-user=\"\(.*\)\" data-context-item-views="`
	tempU=${tempU//,/MY_COMMA}
	
	tempT=`expr "$x" : ".*data-context-item-time=\"\(.*\)\" data-context-item-title"`
	tempT=${tempT//,/MY_COMMA}
	
	tempTitle=`expr "$x" : ".*data-context-item-title=\"\(.*\)\" data-context-item-user"`
	tempTitle=${tempTitle//,/MY_COMMA}

	echo $tempViews","$tempU","$tempT","$tempTitle >> index-2013-04-08-`echo $hr`-`echo $min`-table.txt;
    done
#Type, Views, Title, ID, Time, User 2:01
    hr="02"
    min="01"
    grep data-context-item index-2013-04-08-`echo $hr`-`echo $min`.html | while read x; do
	tempViews=`expr "$x" : ".*data-context-item-views=\"\([0-9,]*\)"`
	tempViews=${tempViews//,/}	#take out the commas, dont bother with MY_COMMA
	#I'm sorting based on Views and turning it into ints anyway, so no need to bother.

	tempU=`expr "$x" : ".*data-context-item-user=\"\(.*\)\">"`
	tempU=${tempU//,/MY_COMMA}
	
	tempT=`expr "$x" : ".*data-context-item-time=\"\(.*\)\" data-context-item-user"`
	tempT=${tempT//,/MY_COMMA}
	
	tempTitle=`expr "$x" : ".*data-context-item-title=\"\(.*\)\" data-context-item-id"`
	tempTitle=${tempTitle//,/MY_COMMA}

	echo $tempViews","$tempU","$tempT","$tempTitle >> index-2013-04-08-`echo $hr`-`echo $min`-table.txt;
    done
#Title, User, Time, ID, Views, Type 1:52
    hr="01"
    min="52"
    grep data-context-item index-2013-04-08-`echo $hr`-`echo $min`.html | while read x; do
	tempViews=`expr "$x" : ".*data-context-item-views=\"\([0-9,]*\)"`
	tempViews=${tempViews//,/}	#take out the commas, dont bother with MY_COMMA
	#I'm sorting based on Views and turning it into ints anyway, so no need to bother.

	tempU=`expr "$x" : ".*data-context-item-user=\"\(.*\)\" data-context-item-time="`
	tempU=${tempU//,/MY_COMMA}
	
	tempT=`expr "$x" : ".*data-context-item-time=\"\(.*\)\" data-context-item-id"`
	tempT=${tempT//,/MY_COMMA}
	
	tempTitle=`expr "$x" : ".*data-context-item-title=\"\(.*\)\" data-context-item-user"`
	tempTitle=${tempTitle//,/MY_COMMA}

	echo $tempViews","$tempU","$tempT","$tempTitle >> index-2013-04-08-`echo $hr`-`echo $min`-table.txt;
    done
#Title, ID, User, type, Views, Time 1:18
    hr="01"
    min="18"
    grep data-context-item index-2013-04-08-`echo $hr`-`echo $min`.html | while read x; do
	tempViews=`expr "$x" : ".*data-context-item-views=\"\([0-9,]*\)"`
	tempViews=${tempViews//,/}	#take out the commas, dont bother with MY_COMMA
	#I'm sorting based on Views and turning it into ints anyway, so no need to bother.

	tempU=`expr "$x" : ".*data-context-item-user=\"\(.*\)\" data-context-item-type="`
	tempU=${tempU//,/MY_COMMA}
	
	tempT=`expr "$x" : ".*data-context-item-time=\"\(.*\)\">"`
	tempT=${tempT//,/MY_COMMA}
	
	tempTitle=`expr "$x" : ".*data-context-item-title=\"\(.*\)\" data-context-item-id"`
	tempTitle=${tempTitle//,/MY_COMMA}

	echo $tempViews","$tempU","$tempT","$tempTitle >> index-2013-04-08-`echo $hr`-`echo $min`-table.txt;
    done
#Title, ID, Views, User, Type, Time 1:48 1:51
    hr="01"
    min="48"
    grep data-context-item index-2013-04-08-`echo $hr`-`echo $min`.html | while read x; do
	tempViews=`expr "$x" : ".*data-context-item-views=\"\([0-9,]*\)"`
	tempViews=${tempViews//,/}	#take out the commas, dont bother with MY_COMMA
	#I'm sorting based on Views and turning it into ints anyway, so no need to bother.

	tempU=`expr "$x" : ".*data-context-item-user=\"\(.*\)\" data-context-item-type="`
	tempU=${tempU//,/MY_COMMA}
	
	tempT=`expr "$x" : ".*data-context-item-time=\"\(.*\)\">"`
	tempT=${tempT//,/MY_COMMA}
	
	tempTitle=`expr "$x" : ".*data-context-item-title=\"\(.*\)\" data-context-item-id"`
	tempTitle=${tempTitle//,/MY_COMMA}

	echo $tempViews","$tempU","$tempT","$tempTitle >> index-2013-04-08-`echo $hr`-`echo $min`-table.txt;
    done
    hr="01"
    min="51"
    grep data-context-item index-2013-04-08-`echo $hr`-`echo $min`.html | while read x; do
	tempViews=`expr "$x" : ".*data-context-item-views=\"\([0-9,]*\)"`
	tempViews=${tempViews//,/}	#take out the commas, dont bother with MY_COMMA
	#I'm sorting based on Views and turning it into ints anyway, so no need to bother.

	tempU=`expr "$x" : ".*data-context-item-user=\"\(.*\)\" data-context-item-type="`
	tempU=${tempU//,/MY_COMMA}
	
	tempT=`expr "$x" : ".*data-context-item-time=\"\(.*\)\">"`
	tempT=${tempT//,/MY_COMMA}
	
	tempTitle=`expr "$x" : ".*data-context-item-title=\"\(.*\)\" data-context-item-id"`
	tempTitle=${tempTitle//,/MY_COMMA}

	echo $tempViews","$tempU","$tempT","$tempTitle >> index-2013-04-08-`echo $hr`-`echo $min`-table.txt;
    done

#Title, Type, Time, User, Views, ID 2:09
    hr="02"
    min="09"
    grep data-context-item index-2013-04-08-`echo $hr`-`echo $min`.html | while read x; do
	tempViews=`expr "$x" : ".*data-context-item-views=\"\([0-9,]*\)"`
	tempViews=${tempViews//,/}	#take out the commas, dont bother with MY_COMMA
	#I'm sorting based on Views and turning it into ints anyway, so no need to bother.

	tempU=`expr "$x" : ".*data-context-item-user=\"\(.*\)\" data-context-item-views="`
	tempU=${tempU//,/MY_COMMA}
	
	tempT=`expr "$x" : ".*data-context-item-time=\"\(.*\)\" data-context-item-user"`
	tempT=${tempT//,/MY_COMMA}
	
	tempTitle=`expr "$x" : ".*data-context-item-title=\"\(.*\)\" data-context-item-type"`
	tempTitle=${tempTitle//,/MY_COMMA}

	echo $tempViews","$tempU","$tempT","$tempTitle >> index-2013-04-08-`echo $hr`-`echo $min`-table.txt;
    done
#Title, User, Views, Time, ID, Type 1:21 1:22
    hr="01"
    min="21"
    grep data-context-item index-2013-04-08-`echo $hr`-`echo $min`.html | while read x; do
	tempViews=`expr "$x" : ".*data-context-item-views=\"\([0-9,]*\)"`
	tempViews=${tempViews//,/}	#take out the commas, dont bother with MY_COMMA
	#I'm sorting based on Views and turning it into ints anyway, so no need to bother.

	tempU=`expr "$x" : ".*data-context-item-user=\"\(.*\)\" data-context-item-views="`
	tempU=${tempU//,/MY_COMMA}
	
	tempT=`expr "$x" : ".*data-context-item-time=\"\(.*\)\" data-context-item-id"`
	tempT=${tempT//,/MY_COMMA}
	
	tempTitle=`expr "$x" : ".*data-context-item-title=\"\(.*\)\" data-context-item-user"`
	tempTitle=${tempTitle//,/MY_COMMA}

	echo $tempViews","$tempU","$tempT","$tempTitle >> index-2013-04-08-`echo $hr`-`echo $min`-table.txt;
    done
    hr="01"
    min="22"
    grep data-context-item index-2013-04-08-`echo $hr`-`echo $min`.html | while read x; do
	tempViews=`expr "$x" : ".*data-context-item-views=\"\([0-9,]*\)"`
	tempViews=${tempViews//,/}	#take out the commas, dont bother with MY_COMMA
	#I'm sorting based on Views and turning it into ints anyway, so no need to bother.

	tempU=`expr "$x" : ".*data-context-item-user=\"\(.*\)\" data-context-item-views="`
	tempU=${tempU//,/MY_COMMA}
	
	tempT=`expr "$x" : ".*data-context-item-time=\"\(.*\)\" data-context-item-id"`
	tempT=${tempT//,/MY_COMMA}
	
	tempTitle=`expr "$x" : ".*data-context-item-title=\"\(.*\)\" data-context-item-user"`
	tempTitle=${tempTitle//,/MY_COMMA}

	echo $tempViews","$tempU","$tempT","$tempTitle >> index-2013-04-08-`echo $hr`-`echo $min`-table.txt;
    done

#Title, User, Views, ID, Type, Time 1:38 2:00
    hr="01"
    min="38"
    grep data-context-item index-2013-04-08-`echo $hr`-`echo $min`.html | while read x; do
	tempViews=`expr "$x" : ".*data-context-item-views=\"\([0-9,]*\)"`
	tempViews=${tempViews//,/}	#take out the commas, dont bother with MY_COMMA
	#I'm sorting based on Views and turning it into ints anyway, so no need to bother.

	tempU=`expr "$x" : ".*data-context-item-user=\"\(.*\)\" data-context-item-views="`
	tempU=${tempU//,/MY_COMMA}
	
	tempT=`expr "$x" : ".*data-context-item-time=\"\(.*\)\">"`
	tempT=${tempT//,/MY_COMMA}
	
	tempTitle=`expr "$x" : ".*data-context-item-title=\"\(.*\)\" data-context-item-user"`
	tempTitle=${tempTitle//,/MY_COMMA}

	echo $tempViews","$tempU","$tempT","$tempTitle >> index-2013-04-08-`echo $hr`-`echo $min`-table.txt;
    done
    hr="02"
    min="00"
    grep data-context-item index-2013-04-08-`echo $hr`-`echo $min`.html | while read x; do
	tempViews=`expr "$x" : ".*data-context-item-views=\"\([0-9,]*\)"`
	tempViews=${tempViews//,/}	#take out the commas, dont bother with MY_COMMA
	#I'm sorting based on Views and turning it into ints anyway, so no need to bother.

	tempU=`expr "$x" : ".*data-context-item-user=\"\(.*\)\" data-context-item-views="`
	tempU=${tempU//,/MY_COMMA}
	
	tempT=`expr "$x" : ".*data-context-item-time=\"\(.*\)\">"`
	tempT=${tempT//,/MY_COMMA}
	
	tempTitle=`expr "$x" : ".*data-context-item-title=\"\(.*\)\" data-context-item-user"`
	tempTitle=${tempTitle//,/MY_COMMA}

	echo $tempViews","$tempU","$tempT","$tempTitle >> index-2013-04-08-`echo $hr`-`echo $min`-table.txt;
    done

#Title, Views, Time, User, ID, Type 1:26 1:59
    hr="01"
    min="26"
    grep data-context-item index-2013-04-08-`echo $hr`-`echo $min`.html | while read x; do
	tempViews=`expr "$x" : ".*data-context-item-views=\"\([0-9,]*\)"`
	tempViews=${tempViews//,/}	#take out the commas, dont bother with MY_COMMA
	#I'm sorting based on Views and turning it into ints anyway, so no need to bother.

	tempU=`expr "$x" : ".*data-context-item-user=\"\(.*\)\" data-context-item-id="`
	tempU=${tempU//,/MY_COMMA}
	
	tempT=`expr "$x" : ".*data-context-item-time=\"\(.*\)\" data-context-item-user"`
	tempT=${tempT//,/MY_COMMA}
	
	tempTitle=`expr "$x" : ".*data-context-item-title=\"\(.*\)\" data-context-item-views"`
	tempTitle=${tempTitle//,/MY_COMMA}

	echo $tempViews","$tempU","$tempT","$tempTitle >> index-2013-04-08-`echo $hr`-`echo $min`-table.txt;
    done
    hr="01"
    min="59"
    grep data-context-item index-2013-04-08-`echo $hr`-`echo $min`.html | while read x; do
	tempViews=`expr "$x" : ".*data-context-item-views=\"\([0-9,]*\)"`
	tempViews=${tempViews//,/}	#take out the commas, dont bother with MY_COMMA
	#I'm sorting based on Views and turning it into ints anyway, so no need to bother.

	tempU=`expr "$x" : ".*data-context-item-user=\"\(.*\)\" data-context-item-id="`
	tempU=${tempU//,/MY_COMMA}
	
	tempT=`expr "$x" : ".*data-context-item-time=\"\(.*\)\" data-context-item-user"`
	tempT=${tempT//,/MY_COMMA}
	
	tempTitle=`expr "$x" : ".*data-context-item-title=\"\(.*\)\" data-context-item-views"`
	tempTitle=${tempTitle//,/MY_COMMA}

	echo $tempViews","$tempU","$tempT","$tempTitle >> index-2013-04-08-`echo $hr`-`echo $min`-table.txt;
    done

#Views, ID, Title, User, Time, Type 1:36 2:06
    hr="01"
    min="36"
    grep data-context-item index-2013-04-08-`echo $hr`-`echo $min`.html | while read x; do
	tempViews=`expr "$x" : ".*data-context-item-views=\"\([0-9,]*\)"`
	tempViews=${tempViews//,/}	#take out the commas, dont bother with MY_COMMA
	#I'm sorting based on Views and turning it into ints anyway, so no need to bother.

	tempU=`expr "$x" : ".*data-context-item-user=\"\(.*\)\" data-context-item-time="`
	tempU=${tempU//,/MY_COMMA}
	
	tempT=`expr "$x" : ".*data-context-item-time=\"\(.*\)\" data-context-item-type"`
	tempT=${tempT//,/MY_COMMA}
	
	tempTitle=`expr "$x" : ".*data-context-item-title=\"\(.*\)\" data-context-item-user"`
	tempTitle=${tempTitle//,/MY_COMMA}

	echo $tempViews","$tempU","$tempT","$tempTitle >> index-2013-04-08-`echo $hr`-`echo $min`-table.txt;
    done
    hr="02"
    min="06"
    grep data-context-item index-2013-04-08-`echo $hr`-`echo $min`.html | while read x; do
	tempViews=`expr "$x" : ".*data-context-item-views=\"\([0-9,]*\)"`
	tempViews=${tempViews//,/}	#take out the commas, dont bother with MY_COMMA
	#I'm sorting based on Views and turning it into ints anyway, so no need to bother.

	tempU=`expr "$x" : ".*data-context-item-user=\"\(.*\)\" data-context-item-time="`
	tempU=${tempU//,/MY_COMMA}
	
	tempT=`expr "$x" : ".*data-context-item-time=\"\(.*\)\" data-context-item-type"`
	tempT=${tempT//,/MY_COMMA}
	
	tempTitle=`expr "$x" : ".*data-context-item-title=\"\(.*\)\" data-context-item-user"`
	tempTitle=${tempTitle//,/MY_COMMA}

	echo $tempViews","$tempU","$tempT","$tempTitle >> index-2013-04-08-`echo $hr`-`echo $min`-table.txt;
    done

#Views, ID, Time, Type, Title, User 1:23
    hr="01"
    min="23"
    grep data-context-item index-2013-04-08-`echo $hr`-`echo $min`.html | while read x; do
	tempViews=`expr "$x" : ".*data-context-item-views=\"\([0-9,]*\)"`
	tempViews=${tempViews//,/}	#take out the commas, dont bother with MY_COMMA
	#I'm sorting based on Views and turning it into ints anyway, so no need to bother.

	tempU=`expr "$x" : ".*data-context-item-user=\"\(.*\)\">"`
	tempU=${tempU//,/MY_COMMA}
	
	tempT=`expr "$x" : ".*data-context-item-time=\"\(.*\)\" data-context-item-type"`
	tempT=${tempT//,/MY_COMMA}
	
	tempTitle=`expr "$x" : ".*data-context-item-title=\"\(.*\)\" data-context-item-user"`
	tempTitle=${tempTitle//,/MY_COMMA}

	echo $tempViews","$tempU","$tempT","$tempTitle >> index-2013-04-08-`echo $hr`-`echo $min`-table.txt;
    done
#Views, Title, Time, ID, Type, User 2:02
    hr="02"
    min="02"
    grep data-context-item index-2013-04-08-`echo $hr`-`echo $min`.html | while read x; do
	tempViews=`expr "$x" : ".*data-context-item-views=\"\([0-9,]*\)"`
	tempViews=${tempViews//,/}	#take out the commas, dont bother with MY_COMMA
	#I'm sorting based on Views and turning it into ints anyway, so no need to bother.

	tempU=`expr "$x" : ".*data-context-item-user=\"\(.*\)\">"`
	tempU=${tempU//,/MY_COMMA}
	
	tempT=`expr "$x" : ".*data-context-item-time=\"\(.*\)\" data-context-item-id"`
	tempT=${tempT//,/MY_COMMA}
	
	tempTitle=`expr "$x" : ".*data-context-item-title=\"\(.*\)\" data-context-item-time"`
	tempTitle=${tempTitle//,/MY_COMMA}

	echo $tempViews","$tempU","$tempT","$tempTitle >> index-2013-04-08-`echo $hr`-`echo $min`-table.txt;
    done
#Views, User, ID, Time, Type, Title 1:27
    hr="01"
    min="27"
    grep data-context-item index-2013-04-08-`echo $hr`-`echo $min`.html | while read x; do
	tempViews=`expr "$x" : ".*data-context-item-views=\"\([0-9,]*\)"`
	tempViews=${tempViews//,/}	#take out the commas, dont bother with MY_COMMA
	#I'm sorting based on Views and turning it into ints anyway, so no need to bother.

	tempU=`expr "$x" : ".*data-context-item-user=\"\(.*\)\" data-context-item-id="`
	tempU=${tempU//,/MY_COMMA}
	
	tempT=`expr "$x" : ".*data-context-item-time=\"\(.*\)\" data-context-item-type"`
	tempT=${tempT//,/MY_COMMA}
	
	tempTitle=`expr "$x" : ".*data-context-item-title=\"\(.*\)\">"`
	tempTitle=${tempTitle//,/MY_COMMA}

	echo $tempViews","$tempU","$tempT","$tempTitle >> index-2013-04-08-`echo $hr`-`echo $min`-table.txt;
    done
#Views, User, Time, ID, Title, Type 1:49
    hr="01"
    min="49"
    grep data-context-item index-2013-04-08-`echo $hr`-`echo $min`.html | while read x; do
	tempViews=`expr "$x" : ".*data-context-item-views=\"\([0-9,]*\)"`
	tempViews=${tempViews//,/}	#take out the commas, dont bother with MY_COMMA
	#I'm sorting based on Views and turning it into ints anyway, so no need to bother.

	tempU=`expr "$x" : ".*data-context-item-user=\"\(.*\)\" data-context-item-time="`
	tempU=${tempU//,/MY_COMMA}
	
	tempT=`expr "$x" : ".*data-context-item-time=\"\(.*\)\" data-context-item-id"`
	tempT=${tempT//,/MY_COMMA}
	
	tempTitle=`expr "$x" : ".*data-context-item-title=\"\(.*\)\" data-context-item-type"`
	tempTitle=${tempTitle//,/MY_COMMA}

	echo $tempViews","$tempU","$tempT","$tempTitle >> index-2013-04-08-`echo $hr`-`echo $min`-table.txt;
    done
#Views, Time, User, Type, ID, Title 1:29
    hr="01"
    min="29"
    grep data-context-item index-2013-04-08-`echo $hr`-`echo $min`.html | while read x; do
	tempViews=`expr "$x" : ".*data-context-item-views=\"\([0-9,]*\)"`
	tempViews=${tempViews//,/}	#take out the commas, dont bother with MY_COMMA
	#I'm sorting based on Views and turning it into ints anyway, so no need to bother.

	tempU=`expr "$x" : ".*data-context-item-user=\"\(.*\)\" data-context-item-type="`
	tempU=${tempU//,/MY_COMMA}
	
	tempT=`expr "$x" : ".*data-context-item-time=\"\(.*\)\" data-context-item-user"`
	tempT=${tempT//,/MY_COMMA}
	
	tempTitle=`expr "$x" : ".*data-context-item-title=\"\(.*\)\">"`
	tempTitle=${tempTitle//,/MY_COMMA}

	echo $tempViews","$tempU","$tempT","$tempTitle >> index-2013-04-08-`echo $hr`-`echo $min`-table.txt;
    done
#Views, Time, Type, ID, Title, User 1:28
    hr="01"
    min="28"
    grep data-context-item index-2013-04-08-`echo $hr`-`echo $min`.html | while read x; do
	tempViews=`expr "$x" : ".*data-context-item-views=\"\([0-9,]*\)"`
	tempViews=${tempViews//,/}	#take out the commas, dont bother with MY_COMMA
	#I'm sorting based on Views and turning it into ints anyway, so no need to bother.

	tempU=`expr "$x" : ".*data-context-item-user=\"\(.*\)\">"`
	tempU=${tempU//,/MY_COMMA}
	
	tempT=`expr "$x" : ".*data-context-item-time=\"\(.*\)\" data-context-item-type"`
	tempT=${tempT//,/MY_COMMA}
	
	tempTitle=`expr "$x" : ".*data-context-item-title=\"\(.*\)\" data-context-item-user"`
	tempTitle=${tempTitle//,/MY_COMMA}

	echo $tempViews","$tempU","$tempT","$tempTitle >> index-2013-04-08-`echo $hr`-`echo $min`-table.txt;
    done
#Views, Time, ID, Title, Type, User 1:55

    hr="01"
    min="55"
    grep data-context-item index-2013-04-08-`echo $hr`-`echo $min`.html | while read x; do
	tempViews=`expr "$x" : ".*data-context-item-views=\"\([0-9,]*\)"`
	tempViews=${tempViews//,/}	#take out the commas, dont bother with MY_COMMA
	#I'm sorting based on Views and turning it into ints anyway, so no need to bother.

	tempU=`expr "$x" : ".*data-context-item-user=\"\(.*\)\">"`
	tempU=${tempU//,/MY_COMMA}
	
	tempT=`expr "$x" : ".*data-context-item-time=\"\(.*\)\" data-context-item-id"`
	tempT=${tempT//,/MY_COMMA}
	
	tempTitle=`expr "$x" : ".*data-context-item-title=\"\(.*\)\" data-context-item-type"`
	tempTitle=${tempTitle//,/MY_COMMA}

	echo $tempViews","$tempU","$tempT","$tempTitle >> index-2013-04-08-`echo $hr`-`echo $min`-table.txt;
    done
}

main
