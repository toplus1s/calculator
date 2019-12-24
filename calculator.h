#ifndef CALCULATOR_H
#define CALCULATOR_H
#include<stdio.h>
#include<stdlib.h>
#include <string.h>
#include <iostream>
#include <iomanip>
#include <conio.h>
#include <process.h>
#include <math.h>
#include <fstream>
#include <windows.h>
#include <string>
#include <QString>
#define MAX   80

using namespace std;




class  polynomial
{
public:
    double Coefficient;
    int    index;
    int    Rauk;
    polynomial *next;
};

class calculator{

public:
    calculator();
    double Realization(char *str);
    void push(polynomial *head,double Coefficient,int index) ;
    QString Build(QString a, int mp);
    void xue(polynomial *head);
    void del(polynomial *DLList1,double Coefficient,int index);
    void sort(polynomial *DLList1);
    void Inverselist(polynomial *DLList1);
    QString algorithm(int CD);
    double ValueofX(polynomial *X, double x);
    QString  Formattedoutput(polynomial *abc);
    void quick(polynomial *Ac);
    void clear();
    QString revalue(int e, double x);

private:
    polynomial *Aa=new polynomial;
    polynomial *Bb=new polynomial;
    polynomial *Cc=new polynomial;
};

#endif // CALCULATOR_H
