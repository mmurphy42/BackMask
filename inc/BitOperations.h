#ifndef BitOperations_h
#define BitOperations_h

#include <utility>
#include <deque>

// This is the array size of the bitmask.
inline const uint8_t BITMASK_SIZE = 4;

// This is the actual bitmask object - an array of 64-bit unsigned ints.
struct bit_mask { uint64_t bm[BITMASK_SIZE]; };

// This sets the max bits per element of the array inside the bit_mask struct.
// ...who said C++ wasn't readable?
inline uint64_t MAX_BITS_PER_ELEMENT{std::numeric_limits<std::remove_reference<decltype(*std::begin(bit_mask::bm))>::type>::digits};

// Gets the first and last edges of a bitmask.
inline std::pair<size_t, size_t> GetBitEdges(size_t input_length, const struct bit_mask &bitmask)
{
    auto set_bits = std::deque<size_t>();
    
    int index_rightmost = -1;
    uint8_t bitmasks_used = (input_length / MAX_BITS_PER_ELEMENT) + 1;
    for (uint8_t i = 0; i < bitmasks_used; ++i) {
        // If this bitmask portion is 0, there is no info for us here.
        // However, there may be info in a future bitmask portion.
        if (bitmask.bm[i] != 0) {
            if (index_rightmost == -1) {
                index_rightmost = __builtin_ffsll(bitmask.bm[i]);
                set_bits.push_back(index_rightmost-1 + (MAX_BITS_PER_ELEMENT * i));   
            }

            int leading_zeroes = __builtin_clzll(bitmask.bm[i]);
            if (leading_zeroes < MAX_BITS_PER_ELEMENT ) {
                set_bits.push_back(MAX_BITS_PER_ELEMENT - leading_zeroes - 1 + (MAX_BITS_PER_ELEMENT * i));
            }
        }
    }
    return std::make_pair(set_bits.front(), set_bits.back());
}

// Adds a single bit at the given position.
inline bit_mask AddOneBit(size_t pos, struct bit_mask bitmask, size_t length) {    
    size_t bitmask_pos = length - pos - 1;

    uint8_t i=0;
    while (bitmask_pos >= MAX_BITS_PER_ELEMENT) {
        ++i;
        bitmask_pos -= MAX_BITS_PER_ELEMENT;
    }

    bitmask.bm[i] |= (1ull << bitmask_pos);
    
    return bitmask;
}

#endif
