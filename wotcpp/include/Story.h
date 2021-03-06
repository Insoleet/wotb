//
// Created by inso on 5/28/16.
//

#ifndef WOTB_STORY_H
#define WOTB_STORY_H

#include "Stats.h"

typedef std::pair<uint32_t, uint32_t> Link;

namespace libwot {

    class Story {
    public:
        Story(uint32_t sigPeriod, uint32_t sigStock, uint32_t sigValidity,
              uint32_t sigQty, uint32_t xpercent, uint32_t stepsMax);

        virtual ~Story();

        virtual void run() = 0;
        virtual void display() = 0;
        void initialize(uint32_t nbMembers);
        uint32_t addIdentity();
        uint32_t addLink(uint32_t from, uint32_t to);

        bool resolveMembership(uint32_t identity);
        uint32_t sentriesRule(uint32_t nbMembers);
        void nextTurn();

    protected:
        void addToCheckedNodes(uint32_t nodeIndex);

        uint32_t mSigPeriod;
        uint32_t mSigStock;
        uint32_t mSigValidity;
        uint32_t mSigQty;
        uint32_t mXpercent;
        uint32_t mStepsMax;
        uint32_t mTurn;
        Stats mStats;
        WebOfTrust* mCurrentWot;
        std::vector<uint32_t> mCurrentMembers;
        std::vector<uint32_t> mNodesLatestCerts;
        std::map< Link, uint32_t > mTimestamps;
        std::vector<uint32_t> mArrivals;
    };
}


#endif //WOTB_STORY_H
