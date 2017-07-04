#include<bits/stdc++.h>
#include<string>

using namespace std;

bool comp(const pair < pair <string,string> , int >&a ,
          const pair < pair <string,string> , int >&b )
          {
              if(a.first.first.compare(b.first.first) < 0)
                return true;
              if(a.first.first.compare(b.first.first) > 0)
                return false;
              else
              {
                  if( a.second < b.second )
                    return true;
                  return false;
              }
          }

int main()
{
    int n,m,i,j,c;

    string str="",str1="",str2="",str3="";

    getline(cin,str);
    c=0;
    for(j=0;str[j]!='\0';j++)
    {
        if(str[j]==' ')
            c++;
        else
        {
            if(c==0)
               str1.push_back(str[j]);
            else
               str2.push_back(str[j]);
        }
    }
    //str1.push_back('\0');
    //str2.push_back('\0');

    n=atoi(str1.c_str());
    m=atoi(str2.c_str());

    while(n--)
        getline(cin,str);

    vector < pair < pair < string,string> ,int> > g;

    for(i=1;i<=m;i++)
    {
        getline(cin,str);
        str1="";
        str2="";
        str3="";
        c=0;

        for(j=0;str[j]!='\0';j++)
        {
            if(str[j]==' ')
                c++;
            else
            {
                if(c==0)
                    str1.push_back(str[j]);
                else if(c==1)
                    str2.push_back(str[j]);
                else
                    str3.push_back(str[j]);
            }
        }

        //str1.push_back('\0');
        //str2.push_back('\0');
        //str3.push_back('\0');

        g.push_back(make_pair(make_pair(str1,str2),atoi(str3.c_str())));

    }

    sort(g.begin(),g.end(),comp);

    str=g[0].first.first;
    cout<<g[0].first.first<<endl;
    cout<<g[0].first.second<<" "<<g[0].second<<endl;
    for(i=1;i<m;i++)
    {
        if(str.compare(g[i].first.first)!=0)
        {
            str=g[i].first.first;
            cout<<g[i].first.first<<endl;
            cout<<g[i].first.second<<" "<<g[i].second<<endl;
        }
        else
            cout<<g[i].first.second<<" "<<g[i].second<<endl;
    }

    return 0;

}
