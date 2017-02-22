#include <Date.h>
using namespace std;

void check(int c)
{

    switch(c)
    {
        case 1 :
                 {
                    cout<<"Case 1 : ";
                    cout<<"Format - ";
                    Date::getFormat().printformat();
                    cout<<"\nConstructing Date 13-11-2011 : ";
                    Date d1("13-11-2011");
                 }
                    break;

        case 2 :
                  {
                      cout<<"\nCase 2 :  Format - ";
                      DateFormat f ("dd-mm-yyyy");
                      Date::setFormat(f);
                      Date::getFormat().printformat();
                      cout<<"\nConstructing Date 13-11-2011 ... ";
                      Date d1("13-11-2011");
                      cout<<"Constructed";
                      cout<<"\nConstructing Date 13-1-2011 ... ";
                      Date d2("13-1-2011");
                      cout<<"Constructed";
                  }
                    break;

        case 3 :
                  {
                      cout<<"\nCase 3 :  Format - ";
                      DateFormat f ("d-m-yy");
                      Date::setFormat(f);
                      Date::getFormat().printformat();
                      cout<<"\nConstructing Date 13-11-11 ... ";
                      Date d1("13-11-11");
                      cout<<"Constructed";
                      cout<<"\nConstructing Date 13-1-11 ... ";
                      Date d2("13-1-11");
                      cout<<"Constructed";
                      cout<<"\nConstructing Date 1-1-11 ... ";
                      Date d3("1-1-11");
                      cout<<"Constructed";
                      cout<<"\nConstructing Date 1-1-2011 ... ";
                      Date d4("1-1-2011");
                      cout<<"Constructed";
                  }
                   break;

        case 4 :
                  {
                      cout<<"\nCase 4 :  Format - ";
                      DateFormat f ("d-m-yyyy");
                      Date::setFormat(f);
                      Date::getFormat().printformat();
                      cout<<"\nConstructing Date 13-11-2011 ... ";
                      Date d1("13-11-2011");
                      cout<<"Constructed";
                      cout<<"\nConstructing Date 13-1-2011 ... ";
                      Date d2("13-1-2011");
                      cout<<"Constructed";
                      cout<<"\nConstructing Date 1-1-2011 ... ";
                      Date d3("1-1-2011");
                      cout<<"Constructed";
                      cout<<"\nConstructing Date 1-1-11 ... ";
                      Date d4("1-1-11");
                      cout<<"Constructed";
                  }
                   break;

        case 5 :
                  {
                        cout<<"\nCase 5 : print current date in various formats using ostream "<<endl;
                        cout<<"Constructing Current Date ... ";
                        Date d1;
                        cout<<"Constructed";
                        cout<<"\nCurrent date in Format : "<<endl;
                        cout<<"dd-mm-yy - "<<d1;
                        DateFormat f("dd-mmm-yyyy");
                        Date::setFormat(f);
                        cout<<"dd-mmm-yyyy - "<<d1;
                        f = DateFormat("dd-mm-yyyy");
                        Date::setFormat(f);
                        cout<<"dd-mm-yyyy - "<<d1;
                        f = DateFormat("dd-m-yy");
                        Date::setFormat(f);
                        cout<<"dd-m-yy - "<<d1;
                        f = DateFormat("d-m-yy");
                        Date::setFormat(f);
                        cout<<"d-m-yy - "<<d1;
                        f = DateFormat("d-m-yyyy");
                        Date::setFormat(f);
                        cout<<"d-m-yyyy - "<<d1;
                  }
                   break;

        case 6 :
                   {
                      cout<<"\nCase 6 :  Output Date using ostream ";
                      DateFormat f ("dd-mm-yy");
                      Date::setFormat(f);
                      cout<<"\nFrom now on DateFormat is : dd-mm-yy\n";
                      cout<<"Constructing current Date ... ";
                      Date d1;
                      cout<<"Constructed";
                      cout<<"\nCurrent Date : "<<d1;
                      cout<<"Constructing Date 29-02-16 ... ";
                      Date d2("29-02-16");
                      cout<<"Constructed";
                      cout<<"\nDate : "<<d2;
                   }
                    break;

        case 7 :
                   {
                      cout<<"\nCase 7 :  out of range for above constructor Date(Day d, Month m, Year y) ";
                      cout<<"\nConstructing Date 31-12-49 ... ";
                      Date d1(D31,Dec,2049);
                      cout<<"Constructed";
                      cout<<"\nDate d1 : "<<d1;
                      cout<<"Constructing Date 01-01-50 ... ";
                      Date d2(D01,Jan,2050);
                      cout<<"Constructed";
                      cout<<"\nDate d2 : "<<d2;
                   }
                    break;

        case 8 :
                    {
                       cout<<"\nCase 8 :  Next day ";
                       cout<<"\nConstructing Current Date ... ";
                       Date d;
                       cout<<"Constructed";
                       cout<<"\nCurrent Date is "<<d;
                       Date n = ++d;
                       cout<<"Next Day of Current Date is: "<<n;
                       cout<<"Constructing Date 31-12-15 ... ";
                       Date d1(D31,Dec,2015);
                       cout<<"Constructed";
                       cout<<"\nDate d1 : "<<d1;
                       Date n1 = ++d1;
                       cout<<"Next Day of d1: "<<n1;
                       cout<<"Constructing Date 29-02-16 ... ";
                       Date d2(D29,Feb,2016);
                       cout<<"Constructed";
                       cout<<"\nDate d2 : "<<d2;
                       Date n2 = ++d2;
                       cout<<"Next Day of d2 : "<<n2;
                       cout<<"Constructing Date 31-12-49 ... ";
                       Date d3(D31,Dec,2049);
                       cout<<"Constructed";
                       cout<<"\nDate d3 : "<<d3;
                       cout<<"Next Day of d3 : ";
                       Date n3 = ++d3;
                       cout<<n3;
                    }
                     break;

         case 9 :
                    {
                       cout<<"\nCase 9 :  Previous day ";
                       cout<<"\nConstructing Current Date ... ";
                       Date d;
                       cout<<"Constructed";
                       cout<<"\nCurrent Date is "<<d;
                       Date n = --d;
                       cout<<"Previous Day of Current Date is: "<<n;
                       cout<<"Constructing Date 01-01-16 ... ";
                       Date d1(D01,Jan,2016);
                       cout<<"Constructed";
                       cout<<"\nDate d1 : "<<d1;
                       Date n1 = --d1;
                       cout<<"Previous Day of d1: "<<n1;
                       cout<<"Constructing Date 01-05-16 ... ";
                       Date d2(D01,May,2016);
                       cout<<"Constructed";
                       cout<<"\nDate d2 : "<<d2;
                       Date n2 = --d2;
                       cout<<"Previous Day of d2 : "<<n2;
                       cout<<"Constructing Date 01-01-50 ... ";
                       Date d3(D01,Jan,1950);
                       cout<<"Constructed";
                       cout<<"\nDate d3 : "<<d3;
                       cout<<"Previous Day of d3 : ";
                       Date n3 = --d3;
                       cout<<n3;
                    }
                     break;

         case 10 :
                    {
                       cout<<"\nCase 10 :  Same day next week ";
                       cout<<"\nConstructing Current Date ... ";
                       Date d;
                       cout<<"Constructed";
                       cout<<"\nCurrent Date is "<<d;
                       d++;
                       cout<<"Same day next week of Current Date is: "<<d;
                       cout<<"Constructing Date 30-12-15 ... ";
                       Date d1(D30,Dec,2015);
                       cout<<"Constructed";
                       cout<<"\nDate d1 : "<<d1;
                       d1++;
                       cout<<"Same day next week of d1: "<<d1;
                       cout<<"Constructing Date 25-02-16 ... ";
                       Date d2(D25,Feb,2016);
                       cout<<"Constructed";
                       cout<<"\nDate d2 : "<<d2;
                       d2++;
                       cout<<"Same day next week of d2 : "<<d2;
                       cout<<"Constructing Date 26-12-49 ... ";
                       Date d3(D26,Dec,2049);
                       cout<<"Constructed";
                       cout<<"\nDate d3 : "<<d3;
                       cout<<"Same day next week of d3 : ";
                       d3++;
                       cout<<d3;
                    }
                     break;

         case 11 :
                    {
                       cout<<"\nCase 11 : Same day previous week ";
                       cout<<"\nConstructing Current Date ... ";
                       Date d;
                       cout<<"Constructed";
                       cout<<"\nCurrent Date is "<<d;
                       d--;
                       cout<<"Same day previous week of Current Date is: "<<d;
                       cout<<"Constructing Date 01-01-16 ... ";
                       Date d1(D01,Jan,2016);
                       cout<<"Constructed";
                       cout<<"\nDate d1 : "<<d1;
                       d1--;
                       cout<<"Same day previous week of d1: "<<d1;
                       cout<<"Constructing Date 01-05-16 ... ";
                       Date d2(D01,May,2016);
                       cout<<"Constructed";
                       cout<<"\nDate d2 : "<<d2;
                       d2--;
                       cout<<"Same day previous week of d2 : "<<d2;
                       cout<<"Constructing Date 01-01-50 ... ";
                       Date d3(D01,Jan,1950);
                       cout<<"Constructed";
                       cout<<"\nDate d3 : "<<d3;
                       cout<<"Same day previous week of d3 : ";
                       d3--;
                       cout<<d3;
                    }
                     break;

         case 12 :
                    {
                        cout<<"\nCase 12 : Number of days between otherDate and current date : ";
                        cout<<"\nConstructing Current Date ... ";
                        Date d1;
                        cout<<"Constructed";
                        cout<<"\nCurrent Date - "<<d1;
                        cout<<"Constructing Other Date 31-01-17 ... ";
                        Date d2(D31,Jan,2017);
                        cout<<"Constructed";
                        cout<<"\nOther Date d2 - "<<d2;
                        unsigned int dif = d1 - d2;
                        cout<<"Differnce between current date and date d2 is "<<dif<<endl;
                        cout<<"Constructing Other Date 29-02-16 ... ";
                        Date d3(D29,Feb,2016);
                        cout<<"Constructed";
                        cout<<"\nOther Date d3 - "<<d3;
                        dif = d1 - d3;
                        cout<<"Differnce between current date and date d3 is "<<dif<<endl;
                    }
                     break;

         case 13 :
                    {
                        cout<<"\nCase 13 : Day noOfDays after the current date";
                        cout<<"\nConstructing Current Date ... ";
                        Date d1;
                        cout<<"Constructed";
                        cout<<"\nCurrent Date is "<<d1;
                        Date d2 = d1 + 100;
                        cout<<"Day after 100 days of current date is "<<d2;
                        Date d3 = d1 + 365;
                        cout<<"Day after 365 days of current date is "<<d3;
                        Date d4 = d1 + 30;
                        cout<<"Day after 30 days of current date is "<<d4;
                        Date d5 = d1 + 1000;
                        cout<<"Day after 1000 days of current date is "<<d5;
                    }
                     break;

         case 14 :
                    {
                        cout<<"\nCase 14 : Day noOfDays before the current date";
                        cout<<"\nConstructing Current Date ... ";
                        Date d1;
                        cout<<"Constructed";
                        cout<<"\nCurrent Date is "<<d1;
                        Date d2 = d1 + (-100);
                        cout<<"Day before 100 days of current date is "<<d2;
                        Date d3 = d1 + (-365);
                        cout<<"Day before 365 days of current date is "<<d3;
                        Date d4 = d1 + (-30);
                        cout<<"Day before 30 days of current date is "<<d4;
                        Date d5 = d1 + (-1000);
                        cout<<"Day before 1000 days of current date is "<<d5;
                    }
                     break;

         case 15 :
                    {
                        cout<<"\nCase 15 : WeekNumber , Weekday , Month ";
                        cout<<"\nConstructing Current Date ... ";
                        Date d1;
                        cout<<"Constructed";
                        cout<<"\nCurrent Date is "<<d1;
                        cout<<"WeekNumber of Current date is "<<WeekNumber(d1);
                        cout<<"\nWeekday of Current date is "<<weekNames[WeekDay(d1)-1];
                        cout<<"\nMonth of Current date is "<<monthNames[Month(d1)-1]<<endl;
                        cout<<"Constructing Date 01-01-16... ";
                        Date d2(D01,Jan,2016);
                        cout<<"Constructed";
                        cout<<"\nDate d2 is "<<d2;
                        cout<<"WeekNumber of date d2 is "<<WeekNumber(d2);
                        cout<<"\nWeekday of date d2 is "<<weekNames[WeekDay(d2)-1];
                        cout<<"\nMonth of date d2 is "<<monthNames[Month(d2)-1]<<endl;
                        cout<<"Constructing Date 01-01-15... ";
                        Date d3(D01,Jan,2015);
                        cout<<"Constructed";
                        cout<<"\nDate d3 is "<<d3;
                        cout<<"WeekNumber of date d3 is "<<WeekNumber(d3);
                        cout<<"\nWeekday of date d3 is "<<weekNames[WeekDay(d3)-1];
                        cout<<"\nMonth of date d3 is "<<monthNames[Month(d3)-1]<<endl;
                        cout<<"Constructing Date 31-12-14... ";
                        Date d4(D31,Dec,2014);
                        cout<<"Constructed";
                        cout<<"\nDate d4 is "<<d4;
                        cout<<"WeekNumber of date d4 is "<<WeekNumber(d4);
                        cout<<"\nWeekday of date d4 is "<<weekNames[WeekDay(d4)-1];
                        cout<<"\nMonth of date d4 is "<<monthNames[Month(d4)-1]<<endl;
                    }
                     break;

         case 16 :
                    {
                        cout<<"\nCase 16 : Binary Relational Operators ";
                        cout<<"\nConstructing Current Date ... ";
                        Date d1;
                        cout<<"Constructed";
                        cout<<"\nDate d1 (current date) is "<<d1;
                        cout<<"Constructing Other Dates ... ";
                        Date d2;
                        cout<<"\nDate d2 is "<<d2;
                        if(d1 == d2)
                            cout<<"Date d1 and d2 are same \n";
                        else
                            cout<<"Date d1 and d2 are different \n";
                        Date d3(D28,Feb,2016);
                        cout<<"Date d3 is "<<d3;
                        Date d4(D25,Dec,2016);
                        cout<<"Date d4 is "<<d4;
                        if(d1 > d3)
                            cout<<"Date d1 is after d3 \n";
                        if(d1 < d3)
                            cout<<"Date d1 is before d3 \n";

                        if(d1 > d4)
                            cout<<"Date d1 is after d4"<<endl;
                        if(d1 < d4)
                            cout<<"Date d1 is before d4"<<endl;
                        if(d1 >= d2)
                            cout<<"Date d1 is after or same as d2"<<endl;
                        if(d1 >= d3)
                            cout<<"Date d1 is after or same as d3"<<endl;
                        if(d1 >= d4)
                            cout<<"Date d1 is after or same as d4"<<endl;
                        if(d1 <= d2)
                            cout<<"Date d1 is before or same as d2"<<endl;
                        if(d1 <= d3)
                            cout<<"Date d1 is before or same as d3"<<endl;
                        if(d1 <= d4)
                            cout<<"Date d1 is before or same as d4"<<endl;
                    }
                     break;

         case 17 :
                    {
                        cout<<"\nCase 17 :  Constructing Date using Date(Day d, Month m, Year y) ";
                        cout<<"\nConstructing Date 01-01-16 ... ";
                        Date d1(D01,Jan,2016);
                        cout<<"Constructed";
                        cout<<"\nDate d1 : "<<d1;
                        cout<<"Constructing Date 29-02-16 ... ";
                        Date d2(D29,Feb,2016);
                        cout<<"Constructed";
                        cout<<"\nDate d2 : "<<d2;
                        cout<<"Constructing Date 31-04-16 ... ";
                        Date d3(D31,Apr,2016);
                        cout<<"Constructed";
                        cout<<"\nDate d3 : "<<d3;
                    }
    }
}

void TestDate()
{
    int i;
    for(i=1; i<=17; i++)
    {
        try {
        check(i);
        }
        catch (const domain_error &e)
        {
            cerr << "error -"<< e.what() <<endl;
        }
        catch (const out_of_range& oor)
        {
            cerr << "error - " << oor.what() <<endl;
        }
        catch (const invalid_argument& er)
        {
            cerr << "error - " << er.what() <<endl;
        }
    }
}
