# MyPush-Swap
for testing hihi :
for i in {1..10}; do ARG=$(seq 0 100 | shuf | tr '\n' ' '); ./push_swap $ARG | ./checker_linux $ARG; done