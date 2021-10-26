link week1/file.txt  _ex2.txt
digit=($(ls -i _ex2.txt))
a=($(find week1/file.txt -inum $digit))
echo $a > ex2.txt
b=($(find week1/file.txt -inum $digit -exec rm {} \))

