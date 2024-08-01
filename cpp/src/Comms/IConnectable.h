#ifndef WAVES_ICONNECTABLE_H
#define WAVES_ICONNECTABLE_H

class IConnectable {
public:
    virtual ~IConnectable() = default;
    virtual void connect() = 0;
    virtual void closeConnection() = 0;
};

#endif // WAVES_ICONNECTABLE_H
