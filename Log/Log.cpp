#include "Log.h"
using namespace std;
namespace He_Arc::RPG
{
    void Log::MessageLog(std::string message){
        freopen( "messages.txt", "a", stdout);
        cout << getCurrentDateTime() << endl;
        cout << message << endl;
        std::fclose(stdout);
    }
    void Log::TradeLog(Hero* h, IItem * i, Merchant m){
        freopen( "trades.txt", "a", stdout);
        cout << getCurrentDateTime() << endl;
        cout << h->GetName() << " has sold a " << i->GetName() << "(" << i->GetFeature() << ", "<< i->GetPrice() << " golds) at" << m.GetName() << endl;
        std::fclose(stdout);
    }
    void Log::TradeLog(Merchant m, IItem * i, Hero* h){
        freopen( "trades.txt", "a", stdout);
        cout << getCurrentDateTime() << endl;
        cout << h->GetName() << " bought a " << i->GetName() << "(" << i->GetFeature() << ", "<< i->GetPrice() << " golds) at" << m.GetName() << endl;
        std::fclose(stdout);
    }
    void Log::ErrorLog(exception e){
        freopen( "errors.txt", "a", stderr);
        cerr << getCurrentDateTime() << endl;
        cerr << e.what() << endl;
        std::fclose(stderr);
    }
    void Log::ErrorLog(string message){
        freopen( "errors.txt", "a", stderr);
        cerr << getCurrentDateTime() << endl;
        cerr << message << endl;
        std::fclose(stderr);
    }
    string Log::getCurrentDateTime(){
        time_t now = time(0);
        struct tm  tstruct;
        char  buf[80];
        tstruct = *localtime(&now);
        strftime(buf, sizeof(buf), "%Y-%m-%d %X", &tstruct);
        return string(buf);
    }
}