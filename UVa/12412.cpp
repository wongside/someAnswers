#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <iomanip>
using namespace std;
#define min 1e-6
struct student
{
    int cid,ma,ch,en,pr,total,sn,rank;//mathematics,chinese,english,procgramming,serial number.
    string name,sid;//sutdent id
};
bool cmp_by_value(const student &lhs, const student &rhs)
{
    if (lhs.total == rhs.total)
        return lhs.sn < rhs.sn;
    else
        return lhs.total > rhs.total;
}

int ranks(int j, vector<student> vs)
{
    student s=vs[j];
    sort(vs.begin(),vs.end(),cmp_by_value);
    vs[0].rank=1;

    if (s.total==vs[0].total)
        return 1;
    else
        for (int i = 1; i < vs.size(); ++i)
        {
            if (vs[i].total==vs[i-1].total)
                vs[i].rank=vs[i-1].rank;
            else
                vs[i].rank=i+1;

            if (vs[i].total==s.total)
                return vs[i].rank;
        }
}
int pass(student s)
{
    int k=0;

    if (s.ma>=60)
        ++k;

    if (s.ch>=60)
        ++k;

    if (s.en>=60)
        ++k;

    if (s.pr>=60)
        ++k;

    return k;
}
int main()
{
    
    cout<<setiosflags(ios::fixed)<<setprecision(2);
    
    vector<student> vs;
    int cid,ma,ch,en,pr,xx,k_sn=0;
    string name,sid;

    while(1)
    {
        cout<<"Welcome to Student Performance Management System (SPMS).\n"<<endl;
        cout<<"1 - Add\n2 - Remove\n3 - Query\n4 - Show ranking\n5 - Show Statistics\n0 - Exit\n"<<endl;
        int choose;
        cin>>choose;

        if(choose==0)//exit
            break;

        if (choose==1)//add
        {
            cout<<"Please enter the SID, CID, name and four scores. Enter 0 to finish."<<endl;

            while(cin>>sid&&sid!="0")
            {
                cin>>cid>>name>>ch>>ma>>en>>pr;
                bool add_in=true;

                for (int i = 0; i < vs.size(); ++i)
                {
                    if (vs[i].sid==sid)
                    {
                        cout<<"Duplicated SID."<<endl;
                        add_in=false;
                        break;
                    }
                }

                if (add_in)
                {
                    student tmp;
                    tmp.sid=sid;
                    tmp.cid=cid;
                    tmp.name=name;
                    tmp.ch=ch;
                    tmp.ma=ma;
                    tmp.en=en;
                    tmp.pr=pr;
                    tmp.total=pr+ch+ma+en;
                    ++k_sn;
                    tmp.sn=k_sn;
                    vs.push_back(tmp);
                }

                cout<<"Please enter the SID, CID, name and four scores. Enter 0 to finish."<<endl;
            }
        }

        if (choose==2)//remove
        {
            cout<<"Please enter SID or name. Enter 0 to finish."<<endl;

            while(cin>>name&&name!="0")
            {
                xx=0;

                for (int i =  vs.size()-1; i >=0; --i)
                {
                    if (vs[i].sid==name||vs[i].name==name)
                    {
                        vs.erase(vs.begin()+i);
                        ++xx;
                    }
                }

                cout<<xx<<" student(s) removed."<<endl;
                cout<<"Please enter SID or name. Enter 0 to finish."<<endl;
            }
        }

        if (choose==3)//query
        {
            cout<<"Please enter SID or name. Enter 0 to finish."<<endl;

            while(cin>>name&&name!="0")
            {
                for (int i =  0; i <vs.size(); ++i)
                {
                    if (vs[i].sid==name||vs[i].name==name)
                    {
                        double average=vs[i].total/4.0+min;
                        cout<<ranks(i,vs)<<" "<<vs[i].sid<<" "<<vs[i].cid<<" "<<vs[i].name<<" "<<vs[i].ch<<" "<<vs[i].ma<<" "<<vs[i].en<<" "<<vs[i].pr;
                        cout<<" "<<vs[i].total<<" "<<average<<endl;
                    }
                }

                cout<<"Please enter SID or name. Enter 0 to finish."<<endl;
            }
        }

        if(choose==4)//ranklist
            cout<<"Showing the ranklist hurts students' self-esteem. Don't do that."<<endl;

        if (choose==5)//statistics
        {
            cout<<"Please enter class ID, 0 for the whole statistics."<<endl;
            cin>>cid;
            map<int, int> mii;;//passed n subjects
            int t_stu=0,ma_p_stu=0,ma_t_sco=0,ch_p_stu=0,ch_t_sco=0,en_p_stu=0,en_t_sco=0,pr_p_stu=0,pr_t_sco=0;//total students ,math pass students,math total score

            for (int i = 0; i < vs.size(); ++i)
            {
                if (cid==0||vs[i].cid==cid)
                {
                    ++mii[pass(vs[i])];
                    ++t_stu;
                    ma_t_sco+=vs[i].ma;

                    if (vs[i].ma>=60)
                        ++ma_p_stu;

                    ch_t_sco+=vs[i].ch;

                    if (vs[i].ch>=60)
                        ++ch_p_stu;

                    en_t_sco+=vs[i].en;

                    if (vs[i].en>=60)
                        ++en_p_stu;

                    pr_t_sco+=vs[i].pr;

                    if (vs[i].pr>=60)
                        ++pr_p_stu;
                }
            }

            cout<<"Chinese"<<endl;
            cout<<"Average Score: "<<(t_stu!=0?ch_t_sco*1.0/t_stu+min:0.00)<<endl;
            cout<<"Number of passed students: "<<ch_p_stu<<endl;
            cout<<"Number of failed students: "<<t_stu-ch_p_stu<<endl;
            cout<<endl;
            cout<<"Mathematics"<<endl;
            cout<<"Average Score: "<<(t_stu!=0?ma_t_sco*1.0/t_stu+min:0.00)<<endl;
            cout<<"Number of passed students: "<<ma_p_stu<<endl;
            cout<<"Number of failed students: "<<t_stu-ma_p_stu<<endl;
            cout<<endl;
            cout<<"English"<<endl;
            cout<<"Average Score: "<<(t_stu!=0?en_t_sco*1.0/t_stu+min:0.00)<<endl;
            cout<<"Number of passed students: "<<en_p_stu<<endl;
            cout<<"Number of failed students: "<<t_stu-en_p_stu<<endl;
            cout<<endl;
            cout<<"Programming"<<endl;
            cout<<"Average Score: "<<(t_stu!=0?pr_t_sco*1.0/t_stu+min:0.00)<<endl;
            cout<<"Number of passed students: "<<pr_p_stu<<endl;
            cout<<"Number of failed students: "<<t_stu-pr_p_stu<<endl;
            cout<<endl;
            cout<<"Overall:"<<endl;
            cout<<"Number of students who passed all subjects: "<<mii[4]<<endl;
            cout<<"Number of students who passed 3 or more subjects: "<<mii[4]+mii[3]<<endl;
            cout<<"Number of students who passed 2 or more subjects: "<<mii[4]+mii[3]+mii[2]<<endl;
            cout<<"Number of students who passed 1 or more subjects: "<<mii[4]+mii[3]+mii[2]+mii[1]<<endl;
            cout<<"Number of students who failed all subjects: "<<mii[0]<<endl;
            cout<<endl;
        }
    }

    return 0;
}
