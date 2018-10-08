#include "msg.h"

int main()
{
    Message *Msg=new Message();
    Msg_Body Body;
    string tmp;
    tmp=Msg->InitMsg(Body);
    Msg->ShowMsg(tmp);
    delete Msg;

}
