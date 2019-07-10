#include <iostream>
#include <stdio.h>
#include <cmath>
#include <cstring>

const double eps = 1e-8;
#define Equ(a,b) (fabs((a)-(b))<(eps))
void swap(int* x, int* y);
void swap2(int* a, int* b);
void change(int &x, int &y);
int stringcmp(char &a, char &b);
void PrintMin(int a, int b);

struct Point{
    int x, y;
    Point(){}
    Point(int _x, int _y):x(_x), y(_y){}
}pt[10];

void Do(int &n, int &c){
    if(n%2==0){
        n = n/2;
        c += 1;
    }else{
        n = (3*n+1)/2;
        c += 1;
    }
}

void swap3(int &x, int &y){
    int temp;
    temp = x;
    x = y;
    y = temp;
}

bool isLeap(int year){
    return (year%4==0 && year%100!=0) || (year%400==0);
}

void DiffDate(int &time1, int &time2){
    // 对平年、闰年存储每月天数
    int month[13][2]={{0, 0},{31, 31},{28, 29},{31,31},{30,30},{31,31},{30,30},
    {31,31},{31,31},{30,30},{31,31},{30,30},{31,31}};
    if(time1>time2){
        swap3(time1, time2);
    }
    int y1, m1, d1;
    int y2, m2, d2;
    int ans=0;
    y1 = time1/10000, m1 = time1%10000/100, d1 = time1%100;
    y2 = time2/10000, m2 = time2%10000/100, d2 = time2%100;
    while(y1<y2 || m1<m2 || d1<d2){
        d1++;
        if(d1==month[m1][isLeap(y1)]+1){
            m1++;
            d1=1;
        }
        if(m1==13){
            y1++;
            m1=1;
        }
        ans++;
    }
    printf("%d\n",ans);
}

void timecount(){
    int time1, time2;
    while(scanf("%d %d", &time1, &time2)!=EOF){
        DiffDate(time1, time2);
    }
}

int Interate(int n){
    if(n==1 | n==0)
        return 1;
    else
        return n*Interate(n-1);
}


void swap(int* x, int* y){
    int temp = *x;
    *x = *y;
    *y = temp;
}

void swap2(int* a, int* b){
    int x;
    int* temp = &x;
    *temp = *a;
    *a = *b;
    *b = *temp;
}

void change(int &x, int &y){
    x = 1;
    y = pow(x+1.0, 3.0);
}

int stringcmp(char &a, char &b){
    int x=0;
    for(int i=0; i<10; i++){
        if(strcmp(&a+i, &b+i)>0){
            x = 1;
            break;
        }else if(strcmp(&a+i, &b+i)){
            x = -1;
            break;
        }
    };
    return x;
}

void PrintMin(int a, int b){
    if(a<b)
        printf("%d", a);
    else
        printf("%d", b);
}
