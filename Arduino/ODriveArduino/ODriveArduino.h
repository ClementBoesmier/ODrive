
#ifndef ODriveArduino_h
#define ODriveArduino_h

#include "Arduino.h"
#include "ODriveEnums.h"

class ODriveArduino {
public:
    /**
     * @brief Construct a new ODriveArduino object
     *
     * @param[in] serial The serial port to use to communicate with the ODrive
     */
    ODriveArduino(Stream& serial);

    //TODO: comprendre comment marche velocity_feedforward
    //TODO: comprendre comment marche current_feedforward
    /**
     * @brief Set the Position of a motor
     *
     * @param[in] motor_number The motor to set the position of
     * @param[in] position The position to set the motor to in tour number
     * @param[in] velocity_feedforward
     * @param[in] current_feedforward
     */
    void setPosition(int motor_number, float position, float velocity_feedforward = 0, 0f, float current_feedforward = 0.0f);

    //TODO: comprendre comment marche current_feedforward
    /**
     * @brief Set the Velocity of a motor
     *
     * @param[in] motor_number The motor to set the velocity of
     * @param[in] velocity The velocity to set the motor to
     * @param[in] current_feedforward
     */
    void setVelocity(int motor_number, float velocity, float current_feedforward = 0.0f);


    void setCurrent(int motor_number, float current);
    void trapezoidalMove(int motor_number, float position);
    // getters
    float getVelocity(int motor_number);
    float getPosition(int motor_number);
    // General params
    float readFloat();
    int32_t readInt();

    // State helper
    bool run_state(int axis, int requested_state, bool wait_for_idle, float timeout = 10.0f);
private:
    String readString();

    Stream& serial_;
};

#endif //ODriveArduino_h
