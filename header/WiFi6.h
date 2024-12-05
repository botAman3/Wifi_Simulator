#ifndef WIFI6_H
#define WIFI6_H

#include "BaseWiFi.h"
#include <chrono>
#include <algorithm>

class WiFi6 : public BaseWiFi {
public:
    WiFi6(std::vector<User> users, Channel& channel) 
        : BaseWiFi(users, channel) {}

    double transmitData() {
        double totalTime = 0;
        unsigned int numSubChannels = 8;
        unsigned int usersPerSlot = (users.size() + numSubChannels - 1) / numSubChannels;

        for (unsigned int i = 0; i < users.size(); i += usersPerSlot) {
            auto startTime = std::chrono::high_resolution_clock::now();
            for (unsigned int j = i; j < i + usersPerSlot && j < users.size(); ++j) {
                channel.transmit(users[j].sendPacket().getSize() / numSubChannels, users.size());
            }
            auto endTime = std::chrono::high_resolution_clock::now();
            double latency = std::chrono::duration<double>(endTime - startTime).count();
            maxLatency = std::max(maxLatency, latency);
            totalLatency += latency;
            totalTime += latency;
        }
        return totalTime;
    }
};

#endif // WIFI6_H