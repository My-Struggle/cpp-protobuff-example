#include <iostream>
#include <cstring>
#include <cstdio>
#include "pack.pb.h"

using namespace std;

int main()
{
    PK_Head *head=new PK_Head();
    head->set_pktype(5972015);
    head->set_pklength(16);

    Msg_Body Msg;
    Msg.set_allocated_pkhead(head);
    Msg.set_msg("Hi how aadasdre you");
    Msg.set_msglength(1115986);
    Msg.set_indexid(9);
    Msg.set_sequence(314957);
    Msg.set_bodynumber(8);
    Msg.set_type(Msg_Body::Linux);
    string tmp;
    Msg.SerializeToString(&tmp);
    Msg_Body get;
    get.ParseFromString(tmp);
    PK_Head pk(get.pkhead());
    cout<<"length="<<sizeof(pk)<<endl;
    cout<<""<<pk.pktype()<<endl;
    cout<<""<<get.msg()<<endl;
    cout<<""<<get.type()<<endl;
    
    return 0;
}