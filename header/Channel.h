#ifndef CHANNEL_H
#define CHANNEL_H

#include <chrono>
#include <thread>

class Channel {
public:
    Channel(double bandwidth) : bandwidth(bandwidth), isBusy(false) {}

    bool check() {
        return !isBusy;
    }

    void transmit(int packetSize, int numUsers) {
        isBusy = true;
        double effectiveBandwidth = bandwidth / numUsers; // Split bandwidth among users
        double transmissionTime = (packetSize * 8.0f) / (effectiveBandwidth * 1e6f); // Time in seconds
        std::this_thread::sleep_for(std::chrono::duration<double>(transmissionTime));
        isBusy = false;
    }

private:
    double bandwidth;
    bool isBusy;
};

#endif // CHANNEL_H

