#include <fstream>
#include "Log.h"
using namespace std;
namespace He_Arc::RPG
{
    /**
     * @brief Write a message in a log file (messages.txt)
     * 
     * @param message 
     */
    void Log::MessageLog(std::string message){
        freopen( "messages.txt", "a", stdout);
        cout << getCurrentDateTime() << endl;
        cout << message << endl;
        std::fclose(stdout);
    }
    /**
     * @brief Write details of a trade in a log file (trades.txt)
     * 
     * @param h Hero who has sold an item
     * @param i Item that has been sold
     * @param m Merchant who bought the item
     */
    void Log::TradeLog(Hero* h, IItem * i, Merchant* m){
        try {
            ofstream TradesLogFile;
            TradesLogFile.open ("trades.txt",  ios::app);
            TradesLogFile << getCurrentDateTime() << "\n";
            TradesLogFile << h->GetName() << " has sold a " << i->GetName() << " (" << i->GetFeature() << ", "<< i->GetPrice() << " golds) at " << m->GetName() << "\n";
            TradesLogFile.close();
        } catch(exception e){
            ErrorLog(e);
        } catch(...){
            ErrorLog("Unkown error happened while reading or writing trading log file");
        }
    }
    /**
     * @brief Write details of a trade in a log file (trades.txt)
     * 
     * @param m Merchant who has sold an item
     * @param i Item that has been sold
     * @param h Hero who bought the item
     */
    void Log::TradeLog(Merchant* m, IItem * i, Hero* h){
        try{
            ofstream TradesLogFile;
            TradesLogFile.open("trades.txt", ios::app);
            TradesLogFile << getCurrentDateTime() << "\n";
            TradesLogFile << h->GetName() << " bought a " << i->GetName() << " (" << i->GetFeature() << ", "<< i->GetPrice() << " golds) at " << m->GetName() << "\n";
            TradesLogFile.close();
        } catch(exception e){
            ErrorLog(e);
        } catch(...) {
            ErrorLog("Unkown error happened while reading or writing trading log file");
        }
    }
    /**
     * @brief Write details of an error in a log file (errors.txt)
     * 
     * @param e Exception
     */
    void Log::ErrorLog(exception e){
        ofstream ErrorsLogFile;
        ErrorsLogFile.open("errors.txt", ios::app);
        ErrorsLogFile << getCurrentDateTime() << "\n";
        ErrorsLogFile << e.what() << "\n";
        ErrorsLogFile.close();
    }
    /**
     * @brief Write details of an error in a log file (errors.txt)
     * 
     * @param message Error message
     */
    void Log::ErrorLog(string message){
        ofstream ErrorsLogFile;
        ErrorsLogFile.open("errors.txt", ios::app);
        ErrorsLogFile << getCurrentDateTime() << "\n";
        ErrorsLogFile << message << "\n";
        ErrorsLogFile.close();
    }
    /**
     * @brief Get the current date for the logging system
     * 
     * @return string Today datetime
     */
    string Log::getCurrentDateTime(){
        time_t now = time(0);
        struct tm  tstruct;
        char  buf[80];
        tstruct = *localtime(&now);
        strftime(buf, sizeof(buf), "%Y-%m-%d %X", &tstruct);
        return string(buf);
    }
}