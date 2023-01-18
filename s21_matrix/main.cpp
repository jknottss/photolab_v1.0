#import "s21_matrix.h"

int main()
{
	std::vector<float> arr(9);
	for (int i = 0; i < 10; i++)
		arr[i] = 2;
	S21Matrix test1 = S21Matrix(3,3);
	test1.print();
	std::cout << "\n";
	S21Matrix test2 = S21Matrix(3, 3, arr);
	S21Matrix test3 = S21Matrix(3, 3, arr);
	S21Matrix res = scalarProduct(test3, test3);
	test2.print();
	std::cout << "\n";
	std::cout << sum(test2) << " - test2 sum" << std::endl;
	res.print();
}
