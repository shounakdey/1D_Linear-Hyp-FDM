/*********************************************************************************************
 * Copyright (c) <2019>, <Diwakar S.V.@JNCASR>                                               *
 *  All rights reserved.                                                                     *
 *   Redistribution and use in source and binary forms, with or without modification, are    *
 *   permitted provided that the following conditions are met:                               *
 *                                                                                           *
 *    1. Redistributions of source code must retain the above copyright notice, this list of *
 *       conditions and the following disclaimer.                                            *
 *    2. Redistributions in binary form must reproduce the above copyright notice, this list *
 *       of conditions and the following disclaimer in the documentation and/or other        *
 *       materials provided with the distribution.                                           *
 *    3. Neither the name of the <JNCASR> nor the names of its contributors may be used to   *
 *       endorse or promote products derived from this software without specific prior       *
 *       written permission.                                                                 *
 *                                                                                           *
 *       THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND     *
 *       ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED       *
 *       WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.  *
 *       IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT,    *
 *       INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING,      *
 *       BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,       *
 *       DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF     *
 *       LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE     *
 *       OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED   *
 *       OF THE POSSIBILITY OF SUCH DAMAGE.                                                  *
 *       Contributors:         Akshaysingh Shekhawat, Nishant Soni, and Diwakar S. V.        *
 *       Suggestions:          diwakar@jncasr.ac.in                                          *
 *       Bugs:                 diwakar@jncasr.ac.in                                          *
 *                                                                                           *
 *********************************************************************************************/

//THE BASIC MATRIX CLASS
#include <mm_malloc.h>

template <typename T> class AMatrix 
{
public:                                                                                     //public
    T * mat;
    unsigned int cols;
    unsigned int rows;
    unsigned int mols;
    unsigned int tols;
                                                                                            //Constructors
    AMatrix(unsigned int c, unsigned int r, unsigned int m, unsigned int t);
    AMatrix(unsigned int c, unsigned int r, unsigned int m);
    AMatrix(unsigned int c, unsigned int r);
    AMatrix(unsigned int c);
    AMatrix(const AMatrix<T>& rhs);
    ~AMatrix();

                                                                                            //Operator overloading
    T& operator()(const unsigned int c, const unsigned int r, const unsigned int m, const unsigned int t)       { return mat[ c*rows*mols*tols + r*mols*tols + m*tols + t ];}
    T  operator()(const unsigned int c, const unsigned int r, const unsigned int m, const unsigned int t) const { return mat[ c*rows*mols*tols + r*mols*tols + m*tols + t ];}
    T& operator()(const unsigned int c, const unsigned int r, const unsigned int m)       { return mat[ c*rows*mols + r*mols + m ];}
    T  operator()(const unsigned int c, const unsigned int r, const unsigned int m) const { return mat[ c*rows*mols + r*mols + m ];}
    T& operator()(const unsigned int c, const unsigned int r)       { return mat[ c*rows + r ];}
    const T  operator()(const unsigned int c, const unsigned int r) const { return mat[ c*rows + r ];}
    T& operator()(const unsigned int c)       { return mat[c];}
    const T  operator()(const unsigned int c) const { return mat[c];}
};

//Constructors
template<typename T> AMatrix<T>::AMatrix(unsigned int c, unsigned int r, unsigned int m, unsigned int t) {
    mat=(T *) _mm_malloc(c*r*m*t*sizeof(T), 4096);
    cols = c;
    rows = r;
    mols = m;
    tols = t;
}

template<typename T> AMatrix<T>::AMatrix(unsigned int c, unsigned int r, unsigned int m) {
    mat=(T *) _mm_malloc(c*r*m*sizeof(T), 4096);
    cols = c;
    rows = r;
    mols = m;
    tols = 1;
}

template<typename T> AMatrix<T>::AMatrix(unsigned int c, unsigned int r) {
    mat=(T *) _mm_malloc(c*r*sizeof(T), 4096);
    cols = c;
    rows = r;
    mols = 1;
    tols = 1;
}

template<typename T> AMatrix<T>::AMatrix(unsigned int c) {
    mat=(T *) _mm_malloc(c*sizeof(T), 4096);
    cols = c;
    rows = 1;
    mols = 1;
    tols = 1;
}

//Copy constructor
template<typename T> AMatrix<T>::AMatrix(const AMatrix<T>& rhs) {
     cols = rhs.cols;
     rows = rhs.rows;
     mols = rhs.mols;
     tols = rhs.tols;
     mat=rhs.mat;
}
//Destructor
template<typename T> AMatrix<T>::~AMatrix() {
    //free(mat);
}
///Matrix Swap
template <typename T> void swapAMatrix(AMatrix<T>& A, AMatrix<T>& B){
    T * swap_mat;
    swap_mat = A.mat;
    unsigned int swap_cols = A.cols;
    unsigned int swap_rows = A.rows;
    unsigned int swap_mols = A.mols;
    unsigned int swap_tols = A.tols;

    A.mat = B.mat;
    A.cols = B.cols;
    A.rows = B.rows;
    A.mols = B.mols;
    A.tols = B.tols;

    B.mat = swap_mat;
    B.cols = swap_cols;
    B.rows = swap_rows;
    B.mols = swap_mols;
    B.tols = swap_tols;
}
