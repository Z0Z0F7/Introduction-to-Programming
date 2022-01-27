#include<bits/stdc++.h>
using namespace std;

typedef struct Date
{
    int da_year;  //年
    int da_mon;  //月
    int da_day;  //日
}DATE;

typedef struct Time
{
    int ti_hour;   //小时
    int ti_min;   //分钟
    int ti_sec;    //秒
}TIME;

//void getTime2()
//{
//    
//    time_t rawtime;
//    struct tm * timeinfo;
//    time ( &rawtime );
//    timeinfo = localtime ( &rawtime );
//    char mytime[80];
//    strcpy(mytime,asctime(timeinfo));
//    
//    
//    printf ( "\007The current date/time is: %s", mytime );
//}

void getTime(struct Date *m,struct Time *n);

int  main ()
{
    DATE date;
    TIME time;
    getTime(&date,&time);
    printf("year:%d,month:%d,day:%d\nhour:%d,min:%d,sec:%.2d\n",date.da_year,date.da_mon,date.da_day,time.ti_hour,time.ti_min,time.ti_sec);
    return 0;
}

void getTime(Date *m,Time *n)
{
	time_t rawtime;
    struct tm * timeinfo;
    time ( &rawtime );
    timeinfo = localtime ( &rawtime );
    char mytime[80];
    strcpy(mytime,asctime(timeinfo));
    
    
    printf ( "The current date/time is: %s", mytime );
    
    char month[][4]={"Jan","Feb","Mar","Apr","May","Jun","Jul","Aug","Sep","Oct","Nov","Dec"};
    for(int i=0;i<12;i++)
    {
    	if(mytime[4]==month[i][0]&&mytime[5]==month[i][1]&&mytime[6]==month[i][2])
    	{
    		m->da_mon=i+1;
		}
	}
	m->da_year=(mytime[20]-'0')*1000+(mytime[21]-'0')*100+(mytime[22]-'0')*10+(mytime[23]-'0');
	m->da_day=(mytime[8]-'0')*10+(mytime[9]-'0');
    n->ti_sec=(mytime[17]-'0')*10+(mytime[18]-'0');
	n->ti_min=(mytime[14]-'0')*10+(mytime[15]-'0');
	n->ti_hour=(mytime[11]-'0')*10+(mytime[12]-'0');
	
}

//	The current date/time is: Fri Dec 24 11:36:26 2021
//	year:2021,month:12,day:24
//	hour:11,min:36,sec:26
//	
//	The current date/time is: Fri Dec 24 14:44:11 2021
