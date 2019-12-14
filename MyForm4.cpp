#include "MyForm4.h"
#include "MyForm2.h"
#include <math.h>
#include "Header.h"

using namespace Laboratornsrabots;
using namespace System;
using namespace System::Windows::Forms;

double Fun(double x)
{
	double y = pow(x, 8) - 0.4 * pow(x, 3) - 1.24;
	return y;
}
void VivodDGV(double x, double y, DataGridView^ DGV)
{
	DGV->ColumnCount = 2;
	DGV->Rows->Add(x, y);
}
void Tabul(double x, double a, double b, double h, double& k, DataGridView^ grid)
{
	x = a;
	double y;
	int n = Convert::ToInt32(((b - a) / h) + 1);
	k = 1;
	for (int i = 1; i <= n; i++)
	{
		y = Fun(x);
		VivodDGV(x, y, grid);
		if (y < 0)
			k = k * y;
		x = x + h;
	}
}
double Vvod(TextBox^ t)
{
	return Convert::ToDouble(t->Text);
}
void Vivod(double z, TextBox^ t)
{
	t->Text = Convert::ToString(z);
}
void Chet(double x, double y, double a, double b, double& p)
{
	double max, min;
	if (x > 0)
	{
		if (y > x)
			max = y;
		else max = x;
		p = max;
	}
	else
		if ((-1 <= x) && (x <= 0))
		{
			if (x > b)
				min = b;
			else min = x;
			p = min;
		}
		else
		{
			if ((x * x) > (a + b))
				max = x * x;
			else max=a + b;
			min = sin(a);
			if (min > cos(b))
				min = cos(b);
			if (min > max)
				min = max;
			p = min;
		}
}
