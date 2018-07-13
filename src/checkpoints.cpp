// Copyright (c) 2009-2012 The Bitcoin developers
// Copyright (c) 2011-2012 Litecoin Developers
// Copyright (c) 2013 Grandcoin Developers
// Distributed under the MIT/X11 software license, see the accompanying
// file COPYING or http://www.opensource.org/licenses/mit-license.php.

#include <boost/assign/list_of.hpp> // for 'map_list_of()'
#include <boost/foreach.hpp>

#include "checkpoints.h"

#include "main.h"
#include "uint256.h"

namespace Checkpoints
{
    typedef std::map<int, uint256> MapCheckpoints;

    //
    // What makes a good checkpoint block?
    // + Is surrounded by blocks with reasonable timestamps
    //   (no blocks before with a timestamp after, none after with
    //    timestamp before)
    // + Contains no strange transactions
    //

	// no checkpoint now, can be added in later releases
    static MapCheckpoints mapCheckpoints =
            boost::assign::map_list_of
            (    1, uint256("0xbfece775f9753eb8b16a6e29bb95d1ba1b05c99b340f68834aafc489904c78b1"))
            (   77, uint256("0x3fbb6973b49f1fc09b958cc7dd647e3d982ea16376a43fbdf00029a664318936"))
            (  157, uint256("0x6c1926663c308227e7d0d9509e378e7e096ca835a6e227bd71c093b086117089"))
            ( 4999, uint256("0x080257c3630b4a1bba90bebed06bebd25b2950629a747fb4f84f038a780066f7"))
            ( 9999, uint256("0x531db3303115d3212cbbb162c2fde32788f873e0cec6ce23ba5bd94a0a8f5281"))
            (15999, uint256("0x425c33aead6db179aa2e1843508e983f9bf3a70460941793c87356df2bfd6679"))
	    (49999, uint256("0x27e49d1e790ce8a8aa3e4a8b75555bbf716488df98c997b83f2a568dd3201999"))
	    (99999, uint256("0x05c47974808768790a732634e9beea04b59cd5194d149fe37afdca963fab2bce"))
	    (199999, uint256("0x3e43d4036a209aea46a8aa7fa8a4adcf2eede7469570d3fcc108e00bbdcfb747"))
	    (299999, uint256("0x5fc0c9509e156b906dfea7abc49387c473501314d09e940602c55dc139ad7df1"))
	    (399999, uint256("0xe364fcb5ec33236783c4f30fbdb8bfcb35be0f3fffa0c7728c035987f991a70b"))
	    (499999, uint256("0x579e412451ae76facf4b04baf5108bfd5f61f4c8c23b1a29f030024212812029"))
	    (599999, uint256("0x70025f1359cc73cb5169431b89e78db05a6934453e7f3d8ab8af32bd2c3c9f04"))
	    (699999, uint256("0x82c5fa053ff00cbe6219c503c675e751fa7737f7b59ea71722397a8299ef998f"))
	    (799999, uint256("0x1c2651ea9e00e9d6bfeccb1bd8bd5240605abbe35c4ad842f8f2f78240d88d5f"))
	    (899999, uint256("0x4b28f730d04633f33a718c0a0bfb207b0fb6be0e480092972c530c987e012334"))
	    (999999, uint256("0x15b25bd66e6e6a681e6537d1214ff05bbf266be61267f40016ed2826d3ce4b4b"))
            (1010000, uint256("0xce92196c51da29c57c84e693220c0cef57d7f86ff46c6267c6be5615881c2acd"))
		;


    bool CheckBlock(int nHeight, const uint256& hash)
    {
        if (fTestNet) return true; // Testnet has no checkpoints

        MapCheckpoints::const_iterator i = mapCheckpoints.find(nHeight);
        if (i == mapCheckpoints.end()) return true;
        return hash == i->second;
		// return true;
    }

    int GetTotalBlocksEstimate()
    {
        if (fTestNet) return 0;
	
        return mapCheckpoints.rbegin()->first;
		// return 0;
    }

    CBlockIndex* GetLastCheckpoint(const std::map<uint256, CBlockIndex*>& mapBlockIndex)
    {
        if (fTestNet) return NULL;

        BOOST_REVERSE_FOREACH(const MapCheckpoints::value_type& i, mapCheckpoints)
        {
            const uint256& hash = i.second;
            std::map<uint256, CBlockIndex*>::const_iterator t = mapBlockIndex.find(hash);
            if (t != mapBlockIndex.end())
                return t->second;
				// return NULL;
        }
        return NULL;
    }
}
