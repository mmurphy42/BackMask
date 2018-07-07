# BACKMASK

How to use: As the one argument to the program, pass in a string from roughly 10-100 characters long (in quotes, if not all one word).

This program will scan the string in reverse, and try to find satanic messages buried in it.

The idea is that you can find satanic messages in really anything, and if we were to program this for other sorts of messages, those would work too.

# EXAMPLE

Here's an example run (using the default string - "Play Chess Online on the #1 Chess Site - Play with over 20 million members")

./bin/BackMask 
Input: Play Chess Online on the #1 Chess Site - Play with over 20 million members
FINAL STRING: BELIAL PET IS HE HELL 
351ms

So we got: BELIAL PET IS HE HELL (check it yourself) in 351ms of processing time.

./bin/BackMask "NYWYKHDHSXTLQSFHNZUMPHYQATXFXZPDNUKIKHVRMPJQNUSTIUEPMJGKUQAK"
Input: NYWYKHDHSXTLQSFHNZUMPHYQATXFXZPDNUKIKHVRMPJQNUSTIUEPMJGKUQAK
FINAL STRING: AM EVIL 
197ms

The cool thing about the above run is that there were more possible traversals through the letters than there are atoms in the universe!

# OPTIMIZATION

The program was optimized in a number of ways. A common strategy might be that each possible word is checked against a hash map/set to see if it is an actual word. This program uses a trie structure to be able to know for sure whether or not a letter sequence can possibly be continued (this is impossible with a hash map/set). 

When assembling phrases we use the fact that we only use bigrams (as opposed to trigrams) to assume that we know the top score for a given word and all its previous words, so all we have to do is compute the current score with that word.

Recursion? This program uses recursion, and while the hope is that the compiler is optimizing this, a big TODO is to implement an iterative solution just in case.
