#include "lab.h"
// функция создания пустой матрицы
void ConstructEmpty(Matrix& out, size_t n, size_t m) {
    out.m_ = m;
    out.n_ = n;

    for (int i{}; i < m; i++) {
        out.data_[i] = new int[n];
    }
}
// Создает заполненную нулями матрицу n x m.
void Construct(Matrix& out, size_t n, size_t m) {
    out.m_ = m;
    out.n_ = n;

    for (int i{}; i < m; i++) {
        out.data_[i] = new int[n];
        for (int j{}; j < n; j++) {
            out.data_[i][j] = j;
        }
    }
}
// Освобождает выделенную память.
void Destruct(Matrix& in) {
    for (unsigned i{}; i < in.m_; i++)
    {
        delete[] in.data_[i];
    }
    delete[] in.data_;
}

// Создает копию матрицы |matrix|.
Matrix Copy(const Matrix& matrix) {
    Matrix matrix_copy;
    matrix_copy.m_ = matrix.m_;
    matrix_copy.n_ = matrix.n_;
    matrix_copy.data_ = matrix.data_;
    return matrix_copy;
}
// Возвращает сумму двух матриц.
// Если операция невозможна - вернуть пустую матрицу
Matrix Add(const Matrix& a, const Matrix& b) {
    Matrix sum{};
    sum.m_ = a.m_;
    sum.n_ = a.n_;
    sum.data_ = new int*[sum.m_]{};
    ConstructEmpty(sum, sum.n_, sum.m_);
    if (a.m_ == b.m_ && a.n_ == b.n_) {
        for (int i{}; i < sum.m_; i++) {;
            for (int j{}; j < sum.n_; j++) {
                sum.data_[i][j] = a.data_[i][j] + b.data_[i][j];
            }
        }
    }
    return sum;
}
// Возвращает разницу двух матриц.
// Если операция невозможна - вернуть пустую матрицу

Matrix Sub(const Matrix& a, const Matrix& b) {
    Matrix sub{};
    sub.m_ = a.m_;
    sub.n_ = b.n_;
    sub.data_ = new int*[sub.m_]{};
    ConstructEmpty(sub, sub.n_, sub.m_);
    if (a.m_ == b.m_ && a.n_ == b.n_) {
        for (int i{}; i < sub.m_; i++) {;
            for (int j{}; j < sub.n_; j++) {
                sub.data_[i][j] = a.data_[i][j] - b.data_[i][j];
            }
        }
    }
    return sub;
}
// Возвращает произведение двух матриц.
// Если операция невозможна - вернуть пустую матрицу
Matrix Mult(const Matrix& a, const Matrix& b) {
    Matrix mult{};
    mult.m_ = a.m_;
    mult.n_ = b.n_;
    mult.data_ = new int*[mult.m_]{};
    ConstructEmpty(mult, mult.n_, mult.m_);
    if (a.m_ == b.n_) {
        for (int i{}; i < mult.m_; i++) {
            for (int j{}; j < mult.n_; j++) {
                int c = 0;
                if (a.n_ >= b.m_){
                    for(int r{}; r < a.n_; r++) {
                        c+= a.data_[i][r] * b.data_[r][j];
                    }
                    mult.data_[i][j] = c;
                }
                else {
                    for(int r{}; r < b.n_; r++) {
                        c+= a.data_[i][r] * b.data_[r][j];
                    }
                    mult.data_[i][j] = c;
                }
            }
        }
    }
    return mult;
}

// Транспонирование матрицы.
void Transposition(Matrix& matrix) {
    if (matrix.m_ > matrix.n_) {

        for (int i{}; i < matrix.m_; i++) {
            int  *arr = new int[matrix.n_];
            for (int j{}; j < matrix.m_; j++) {
                arr[j] = matrix.data_[i][j];
            }
            matrix.data_[i] = arr;
            if (i == matrix.n_) {
                for(int ind{}; ind < matrix.m_; ind++) {
                    matrix.data_[ind][i] = matrix.data_[i][ind];
                }
                delete[] matrix.data_[i];
            }
        }

        for (int i{}; i < matrix.m_; i++) {
            for (int j{i}; j < matrix.n_; j++) {

                int tr_elem = matrix.data_[j][i];
                matrix.data_[j][i] = matrix.data_[i][j];
                matrix.data_[i][j] = tr_elem;
            }
        }

    }

    else {
        size_t str_count = matrix.m_;
        while(str_count < matrix.n_) {
            matrix.data_[str_count] = new int[matrix.m_];
            str_count++;
        }

        for (int i{}; i < matrix.n_; i++) {
            for (int j{i}; j < matrix.m_; j++) {

                int tr_elem = matrix.data_[j][i];
                matrix.data_[j][i] = matrix.data_[i][j];
                matrix.data_[i][j] = tr_elem;
            }
        }
    }
}
// Сравнение двух матриц.
bool operator==(const Matrix& a, const Matrix& b) {
    auto m = a.m_;
    auto n = a.n_;
    int count{};
    if (a.m_ == b.m_ && a.n_ == b.n_) {

        for (int i{}; i < m; i++) {
            for (int j{}; j < n; j++) {
                if(a.data_[i][j] == b.data_[i][j]){
                    count+=1;
                }
            }
        }
    }
    return (count == m * n);
}