//
// Created by Peter on 7/5/2024.
//

#ifndef WAVES_DATALOGGER_H
#define WAVES_DATALOGGER_H


#include "../Comms/WavesStatusMessage.h"

class DataLogger {
public:
    explicit DataLogger(std::string fileDirectory_);
    void init();
    void log(const WavesStatusMessage& message);

private:
    const std::string fileDirectory;
    std::vector<std::string> headers;
    static std::vector<std::string> getHeaders();
};


#endif //WAVES_DATALOGGER_H
