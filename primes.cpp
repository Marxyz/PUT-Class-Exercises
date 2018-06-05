#include <iostream>
#include <thread>
#include <vector>
#include <math.h>
#include <cstdlib>
#include <chrono>


using namespace std;


bool isPrime(int number) {

	double sqrt = pow(number, 0.5);

	for (int i = sqrt; i > 1; i--){
		if (number % i == 0){
			return false;
		}
	}
	return true;
}

long int findPrime(int number) {
	while (!isPrime(number)) {
		number--;
	}
	return number;
}

void findPrimes(vector<long int> numbers, vector<long int> indexes, vector<long int> &primes) {
	for (auto item : indexes) {
		primes.push_back(findPrime(numbers[item]));
	}
}

auto main()->int {

	srand(0);
	int numberCount, threadCount;
	cin >> numberCount>>threadCount;
	vector<long int> numbers;
	vector<long int> primeNumbers;
	vector<vector<long int>> indexes;
	vector<thread> threads;

	chrono::time_point<std::chrono::system_clock> start, end;

	for (int i = 0; i < numberCount; i++) {
		numbers.push_back(pow(rand(), 2) - 1);
	}
	
	indexes.resize(threadCount);


	for (int j = 0; j < numberCount; j++) {
		indexes[j%threadCount].push_back(j);
	}

	/*for (auto item : indexes) {
		for(auto itemx : item)
			cout << itemx << endl;
		cout << endl;
	}*/
	start = chrono::system_clock::now();
	for (int i = 0; i < threadCount; i++) {
		threads.push_back(thread(findPrimes, numbers, indexes[i], ref(primeNumbers)));
	}
	for (auto itr = threads.begin(); itr != threads.end(); itr++) {
		itr->join();
	}
	end = chrono::system_clock::now();
	chrono::duration<double> elapsed_time = end - start;
	cout << "czas: " << elapsed_time.count() << std::endl;
	/*for (auto item : primeNumbers) {
		cout << item <<" elo"<< endl;;
	}*/



	system("PAUSE");
	return 0;
}
