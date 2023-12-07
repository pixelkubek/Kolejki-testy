#!/bin/bash

g++ @opcjeCpp main.cpp kol.cpp -o main.e
if [ $? != 0 ]; then
    exit -1
fi

licznik=1

while [[ true ]]; do
    python3 ./gen.py $licznik
    echo -n -e "Test $licznik...\t"
    ./main.e < ./dane.in
    if [[ $? -eq 0 ]]; then
        echo -e "\033[0;32mOK\e[0m"
    else
        echo -e "\033[0;31mBLAD\e[0m"
        echo -e "\033[0;33mPlik dane.in zostal zachowany\e[0m"
        break
    fi

    rm dane.in
    licznik=$(($licznik + 1))
done

rm main.e
