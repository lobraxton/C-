#include <iostream>
#include <vector>

using namespace std;

const int MAX_DAYS = 7;
const int MAX_ROWS = 10;
const int MAX_COLS = 10; 

const double RISK_THRESHOLD = 80.0; // percentage of saturation that is consdiered risky
const int MIN_RISK_DAYS = 3; //days saturation is aboove threshold

/* Calculates average for one day and repeats until the last day*/
// rows doesn;t need to be initialized but columns does.
double getAverage(double grid[][MAX_COLS], int rows, int cols) {
    double sum = 0;

// loops through all the cells
    for (int r = 0; r < rows; r++) {
        for (int c = 0; c< cols; c++) {
            sum += grid[r][c]; 
        }
    }
    
    // total divided by the number of ceels and gives the average
    return sum / (rows* cols); 
}

int main() {
    // days of data, rows in city grid, and columns in city grid
    int days, rows, cols; 

    //city 1D - days 2D- rows 3D- columns
    double city[MAX_DAYS][MAX_ROWS][MAX_COLS];

    //stores data for one day
    double dayGrid [MAX_ROWS][MAX_COLS];

    /*stores the average saturation for each day
    vector used because the size can grow or change*/
    vector<double> dailyAverages;
 

    // takes user input for days, rows, and colums 
    cout <<"Enter number of days: ";
    cin>> days;
    cout << "Enter number of rows:  ";
    cin >> rows;
    cout <<"Enter Number of columns: ";
    cin>> cols;

    for (int d = 0; d <days; d++) {
        cout << "Day " << d + 1 << " data: " << endl; 
        for (int r = 0; r < rows; r++) {
            for (int c = 0; c < cols; c++){
                cin >> city [d][r][c];

                // keeps values between 0 and 100
                if (city[d][r][c] < 0) 
                    city[d][r][c] =0;
                if (city[d][r][c] > 100) 
                    city[d][r][c] = 100;
            }
        }
        // calculate daily average
        dailyAverages.push_back(getAverage (dayGrid, rows, cols));
    }

    //Find max saturation and overall average 
    double total = 0;
    double maxVal= city[0][0][0];
    int maxDay = 0, maxRow = 0, maxCol = 0;

    // goes through each cell and adds them together to get the toal
    for (int d = 0; d  < days; d++) {
        for (int r =0; r <rows; r++) {
            for (int c = 0; c < cols; c++){
                total += city[d][r][c]; // gathers the total

                /* if the loop finds an array value that is greater than 
                what is currently saved in the variable maxVal, then it 
                will replace maxVal with the current value and loops 
                until it goes through all the cells.*/
                if (city[d][r][c] > maxVal) {
                    maxVal = city[d][r][c];
                    maxDay = d;
                    maxRow = r;
                    maxCol = c;
                }
            }
        }
    }


    
    //output for the saturation report
    cout << "City Saturation Report" << endl;

    cout << "This report includes " << days << "day(s)," << rows <<
    "rows, and " << cols << "columns." << endl;

    // prints the daily averages 
    for (int i = 0; i < dailyAverages.size(); i++) {
        cout << "Day "<< i+1 << "average: " << dailyAverages[i] << "%\n";
    }

    //prints the overall average of saturation
    cout << "Overall Average: " << total/ (days*rows*cols) << "%\n";

    // prints out the maximun (largest) saturation 
    cout << "Maximum Saturation: " << maxVal 
        << "% (Day " << maxDay + 1
         <<" Row " << maxRow 
        << ", Columun "<< maxCol << ")\n";

    //outout high risk zones
    cout << "High Risk Zones:" << endl;
    bool foundRisk = false; 

    for (int r =0; r < rows; r++) {
        for (int c= 0; c< cols; c++){
            int count = 0; 

            for (int d = 0; d < days; d++) {
                if (city[d][r][c] >= RISK_THRESHOLD) {
                    count++;
                }
            }
            

            //print days if risky 
            if (count >= MIN_RISK_DAYS) {
                cout << "Zone (Row " << r << ", Column " << c  
                << ") high on " << count << "day(s)";
            foundRisk =true; 
            }
        }

    }
    // if no risk days are found, the program outputs "none"
    if (!foundRisk) {
        cout << "None" << endl; 
    }

    return 0;
}
