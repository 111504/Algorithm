#include "iostream"
#include "cstdio"
#include "cstdlib"
#include "cstring"
#include "algorithm"
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
const int MAX = 10000;

char txt[MAX]; //input
int iSA[MAX],SA[MAX]; //output
int cnt[MAX],next2[MAX]; //internal
bool bh[MAX],b2h[MAX];
void print_array(int n,int *a){
 for(int i=0;i<n;i++){
    cout<<a[i]<<" ";

 }
 cout<<endl;
}

void print_array2(int n,bool *a){
 for(int i=0;i<n;i++){
    cout<<a[i]<<" ";
}
 cout<<endl;
}
void print_array3(int n,int *SA,char *txt){
 for(int i=0;i<n;i++){
      cout<<SA[i]<<" ";
    for(int j=SA[i];j<n;j++){
      cout<<txt[j];
    }
    cout<<endl;
    }
 cout<<endl;
}
void print_SA_iSA(int n,int *SA,int *iSA,char *txt){
 for(int i=0;i<n;i++){
    cout<<SA[i]<<" ";
    for(int j=SA[i];j<n;j++){
      cout<<txt[j];
    }
    cout<<endl;
 }
 cout<<endl;
 for(int i=0;i<n;i++){
    cout<<iSA[i]<<" ";
    for(int j=iSA[i];j<n;j++){
      cout<<txt[j];
    }
    cout<<endl;
 }
 cout<<endl;

}

// Compares two suffixes according to their first characters
bool smaller_first_char(int a, int b){
    cout<<a<<"  "<<txt[a]<<"    "<<b<<"  "<<txt[b]<<endl;
    return txt[a] < txt[b];
}

void suffixSort(int n){
    cout<<"the length of input txt "<<n<<endl;
    cout<<txt<<endl;
  //sort suffixes according to their first characters
  for (int i=0; i<n; ++i){
    SA[i] = i;
  }

  sort(SA, SA + n, smaller_first_char);
  print_array3(n,SA,txt);
  //{SA contains the list of suffixes sorted by their first character}

  for (int i=0; i<n; ++i){
    cout<<"i="<<i<<" "<<txt[SA[i]]<<"  "<<"i-1="<<i-1<<" "<<txt[SA[i-1]]<<endl;
    bh[i] = (i == 0) || (txt[SA[i]] != txt[SA[i-1]]);
    //cout<<"bh["<<i<<"]"<<bh[i]<<endl;
    b2h[i] = false;
  }
 print_array2(n,bh);
 print_array2(n,b2h);

  for (int h = 1; h < n; h <<= 1){
    cout<<"h="<<h<<endl;
    //{bh[i] == false if the first h characters of SA[i-1] == the first h characters of SA[i]}
    int buckets = 0;
    ////////////////////////////////////////
    for (int i=0, j; i < n; i = j){
      cout<<"i= "<<i<<endl;
      j = i + 1;
      cout<<"j= "<<j<<endl;
      // !(bh[j]) txt[sa[i]]==txt[sa[i-1]]
      while (j < n && !bh[j]) {
        j++;
      }
      cout<<"j= "<<j<<endl;
      next2[i] = j;
      buckets++;
      cout<<"finish  "<<endl;
    }
    cout<<"buckets="<<buckets<<endl;//how types of  alphabet
    print_array(n,next2);
    if (buckets == n) break; // We are done! Lucky bastards!
    //{suffixes are separted in buckets containing txtings starting with the same h characters}
    cout<<"deal  next2------------------"<<endl;
    for (int i = 0; i < n; i = next2[i]){
      cnt[i] = 0;
      cout<<"i= "<<i<<endl;
      cout<<"next2[i]="<<next2[i]<<endl;
      for (int j = i; j < next2[i]; ++j){
        cout<<" j= "<<j<<" "<<SA[j];
        iSA[SA[j]] = i;
      }
      cout<<endl;
    }
    cout<<"finish next2----------------"<<endl;
    cout<<"output iSA------------------"<<endl;
    //print_SA_iSA(n,SA,iSA,txt);
 //   print_array(n,iSA);
    for(int i=0;i<n;i++){
         cout<<iSA[i]<<" ";
         for(int j=i;j<n;j++){
             cout<<txt[j];
      }
      cout<<endl;
    }
    cout<<endl;
    cout<<"output cnt------------------"<<endl;
    cnt[iSA[n - h]]++;
    print_array(n,cnt);
    cout<<"output b2h------------------"<<endl;
    b2h[iSA[n - h]] = true;
    print_array2(n,b2h);
    cout<<"next stage@@@@@@@@@--------------------------------------"<<endl;

    for (int i = 0; i < n; i = next2[i]){
      cout<<"i= "<<i;
      for (int j = i; j < next2[i]; ++j){
        cout<<"j= "<<j<<" ";
        int s = SA[j] - h;
        cout<<"s= "<<s<<" "<<endl;;
        if (s >= 0){
          int head = iSA[s];
          cout<<"head= "<<head<<endl;
          iSA[s] = head + cnt[head]++;
          cout<<iSA[s]<<" "<<head<<" "<<cnt[head]<<endl;
          b2h[iSA[s]] = true;

        }
       cout<<endl;
      }
        print_array2(n,b2h);
        print_array(n,iSA);

      cout<<"next for---------------"<<endl;
      for (int j = i; j < next2[i]; ++j){
        cout<<"j= "<<j<<" "<<endl;;
        int s = SA[j] - h;
        if (s >= 0 && b2h[iSA[s]]){
          cout<<"s= "<<s<<" "<<"iSA[s]= "<<iSA[s]<<" "<<"b2h[iSA[s]]= "<<b2h[iSA[s]]<<endl;
          for (int k = iSA[s]+1; !bh[k] && b2h[k]; k++) {
                cout<<"k= "<<k<<" ";
                b2h[k] = false;
          }
          cout<<endl;
        }
      }
      cout<<"next finish---------------"<<endl;
      print_array2(n,b2h);
      cout<<endl;
    }
    cout<<"finish stage@@@@@@@@@--------------------------------------"<<endl;
    for (int i=0; i<n; ++i){
      SA[iSA[i]] = i;
      bh[i] |= b2h[i];
    }
     print_array3(n,SA,txt);
     print_array2(n,b2h);
  }
  for (int i=0; i<n; ++i){
    iSA[SA[i]] = i;
  }
  print_SA_iSA(n,SA,iSA,txt);
}
// End of suffix array algorithm


/*// Begin of the O(n) longest common prefix algorithm
// Refer to "Linear-Time Longest-Common-Prefix Computation in Suffix
// Arrays and Its Applications" by Toru Kasai, Gunho Lee, Hiroki
// Arimura, Setsuo Arikawa, and Kunsoo Park.
int lcp[MAX];
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
   print_array3(len,SA,txt);
 }
   return 0;
 }

