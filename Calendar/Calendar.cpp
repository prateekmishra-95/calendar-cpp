// Calendar.cpp : Defines the entry point for the console application.

#include "stdafx.h"

using namespace std;

int arr[31] = { 1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,
21,22,23,24,25,26,27,28,29,30,31 };
char months[12][10] = { "JANUARY","FEBRUARY","MARCH","APRIL","MAY","JUNE","JULY","AUGUST","SEPTEMBER","OCTOBER","NOVEMBER","DECEMBER" };
int x = 10, y = 6, yr = 1990, ptr_x, ptr_y, ch, lx = 44, *t = arr;  //t to keep the track of date.
int set_date = 1, set_month = 1, set_year = 1990, dateLimit, previous;

void set_position(int year, int month);
void print(int month, int year);
int is_leap_yr(int year);
void userArea();
void gotoxy(int x, int y);

int main()
{
	system("cls");
	time_t now = time(0);
	struct tm timeInfo;
	localtime_s(&timeInfo, &now);
	set_year = timeInfo.tm_year + 1900;
	set_month = timeInfo.tm_mon + 1;
	set_date = timeInfo.tm_mday;
	for (int z = 1; z<set_date; z++)
		t++;
	/*int year,month;
	cout<<"\nEnter the month and year : ";
	cin>>month>>year;*/
	set_position(set_year, set_month);
	userArea();
	_getch();
	return 0;
}

void set_position(int year, int month)
{
	int yr1 = yr, n = year - yr, m;
	for (int i = 0; i<n; i++)
	{
		yr1++;
		m = yr1 - 1;
		if (is_leap_yr(m))
		{
			if (x<58)
			{
				x = x + 8;
				if (x<58)
				{
					x = x + 8;
					gotoxy(x, y);
				}
				else
				{
					x = 10;
					gotoxy(x, y);
				}
			}
			else
			{
				x = 10;
				x = x + 8;
				gotoxy(x, y);

			}
		}
		/*If the previous year is not a leap year then increment
		by only one */
		else if (x<58)
		{
			x = x + 8;
			gotoxy(x, y);
		}
		/*if the above else if doesn't work i.e.
		if the cursor is at SUN
		*/
		else
		{
			x = 10;
			gotoxy(x, y);
		}


	}
	print(month, year);
}

void print(int month, int year)
{
	system("cls");
	gotoxy(30, 2);
	cout << months[month - 1] << " " << year;
	gotoxy(10, 4);
	cout << "MON\tTUE\tWED\tTHU\tFRI\tSAT\tSUN ";
	int *q;
	int s, b = 0;

	if (month == 1)
	{
		previous = 31;
		gotoxy(x, y);
		dateLimit = 31;
		ptr_x = x;
		ptr_y = y + 1;
		q = arr;
		cout << *q;
		for (int a = 1; a<31; a++)
		{
			q = q + 1;
			if (x<58)
				x = x + 8;
			else
			{
				x = 10;
				y = y + 2;
			}
			gotoxy(x, y);
			cout << *q;
		}
	}
	else
	{
		int a;
		for (int j = 1; j<month; j++)
		{

			switch (j)
			{
			case 1: case 3: case 5: case 7: case 8: case 10: case 12:
				a = 31;
				if (j == 1)
					b = 1;
				else if (j == 7)
					b = 4;
				else
					b = 2;
				break;

			case 2:
				if (is_leap_yr(year))
					a = 29;
				else
					a = 28;

				b = 3;
				break;

			case 4: case 6: case 9: case 11:
				a = 30;
				b = 4;
				break;
			}

			for (int k = 1; k<a; k++)
			{
				if (x<58)
					x = x + 8;
				else
				{
					x = 10;
					y = y + 2;
				}
				gotoxy(x, y);
			}
			if (x<58)
			{
				x = x + 8;
				y = 6;
				gotoxy(x, y);
			}
			else
			{
				x = 10;
				y = 6;
				gotoxy(x, y);
			}

			ptr_x = x;
			ptr_y = y + 1;

		}

		previous = a;
		if (b == 1)
		{
			q = arr;
			cout << *q;
			if (is_leap_yr(year))
				dateLimit = s = 29;
			else
				dateLimit = s = 28;
			for (int z = 1; z<s; z++)
			{
				q = q + 1;
				if (x<58)
					x = x + 8;
				else
				{
					x = 10;
					y = y + 2;
				}
				gotoxy(x, y);
				cout << *q;
			}
		}

		if (b == 2)
		{
			q = arr;
			cout << *q;
			dateLimit = 30;
			for (int l = 1; l<30; l++)
			{
				q = q + 1;
				if (x<58)
					x = x + 8;
				else
				{
					x = 10;
					y = y + 2;
				}
				gotoxy(x, y);
				cout << *q;
			}
		}

		if (b == 3 || b == 4)
		{
			q = arr;
			cout << *q;
			dateLimit = 31;
			for (int m = 1; m<31; m++)
			{
				q = q + 1;
				if (x<58)
					x = x + 8;
				else
				{
					x = 10;
					y = y + 2;
				}
				gotoxy(x, y);
				cout << *q;
			}
		}
	}
	if (*t > dateLimit)
	{
		t = arr;
		while (*t != dateLimit)
			t++;
		set_date = dateLimit;
		gotoxy(45, 23);
		cout << set_date << "\b";
	}

	for (int o = 1; o<*t; o++)
	{
		if (ptr_x<58)
			ptr_x += 8;
		else
		{
			ptr_x = 10;
			ptr_y += 2;
		}
	}

	gotoxy(ptr_x, ptr_y);
	cout << (char)94;

	gotoxy(24, 23);
	cout << "Enter the date : ";
	gotoxy(44, 22);
	cout << "Day";
	gotoxy(51, 22);
	cout << "Month";
	gotoxy(61, 22);
	cout << "Year";
	gotoxy(45, 23);
	cout << set_date << "\b";
	gotoxy(53, 23);
	cout << set_month << "\b";
	gotoxy(61, 23);
	cout << set_year << "\b";
	gotoxy(lx, 23);
	cout << (char)62;


}

void userArea()
{


	while ((ch = _getch()) != 27)
	{
		if (ch == 0 || ch == 224)
		{
			ch = _getch();


			if (ch == 72)
			{
				if (lx == 44)
				{
					if (set_date < dateLimit)
					{
						set_date++;
						gotoxy(ptr_x, ptr_y);
						cout << " ";
						if (ptr_x<58)
							ptr_x += 8;
						else
						{
							ptr_x = 10;
							ptr_y += 2;
						}
						t++;
						gotoxy(ptr_x, ptr_y);
						cout << (char)94;
						gotoxy(45, 23);
						cout << set_date << "\b";
					}
					else
					{
						t = arr;
						set_date = 1;
						if (set_month <12)
							set_month++;
						else
						{
							set_month = 1;
							set_year++;
						}
						x = 10; y = 6;
						set_position(set_year, set_month);
						gotoxy(45, 23);
						cout << set_date << "\b";
					}
				}
				else if (lx == 52)
				{
					if (set_month<12)
						set_month++;
					else
					{
						set_month = 1;
						set_year++;
					}
					x = 10; y = 6;
					set_position(set_year, set_month);
					gotoxy(53, 23);
					cout << set_month << "\b";

				}
				else if (lx == 60 && set_year<2050)
				{
					set_year++;
					x = 10; y = 6;
					set_position(set_year, set_month);
					gotoxy(61, 23);
					cout << set_year << "\b";
				}
			}


			else if (ch == 80)
			{
				if (lx == 44 && set_year>1990)
				{
					if (set_date>1)
					{
						set_date--;
						gotoxy(ptr_x, ptr_y);
						cout << " ";
						if (ptr_x>10)
							ptr_x -= 8;
						else
						{
							ptr_x = 58;
							ptr_y -= 2;
						}
						t--;
					}
					else
					{
						set_date = previous;
						t = arr;
						while (*t != set_date)
							t++;
						if (set_month>1)
							set_month--;
						else
						{
							set_month = 12;
							set_year--;
						}
						x = 10; y = 6;
						set_position(set_year, set_month);
					}
					gotoxy(ptr_x, ptr_y);
					cout << (char)94;
					gotoxy(45, 23);
					if (set_date >= 10)
						cout << set_date << "\b";
					else
						cout << set_date << " " << "\b\b";

				}
				else if (lx == 52)
				{
					if (set_month>1)
						set_month--;
					else
					{
						if (set_year >1990)
						{
							set_month = 12;
							set_year--;
						}
					}
					x = 10; y = 6;
					set_position(set_year, set_month);
					gotoxy(53, 23);
					cout << set_month << "\b";
				}
				else if (lx == 60 && set_year>1990)
				{
					set_year--;
					x = 10; y = 6;
					set_position(set_year, set_month);
					gotoxy(61, 23);
					cout << set_year << "\b";
				}

			}


			else if (ch == 77)
			{
				gotoxy(lx, 23);
				cout << " ";
				if (lx<60)
					lx += 8;
				else
				{
					lx = 44;
				}
				gotoxy(lx, 23);
				cout << (char)62 << "\b";
			}


			else if (ch == 75)
			{
				gotoxy(lx, 23);
				cout << " ";
				if (lx>44)
					lx -= 8;
				else
				{
					lx = 60;
				}
				gotoxy(lx, 23);
				cout << (char)62 << "\b";
			}


		}
	}

}

int is_leap_yr(int year)
{
	if ((year % 400 == 0) || (year % 4 == 0) && year % 100 != 0)
		return 1;
	else
		return 0;
}

void gotoxy(int x, int y) {
	COORD c = { x, y };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), c);
}


