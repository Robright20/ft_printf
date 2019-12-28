Make

gcc main_ft.c libftprintf.a  && ./a.out > mine.txt

gcc main_ft2.c libftprintf.a && ./a.out > theirs.txt

DIFF=$(diff mine.txt theirs.txt)
red=`tput setaf 1`
green=`tput setaf 2`
bold='\033[1m'
none='\033[00m'

if [ "$DIFF" == "" ] 
then
	echo "${green}SUCCESS"
else
	echo -e "${red}${bold}RETARD${none}"
fi
tput sgr0

rm mine.txt
rm theirs.txt
rm ./a.out
