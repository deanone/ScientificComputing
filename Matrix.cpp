#include "Matrix.h"

// TODO: check how can I get the number of rows and columns of the matrix from the file
Matrix::Matrix(std::string matrixFilename, int nrows, int ncols)
{
    this->nrows = nrows;
    this->ncols = ncols;

    arr = new double[nrows * ncols];
    for (int i = 0; i < nrows; i++)
    {
        for (int j = 0; j < ncols; j++)
        {
            arr[(i * ncols) + j] = 0.0;
        }
    }

    std::fstream in(matrixFilename, std::ios::in);
    if (in.is_open())
    {
        std::string dataline = "";
        int i = 0;
        while (std::getline(in, dataline))
        {
            std::string item = "";
            std::istringstream inStream(dataline);
            int j = 0;
            while (getline(inStream, item, ','))
            {
                arr[(i * ncols) + j] = std::stod(item);
                j++;
            }
            i++;
        }
        in.close();
    }
}

Matrix::~Matrix()
{
    if (arr != nullptr)
    {
        delete[] arr;
    }
}

// TODO: check what to return when indexes are not within the allowed bounds
double& Matrix::operator()(int i, int j)
{
    if (((i >= 0) && (i < nrows)) && ((j >= 0) && (j < ncols)))
    {
        return arr[(i * ncols) + j];
    }
}

int Matrix::rows()
{
    return nrows;
}

int Matrix::cols()
{
    return ncols;
}

void Matrix::print()
{
    for (int i = 0; i < nrows; i++)
    {
        for (int j = 0; j < ncols; j++)
        {
            std::cout << arr[(i * ncols) + j] << " ";
        }
        std::cout << "\n";
    }
}