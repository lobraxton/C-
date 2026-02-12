#include <iostream>

 using namespace std;


 int main ()
{
    // initalize the 2x2 array
    int arr[3][3];
    
    cout << "Enter 9 integers:" << endl;
    
    // loops through all the cells and fills every number that the user entered
    for (int i =0; i < 3; i++) {
        for (int j = 0; j < 3; j++){
            cin >> arr[i][j];
            sum += arr[i][j];
        }
    }
    
    cout << "The sum of all elements are: " << sum << endl;
    
    // set to zero to negate memory value being saved and printed out
    int largest = arr[0][0]; 
    
    for (int i =0; i < 3; i++) {
        for (int j = 0; j < 3; j++){
            if (arr[i][j] > largest) {
                largest = arr[i][j];
            }
            
        }
    }
    
    cout << "The largest integer in the array is: " << largest << endl;
    

// CASE:: FIND THE SECOND LARGEST INTEGER IN AN ARRAY


// finding the second largest in the array
   /* int largest = arr[0][0]; 
    int secondLargest = arr[0][0];
    
    for (int i =0; i < 3; i++) {
        for (int j = 0; j < 3; j++){
            if (arr[i][j] > largest) {
                secondlargest = largest; // first to save the old largest value 
                largest = arr[i][j]; // saves the updated largest
                
            }
            
            else if (arr[i][j] > secondLargest && arr[i][j] != largest) {
                second largest == arr[i][j];
            }
        }
    }
*/
    return 0;
}