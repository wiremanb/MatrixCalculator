//
//  main.cpp
//  
//
//  Created by Benjamin Wireman on 3/18/2015.
//
//

#include <iostream>
#include <iomanip>
#include <new>

typedef double** matrix;

struct matrixInfo
{
    matrix mat;
    int rows;
    int columns;
};

int columns=0, rows=0;

void createMatrix(int rowCount, int columnCount, matrix mat, matrixInfo &info, bool &created);
void printMat(matrixInfo);
double getDet(matrix);

int main(int argc, char* argv[])
{
//    for(int i = 0; i < 100; i++)
//    {
//        std::cout << i << std::setw(4) << std::endl;
//    }
    
    std::cout << "Rows: ";
    std::cin >> rows;
    std::cout << "Columns: ";
    std::cin >> columns;
    bool created = false;
    matrix myMat = NULL;
    matrixInfo matInfo;
    createMatrix(rows, columns, myMat, matInfo, created);
    if(created)
        printMat(matInfo);
    
    return 0;
}

void createMatrix(int rowCount, int columnCount, matrix mat, matrixInfo &info, bool &created)
{
    try
    {
        mat = new double*[rowCount];
        for(int i = 0; i < rowCount; ++i)
            mat[i] = new double[columnCount];
    }
    catch(std::bad_alloc)
    {
        created = false;
        return;
    }
    
    for(int r=0; r < rowCount; r++)
    {
        std::cout << "Row number " << r << std::endl;
        for(int c=0; c<columnCount; c++)
        {
            double storeThis = 0;
            std::cout << "Store: ";
            std::cin >> storeThis;
            mat[r][c] = storeThis;
        }
    }
    std::cout << std::endl;
    info.mat = mat;
    info.rows = rowCount;
    info.columns = columnCount;
    created = true;
}

void printMat(matrixInfo info)
{
    std::cout << "Your matrix is -> " << std::endl;
    std::cout << std::setw(10);
    for(int r=0; r<info.rows; r++)
    {
        for(int c=0; c<info.columns; c++)
        {
            std::cout << info.mat[r][c] << "   ";
        }
        std::cout << std::endl;
        std::cout << std::setw(10);
    }
}

double getDet(matrix mat)
{
    return 0.00;
}