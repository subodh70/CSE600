#include<bits/stdc++.h>
using namespace std;
string filename;
const int rows = 63;
int i = 0,yr;
long double inf[rows],ir[rows],inv,a,amnt,inf_amnt;
class q1
{
    public :
   
     void read() // parsing file
    {
        cout.unsetf( std::ios::floatfield );                
        cout.precision(16);
        fstream f("india.csv");
        string s;
        getline(f,s);
        while(f >> s)
        {
            stringstream ss(s);
            char c;
            int temp,year;
            ss >> temp >> c >> year >> c >> ir[i] >> c >> inf[i] ;
            i++;
        }       
        f.close();
        
    }

    double val(double inv , int yr)
    {
        for(i = yr - 1960 ; i<rows ; i++)
      {
          a = inv*(1+(ir[i]/100));
          inv = a;
     }
       
       return inv;
    }
    
    double val(double amnt) // function overloading , for inflation
    {
        for( i = 62 ; i>=yr-1960 ; i--)
          {
            a = (1-(inf[i]/100))*amnt;
            amnt = a;
         }
         
        return amnt;
    }
};
int main()
{
    cout<<"------------- ~~~ INDIA ~~~ ------------- ";
    q1 q;
    q.read();
    char c = 'y';
    while(c == 'y' || c == 'Y')
    {
        cout<<"\nInvestment year = ";
        cin>>yr;                       // user input

        if(yr < 1960 || yr > 2022)     // input validity check
           cout<<"\nRange of year is between 1960 - 2022 , both inclusive ";
        else
        {
            cout<<"\nInvestment Amount = Rs "; 
            cin>>inv;                      // user input
            if(inv <= 0)     // input validity check
                  cout<<"\nInvestment Amount must be > 0";
            else
            {
                 amnt = q.val(inv,yr);
                 cout<<"\nValue of money = Rs " <<round(amnt*100)/100;
                 inf_amnt = q.val(amnt);
                 cout<<"\nValue of inflated money = Rs " <<round(inf_amnt*100)/100;
            }

        }    
        cout<<"\nDo you want more ( Y / N ) : ";
        cin>>c;
    }
    return 0;
}  