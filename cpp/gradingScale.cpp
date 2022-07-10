//
//  main.cpp
//  Grading Scale
//
//  Created by afieqha mieza azemi on 26/10/2019.
//  Copyright © 2019 afieqha mieza azemi. All rights reserved.
//

#include <iostream>
using namespace std;

char letterGrade(double score)
{
    double grade;
    
    if (score >= 90)
        grade = 'A';
    else if (score <= 89 && score >= 80)
        grade = 'B';
    else if (score <= 79 && score >= 70)
        grade = 'C';
    else if (score <= 69 && score >= 60)
        grade = 'D';
    else
        grade = 'F';
    
    return grade;
}

int main(int argc, const char * argv[])
{
    double score;
    
    cout << "Enter a score: " ;
    cin  >> score;
    
    cout << "The grade is " << letterGrade(score) << endl;
    
    
    return 0;
}
