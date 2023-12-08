// Taylor Benoit 
// Stephen Lahood
// Jack Rivas Vazquez


#include "PlaylistNode.h"
#include <iostream>
using namespace std; 

PlaylistNode::PlaylistNode()
    : uniqueID("none"), songName("none"), artistName("none"), songLength(0), nextNodePtr(nullptr) {}


PlaylistNode::PlaylistNode(string id, string song, string artist, int length)
    : uniqueID(id), songName(song), artistName(artist), songLength(length), nextNodePtr(nullptr) {}


string PlaylistNode::GetID() const { return uniqueID; }
string PlaylistNode::GetSongName() const { return songName; }
string PlaylistNode::GetArtistName() const { return artistName; }
int PlaylistNode::GetSongLength() const { return songLength; }
PlaylistNode* PlaylistNode::GetNext() const { return nextNodePtr; }


void PlaylistNode::InsertAfter(PlaylistNode* nodePtr) {
    nodePtr->nextNodePtr = this->nextNodePtr;
    this->nextNodePtr = nodePtr;
}

void PlaylistNode::SetNext(PlaylistNode* nodePtr) {
    this->nextNodePtr = nodePtr;
}


void PlaylistNode::PrintPlaylistNode() const {
cout << "Unique ID: " << uniqueID << endl;
cout << "Song Name: " << songName << endl;
cout << "Artist Name: " << artistName << endl;
cout << "Song Length (in seconds): " << songLength << endl;
cout << endl;
}
