#include <iostream>
#include <stdio.h>
#include <cmath>
#include <string.h>
#include <fstream>

using namespace std;
void print_min(int a, int b){
    if(a<b)
        printf("%d", a);
    else
        printf("%d", b);
}

int main(){
    int a=4, b=5;
    int c[10];
    ifstream in("/Volumes/STORY/121.txt");
    ofstream out("/Volumes/STORY/1212.txt");

    for(int i=0;i<10;i++)
        in>>c[i];
    for(int i=0;i<10;i++)
        cout<<c[i]<<" ";
    cout << "\n";
    for(int i=0;i<10;i++)
        out<<c[i]<<" ";

    in.close();
    out.close();

    void (*pf) (int, int);
    pf = print_min;
    pf(a, b);
    
    printf("Hello world.\n");
    return 0;
}
