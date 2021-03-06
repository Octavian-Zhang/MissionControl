#include <future>
#include "DataLogging.hpp"

DataLogging::DataLogging(const std::string& path) : storage_(initStorage(path))
{
    storage_.sync_schema();
}

void DataLogging::wrtieLog(const FlightLogging* data)
{
    static DataLogging instance{"FlightLogging.sqlite"};
    auto sqlfuture = std::async(std::launch::async,
                                [&]()
                                { instance.storage_.transaction([&]
                                                                {
                instance.storage_.insert(data->FlightCMD);
                instance.storage_.insert(data->InnerState);
                instance.storage_.insert(data->MiscStatus);
                instance.storage_.insert(data->RealUAVState);
                instance.storage_.insert(data->SimUAVState);
                instance.storage_.insert(data->VectorSpd);
                instance.storage_.insert(data->ADRC_Log);
                instance.storage_.insert(data->TimeNow);
                return true; }); });
}