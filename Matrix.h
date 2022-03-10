#ifndef MATRIX_H
#define MATRIX_H

#include "DataTypes.h"

class Matrix
{
    double* arr;    //  contiguous block of memory representing a 2D matrix accessed in row-major order
    int nrows;
    int ncols;

public:
    /*!
     * Constructor
     * @param matrixFilename the name of the (.csv) file that contains the Matrix.
     * @param nrows the number of rows of the Matrix.
     * @param ncols the number of columns of the Matrix.
     */
    Matrix(std::string matrixFilename, int nrows, int ncols);
    
    /*!
     * Destructor.
     */
    ~Matrix();

    /*!
     * Overloading of operator () for accessing elements of the Matrix using the notation Matrix(i, j) for 
     * the element in the i-th row and j-th column.
     * @param i the row index.
     * @param j the column index.
     * @return the element Matrix(i, j). 
     */
    double& operator()(int i, int j);
    
    /*!
     * Returns the number of rows.
     * @return the number of rows.
     */
    int rows();
    
    /*!
     * Returns the number of columns.
     * @return the number of columns.
     */
    int cols();
    
    /*!
     *  Prints the elements of the Matrix.
     */
    void print();
};

#endif  // MATRIX_H