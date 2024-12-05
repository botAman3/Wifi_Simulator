#ifndef WIFI4_H
#define WIFI4_H

#include "BaseWiFi.h"
#include <chrono>
#include <algorithm>
#include <random>

class WiFi4 : public BaseWiFi {
public:
    WiFi4(std::vector<User> users, Channel & channel) 
        : BaseWiFi(users, channel) {}

    double transmitData() {
        double totalTime = 0;
        for (auto& user : users) {
            while (!channel.check()) {
                double backoffTime = static_cast<double>(rand()) / RAND_MAX * (0.1f + 0.01f * users.size());
                std::this_thread::sleep_for(std::chrono::duration<double>(backoffTime));
            }
            auto startTime = std::chrono::high_resolution_clock::now();
            channel.transmit(user.sendPacket().getSize(), users.size());
            auto endTime = std::chrono::high_resolution_clock::now();
            double latency = std::chrono::duration<double>(endTime - startTime).count();
            maxLatency = std::max(maxLatency, latency);
            totalLatency += latency;
            totalTime += latency;
        }
        return totalTime;
    }
};

#endif // WIFI4_H