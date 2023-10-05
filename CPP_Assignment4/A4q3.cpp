#include <iostream>
using namespace std;

class Matrix
{
private:
    int rows;
    int cols;
    int **matrix;

public:
    // Parameter-less constructor
    Matrix()
    {
        rows = 0;
        cols = 0;
        matrix = nullptr;
    }

    // Parameterized constructor to allocate memory dynamically
    Matrix(int numRows, int numCols)
    {
        rows = numRows;
        cols = numCols;
        matrix = new int *[rows];
        for (int i = 0; i < rows; i++)
        {
            matrix[i] = new int[cols];
        }
    }

    // Destructor to deallocate memory
    ~Matrix()
    {
        if (matrix != nullptr)
        {
            for (int i = 0; i < rows; i++)
            {
                delete[] matrix[i];
            }
            delete[] matrix;
        }
    }

    // Function to accept input for the matrix
    void accept()
    {
        cout << "Enter matrix elements:" << endl;
        for (int i = 0; i < rows; i++)
        {
            for (int j = 0; j < cols; j++)
            {
                cin >> matrix[i][j];
            }
        }
    }

    // Function to print the matrix
    void print()
    {
        cout << "Matrix:" << endl;
        for (int i = 0; i < rows; i++)
        {
            for (int j = 0; j < cols; j++)
            {
                cout << matrix[i][j] << " ";
            }
            cout << endl;
        }
    }

    // Function to add two matrices
    Matrix add(const Matrix &other)
    {
        if (rows != other.rows || cols != other.cols)
        {
            cout << "Matrix dimensions do not match for addition." << endl;
            return Matrix();
        }

        Matrix result(rows, cols);

        for (int i = 0; i < rows; i++)
        {
            for (int j = 0; j < cols; j++)
            {
                result.matrix[i][j] = matrix[i][j] + other.matrix[i][j];
            }
        }

        return result;
    }

    // Function to subtract two matrices
    Matrix subtract(const Matrix &other)
    {
        if (rows != other.rows || cols != other.cols)
        {
            cout << "Matrix dimensions do not match for subtraction." << endl;
            return Matrix();
        }

        Matrix result(rows, cols);

        for (int i = 0; i < rows; i++)
        {
            for (int j = 0; j < cols; j++)
            {
                result.matrix[i][j] = matrix[i][j] - other.matrix[i][j];
            }
        }

        return result;
    }

    // Function to multiply two matrices
    Matrix multiply(const Matrix &other)
    {
        if (cols != other.rows)
        {
            cout << "Matrix dimensions do not allow multiplication." << endl;
            return Matrix();
        }

        Matrix result(rows, other.cols);

        for (int i = 0; i < rows; i++)
        {
            for (int j = 0; j < other.cols; j++)
            {
                result.matrix[i][j] = 0;
                for (int k = 0; k < cols; k++)
                {
                    result.matrix[i][j] += matrix[i][k] * other.matrix[k][j];
                }
            }
        }

        return result;
    }

    // Function to transpose the matrix
    Matrix transpose()
    {
        Matrix result(cols, rows);

        for (int i = 0; i < cols; i++)
        {
            for (int j = 0; j < rows; j++)
            {
                result.matrix[i][j] = matrix[j][i];
            }
        }

        return result;
    }
};

int main()
{
    int numRows, numCols;

    cout << "Enter the number of rows and columns for Matrix A:" << endl;
    cin >> numRows >> numCols;

    Matrix matrixA(numRows, numCols);
    matrixA.accept();

    cout << "Matrix A:" << endl;
    matrixA.print();

    cout << "Enter the number of rows and columns for Matrix B:" << endl;
    cin >> numRows >> numCols;

    Matrix matrixB(numRows, numCols);
    matrixB.accept();

    cout << "Matrix B:" << endl;
    matrixB.print();

    Matrix result;

    // Add matrices A and B
    result = matrixA.add(matrixB);
    cout << "Matrix A + Matrix B:" << endl;
    result.print();

    // Subtract matrices B from A
    result = matrixA.subtract(matrixB);
    cout << "Matrix A - Matrix B:" << endl;
    result.print();

    // Multiply matrices A and B
    result = matrixA.multiply(matrixB);
    cout << "Matrix A * Matrix B:" << endl;
    result.print();

    // Transpose matrix A
    result = matrixA.transpose();
    cout << "Transpose of Matrix A:" << endl;
    result.print();

    return 0;
}
