//
//  main.cpp
//  Question2
//
//  Created by afieqha mieza azemi on 05/11/2019.
//  Copyright © 2019 afieqha mieza azemi. All rights reserved.
//

#include <iostream>
using namespace std;

bool occur(string str, string str1)
{
    bool check=true;
    
    if (str[0] == '\0' || str.length() < str1.length())
        check = false;
    else
    {
        if (str[0] != str1[0])
            check = occur(str.substr(1), str1);
        
        if (str[0] == str1[0])
            for (int i=0; i!=str1.length(); i++)
                if (str[i] != str1[i])
                    check = occur(str.substr(1), str1);
     }
    
    
    
    return check;
}
int main(int argc, const char * argv[])
{
    string str, str1;
    
    cout << "Enter a string: ";
    cin  >> str;
    cout << "Enter another string: ";
    cin  >> str1;
    
    if (occur(str, str1)) {
        cout << str1 << " is included in " << str << endl;
    }
    
    else
        cout << str1 << " is not included in " << str << endl;
    return 0;
}
