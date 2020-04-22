if g++ $1.cpp -o $1 ;
then
	echo "Successful Compilation"
	echo "Enter input";
	./$1
else
	echo "Compilation failed!";
fi


#PID=$!
#wait $PID


