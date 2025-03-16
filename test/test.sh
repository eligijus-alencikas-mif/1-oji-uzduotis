> ./test_res.txt
for i in {1..5}
do
../build/1-oji-uzduotis < ./1000t.txt
cat ./laikai.txt >> ./test_res.txt
echo  >> ./test_res.txt
done
echo "-" >> ./test_res.txt
for i in {1..5}
do
../build/1-oji-uzduotis < ./10000t.txt
cat ./laikai.txt >> ./test_res.txt
echo  >> ./test_res.txt
done
echo "-" >> ./test_res.txt
for i in {1..5}
do
../build/1-oji-uzduotis < ./100000t.txt
cat ./laikai.txt >> ./test_res.txt
echo  >> ./test_res.txt
done
echo "-" >> ./test_res.txt
for i in {1..5}
do
../build/1-oji-uzduotis < ./1000000t.txt
cat ./laikai.txt >> ./test_res.txt
echo  >> ./test_res.txt
done
echo "-" >> ./test_res.txt
for i in {1..5}
do
../build/1-oji-uzduotis < ./10000000t.txt
cat ./laikai.txt >> ./test_res.txt
echo  >> ./test_res.txt
done