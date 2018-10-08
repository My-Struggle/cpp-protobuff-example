#include "msg.h"

Message::Message()
{
    cout << "message" << endl;
}
string Message::InitMsg(Msg_Body &Msg)
{
    //Msg_Body Msg;
    PK_Head *head = new PK_Head();
    head->set_pktype(5972015);
    head->set_pklength(16);

    // Msg_Body Msg;
    Msg.set_allocated_pkhead(head);
    Msg.set_msg("Hi，how are you");
    Msg.set_msglength(1115986);
    Msg.set_indexid(9);
    Msg.set_sequence(314957);
    Msg.set_bodynumber(8);
    Msg.set_type(Msg_Body::Linux);
    string tmp;
    Msg.SerializeToString(&tmp);
    // delete head;
    return tmp;
}
void Message::ShowMsg(string &tmp)
{

    Msg_Body get;
    get.ParseFromString(tmp);
    PK_Head pk(get.pkhead());
    cout << "PkLength=" << sizeof(pk) << endl;
    cout << "PkType=" << pk.pktype() << endl;
    cout << "Msg=" << get.msg() << endl;
    cout << "MsgLength=" << get.msglength() << endl;
    cout << "IndexID=" << get.indexid() << endl;
    cout << "Sequence=" << get.sequence() << endl;
    cout << "BodyNumber=" << get.bodynumber() << endl;
    // cout<<"Msg="<<get.msg()<<endl;
    // cout<<"Msg="<<get.msg()<<endl;
    cout << "SystemType=" << get.type() << endl;

    Msg_Body_SystemType *Type1 = new Msg_Body_SystemType();
    switch (get.type())
    {
    case Msg_Body::IOS:
        cout << "The system type is IOS" << endl;
        break;
    case Msg_Body::Android:
        cout << "The system type is Android" << endl;
        break;
    case Msg_Body::Symbian:
        cout << "The system type is Symbian" << endl;
        break;
    case Msg_Body::Windows:
        cout << "The system type is Windows" << endl;
        break;
    case Msg_Body::Linux:
        cout << "The system type is Linux" << endl;
        break;
    case Msg_Body::Other:
        cout << "The system type is Other" << endl;
        break;

    default:
        break;
    }
}
Message::~Message()
{

    cout << "~message" << endl;
}