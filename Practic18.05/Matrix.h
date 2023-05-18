#pragma once
#include <iostream>
#include <vector>
using namespace std;

void stopProgram(string message) {
	cout << message << endl;
	cout << "Press any key to exit program" << endl;
	exit(1);
}

/*template <class T, int height, int width>
class Matrix {
	T m[height][width];
public:
	const auto& operator()(int j, int i)const {
		if (j < 0 || j >= height || i < 0 || i >= width)
			stopProgram("Matrix index error!");
		return m[j][i];
	}
	auto& operator()(int j, int i){
		if (j < 0 || j >= height || i < 0 || i >= width)
			stopProgram("Matrix index error!");
		return m[j][i];
	}
	auto getMin() {
		auto min = m[0][0];
		for (int j = 0; j < height; j++) {
			for (int i = 0; i < width; i++) {
				if (m[j][i] < min) min = m[j][i];
			}
		}
		return min;
	}
	auto getMax() {
		auto max = m[0][0];
		for (int j = 0; j < height; j++) {
			for (int i = 0; i < width; i++) {
				if (m[j][i] > max) max = m[j][i];
			}
		}
		return max;
	}
};

template <int height, int width>
class Matrix<const char*, height, width> {
	const char* m[height][width];
public:
	const auto& operator()(int j, int i)const {
		if (j < 0 || j >= height || i < 0 || i >= width)
			stopProgram("Matrix index error!");
		return m[j][i];
	}
	auto& operator()(int j, int i) {
		if (j < 0 || j >= height || i < 0 || i >= width)
			stopProgram("Matrix index error!");
		return m[j][i];
	}
	auto getMin() {
		auto min = m[0][0];
		for (int j = 0; j < height; j++) {
			for (int i = 0; i < width; i++) {
				if (strcmp(m[j][i], min) < 0) min = m[j][i];
			}
		}
		return min;
	}
	auto getMax() {
		auto max = m[0][0];
		for (int j = 0; j < height; j++) {
			for (int i = 0; i < width; i++) {
				if (strcmp(m[j][i], max) > 0) max = m[j][i];
			}
		}
		return max;
	}
};*/

template <class T>
class Matrix {
protected:
	int height;
	int width;
	T** m;
private:
	bool allocate(int h, int w) {
		if (h <= 0 && w <= 0) {
			return false;
		}
		height = h;
		width = w;
		m = new T * [height];
		for (int i = 0; i < height; i++) {
			m[i] = new T[width];
			for (int j = 0; j < width; j++) {
				m[i][j] = T();
			}
		}
		return true;
	}
	void clear() {
		if (m != nullptr) {
			for (int i = 0; i < height; i++) {
				delete[] m[i];
			}
			delete[] m;
		}
		m = nullptr;
	}
	void copyTo(T** from) {
		for (int i = 0; i < height; i++) {
			for (int j = 0; j < width; j++) {
				m[i][j] = from[i][j];
			}
		}
	}
public:
	Matrix(int h, int w) {
		if (h <= 0 || w <= 0) stopProgram("Wrong size");
		if (!allocate(h, w)) stopProgram("Wrong size");
	}
	Matrix(int size) : Matrix(size, size) {}
	Matrix() :height{ 0 }, width{ 0 }, m{ nullptr } {}
	Matrix(const Matrix& matrix) {
		clear();
		allocate(matrix.height, matrix.width);
		copyTo(matrix.m);
	}
	~Matrix() { clear(); }

	auto& operator()(int j, int i) {
		if (j < 0 || j >= height || i < 0 || i >= width)
			stopProgram("Matrix index error!");
		return m[j][i];
	}
	Matrix<T>& operator=(const Matrix<T>& matrix) {
		if (&matrix == this) {
			return *this;
		}
		clear();
		allocate(matrix.height, matrix.width);
		copyTo(matrix.m);
		return *this;
	}
	friend ostream& operator<< (ostream& out, const Matrix& matrix) {
		if (matrix.m == nullptr) out << "Empty matrix" << endl;
		for (int i = 0; i < matrix.height; i++) {
			for (int j = 0; j < matrix.width; j++) {
				out << matrix.m[i][j] << " ";
			}
			out << endl;
		}
		return out;
	}

};

template<class T>
class NumberMatrix : public Matrix<T> {
public:
	NumberMatrix(int h, int w) : Matrix<T>(h, w) {}
	NumberMatrix(int size) : NumberMatrix(size) {}

	void setRand(int max = 100, int min = 0) {
		for (int i = 0; i < this->height; i++) {
			for (int j = 0; j < this->width; j++) {
				this->m[i][j] = (T)(min + rand() % (max - min + 1));
			}
		}
	}
	friend NumberMatrix<T> operator+ (const NumberMatrix<T>& m1, const NumberMatrix<T>& m2) {
		if (m1.height != m2.height || m1.width != m2.width) stopProgram("Matrix sizes do not match!");

		NumberMatrix<T> mRes(m1.height, m1.width);
		for (int i = 0; i < mRes.height; i++) {
			for (int j = 0; j < mRes.width; j++) {
				mRes.m[i][j] = m1.m[i][j] + m2.m[i][j];
			}
		}
		return mRes;
	}
	friend NumberMatrix<T> operator- (const NumberMatrix<T>& m1, const NumberMatrix<T>& m2) {
		if (m1.height != m2.height || m1.width != m2.width) stopProgram("Matrix sizes do not match!");

		NumberMatrix<T> mRes(m1.height, m1.width);
		for (int i = 0; i < mRes.height; i++) {
			for (int j = 0; j < mRes.width; j++) {
				mRes[i][j] = m1.m[i][j] - m2.m[i][j];
			}
		}
		return mRes;
	}
	friend ostream& operator<< (ostream& out, const NumberMatrix& matrix) {
		if (matrix.m == nullptr) out << "Empty matrix" << endl;
		for (int i = 0; i < matrix.height; i++) {
			for (int j = 0; j < matrix.width; j++) {
				out << matrix.m[i][j] << " ";
			}
			out << endl;
		}
		return out;
	}

};

