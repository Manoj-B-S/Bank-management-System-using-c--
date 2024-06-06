#include <iostream>
using namespace std;
class Bank_Account
{
    string name;
    int accno;
    float balance;
    string acctype;

public:
    Bank_Account()
    {
    }
    void input();
    void withdraw(float a);
    void deposit(float a);
    void information();
    int check()
    {
        return accno;
    }
};
void Bank_Account::input()
{
    cout << "\nEnter Name : ";
    cin >> name;
    cout << "\nEnter Account No. : ";
    cin >> accno;
    cout << "\nEnter intial balance : ";
    cin >> balance;
    cout << "\nEnter Account Type(SAVINGS/CURRENT) : ";
    cin >> acctype;
}
void Bank_Account::withdraw(float a)
{
    if (a > balance)
    {
        cout << "\nINSUFFICIENT BALANCE : " << endl;
    }
    else
    {
        balance = balance - a;
        cout << "\nCurrent Balance : " << balance << endl;
    }
}
void Bank_Account::deposit(float a)
{
    balance = balance + a;
    cout << "\nCurrent Balance : " << balance << endl;
}
void Bank_Account::information()
{
    cout << "\n\nYour acc_no is: " << accno;
    cout << "\nYour name is: " << name;
    cout << "\nYour current balance is: " << balance;
    cout << "\nYour type of account is: " << acctype << endl;
}
int main()
{
    int id, h, ii, c, i, che = 0;
    cout << "\nEnter no. Account Holders : ";
    cin >> h;
    Bank_Account b[h];
    for (i = 0; i < h; i++)
    {
        b[i].input();
    }

    char run;
    float with;
    do
    {
        cout << "\n------------------------------\n";
        cout << "\n        W E L C O M E \n " << endl;
        cout << "------------------------------\n";
        cout << "Enter Account Number : ";
        cin >> id;
        for (i = 0; i < 10; i++)
        {
            if (b[i].check() == id)
            {
                che = 1;
                ii = i;
                break;
            }
            else
            {
                che = 0;
            }
        }
        while (1)
        {
            if (che == 1)
            {
                cout << "\n1.Display\n2.Withdraw\n3.Deposite\n4.Exit\n Enter the Choice :";
                cin >> c;
                switch (c)
                {
                case 1:
                    b[ii].information();
                    break;
                case 2:
                    cout << "Enter the amount to be withdrawn : ";
                    cin >> with;
                    b[ii].withdraw(with);
                    break;
                case 3:
                    cout << "Enter the amount to be deposited :";
                    cin >> with;
                    b[ii].deposit(with);
                    break;
                case 4:
                    cout << "Program Exited" << endl;
                    break;
                default:
                    cout << "INCORRECT INPUT TRY AGAIN" << endl;
                }
                if (c == 4)
                {
                    break;
                }
            }
            else
            {
                cout << "\nAccount Number not available:" << endl;
                break;
            }
        }
        cout << "\nDo you want to check for other account(Y for yes and N for no) : ";
        cin >> run;
        if (run == 'N' || run == 'n')
        {
            break;
        }
    } while (1);
}