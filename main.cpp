#include <iostream>

enum class Color
{
    BLACK,
    WHITE
};

enum class DeviceType
{
    ENERGY_COUNTER,
    SIGNAL_INPUT,
    TEMP_MANAGEMENT
};

class Device
{
private:
    Color m_color;

protected:
    DeviceType m_type;
};

class EnergyCounter : public Device
{
private:

public:

};

class SignalInput : public Device
{
private:

public:

};

class TempManager : public Device
{
private:

public:

};

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
