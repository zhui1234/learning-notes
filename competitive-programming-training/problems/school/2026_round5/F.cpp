#include<bits/stdc++.h>
using namespace std;

#define i64 long long
#define N 200010
int n,m;
map<string,int>n_contest,n_team;
struct contest
{
	i64 p,x,y,z;
}c[N];
struct team
{
	vector<int>con;
	vector<string>type,medal;
	i64 sum;
}t[N];

i64 num(string x)
{
	int len=x.size();
	i64 res=0;
	for(int i=0;i<len;i++)
		res=res*10+x[i]-'0';
	return res;
}

void solve()
{
	string order;
	bool p=0;
	while(p || cin>>order)
	{
		p=0;
		if(order=="REGISTER")
		{
			string s1,s2,s3,s4,s5,name;
			cin>>s1>>s2>>s3>>s4>>s5;
			name=s1.substr(8);
			if(n_contest.find(name)!=n_contest.end())
			{
				cout<<"CONTEST ALMOST EXISTS\n";
				continue;
			}
			n_contest[name]=++n;
			c[n].p=num(s2.substr(7));
			c[n].x=num(s3.substr(4));
			c[n].y=num(s4.substr(6));
			c[n].z=num(s5.substr(5));
			cout<<"OK\n";
		}
		else if(order=="NEWTEAM")
		{
			string s,name;
			cin>>s;
			name=s.substr(5);
			if(n_team.find(name)!=n_team.end())
			{
				cout<<"TEAM ALMOST EXISTS\n";
				continue;
			}
			n_team[name]=++m;
			cout<<"OK\n";
		}
		else if(order=="PARTICIPATE")
		{
			string s1,s2,s3,s4,name_t,name_c;
			cin>>s1>>s2>>s3>>s4;
			name_t=s1.substr(5);
			name_c=s2.substr(8);
			if(n_contest.find(name_c)==n_contest.end())
			{
				cout<<"CONTEST NOT FOUND\n";
				continue;
			}
			if(n_team.find(name_t)==n_team.end())
			{
				cout<<"TEAM NOT FOUND\n";
				continue;
			}
			int id_t=n_team[name_t],id_c=n_contest[name_c];
			if(find(t[id_t].con.begin(),t[id_t].con.end(),id_c) != t[id_t].con.end())
			{
				cout<<"ALREADY PARTICIPATED\n";
				continue;
			}
			t[id_t].con.push_back(id_c);
			t[id_t].type.push_back(s3.substr(5));
			t[id_t].medal.push_back(s4.substr(6));
			if(s3.substr(5)=="REGULAR" && s4.substr(6)!="IRON")
				t[id_t].sum+=80*c[id_c].p;
			cout<<"OK\n";
		}
		else if(order=="REIMBURSEMENT")
		{
			string s1,s2,name_t,name_c;
			cin>>s1>>s2;
			name_t=s1.substr(5);
			name_c=s2.substr(8);
			string s;
			vector<string>seq;
			while(cin>>s)
                if(s.find('=') < s.size())
				    seq.push_back(s);
                else
                {
			        order=s,p=1;
                    break;
                }
			if(n_contest.find(name_c)==n_contest.end())
			{
				cout<<"CONTEST NOT FOUND\n";
				continue;
			}
			if(n_team.find(name_t)==n_team.end())
			{
				cout<<"TEAM NOT FOUND\n";
				continue;
			}
			int id_t=n_team[name_t],id_c=n_contest[name_c];
            int id_t_c=find(t[id_t].con.begin(),t[id_t].con.end(),id_c)-t[id_t].con.begin();
			if(id_t_c == t[id_t].con.size() || t[id_t].type[id_t_c]=="STARRED" || t[id_t].medal[id_t_c]=="IRON")
			{
				cout<<"INELIGIBLE\n";
				continue;
			}
			bool ac=0;
			i64 sum=0,v;
			for(int i=0;i<seq.size() && !ac;i++)
				if(seq[i].size()>15 && seq[i].substr(0,15)=="REGISTRATIONFEE")
				{
					v=num(seq[i].substr(16));
					if(v!=c[id_c].x)
					{
						cout<<"INCORRECT REGISTRATION FEE\n";
						ac=1;
					}
					sum+=v;
				}
			for(int i=0;i<seq.size() && !ac;i++)
				if(seq[i].size()>9 && seq[i].substr(0,9)=="TRAINFARE")
				{
					v=num(seq[i].substr(10));
					if(v>2*c[id_c].y*c[id_c].p)
					{
						cout<<"INCORRECT TRAIN FARE\n";
						ac=1;
					}
					sum+=v;
				}
			for(int i=0;i<seq.size() && !ac;i++)
				if(seq[i].size()>8 && seq[i].substr(0,8)=="ROOMRATE")
				{
					v=num(seq[i].substr(9));
					if(v>2*c[id_c].z*c[id_c].p)
					{
						cout<<"INCORRECT ROOMRATE\n";
						ac=1;
					}
					sum+=v;
				}
			if(ac)continue;
			cout<<"OK,REIMBURSED="<<sum<<'\n';
			t[id_t].sum+=sum;
		}
		else if(order=="QUERYSUM")
		{
			i64 sum=0;
			for(int i=1;i<=m;i++)
				sum+=t[i].sum;
			cout<<"OK,SUM="<<sum<<'\n';
		}
		else
		{
			string s,name;
			cin>>s;
			name=s.substr(5);
			if(n_team.find(name)!=n_team.end())
			{
				cout<<"OK,TEAMSUM="<<t[n_team[name]].sum<<'\n';
			}
			else
			{
				cout<<"TEAM NOT FOUND\n";
			}
		}
	}
}

int main()
{
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	int T=1;
	//cin>>T;
	while(T--)solve();
	return 0;
}
