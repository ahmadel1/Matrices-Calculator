#include<iostream>
#include<string>
#include<cmath>
using namespace std;

//functions prototypes
void fillMatrixA(long double matA[][10], int r1);
void fillMatrixB(long double matB[][10], int r2);
void addMats(long double matA[][10], int r1, long double matB[][10], int r2);
void subMats(long double matA[][10], int r1, long double matB[][10], int r2);
void multMats(long double matA[][10], int r1, long double matB[][10], int r2);
long long matDet(long double matA[][10],int r);
void matDiv(long double  matA[][10], int r1, long double  matB[][10], int r2);

//Global variables
int r1=0,r2=0,c1=0,c2=0;

//main function
int main(){
    int y;
    cout << "Please enter dimensions of Matrix A:\n";
    cin >> r1 >> c1;
    cout << "Please enter dimensions of Matrix B:\n";
    cin >> r2 >> c2;
    long double  matA[10][10], matB[10][10];
    cout << "Please enter values of Matrix A:\n";
    fillMatrixA(matA, r1);
    cout << "Please enter values of Matrix B:\n";
    fillMatrixB(matB, r2);
    do{
        cout << "Please choose operation type(1: A+B, 2: A-B, 3: AxB, 4: A*inverse(B), 5: |A|, 6: |B|, 7: quit):"<< "\n";
        cin >> y;
        switch(y){
        case(1):
            addMats(matA, r1, matB, r2);
            break;
        case(2):
            subMats(matA, r1, matB, r2);
            break;
        case(3):
            multMats(matA, r1, matB, r2);
            break;
        case(4):
            matDiv(matA, r1, matB, r2);
            break;
        case(5):
            if(r1!=c1){
                cout << "The operation you chose is invalid for the given matrices." << "\n";
            }else{
                cout << matDet(matA,r1)<< "\n";
            }
            break;
        case(6):
            if(r2!=c2){
                cout << "The operation you chose is invalid for the given matrices." << "\n";
            }else{
                cout << matDet(matB,r2)<< "\n";
            }
            break;
        case(7):
            cout << "Thank you!"<< "\n";
            break;
        }}while(y!=7);

}
//End of main

//functions::

//function for filling the matrices
void fillMatrixA(long double matA[][10], int r1){
    for (int i=0; r1>i; i++){
        for(int j = 0; c1>j; j++){
            cin >> matA[i][j];
        }
    }
}
void fillMatrixB(long double matB[][10], int r2){
    for (int i=0; r2>i; i++){
        for(int j = 0; c2>j; j++){
            cin >> matB[i][j];
        }
    }
}
//end of filling functions

//addition function
void addMats(long double matA[][10], int r1, long double matB[][10], int r2){
    if(r1!=r2 || c1!=c2){
        cout << "The operation you chose is invalid for the given matrices." << "\n";
    }else{
        for(int i = 0 ; r1>i; i++){
        for (int j =0; c1>j; j++){
            cout << matA[i][j] + matB[i][j] << " ";
            }cout << "\n";
        }
    }
}
//end of addition functions

//subtraction function
void subMats(long double matA[][10], int r1, long double matB[][10], int r2){
    if(r1!=r2 || c1!=c2){
        cout << "The operation you chose is invalid for the given matrices." << "\n";
    }else{
        for(int i = 0 ; r1>i; i++){
        for (int j =0; c1>j; j++){
            cout << matA[i][j] - matB[i][j] << " ";
        }cout << "\n";
    }
    }
}
//end of subtraction functions

//Multiplication function
//for multiplication, number of columns of matrix A  must be equal number of rows of matrix B
void multMats(long double matA[][10], int r1, long double matB[][10], int r2){
    long double sum=0;
    if(c1!=r2){
        cout << "The operation you chose is invalid for the given matrices." << "\n";
    }else{
        for(int j=0; r1>j; j++){
            for(int i = 0; c2>i; i++){
                for(int k = 0; c1>k; k++){
                sum = (matA[j][k] * matB[k][i]) + sum;
           }sum = roundl(sum);
            if(sum == -0) {sum = 0;}
            cout << sum << " ";
            sum = 0;
        }cout << "\n";}
    }
}
//end of Multiplication function


//Determinant function
//the matrix must be square
long long matDet(long double mat[][10],int r){
    long double tempMat[10][10];
    long long result=0;
    if(r == 1){
        result = mat[0][0];
        return result;
    }else if(r == 2){
        result = mat[0][0]*mat[1][1] - mat[0][1]*mat[1][0];
        return result;
    }else{
        for(int i = 0; i<r; i++){
            int sign,temR=0,temC=0;
            if(i%2==0)sign=1;
            else sign = -1;
            for(int j=1; r>j; j++){
                for(int k=0; r>k; k++){
                    if(k==i)continue;
                    tempMat[temR][temC] = mat[j][k];
                    temC++;
                    if(temC == r-1){
                        temR++;
                        temC=0;
                    }
                }
            }result = result + mat[0][i]*sign*matDet(tempMat, r-1);
        }return result;
    }
}
//end of determinant function

//matrices division function
void matDiv(long double matA[][10], int r1, long double matB[][10], int r2){
    long double tempMat[10][10];
    long double tempMat2[10][10];
    long double detResult = matDet(matB,r2);
    if(detResult == 0){
        cout << "The operation you chose is invalid for the given matrices." << "\n";
    }else if(c2!=r2){
        cout << "The operation you chose is invalid for the given matrices." << "\n";
    }else if(r2==1){
        tempMat2[0][0] = pow(matB[0][0],-1);
        multMats(matA, r1, tempMat2, r2);
    }else if(r2 >= 2){
        for(int y = 0; y<r2; y++){
            for(int i = 0; i<r2; i++){
                int temR=0,temC=0;
                for(int j=0; r2>j; j++){
                    for(int k=0; r2>k; k++){
                        if(j==y)continue;
                        if(k==i)continue;
                        tempMat[temR][temC] = matB[j][k];
                        temC++;
                        if(temC == r2-1){
                        temR++;
                        temC=0;}
                        }
                    }tempMat2[i][y] = pow(detResult,-1) * matDet(tempMat,r2-1) * pow(-1,y+i);
                }
        }multMats(matA, r1, tempMat2, r2);
    }
}
//end matrices division function
//end of Functions s
