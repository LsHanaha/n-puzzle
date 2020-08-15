# usage: sh test.sh N_TIMES SIDE_LEN EURISTIC
# for example: sh test.sh 100 4 phased_manhattan

for i in `seq $1`
do
	map=$(python nice_puzzle_generator.py $2 solvable)
	echo $map
	time python test.py $map --euristic $3
	echo "\n"
done