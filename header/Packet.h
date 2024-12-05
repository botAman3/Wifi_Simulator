#ifndef PACKET_H
#define PACKET_H

class Packet {
public:
    Packet(int size) : size(size) {}

    int getSize() const {
        return size;
    }

private:
    int size; // Size in bytes
};

#endif // PACKET_H