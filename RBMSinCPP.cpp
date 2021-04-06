#include<fstream.h>
#include<conio.h>
#include<stdio.h>
#include<process.h>

class Economy {
    double year,gdp,mic,gold,exp,imp,pop,aeqd,gdpr,gdppc,gnp,diff,re,rr,fiscal;
    int infl;
    public:
    void enter() { //function to get input from the user
        cout<<"Enter year: ";
        cin>>year;
        cout<<"Enter GDP of the country in billion USD: ";
        cin>>gdp;
        cout<<"Enter money in circulation in trillion USD: ";
        cin>>mic;
        cout<<"Enter gold reserves present with central bank in tonnes: ";
        cin>>gold;
        cout<<"Enter amount eqivalent to 1 USD: ";
        cin>>aeqd;
        cout<<"Enter population of country in millions: ";
        cin>>pop;
        cout<<"Enter GDP growth rate: ";
        cin>>gdpr;
        cout<<"Enter GNP of country in billion USD: ";
        cin>>gnp;
        cout<<"Enter exports for the year in billion USD:";
        cin>>exp;
        cout<<"Enter imports for the year in billion USD: ";
        cin>>imp;
        cout<<"Enter revenue expenditure in million USD: ";
        cin>>re;
        cout<<"Enter revenue receipts in million USD: ";
        cin>>rr;
        cout<<"Enter inflation rate: ";
        cin>>infl;
        
    }
    void calcpercapita() {
        gdppc = gdp/pop;
    }
    void calcdiff() {
        diff = exp-imp;
    }
    void calcfiscal() {
        fiscal = re-rr;
    }
    double retyear() {
        return year;
    }
    Economy() {
        diff = 0;
        gdppc = 0;
        fiscal = 0;
    }
    void display() {   //function to display the data of the class
        cout<<"Year: "<<year<<endl;
        cout<<"GDP: "<<gdp<<"units \n";
        cout<<"Money in circuation in trillion USD: "<<mic<<endl;
        cout<<"Gold reserves present with central bank: "<<gold<<endl;
        cout<<"Amount equivalent to 1 USD: "<<aeqd<<endl;
        cout<<"GDP per capita: "<<gdppc<<endl;
        cout<<"GDP growth rate: "<<gdpr<<endl;
        cout<<"Gross National Product: "<<gnp<<endl;
        cout<<"Difference between import and export: "<<diff<<"\n";
        cout<<"Fiscal deficit: "<<fiscal<<endl;
        cout<<"Inflation rate: "<<infl<<'\n';
    }
}e;

void calculate();

void create() {
    char rep = 'y';
    ofstream fout("economy.dat", ios::binary);
    do {
        e.enter();
        calculate();
        fout.write((char*)&e,sizeof(e));

        cout<<"Enter y to add data for another year:";
        cin>>rep;
        cout<<'\n';
    }
    while(rep == 'y');
    fout.close();
}

void calculate() {
    e.calcpercapita();
    e.calcdiff();
    e.calcfiscal();
}

void report() {
    int ch,yr;
    cout<<"Enter 1 to view record for a particular year or 2 to view records of all the year entered:";
    cin>>ch;
    if(ch == 1) {
        cout<<"Enter the year whose record you want:";
        cin>>yr;
    }
    fstream fout("Economy.dat",ios::binary|ios::in);
    if(!fout) {
        cout<<"Error in opening the file";
    }
    while(fout.read((char*)&e,sizeof(e))) {
        if(ch == 1) {
            if(e.retyear() == yr) {
                e.display();
            }
        }

        else {
            e.display();
        }
    }
    fout.close();
}

void main() {
    Economy e;
    clrscr();
    char rep = 'y';
    while(rep == 'y') {
        int ch;
        cout<<"Enter 1 to view record \n";
        cout<<"Enter 2 to view report \n";
        cin>>ch;
        switch(ch) {
            case 1: create();
                    break;
            case 2:report();
                   break;
            default:cout<<"Invalid input \n";         
        }
        cout<<"If you wish to continue enter y,else anything else:";
        cin>>rep;
        cout<<'\n';
    }
    getch();
}