#include <iostream>
#include <string>
#include "PKMSG/pack.pb.h"

using namespace PKMSG;
using namespace std;

class Message
{

    public:
        Message(/* args */);
        ~Message();
        string InitMsg(Msg_Body &Msg);
        void ShowMsg(string &tmp);
    private:
   
};

