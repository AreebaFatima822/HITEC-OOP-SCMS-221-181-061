#include<iostream>
using namespace std;
class FeeRecord
{
    protected:
    string StudentRef;
    float SemesterFee;
    float HostelFee;
    float LibraryFine;
    float Totalpaid;
    float Balance;
    public:
    FeeRecord(string a=" ",float b=0,float c=0,float d=0,float e=0)
    {
        StudentRef =a;
        SemesterFee =b;
        HostelFee =c;
        LibraryFine =d;
        Totalpaid =e;
        Balance =SemesterFee + HostelFee + LibraryFine;
    }
    FeeRecord(const FeeRecord &F)
    {
        StudentRef =F.StudentRef;
        SemesterFee =F.SemesterFee;
        HostelFee =F.HostelFee;
        LibraryFine =F.LibraryFine;
        Totalpaid =F.Totalpaid;
        Balance =F.Balance;
    }
     FeeRecord &operator=(const FeeRecord &F)
    {
        StudentRef =F.StudentRef;
        SemesterFee =F.SemesterFee;
        HostelFee =F.HostelFee;
        LibraryFine =F.LibraryFine;
        Totalpaid =F.Totalpaid;
        Balance =F.Balance;
    }
    void operator-=(float Payment)
    {
        Totalpaid += Payment;
        Balance += Payment;

        if(Balance < 0)
        {
            Balance = 0;
        }
    }
    void display()
    {
        cout<<" Student Ref : "<<StudentRef<<endl;
        cout<<" Semester Fee : "<<SemesterFee<<endl;
        cout<<" Hostel Fee : "<<HostelFee<<endl;
        cout<<" Library Fine : "<<LibraryFine<<endl;
        cout<<" Total Paid : "<<Totalpaid<<endl;
        cout<<" Balance : "<<Balance<<endl; 
    }
};
class Invoice
{
    private:
    int invoiceid;
    string date;
    string *item;
    int items;
    float totalamount;
    static int invoicecounter;
    public:
    Invoice(string a, int b, double c)
    {
        invoicecounter++;
        invoiceid = invoicecounter;

        date = a;
        items = b;
        totalamount = c;

        item = new string[items];

        for (int i = 0; i < items; i++)
        {
            cout << "Enter Item " << i + 1 << ": ";
            cin >> item[i];
        }
    }
      void display()
    {
        cout << "Invoice ID : " << invoiceid<<endl;
        cout << "Date : " << date<<endl;

        cout << "Items:"<<endl;

        for (int i = 0; i < items; i++)
            cout << item[i] << endl;

        cout << "Total Amount : " << totalamount << endl;
    }

    static void showCounter()
    {
        cout <<"Total Invoices = "<< invoicecounter << endl;
    }

    ~Invoice()
    {
        delete[] item;
        cout << "Invoice " << invoiceid << " Destroyed";
    }
};

int Invoice::invoicecounter = 0;


int main()
{
    FeeRecord F1("25-CS-061",90000,30000,500);
    FeeRecord F2("25-CS-390",70000,30000,200);

    FeeRecord F3(F1);

    F1 -= 2000;
    F2 -= 4000;

    FeeRecord F4;
    F4 = F2;

    F1.display();
    F2.display();
    cout<<"Copy Constructor"<<endl;
    F3.display();
    cout<<"Copy Assignment Operator "<<endl;
    F4.display();

     Invoice I1("1-June-2024",3,6400);
    I1.display();

    Invoice I2("10-Oct-2022",2,7800);
    I2.display();

    Invoice::showCounter();

    return 0;
}
