#pragma once

#include <iomanip>
#include <iostream>
#include <conio.h>
#include <windows.h>
#include "MyFunction.h"

#define UCHAR unsigned char
#define UCH unsigned char
#define CLEAR system("cls")
#define PAUSE system("pause")
#define SKIP SetColor(0,0)
#define ESC 27



using namespace std;

void task1();
void task2();
void task3();
int FirstTermMenu();
int LabirintMenu();
void maska();
void RecMenu();
void RecTable();
float rec(float x, float ept, float n, float an, float numc, float y);