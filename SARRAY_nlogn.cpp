#include <iostream> 
#include <cstdio>

#include <cstdlib>
#include <cstring>
#include <algorithm> 
using namespace std;

// Begins Suffix Arrays implementation
// O(n log n) - Manber and Myers algorithm
// Refer to "Suffix arrays: A new method for on-line txting searches",
// by Udi Manber and Gene Myers
 
//Usage:
// Fill txt with the characters of the txting.
// Call SuffixSort(n), where n is the length of the txting stored in txt.
// That's it!
 
//Output:
// SA = The suffix array. Contains the n suffixes of txt sorted in lexicographical order.
//       Each suffix is represented as a single integer (the SAition of txt where it starts).
// iSA = The inverse of the suffix array. iSA[i] = the index of the suffix txt[i..n)
//        in the SA array. (In other words, SA[i] = k <==> iSA[k] = i)
//        With this array, you can compare two suffixes in O(1): Suffix txt[i..n) is smaller
//        than txt[j..n) if and only if iSA[i] < iSA[j]
const int MAX = 100010;
char txt[MAX]; //input
int iSA[MAX], SA[MAX]; //output
int cnt[MAX], next2[MAX]; //internal
bool bh[MAX], b2h[MAX];


void outputArrayint(int arr[],int n){
	for(int i=0;i<n;i++){
	   cout<<arr[i]<<" ";
	   
	}
	cout<<endl;
}
 
void outputArraybool(bool arr[],int n){
	for(int i=0;i<n;i++){
	   cout<<arr[i]<<" ";
	  
	}
	cout<<endl;
} 
void  outputArraySA(int sa[],int n){
	cout<<endl;
    for(int i=0;i<n;i++){
	     cout<<sa[i]<<" ";
	     for(int j=sa[i];j<n;j++){
		  cout<<txt[j];
		 }
		 cout<<endl;
	   
	}
	cout<<endl;

}
void  outputArrayiSA(int isa[],int n){
	cout<<endl;
    for(int i=0;i<n;i++){
	     cout<<isa[i]<<" ";
	     for(int j=i;j<n;j++){
		  cout<<txt[j];
		 }
		 cout<<endl;
	   
	}
	cout<<endl;

}
// Compares two suffixes according to their first characters
bool smaller_first_char(int a, int b){
  return txt[a] < txt[b];
}
 
void suffixSort(int n){
  //sort suffixes according to their first characters
  for (int i=0; i<n; ++i){
    SA[i] = i;
  }
  sort(SA, SA + n, smaller_first_char);
  //{SA contains the list of suffixes sorted by their first character}
 
  for (int i=0; i<n; ++i){
    bh[i] = i == 0 || txt[SA[i]] != txt[SA[i-1]];
    b2h[i] = false;
  }
 
  for (int h = 1; h < n; h <<= 1){
    //{bh[i] == false if the first h characters of SA[i-1] == the first h characters of SA[i]}
    int buckets = 0;
    for (int i=0, j; i < n; i = j){
      j = i + 1;
      while (j < n && !bh[j]) j++;
      next2[i] = j;
      buckets++;
    }
    cout<<"next2= ";
	outputArrayint(next2,n);
    if (buckets == n) break; // We are done! Lucky bastards!
    //{suffixes are separted in buckets containing txtings starting with the same h characters}
 
    for (int i = 0; i < n; i = next2[i]){
      cnt[i] = 0;
      for (int j = i; j < next2[i]; ++j){
        iSA[SA[j]] = i;
      }
    }
    cout<<"SA= ";
	outputArraySA(SA,n);
    cout<<"iSA= ";
	outputArrayiSA(iSA,n);
    cnt[iSA[n - h]]++;
    b2h[iSA[n - h]] = true;
    
    cout<<"cnt= ";
	outputArrayint(cnt,n);
    cout<<"bh= ";
	outputArraybool(bh,n);
    cout<<"b2h= ";
	outputArraybool(b2h,n);
    
    
    for (int i = 0; i < n; i = next2[i]){
    	
      cout<<endl;	
      cout<<"i= "<<i<<", enetr first loop-----      "<<endl;
      for (int j = i; j < next2[i]; ++j){
        int s = SA[j] - h;
        cout<<"j= "<<j<<" s= "<<s<<" "<<SA[j]<<" "<<h<<endl;
        if (s >= 0){
          int head = iSA[s];
          cout<<"head= "<<head<<" "<<"cnt[head]= "<<cnt[head]<<endl;
          iSA[s] = head + cnt[head]++;
          cout<<"iSA[s]= "<<iSA[s]<<endl;
          b2h[iSA[s]] = true;
        }
        
      }
      cout<<"finish-------------------------"<<endl;
      cout<<"bh= ";
	  outputArraybool(bh,n);
	  cout<<"b2h= ";
	  outputArraybool(b2h,n);
	  cout<<"iSA= ";
	  outputArrayiSA(iSA,n);
      cout<<endl;
      cout<<" enetr second loop-----"<<endl;
      for (int j = i; j < next2[i]; ++j){
        int s = SA[j] - h;
        cout<<"j= "<<j<<" s= "<<s<<" "<<SA[j]<<" "<<h<<endl;
        if (s >= 0 && b2h[iSA[s]]){
        	cout<<"iSA[s]= "<<iSA[s]<<endl;
          for (int k = iSA[s]+1; !bh[k] && b2h[k]; k++) {
		    cout<<"k= "<<k<<"  ";
		    b2h[k] = false;
		   }
		   cout<<endl;
        }
      }
      cout<<" finish second loop-----"<<endl;
      cout<<"b2h= ";
	  outputArraybool(b2h,n);
      
    }
    cout<<"deal SA------------bh-------"<<endl;
	for (int i=0; i<n; ++i){
      SA[iSA[i]] = i;
      bh[i] |= b2h[i];
    }
      cout<<"SA= ";
	  outputArraySA(SA,n);
      cout<<"b2h= ";
	  outputArraybool(b2h,n);
  }
  
  for (int i=0; i<n; ++i){
    iSA[SA[i]] = i;
  }
}
// End of suffix array algorithm
 
 
// Begin of the O(n) longest common prefix algorithm
// Refer to "Linear-Time Longest-Common-Prefix Computation in Suffix
// Arrays and Its Applications" by Toru Kasai, Gunho Lee, Hiroki
// Arimura, Setsuo Arikawa, and Kunsoo Park.
/*int lcp[MAX];
// lcp[i] = length of the longest common prefix of suffix SA[i] and suffix SA[i-1]
// lcp[0] = 0
void getlcp(int n)
{
  for (int i=0; i<n; ++i) 
    iSA[SA[i]] = i;

  lcp[0] = 0;

  for (int i=0, h=0; i<n; ++i)
  {
    if (iSA[i] > 0)
    {
      int j = SA[iSA[i]-1];
      while (i + h < n && j + h < n && txt[i+h] == txt[j+h]) 
          h++;
      lcp[iSA[i]] = h;

      if (h > 0) 
        h--;
    }
  }
}*/

// End of longest common prefixes algorithm
int main()
{
  int len;
 gets(txt);
 len = strlen(txt);

 suffixSort(len);
 for (int i = 0; i < len; ++i)
 {
   printf("%d\n",SA[i] );
 }
   return 0;
 }
