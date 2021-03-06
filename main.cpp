#include <iostream>
#include "Matrix.h"
#include "Point.h"

int main() {
	int rows1 = 0;
	int columns1 = 0;
	int rows2 = 0;
	int columns2 = 0;
	int row_get = 0;
	int column_get = 0;
	const int row_id = 1;
	const int column_id = 1;
	int row_set = 0;
	int column_set = 0;
	int value;
	    
	try {
		std::cout << "Set rows for the 1st matrix: ";
		std::cin >> rows1;
		if (rows1 <= 0) {
			std::range_error et("Incorrect input");
			throw et;
		}
		std::cout << "Set columns for the 1st matrix: ";
		std::cin >> columns1;
		if (columns1 <= 0) {
			std::range_error et("Incorrect input");
			throw et;
		}
		  Matrix <int> m(rows1, columns1);
		std::cin >> m;
		std::cout << m;



		std::cout << "operator[][]:\n";
		std::cout << "Set row position: ";
		std::cin >> row_get;
		if (row_get <= 0) {
			std::invalid_argument ek("Incorrect input for [][]");

		}
		std::cout << "Set column position: ";
		std::cin >> column_get;
		if (column_get <= 0) {
			std::invalid_argument ek("Incorrect input for [][]");

		}
		std::cout << m[row_get][column_get] << std::endl;
		



		std::cout << "Testing get method\n";



		std::cout << "Set row position: ";
		std::cin >> row_get;
		std::cout << "Set column position: ";
		std::cin >> column_get;
		std::cout << m.get(row_get, column_get);



		std::cout << "\nTesting set method\n";



		std::cout << "Set row position: ";
		std::cin >> row_set;
		std::cout << "Set colum position: ";
		std::cin >> column_set;
		std::cout << "Set a value: ";
		std::cin >> value;
		m.set(row_set, column_set, value);
		std::cout << m;



		std::cout << "\nTesting the multiplication function\n";



		std::cout << "Set rows for 2nd matrix: ";
		std::cin >> rows2;
		std::cout << "Set columns for 2nd matrix: ";
		std::cin >> columns2;
		Matrix <int> m1(rows2, columns2);
		std::cin >> m1;
		std::cout << m.mul(m1);
	}
	catch (std::range_error& et) {
		std::cerr << "Error: " << et.what()<< std::endl;
	}
	catch (std::out_of_range& ek) {
		std::cerr << "Error: " << ek.what() << std::endl;
	}
	catch (std::exception& e) {
		std::cerr << "Error: " << e.what() << std::endl;
	}
	return 0;
}