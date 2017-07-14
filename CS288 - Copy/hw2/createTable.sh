#!/bin/bash
#Vladimir Ventura
#2/17/2013
#Homework 2
#Notes: I find that having user names and titles with spaces in between makes it really hard to use output functions/"programs," such as the printf function... no nice way of organizing it; proof of this is in the Russian(?) user; that row is the ONLY one not formatted correctly... which leads me to believe the output and the storage of the data differ in length.
function constructTable()
{
    User="User" Views="Views" Time="Time" Title="Title"
    printf '%-30s %-40s %-40s %-40s\n' $User $Views $Time $Title
    grep data-context-item index.html | while read x; do
	tempViews=`expr "$x" : ".*data-context-item-views=\"\([0-9,]*\)"`;
	tempU=`expr "$x" : ".*data-context-item-user=\"\(.*\)\" data-context-item-type"`
	tempT=`expr "$x" : ".*data-context-item-time=\"\(.*\)\" data-context-item-views"`;
	tempTitle=`expr "$x" : ".*data-context-item-title=\"\(.*\)\" data-context-item-time"`;

	 printf "%-30s %-40s %-40s %-40s\n" "${tempU} " "${tempViews//,/}" "$tempT" "$tempTitle"
    done

# userName=( )
#    grep data-context-item-user index.html| while read x; do tempU=`expr "$x" : ".*data-context-item-user=\"\(.*\)\" data-context-item-type"`; echo $tempU;done;

#    t=`grep data-context-item-time index.html`
#    newT=( )
#    for x in $t; do
#	tempT=`expr "$x" : ".*data-context-item-time=\"\(.*\)\""`;
#	#echo $tempT
#	newT=(${newT[@]} $tempT);
 #   done
#
#
 #allTitles=( )
  #  grep data-context-item-title index.html| while read x; do tempTitle=`expr "$x" : ".*data-context-item-title=\"\(.*\)\" data-context-item-time"`;
#allTitles=(${allTitles[@]} $tempTitle); echo $tempTitle; done



}


function main()
{

    constructTable

exit
exit



#below is the process through which I got the above.


##################################
# quick way to get partial views #
##################################
    
#    s=`grep views index.html | grep -v div | cut -d " " -f5| while read x; do echo ${x//,/}; done`

#    echo $s; #this shows SOME, but not ALL views
################
#     Views    #
################

    views=( )
    grep data-context-item-views index.html | while read x; do
	tempViews=`expr "$x" : ".*data-context-item-views=\"\([0-9,]*\)"`;
#	views=(${views[@]} ${tempViews[@]}); 
	echo ${tempViews//,/};
    done
    
############
#gets me the views using space as a delimiter...
############
#    d=`grep data-context-item-views index.html`
#    #this way shows ALL video views on the page
#    for x in $d; do
#	tempViews=`expr "$x" : ".*data-context-item-views=\"\([0-9,]*\)"` #the views is on another line when you read using the for x in $variable loop.
#	views=(${views[@]} $tempViews);
#    done;

    for x in ${views[@]}; do
	#echo $x;
	echo ${x//,/};
    done;
#################
#      users    #
#################

    userName=( )
    grep data-context-item-user index.html| while read x; do tempU=`expr "$x" : ".*data-context-item-user=\"\(.*\)\" data-context-item-type"`; echo $tempU;done;
#####################
# I can't use space as a delimiter, as some users have a space in their name..
#####################
  #  for x in $user; do
#	echo $x;
 #   done
    #for x in $user; do
#	tempUser=`expr "$x" : ".*\"ltr\">\(.*\)<\/a>"`
#	echo $tempUser
#	userName=(${userName[@]} $tempUser);
 #   done
#    for x in ${userName[@]}; do
#	echo $x;
#	done;
 #   echo $userName;

##############
#    times   #
##############
    t=`grep data-context-item-time index.html`
    newT=( )
    for x in $t; do
	tempT=`expr "$x" : ".*data-context-item-time=\"\(.*\)\""`;
	#echo $tempT
	newT=(${newT[@]} $tempT);
    done
    
    for x in ${newT[@]}; do
	echo $x;
    done;

##################
#     Titles     #
##################

    allTitles=( )
    grep data-context-item-title index.html| while read x; do tempT=`expr "$x" : ".*data-context-item-title=\"\(.*\)\" data-context-item-time"`;
allTitles=(${allTitles[@]} $tempT); echo $tempT; done

###################################################
#    Nope, can't use spaces here either...        #
###################################################
#    for x in $title; do
#	tempTitle=`expr "$x" : ".*data-context-item-title=\"\(.*\)\""`;
#	allTitles=(${allTitles[@]} $tempTitle);
 #   done
    
#    for x in ${allTitles[@]}; do
#	echo $x;
#    done;


}

main