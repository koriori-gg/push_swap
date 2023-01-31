printf "\n**** error case ****\n"
printf "\n**** 4 3 a 2 ****\n"
ARG="4 3 a 2"; ./push_swap $ARG
ARG="4 3 a 2"; ./checker_Mac $ARG

printf "\n**** 2147483647 1 3 ****\n"
ARG="2147483647 1 3"; ./push_swap $ARG
ARG="2147483647 1 3"; ./push_swap $ARG | ./checker_Mac $ARG

printf "\n**** 2147483648 1 3 ****\n"
ARG="2147483648 1 3"; ./push_swap $ARG
ARG="2147483648 1 3"; ./checker_Mac $ARG

printf "\n**** -2147483648 1 3 ****\n"
ARG="-2147483648 1 3"; ./push_swap $ARG
ARG="-2147483648 1 3"; ./push_swap $ARG | ./checker_Mac $ARG

printf "\n**** -2147483649 1 3 ****\n"
ARG="-2147483649 1 3"; ./push_swap $ARG
ARG="-2147483649 1 3"; ./checker_Mac $ARG

printf "\n**** 1 1 3 ****\n"
ARG="1 1 3"; ./push_swap $ARG
ARG="1 1 3"; ./checker_Mac $ARG

printf "\n**** 1 1 3 ****\n"
ARG="1 1 3"; ./push_swap $ARG
ARG="1 1 3"; ./checker_Mac $ARG

printf "\n**** 1 2 3 ****\n"
ARG="1 2 3"; ./push_swap $ARG
ARG="1 2 3"; ./checker_Mac $ARG

