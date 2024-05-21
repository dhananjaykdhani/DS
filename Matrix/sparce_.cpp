// Sparce Matric Addition and Multiplication

#include <iostream>
using namespace std;

#define max 30
int s1[max][3], s2[max][3], s3[max][3], m = 0, n = 0, l = 0;

void input(){
    cout<<"Enter the number of rows and columns And Length of the matrix: ";
    cin>>m>>n>>l;

    if(l>(m*n)/2){
        cout<<"Matrix is not sparce";
        return;
    }
    cout<<"Enter the elements of the matrix 1: ";
    for(int i=0; i<l; i++){
        cin>>s1[i][0]>>s1[i][1]>>s1[i][2];
    }

    cout << "given matrix 1:\n";
    for (int i = 0; i < l; i++)
    {
        cout << s1[i][0] << " " << s1[i][1] << " " << s1[i][2] << " \n";
    }

    cout<<"Enter the elements of the matrix 2: ";
    for(int i=0; i<l; i++){
        cin>>s2[i][0]>>s2[i][1]>>s2[i][2];
    }
    cout << "given matrix 2:\n";
    for (int i = 0; i < l; i++)
    {
        cout << s2[i][0] << " " << s2[i][1] << " " << s2[i][2] << " \n";
    }
    
}

void add(){
    int i=0, j=0, k=0;
    while(i<l && j<l){
        if(s1[i][0]<s2[j][0]){
            s3[k][0] = s1[i][0];
            s3[k][1] = s1[i][1];
            s3[k][2] = s1[i][2];
            i++;
            k++;
        }
        else if(s1[i][0]>s2[j][0]){
            s3[k][0] = s2[j][0];
            s3[k][1] = s2[j][1];
            s3[k][2] = s2[j][2];
            j++;
            k++;
        }
        else{
            if(s1[i][1]<s2[j][1]){
                s3[k][0] = s1[i][0];
                s3[k][1] = s1[i][1];
                s3[k][2] = s1[i][2];
                i++;
                k++;
            }
            else if(s1[i][1]>s2[j][1]){
                s3[k][0] = s2[j][0];
                s3[k][1] = s2[j][1];
                s3[k][2] = s2[j][2];
                j++;
                k++;
            }
            else{
                s3[k][0] = s1[i][0];
                s3[k][1] = s1[i][1];
                s3[k][2] = s1[i][2] + s2[j][2];
                i++;
                j++;
                k++;
            }
        }
    }
    while(i<l){
        s3[k][0] = s1[i][0];
        s3[k][1] = s1[i][1];
        s3[k][2] = s1[i][2];
        i++;
        k++;
    }
    while(j<l){
        s3[k][0] = s2[j][0];
        s3[k][1] = s2[j][1];
        s3[k][2] = s2[j][2];
        j++;
        k++;
    }
    cout<<"Addition of the matrix is: \n";
    for(int i=0; i<k; i++){
        cout<<s3[i][0]<<" "<<s3[i][1]<<" "<<s3[i][2]<<endl;
    }
}

void multiply(){
    int i=0, j=0, k=0;
    while(i<l){
        j=0;
        while(j<l){
            if(s1[i][1]==s2[j][0]){
                s3[k][0] = s1[i][0];
                s3[k][1] = s2[j][1];
                s3[k][2] = s1[i][2] * s2[j][2];
                k++;
            }
            j++;
        }
        i++;
    }
    cout<<"Multiplication of the matrix is: \n";
    for(int i=0; i<k; i++){
        cout<<s3[i][0]<<" "<<s3[i][1]<<" "<<s3[i][2]<<endl;
    }
}

int main(){
    input();
    add();
    multiply();
    return 0;
}
