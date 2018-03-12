#include <numeric>
#include <iostream>
#include <vector>
#include <iomanip>
using namespace std;


float direct_summation(float number)
{
float sum=0;
int counter=0;
while(counter<1000) {
sum+=number;
counter++;
}
return sum;

}
float kahan_summation(float begin) {
  float result = 0.f;

  float c = 0.f;
  int counter=0;
  while(counter<1000) {
    float y = begin - c;
    float t = result + y;
    c = (t - result) - y;
    result = t;
	counter++;
	
  }
  return result;
}

int main()
{

	cout << fixed << setprecision(20) <<"Kahan summation : " <<kahan_summation(2.11385479)<<"\n";
	cout << fixed << setprecision(20) <<"Direct summation: "<< direct_summation(2.11385479)<<" \n";
	cout<<("Correct Sum : 2113.8547900000000 ")<<"\n";
	cout<<"\n";
	cout << fixed << setprecision(20) <<"Kahan summation : " <<kahan_summation(0.1324212)<<"\n";
	cout << fixed << setprecision(20) <<"Direct summation: "<< direct_summation(0.1324212)<<"\n";
	cout<<("Correct Sum : 132.4212000000000 ");
	getchar();
    return 0;
}
