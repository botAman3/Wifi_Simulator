#ifndef WIFI5_H
#define WIFI5_H

#include "BaseWiFi.h"
#include <chrono>
#include <algorithm>

class WiFi5 : public BaseWiFi {
public:
    WiFi5(std::vector<User> users, Channel& channel) 
        : BaseWiFi(users, channel) {}

    double transmitData() {
        double totalTime = 0;
        unsigned int streams = 4; // Simulate MU-MIMO streams
        for (unsigned int i = 0; i < users.size(); i += streams) {
            auto startTime = std::chrono::high_resolution_clock::now();
            for (unsigned int j = i; j < i + streams && j < users.size(); ++j) {
                channel.transmit(users[j].sendPacket().getSize() / streams, users.size());
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

#endif // WIFI5_H