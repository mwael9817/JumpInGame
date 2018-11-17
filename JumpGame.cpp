#include <iostream>
using namespace std;


//-------------------------
//Mohamed Wa'el Abdelhady |
//20170260                |
//--------------------------


int jumpIt(int gameBoardArr[], int gameBoardArrSize, int n);

int main() {
    int lowCostJump;
    int gameBoardArr[] = {0, 3, 80, 6, 57, 10,5,5};
    int gameBoardArrSize = 8;

    int n = 0;

    for (int i = 0; i < gameBoardArrSize; i++) {
        cout<<gameBoardArr[i]<<" ";
    }

    cout<<endl;

    lowCostJump = jumpIt(gameBoardArr, gameBoardArrSize - 1, n);
    cout<<"Jump board lowest cost is: "<<lowCostJump<<endl;


    return 0;
}
//Recursive solution

int jumpIt(int gameBoardArr[], int gameBoardArrSize, int n) {

    // if index position is equal to gameBoardArrSize

    if (n == gameBoardArrSize) {
        return gameBoardArr[n];
    }

    // if there are only the first and last element in the array

     else if (n == gameBoardArrSize - 1) {
        return (gameBoardArr[0] + gameBoardArr[gameBoardArrSize]);
     }
    // Recursive function if the previous element is less than the next element

     else if (jumpIt(gameBoardArr, gameBoardArrSize, n + 1) < jumpIt(gameBoardArr, gameBoardArrSize, n + 2))
        return (gameBoardArr[n] + jumpIt(gameBoardArr, gameBoardArrSize, n + 1));

    // Recursive function: else the previous element is NOT less than the next element

    else
        return (gameBoardArr[n] + jumpIt(gameBoardArr, gameBoardArrSize, n + 2));
}
