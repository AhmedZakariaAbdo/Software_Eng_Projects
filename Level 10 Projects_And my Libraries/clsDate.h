#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <ctime>
#include "clsString.h"
using namespace std;

class clsDate
{
private:
    short _Day = 1;
    short _Month = 1;
    short _Year = 1900;

public:
    // ==================== Constructors ====================
    clsDate()
    {
        *this = GetSystemDate();
    }

    clsDate(short Day, short Month, short Year)
    {
        _Day = Day;
        _Month = Month;
        _Year = Year;
    }

    clsDate(string sDate)
    {
        vector<string> vDate = clsString::SplitString(sDate, "/");
        if (vDate.size() >= 3)
        {
            _Day = stoi(vDate[0]);
            _Month = stoi(vDate[1]);
            _Year = stoi(vDate[2]);
        }
    }

    clsDate(short DateOrderInYear, short Year)
    {
        *this = GetDateFromDayOrderInYear(DateOrderInYear, Year);
    }

    // ==================== Getters & Setters ====================
    void SetDay(short Day) { if (Day >= 1 && Day <= 31) _Day = Day; }
    short GetDay() const { return _Day; }

    void SetMonth(short Month) { if (Month >= 1 && Month <= 12) _Month = Month; }
    short GetMonth() const { return _Month; }

    void SetYear(short Year) { _Year = Year; }
    short GetYear() const { return _Year; }

    void Print() const
    {
        cout << DateToString() << endl;
    }

    // ==================== Static Functions ====================
    static clsDate GetSystemDate()
    {
        time_t t = time(0);
        tm* now = localtime(&t);
        return clsDate(now->tm_mday, now->tm_mon + 1, now->tm_year + 1900);
    }

    static string DateToString(clsDate Date)
    {
        return to_string(Date._Day) + "/" + to_string(Date._Month) + "/" + to_string(Date._Year);
    }

    string DateToString() const
    {
        return DateToString(*this);
    }

    static bool isLeapYear(short Year)
    {
        return (Year % 4 == 0 && Year % 100 != 0) || (Year % 400 == 0);
    }

    bool isLeapYear() const
    {
        return isLeapYear(_Year);
    }

    static short NumberOfDaysInAYear(short Year)
    {
        return isLeapYear(Year) ? 366 : 365;
    }

    short NumberOfDaysInAYear() const
    {
        return NumberOfDaysInAYear(_Year);
    }

    static short NumberOfDaysInAMonth(short Month, short Year)
    {
        if (Month < 1 || Month > 12) return 0;
        short Days[12] = { 31,28,31,30,31,30,31,31,30,31,30,31 };
        return (Month == 2) ? (isLeapYear(Year) ? 29 : 28) : Days[Month - 1];
    }

    short NumberOfDaysInAMonth() const
    {
        return NumberOfDaysInAMonth(_Month, _Year);
    }

    static short DayOfWeekOrder(short Day, short Month, short Year)
    {
        short a = (14 - Month) / 12;
        short y = Year - a;
        short m = Month + (12 * a) - 2;
        return (Day + y + (y / 4) - (y / 100) + (y / 400) + (31 * m / 12)) % 7;
    }

    short DayOfWeekOrder() const
    {
        return DayOfWeekOrder(_Day, _Month, _Year);
    }

    static string DayShortName(short DayOfWeek)
    {
        string arr[] = { "Sun","Mon","Tue","Wed","Thu","Fri","Sat" };
        return arr[DayOfWeek];
    }

    string DayShortName() const
    {
        return DayShortName(DayOfWeekOrder());
    }

    static string MonthShortName(short MonthNumber)
    {
        string Months[12] = { "Jan", "Feb", "Mar", "Apr", "May", "Jun",
                             "Jul", "Aug", "Sep", "Oct", "Nov", "Dec" };
        return Months[MonthNumber - 1];
    }

    string MonthShortName() const
    {
        return MonthShortName(_Month);
    }

    // ==================== Core Date Functions ====================
    static short DaysFromTheBeginingOfTheYear(short Day, short Month, short Year)
    {
        short TotalDays = 0;
        for (short i = 1; i < Month; i++)
            TotalDays += NumberOfDaysInAMonth(i, Year);
        TotalDays += Day;
        return TotalDays;
    }

    short DaysFromTheBeginingOfTheYear() const
    {
        return DaysFromTheBeginingOfTheYear(_Day, _Month, _Year);
    }

    static clsDate GetDateFromDayOrderInYear(short DateOrderInYear, short Year)
    {
        clsDate Date;
        short RemainingDays = DateOrderInYear;
        Date._Year = Year;
        Date._Month = 1;

        while (true)
        {
            short MonthDays = NumberOfDaysInAMonth(Date._Month, Year);
            if (RemainingDays > MonthDays)
            {
                RemainingDays -= MonthDays;
                Date._Month++;
            }
            else
            {
                Date._Day = RemainingDays;
                break;
            }
        }
        return Date;
    }

    static bool IsDate1BeforeDate2(clsDate Date1, clsDate Date2)
    {
        if (Date1._Year < Date2._Year) return true;
        if (Date1._Year > Date2._Year) return false;

        if (Date1._Month < Date2._Month) return true;
        if (Date1._Month > Date2._Month) return false;

        return Date1._Day < Date2._Day;
    }

    bool IsDateBeforeDate2(clsDate Date2) const
    {
        return IsDate1BeforeDate2(*this, Date2);
    }

    static bool IsDate1EqualDate2(clsDate Date1, clsDate Date2)
    {
        return (Date1._Year == Date2._Year && Date1._Month == Date2._Month && Date1._Day == Date2._Day);
    }

    bool IsDateEqualDate2(clsDate Date2) const
    {
        return IsDate1EqualDate2(*this, Date2);
    }

    static bool IsLastDayInMonth(clsDate Date)
    {
        return Date._Day == NumberOfDaysInAMonth(Date._Month, Date._Year);
    }

    bool IsLastDayInMonth() const
    {
        return IsLastDayInMonth(*this);
    }

    static clsDate AddOneDay(clsDate Date)
    {
        if (IsLastDayInMonth(Date))
        {
            if (IsLastMonthInYear(Date._Month))
            {
                Date._Day = 1;
                Date._Month = 1;
                Date._Year++;
            }
            else
            {
                Date._Day = 1;
                Date._Month++;
            }
        }
        else
        {
            Date._Day++;
        }
        return Date;
    }

    void AddOneDay() { *this = AddOneDay(*this); }

    static int GetDifferenceInDays(clsDate Date1, clsDate Date2, bool IncludeEndDay = false)
    {
        int Days = 0;
        short SwapFlag = 1;

        if (!IsDate1BeforeDate2(Date1, Date2))
        {
            swap(Date1, Date2);   // تحتاج #include <algorithm> أو استخدم SwapDates
            SwapFlag = -1;
        }

        while (IsDate1BeforeDate2(Date1, Date2))
        {
            Days++;
            Date1 = AddOneDay(Date1);
        }

        return IncludeEndDay ? ++Days * SwapFlag : Days * SwapFlag;
    }

    int GetDifferenceInDays(clsDate Date2, bool IncludeEndDay = false) const
    {
        return GetDifferenceInDays(*this, Date2, IncludeEndDay);
    }

    void AddDays(short Days)
    {
        for (short i = 1; i <= Days; i++)
            AddOneDay();
    }

    static bool IsLastMonthInYear(short Month) { return Month == 12; }

    // Increase & Decrease + Business Days + Vacation يمكن إضافتها لاحقاً

    static bool IsWeekEnd(clsDate Date)
    {
        short DayIndex = DayOfWeekOrder(Date._Day, Date._Month, Date._Year);
        return (DayIndex == 5 || DayIndex == 6); // Fri or Sat
    }

    bool IsWeekEnd() const { return IsWeekEnd(*this); }
};