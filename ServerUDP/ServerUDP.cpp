#include "pch.h"

using namespace System;
using namespace System::Net;
using namespace System::Net::Sockets;
using namespace System::Text;


int main()
{
    int port = 5004;
    IPAddress^ IP = IPAddress::Parse("127.0.0.1");
    UdpClient^ listener = gcnew UdpClient(port);
    IPEndPoint^ groupEP = gcnew IPEndPoint(IP, port);
    try
    {
        while (true)
        {
            Console::WriteLine("Waiting for broadcast");
            array<unsigned char>^ b = listener->Receive(groupEP);

            Console::WriteLine("Received broadcast from " + groupEP + " :");
            Console::WriteLine(Encoding::ASCII->GetString(b, 0, b->Length));
        }
    }
    catch (SocketException^ e)
    {
        Console::WriteLine(e);
    }
    finally
    {
        listener->Close();
    }
}