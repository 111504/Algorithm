/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <iostream>
#include <vector>
using namespace std;
void search(vector<int>::iterator begin,vector<int>::iterator end,int val){
    //cout<<"end="<<*end<<endl;
    for(;begin!=end;++begin){
        std::cout << ' ' << *begin;
        if(*begin==val)
            cout<<"find"<<endl;
      //     return true;
    //    return false;
    }
    
}
int main ()
{
  std::vector<int> myvector;
  for (int i=1; i<=5; i++) myvector.push_back(i);

  std::cout << "myvector contains:";
  for (std::vector<int>::iterator it = myvector.begin() ; it != myvector.end(); ++it)
    std::cout << ' ' << *it;
  std::cout << '\n';
  
  search(myvector.begin(),myvector.end(),3);

  return 0;
}