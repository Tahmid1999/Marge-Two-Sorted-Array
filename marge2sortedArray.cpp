#include<iostream>
#include<ctime>
#include<cstdlib>
#include<iomanip>
using namespace std;


///Prototypes:
void creat_array(int *&X,int s);
void populate_array(int *X,int s,int l,int h);
int max(int *X,int s);
int num_digit(int n);
void display_array(int *X,int s,int m);
void insertion_sort(int *X,int s);
void marge_2sorted_arrays(int *X,int s1,int *Y,int s2,int *Z,int s3);



int main(){
int *A,*B,*C;
int s1,s2;
cout<<"Enter the size of your array: ";
cin>>s1;
int l1;
cout<<"Enter the low value: ";
cin>>l1;
int h1;
cout<<"Enter the higest value: ";
cin>>h1;

creat_array(A,s1);
populate_array(A,s1,l1,h1);

cout<<endl;

cout<<"Enter the size of your array: ";
cin>>s2;
int l2;
cout<<"Enter the low value: ";
cin>>l2;
int h2;
cout<<"Enter the higest value: ";
cin>>h2;
creat_array(B,s2);
populate_array(B,s2,l2,h2);

cout<<"1st array: ";
display_array(A,s1,max(A,s1));
cout<<endl;
cout<<"2nd array: ";
display_array(B,s2,max(B,s2));

insertion_sort(A,s1);
insertion_sort(B,s2);
cout<<endl;
cout<<"1st sorted array: ";
display_array(A,s1,max(A,s1));
cout<<endl;
cout<<"2nd sorted array: ";
display_array(B,s2,max(B,s2));

creat_array(C,s1+s2);
marge_2sorted_arrays(A,s1,B,s2,C,s1+s2);
cout<<endl;
cout<<"Marged array: ";
display_array(C,s1+s2,max(C,s1+s2));

system("pause");

return 0;
}


void creat_array(int *&X,int s){
X=new int [s];
}

void populate_array(int *X,int s,int l,int h){

srand(time(0));
for(int i=0;i<s;i++){
    X[i]=l+rand()%(h+1-l);
}
}

int max(int *X,int s){
int maximum=X[0];
for(int i=0;i<s;i++){
    if(X[i]>maximum){
        maximum=X[i];
    }
}
 return maximum;
}

int num_digit(int n){
  if(n<10) return 1;
  else 1+num_digit(n/10);
}

void display_array(int *X,int s,int m){
 for(int i=0;i<s;i++){
    if(i%10==0) cout<<endl;
    cout<<setw(num_digit(m)+2)<<X[i]<<" ";

 }
}

/*
void insertion_sort(int *X,int s){
for(int i=1;i<s;i++){
    int key=X[i];
    int j=i-1;
    while(j>=0){
        if(X[j]>key){
            X[j+1]=X[j];
        }
        else break;
        j--;
    }
    X[j+1]=key;
}

}
*/






void marge_2sorted_arrays(int *X,int s1,int *Y,int s2,int *Z,int s3){
 int i=0,j=0,k=0;
 while(i<s1 && j<s2){
    if(X[i]>=Y[j]){
        Z[k]=Y[j];
        k++;
        j++;
    }
    else {
        Z[k]=X[i];
        k++;
        i++;
    }

 }


 while (i<s1){
    Z[k]=X[i];
    k++;
    i++;
 }

 while(j<s2){
    Z[k]=Y[j];
    k++;
    j++;
 }

}

