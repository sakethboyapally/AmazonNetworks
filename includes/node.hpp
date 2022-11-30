#pragma once

#include <stdint.h>
#include <string>

using namespace std;
class Node {
    public:
        Node(std::string data);
        ~Node();

        Node getNode(int id);

        int getID() { return ID_; }
        void setID(int ID) {}

        int getASIN() { return ASIN_; }
        void setASIN(int ASIN) { ASIN_ = ASIN}

        std::string getData();

        static unsigned num_nodes_;

    private:
        int ID_;
        int ASIN_;
        string group_;
        int salesrank_;
        vector<int> similar_;
};
