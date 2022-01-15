
#ifndef ODriveArduino_h
#define ODriveArduino_h

#include "Arduino.h"
#include "ODriveEnums.h"

class ODriveArduino {
private:
    Stream& serial_;

    String readString();

public:
    /**
     * @brief Construct a new ODriveArduino object
     *
     * @param[in] serial The serial port to use to communicate with the ODrive
     */
    ODriveArduino(Stream& serial);

    /**
     * @brief Set the Position of a motor with a given velocity and torque
     * Note that if you don’t know what feed-forward is or what it’s used for, simply omit it.
     * This command updates the watchdog timer for the motor.
     * @param[in] motor_number is the motor number, 0 or 1
     * @param[in] position is the desired position, in [turns].
     * @param[in] velocity_feedforward is the velocity limit, in [turns/s] (optional)
     * @param[in] torque_feedforward is the torque limit, in [Nm] (optional)
     */
    void setPosition(int motor_number, float position, float velocity_feedforward = 0.0f, float torque_feedforward = 0.0f);

    /**
     * @brief Set the Velocity of a motor
     * Note that if you don’t know what feed-forward is or what it’s used for, simply omit it.
     * This command updates the watchdog timer for the motor.
     * @param[in] motor_number is the motor number, 0 or 1.
     * @param[in] velocity is the desired velocity in [turns/s].
     * @param[in] torque_feedforward is the torque feed-forward term, in [Nm] (optional).
     */
    void setVelocity(int motor_number, float velocity, float torque_feedforward = 0.0f);

    /**
     * @brief Set the torque of a motor
     * This command updates the watchdog timer for the motor.
     * @param motor_number The motor to set the torque of
     * @param torque
     */
    void setTorque(int motor_number, float torque);

    //TODO: comprendre comment marche la notion de trapezoidalMove
    void trapezoidalMove(int motor_number, float position);


    /**
     * @brief Get the Velocity of a motor
     *
     * @param[in] motor_number The motor to get the velocity of
     * @return float The velocity of the motor
     */
    float getVelocity(int motor_number);

    /**
     * @brief Get the Position of a motor
     *
     * @param[in] motor_number The motor to get the position of
     * @return float The position of the motor
     */
    float getPosition(int motor_number);


    // General params
    float readFloat();
    int32_t readInt();

    // State helper
    bool run_state(int axis, int requested_state, bool wait_for_idle, float timeout = 10.0f);
};

#endif //ODriveArduino_h
