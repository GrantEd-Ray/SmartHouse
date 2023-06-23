#include <iostream>
#include <fstream>
#include <string>

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
protected:
    DeviceType m_type;
    std::string m_name;
public:
    Device(const std::string& name) : m_name(name)
    {

    }

    Device& operator= (const Device& other)
    {
        this->m_name = other.m_name;
        this->m_type = other.m_type;
        return *this;
    }
    virtual void pool() = 0;
};

class EnergyCounter : public Device
{
public:
    explicit EnergyCounter(const std::string& name) : Device(name)
    {
        m_type = DeviceType::ENERGY_COUNTER;
    }
    void pool() override
    {
        std::cout << m_name << std::endl;
    }
};

class SignalInput : public Device
{
public:
    explicit SignalInput(const std::string& name) : Device(name)
    {
        m_type = DeviceType::ENERGY_COUNTER;
    }
    void pool() override
    {
        std::cout << m_name << std::endl;
    }
};

class TempManager : public Device
{
public:
    explicit TempManager(const std::string& name) : Device(name)
    {
        m_type = DeviceType::ENERGY_COUNTER;
    }
    void pool() override
    {
        std::cout << m_name << std::endl;
    }
};

struct Configuration
{
    EnergyCounter m_EC;
    SignalInput m_SI;
    TempManager m_TM;

    Configuration() = default;
    /*~Configuration()
    {
        if (m_EC != nullptr)
            delete m_EC;
        if (m_SI != nullptr)
            delete m_SI;
        if (m_TM != nullptr)
            delete m_TM;
    }
    */
    void set_EC(const EnergyCounter& EC)
    {
        m_EC = EC;
    }

    void set_SI(const SignalInput& SI)
    {
        m_SI = SI;
    }

    void set_TM(const TempManager& TM)
    {
        m_TM = TM;
    }
};

int main() {
    setlocale(LC_ALL, "ru");
    std::fstream config("Config.txt");
    Configuration cf1();

    std::fstream ECs("Texts/Energy_Counter_Devices.txt");
    std::fstream SIs("Texts/Input_Devices.txt");
    std::fstream TMs("Texts/Temp_Devices.txt");

    std::string curr_device;
    std::string chech_device;

    while (std::getline(config, curr_device))
    {
        while (std::getline(ECs, chech_device))
        {
            if (curr_device == chech_device)
            {
                EnergyCounter EC(curr_device);
                cf1().set_EC(EC);
            }
        }
        while (std::getline(SIs, chech_device))
        {
            if (curr_device == chech_device)
            {
                SignalInput SI(curr_device);
                cf1().set_SI(SI);
            }
        }
        while (std::getline(TMs, chech_device))
        {
            if (curr_device == chech_device)
            {
                TempManager TM(curr_device);
                cf1().set_TM(TM);
            }
        }
    }


    cf1().m_EC.pool();
    cf1().m_SI.pool();
    cf1().m_TM.pool();

    return 0;
}
