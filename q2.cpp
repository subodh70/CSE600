#include<bits/stdc++.h>
using namespace std;
string filename;
const int rows = 63;
int i = 0,yr;
long double inf[rows],ir[rows],inv,a,amnt,inf_amnt,x;
class q1
{
    public :
   
     void read() // parsing file
    {
        cout.unsetf( std::ios::floatfield );                
        cout.precision(16);
        fstream f("spain.csv");
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
          if(i == 42)  // 2002 , investment began in Peseta , corner cases
                inv = inv / 166 ;        
          a = inv*(1+(ir[i]/100));
          inv = a;
    }
       
       return inv;
    }
    
    double val(double amnt) // function overloading , for inflation
    {
        for( i = 62 ; i>=yr-1960 ; i--)
          {
            if(i == 42)  // 2002 , investment began in Peseta , corner case
                amnt = amnt * 166 ; 
            a = (1-(inf[i]/100))*amnt;
            amnt = a;
         }
         
        return amnt;
    }

   void check(double inv , int yr)
{ 
    double inv_1 = inv , k;
   for (i=0;i<18;i++)
    {
        a = inv*(1+(ir[i]/100));
        inv = a;
    }
   
   for(i=0;i<18;i++)
    {
     amnt = (1-(inf[i]/100))*a;
     a = amnt ;
    }
    amnt=amnt/18;

for (i=18;i<63;i++)
    {
        a = inv_1*(1+(ir[i]/100));
        inv_1 = a;
    }
   
   for(i=0;i<18;i++)
    {
     k = (1-(inf[i]/100))*a;
     a = k ;
    }
    k=k/45;  
      if(amnt>k)
           cout<<"\nDictatorship era is better";
      else
        cout<<"\nRepublican era is better";
    

}
};
int main()
{
    cout<<"------------- ~~~ SPAIN ~~~ ------------- ";
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
            cout<<"\nInvestment Amount =";
            if(yr>=2002)
            cout<<" EUR "; 
            else
            cout<<" Pta "; 
            cin>>inv;                      // user input
            if(inv <= 0)     // input validity check
                  cout<<"\nInvestment Amount must be > 0";
            else
            {
                x = inv;
                amnt = q.val(inv,yr);
                cout<<"\nValue of money = EUR " <<round(amnt*100)/100;
                inf_amnt = q.val(amnt);
                cout<<"\nValue of inflated money = " ;
                if(yr>=2002)
                cout<<" EUR "; 
                else
                cout<<" Pta "; 
                cout<<round(inf_amnt*100)/100;
                q.check(x,yr);

            }

        }    
        cout<<"\nDo you want more ( Y / N ) : ";
        cin>>c;
    }
    return 0;
}  