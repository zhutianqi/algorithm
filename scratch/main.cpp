#include <iostream>
#include <bits/stdc++.h>
#include <ranges>
#include "all.hpp"
#include <Eigen/Dense>
using namespace Eigen;
using namespace std;

int main(int argc, const char * argv[]) {
    // insert code here...
    cout << "Hello, World!\n";
    cout << "Hello, World Again from scratch!\n";

    MatrixXd A(3,3);
    VectorXd b(3);
    b << 1, 0, 1;
    A << 2, -1, 0,
         -1, 2, -1,
          0, -1, 2;
    cout << "A =\n" << A << endl;
    

    PartialPivLU<MatrixXd> lu(A);
    VectorXd x = lu.solve(b);
    cout << "Solution x =\n" << x << endl;
    MatrixXd L = MatrixXd::Identity(3,3);
    cout << "L =\n" << L << endl;
    // 如果要拿到 L, U, P  LU = L （strictly 下半 没有 I） + U
    L.triangularView<StrictlyLower>() = lu.matrixLU();
    MatrixXd U = lu.matrixLU().triangularView<Upper>();
    //

    PermutationMatrix<Dynamic, Dynamic> P = lu.permutationP();
    cout << "P =\n" << MatrixXd(P) << endl;
    return 0;
}
