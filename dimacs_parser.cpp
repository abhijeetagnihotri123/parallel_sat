#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
using namespace std;
vector<vector<int>>dummyclauses;
vector<vector<int>>clauses; 
int main()
{   
    fstream fp;
    fp.open("cl.cnf",ios::in);
    char c;
    string str="";
    for(int i=0;i<5;i++)
    {
        fp.seekg(i,ios::beg);
        fp.get(c);
        str+=c;
    }
    if(str=="p cnf")
    {   
        int numvariables,numclauses;
        fp.seekg(6,ios::beg);
        str="";
        while(fp)
        {
            if(c=='\n')
            {
                 break;
            }
            fp.get(c);
            str=str+c;
        }
        stringstream s(str);
        s>>numvariables>>numclauses;
        str="";
        while(!fp.eof())
        {
            fp.get(c);
            if(c!='\n')
            {
                str=str+c;
            }
            else
            {   stringstream s(str);
                int k;
                vector<int>a;
                while(s>>k)
                {
                    if(k!=0)
                    {
                        a.push_back(k);
                    }
                }
                dummyclauses.push_back(a);
                str="";
            }
        }
        for(int i=0;i<dummyclauses.size();i++) // some empty were empty so remove them
        {   
            if(dummyclauses[i].size()>0)
            {
                clauses.push_back(dummyclauses[i]);
            }
        }
        dummyclauses.clear();
        if(clauses.size()!=numclauses)
        {
            cout<<"Warning number of clauses provided and mentioned are not equal\n";
        }
    }
    else
    {
        cout<<"Wrong format parse error\n";
    }
    fp.close();
    return 0;   
}