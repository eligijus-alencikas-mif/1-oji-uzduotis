> ./test_res.txt
for i in {1..5}
do
../build/1-oji-uzduotis < ./test_cases/1000t.txt
cat ./laikai.txt >> ./test_res.txt
echo  >> ./test_res.txt
done
echo "-" >> ./test_res.txt

for i in {1..5}
do
../build/1-oji-uzduotis < ./test_cases/10000t.txt
cat ./laikai.txt >> ./test_res.txt
echo  >> ./test_res.txt
done
echo "-" >> ./test_res.txt

for i in {1..5}
do
../build/1-oji-uzduotis < ./test_cases/100000t.txt
cat ./laikai.txt >> ./test_res.txt
echo  >> ./test_res.txt
done
echo "-" >> ./test_res.txt

for i in {1..5}
do
../build/1-oji-uzduotis < ./test_cases/1000000t.txt
cat ./laikai.txt >> ./test_res.txt
echo  >> ./test_res.txt
done
echo "-" >> ./test_res.txt

for i in {1..5}
do
../build/1-oji-uzduotis < ./test_cases/10000000t.txt
cat ./laikai.txt >> ./test_res.txt
echo  >> ./test_res.txt
done

rm ./out.txt ./laikai.txt ./nuskriaustukai.txt ./galvociai.txt
./time-table ms