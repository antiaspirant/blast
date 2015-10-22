#!/bin/bash

function usage() {
    echo -e "Usage: $0 <T>\n\tT\tamount of tests"
    echo "For each test T generates N random points with random coordinates. By default prints to stdout."
    exit
}

function randomN() {
    echo $(( ( RANDOM % $1 ) + 1 ))
}

function randomCoord() {
    echo $(( ( RANDOM % (( $1 + 1)) ) ))
}

[[ -z $1 ]] && usage
[[ $1 -lt 1 ]] && usage

T=$1
Nmax=200
Wmax=1000

echo $T

for (( i = 0 ; i < $T ; i++ )) ; do {
    N=`randomN ${Nmax}`;
    echo $N;
    for (( j = 0 ; j < $N ; j++ )) ; do {
        echo -ne `randomCoord ${Wmax}`" "`randomCoord $Wmax`" "`randomCoord $Wmax`"\n"
    } ; done
} ; done

