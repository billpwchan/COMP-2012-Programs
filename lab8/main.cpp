#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator> 
#include "sum.h"    
#include "average.h"
#include "water.h"  
using namespace std;

int main()
{
  vector<double> doubleContainer;
  for(int i=1; i<=10; i++)
    doubleContainer.push_back((double)i/2);
    
  vector<Water> waterContainer;
  for(int i=1; i<=10; i++)
    waterContainer.push_back(Water(i));
    
  Sum<double> doubleSum = for_each(doubleContainer.begin(), doubleContainer.end(), Sum<double>(0));
  cout << "The sum of [ ";
  copy(doubleContainer.begin(), doubleContainer.end(), ostream_iterator<double>(cout, ", "));
  cout << "] is " << doubleSum << endl;
  
  Average<double> doubleAverage = for_each(doubleContainer.begin(), doubleContainer.end(), Average<double>(0,0));
  cout << "The average of [ ";
  copy(doubleContainer.begin(), doubleContainer.end(), ostream_iterator<double>(cout, ", "));
  cout << "] is " << doubleAverage << endl;
  
  Sum<Water> waterSum = for_each(waterContainer.begin(), waterContainer.end(), Sum<Water>(Water()));
  cout << "The sum of [ ";
  copy(waterContainer.begin(), waterContainer.end(), ostream_iterator<Water>(cout, ", "));
  cout << "] is " << waterSum << endl;
  
  Average<Water> waterAverage = for_each(waterContainer.begin(), waterContainer.end(), Average<Water>(Water(),0));
  cout << "The average of [ ";
  copy(waterContainer.begin(), waterContainer.end(), ostream_iterator<Water>(cout, ", "));
  cout << "] is " << waterAverage << endl;
  
  return 0;
}
