OUT=test


clear
rm ${OUT}
g++ main.cpp -o ${OUT} \
    -std=c++11 \
    -Wall 
    # -Werror
    
./test