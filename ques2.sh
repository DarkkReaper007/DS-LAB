echo Given diretory is $1
echo Given Regular expression is $2
ls "$1" | grep -E "$2"
echo Done
