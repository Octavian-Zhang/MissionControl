#include <future>
#include "DataLogging.hpp"

DataLogging::DataLogging(const std::string& path) : storage_(initStorage(path))
{
    storage_.sync_schema();
}

void DataLogging::wrtieLog(const FlightLogging* data)
{
    static DataLogging instance{"FlightLogging.sqlite"};
    static std::unique_ptr<std::thread> ptrLogTd;
    std::packaged_task<void()> task([&]()
                                    { instance.storage_.transaction([&]
                                                                    {
                instance.storage_.insert(data->FlightCMD);
                instance.storage_.insert(data->InnerState);
                instance.storage_.insert(data->RealUAVState);
                instance.storage_.insert(data->SimUAVState);
                instance.storage_.insert(data->VectorSpd);
                instance.storage_.insert(data->ADRC_Log);
                instance.storage_.insert(data->TimeNow); 
                return true; }); });
    ptrLogTd = std::make_unique<std::thread>(std::move(task));
}