#!/bin/sh

files=`ls $1/$1.*.in`
for f in $files
do
    len=`expr length $f`
    out=${f:0:$len-3}
    ret=`cat $f | ./a.out`
    outret=`cat "$out.out"`
    if [ $ret != $outret ]
    then
        echo $f
        echo 'cac: '$ret
        echo 'res: '$outret
    fi
done
