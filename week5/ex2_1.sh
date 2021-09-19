for i in {1..500}
do
    digit=$( tail -n 1 ex2.txt )
    ((digit++))
    echo  $digit >> ex2.txt
done