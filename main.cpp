#include "GenericFunc.h"
#include "Matrix.h"

int main()
{
    std::string matrixFilename = gnfnc::getExecutablePathAndMatchItWithFilename("mat.csv");
    int nrows = 6;
    int ncols = 6;
    Matrix A(matrixFilename, nrows, ncols);
    A.print();
    std::cout << A(3, 3) << "\n";
    return 0;
}