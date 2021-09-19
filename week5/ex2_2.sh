for i in {1..500}
do
    if ln ex2.txt file.lock;  then
        digit=$( tail -n 1 ex2.txt )
        ((digit++))
        echo  $digit >> ex2.txt
        rm file.lock
    fi
done