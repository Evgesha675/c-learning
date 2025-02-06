#include <iostream>
#include <vector>

class Matrix {
private:
    std::vector<std::vector<int>> mat;
    int rows, cols;

public:
    Matrix(int r, int c) : rows(r), cols(c) {
        mat.resize(r, std::vector<int>(c, 0));
    }

    void input() {
        std::cout << "Введите элементы матрицы " << rows << "x" << cols << ":\n";
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                std::cin >> mat[i][j];
            }
        }
    }

    // Функция для отображения матрицы
    void display() const {
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                std::cout << mat[i][j] << " ";
            }
            std::cout << "\n";
        }
    }

    // Функция для умножения матриц
    Matrix multiply(const Matrix &other) {
        if (cols != other.rows) {
            throw std::invalid_argument("Невозможно перемножить матрицы: количество столбцов первой матрицы должно быть равно количеству строк второй.");
        }
        
        Matrix result(rows, other.cols); // Результирующая матрица

        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < other.cols; ++j) {
                for (int k = 0; k < cols; ++k) {
                    result.mat[i][j] += mat[i][k] * other.mat[k][j];
                }
            }
        }
        
        return result;
    }

    // Получить количество строк и столбцов
    int getRows() const { return rows; }
    int getCols() const { return cols; }
};

int main() {
    int m, n, p, q;
    
    // Вводим размеры первой матрицы
    std::cout << "Введите размеры первой матрицы (m x n): ";
    std::cin >> m >> n;
    Matrix mat1(m, n);
    mat1.input();

    // Вводим размеры второй матрицы
    std::cout << "Введите размеры второй матрицы (n x p): ";
    std::cin >> n >> p;
    Matrix mat2(n, p);
    mat2.input();

    // Перемножаем матрицы
    try {
        Matrix result = mat1.multiply(mat2);
        
        std::cout << "Результат умножения матриц:\n";
        result.display();
    } catch (const std::invalid_argument &e) {
        std::cerr << e.what() << "\n";
    }

    return 0;
}
ё