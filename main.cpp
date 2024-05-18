#include<bits/stdc++.h>
#include <cstdlib>
#include <ctime>
#include <iostream>
#include <stdio.h>
#include <vector>
#include <cstring>
#include <string>
using namespace std;
 class Person{
public:
    vector<Person>kills;
    string name;
  Person(string name){
      this->name=name;
    }
  };
int main()
{
    int t,x=1,z;
    char k;
    string name;
    vector<Person>alive;
    vector<Person>dead;
    cout<<"Hello ladies and gentlemen! Welcome to the Grand Hunger Games!\nPlease insert the number of players you wish to participate:\n";
    cin>>t;
    cout<<"And now, please insert the players' names:\n";
    for (int i=1; i<=t; i++)
    {
        cin>>name;
        Person player(name);
        alive.push_back(player);
    }
    cout<<"The simulation shall begin.\n";
    srand((unsigned) time(0));
    int day,person,times;
    while(t!=1){
    cout<<"***Day "<<x<<"***\n";
    times = (rand() % t/2+t/2) + 1;
    for (int i = 0; i < times; i++)
    {
        person = (rand() % t);
        day = (rand() % 10) + 1;
        cout<<alive.at(person).name;
        switch(day)
        {
        case 1 :
            cout<<" is fishing\n";
            break;
        case 2 :
            cout<<" is making weapons\n";
            break;
        case 3 :
            cout<<" is looking for a cave\n";
            break;
        case 4 :
            cout<<" is looking for other players\n";
            break;
        case 5 :
            cout<<" is thinking about winning\n";
            break;
        case 6 :
            cout<<" has reached high ground\n";
            break;
        case 7 :
            cout<<" just befriended a pig\n";
            break;
        case 8 :
            cout<<" is contemplating his/her decisions\n";
            break;
        case 9 :
            cout<<" is making shelter\n";
            break;
        case 10 :
            cout<<" is trying to make a bonfire\n";
            break;
        }
    }
    int night,contender,time,victim;
    int peace=0;
    cout<<"***Night "<<x<<"***\n";
    times = (rand() % t/2+t/2) + 1;
    for (int j = 0; j < times; j++)
    {
        if(t==1)
            break;
        contender = (rand() % t);
        victim = (rand() % t);
        night = (rand() % 11) + 1;
        switch(night)
        {
        case 1:
            if(victim!=contender){
            cout<<alive.at(contender).name<<" decapitated "<<alive.at(victim).name<<" with a sword slash\n";
            alive.at(contender).kills.push_back(alive.at(victim));
            alive.erase(alive.begin()+victim);
            t=t-1;
            break;
            }
        case 2:
            if(victim!=contender){
            cout<<alive.at(contender).name<<" poisoned "<<alive.at(victim).name<<"\n";
            alive.at(contender).kills.push_back(alive.at(victim));
            alive.erase(alive.begin()+victim);
            t=t-1;
            break;
            }
        case 3:
            if(victim!=contender){
            cout<<alive.at(victim).name<<" bled to death after a fight with "<<alive.at(contender).name<<"\n";
            alive.at(contender).kills.push_back(alive.at(victim));
            alive.erase(alive.begin()+victim);
            t=t-1;
            break;
            }
        case 4:
            cout<<alive.at(victim).name<<" died from thirst\n";
            alive.erase(alive.begin()+victim);
            t=t-1;
            break;
        case 5:
            cout<<alive.at(victim).name<<" died form an infection\n";
            alive.erase(alive.begin()+victim);
            t=t-1;
            break;
        case 6:
            cout<<alive.at(victim).name<<" got shot by an arrow\n";
            alive.erase(alive.begin()+victim);
            t=t-1;
            break;
        case 7:
            if(victim!=contender){
            cout<<alive.at(victim).name<<" was betrayed by "<<alive.at(contender).name<<"\n";
            alive.at(contender).kills.push_back(alive.at(victim));
            alive.erase(alive.begin()+victim);
            t=t-1;
            break;
        }
        case 8:
            if(victim!=contender){
            cout<<alive.at(victim).name<<" got his neck snapped by "<<alive.at(contender).name<<"\n";
            alive.at(contender).kills.push_back(alive.at(victim));
            alive.erase(alive.begin()+victim);
            t=t-1;
            break;
            }
        case 9:
            cout<<alive.at(victim).name<<" set himself on fire\n";
            alive.erase(alive.begin()+victim);
            t=t-1;
            break;
        case 10:
            cout<<alive.at(victim).name<<" got stomped by an elephant\n";
            alive.erase(alive.begin()+victim);
            t=t-1;
            break;
        case 11:
            if(j==0)
                cout<<"Nobody died tonight :D\n";
            peace=1;
            break;
        }
        if(peace==1)
            break;
    }
    cout<<"Press to continue \n";
    cin>>k;
    x=x+1;
    }
    cout<<"THE WINNER IS "<<alive.at(0).name<<" WITH "<<alive.at(0).kills.size()<<" KILLS :\n";
    for(z=0;z<alive.at(0).kills.size();z++)
        cout<<alive.at(0).kills.at(z).name<<endl;
    return 0;
}
