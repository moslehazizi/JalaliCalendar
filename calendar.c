#include <stdio.h>
#include <ncurses.h>
#include <stdlib.h>
#include <stdbool.h>


// Menu
void option1();
void option2();
void option3();
void option4();
int calculateAge(int , int , int);
// End of menu


// Conversion
void convert1();
void convert2();
void convert3();
void convert4();
void convert5();
void convert6();
int shamsitogregorian(int,  int, int);
int shamsitoqamari(int , int ,int);
int numberOfLeaps2(int);
int daystoymd(int);
int daystoymdForQ(int);
long shamsiupload(int, int , int);
int miladiupload(int, int, int);
int numberOfLeapsG(int);
int lenofmonthG(int);
bool isLeapG(int);
int daysOfMonthQ(int);
int alldaysinG(int, int, int);
int numberOfLeapsFoConvert(int);
int numberOfLeapsQ(int);
bool isLeapQ(int);
int numberOfLeapsGfromF(int, int);
int daystoymdshFC(int);
// End of conversion

// Age section
int daysOfLeapYears(int, int);
int daysInbyear(int , int, int);
int monthDaysInyear(int);
int monthDaysInbyear(int, int);
int daystoymdsh(int);
// End of Age section


// Calendar
int calendar(int , int);
bool isLeap(int);
int getFirstDayOfYear(int);
int numberOfLeaps(int);
int dayscounter(int , int);
int lenofmonth(int , int);
// End of calendar


int main() {
    int choice;

    do {

        printf("---------------\n");
        printf("[1] exit\n");
        printf("[2] calendar\n");
        printf("[3] age\n");
        printf("[4] conversion\n");
        printf("---------------\n");
        printf("select option: ");


        scanf("%d", &choice);


        switch (choice) {
            case 1:
                option1();
                break;
            case 2:
                option2();
                break;
            case 3:
                option3();
                break;
            case 4:
                option4();
                break;
        }

    } while (choice != 4);


    return 0;
}


void option1() {
    exit(0);
}

void option4() {
    system("cls");
    printf("[0] back to menu\n");
    printf("*********************\n");
    printf("which type of convesion you want to do?\n");
    printf("-------------------\n");
    printf("[1] SHAMSI to MILADI\n");
    printf("[2] SHAMSI to QAMARI\n");
    printf("[3] miladi to shamsi\n");
    printf("[4] miladi to qamari\n");
    printf("[5] qamari to miladi\n");
    printf("[6] qamari to shamsi\n");
    printf("-------------------\n");

    int chose;
    scanf("%d", &chose);
    
    switch(chose){
        case 0:
           system("cls");
           main();
        case 1:
           system("cls");
           convert1();
           break;
        case 2:
           system("cls");
           convert2();
           break;
        case 3:
           system("cls");
           convert3();
           break;
        case 4:
           system("cls");
           convert4();
           break;
        case 5:
           system("cls");
           convert5();
           break;
        case 6:
           system("cls");
           convert6();
           break;
    }
}

void option3(){

    system("cls");
    printf("[0] back to menu\n");
    printf("----------------\n");

    int year;
    int month;
    int day;

    int byear;
    int bmonth;
    int bday;
    int daysToNow;

    printf("please enter your year of birth: \n");
    scanf("%d", &byear);

    printf("and the month of your birth: \n");
    scanf("%d", &bmonth);

    printf("and your birthday: \n");
    scanf("%d", &bday);

    printf("Please enter today's date, first enter year: \n");
    scanf("%d", &year);

    printf("Please enter today's date, second enter month: \n");
    scanf("%d", &month);

    printf("Please enter today's date, third enter day: \n");
    scanf("%d", &day);

    daysToNow = ((year - byear) * 365) + monthDaysInbyear(byear,bmonth) +  monthDaysInyear(month) + daysInbyear(byear, bmonth, bday) + day + daysOfLeapYears(year, byear);

    daystoymdsh(daysToNow);
    // int yearNum = (int)(daysToNow/365);
    // int daysRemain = daysToNow%365;
    // int monthNum = (int)(daysRemain/30);

}

int daystoymdsh(int days){

    int daysInMonth[] = {31, 31, 31, 31, 31, 31, 30, 30, 30, 30, 30, 29};
    int shamsiYear = 1; // The Gregorian calendar starts from year 1

    while (days > 365) {
        if (isLeap(shamsiYear)) {
            if (days >= 366) {
                days -= 366;
                shamsiYear++;
            }
        } else {
            days -= 365;
            shamsiYear++;
        }
    }

    int shamsiMonth = 0;
    while (days > daysInMonth[shamsiMonth]) {
        if (shamsiMonth == 12 && (isLeap(shamsiYear))) {
            if (days > 29) {
                days -= 29;
                shamsiMonth++;
            }
        } else {
            days -= daysInMonth[shamsiMonth];
            shamsiMonth++;
        }
    }

    int shYear = shamsiYear - 2;
    int shmMonth = shamsiMonth;
    int shDay = days + 1; // Days are 1-indexed

    printf("Your age is %d year and %d month and %d", shYear , shmMonth, shDay);
}

int daystoymdshFC(int days){

    int daysInMonth[] = {31, 31, 31, 31, 31, 31, 30, 30, 30, 30, 30, 29};
    int shamsiYear = 1;

    while (days > 365) {
        if (isLeap(shamsiYear)) {
            if (days >= 366) {
                days -= 366;
                shamsiYear++;
            }
        } else {
            days -= 365;
            shamsiYear++;
        }
    }

    int shamsiMonth = 0;
    while (days > daysInMonth[shamsiMonth]) {
        if (shamsiMonth == 12 && (isLeap(shamsiYear))) {
            if (days > 29) {
                days -= 29;
                shamsiMonth++;
            }
        } else {
            days -= daysInMonth[shamsiMonth];
            shamsiMonth++;
        }
    }

    int shYear = shamsiYear;
    int shmMonth = shamsiMonth;
    int shDay = days; // Days are 1-indexed

    printf("%d %d %d", shYear , shmMonth, shDay);
}

int monthDaysInbyear(int byear, int bmonth) {
    if (bmonth < 6 && isLeap(byear)) {
        return ((6-bmonth) * 31) + 180;
    } else if (bmonth == 6 && isLeap(byear)) {
        return 180;
    } else if (bmonth < 6 && !(isLeap(byear))) {
        return ((6-bmonth) * 31) + 179;
    } else if (bmonth == 6 && !(isLeap(byear))) {
        return 179;
    } else if (bmonth > 6 && bmonth !=12 && isLeap(byear)) {
        return ((11 - bmonth) * 30) + 30;
    } else if (bmonth > 6 && bmonth !=12 && !(isLeap(byear))) {
        return ((11 - bmonth) * 30) + 29;
    } else if (bmonth > 6 && bmonth ==12) {
        return 0;
    }
}

int monthDaysInyear(int month){
    if (month <= 6) {
        return ((month - 1) * 31);
    } else if (month > 6) {
        return (((month - 7) * 30) + 186);
    }
}

int daysInbyear(int byear, int bmonth, int bday){
    if (bmonth <= 6){
        return 31 - bday;
    } else if (bmonth > 6 && bmonth < 12) {
        return 30 - bday;
    } else if (bmonth == 12 && !(isLeap(byear))){
        return 29 - bday;
    } else if (bmonth == 12 && (isLeap(byear))){
        return 30 - bday;
    }
}

int daysOfLeapYears(int year, int byear) {
    int i;
    int counter = 0;
    
    for(i = byear ; i < year ; i++){
        if(isLeap(i)){
            counter += 1;
        }
    }
    
    return counter;
}

void option2() {
    
    int year;    
    int month;

    system("cls");
    printf("[0] back to menu\n");
    printf("----------------\n");

    printf("enter the year:");
    scanf("%d", &year);
    if(year == 0){
        system("cls");
        main();
    }

    printf("enter the month:");
    scanf("%d", &month);

    while(year != 0){
        calendar(year, month);
        printf("\n**************************************************");
        printf("\nENTER ANOTHER YEAR: ");
        scanf("%d", &year);
        printf("\nEnter ANOTHER MONTH: ");
        scanf("%d", &month);
    }
    system("cls");
    main();
         
}

//functions for calendar
int calendar(int year, int month){
    char *months[] = {"Farvardin", "Ordibehesht", "Khordad", "Tir", "Mordad", "Shavrivar", "Mehr", "Aban", "Azar", "Day", "Bahman", "Esfand"};
    int daysOfMonth[] = {31, 31, 31, 31, 31, 31, 30, 30, 30, 30, 30, 29};
    int i, j, weekDay = 0, spaceCounter = 0;

    //check leap year
    int x = year % 128;

    if(x==0 || x==4 || x==8 || x==12 || x==16 || x==20 || x==24 || x==29 || x==33 || x==37 || x==41 || x==45 || x==49 || x==53 || x==57 || x==62 || x==66 || x==70 || x==74 || x==78 || x==82 || x==86 || x==90 || x==95 || x==99 || x==103 || x==107 || x==111 || x==115 || x==119 || x==124){
        daysOfMonth[12]=30;
    }


    //get first day of year.
    weekDay += getFirstDayOfYear(year) + 5;

    if(weekDay > 6){
        weekDay = weekDay - 7;
    }

    int firstdayofmonth = (weekDay + dayscounter(month, year)) % 7;

    //print days
    printf("\n-------------------- %s ------------------\n", months[month - 1]);
    printf("    SH     YEK     DO     SE     CH     PA     JO    \n");
    //print space
    for(spaceCounter = 1; spaceCounter <= firstdayofmonth; spaceCounter++){
        printf("       ");
    }



    //print date of month
    for(j=1; j<= lenofmonth(month , year); j++){
        printf("%7d",j);
        firstdayofmonth++;

        if(firstdayofmonth > 6){
            printf("\n");
            firstdayofmonth = 0;
        }
    }
}

bool isLeap(int year){
    int x = year % 128;

    if(x==0 || x==4 || x==8 || x==12 || x==16 || x==20 || x==24 || x==29 || x==33 || x==37 || x==41 || x==45 || x==49 || x==53 || x==57 || x==62 || x==66 || x==70 || x==74 || x==78 || x==82 || x==86 || x==90 || x==95 || x==99 || x==103 || x==107 || x==111 || x==115 || x==119 || x==124){
        return true;
    }
    else
        return false;
}

int getFirstDayOfYear(int year){

    int firstday = ((year - 1206) * 365 + numberOfLeaps(year)) % 7;

    return firstday;
}

int numberOfLeaps(int year){

    int i;
    int counter = 0;
    
    for(i = 1206 ; i <= year ; i++){
        if(isLeap(i)){
            counter += 1;
        }
    }
    
    return counter;
}

int dayscounter(int month,int year){
    if(month >= 1 && month <= 6){
        int wantedmonth[31];
        int daystomonth = (month - 1) * 31;
        return daystomonth;
    }
    else if(month >= 7 && month < 12){
        int wantedmonth[30];
        int daystomonth = (6 * 31) + (month - 7) * 30;
        return daystomonth;
    }
    else if(month == 12){
        if(isLeap(year)){
            int wantedmonth[30];
        }
        else{
            int wantedmonth[29];
        }
        int daystomonth = (6 * 31) + (month - 7) * 30;
        return daystomonth;
    }
}
int lenofmonth(int month, int year) {
        if(month >= 1 && month <= 6){
        return 31;
    }
    else if(month >= 7 && month < 12){
        return 30;
    }
    else if(month == 12){
        if(isLeap(year)){
            return 30;
        }
        else{
            return 29;
        }
    }
}
// end of calendarfunctions


// functions for conversion
void convert1(){
    
    int year , month , day;

    printf("[0] back to menu of conversion\n");

    printf("**************************\n");
    printf("enter the year in SHAMSI: \n");
    scanf("%d" , &year);
    if(year == 0){
        system("cls");
        option4();
    }
    printf("enter the month in SHAMSI: \n");
    scanf("%d" , &month);
    printf("Enter the day in SHAMSI: \n");
    scanf("%d", &day);

    year += 1595;
    long days = -355668 + (365 * year) + (((int)(year / 33)) * 8) + ((int)(((year % 33) + 3) / 4)) + day + ((month < 7) ? (month - 1) * 31 : ((month - 7) * 30) + 186);
    long gy = 400 * ((int)(days / 146097));
    days %= 146097;
    if (days > 36524) {
    gy += 100 * ((int)(--days / 36524));
    days %= 36524;
    if (days >= 365) days++;
    }
    gy += 4 * ((int)(days / 1461));
    days %= 1461;
    if (days > 365) {
        gy += (int)((days - 1) / 365);
        days = (days - 1) % 365;
    }
    long gd = days + 1;
    long gm;
    {
        long sal_a[13] = {0, 31, ((gy % 4 == 0 && gy % 100 != 0) || (gy % 400 == 0)) ? 29 : 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
        for (gm = 0; gm < 13 && gd > sal_a[gm]; gm++) gd -= sal_a[gm];
    }
    int gyear = gy;
    int gmonth = gm;
    int gday = gd;
    
    printf("\n");

    printf("%d %d %d", gyear , gmonth, gday);

}

void convert2(){
    int year , month , day;
   
    printf("[00] back to menu of conversion\n");

    printf("**************************\n");
    printf("enter the year in SHAMSI: \n");
    scanf("%d" , &year);
    if(year == 0){
        system("cls");
        option4();
    }
    printf("enter the month in SHAMSI: \n");
    scanf("%d" , &month);
    printf("Enter the day in SHAMSI: \n");
    scanf("%d", &day);
    printf("**************************\n");

    // old method
    //long days = shamsiupload(year , month , day);
    //printf("\n");
    //daystoymdForQ(days);

    // new method : first shamsi date convert to gregorian then gregorian to qamari

    year += 1595;
    long days = -355668 + (365 * year) + (((int)(year / 33)) * 8) + ((int)(((year % 33) + 3) / 4)) + day + ((month < 7) ? (month - 1) * 31 : ((month - 7) * 30) + 186);
    long gy = 400 * ((int)(days / 146097));
    days %= 146097;
    if (days > 36524) {
    gy += 100 * ((int)(--days / 36524));
    days %= 36524;
    if (days >= 365) days++;
    }
    gy += 4 * ((int)(days / 1461));
    days %= 1461;
    if (days > 365) {
        gy += (int)((days - 1) / 365);
        days = (days - 1) % 365;
    }
    long gd = days + 1;
    long gm;
    {
        long sal_a[13] = {0, 31, ((gy % 4 == 0 && gy % 100 != 0) || (gy % 400 == 0)) ? 29 : 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
        for (gm = 0; gm < 13 && gd > sal_a[gm]; gm++) gd -= sal_a[gm];
    }
    int gyear = gy;
    int gmonth = gm;
    int gday = gd;
    
	unsigned long jd,l,j,n;   

	if ((gy>1582)||((gy==1582)&&(gm>10))||((gy==1582)&&(gm==10)&&(gd>14)))
		jd=(1461*(gy+4800+(gm-14)/12))/4+(367*(gm-2-12*((gm-14)/12)))/12-(3*((gy+4900+(gm-14)/12)/100))/4+gd-32075;

	else jd = 367*gy-(7*(gy+5001+(gm-9)/7))/4+(275*gm)/9+gd+1729777;
        
	l=jd-1948440+10632;
                                                
	n=(l-1)/10631;
	l=l-10631*n+354;
	j=((10985-l)/5316)*((50*l)/17719)+(l/5670)*((43*l)/15238);
	l=l-((30-j)/15)*((17719*j)/50)-(j/16)*((15238*j)/43)+29; 
                                        
                                        
    int hmonth = (24*l)/709;
	int hyear = 30*n+j-30;
    int hday = l-(709 * hmonth)/24;

    printf("\n");

    printf("%d %d %d", hyear , hmonth, hday);

}

void convert3(){

    int year , month , day;

    printf("**************************\n");
    printf("enter the year in MILADI: \n");
    scanf("%d" , &year);
    printf("enter the month in MILADI: \n");
    scanf("%d" , &month);
    printf("Enter the day in MILADI: \n");
    scanf("%d", &day);
    printf("**************************\n");

    long days;
    long jm;
    long jd;
    {
        long gy2 = (month > 2) ? (year + 1) : year;
        long g_d_m[12] = {0, 31, 59, 90, 120, 151, 181, 212, 243, 273, 304, 334};
        days = 355666 + (365 * year) + ((int)((gy2 + 3) / 4)) - ((int)((gy2 + 99) / 100)) + ((int)((gy2 + 399) / 400)) + day + g_d_m[month - 1];
    }
    long jy = -1595 + (33 * ((int)(days / 12053)));
    days %= 12053;
    jy += 4 * ((int)(days / 1461));
    days %= 1461;
    if (days > 365) {
        jy += (int)((days - 1) / 365);
        days = (days - 1) % 365;
    }
    if (days < 186) {
        jm = 1 + (int)(days / 31);
        jd = 1 + (days % 31);
    } else {
        jm = 7 + (int)((days - 186) / 30);
        jd = 1 + ((days - 186) % 30);
    }

    int jyear = jy;
    int jmonth = jm;
    int jday = jd;
    
    printf("\n");

    printf("%d %d %d", jyear , jmonth, jday);

}


void convert4(){
    int year , month , day;

    printf("[0] back to menu of conversion\n");

    printf("**************************\n");
    printf("enter the year in MILADI: \n");
    scanf("%d" , &year);
    if(year == 0){
        system("cls");
        option4();
    }
    printf("enter the month in MILADI: \n");
    scanf("%d" , &month);
    printf("Enter the day in MILADI: \n");
    scanf("%d", &day);
    printf("**************************\n");

    // This is old method and not accurate:
        //int days = miladiupload(year , month , day);
        //printf("\n");
        //daystoymd(days);3

    unsigned long jd,l,j,n;   

	if ((year>1582)||((year==1582)&&(month>10))||((year==1582)&&(month==10)&&(day>14)))
		jd=(1461*(year+4800+(month-14)/12))/4+(367*(month-2-12*((month-14)/12)))/12-(3*((year+4900+(month-14)/12)/100))/4+day-32075;

	else jd = 367*year-(7*(year+5001+(month-9)/7))/4+(275*month)/9+day+1729777;
        
	l=jd-1948440+10632;
                                                
	n=(l-1)/10631;
	l=l-10631*n+354;
	j=((10985-l)/5316)*((50*l)/17719)+(l/5670)*((43*l)/15238);
	l=l-((30-j)/15)*((17719*j)/50)-(j/16)*((15238*j)/43)+29; 
                                        
                                        
    int hmonth = (24*l)/709;
	int hyear = 30*n+j-30;
    int hday = l-(709 * hmonth)/24;

    printf("\n");

    printf("%d %d %d", hyear , hmonth, hday);

}

// This is convert qamaro to miladi
void convert5(){
    int year , month , day;
    printf("[0] back to menu of conversion\n");

    printf("**************************\n");
    printf("enter the year in QAMARI: \n");
    scanf("%d" , &year);
    if(year == 0){
        system("cls");
        option4();
    }
    printf("enter the month in QAMARI: \n");
    scanf("%d" , &month);
    printf("Enter the day in QAMARI: \n");
    scanf("%d", &day);
    printf("**************************\n");

    int days = ((year - 1) * 354) + daysOfMonthQ(month) + day + numberOfLeapsQ(year) + 227074 - 60 ;

    printf("\n");

    daystoymd(days);
}

// This is convert qamari to shamsi
void convert6(){
    int year , month , day;

    printf("[0] back to menu of conversion\n");
    
    

    printf("**************************\n");
    printf("enter the year in QAMARI: \n");
    scanf("%d" , &year);
    if(year == 0){
        system("cls");
        option4();
    }
    printf("enter the month in QAMARI: \n");
    scanf("%d" , &month);
    printf("Enter the day in QAMARI: \n");
    scanf("%d", &day);
    printf("**************************\n");

    //int days = ((year - 1) * 354) + daysOfMonthQ(month) + day + numberOfLeapsQ(year) - 60;
    //printf("\n");
    //daystoymdshFC(days);

    int qd = ((year - 1) * 354) + daysOfMonthQ(month) + day + numberOfLeapsQ(year) + 227074 - 60 ;
    printf("\n");
    //daystoymd(days);
    int daysInMonth[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    int gregorianYear = 1; // The Gregorian calendar starts from year 1

    while (qd > 365) {
        if (isLeapG(gregorianYear)) {
            if (qd >= 366) {
                qd -= 366;
                gregorianYear++;
            }
        } else {
            qd -= 365;
            gregorianYear++;
        }
    }

    int gregorianMonth = 0;
    while (qd > daysInMonth[gregorianMonth]) {
        if (gregorianMonth == 1 && (isLeapG(gregorianYear))) {
            if (qd > 29) {
                qd -= 29;
                gregorianMonth++;
            }
        } else {
            qd -= daysInMonth[gregorianMonth];
            gregorianMonth++;
        }
    }

    int Gyear = gregorianYear;
    int Gmonth = gregorianMonth + 1; // Months are 1-indexed
    int Gday = qd + 1; // Days are 1-indexed

    long days;
    long jm;
    long jd;
    {
        long gy2 = (Gmonth > 2) ? (Gyear + 1) : Gyear;
        long g_d_m[12] = {0, 31, 59, 90, 120, 151, 181, 212, 243, 273, 304, 334};
        days = 355666 + (365 * Gyear) + ((int)((gy2 + 3) / 4)) - ((int)((gy2 + 99) / 100)) + ((int)((gy2 + 399) / 400)) + Gday + g_d_m[Gmonth - 1];
    }
    long jy = -1595 + (33 * ((int)(days / 12053)));
    days %= 12053;
    jy += 4 * ((int)(days / 1461));
    days %= 1461;
    if (days > 365) {
        jy += (int)((days - 1) / 365);
        days = (days - 1) % 365;
    }
    if (days < 186) {
        jm = 1 + (int)(days / 31);
        jd = 1 + (days % 31);
    } else {
        jm = 7 + (int)((days - 186) / 30);
        jd = 1 + ((days - 186) % 30);
    }

    int jyear = jy;
    int jmonth = jm;
    int jday = jd - 2;
    
    printf("\n");

    printf("%d %d %d", jyear , jmonth, jday);
}

// This is for old method not accurate
int daystoymdForQ(int days){
    int daysInQMonth[] = {30, 29, 30, 29, 30, 29, 30, 29, 30, 29, 30, 29};
    int qamariYear = 1;

    while (days > 354) {
        if (qamariYear % 30 == 2 || qamariYear % 30 == 5 || qamariYear % 30 == 7 || qamariYear % 30 == 10 || qamariYear % 30 == 13 || qamariYear % 30 == 16 || qamariYear % 30 == 18 || qamariYear % 30 == 21 || qamariYear % 30 == 24 || qamariYear % 30 == 26 || qamariYear % 30 == 29){
            if (days >= 355) {
                days -= 355;
                qamariYear++;
            }
        } else {
            days -= 354;
            qamariYear++;
        }
    }

    int qMonth = 0;
    while (days > daysInQMonth[qMonth]) {
        if (qMonth == 0 || qMonth == 2 || qMonth == 4 || qMonth == 6 || qMonth == 8 || qMonth == 10) {
            if (days > 30) {
                days -= 30;
                qMonth++;
            }
        } else if (qMonth == 1 || qMonth == 3 || qMonth == 5 || qMonth == 7 || qMonth == 9) {
            if (days > 29) {
                days -= 29;
                qMonth++;
            }
        }else if (qMonth == 11 && (qamariYear % 30 == 2 || qamariYear % 30 == 5 || qamariYear % 30 == 7 || qamariYear % 30 == 10 || qamariYear % 30 == 13 || qamariYear % 30 == 16 || qamariYear % 30 == 18 || qamariYear % 30 == 21 || qamariYear % 30 == 24 || qamariYear % 30 == 26 || qamariYear % 30 == 29)) {
            if (days > 30) {
                days -= 30;
                qMonth++;
            }
        } else if (qMonth == 11 && !(qamariYear % 30 == 2 || qamariYear % 30 == 5 || qamariYear % 30 == 7 || qamariYear % 30 == 10 || qamariYear % 30 == 13 || qamariYear % 30 == 16 || qamariYear % 30 == 18 || qamariYear % 30 == 21 || qamariYear % 30 == 24 || qamariYear % 30 == 26 || qamariYear % 30 == 29))
            if (days > 29) {
                    days -= 29;
                    qMonth++;
            }
    }

    printf("%d %d %d", qamariYear , qMonth, days);
}

// This is for old method not accurate, this func is to converts days to year, month and day in gregorian
int daystoymd(int days){

    int daysInMonth[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    int gregorianYear = 1; // The Gregorian calendar starts from year 1

    while (days > 365) {
        if (isLeapG(gregorianYear)) {
            if (days >= 366) {
                days -= 366;
                gregorianYear++;
            }
        } else {
            days -= 365;
            gregorianYear++;
        }
    }

    int gregorianMonth = 0;
    while (days > daysInMonth[gregorianMonth]) {
        if (gregorianMonth == 1 && (isLeapG(gregorianYear))) {
            if (days > 29) {
                days -= 29;
                gregorianMonth++;
            }
        } else {
            days -= daysInMonth[gregorianMonth];
            gregorianMonth++;
        }
    }

    int Gyear = gregorianYear;
    int Gmonth = gregorianMonth + 1; // Months are 1-indexed
    int Gday = days + 1; // Days are 1-indexed

    printf("%d %d %d", Gyear , Gmonth, Gday);
}

// This is for old method, this func is to calculate number of days of shamsi date
long shamsiupload(int year , int month , int day){
    if (month <= 6){
        long days = ((year - 1) * 365) + ((month - 1) * 31) + day + numberOfLeapsFoConvert(year - 1); //hijri
        return days;
    }
    else if (month > 6 && month <= 12) {
        long days = ((year - 1) * 365) + (6 * 31) + ((month - 7) * 30) + day + numberOfLeapsFoConvert(year - 1); //hijri
        return days;
    } 
}

// This is for old method, not used
int miladiupload(int year , int month , int day){
    int days = (year) * 365 + lenofmonthG(month-1) + day + numberOfLeapsG(year) + ((year * 5.8)/24); //miladi
    return days;
}

// This is for old method, this func is to check leap years in greorian.
bool isLeapG(int year) {
    if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0)) {
        return true; // It's a leap year
    } else {
        return false; // It's not a leap year
    }
}

// I don't know what is this func for
int lenofmonthG(int month){
    if(month == 1)
        return 31;
    else if(month == 2)
        return 31 + 29;
    else if(month == 3)
        return 31 + 29 + 31;
    else if(month == 4)
        return 31 + 31 + 29 + 30;
    else if(month == 5)
        return 31 + 29 + 31 + 30 + 31;
    else if(month == 7)
        return 31 + 29 + 31 + 30 + 31 + 30;
    else if(month == 8)
        return 31 + 29 + 31 + 30 + 31 + 30 + 31;
    else if(month == 9)
        return 31 + 29 + 31 + 30 + 31 + 30 + 31 + 31;
    else if(month == 10)
        return 31 + 29 + 31 + 30 + 31 + 30 + 31 + 31 + 30;
    else if(month == 11)
        return 31 + 29 + 31 + 30 + 31 + 30 + 31 + 31 + 30 + 31;
    else if(month == 12)
        return 31 + 29 + 31 + 30 + 31 + 30 + 31 + 31 + 30 + 31 + 30;
}

// This is for old method, this func is to calculate number of leap years.
int numberOfLeapsG(int year){

    int i;
    int counter = 0;
    
    for(i = 0 ; i <= year ; i++){
        if(isLeapG(i)){
            counter += 1;
        }
    }
    
    return counter;
}

int numberOfLeapsGfromF(int year, int fyear){

    int i;
    int counter = 0;
    
    for(i = fyear ; i <= year ; i++){
        if(isLeapG(i)){
            counter += 1;
        }
    }
    
    return counter;
}

// This is for old method, this func is for calculating number of all days in gregorian.
int alldaysinG(int year, int month, int day){
    int days = shamsiupload(year , month , day) + (621 * 365);
    return days;
}

// This is for old method, this func is for calculating leap years for converting.
int numberOfLeapsFoConvert(int year){

    int i;
    int counter = 0;
    
    for(i = 1 ; i < year ; i++){
        if(isLeap(i)){
            counter += 1;
        }
    }
    
    return counter;
}

int daysOfMonthQ(int month) {
    if (month == 2) {
        return 30;
    } else if (month == 3){
        return 30 + 29;
    } else if (month == 4) {
        return 30 + 29 + 30;
    } else if (month == 5){
        return 30 + 29 + 30 + 29;
    } else if (month == 6){
        return 30 + 29 + 30 + 29 + 30;
    } else if (month == 7){
        return 30 + 29 + 30 + 29 + 30 + 29;
    } else if (month == 8){
        return 30 + 29 + 30 + 29 + 30 + 29 + 30;
    } else if (month == 9){
        return 30 + 29 + 30 + 29 + 30 + 29 + 30 + 29;
    } else if (month == 10){
        return 30 + 29 + 30 + 29 + 30 + 29 + 30 + 29 + 30;
    } else if (month == 11){
        return 30 + 29 + 30 + 29 + 30 + 29 + 30 + 29 + 30 + 29;
    } else if (month == 12){
        return 30 + 29 + 30 + 29 + 30 + 29 + 30 + 29 + 30 + 29 + 30;
    } 
}

int numberOfLeapsQ(int year){

    int i;
    int counter = 0;
    
    for(i = 0 ; i <= year ; i++){
        if(isLeapQ(i)){
            counter += 1;
        }
    }
    
    return counter;
}

bool isLeapQ(int year) {
    if (year % 30 == 2 || year % 30 == 5 || year % 30 == 7 || year % 30 == 10 || year % 30 == 13 || year % 30 == 16 || year % 30 == 18 || year % 30 == 21 || year % 30 == 24 || year % 30 == 26 || year % 30 == 29){
        return true;
    } else {
        return false;
    }
}