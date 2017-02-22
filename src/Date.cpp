#include "Date.h"
#include<string>
#include <cstdlib>
#include <stdlib.h>

ostream& operator<< (ostream& out, const Date& date)
{
    DateFormat f = Date::getFormat();
    if (f.getdateformat() == NULL);
	else
    {
        if (strlen(f.getdateformat()) == 2)
        {
            if(date.day < 10)
            out<<"0";
        }
        out<<date.day<<"-";
    }
    if(strlen(f.getmonthformat()) == 3)
    {
        out<<monthNames[date.mon-1]<<"-";
    }
    else
    {
        if(strlen(f.getmonthformat()) == 2)
        {
            if(date.mon < 10)
                out<<"0";
        }
        out<<date.mon<<"-";
    }

    if(strlen(f.getyearformat()) == 4)
        out<<date.year<<endl;
    else if(strlen(f.getyearformat()) == 2)
    {
        int y = date.year%100;
        if(y < 10)
            cout<<"0";
        out<<y<<endl;
    }
	return out;
}

istream& operator>> (istream& in, Date& date)
{
    char *str = new char[20];
    in>>str;
    Date d(str);
    date = d;
    return in;
}

// intializing static variable
DateFormat Date::format ;

void Date::setFormat(DateFormat& df)
{
    format = df;
}

DateFormat& Date::getFormat()
{
    return format;
}

void DateFormat::printformat()
{
    cout<<dateFormat<<"-";
    cout<<monthFormat<<"-";
    cout<<yearFormat;
}

char* DateFormat::getdateformat()
{
    return dateFormat;
}

char* DateFormat::getmonthformat()
{
    return monthFormat;
}

char* DateFormat::getyearformat()
{
    return yearFormat;

}

DateFormat::DateFormat(const char* dateFormat, const char* monthFormat, const char* yearFormat)
{
			this->dateFormat = new char [strlen(dateFormat) + 1];
			strcpy(this->dateFormat,dateFormat);
			this->monthFormat = new char [strlen(monthFormat) + 1];
			strcpy(this->monthFormat,monthFormat);
			this->yearFormat = new char [strlen(yearFormat) + 1];
			strcpy(this->yearFormat,yearFormat);
}

DateFormat::DateFormat(const char* format)
{
			this->dateFormat = new char [3];
			this->monthFormat = new char [4];
			this->yearFormat = new char [5];
			int i = 0 , j = 0;
			while(format[i] != '-')
			{
				this->dateFormat[i] = format[i];
				i++;
			}
			this->dateFormat[i] = '\0';
			i++;
			while(format[i] != '-')
			{
				this->monthFormat[j] = format[i];
				j++;
				i++;
			}
			this->monthFormat[j] = '\0';
			i++;  j=0;
			while(format[i] != '\0')
			{
				this->yearFormat[j] = format[i];
				j++;
				i++;
			}
			this->yearFormat[j] = '\0';
}

DateFormat& DateFormat::operator= (const DateFormat& df)
{
			strcpy(this->dateFormat , df.dateFormat);
			strcpy(this->monthFormat , df.monthFormat);
			strcpy(this->yearFormat , df.yearFormat);
			return *this;
}

// Default DateFormat created as "dd-mmm-yy"
DateFormat::DateFormat()
{
			this->dateFormat = new char [3];
			strcpy(this->dateFormat,"dd");
			this->monthFormat = new char [4];
			strcpy(this->monthFormat,"mmm");
			this->yearFormat = new char [3];
			strcpy(this->yearFormat,"yy");
}

DateFormat::~DateFormat()
{
			//cout<<"delete ";
			delete[] dateFormat;
			delete[] monthFormat;
			delete[] yearFormat;
}

Date::Date ()
{
            time_t currentTime;
  			struct tm *localTime;

  			time( &currentTime );                   // Get the current time
  			localTime = localtime( &currentTime );  // Convert the current time to the local time

  			int D    = localTime->tm_mday;
  			int M  = localTime->tm_mon + 1;
  			int Y   = localTime->tm_year + 1900;

  			if(Y > 2049)
                throw out_of_range("out of range");

  			this->day = static_cast<Day>(D);
  			this->mon = static_cast<Month>(M);
  			this->year = Y;

}

Date::Date(Day d, Month m, Year y) throw(invalid_argument,domain_error,out_of_range)	// Construct a Date from (d, m, y)
{
			if((y > 99 && y < 1950) || y > 2049 )
			{
				throw out_of_range ("out of range ");
			}
			if(y < 100)
            {
                if (y>0 && y<50)
                    y = 2000 + y;
                else if (y>=50)
                    y = 1900 + y;
            }

			if (d > monthDays[m-1])
			{
				if(m == 2 && d == 29 )
				{
					if(y % 4 != 0)
						throw domain_error ("domain error");
				}
				else
					throw domain_error ("domain error");
			}
			day = d;
			mon = m;
			year = y;
}

Date::Date (const char* date) throw(invalid_argument,domain_error,out_of_range)
{
    DateFormat f = Date::getFormat();
    int len = strlen(date);
    int cnt = 0;
    for(int i = 0; i<len; i++)
    {
        if (date[i] == '-')
            cnt++;
    }
    if(cnt != 2)
        throw invalid_argument("invalid argument");

    char* datef = new char [10];
    char* monthf = new char [10];
    char* yearf = new char [10];
    int i = 0 , j = 0;
    while(date[i] != '-')
    {
        datef[i] = date[i];
        i++;
    }
    datef[i] = '\0';
    i++;
    while(date[i] != '-')
    {
        monthf[j] = date[i];
        j++;
        i++;
    }
    monthf[j] = '\0';
    i++;  j=0;
    while(date[i] != '\0')
    {
        yearf[j] = date[i];
        j++;
        i++;
    }
    yearf[j] = '\0';
    if(strlen(f.getmonthformat()) == 3)
        throw invalid_argument("This Format is for output only!!!");

    if(strlen(datef) != strlen(f.getdateformat()) || strlen(monthf) != strlen(f.getmonthformat()) || strlen(yearf) != strlen(f.getyearformat()) )
    {
        if(strlen(f.getdateformat()) == 1 );
        else
            throw invalid_argument("Not according to Format!!!");
        if(strlen(f.getmonthformat()) == 1);
        else
            throw invalid_argument("Not according to Format!!!");
        if (strlen(yearf) != strlen(f.getyearformat()))
            throw invalid_argument("Not according to Format!!!");
    }

    int d , m , y;
    d = atoi(datef);
    m = atoi(monthf);
    y = atoi(yearf);
    this->day = static_cast<Day>(d);
    this->mon = static_cast<Month>(m);
    if (y < 100)
    {
        if(y>0 && y<50)
            y = y + 2000;
        else
            y = y + 1900;
    }
    if ( m == 2)
    {
        if(leapYear())
        {
            if(d > 29)
                throw domain_error("domain error");
        }
        else
        {
            if(d > 28)
                throw domain_error("domain error");
        }
    }
    else if (m==4 || m==6 || m==9 || m==11)
    {
        if(d > 30)
            throw domain_error("domain error");
    }
    if(y > 2049 || y < 1950)
        throw out_of_range("out of range");
    this->year = y;
}

Date::~Date() {} // Destructor

Date::Date(const Date& date)
{
    this->day = date.day;
    this->mon = date.mon;
    this->year = date.year;
}

Date& Date::operator=(const Date& date)
{
    if (this == &date) return *this; // handle self assignment
    //assignment operator
    this->day = date.day;
    this->mon = date.mon;
    this->year = date.year;
    return *this;
}

bool Date::leapYear() const // True if the year of the current date is a leap year
{
			if(this->year % 4 == 0)
			{
				return true;
			}
			return false;
}

Date& Date::operator++() // Next day
{
			 if (this->day == 31)
			 {
			 	if(this->mon == 12)
			 	{
			 		if (this->year >= 2049)
                        throw out_of_range("out of range");

			 		this->day = D01;
			 		this->mon = Jan;
			 		(this->year)++;
				}
				else
				{
					this->day = D01;
					int i = static_cast<int>(this->mon);
					this->mon = static_cast<Month>(i+1);
				}
			 }
			 else if (this->day == 30)
			 {
			 	if(this->mon == 4 || this->mon == 6 || this->mon == 9 || this->mon == 11)
			 	{
			 		this->day = D01;
					int i = static_cast<int>(this->mon);
					this->mon = static_cast<Month>(i+1);
				}
				else
				{
					this->day = D31;
				}
			 }
			 else if (this->mon == 2)
			 {
			 	if( leapYear() )
			 	{
			 		if(this->day == 29)
			 		{
			 			this->day = D01;
			 			this->mon = Mar;
					}
					else
					{
						int i = static_cast<int>(this->day);
						this->day = static_cast<Day>(i+1);
					}
				}
				else
				{
					if(this->day == 28)
			 		{
			 			this->day = D01;
			 			this->mon = Mar;
					}
					else
					{
						int i = static_cast<int>(this->day);
						this->day = static_cast<Day>(i+1);
					}
				}
			 }
			 else
			 {
			 	int i = static_cast<int>(this->day);
				this->day = static_cast<Day>(i+1);
			 }
			return *this;
}

		// Same day next week
Date& Date::operator++(int)
{
    Date d(*this);
    for(int i = 0; i < 7; i++)
        ++(*this);
    return d;
}

Date& Date::operator--()// Previous day
{
			if(this->day == 1)
			{
				if(this->mon == 1)
				{
				    if(year <= 1950)
                        throw out_of_range("out of range");
					this->day = D31;
					this->mon = Dec;
					year--;
				}
				else if (this->mon == 2 || this->mon == 4 || this->mon == 6 || this->mon == 9 || this->mon == 11 || this->mon == 8)
				{
					this->day = D31;
					int i = static_cast<int>(this->mon);
					this->mon = static_cast<Month>(i-1);
				}
				else if (this->mon == 3)
				{
					if(leapYear() )
					{
						this->day = D29;
						this->mon = Feb;
					}
					else
					{
						this->day = D28;
						this->mon = Feb;
					}
				}
				else
				{
					this->day = D30;
					int i = static_cast<int>(this->mon);
					this->mon = static_cast<Month>(i-1);
				}
			}
			else
			{
				int i = static_cast<int>(this->day);
				this->day = static_cast<Day>(i-1);
			}
			return *this;
}

Date& Date::operator--(int) // Same day previous week
{
    Date d(*this);
    for(int i = 0; i < 7; i++)
        --(*this);
    return d;
}

// BINARY RELATIONAL OPERATORS
bool Date::operator==(const Date& otherDate)
{
			if(this->day != otherDate.day)
			{
				return false;
			}
			if(this->mon != otherDate.mon)
			{
				return false;
			}
			if(this->year != otherDate.year)
			{
				return false;
			}
			return true;
}

bool Date::operator!=(const Date& otherDate)
{
			if((*this) == otherDate)
                return false;
            else
                return true;
}

bool Date::operator<(const Date& otherDate)
{
		    if((*this) == otherDate)
                return false;

			if(otherDate.year > this->year)
			{
				return true;
			}
			else if (otherDate.year < this->year)
			{
				return false;
			}
			else
			{
				if (otherDate.mon > this->mon)
					return true;
				else if (otherDate.mon < this->mon)
					return false;
				else
				{
					if (otherDate.day > this->day)
						return true;
					else if (otherDate.day < this->day)
						return false;
					else
						return false;
				}
			}
}

bool Date::operator<=(const Date& otherDate)
{
			if ((*this) == otherDate)
                return true;
            if((*this) < otherDate)
                return true;
            else
                return false;
}

bool Date::operator>(const Date& otherDate)
{
			if((*this) == otherDate)
                return false;
            else if ((*this) < otherDate)
                return false;
            else
                return true;
}

bool Date::operator>=(const Date& otherDate)
{
			if ((*this) == otherDate)
                return true;
            if((*this) > otherDate)
                return true;
            else
                return false;
}

int Date::countLeapYears(Year year,Month m)
{
    // Check if the current year needs to be considered
    // for the count of leap years or not
    if (m <= 2)
        year--;
    // An year is a leap year if it is a multiple of 4,
    // multiple of 400 and not a multiple of 100.
    return (year / 4 - year / 100 + year / 400);
}

unsigned int Date::operator-(const Date& otherdate)
{
	Year y = this->year;
	if(y<100)
	{
		if(y >= 50)
			y = 1900 + y;
		else
			y = 2000 + y;
	}
	long int n1 = y*365 + this->day;

    // Add days for months in given date
    for (int i=0; i<this->mon - 1; i++)
        n1 += monthDays[i];

    // Since every leap year is of 366 days,
    // Add a day for every leap year
    n1 += countLeapYears( y ,this->mon);

    // SIMILARLY, COUNT TOTAL NUMBER OF DAYS BEFORE 'dt2'
    y = otherdate.year;
    if(y<100)
	{
		if(y >= 50)
			y = 1900 + y;
		else
			y = 2000 + y;
	}

    long int n2 = y*365 + otherdate.day;
    for (int i=0; i<otherdate.mon - 1; i++)
        n2 += monthDays[i];
    n2 += countLeapYears(y,otherdate.mon );

    // return difference between two counts
    n2 = (n2 - n1);
    if (n2 < 0)
        n2 = (-1) * n2 ;
    return n2;
}

Date Date::operator+(int n) throw(domain_error, out_of_range)
{
	Date d(*this);
	if(n>0)
	{
		while(n >= 365)
		{
			if(d.leapYear() && d.mon<=2)
				n--;
			n = n - 365;
			d.year++;
			if(d.leapYear() && d.mon>2)
				n--;
		}
		while(n >= 7)
		{
			d++;
			n = n-7;
		}
		while(n > 0)
		{
			++d;
			--n;
		}
		if(n<0)
			--d;
        if(d.year > 2049)
            throw out_of_range("out of range");
	}
	else
    {
        while(n <= -365)
		{
			if(d.leapYear() && d.mon>2)
				n++;
			n = n + 365;
			d.year--;
			if(d.leapYear() && d.mon<=2)
				n++;
		}
		while(n <= -7)
		{
			d--;
			n = n+7;
		}
		while(n < 0)
		{
			--d;
			++n;
		}
		if(n>0)
			++d;
        if(d.year < 1950)
            throw out_of_range("out of range");
    }
	return d;
}

// CAST OPERATORS
Date::operator WeekNumber() const // Cast to the week number of the year in which the current date falls
{
			Date ds(D01,Jan,1950);
			if (ds - (*this) == 0)
			{
			     WeekNumber w = W53;
			     return w;
			}
			Date d1(D01,Jan,this->year);
            WeekDay wd = WeekDay(d1);
            int d = static_cast<int>(wd);
			int n;
			if(d <= 4)
			{
				n = d - 1;
				for(int i=0; i<this->mon - 1; i++)
					n += monthDays[i];
			}
			else
			{
				 n = d - 8;
				for(int i=0; i<this->mon - 1; i++)
					n += monthDays[i];
			}
			n += this->day;
			if(this->mon > 2)
			{
				if(leapYear())
					n++;
			}
			if (n < 0)
			 	return Date(D31,Dec,this->year-1);
			else
			{
				//n += d;
				if(n % 7 == 0)
					n = n / 7 ;
				else
					n = n / 7 + 1 ;

				if (n == 53)
                {
                    Date temp(D01,Jan,this->year + 1);
                    WeekDay wd = WeekDay(temp);
                    if(wd <= 4 && WeekDay(*this) < wd)
                        n = 1;
                }
				WeekNumber wn = static_cast<WeekNumber>(n);
				return wn;
			}
}

Date::operator Month() const // Cast to the month of the year in which the current date falls
{
			return mon;
}

Date::operator WeekDay() const // Cast to the day of the week of the current date
{
			Date d1(D01,Jan,1950);
			if (d1 - (*this) == 0)
            {
                WeekDay w = Sun;
                return w;
            }
            ++d1;
			Date d2(this->day,this->mon,this->year);
			unsigned int d = d1 - d2;
			d = d % 7;
			WeekDay wd = Mon;
			d++;
			wd = static_cast<WeekDay>(d);
			return wd;
}
