#include<iostream>
#include<list>
#include<bits/stdc++.h>

using namespace std;
string months[] = {"January", "February", "March",
                   "April", "May", "June",
                   "July", "August", "September",
                   "October", "November", "December"
                  };
string days[]= {"Sun","Mon","Tue","Wed","Thu","Fri","Sat"};

int **dates=new int *[12];


struct reminder
{
    string reminder_title;
    string reminder_description;
    int reminder_date;
    string reminder_month;
};

int total_days(int month_no, int year)
{
    if(month_no==0 || month_no==2 || month_no==4 || month_no==6 ||month_no==7 || month_no==9 || month_no==11 )
    {
        return (31);
    }
    if(month_no==1)
    {
        if(((year % 4 == 0) && (year % 100 != 0)) || (year % 400 == 0))
        {
            return (29);
        }
        else
        {
            return (28);
        }
    }
    else
    {
        return (30);
    }
}

list<reminder>mylist;

int reminder_exists(int given_date, string given_month)
{

    if(mylist.empty()==true)
    {
        return 0;
    }
    else
    {
        for (list<reminder>::iterator it=mylist.begin() ; it != mylist.end(); ++it)
        {
            if(it->reminder_date==given_date && it->reminder_month==given_month )
            {

                return 1;
            }
        }
    }
}

void print_new_calendar(int year, string starting_day,reminder r)
{
    for(int i=0; i<12; i++)
    {
        int days_in_month=total_days(i,year);
        cout<<"   ----------------"<<months[i]<<"---------------- \n"<<endl;

        for(int j=0; j<7; j++)
        {
            cout<<"   "<<days[j];
        }
        cout<<endl;
        if(days_in_month==31)
        {
            for(int j=0; j<31; j++)
            {
                dates[i][j]=j+1;
            }
        }
        else if(days_in_month==30)
        {
            for(int j=0; j<30; j++)
            {
                dates[i][j]=j+1;
            }
        }
        else if(days_in_month==29)
        {
            for(int j=0; j<29; j++)
            {
                dates[i][j]=j+1;
            }
        }
        else
        {
            for(int j=0; j<28; j++)
            {
                dates[i][j]=j+1;
            }
        }
        int start=0;
        for(int j=0; j<7; j++)
        {
            if(days[j]==starting_day)
            {
                start=j;
            }
        }

        for(int j=0; j<start; j++)
        {
            cout<<"      ";
        }
        int week_days=start;
        for(int k=0; k<days_in_month; k++)
        {
            if(reminder_exists(dates[i][k],months[i])==1)
            {
                if(k<9)
                {
                    cout<<"    *"<<dates[i][k];
                }
                else
                {
                    cout<<"   *"<<dates[i][k];
                }

            }
            else
            {
                if(k<9)
                {
                    cout<<"     "<<dates[i][k];
                }
                else
                {
                    cout<<"    "<<dates[i][k];
                }
            }

            week_days++;
            if(week_days>6)
            {
                week_days=0;
                cout<<endl;
            }
        }
        cout<<endl;
        cout<<endl;
        starting_day= days[week_days];
    }
    cout<<endl;
}



void add_reminder(int year,string starting_day)
{

    reminder r;
    cout<<"Reminder title: ";
    cin.ignore();
    getline(cin, r.reminder_title);
    cout<<"Reminder description: ";
    getline(cin, r.reminder_description);
    cout<<"Date: ";
    cin>>r.reminder_date;
    cout<<"Month (Keep first letter capital): ";
    cin>>r.reminder_month;
    mylist.push_back(r);
    print_new_calendar(year, starting_day,r);
}


void update_reminder(int year,string starting_day)
{

    reminder u;
    cout<<"Reminder title: ";
    cin.ignore();
    getline(cin, u.reminder_title);
    cout<<"Reminder description: ";
    getline(cin, u.reminder_description);
    cout<<"Date: ";
    cin>>u.reminder_date;
    cout<<"Month (Keep first letter capital): ";
    cin>>u.reminder_month;
    if(reminder_exists(u.reminder_date, u.reminder_month)==1)
    {
        for (list<reminder>::iterator it=mylist.begin() ; it != mylist.end(); ++it)
        {

            for(int i=0; i<4; i++)
            {
                cout<<endl<<"To update title          ---press 1: "<<endl;
                cout<<"To update description    ---press 2: "<<endl;
                cout<<"To update reminder date  ---press 3: "<<endl;
                cout<<"To update reminder month ---press 4: "<<endl;
                cout<<"To exit press 0: "<<endl;
                cout<<endl<<"Enter your choice : ";
                if(it->reminder_title == u.reminder_title  && it->reminder_date == u.reminder_date && it->reminder_month == u.reminder_month)
                {
                    int choice;
                    cin>>choice;

                    if(choice==1)
                    {
                        if(u.reminder_title==it->reminder_title)
                        {

                            cout<<"Enter the new title:";
                            cin.ignore();
                            getline(cin, u.reminder_title);
                            it->reminder_title=u.reminder_title;
                        }
                    }

                    else if(choice==2)
                    {
                        if(u.reminder_description==it->reminder_description)
                        {
                            cout<<"Enter the new description:";
                            cin.ignore();
                            getline(cin, u.reminder_description);
                            it->reminder_description=u.reminder_description;

                        }

                    }
                    else if(choice==3)
                    {
                        if(u.reminder_date==it->reminder_date)
                        {

                            cout<<"Enter the new date:";
                            cin>> u.reminder_date;
                            it->reminder_date=u.reminder_date;

                        }

                    }
                    else if(choice==4)
                    {
                        if(u.reminder_month==it->reminder_month)
                        {

                            cout<<"Enter the new month (Keep first letter capital):";
                            cin>>u.reminder_month;
                            it->reminder_month=u.reminder_month;

                        }
                    }
                    else if(choice==0)
                    {
                        break;
                    }
                }

            }

        }
        print_new_calendar(year, starting_day,u);
    }
    else
    {
        cout<<endl;
        cout<<"No reminder matches the input"<<endl;
    }
}


void delete_reminder(int year,string starting_day)
{
    reminder d;
    cout<<"Reminder title: ";
    cin.ignore();
    getline(cin, d.reminder_title);
    cout<<"Date: ";
    cin>>d.reminder_date;
    cout<<"Month (Keep first letter capital): ";
    cin>>d.reminder_month;
    if(reminder_exists(d.reminder_date, d.reminder_month)==1)
    {
        for(list<reminder>::iterator it=mylist.begin() ; it != mylist.end(); ++it)
        {
            if(it->reminder_title==d.reminder_title &&  it->reminder_date==d.reminder_date && it->reminder_month==d.reminder_month)
            {
                mylist.erase(it);
                break;
            }
        }
        cout<<endl<<"Reminder deleted"<<endl;
        print_new_calendar(year, starting_day,d);

    }
    else
    {
        cout<<endl;
        cout<<"No reminder matches the input"<<endl;
    }

}

int reminder_exists_in_the_month( string given_month)
{
    if(mylist.empty()==false)
    {
        for (list<reminder>::iterator it=mylist.begin() ; it != mylist.end(); ++it)
        {
            if( it->reminder_month==given_month )
            {
                return 1;
            }
        }
    }
    else
    {
        return 0;
    }
}


void view_reminder()
{
    reminder v;
    cout<<"Enter month name you want to view reminder (Keep first letter capital): ";
    cin>>v.reminder_month;
    if(reminder_exists_in_the_month( v.reminder_month)==1)
    {
        int rem_num=1;
        for(list<reminder>::iterator it=mylist.begin() ; it != mylist.end(); ++it)
        {
            if( it->reminder_month==v.reminder_month)
            {

                cout<<"Reminder "<<rem_num<<": "<<endl;
                cout<<"Title       : "<<it->reminder_title<<endl;
                cout<<"Description : "<<it->reminder_description<<endl;
                cout<<"Date        : "<<it->reminder_date<<endl;
                cout<<"Month       : "<<it->reminder_month<<endl;

            }
            rem_num++;
            cout<<endl;
        }
    }
    else
    {
        cout<<endl<<"No reminder in this month"<<endl;
    }

}

void  print_calendar(int year,string starting_day)
{

    for(int i=0; i<12; i++)
    {
        int days_in_month=total_days(i,year);
        cout<<"   ----------------"<<months[i]<<"---------------- \n"<<endl;

        for(int j=0; j<7; j++)
        {
            cout<<"   "<<days[j];
        }
        cout<<endl;
        if(days_in_month==31)
        {
            dates[i]=new int[31];
            for(int j=0; j<31; j++)
            {
                dates[i][j]=j+1;
            }
        }
        else if(days_in_month==30)
        {
            dates[i]=new int[30];
            for(int j=0; j<30; j++)
            {
                dates[i][j]=j+1;
            }
        }
        else if(days_in_month==29)
        {
            dates[i]=new int[29];
            for(int j=0; j<29; j++)
            {
                dates[i][j]=j+1;
            }
        }
        else
        {
            dates[i]=new int[28];
            for(int j=0; j<28; j++)
            {
                dates[i][j]=j+1;
            }
        }
        int start=0;
        for(int j=0; j<7; j++)
        {
            if(days[j]==starting_day)
            {
                start=j;
            }
        }

        for(int j=0; j<start; j++)
        {
            cout<<"      ";
        }
        int week_days=start;
        for(int k=0; k<days_in_month; k++)
        {
            if(k<9)
            {
                cout<<"     "<<dates[i][k];
            }
            else
            {
                cout<<"    "<<dates[i][k];
            }
            week_days++;
            if(week_days>6)
            {
                week_days=0;
                cout<<endl;
            }
        }
        cout<<endl;
        cout<<endl;
        starting_day= days[week_days];
    }
    cout<<endl;
}

int main()
{
    int year,choice;
    cout<<"Enter the year :";
    cin>>year;
    string starting_day;
    cout<<"Starting day of the year (Sun,Mon,Tue,Wed,Thu,Fri,Sat):";
    cin>>starting_day;

    print_calendar(year,starting_day);
    cout<<endl;
    while(1)
    {
        cout<<endl<<"Add Reminder         -- Press 1"<<endl;
        cout<<"Update Reminder      -- Press 2"<<endl;
        cout<<"Delete Reminder      -- Press 3"<<endl;
        cout<<"View Reminder        -- Press 4"<<endl;
        cout<<"Exit                 -- Press 0"<<endl;
        cout<<endl<<"Enter your choice : ";
        cin>>choice;
        if(choice==1)
        {
            add_reminder(year,starting_day);
        }
        else if(choice==2)
        {
            update_reminder(year,starting_day);
        }
        else if(choice==3)
        {
            delete_reminder(year,starting_day);

        }
        else if(choice==4)
        {
            view_reminder();
        }
        else if(choice==0)
        {
            break;
        }
    }
return 0;
}
