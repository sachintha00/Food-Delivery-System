#include<iostream>
#include<conio.h>
#include<iomanip>
#include<fstream>
#include<stdlib.h>
#include<windows.h>
#include<string>
#include<ctime>

using namespace std;


int MainMenuH();
void DecorateTopic();
int timeANDdate();
void LoadingBar();


char q=178,g=219,l=201,m=205,r=186,z=187,s=200,t=188,ri=254,n1=177,n2=176,bd1=176,bd2=221;

int location (int x, int y)
{
   COORD sach;
   sach.X=x;
   sach.Y=y;
   SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),sach);
}


class FoodConer
{
public:
    virtual void getdata()=0;
};

class BrekFast : public FoodConer
{
private:
    int BrekfastCode;
    char BrekfastName[20];
    float BrekfastPrice;
public:
    void getdata()
    {
        system("cls");
        BuyBrekfast();
    }
    void addBrekfast();
    void BuyBrekfast();
    void WriteBrekfast();
    void UpdateDetailBrekfast();
    void DeleteDetailBrekfast();
};

void BrekFast :: BuyBrekfast()
{
    system("cls");
    location(2,1);
    timeANDdate();
    BrekFast Bobj;
    int temBid,HmT,i;
    float calc=0,countCalc=0,Bcont;
    int k=13;
    char d[25]="B R E A K F A S T";
    int j;

        location(48,6);
        for(j=0;j<15;j++)
        {
            Sleep(50);
            cout<<bd2;
        }
        cout<<" ";
        for(j=0;j<19;j++)
        {
           Sleep(50);
           cout<<d[j];
        }
       for(j=0;j<15;j++)
        {
           Sleep(50);
           cout<<bd2;
        }

    ifstream inBrekfast;
	inBrekfast.open("Brekfast.dat",ios::binary | ios::in);

	if(!inBrekfast)
    {
        system("cls");
        location(75,27);
        cout<<"Record Not Found....!!!";
        location(168,48);
        cout<<"Press ENTER to return main menu..";
        if(getch()==13)
        {
            MainMenuH();
        }
        else
        {
            MainMenuH();
        }
    }
    else
    {

        location(40,10);
        cout<<"========================================================================================\n";
        location(40,11);
        cout<<"Breakfast No             Breakfast Name                              Breakfast Cost"<<endl;
        location(40,12);
        cout<<"========================================================================================\n";


            while(inBrekfast.read(reinterpret_cast<char *>(&Bobj),sizeof(BrekFast)))
            {
                location(40,k);
                cout<<Bobj.BrekfastCode<<setw(23)<<" "<<Bobj.BrekfastName<<setw(33)<<Bobj.BrekfastPrice<<endl<<endl;
                k+=2;
            }
            inBrekfast.close();
        location(40,k);
        cout<<"========================================================================================\n";

        inBrekfast.open("Brekfast.dat",ios::binary | ios::in);

        cout<<"\n\n\t\t\t\t\t\tEnter the breakfast code you want to buy: ";
        cin>>temBid;
        cout<<"\t\t\t\t\t\tHow many portions: ";
        cin>>Bcont;

        while(inBrekfast.read(reinterpret_cast<char *>(&Bobj),sizeof(BrekFast)))
        {
            if(temBid==Bobj.BrekfastCode)
            {
                calc=+(float)Bcont*(float)Bobj.BrekfastPrice;
            }
        }

        inBrekfast.close();
        cout<<"\n\t\t\t\t\t\tYOUR BILL AMOUNT IS: "<<calc;
        cout<<"\n\n\t\t\t\t\t\tIf you want to buy another breakfast, press <y>..";
        location(168,48);
        cout<<"Press ENTER to return main menu..";
        switch(getch())
        {
        case 'Y':
        case 'y':
            Bobj.BuyBrekfast();
            break;
        case 13:
            system("cls");
            MainMenuH();
            break;
        default:
            system("cls");
            MainMenuH();
            break;
        }
    }
}

void BrekFast :: addBrekfast()
{
    cout<<"\t\t\t\t\t\t Enter The Brekfast Name: ";
    cin>>BrekfastName;
    cout<<"\t\t\t\t\t\t Enter Brekfast Price: ";
    cin>>BrekfastPrice;
}

void BrekFast :: WriteBrekfast()
{
    system("cls");
    location(2,1);
    timeANDdate();
    int BNo,k=13;
    BrekFast Bobj;

        ofstream outFile;
        ifstream inFile;
        outFile.open("Brekfast.dat",ios::binary | ios::out | ios::app);
        inFile.open("Brekfast.dat",ios::binary | ios::in);

        location(40,10);
        cout<<"========================================================================================\n";
        location(40,11);
        cout<<"Breakfast No             Breakfast Name                 Breakfast Cost"<<endl;
        location(40,12);
        cout<<"========================================================================================\n";


            while(inFile.read(reinterpret_cast<char *>(&Bobj),sizeof(BrekFast)))
            {
                location(40,k);
                cout<<Bobj.BrekfastCode<<setw(23)<<" "<<Bobj.BrekfastName<<setw(33)<<Bobj.BrekfastPrice<<endl<<endl;
                k+=2;
            }
            inFile.close();
        location(40,k);
        cout<<"========================================================================================\n";

        inFile.open("Brekfast.dat",ios::binary |ios::in);

        cout<<"\t\t\t\t\t\t Enter The Breakfast Code: ";
        cin>>BNo;

        while(inFile.read(reinterpret_cast<char *>(&Bobj),sizeof(BrekFast)))
        {
            if(BNo==Bobj.BrekfastCode)
            {
                cout<<"\t\t\t\t\t\t Sorry, You can't enter this code";
                getch();
                Bobj.WriteBrekfast();
            }
        }

        Bobj.BrekfastCode=BNo;
        Bobj.addBrekfast();
        cout<<endl<<endl;
        outFile.write(reinterpret_cast<char *> (&Bobj), sizeof(BrekFast));
        outFile.close();

    cout<<"\n\n\t\t\t\t\t\t If you want to order another breakfast, press <y>..";
    location(168,48);
    cout<<"Press ENTER to return main menu..";
    switch (getch())
    {
    case 'y':
    case 'Y':
        Bobj.WriteBrekfast();
        break;
    case 13:
        system("cls");
        MainMenuH();
        break;
    default:
        system("cls");
        MainMenuH();
        break;
    }
}

void BrekFast :: UpdateDetailBrekfast()
{
    system("cls");
    location(2,1);
    timeANDdate();
    BrekFast Bobj;
    int k=13;

    ifstream inBrekfast;
	inBrekfast.open("Brekfast.dat",ios::binary | ios::in);

	if(!inBrekfast)
    {
        system("cls");
        location(75,27);
        cout<<"Record Not Found....!!!";
        location(168,48);
        cout<<"Press ENTER to return main menu..";
        if(getch()==13)
        {
            MainMenuH();
        }
        else
        {
            MainMenuH();
        }
    }
    else
    {

        location(40,10);
        cout<<"========================================================================================\n";
        location(40,11);
        cout<<"Breakfast No             Breakfast Name                 Breakfast Cost"<<endl;
        location(40,12);
        cout<<"========================================================================================\n";


            while(inBrekfast.read(reinterpret_cast<char *>(&Bobj),sizeof(BrekFast)))
            {
                location(40,k);
                cout<<Bobj.BrekfastCode<<setw(23)<<" "<<Bobj.BrekfastName<<setw(33)<<Bobj.BrekfastPrice<<endl<<endl;
                k+=2;
            }
            inBrekfast.close();
        location(40,k);
        cout<<"========================================================================================\n";

        int d;

            cout<<"\n\n\t\t\t\t\t\t Enter breakfast code you want to update: ";
            cin>>d;

            fstream File;
            File.open("Brekfast.dat",ios::binary | ios::in | ios::out | ios::app);
            if(!File)
            {
                cout<<"File Doesn't Found!";
            }
            while(File.read(reinterpret_cast<char *>(&Bobj),sizeof(BrekFast)))
            {
                if(d==Bobj.BrekfastCode)
                {
                    system("cls");
                    location(20,7);
                    cout<<l<<m<<m<<m<<m<<m<<m<<m<<m<<m<<m<<m<<m<<m<<m<<m<<m<<m<<m<<m<<m<<m<<m<<m<<m<<m<<m<<m<<m<<m<<m<<m<<m<<m<<m<<m<<m<<m<<m<<m<<z;
                    location(20,8);
                    cout<<r<<endl;                                              location(60,8);cout<<r;
                    location(20,9);
                    cout<<r<<"Breakfast Code is: "<<Bobj.BrekfastCode<<endl;            location(60,9);cout<<r;
                    location(20,10);
                    cout<<r<<"Breakfast Name is: "<<Bobj.BrekfastName<<endl;            location(60,10);cout<<r;
                    location(20,11);
                    cout<<r<<"Breakfast Price is: "<<Bobj.BrekfastPrice<<endl;            location(60,11);cout<<r;
                    location(20,12);
                    cout<<r<<endl;                                              location(60,12);cout<<r;
                    location(20,13);
                    cout<<s<<m<<m<<m<<m<<m<<m<<m<<m<<m<<m<<m<<m<<m<<m<<m<<m<<m<<m<<m<<m<<m<<m<<m<<m<<m<<m<<m<<m<<m<<m<<m<<m<<m<<m<<m<<m<<m<<m<<m<<t;

                    location(20,14);
                    cout<<"\t\t\t\t\t\t Enter The Breakfast Code: ";
                    cin>>Bobj.BrekfastCode;
                    Bobj.addBrekfast();

                    int pos=(-1)*static_cast<int>(sizeof(Bobj));
                    File.seekp(pos,ios::cur);
                    File.write(reinterpret_cast<char *> (&Bobj),sizeof(BrekFast));
                    cout<<"RECORD UPDATED!"<<endl;
                }

            }
            File.close();

        cout<<"\n\n\t\t\t\t\t\t If you want to update again, press <y>..";
        location(168,48);
        cout<<"Press ENTER to return main menu..";
        switch(getch())
        {
        case 'Y':
        case 'y':
            Bobj.UpdateDetailBrekfast();
            break;
        case 13:
            system("cls");
            MainMenuH();
            break;
        default:
            system("cls");
            MainMenuH();
            break;
        }
    }
}

void BrekFast :: DeleteDetailBrekfast()
{
    int i,j;
    BrekFast Bobj;
    system("cls");
    location(2,1);
    timeANDdate();
    int k=13;
    ifstream inBrekfast;
	inBrekfast.open("Brekfast.dat",ios::binary | ios::in);

	if(!inBrekfast)
    {
        system("cls");
        location(75,27);
        cout<<"Record Not Found....!!!";
        location(168,48);
        cout<<"Press ENTER to return main menu..";
        if(getch()==13)
        {
            MainMenuH();
        }
        else
        {
            MainMenuH();
        }
    }
    else
    {

        location(40,10);
        cout<<"========================================================================================\n";
        location(40,11);
        cout<<"Breakfast No             Brekafast Name                 Breakfast Cost"<<endl;
        location(40,12);
        cout<<"========================================================================================\n";


            while(inBrekfast.read(reinterpret_cast<char *>(&Bobj),sizeof(BrekFast)))
            {
                location(40,k);
                cout<<Bobj.BrekfastCode<<setw(23)<<" "<<Bobj.BrekfastName<<setw(33)<<Bobj.BrekfastPrice<<endl<<endl;
                k+=2;
            }
            inBrekfast.close();
        location(40,k);
        cout<<"========================================================================================\n";

        int BId;

            cout<<"\n\t\t\t\t\t\t Enter the Breakfast code you want to delete: ";
            cin>>BId;
            ifstream inFile;
            inFile.open("Brekfast.dat",ios::binary | ios::in);

            if(!inFile)
            {
                cout<<"File Does Not Found";
                Bobj.DeleteDetailBrekfast();
            }

            ofstream outFile;
            outFile.open("tempBrekfast.dat",ios::binary | ios::out | ios::app);
            inFile.seekg(0,ios::beg);

            while(inFile.read(reinterpret_cast<char *>(&Bobj),sizeof(BrekFast)))
            {
                if(BId!=Bobj.BrekfastCode)
                {
                    outFile.write(reinterpret_cast<char *>(&Bobj),sizeof(BrekFast));
                }
            }

            outFile.close();
            inFile.close();
            remove("Brekfast.dat");
            rename("tempBrekfast.dat","Brekfast.dat");
            cout<<"Record Deleted Successfully!!!!"<<endl<<endl;

        cout<<"\n\n\t\t\t\t\t\t If you want to delete again, press <y>..";
        location(168,48);
        cout<<"Press ENTER to return main menu..";
        switch(getch())
        {
        case 'Y':
        case 'y':
            system("cls");
            Bobj.DeleteDetailBrekfast();
            break;
        case 13:
            system("cls");
            MainMenuH();
            break;
        default:
            system("cls");
            MainMenuH();
            break;
        }
    }
}


class Lunch : public FoodConer
{
private:
    int lunchCode;
    char lunchName[20];
    float lunchPrice;
public:
    void getdata()
    {
        system("cls");
        Buylunch();
    }
    void addlunch();
    void Buylunch();
    void Writelunch();
    void UpdateDetaillunch();
    void DeleteDetaillunch();
};

void Lunch :: Buylunch()
{
    system("cls");
    location(2,1);
    timeANDdate();
    Lunch Lobj;
    int temLid,HmT,i;
    float calc=0,countCalc=0,Lcont;
    int k=13;
    char d[25]="L U N C H";
    int j;

        location(48,6);
        for(j=0;j<15;j++)
        {
            Sleep(50);
            cout<<bd2;
        }
        cout<<" ";
        for(j=0;j<11;j++)
        {
           Sleep(50);
           cout<<d[j];
        }
       for(j=0;j<15;j++)
        {
           Sleep(50);
           cout<<bd2;
        }

    ifstream inlunch;
	inlunch.open("lunch.dat",ios::binary | ios::in);

	if(!inlunch)
    {
        system("cls");
        location(75,27);
        cout<<"Record Not Found....!!!";
        location(168,48);
        cout<<"Press ENTER to return main menu..";
        if(getch()==13)
        {
            MainMenuH();
        }
        else
        {
            MainMenuH();
        }
    }
    else
    {

        location(40,10);
        cout<<"========================================================================================\n";
        location(40,11);
        cout<<"Lunch No                         Lunch Name                                  Lunch Cost"<<endl;
        location(40,12);
        cout<<"========================================================================================\n";


            while(inlunch.read(reinterpret_cast<char *>(&Lobj),sizeof(Lunch)))
            {
                location(40,k);
                cout<<Lobj.lunchCode<<setw(23)<<" "<<Lobj.lunchName<<setw(33)<<Lobj.lunchPrice<<endl<<endl;
                k+=2;
            }
            inlunch.close();
        location(40,k);
        cout<<"========================================================================================\n";

        inlunch.open("lunch.dat",ios::binary | ios::in);

        cout<<"\n\n\t\t\t\t\t\tEnter the lunch code you want to buy: ";
        cin>>temLid;
        cout<<"\t\t\t\t\t\tHow many portions: ";
        cin>>Lcont;
        while(inlunch.read(reinterpret_cast<char *>(&Lobj),sizeof(Lunch)))
        {
            if(temLid==Lobj.lunchCode)
            {
                calc=+(float)Lcont*(float)Lobj.lunchPrice;
            }
        }

        inlunch.close();
        cout<<"\n\t\t\t\t\t\tYOUR BILL AMOUNT IS: "<<calc;
        cout<<"\n\n\t\t\t\t\t\tIf you want to buy another lunch, press <y>...";
        location(168,48);
        cout<<"Press ENTER to return main menu..";
        switch(getch())
        {
        case 'Y':
        case 'y':
            Lobj.Buylunch();
            break;
        case 13:
            system("cls");
            MainMenuH();
            break;
        default:
            system("cls");
            MainMenuH();
            break;
        }
    }
}

void Lunch :: addlunch()
{
    cout<<"\t\t\t\t\t\t Enter The Lunch Name: ";
    cin>>lunchName;
    cout<<"\t\t\t\t\t\t Enter Lunch Price: ";
    cin>>lunchPrice;
}

void Lunch :: Writelunch()
{
    system("cls");
    location(2,1);
    timeANDdate();
    int LNo,k=13;
    Lunch Lobj;

        ofstream outFile;
        ifstream inFile;
        outFile.open("lunch.dat",ios::binary | ios::app);
        inFile.open("lunch.dat",ios::binary | ios::in);

        location(40,10);
        cout<<"========================================================================================\n";
        location(40,11);
        cout<<"Lunch No                         Lunch Name                                  Lunch Cost"<<endl;
        location(40,12);
        cout<<"========================================================================================\n";


            while(inFile.read(reinterpret_cast<char *>(&Lobj),sizeof(Lunch)))
            {
                location(40,k);
                cout<<Lobj.lunchCode<<setw(23)<<" "<<Lobj.lunchName<<setw(33)<<Lobj.lunchPrice<<endl<<endl;
                k+=2;
            }
            inFile.close();
        location(40,k);
        cout<<"========================================================================================\n";

        inFile.open("lunch.dat",ios::binary | ios::in);

        cout<<"\t\t\t\t\t\t Enter The Lunch Code: ";
        cin>>LNo;

        while(inFile.read(reinterpret_cast<char *>(&Lobj),sizeof(Lunch)))
        {
            if(LNo==Lobj.lunchCode)
            {
                cout<<"Sorry!!! You cant Enter This Code";
                getch();
                Lobj.Writelunch();
            }
        }

        Lobj.lunchCode=LNo;
        Lobj.addlunch();
        cout<<endl<<endl;
        outFile.write(reinterpret_cast<char *> (&Lobj), sizeof(Lunch));
        outFile.close();

    cout<<"\n\n\t\t\t\t\t\t If you want to add another lunch the you press <y>..";
    location(168,48);
    cout<<"Press ENTER to return main menu..";
    switch (getch())
    {
    case 'y':
    case 'Y':
        Lobj.Writelunch();
        break;
    case 13:
        system("cls");
        MainMenuH();
        break;
    default:
        system("cls");
        MainMenuH();
        break;
    }
}

void Lunch :: UpdateDetaillunch()
{
    system("cls");
    location(2,1);
    timeANDdate();
    Lunch Lobj;
    int k=13;
    ifstream inlunch;
	inlunch.open("lunch.dat",ios::binary | ios::in);

	if(!inlunch)
    {
        system("cls");
        location(75,27);
        cout<<"Record Not Found....!!!";
        location(168,48);
        cout<<"Press ENTER to return main menu..";
        if(getch()==13)
        {
            MainMenuH();
        }
        else
        {
            MainMenuH();
        }
    }
    else
    {

        location(40,10);
        cout<<"========================================================================================\n";
        location(40,11);
        cout<<"Lunch No                         Lunch Name                                  Lunch Cost"<<endl;
        location(40,12);
        cout<<"========================================================================================\n";


            while(inlunch.read(reinterpret_cast<char *>(&Lobj),sizeof(Lunch)))
            {
                location(40,k);
                cout<<Lobj.lunchCode<<setw(23)<<" "<<Lobj.lunchName<<setw(33)<<Lobj.lunchPrice<<endl<<endl;
                k+=2;
            }
            inlunch.close();
        location(40,k);
        cout<<"========================================================================================\n";

        int d;

            cout<<"\n\n\t\t\t\t\t\t Enter lunch number you want to update: ";
            cin>>d;

            fstream File;
            File.open("Brekfast.dat",ios::binary | ios::in | ios::out | ios::app);
            if(!File)
            {
                cout<<"File Doesn't Found !!!";
            }
            while(File.read(reinterpret_cast<char *>(&Lobj),sizeof(Lunch)))
            {
                if(d==Lobj.lunchCode)
                {
                    system("cls");
                    location(20,7);
                    cout<<l<<m<<m<<m<<m<<m<<m<<m<<m<<m<<m<<m<<m<<m<<m<<m<<m<<m<<m<<m<<m<<m<<m<<m<<m<<m<<m<<m<<m<<m<<m<<m<<m<<m<<m<<m<<m<<m<<m<<m<<z;
                    location(20,8);
                    cout<<r<<endl;                                              location(60,8);cout<<r;
                    location(20,9);
                    cout<<r<<"The Lunch Code is: "<<Lobj.lunchCode<<endl;            location(60,9);cout<<r;
                    location(20,10);
                    cout<<r<<"The Lunch Name is: "<<Lobj.lunchName<<endl;            location(60,10);cout<<r;
                    location(20,11);
                    cout<<r<<"The Lunch Prize is: "<<Lobj.lunchPrice<<endl;            location(60,11);cout<<r;
                    location(20,12);
                    cout<<r<<endl;                                              location(60,12);cout<<r;
                    location(20,13);
                    cout<<s<<m<<m<<m<<m<<m<<m<<m<<m<<m<<m<<m<<m<<m<<m<<m<<m<<m<<m<<m<<m<<m<<m<<m<<m<<m<<m<<m<<m<<m<<m<<m<<m<<m<<m<<m<<m<<m<<m<<m<<t;

                    location(20,14);
                    cout<<"\t\t\t\t\t\t Enter The Lunch Code: ";
                    cin>>Lobj.lunchCode;
                    Lobj.addlunch();

                    int pos=(-1)*static_cast<int>(sizeof(Lobj));
                    File.seekp(pos,ios::cur);
                    File.write(reinterpret_cast<char *> (&Lobj),sizeof(Lunch));
                    cout<<"RECORD UPDATED SUCESSFULY!!!!"<<endl;
                }

            }
            File.close();

        cout<<"\n\n\t\t\t\t\t\t You Want To Update Again then press <y>..";
        location(168,48);
        cout<<"Press ENTER to return main menu..";
        switch(getch())
        {
        case 'Y':
        case 'y':
            Lobj.UpdateDetaillunch();
            break;
        case 13:
            system("cls");
            MainMenuH();
            break;
        default:
            system("cls");
            MainMenuH();
            break;
        }
    }
}

void Lunch :: DeleteDetaillunch()
{

    Lunch Lobj;
    system("cls");
    location(2,1);
    timeANDdate();
    int k=13;

    ifstream inlunch;
	inlunch.open("lunch.dat",ios::binary | ios::in);

	if(!inlunch)
    {
        system("cls");
        location(75,27);
        cout<<"Record Not Found....!!!";
        location(168,48);
        cout<<"Press ENTER to return main menu..";
        if(getch()==13)
        {
            MainMenuH();
        }
        else
        {
            MainMenuH();
        }
    }
    else
    {

        location(40,10);
        cout<<"========================================================================================\n";
        location(40,11);
        cout<<"Lunch No                         Lunch Name                                  Lunch Cost"<<endl;
        location(40,12);
        cout<<"========================================================================================\n";


            while(inlunch.read(reinterpret_cast<char *>(&Lobj),sizeof(Lunch)))
            {
                location(40,k);
                cout<<Lobj.lunchCode<<setw(23)<<" "<<Lobj.lunchName<<setw(33)<<Lobj.lunchPrice<<endl<<endl;
                k+=2;
            }
            inlunch.close();
        location(40,k);
        cout<<"========================================================================================\n";


        int LId;

            cout<<"\n\t\t\t\t\t\t Enter the Lunch Code You want to Delete: ";
            cin>>LId;
            ifstream inFile;
            inFile.open("lunch.dat",ios::binary | ios::in);

            if(!inFile)
            {
                cout<<"File Does Not Found";
                Lobj.DeleteDetaillunch();
            }

            ofstream outFile;
            outFile.open("templunch.dat",ios::binary | ios::out | ios::app);
            inFile.seekg(0,ios::beg);

            while(inFile.read(reinterpret_cast<char *>(&Lobj),sizeof(Lunch)))
            {
                if(LId!=Lobj.lunchCode)
                {
                    outFile.write(reinterpret_cast<char *>(&Lobj),sizeof(Lunch));
                }
            }

            outFile.close();
            inFile.close();
            remove("lunch.dat");
            rename("templunch.dat","lunch.dat");
            cout<<"Record Deleted Successfully!!!!"<<endl<<endl;

        cout<<"\n\n\t\t\t\t\t\t You Want To Delete Again then press <y>..";
        location(168,48);
        cout<<"Press ENTER to return main menu..";
        switch(getch())
        {
        case 'Y':
        case 'y':
            system("cls");
            Lobj.DeleteDetaillunch();
            break;
        case 13:
            system("cls");
            MainMenuH();
            break;
        default:
            system("cls");
            MainMenuH();
            break;
        }
    }
}


class Dinner : public FoodConer
{
private:
    int dinnerCode;
    char dinnerName[20];
    float dinnerPrice;
public:
    void getdata()
    {
        system("cls");
        Buydinner();
    }
    void adddinner();
    void Buydinner();
    void Writedinner();
    void UpdateDetaildinner();
    void DeleteDetaildinner();
};

void Dinner :: Buydinner()
{
    system("cls");
    location(2,1);
    timeANDdate();
    Dinner Dobj;
    int temDid,HmT,i;
    float calc=0,countCalc=0,Dcont;
    int k=13;
    char d[25]="D I N N E R";
    int j;

        location(48,6);
        for(j=0;j<15;j++)
        {
            Sleep(50);
            cout<<bd2;
        }
        cout<<" ";
        for(j=0;j<13;j++)
        {
           Sleep(50);
           cout<<d[j];
        }
       for(j=0;j<15;j++)
        {
           Sleep(50);
           cout<<bd2;
        }

    ifstream indinner;
	indinner.open("dinner.dat",ios::binary | ios::in);

	if(!indinner)
    {
        system("cls");
        location(75,27);
        cout<<"Record Not Found....!!!";
        location(168,48);
        cout<<"Press ENTER to return main menu..";
        if(getch()==13)
        {
            MainMenuH();
        }
        else
        {
            MainMenuH();
        }
    }
    else
    {

        location(40,10);
        cout<<"========================================================================================\n";
        location(40,11);
        cout<<"Dinner No                        Dinner Name                             Dinner Cost"<<endl;
        location(40,12);
        cout<<"========================================================================================\n";


            while(indinner.read(reinterpret_cast<char *>(&Dobj),sizeof(Dinner)))
            {
                location(40,k);
                cout<<Dobj.dinnerCode<<setw(25)<<" "<<Dobj.dinnerName<<setw(33)<<Dobj.dinnerPrice<<endl<<endl;
                k+=2;
            }
            indinner.close();
        location(40,k);
        cout<<"========================================================================================\n";

        indinner.open("dinner.dat",ios::binary | ios::in);

        cout<<"\n\n\t\t\t\t\t\tEnter the dinner code you want to buy: ";
        cin>>temDid;
        cout<<"\t\t\t\t\t\tHow many portions: ";
        cin>>Dcont;
        while(indinner.read(reinterpret_cast<char *>(&Dobj),sizeof(Dinner)))
        {
            if(temDid==Dobj.dinnerCode)
            {
                calc=+(float)Dcont*(float)Dobj.dinnerPrice;
            }
        }

        indinner.close();
        cout<<"\n\t\t\t\t\t\tYOUR BILL AMOUNT IS: "<<calc;
        cout<<"\n\n\t\t\t\t\t\tIf You Want To add another Dinner the you press <y>..";
        location(168,48);
        cout<<"Press ENTER to return main menu..";
        switch(getch())
        {
        case 'Y':
        case 'y':
            Dobj.Buydinner();
            break;
        case 13:
            system("cls");
            MainMenuH();
            break;
        default:
            system("cls");
            MainMenuH();
            break;
        }
    }
}

void Dinner :: adddinner()
{
    cout<<"\t\t\t\t\t\t Enter The Dinner Name: ";
    cin>>dinnerName;
    cout<<"\t\t\t\t\t\t Enter Dinner Price: ";
    cin>>dinnerPrice;
}

void Dinner :: Writedinner()
{
    system("cls");
    location(2,1);
    timeANDdate();
    int DNo,k=13;
    Dinner Dobj;

        ofstream outFile;
        ifstream inFile;
        outFile.open("dinner.dat",ios::binary | ios::out | ios::app);
        inFile.open("dinner.dat",ios::binary | ios::in);

        location(40,10);
        cout<<"========================================================================================\n";
        location(40,11);
        cout<<"Dinner No                        Dinner Name                             Dinner Cost"<<endl;
        location(40,12);
        cout<<"========================================================================================\n";


            while(inFile.read(reinterpret_cast<char *>(&Dobj),sizeof(Dinner)))
            {
                location(40,k);
                cout<<Dobj.dinnerCode<<setw(25)<<" "<<Dobj.dinnerName<<setw(33)<<Dobj.dinnerPrice<<endl<<endl;
                k+=2;
            }
            inFile.close();
        location(40,k);
        cout<<"========================================================================================\n";

        inFile.open("dinner.dat",ios::binary | ios::in);

        cout<<"\t\t\t\t\t\t Enter Dinner Code: ";
        cin>>DNo;

        while(inFile.read(reinterpret_cast<char *>(&Dobj),sizeof(Dinner)))
        {
            if(DNo==Dobj.dinnerCode)
            {
                cout<<"Sorry! You can't Enter This Code";
                getch();
                Dobj.Writedinner();
            }
        }

        Dobj.dinnerCode=DNo;
        Dobj.adddinner();
        cout<<endl<<endl;
        outFile.write(reinterpret_cast<char *> (&Dobj), sizeof(Dinner));
        outFile.close();

    cout<<"\n\n\t\t\t\t\t\tIf you want to add another Dinner, Press <y>..";
    location(168,48);
    cout<<"Press ENTER to return main menu..";
    switch (getch())
    {
    case 'y':
    case 'Y':
        Dobj.Writedinner();
        break;
    case 13:
        system("cls");
        MainMenuH();
        break;
    default:
        system("cls");
        MainMenuH();
        break;
    }
}

void Dinner :: UpdateDetaildinner()
{
    system("cls");
    location(2,1);
    timeANDdate();
    Dinner Dobj;
    int k=13;

    ifstream indinner;
	indinner.open("dinner.dat",ios::binary | ios::in);

	if(!indinner)
    {
        system("cls");
        location(75,27);
        cout<<"Record Not Found....!!!";
        location(168,48);
        cout<<"Press ENTER to return main menu..";
        if(getch()==13)
        {
            MainMenuH();
        }
        else
        {
            MainMenuH();
        }
    }
    else
    {

        location(40,10);
        cout<<"========================================================================================\n";
        location(40,11);
        cout<<"Dinner No                        Dinner Name                             Dinner Cost"<<endl;
        location(40,12);
        cout<<"========================================================================================\n";


            while(indinner.read(reinterpret_cast<char *>(&Dobj),sizeof(Dinner)))
            {
                location(40,k);
                cout<<Dobj.dinnerCode<<setw(25)<<" "<<Dobj.dinnerName<<setw(33)<<Dobj.dinnerPrice<<endl<<endl;
                k+=2;
            }
            indinner.close();
        location(40,k);
        cout<<"========================================================================================\n";

        int d;

            cout<<"\n\n\t\t\t\t\t\t Enter the Dinner Number you want to update: ";
            cin>>d;

            fstream File;
            File.open("dinner.dat",ios::binary | ios::in | ios::out | ios::app);
            if(!File)
            {
                cout<<"File Doesn't Found!";
            }
            while(File.read(reinterpret_cast<char *>(&Dobj),sizeof(Dinner)))
            {
                if(d==Dobj.dinnerCode)
                {
                    system("cls");
                    location(20,7);
                    cout<<l<<m<<m<<m<<m<<m<<m<<m<<m<<m<<m<<m<<m<<m<<m<<m<<m<<m<<m<<m<<m<<m<<m<<m<<m<<m<<m<<m<<m<<m<<m<<m<<m<<m<<m<<m<<m<<m<<m<<m<<z;
                    location(20,8);
                    cout<<r<<endl;                                              location(60,8);cout<<r;
                    location(20,9);
                    cout<<r<<"The Dinner Code is: "<<Dobj.dinnerCode<<endl;            location(60,9);cout<<r;
                    location(20,10);
                    cout<<r<<"The Dinner Name is: "<<Dobj.dinnerName<<endl;            location(60,10);cout<<r;
                    location(20,11);
                    cout<<r<<"The Dinner Price is: "<<Dobj.dinnerPrice<<endl;            location(60,11);cout<<r;
                    location(20,12);
                    cout<<r<<endl;                                              location(60,12);cout<<r;
                    location(20,13);
                    cout<<s<<m<<m<<m<<m<<m<<m<<m<<m<<m<<m<<m<<m<<m<<m<<m<<m<<m<<m<<m<<m<<m<<m<<m<<m<<m<<m<<m<<m<<m<<m<<m<<m<<m<<m<<m<<m<<m<<m<<m<<t;

                    location(20,14);
                    cout<<"Enter The Dinner Code: ";
                    cin>>Dobj.dinnerCode;
                    Dobj.adddinner();

                    int pos=(-1)*static_cast<int>(sizeof(Dobj));
                    File.seekp(pos,ios::cur);
                    File.write(reinterpret_cast<char *> (&Dobj),sizeof(Dinner));
                    cout<<"RECORD UPDATED SUCCESSFULLY!"<<endl;
                }

            }
            File.close();

        cout<<"\n\n\t\t\t\t\t\t If you want to update again, press <y>..";
        location(168,48);
        cout<<"Press ENTER to return main menu..";
        switch(getch())
        {
        case 'Y':
        case 'y':
            Dobj.UpdateDetaildinner();
            break;
        case 13:
            system("cls");
            MainMenuH();
            break;
        default:
            system("cls");
            MainMenuH();
            break;
        }
    }
}

void Dinner :: DeleteDetaildinner()
{
    Dinner Dobj;
    system("cls");
    location(2,1);
    timeANDdate();
    int k=13;

    ifstream indinner;
	indinner.open("dinner.dat",ios::binary | ios::in);

	if(!indinner)
    {
        system("cls");
        location(75,27);
        cout<<"Record Not Found....!!!";
        location(168,48);
        cout<<"Press ENTER to return main menu..";
        if(getch()==13)
        {
            MainMenuH();
        }
        else
        {
            MainMenuH();
        }
    }
    else
    {

        location(40,10);
        cout<<"========================================================================================\n";
        location(40,11);
        cout<<"Dinner No             Dinner Name                 Dinner Cost"<<endl;
        location(40,12);
        cout<<"========================================================================================\n";


            while(indinner.read(reinterpret_cast<char *>(&Dobj),sizeof(Dinner)))
            {
                location(40,k);
                cout<<Dobj.dinnerCode<<setw(25)<<" "<<Dobj.dinnerName<<setw(33)<<Dobj.dinnerPrice<<endl<<endl;
                k+=2;
            }
            indinner.close();
        location(40,k);
        cout<<"========================================================================================\n";


        int DId;

            cout<<"\n\t\t\t\t\t\t Enter the Dinner Code you want to Delete: ";
            cin>>DId;
            ifstream inFile;
            inFile.open("dinner.dat",ios::binary | ios::in);

            if(!inFile)
            {
                cout<<"File Does Not Found";
                Dobj.DeleteDetaildinner();
            }

            ofstream outFile;
            outFile.open("tempdinner.dat",ios::binary | ios::out | ios::app);
            inFile.seekg(0,ios::beg);

            while(inFile.read(reinterpret_cast<char *>(&Dobj),sizeof(Dinner)))
            {
                if(DId!=Dobj.dinnerCode)
                {
                    outFile.write(reinterpret_cast<char *>(&Dobj),sizeof(Dinner));
                }
            }

            outFile.close();
            inFile.close();
            remove("dinner.dat");
            rename("tempdinner.dat","dinner.dat");
            cout<<"Record Deleted Successfully!!!!"<<endl<<endl;

        cout<<"\n\n\t\t\t\t\t\t If you want to delete again, Press <y>..";
        location(168,48);
        cout<<"Press ENTER to return main menu..";
        switch(getch())
        {
        case 'Y':
        case 'y':
            system("cls");
            Dobj.DeleteDetaildinner();
            break;
        case 13:
            system("cls");
            MainMenuH();
            break;
        default:
            system("cls");
            MainMenuH();
            break;
        }
    }
}

void WhatIsTheFunction(FoodConer*p)
{
    p->getdata();
}

void FoodConerMain()
{
    system("cls");

    FoodConer *f;

    BrekFast bfast;
    Lunch lunch;
    Dinner dinner;

    DecorateTopic();
    location(2,1);
    timeANDdate();

    location(75,27);
    cout<<ri<<ri<<ri<<ri<<ri<<ri<<ri<<ri<<ri<<ri<<" FOOD SECTION "<<ri<<ri<<ri<<ri<<ri<<ri<<ri<<ri<<ri<<ri<<ri;
    location(75,29);
    cout<<"...................................";

    location(75,31);
    cout<<g<<g<<q<<" 1.BREAKFAST "<<endl;
    location(75,33);
    cout<<g<<g<<q<<" 2.LUNCH "<<endl;
    location(75,35);
    cout<<g<<g<<q<<" 3.DINNER "<<endl;
    location(75,37);
    cout<<g<<g<<q<<" 4.BACK TO MAIN MENU"<<endl;

    location(75,39);
    cout<<"...................................";
    location(75,41);
    cout<<ri<<ri<<ri<<ri<<ri<<ri<<ri<<ri<<ri<<ri<<ri<<ri<<ri<<ri<<ri<<ri<<ri<<ri<<ri<<ri<<ri<<ri<<ri<<ri<<ri<<ri<<ri<<ri<<ri<<ri<<ri<<ri<<ri<<ri<<ri;

    location(75,43);
    cout<<"What is you choice?: ";
    switch (getch())
    {
        case '1':
            WhatIsTheFunction(&bfast);
            break;
        case '2':
            WhatIsTheFunction(&lunch);
            break;
        case '3':
            WhatIsTheFunction(&dinner);
            break;
        case '4':
            system("cls");
            MainMenuH();
            break;
        default:
            system("cls");
            FoodConerMain();
            break;
    }
}

void administration()
{
     system("cls");

    BrekFast Bobj;
    Lunch Lobj;
    Dinner Dobj;

    DecorateTopic();
    location(2,1);
    timeANDdate();

    location(75,28);
    cout<<n1<<n1<<n1<<n1<<n1<<n1<<n1<<n1<<n1<<n1<<n1<<n1<<" FOOD SERVICE "<<n1<<n1<<n1<<n1<<n1<<n1<<n1<<n1<<n1<<n1<<n1<<n1<<endl;
    location(75,30);
    cout<<n1<<n2<<n2<<" 1.BREAK FAST DETAILS"<<endl;
    location(75,32);
    cout<<n1<<n2<<n2<<" 2.LUNCH DETAILS"<<endl;
    location(75,34);
    cout<<n1<<n2<<n2<<" 3.DINNER DETAILS"<<endl;
    location(75,36);
    cout<<n1<<n2<<n2<<" 4.BACK TO SERVICE CENTER"<<endl;
    location(75,38);
    cout<<n1<<n2<<n2<<" 5.BACK TO MAIN MENU"<<endl;
    location(75,40);
    cout<<n1<<n1<<n1<<n1<<n1<<n1<<n1<<n1<<n1<<n1<<n1<<n1<<n1<<n1<<n1<<n1<<n1<<n1<<n1<<n1<<n1<<n1<<n1<<n1<<n1<<n1<<n1<<n1<<n1<<n1<<n1<<n1<<n1<<n1<<n1<<n1<<n1<<n1<<n1<<endl;

    location(75,42);
	cout<<"Enter your choice: ";

    switch(getch())
    {

    case '1':
        system("cls");
        DecorateTopic();
        location(2,1);
        timeANDdate();
        location(75,28);
        cout<<n1<<n1<<n1<<n1<<n1<<n1<<n1<<n1<<n1<<n1<<n1<<n1<<" BREAKFAST SERVICE "<<n1<<n1<<n1<<n1<<n1<<n1<<n1<<n1<<n1<<n1<<n1<<n1<<endl;
        location(75,30);
        cout<<n1<<n2<<n2<<" 1.ADD DETAIL"<<endl;
        location(75,32);
        cout<<n1<<n2<<n2<<" 2.UPDATE DETAIL"<<endl;
        location(75,34);
        cout<<n1<<n2<<n2<<" 3.DELETE DETAILS"<<endl;
        location(75,36);
        cout<<n1<<n2<<n2<<" 4.BACK TO FOOD DETAIL MENU"<<endl;
        location(75,38);
        cout<<n1<<n2<<n2<<" 5.BACK TO MAIN MENU"<<endl;
        location(75,40);
        cout<<n1<<n1<<n1<<n1<<n1<<n1<<n1<<n1<<n1<<n1<<n1<<n1<<n1<<n1<<n1<<n1<<n1<<n1<<n1<<n1<<n1<<n1<<n1<<n1<<n1<<n1<<n1<<n1<<n1<<n1<<n1<<n1<<n1<<n1<<n1<<n1<<n1<<n1<<n1<<endl;
        location(75,42);
        cout<<"Enter your choice: ";

        switch(getch())
        {
        case '1':
            Bobj.WriteBrekfast();
            break;
        case '2':
            Bobj.UpdateDetailBrekfast();
            break;
        case '3':
            Bobj.DeleteDetailBrekfast();
            break;
        case '4':
            administration();
            break;
        case '5':
            MainMenuH();
            break;
        default:
            administration();
            break;
        }

    case '2':
        system("cls");
        DecorateTopic();
        location(2,1);
        timeANDdate();
        location(75,28);
        cout<<n1<<n1<<n1<<n1<<n1<<n1<<n1<<n1<<n1<<n1<<n1<<n1<<" LUNCH SERVICE "<<n1<<n1<<n1<<n1<<n1<<n1<<n1<<n1<<n1<<n1<<n1<<n1<<endl;
        location(75,30);
        cout<<n1<<n2<<n2<<" 1.ADD DETAIL"<<endl;
        location(75,32);
        cout<<n1<<n2<<n2<<" 2.UPDATE DETAIL"<<endl;
        location(75,34);
        cout<<n1<<n2<<n2<<" 3.DELETE DETAILS"<<endl;
        location(75,36);
        cout<<n1<<n2<<n2<<" 4.BACK TO FOOD DETAIL MENU"<<endl;
        location(75,38);
        cout<<n1<<n2<<n2<<" 5.BACK TO MAIN MENU"<<endl;
        location(75,40);
        cout<<n1<<n1<<n1<<n1<<n1<<n1<<n1<<n1<<n1<<n1<<n1<<n1<<n1<<n1<<n1<<n1<<n1<<n1<<n1<<n1<<n1<<n1<<n1<<n1<<n1<<n1<<n1<<n1<<n1<<n1<<n1<<n1<<n1<<n1<<n1<<n1<<n1<<n1<<n1<<endl;
        location(75,42);
        cout<<"Enter your choice: ";

        switch(getch())
        {
        case '1':
            Lobj.Writelunch();
            break;
        case '2':
            Lobj.UpdateDetaillunch();
            break;
        case '3':
            Lobj.DeleteDetaillunch();
            break;
        case '4':
            administration();
            break;
        case '5':
            MainMenuH();
            break;
        default:
            administration();
            break;
        }

    case '3':
        system("cls");
        DecorateTopic();
        location(2,1);
        timeANDdate();
        location(75,28);
        cout<<n1<<n1<<n1<<n1<<n1<<n1<<n1<<n1<<n1<<n1<<n1<<n1<<" DINNER SERVICE "<<n1<<n1<<n1<<n1<<n1<<n1<<n1<<n1<<n1<<n1<<n1<<n1<<endl;
        location(75,30);
        cout<<n1<<n2<<n2<<" 1.ADD DETAIL"<<endl;
        location(75,32);
        cout<<n1<<n2<<n2<<" 2.UPDATE DETAIL"<<endl;
        location(75,34);
        cout<<n1<<n2<<n2<<" 3.DELETE DETAILS"<<endl;
        location(75,36);
        cout<<n1<<n2<<n2<<" 4.BACK TO FOOD DETAIL MENU"<<endl;
        location(75,38);
        cout<<n1<<n2<<n2<<" 5.BACK TO MAIN MENU"<<endl;
        location(75,40);
        cout<<n1<<n1<<n1<<n1<<n1<<n1<<n1<<n1<<n1<<n1<<n1<<n1<<n1<<n1<<n1<<n1<<n1<<n1<<n1<<n1<<n1<<n1<<n1<<n1<<n1<<n1<<n1<<n1<<n1<<n1<<n1<<n1<<n1<<n1<<n1<<n1<<n1<<n1<<n1<<endl;
        location(75,42);
        cout<<"Enter your choice: ";

        switch(getch())
        {
        case '1':
            Dobj.Writedinner();
            break;
        case '2':
            Dobj.UpdateDetaildinner();
            break;
        case '3':
            Dobj.DeleteDetaildinner();
            break;
        case '4':
            administration();
            break;
        case '5':
            MainMenuH();
            break;
        default:
            administration();
            break;
        }

        case '4':
            administration();
            break;
        case '5':
            MainMenuH();
            break;
        default:
            MainMenuH();
            break;
    }
}

int MainMenuH()
{
    system("color 46");
    DecorateTopic();
    location(2,1);
    timeANDdate();
    Sleep(500);

    location(75,27);
    cout<<q<<q<<q<<q<<q<<q<<q<<q<<q<<q<<q<<q<<q<<q<<q<<q<<" MAIN MENU " <<q<<q<<q<<q<<q<<q<<q<<q<<q<<q<<q<<q<<q<<q<<q<<q;
    location(75,29);
    cout<<g<<g<<g<<g<<q<<" 1. ADMINISTRSTION SECTION   ";
    location(75,31);
    cout<<g<<g<<g<<g<<q<<" 2. CUSTOMER SECTION";
    location(75,33);
    cout<<g<<g<<g<<g<<q<<" 3. ABOUT US";
    location(75,35);
    cout<<g<<g<<g<<g<<q<<" 0. EXIT";
    location(75,37);
    cout<<q<<q<<q<<q<<q<<q<<q<<q<<q<<q<<q<<q<<q<<q<<q<<q<<q<<q<<q<<q<<q<<q<<q<<q<<q<<q<<q<<q<<q<<q<<q<<q<<q<<q<<q<<q<<q<<q<<q<<q<<q<<q<<q;
    location(75,39);
	cout<<"Enter your choice: ";

	switch(getch())
        {
            case '1':
                system("color 46");
                administration();
                break;
			case '2':
			    system("color 46");
			    FoodConerMain();
			    break;
            case '0':
                system("cls");
                system("color 46");
                location(23,7);
                cout<<"Are You sure!!!!\n\t\t\t\tThen Press (y) or (n)...";
                if(getch()=='y' | getch()=='Y')
                {
                    system("cls");
                    location(20,6);
                    cout<<"PROGRAMMER....";
                    location(20,9);
                    cout<<"1. Sachintha Madhawa     MA-DSE-192-F-011";
                    Sleep(1000);
                    location(20,10);
                    cout<<"   Mobile: +940701871192     E-mail: dsema192f011@student.nibm.lk";
                    location(50,22);
                    Sleep(1000);
                    cout<<"...................THANK YOU...................";
                    location(50,23);
                    cout<<"Exiting in 5 second...........";
                    Sleep(5000);
                    system("cls");
                    exit(0);
                }
                else
                {
                    MainMenuH();
                    system("cls");
                }

			default :
			    system("cls");
			    location(20,5);
                cout<<"\aWrong Entry!!\n\n\t\t\tPlease re-entered correct option";
                getch();
                system("cls");
                MainMenuH();
                break;
		}
}

void DecorateTopic()
{
    system("cls");
    cout<<endl;
    cout<<"\t\t\t       @@@@@@@@@@@@@  @@@@@@@   @@@@@@@   @@@@@@@@@@@               @@@@@@@@@@@   @@@@@@@@@@  @@        @@@@@@@@@@  @@                 @@ @@@@@@@@@@ @@@@@@@@@@               "<<endl;
    cout<<"\t\t\t       @@            @@@@@@@@@ @@@@@@@@@  @@@@@@@@@@@@              @@@@@@@@@@@@  @@@@@@@@@@  @@            @@       @@               @@  @@@@@@@@@@ @@@@@@@@@@@               "<<endl;
    cout<<"\t\t\t       @@            @@     @@ @@     @@  @@         @@             @@         @@ @@          @@            @@        @@             @@   @@         @@        @@      "<<endl;
    cout<<"\t\t\t       @@            @@     @@ @@     @@  @@         @@             @@         @@ @@          @@            @@         @@           @@    @@         @@        @@       "<<endl;
    cout<<"\t\t\t       @@@@@@@@@@    @@     @@ @@     @@  @@         @@             @@         @@ @@@@@@@     @@            @@          @@         @@     @@@@@@@    @@        @@       "<<endl;
    cout<<"\t\t\t       @@            @@     @@ @@     @@  @@         @@             @@         @@ @@@@@@@     @@            @@           @@       @@      @@@@@@@    @@       @@        "<<endl;
    cout<<"\t\t\t       @@            @@     @@ @@     @@  @@         @@             @@         @@ @@          @@            @@            @@     @@       @@         @@@@@@@@@             "<<endl;
    cout<<"\t\t\t       @@            @@     @@ @@     @@  @@         @@             @@         @@ @@          @@            @@             @@   @@        @@         @@     @@              "<<endl;
    cout<<"\t\t\t       @@            @@@@@@@@@ @@@@@@@@@  @@@@@@@@@@@@              @@@@@@@@@@@@  @@@@@@@@@@  @@@@@@@@@@    @@              @@ @@         @@@@@@@@@@ @@      @@           "<<endl;
    cout<<"\t\t\t       @@             @@@@@@@   @@@@@@@   @@@@@@@@@@@               @@@@@@@@@@@   @@@@@@@@@@  @@@@@@@@@@ @@@@@@@@@@          @@@          @@@@@@@@@@ @@       @@        "<<endl;
    cout<<"\t\t\t============================================================================================================================================================="<<endl;
    cout<<endl;
    cout<<"\t\t\t\t                          @@@@@@@@@  @@      @@   @@@@@@@@@  @@@@@@@@@@  @@@@@@@@@@  @@               @@"<<endl;
    cout<<"\t\t\t\t                         @@@@@@@@@@  @@      @@  @@@@@@@@@@  @@@@@@@@@@  @@@@@@@@@@  @@@             @@@"<<endl;
    cout<<"\t\t\t\t                         @@           @@    @@   @@              @@      @@          @@@@           @@@@"<<endl;
    cout<<"\t\t\t\t                         @@            @@  @@    @@              @@      @@          @@ @@         @@ @@"<<endl;
    cout<<"\t\t\t\t                         @@@@@@@@@      @@@@     @@@@@@@@@       @@      @@@@@@@     @@  @@       @@  @@"<<endl;
    cout<<"\t\t\t\t                          @@@@@@@@@      @@       @@@@@@@@@      @@      @@@@@@@     @@   @@     @@   @@"<<endl;
    cout<<"\t\t\t\t                                 @@      @@              @@      @@      @@          @@    @@   @@    @@"<<endl;
    cout<<"\t\t\t\t                                 @@      @@              @@      @@      @@          @@     @@ @@     @@"<<endl;
    cout<<"\t\t\t\t                         @@@@@@@@@@      @@      @@@@@@@@@@      @@      @@@@@@@@@@  @@      @@@      @@"<<endl;
    cout<<"\t\t\t\t                         @@@@@@@@@       @@      @@@@@@@@@       @@      @@@@@@@@@@  @@               @@"<<endl;
    cout<<"\t\t\t\t ==========================================================================================================================================================="<<endl;
    cout<<endl;
}

int timeANDdate()
{
    time_t t;
    t=time(NULL);
    cout<<asctime(localtime(&t));
}

void LoadingBar()
{
    system("color 46");
    location(2,1);
    timeANDdate();
    char des=219;
    location(80,21);
    cout<<"loading...";
    for(int j=0;j<=100;j++)
    {
        //system("cls");
        location(115,22);
        cout<<j<<"%"<<endl;
        location(0,21);

        cout<<"\n\t\t\t\t\t\t\t\t\t\t";
        for(int i=1;i<=j;i++)
        {

            if(i%3==0)
            {
                cout<<des;
            }
        }
        cout<<endl;
        Sleep(30);
    }
    Sleep(1000);
}

int main()
{
    LoadingBar();
    MainMenuH();
}
