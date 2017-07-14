#!/bin/bash

function main()
{
    traverse
}

function traverse()
{
    echo "Directory: $1"
    cd $1
    echo `ls`
    echo "Directory: $1"
}


main $1
