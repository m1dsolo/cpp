#!/bin/bash

if [ $# != 1 ];then
    echo "please input 1 arg"
    exit
fi

mkdir $1
cd $1
touch $1.c
touch $1.h
touch _$1.h

echo "#include \"$1.h\"" >> $1.c
echo "#include \"_$1.h\"" >> $1.c
echo '#pragma once' >> $1.h
echo "" >> $1.h
echo "#include \"../game_head.h\"" >> $1.h
echo '#pragma once' >> _$1.h
echo "" >> _$1.h
echo "#include \"../game_head.h\"" >> _$1.h

cd ..