#include <iostream>
#include <chrono>
#include <random>
#include "../include/tmatrix.h"

enum operations {
	PLUS,
	MINUS,
	MULTIPLY,
	DIVIDE,
	COPY,
	COMPARE
};

auto average_test(size_t size, operations op, size_t iterations = 10) {
	int max_random = 10000;
	int min_random = 0;
	long long average_time = 0;
	for (size_t i = 0; i < iterations; i++) {
		TDynamicMatrix<double> matrix(size), matrix1(size);
		
		for (size_t i1 = 0; i1 < size; i1++) {
			for (size_t j1 = 0; j1 < size; j1++) {
				matrix[i1][j1] = min_random + std::rand() % static_cast<int>(max_random - min_random + 1);
				matrix1[i1][j1] = min_random + std::rand() % static_cast<int>(max_random - min_random + 1);
			}
		}

		std::chrono::steady_clock::time_point begin, end;

		switch (op)
		{
		case PLUS:
			begin = std::chrono::steady_clock::now();

			matrix + matrix1;

			end = std::chrono::steady_clock::now();
			break;
		case MINUS:
			begin = std::chrono::steady_clock::now();

			matrix - matrix1; 

			end = std::chrono::steady_clock::now();
			break;
		case COPY:
			begin = std::chrono::steady_clock::now();

			matrix = matrix1; 

			end = std::chrono::steady_clock::now();
			break;
		case COMPARE:
			begin = std::chrono::steady_clock::now();

			matrix == matrix1; 

			end = std::chrono::steady_clock::now();
			break;
		case MULTIPLY:
			begin = std::chrono::steady_clock::now();

			matrix * matrix1; 

			end = std::chrono::steady_clock::now();
			break;
		case DIVIDE:
			begin = std::chrono::steady_clock::now();

			matrix / matrix1;

			end = std::chrono::steady_clock::now();
			break;
		default:
			break;
		}

		auto elapsed_ms = std::chrono::duration_cast<std::chrono::milliseconds>(end - begin);
		average_time += elapsed_ms.count();
		cout << i + 1 << '\t' << elapsed_ms.count() << endl;
	}

	cout << "Average time: " << average_time / static_cast<double>(iterations) << endl;
	return average_time / static_cast<double>(iterations);
}

int main(int argc, char** arhv)
{
	auto begin = std::chrono::steady_clock::now();

	average_test(5, DIVIDE);

	auto end = std::chrono::steady_clock::now();
	auto elapsed_ms = std::chrono::duration_cast<std::chrono::milliseconds>(end - begin);
	cout << "Execution time: " << elapsed_ms.count();

}